/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - LOCO Project  */
/* C Run-time                                          Daniel Diaz - 1992  */
/*                                                                         */
/* Modified by Yan Georget - June 1998                                     */
/* sfd_engine.c                                                            */
/*-------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>

#define FD_ENGINE

#include "wam_engine.h"
#include "sfd_engine.h"


LibPrototype(extern int fprintf())
LibPrototype(extern int sscanf())



/*---------------------------------*/
/* Constants                       */
/*---------------------------------*/

/*---------------------------------*/
/* Type Definitions                */
/*---------------------------------*/

/*---------------------------------*/
/* Global Variables                */
/*---------------------------------*/


/* for global constraints */
/*------------------------*/
static WamWord*  global_cstr_stack[GLOBAL_CSTR_STACK_SIZE];
static int       GCS = 0;



/* as in clp(FD): for reduction queue */
/*------------------------------------*/
static WamWord   dummy_fd_var[FD_VARIABLE_FRAME_SIZE];



/* for constraint retraction */
/*---------------------------*/
static WamWord   dummy_fd_var2[FD_VARIABLE_FRAME_SIZE];
WamWord          *TP2 ;
                 /* the 2 vars above are used for ENLARGEMENT */

int              propagation_mode = REDUCTION;  
                                    /* there are 3 modes:          */
                                    /* REDUCTION                   */
                                    /* REDUCTION_AFTER_ENLARGEMENT */
                                    /* ENLARGEMENT                 */


#ifdef WAM_PROFILE

static int   nb_fd_var=0;
static int   nb_fd_int_var=0;


static int   nb_fd_cstr=0;
static int   nb_fd_int_cstr=0;
static int   nb_unif_fd_int_imposs=0;
static int   nb_unif_fd_int_poss=0;

static int   prof_count[100];

static char *prof_name[100]=
       { "",                                /* prof_{name/count}[0] unused */
         "Total Tell",
         "True  Tell", "False Tell", 
         "INT Check Ok", "INT C Not Ok", "Empty Range",
         "",
         "In Queue","X Ground",
         "$"};

#endif




/*---------------------------------*/
/* Function Prototypes             */
/*---------------------------------*/
static 
void      All_Propagations      (WamWord *fdv_adr,int propag);

static 
void      All_Propagations2     (WamWord *fdv_adr,int propag);




#ifdef WAM_PROFILE

#define COUNT(x)   prof_count[x]++

#else

#define COUNT(x)

#endif






/*---------------------------------*/
/* Auxiliary engine macros         */
/*---------------------------------*/


#define Trail_Range_If_Necessary(fdv_adr)                                   \
    {                                                                       \
     if (Range_Stamp(fdv_adr)!=STAMP)                                       \
        {                                                                   \
         Trail_MV(fdv_adr+OFFSET_RANGE,RANGE_SIZE)                          \
         if (Mode(fdv_adr) == R_SPARSE)                                     \
             Trail_MV((WamWord *) Vec(fdv_adr),vec_size)                    \
         Range_Stamp(fdv_adr)=STAMP;                                        \
        }                                                                   \
    }



#define Trail_Chains_If_Necessary(fdv_adr)                                  \
    {                                                                       \
     if (Chains_Stamp(fdv_adr)!=STAMP)                                      \
        {                                                                   \
         Trail_MV(fdv_adr+OFFSET_CHAINS,CHAINS_SIZE)                        \
         Chains_Stamp(fdv_adr)=STAMP;                                       \
        }                                                                   \
    }



#define Update_Range_From_Range(fdv_adr,range,propag)                       \
    {                                                                       \
     propag=MASK_EMPTY;                                                     \
                                                                            \
     if (!Vector_Equal(Vec(fdv_adr),range->vec))                            \
       {                                                                    \
         Trail_Range_If_Necessary(fdv_adr)                                  \
         Set_Def_Mask(propag);                                              \
         Vector_Copy(Vec(fdv_adr),range->vec);                              \
                                                                            \
         if (Min(fdv_adr) != (range)->min)                                  \
           {                                                                \
             Min(fdv_adr) = (range)->min;                                   \
             Set_Min_Mask(propag)                                           \
             Set_Min_Max_Mask(propag)                                       \
           }                                                                \
                                                                            \
         if (Max(fdv_adr) != (range)->max)                                  \
           {                                                                \
             Max(fdv_adr) = (range)->max;                                   \
             Set_Max_Mask(propag)                                           \
             Set_Min_Max_Mask(propag)                                       \
           }                                                                \
                                                                            \
         if (Sigma(fdv_adr) != range->sigma)                                \
            {                                                               \
              Sigma(fdv_adr) = range->sigma;                                \
              Set_Sigma_Mask(propag);                                       \
            }                                                               \
        }                                                                   \
    }


#define Update_Range_From_Range_No_Propag_No_Trail(fdv_adr,range)           \
    {                                                                       \
     if (!Vector_Equal(Vec(fdv_adr),range->vec))                            \
       {                                                                    \
         Vector_Copy(Vec(fdv_adr),range->vec);                              \
         Min(fdv_adr) = range->min;                                         \
         Max(fdv_adr) = range->max;                                         \
         Sigma(fdv_adr) = range->sigma;                                     \
        }                                                                   \
    }



#define Update_Range_From_Int(fdv_adr,i,v,propag)                           \
    {                                                                       \
     propag=MASK_EMPTY;                                                     \
                                                                            \
     Trail_Range_If_Necessary(fdv_adr)                                      \
                                                                            \
     Set_Def_Mask(propag);                                                  \
     Set_Val_Mask(propag);                                                  \
                                                                            \
     if (Sigma(fdv_adr) != v)                                               \
       {                                                                    \
          Sigma(fdv_adr) = v;                                               \
          Set_Sigma_Mask(propag);                                           \
       }                                                                    \
                                                                            \
     if (Min(fdv_adr) != i)                                                 \
       {                                                                    \
          Min(fdv_adr) = i;                                                 \
          Set_Min_Mask(propag);                                             \
          Set_Min_Max_Mask(propag);                                         \
       }                                                                    \
                                                                            \
     if (Max(fdv_adr) != i)                                                 \
       {                                                                    \
          Max(fdv_adr) = i;                                                 \
          Set_Max_Mask(propag);                                             \
          Set_Min_Max_Mask(propag);                                         \
       }                                                                    \
                                                                            \
     Mode(fdv_adr) = R_INTEGER;                                             \
    }


#define Update_Range_From_Int_No_Propag_No_Trail(fdv_adr,i,v)               \
    {                                                                       \
     Mode(fdv_adr) = R_INTEGER;                                             \
     Sigma(fdv_adr) = v;                                                    \
     Min(fdv_adr) = Max(fdv_adr) = i;                                       \
    }


#define Update_Interval_From_Range(fdv_adr,range,propag)                    \
    {                                                                       \
     propag=MASK_EMPTY;                                                     \
                                                                            \
     if (Min(fdv_adr) != (range)->min)                                      \
        {                                                                   \
         Set_Min_Mask(propag)                                               \
         Set_Min_Max_Mask(propag)                                           \
        }                                                                   \
                                                                            \
     if (Max(fdv_adr) != (range)->max)                                      \
        {                                                                   \
         Set_Max_Mask(propag)                                               \
         Set_Min_Max_Mask(propag)                                           \
        }                                                                   \
                                                                            \
     if (Sigma(fdv_adr) != range->sigma)                                    \
        {                                                                   \
         Set_Sigma_Mask(propag);                                            \
        }                                                                   \
                                                                            \
     Trail_Range_If_Necessary(fdv_adr)                                      \
     Set_Def_Mask(propag);                                                  \
     Range_Copy(Range(fdv_adr),range);                                      \
    }


#define Update_Interval_From_Range_No_Propag_No_Trail(fdv_adr,range)        \
     Range_Copy(Range(fdv_adr),range);


#define Update_Interval_From_Interval(fdv_adr,min,max,v,propag)             \
    {                                                                       \
     propag=MASK_EMPTY;                                                     \
                                                                            \
     if (Min(fdv_adr) != min || Max(fdv_adr) != max || Sigma(fdv_adr) != v) \
        {                                                                   \
         Trail_Range_If_Necessary(fdv_adr)                                  \
                                                                            \
         Set_Def_Mask(propag)                                               \
                                                                            \
         if (Min(fdv_adr) != min)                                           \
            {                                                               \
             Min(fdv_adr)=min;                                              \
             Set_Min_Mask(propag)                                           \
             Set_Min_Max_Mask(propag)                                       \
            }                                                               \
                                                                            \
         if (Max(fdv_adr) != max)                                           \
            {                                                               \
             Max(fdv_adr)=max;                                              \
             Set_Max_Mask(propag)                                           \
             Set_Min_Max_Mask(propag)                                       \
            }                                                               \
                                                                            \
         if (Sigma(fdv_adr) != v)                                           \
            {                                                               \
             Sigma(fdv_adr)=v;                                              \
             Set_Sigma_Mask(propag)                                         \
            }                                                               \
        }                                                                   \
    }


#define Update_Interval_From_Interval_No_Propag_No_Trail(fdv_adr,min,max,v) \
    {                                                                       \
      Sigma(fdv_adr) = v;                                                   \
      Min(fdv_adr) = min;                                                   \
      Max(fdv_adr) = max;                                                   \
    }



#define Update_Interval_From_Int(fdv_adr,i,v,propag)                        \
    {                                                                       \
     propag=MASK_EMPTY;                                                     \
                                                                            \
     Trail_Range_If_Necessary(fdv_adr)                                      \
                                                                            \
     Set_Def_Mask(propag)                                                   \
     Set_Val_Mask(propag)                                                   \
                                                                            \
     if (Min(fdv_adr) != i)                                                 \
       {                                                                    \
         Min(fdv_adr)=i;                                                    \
         Set_Min_Mask(propag)                                               \
         Set_Min_Max_Mask(propag)                                           \
       }                                                                    \
                                                                            \
     if (Max(fdv_adr) != i)                                                 \
       {                                                                    \
         Max(fdv_adr)=i;                                                    \
         Set_Max_Mask(propag)                                               \
         Set_Min_Max_Mask(propag)                                           \
       }                                                                    \
                                                                            \
     if (Sigma(fdv_adr) != v)                                               \
       {                                                                    \
         Sigma(fdv_adr)=v;                                                  \
         Set_Sigma_Mask(propag)                                             \
       }                                                                    \
                                                                            \
     Mode(fdv_adr) = R_INTEGER;                                             \
    }


#define Update_Interval_From_Int_No_Propag_No_Trail(fdv_adr,i,v)            \
    {                                                                       \
     Min(fdv_adr)=i;                                                        \
     Max(fdv_adr)=i;                                                        \
     Sigma(fdv_adr)=v;                                                      \
     Mode(fdv_adr) = R_INTEGER;                                             \
    }



#define Update_Int_From_Int(fdv_adr,i,v,propag)                             \
    {                                                                       \
     propag=MASK_EMPTY;                                                     \
                                                                            \
     if (Sigma(fdv_adr) != v)                                               \
	{                                                                   \
          Trail_Range_If_Necessary(fdv_adr)                                 \
          Set_Def_Mask(propag);                                             \
          Set_Sigma_Mask(propag);                                           \
          Sigma(fdv_adr) = v ;                                              \
	}                                                                   \
    }                                                                       \


#define Update_Int_From_Int_No_Propag_No_Trail(fdv_adr,i,v)                 \
    Sigma(fdv_adr) = v ;                           



/*-------------------------------------------------------------------------*/
/* INIT_FD_ENGINE                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Init_Fd_Engine(void)

{
 int max_val;

 atom_infinity = Create_Atom("infinity");

 max_val = DEFAULT_VECTOR_MAX;

 Define_Vector_Size(max_val);

 STAMP = 0;
 DATE  = 0;
}




/*-------------------------------------------------------------------------*/
/* TERM_FD_ENGINE                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Term_Fd_Engine(void)

{
#ifdef WAM_PROFILE
 int i,j;
#endif

#ifdef WAM_PROFILE
 Lib1(printf,"clp(FD) Profile informations\n\n");


 Lib1(printf,"FD variables:\n");
 Lib2(printf,"   true FD var :%10d\n",nb_fd_var);
 Lib2(printf,"   integer     :%10d\n\n",nb_fd_int_var);

 Lib1(printf,"Constraints:\n");
 Lib2(printf,"   Basic X in r:%10d\n",nb_fd_cstr);
 Lib2(printf,"   Unif integer:%10d with a possible value\n",
             nb_unif_fd_int_poss);
 Lib2(printf,"                %10d with an impossible value\n\n",
             nb_unif_fd_int_imposs);

 Lib1(printf,"Vectors:\n");

 Lib2(printf,"   defined size:%10d word(s)\n",vec_size);
 Lib2(printf,"   defined max :%10d\n\n",vec_infinity);

 Lib1(printf,"Counters:\n");

 for(i=j=1;*prof_name[i]!='$';i++)
     if (*prof_name[i])
         Lib3(printf,"   %-12s:%10d\n",prof_name[i],prof_count[j++]);
      else
         Lib1(printf,"\n");

 Lib1(printf,"\n");

#endif

}


/*-------------------------------------------------------------------------*/
/* PUSH_FD_VARIABLE                                                        */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Push_Fd_Variable(void)

{
 WamWord *fdv_adr=H;

 H += FD_VARIABLE_FRAME_SIZE;

 FD_Tag_Value(fdv_adr) = Tag_Value(FDV,fdv_adr);
 
 Queue_Date_At_Push(fdv_adr)  = 0;
 Queue_Propag_Mask(fdv_adr)   = 0;
 Queue_Next_Fdv_Adr(fdv_adr)  = (WamWord) NULL;
 
 Queue2_Date_At_Push(fdv_adr) = 0;
 Queue2_Propag_Mask(fdv_adr)  = 0;
 Queue2_Next_Fdv_Adr(fdv_adr) = (WamWord) NULL;
 
 Date_Of_Enlargement(fdv_adr) = 0;
 Cstrs_Block(fdv_adr)         = (WamWord) NULL;

 Range_Stamp(fdv_adr)         = STAMP;
 Chains_Stamp(fdv_adr)        = STAMP;
 
 Init_Range_Full(Range(fdv_adr)) ;

 Chains_Mask(fdv_adr)         = MASK_EMPTY;
 Chain_Sigma(fdv_adr)         = (WamWord) NULL;
 Chain_Def(fdv_adr)           = (WamWord) NULL;
 Chain_Min(fdv_adr)           = (WamWord) NULL;
 Chain_Max(fdv_adr)           = (WamWord) NULL;
 Chain_Min_Max(fdv_adr)       = (WamWord) NULL;
 Chain_Val(fdv_adr)           = (WamWord) NULL;
 Chain_Static(fdv_adr)        = (WamWord) NULL;

#ifdef WAM_PROFILE
 nb_fd_var++;
#endif
}

/*-------------------------------------------------------------------------*/
/* PUSH_FD_INT_VARIABLE                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Push_Fd_Int_Variable(int n)
{
 WamWord *fdv_adr=H;

 H += FD_VARIABLE_FRAME_SIZE;

 FD_Tag_Value(fdv_adr) = Tag_Value(FDV,fdv_adr);
 
 Queue_Date_At_Push(fdv_adr ) = 0;
 Queue_Propag_Mask(fdv_adr)   = 0;
 Queue_Next_Fdv_Adr(fdv_adr)  = (WamWord) NULL;

 Queue2_Date_At_Push(fdv_adr) = 0;
 Queue2_Propag_Mask(fdv_adr)  = 0;
 Queue2_Next_Fdv_Adr(fdv_adr) = (WamWord) NULL;
 
 Date_Of_Enlargement(fdv_adr) = 0;
 Cstrs_Block(fdv_adr)         = (WamWord) NULL;

 Range_Stamp(fdv_adr)         = STAMP;
 Chains_Stamp(fdv_adr)        = STAMP;
 
 Init_Range_Term(Range(fdv_adr),n,UnityA) ;

 Chains_Mask(fdv_adr)         = MASK_EMPTY;
 Chain_Sigma(fdv_adr)         = (WamWord) NULL;
 Chain_Def(fdv_adr)           = (WamWord) NULL;
 Chain_Min(fdv_adr)           = (WamWord) NULL;
 Chain_Max(fdv_adr)           = (WamWord) NULL;
 Chain_Min_Max(fdv_adr)       = (WamWord) NULL;
 Chain_Val(fdv_adr)           = (WamWord) NULL;
 Chain_Static(fdv_adr)        = (WamWord) NULL;

#ifdef WAM_PROFILE
 nb_fd_var++;
#endif
}

/*-------------------------------------------------------------------------*/
/* CHECK_FOR_FD_VARIABLE                                                   */
/*                                                                         */
/*-------------------------------------------------------------------------*/
WamWord *Check_For_Fd_Variable(WamWord start_word)

{
 WamWord  word,tag,*adr;
 WamWord *fdv_adr;


 Deref(start_word,word,tag,adr)

 switch(tag)
    {
     case REF:
         Bind_UV(adr,Tag_Value(REF,H))
         fdv_adr=H;
         Push_Fd_Variable();
         break;
	 
     case INT: 
         fdv_adr=H;
         Push_Fd_Int_Variable(UnTag_INT(word));
         break;

     case FDV:
         fdv_adr=UnTag_FDV(word);
         break;

     default:
         fdv_adr=NULL;
    }

 return fdv_adr;
}




/*-------------------------------------------------------------------------*/
/* CREATE_C_FRAME                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
WamWord *Create_C_Frame(Bool (*cstr_fct)(), 
			void (*enlargement_fct)(), 
			Bool (*test_enlargement_fct)(), 
			void (*reduction_fct)(),
			WamWord *AF)

{
 WamWord *CF=H;

 AF_Pointer(CF)               = (WamWord) AF;
 Cstr_Address(CF)             = (WamWord) cstr_fct;
 Enlargement_Address(CF)      = (WamWord) enlargement_fct;
 Test_Enlargement_Address(CF) = (WamWord) test_enlargement_fct;
 Reduction_Address(CF)        = (WamWord) reduction_fct;
 Infos(CF)                    = (WamWord) 0;
 Set_Active(CF) ;
 Next_Cstr(CF)                = (WamWord) last_CF;

 H += CONSTRAINT_FRAME_SIZE;

 return CF;
}




/*-------------------------------------------------------------------------*/
/* ADD_RECORD_IN_CHAIN                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Add_Record_In_Chain(WamWord *fdv_adr,int chain_nb,WamWord *CF)

{
 WamWord **chain_adr;

 Trail_Chains_If_Necessary(fdv_adr)

 Chains_Mask(fdv_adr) |= (1<<chain_nb);

 chain_adr=(WamWord **) (&Chain_Sigma(fdv_adr)+chain_nb);

 CF_Pointer(H)=(WamWord) CF;
 Next_Chain(H)=(WamWord) *chain_adr;

 *chain_adr=H;

 H += CHAIN_RECORD_FRAME_SIZE;
}



/*-------------------------------------------------------------------------*/
/* ADD_RECORD_IN_STATIC_CHAIN                                              */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Add_Record_In_Static_Chain(WamWord *fdv_adr,WamWord *CF)

{
 WamWord **chain_adr;
 
 Trail_Chains_If_Necessary(fdv_adr)

 chain_adr=(WamWord **) (&Chain_Static(fdv_adr));

 CF_Pointer(H)=(WamWord) CF;
 Next_Chain(H)=(WamWord) *chain_adr;

 *chain_adr=H;

 H += CHAIN_RECORD_FRAME_SIZE;
}



/*-------------------------------------------------------------------------*/
/* INIT_CALL_CONSTRAINT                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Init_Call_Constraint(void)

{
 Set_Global_Cstr_Stack_Empty 
 TP  = dummy_fd_var;
 TP2 = dummy_fd_var2;
 DATE++;
}



/*-------------------------------------------------------------------------*/
/* TELL_RANGE_RANGE                                                        */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Tell_Range_Range(WamWord *fdv_adr,Range *range)

{   
  int propag;
  
  switch (propagation_mode)
    {
    case REDUCTION:
      Range_MulA_Range(range,Range(fdv_adr));
      if (range->mode == R_EMPTY)
	return FALSE;

      H=save_H;
 
      switch (range->mode)
	{
	case R_SPARSE:
	  Update_Range_From_Range(fdv_adr,range,propag)
	  break;

	case R_INTEGER:
	  Update_Range_From_Int(fdv_adr,range->min,range->sigma,propag) 
          break;
	}
      All_Propagations(fdv_adr,propag);
      return TRUE;
    
    case REDUCTION_AFTER_ENLARGEMENT:
      Range_MulA_Range(range,Range(fdv_adr));

      H=save_H;
 
      switch (range->mode)
	{
	case R_SPARSE:
	  Update_Range_From_Range(fdv_adr,range,propag)
	  break;

	case R_INTEGER:
	  Update_Range_From_Int(fdv_adr,range->min,range->sigma,propag) 
          break;
	}
      All_Propagations(fdv_adr,propag);
      return TRUE;

    case ENLARGEMENT:
      Range_MulA_Range(range,Range(fdv_adr));
      
      H=save_H;

      /* no need to trail there */
      switch (range->mode)
	{
	case R_SPARSE:
	  Update_Range_From_Range_No_Propag_No_Trail(fdv_adr,range)
	  break;
        case R_INTEGER:
	  Update_Range_From_Int_No_Propag_No_Trail(fdv_adr,range->min,range->sigma)
          break;
	}
      return TRUE;
    }
}



/*-------------------------------------------------------------------------*/
/* TELL_RANGE_INTEGER                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/ 
Bool Tell_Range_Integer(WamWord *fdv_adr, int i, VecWord v)

{
  int propag;

  switch (propagation_mode)
    {                      
    case REDUCTION:     
      if (i<0 || i>vec_infinity)
	return FALSE;
      v = MulA(v,ValA_Vector(Vec(fdv_adr),i));
      if (IsNullA(v))
	return FALSE;
      
      Update_Range_From_Int(fdv_adr,i,v,propag) 
      All_Propagations(fdv_adr,propag);
      return TRUE;
      
    case REDUCTION_AFTER_ENLARGEMENT:
      v = MulA(v,ValA_Vector(Vec(fdv_adr),i));
      
      Update_Range_From_Int(fdv_adr,i,v,propag) 
      All_Propagations(fdv_adr,propag);
      return TRUE;

    case ENLARGEMENT:
      v = MulA(v,ValA_Vector(Vec(fdv_adr),i));
      
      Update_Range_From_Int_No_Propag_No_Trail(fdv_adr,i,v) 
      return TRUE;
    }
}


/*-------------------------------------------------------------------------*/
/* TELL_INTERVAL_RANGE                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/ 
Bool Tell_Interval_Range(WamWord *fdv_adr,Range *range)

{   
  int propag;

  switch (propagation_mode)
    {                      
    case REDUCTION:
      Range_MulA_Range(range,Range(fdv_adr));
      if (range->mode == R_EMPTY)
	return FALSE;

      H=save_H;
 
      switch (range->mode)
	{
	case R_SPARSE:
	  Update_Interval_From_Range(fdv_adr,range,propag) 
	  break;
	case R_INTERVAL:
	  Update_Interval_From_Interval(fdv_adr,range->min,range->max,range->sigma,propag) 
          break;
	case R_INTEGER:
	  Update_Interval_From_Int(fdv_adr,range->min,range->sigma,propag) 
          break;
	}
      All_Propagations(fdv_adr,propag);
      return TRUE;
    
    case REDUCTION_AFTER_ENLARGEMENT:
      Range_MulA_Range(range,Range(fdv_adr));

      H=save_H;
 
      switch (range->mode)
	{
	case R_SPARSE:
	  Update_Interval_From_Range(fdv_adr,range,propag) 
	  break;
	case R_INTERVAL:
	  Update_Interval_From_Interval(fdv_adr,range->min,range->max,range->sigma,propag) 
          break;
	case R_INTEGER:
	  Update_Interval_From_Int(fdv_adr,range->min,range->sigma,propag) 
          break;
	}
      All_Propagations(fdv_adr,propag);
      return TRUE;


    case ENLARGEMENT:
      Range_MulA_Range(range,Range(fdv_adr));
      
      H=save_H;

      /* no need to trail there */
      switch (range->mode)
	{
	case R_SPARSE:
	  Update_Interval_From_Range_No_Propag_No_Trail(fdv_adr,range) 
          break;
	case R_INTERVAL:
	  Update_Interval_From_Interval_No_Propag_No_Trail(fdv_adr,range->min,range->max,range->sigma)
          break;
        case R_INTEGER:   
	  Update_Interval_From_Int_No_Propag_No_Trail(fdv_adr,range->min,range->sigma)
          break;
	}
      return TRUE;
    }
}


/*-------------------------------------------------------------------------*/
/* TELL_INTERVAL_INTERVAL                                                  */
/*                                                                         */
/*-------------------------------------------------------------------------*/ 
Bool Tell_Interval_Interval(WamWord *fdv_adr, int min, int max, VecWord v)

{
  int propag;
  int min1;
  int max1;

  switch (propagation_mode)
    {
    case REDUCTION:
      min1 = Min(fdv_adr);
      max1 = Max(fdv_adr);
      min = math_max(min,min1);
      max = math_min(max,max1);
      v   = MulA(v, Sigma(fdv_adr));

      if (IsNullA(v) || (min > max))
	return FALSE;

      if (min == max) 
	Update_Interval_From_Int(fdv_adr,min,v,propag)
      else
	Update_Interval_From_Interval(fdv_adr,min,max,v,propag)

      All_Propagations(fdv_adr,propag);
      return TRUE;
   
    case REDUCTION_AFTER_ENLARGEMENT:
      min1 = Min(fdv_adr);
      max1 = Max(fdv_adr);
      min = math_max(min,min1);
      max = math_min(max,max1);
      v   = MulA(v, Sigma(fdv_adr));

      if (min == max) 
	Update_Interval_From_Int(fdv_adr,min,v,propag)
      else
	Update_Interval_From_Interval(fdv_adr,min,max,v,propag)

      All_Propagations(fdv_adr,propag);
      return TRUE;
      
    case ENLARGEMENT:
      min1 = Min(fdv_adr);
      max1 = Max(fdv_adr);
      min = math_max(min,min1);
      max = math_min(max,max1);
      v   = MulA(v, Sigma(fdv_adr));

      /* no need to trail there */
      if (min == max) 
	Update_Interval_From_Int_No_Propag_No_Trail(fdv_adr,min,v)
      else
	Update_Interval_From_Interval_No_Propag_No_Trail(fdv_adr,min,max,v)
      return TRUE;
    }
}


/*-------------------------------------------------------------------------*/
/* TELL_INTERVAL_INTEGER                                                   */
/*                                                                         */
/*-------------------------------------------------------------------------*/ 
Bool Tell_Interval_Integer(WamWord *fdv_adr, int i, VecWord v)

{
  int propag;

  switch (propagation_mode)
    {
    case REDUCTION:
      v = MulA(v, Sigma(fdv_adr));

      if (IsNullA(v) || (i < Min(fdv_adr)) || (i > Max(fdv_adr)))
	return FALSE;

      Update_Interval_From_Int(fdv_adr,i,v,propag)

      All_Propagations(fdv_adr,propag);
      return TRUE;
   
    case REDUCTION_AFTER_ENLARGEMENT:
      v = MulA(v, Sigma(fdv_adr));

      Update_Interval_From_Int(fdv_adr,i,v,propag)

      All_Propagations(fdv_adr,propag);
      return TRUE;

    case ENLARGEMENT:
      v = MulA(v, Sigma(fdv_adr));

      Update_Interval_From_Int_No_Propag_No_Trail(fdv_adr,i,v)
      return TRUE;
    }
}


/*-------------------------------------------------------------------------*/
/* TELL_INTEGER_RANGE                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/ 
Bool Tell_Integer_Range(WamWord *fdv_adr, Range *range)

{
  int propag;
  int i;
  VecWord v;

  switch (propagation_mode)
    {
    case REDUCTION:
      i = Min(fdv_adr);
      v = MulA(Sigma(fdv_adr), Value_Of_Int_In_Range(range,i));
      if (IsNullA(v))
	return FALSE;

      H=save_H;
 
      Update_Int_From_Int(fdv_adr,i,v,propag) 
      All_Propagations(fdv_adr,propag);
      return TRUE;

    case REDUCTION_AFTER_ENLARGEMENT:
      i = Min(fdv_adr);
      v = MulA(Sigma(fdv_adr), Value_Of_Int_In_Range(range,i));

      H=save_H;
 
      Update_Int_From_Int(fdv_adr,i,v,propag) 
      All_Propagations(fdv_adr,propag);
      return TRUE;

    case ENLARGEMENT:
      i = Min(fdv_adr);
      v = MulA(Sigma(fdv_adr), Value_Of_Int_In_Range(range,i));
  
      H=save_H;

      /* no need to trail there */
      Update_Int_From_Int_No_Propag_No_Trail(fdv_adr,i,v);
      return TRUE;
    }
}


/*-------------------------------------------------------------------------*/
/* TELL_INTEGER_INTERVAL                                                   */
/*                                                                         */
/*-------------------------------------------------------------------------*/ 
Bool Tell_Integer_Interval (WamWord *fdv_adr, int min, int max, VecWord v)

{
  int propag;
  int i;

  switch (propagation_mode)
    {                      
    case REDUCTION:
      i = Min(fdv_adr);
      v = MulA(Sigma(fdv_adr),v);
      if (IsNullA(v) || (i<min) || (i>max))
	return FALSE;
 
      Update_Int_From_Int(fdv_adr,i,v,propag) 
      All_Propagations(fdv_adr,propag);
      return TRUE;
      
    case REDUCTION_AFTER_ENLARGEMENT:
      i = Min(fdv_adr);
      v = MulA(Sigma(fdv_adr),v);
 
      Update_Int_From_Int(fdv_adr,i,v,propag) 
      All_Propagations(fdv_adr,propag);
      return TRUE;

    case ENLARGEMENT:
      i = Min(fdv_adr);
      v = MulA(Sigma(fdv_adr),v);
  
      /* no need to trail there */
      Update_Int_From_Int_No_Propag_No_Trail(fdv_adr,i,v);
      return TRUE;
    }
}


/*-------------------------------------------------------------------------*/
/* TELL_INTEGER_INTEGER                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/ 
Bool Tell_Integer_Integer  (WamWord *fdv_adr, int i, VecWord v)

{
  int propag;

  switch (propagation_mode)
    {                      
    case REDUCTION:
      v = MulA(Sigma(fdv_adr),v);
      if (IsNullA(v) || Min(fdv_adr) != i)
	return FALSE;

      Update_Int_From_Int(fdv_adr,i,v,propag) 
      All_Propagations(fdv_adr,propag);
      return TRUE;
      
    case REDUCTION_AFTER_ENLARGEMENT:
      v = MulA(Sigma(fdv_adr),v);

      Update_Int_From_Int(fdv_adr,i,v,propag) 
      All_Propagations(fdv_adr,propag);
      return TRUE;
      
    case ENLARGEMENT:
      v = MulA(Sigma(fdv_adr),v);

      /* no need to trail there */
      Update_Int_From_Int_No_Propag_No_Trail(fdv_adr,i,v);
      return TRUE;
    }
}


/*-------------------------------------------------------------------------*/
/* ALL_PROPAGATIONS                                                        */
/*                                                                         */
/* this corresponds to the propagation of both reductions                  */
/*-------------------------------------------------------------------------*/
static void All_Propagations(WamWord *fdv_adr,int propag)

{
 if (propag &= Chains_Mask(fdv_adr))
    {
     if (Queue_Date_At_Push(fdv_adr) < DATE)       /* not yet in the queue */
        {
         Queue_Date_At_Push(fdv_adr) = DATE;
         Queue_Propag_Mask(fdv_adr)  = propag;
         Queue_Next_Fdv_Adr(TP)      = (WamWord) fdv_adr;
         TP = fdv_adr;
        }
      else                                         /* already in the queue */
         Queue_Propag_Mask(fdv_adr) |= propag;
    }
}


/*-------------------------------------------------------------------------*/
/* ALL_PROPAGATIONS2                                                       */
/*                                                                         */
/* this corresponds to the propagation of the enlargement                  */
/*-------------------------------------------------------------------------*/
static void All_Propagations2(WamWord *fdv_adr,int propag)

{
 if (propag &= Chains_Mask(fdv_adr))
    {
     if (Queue2_Date_At_Push(fdv_adr) < DATE)      /* not yet in the queue */
        {
         Queue2_Date_At_Push(fdv_adr) = DATE;
         Queue2_Propag_Mask(fdv_adr)  = propag;
         Queue2_Next_Fdv_Adr(TP2)     = (WamWord) fdv_adr;
         TP2 = fdv_adr;
        }
      else                                         /* already in the queue */
         Queue2_Propag_Mask(fdv_adr) |= propag;
    }
}



/*-------------------------------------------------------------------------*/
/* EXECUTE_PROPAGATION                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Execute_Propagation(void)

{
 WamWord         propag;
 WamWord        *fdv_adr;
 WamWord        *record_adr;
 WamWord        *chain_adr;
 WamWord        *CF;
 WamWord        *BP;

 BP = dummy_fd_var;
 while((BP != TP) || (!Is_Global_Cstr_Stack_Empty))
   {
     while(BP != TP)
       {
	 BP=(WamWord *) Queue_Next_Fdv_Adr(BP);
	 do
	   {
	     fdv_adr = (WamWord *) BP;
	     propag  = Queue_Propag_Mask(fdv_adr);
	     Queue_Propag_Mask(fdv_adr) = 0;
	     chain_adr = &Chain_Sigma(fdv_adr);
	     
	     for( ; propag ; propag >>= 1, chain_adr++)
	       if (propag & 1)
		 {
		   record_adr = (WamWord *) (*chain_adr);
		   do
		     {
		       CF = (WamWord *) CF_Pointer(record_adr);
		       if (Is_Active(CF) 
			   && ((propagation_mode == REDUCTION) 
			       || Test_Enlarged_Variables(CF)))
			 {
			   if (Is_Global_Cstr(CF))
			     {
			       if (!Is_On_Global_Cstr_Stack(CF))
				 {
				   Global_Cstr_Stack_Push
				   Trail_OV(&Infos(CF));  
				   Set_On_Global_Cstr_Stack(CF)
				 }
			     }
			   else
			     Execute_Constraint(return FALSE;)
			 }
		     }
		   while(record_adr = (WamWord *) Next_Chain(record_adr));
		 }
	   }
	 while (Queue_Propag_Mask(fdv_adr) != 0);
	 Queue_Date_At_Push(fdv_adr) = 0;
       }

     while (!Is_Global_Cstr_Stack_Empty) /* or if */
       {
	 Global_Cstr_Stack_Pop
	 Set_Off_Global_Cstr_Stack(CF)  
	 Execute_Constraint(return FALSE;)
       }
   }
 return TRUE;
}



/*-------------------------------------------------------------------------*/
/* EXECUTE_ENLARGEMENT_PROPAGATION                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Execute_Enlargement_Propagation(void)

{
 WamWord         propag;
 WamWord         mask;
 WamWord        *fdv_adr;
 WamWord        *record_adr;
 WamWord        *chain_adr;
 WamWord        *CF;
 WamWord        *BP2;

 BP2 = dummy_fd_var2;
 while(BP2 != TP2)
   {
     BP2=(WamWord *) Queue2_Next_Fdv_Adr(BP2);
     do
       {
	 fdv_adr = (WamWord *) BP2;
	 mask    = Chains_Mask(fdv_adr);
	 propag  = Queue2_Propag_Mask(fdv_adr);
	 Queue2_Propag_Mask(fdv_adr) = 0;
	 chain_adr = &Chain_Sigma(fdv_adr);
	 
	 for( ; mask ; mask >>= 1, propag >>= 1, chain_adr++)
	   if (mask & 1)
	     {
	       record_adr = (WamWord *) (*chain_adr);
	       do
		 {
		   CF = (WamWord *) CF_Pointer(record_adr);

		   if ((propag & 1) && (Is_Active(CF)))
		       Enlarge_Constrained_Variables(CF)		 

		   Reduce_Enlarged_Variables(CF)
		 }
	       while(record_adr = (WamWord *) Next_Chain(record_adr));
	     }
       }
     while (Queue2_Propag_Mask(fdv_adr) != 0);
     Queue2_Date_At_Push(fdv_adr) = 0;
   }
}



/*-------------------------------------------------------------------------*/
/* CSTRS_BLOCK_RETRACTION                                                  */
/*                                                                         */
/*-------------------------------------------------------------------------*/

void Cstrs_Block_Retraction(WamWord *cb)

{  
  WamWord        *cstr_adr;

  Init_Call_Constraint();

  cstr_adr = cb;
  do
    {
      Trail_OV(&Infos(cstr_adr));
      Set_Non_Active(cstr_adr);
    }
  while (cstr_adr = (WamWord *) Next_Cstr(cstr_adr));
  
  propagation_mode = ENLARGEMENT;
  cstr_adr = cb ;
  do
      Enlarge_Constrained_Variables(cstr_adr)
  while (cstr_adr = (WamWord *) Next_Cstr(cstr_adr));

  Execute_Enlargement_Propagation();
  
  propagation_mode = REDUCTION_AFTER_ENLARGEMENT;
  if (!Execute_Propagation()) {};
  
  propagation_mode = REDUCTION;
}



/*-------------------------------------------------------------------------*/
/* CSTRS_BLOCK_ADDITION                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/

Bool Cstrs_Block_Addition(WamWord *CF)

{  
  Init_Call_Constraint();

  do
    {
      Trail_OV(&Infos(CF));
      Set_Active(CF);
      Execute_Constraint(fail)
    }
  while (CF = (WamWord *) Next_Cstr(CF)) ;
  
  if (!Execute_Propagation())                                            
    fail 
}



/*-------------------------------------------------------------------------*/
/* CSTRS_BLOCK_SIZE                                                        */
/*                                                                         */
/*-------------------------------------------------------------------------*/

int Cstrs_Block_Size(WamWord *CF)

{  
  int size = 0 ;

  while(CF)
    {
      CF = (WamWord *) Next_Cstr(CF); 
      size++;
    }
  
  return size;
}


/*-------------------------------------------------------------------------*/
/* IS_ENLARGED_FDV                                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/

Bool Is_Enlarged_FDV(WamWord *fdv_adr)
{
  return (Date_Of_Enlargement(fdv_adr) ==  DATE);
}


/*-------------------------------------------------------------------------*/
/* ENLARGE_FDV                                                             */
/*                                                                         */
/*-------------------------------------------------------------------------*/

void Enlarge_FDV(WamWord *fdv_adr)
{
  if (Date_Of_Enlargement(fdv_adr) < DATE)
    {     
      Compute_Static_Domain(fdv_adr);
      Date_Of_Enlargement(fdv_adr) = DATE;
      /* mark the variable as enlarged */
    }
}



/*-------------------------------------------------------------------------*/
/* COMPUTE_STATIC_DOMAIN                                                   */
/*                                                                         */
/*-------------------------------------------------------------------------*/

void Compute_Static_Domain(WamWord *fdv_adr)
{
  int propag = MASK_EMPTY;

  Vector  old_vec ;
  VecWord old_sigma = Sigma(fdv_adr);
  int     old_min   = Min(fdv_adr);
  int     old_max   = Max(fdv_adr);

  Trail_Range_If_Necessary(fdv_adr) 
    
  switch (Mode(fdv_adr)) 
    {
    case R_SPARSE:      
      Temporary_Vector_Allocate(old_vec);
      Vector_Copy(old_vec,Vec(fdv_adr));
      
      Set_Range_Full(Range(fdv_adr));
      Static_Cstrs_Execution(fdv_adr);
      
      if (Mode(fdv_adr) != R_SPARSE)
	{
	  Set_Def_Mask(propag);    
	  /* approximation */ 
	}
      else
	{
	  if (!Vector_Equal(Vec(fdv_adr),old_vec))
	    Set_Def_Mask(propag);  
	}
      
      if (Has_Def_Mask(propag))
	{
	  if (Sigma(fdv_adr) != old_sigma)                            
	    Set_Sigma_Mask(propag);
	  
	  if (Min(fdv_adr) != old_min)                                  
	    {
	      Set_Min_Mask(propag);
	      Set_Min_Max_Mask(propag);
	    }
	  
	  if (Max(fdv_adr) != old_max)                                  
	    {
	      Set_Max_Mask(propag);
	      Set_Min_Max_Mask(propag);
	    }
	}	
      Temporary_Vector_Free(old_vec);  
      break;

    case R_INTERVAL:
      Set_Range_Full(Range(fdv_adr));
      Static_Cstrs_Execution(fdv_adr);
      
      if (Min(fdv_adr) != old_min || Max(fdv_adr) != old_max || Sigma(fdv_adr) != old_sigma)
	{
	  Set_Def_Mask(propag);    
	  
	  if (Sigma(fdv_adr) != old_sigma)                            
	    Set_Sigma_Mask(propag);
	  
	  if (Min(fdv_adr) != old_min)                                  
	    {
	      Set_Min_Mask(propag);
	      Set_Min_Max_Mask(propag);
	    }
	  
	  if (Max(fdv_adr) != old_max)                                  
	    {
	      Set_Max_Mask(propag);
	      Set_Min_Max_Mask(propag);
	    }
	}
      break;

    case R_INTEGER:
      Set_Range_Full(Range(fdv_adr));
      Static_Cstrs_Execution(fdv_adr);
      
      if (Mode(fdv_adr) != R_INTEGER || Sigma(fdv_adr) != old_sigma)
	{
	  Set_Def_Mask(propag);    
	  
	  if (Sigma(fdv_adr) != old_sigma)                            
	    Set_Sigma_Mask(propag);
	  
	  if (Min(fdv_adr) != old_min)                                  
	    {
	      Set_Min_Mask(propag);
	      Set_Min_Max_Mask(propag);
	    }
	  
	  if (Max(fdv_adr) != old_max)                                  
	    {
	      Set_Max_Mask(propag);
	      Set_Min_Max_Mask(propag);
	    }

	  if (Mode(fdv_adr) != R_INTEGER)
	    Set_Val_Mask(propag);
	}
      break;
    }     
 
  All_Propagations2(fdv_adr,propag);  
}


/*-------------------------------------------------------------------------*/
/* STATIC_CSTRS_EXECUTION                                                  */
/*                                                                         */
/*-------------------------------------------------------------------------*/

void Static_Cstrs_Execution(WamWord *fdv_adr)
{
  WamWord        *record_adr;
  WamWord        *CF;

  if (record_adr = (WamWord *) (Chain_Static(fdv_adr)))
    {
      do
	{
	  CF = (WamWord *) CF_Pointer(record_adr);
	  if (Is_Active(CF))
	    Execute_Constraint({})  
	}
      while(record_adr = (WamWord *) Next_Chain(record_adr));   
    }   
}



/*-------------------------------------------------------------------------*/
/* REDUCE_FDVS                                                             */
/*                                                                         */
/*-------------------------------------------------------------------------*/

void Reduce_FDVs (WamWord *fdv_adr)
{
  All_Propagations(fdv_adr,MASK_FULL);
}



/*-------------------------------------------------------------------------*/
/* UNIFY_FDV_AND_INT (for wam_engine)                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Unify_FDV_And_INT(WamWord *fdv_adr,int i)
{
 int propag;

 switch (Mode(fdv_adr))
   {
   case R_SPARSE:
     if (!IsNullA(ValA_Vector(Vec(fdv_adr),i)))
       {
	 Init_Call_Constraint();                  /* Unify(X,n) == X in n..n */
	 
	 Update_Range_From_Int(fdv_adr,i,UnityA,propag)
	   
         All_Propagations(fdv_adr,propag);
	 
	 return Execute_Propagation();
       }
     else
       return FALSE;
   
   case R_INTERVAL:
     if (Min(fdv_adr) <= i && i <= Max(fdv_adr))
       {
	 Init_Call_Constraint();                  /* Unify(X,n) == X in n..n */
	 
	 Update_Interval_From_Int(fdv_adr,i,UnityA,propag)
	   
	 All_Propagations(fdv_adr,propag);
	 
	 return Execute_Propagation();
       }
     else
       return FALSE;
  
   case R_INTEGER:
     return (Min(fdv_adr) == i);
   }
}



/*-------------------------------------------------------------------------*/
/* UNIFY_FDV_AND_FDV (for wam_engine)                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Unify_FDV_And_FDV(WamWord *fdv_adr1,WamWord *fdv_adr2)

#define Fd_Unify_2   Prefix(X66645F756E696679_2)

{

 Prototype(Fd_Unify_2)
 Bool     ret;
 WamWord *save_reg_bank=reg_bank;
 WamWord  local_reg_bank[REG_BANK_SIZE];

 Switch_Reg_Bank(local_reg_bank);

 A(0)=Tag_Value(REF,fdv_adr1);
 A(1)=Tag_Value(REF,fdv_adr2);

 ret=Call_Prolog((CodePtr) Fd_Unify_2);

 Switch_Reg_Bank(save_reg_bank);

 return ret;

}


/*-------------------------------------------------------------------------*/
/* FD_VARIABLE_SIZE                                                        */
/*                                                                         */
/*-------------------------------------------------------------------------*/
int Fd_Variable_Size(WamWord *fdv_adr)

{
 int size=FD_VARIABLE_FRAME_SIZE;

 size+=vec_size;

 return 1+size;         /* 1+ for <REF,->fdv_adr> since Global_UnMove(FDV) */
}




/*-------------------------------------------------------------------------*/
/* COPY_FD_VARIABLE                                                        */
/*                                                                         */
/* also returns the size of the created fd var (like FD_TERM_SIZE)         */
/*-------------------------------------------------------------------------*/
int Copy_Fd_Variable(WamWord *dst_adr,WamWord *fdv_adr)

{
 WamWord *savH;
 int      size;

 savH=H;
 H=dst_adr;

 Push_Fd_Variable();

 Range_Copy(Range(dst_adr),Range(fdv_adr));

 size=H-dst_adr;
 H=savH;

 return size;
}



/*-------------------------------------------------------------------------*/
/* PROLOG_RANGE_TO_RANGE                                                   */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Prolog_Range_To_Range(WamWord *start_adr,Range *range)

{
 WamWord  word,tag,*adr;
 WamWord *cur_adr;

 range->mode = R_SPARSE;
 Vector_Allocate(range->vec);
 Set_Vector_Empty(range->vec);

 Deref(*start_adr,word,tag,adr)

 while(word!=word_nil)
    {
     if (tag!=LST)
         return FALSE;

     adr=UnTag_LST(word);
     cur_adr=&Car(adr);
     start_adr=&Cdr(adr);
     Deref(*cur_adr,word,tag,adr)
     
     if (tag!=INT)
       return FALSE ;

     word=UnTag_INT(word);
     
     if (word>=0 && word<=vec_infinity)
       Set_ValA_Unity_Vector(range->vec,word);

     Deref(*start_adr,word,tag,adr)
    }

 Range_From_Vector(range);

 return TRUE;
}


/*-------------------------------------------------------------------------*/
/* WRITE_FD_VARIABLE                                                       */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Write_Fd_Variable(FILE *out,WamWord *fdv_adr)

{
 Range_Write(out,Range(fdv_adr));
}


