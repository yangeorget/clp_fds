/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - LOCO Project  */
/* C Run-time                                          Daniel Diaz - 1992  */
/*                                                                         */
/* Modified by Yan Georget - June 1998                                     */
/* sfd_engine.h                                                            */
/*-------------------------------------------------------------------------*/


#include "bool.h"
#include "sfd_range.h"


/*---------------------------------*/
/* Constants                       */
/*---------------------------------*/

          /* FD Range/Term Registers */

#define T(t)                       (CPP_CAT(tr,t))
#define R(r)                       (CPP_CAT(rr,r))


          /* FD Variable Frame */

#define FD_VARIABLE_FRAME_SIZE     (OFFSET_RANGE+RANGE_SIZE+CHAINS_SIZE)

#define OFFSET_RANGE               9
#define RANGE_SIZE                 (1+(sizeof(Range)/sizeof(WamWord)))

#define OFFSET_CHAINS              (OFFSET_RANGE+RANGE_SIZE)
#define CHAINS_SIZE                9


#define FD_Tag_Value(fdv_adr)      (((WamWord *) fdv_adr)[0])

/* to reduce */
#define Queue_Date_At_Push(fdv_adr)(((WamWord *) fdv_adr)[1])
#define Queue_Propag_Mask(fdv_adr) (((WamWord *) fdv_adr)[2])
#define Queue_Next_Fdv_Adr(fdv_adr)(((WamWord *) fdv_adr)[3])

/* to enlarge */
#define Queue2_Date_At_Push(fdv_adr)(((WamWord *) fdv_adr)[4])
#define Queue2_Propag_Mask(fdv_adr) (((WamWord *) fdv_adr)[5])
#define Queue2_Next_Fdv_Adr(fdv_adr)(((WamWord *) fdv_adr)[6])

#define Date_Of_Enlargement(fdv_adr)(((WamWord *) fdv_adr)[7])

#define Cstrs_Block(fdv_adr)        (((WamWord *) fdv_adr)[8])

#define Range_Stamp(fdv_adr)       (((WamWord *) fdv_adr)[OFFSET_RANGE])
#define Range(fdv_adr)             ((Range *) ((WamWord *) fdv_adr+OFFSET_RANGE+1))

#define Chains_Stamp(fdv_adr)      (((WamWord *) fdv_adr)[OFFSET_CHAINS])
#define Chains_Mask(fdv_adr)       (((WamWord *) fdv_adr)[OFFSET_CHAINS+1])
#define Chain_Sigma(fdv_adr)       (((WamWord *) fdv_adr)[OFFSET_CHAINS+2])
#define Chain_Def(fdv_adr)         (((WamWord *) fdv_adr)[OFFSET_CHAINS+3])
#define Chain_Min(fdv_adr)         (((WamWord *) fdv_adr)[OFFSET_CHAINS+4])
#define Chain_Max(fdv_adr)         (((WamWord *) fdv_adr)[OFFSET_CHAINS+5])
#define Chain_Min_Max(fdv_adr)     (((WamWord *) fdv_adr)[OFFSET_CHAINS+6])
#define Chain_Val(fdv_adr)         (((WamWord *) fdv_adr)[OFFSET_CHAINS+7])
#define Chain_Static(fdv_adr)      (((WamWord *) fdv_adr)[OFFSET_CHAINS+8])


          /* Shorthands for Range(fdv_adr)'s fields */

#define Sigma(fdv_adr)             ((Range(fdv_adr))->sigma)
#define Vec(fdv_adr)               ((Range(fdv_adr))->vec)
#define Min(fdv_adr)               ((Range(fdv_adr))->min)
#define Max(fdv_adr)               ((Range(fdv_adr))->max)
#define Mode(fdv_adr)              ((Range(fdv_adr))->mode)



          /* Chain / Propagation Mask */

#define CHAIN_NB_SIGMA             0
#define CHAIN_NB_DEF               1
#define CHAIN_NB_MIN               2
#define CHAIN_NB_MAX               3
#define CHAIN_NB_MIN_MAX           4
#define CHAIN_NB_VAL               5
#define CHAIN_NB_STATIC            6


#define MASK_EMPTY                 0
#define MASK_SIGMA                 1
#define MASK_DEF                   2
#define MASK_MIN                   4
#define MASK_MAX                   8
#define MASK_MIN_MAX              16
#define MASK_VAL                  32
#define MASK_STATIC               64
#define MASK_FULL                 63


#define Has_Sigma_Mask(mask)       ((mask) & MASK_SIGMA)
#define Has_Def_Mask(mask)         ((mask) & MASK_DEF)
#define Has_Min_Mask(mask)         ((mask) & MASK_MIN)
#define Has_Max_Mask(mask)         ((mask) & MASK_MAX)
#define Has_Min_Max_Mask(mask)     ((mask) & MASK_MIN_MAX)
#define Has_Val_Mask(mask)         ((mask) & MASK_VAL)
#define Has_Static_Mask(mask)      ((mask) & MASK_STATIC)


#define Set_Sigma_Mask(mask)       ((mask) |= MASK_SIGMA);
#define Set_Def_Mask(mask)         ((mask) |= MASK_DEF);
#define Set_Min_Mask(mask)         ((mask) |= MASK_MIN);
#define Set_Max_Mask(mask)         ((mask) |= MASK_MAX);
#define Set_Min_Max_Mask(mask)     ((mask) |= MASK_MIN_MAX);
#define Set_Val_Mask(mask)         ((mask) |= MASK_VAL);
#define Set_Static_Mask(mask)      ((mask) |= MASK_STATIC);


          /* Chain Record Frame */

#define CHAIN_RECORD_FRAME_SIZE    2

#define CF_Pointer(rec_adr)        (rec_adr[0])
#define Next_Chain(rec_adr)        (rec_adr[1])


          /* Constraint Frame */

#define CONSTRAINT_FRAME_SIZE      7

#define AF_Pointer(cf)               (cf[0])
#define Cstr_Address(cf)             (cf[1])
#define Enlargement_Address(cf)      (cf[2])
#define Test_Enlargement_Address(cf) (cf[3])
#define Reduction_Address(cf)        (cf[4])
#define Infos(cf)                    (cf[5])
#define Next_Cstr(cf)                (cf[6])

#define Is_Active(cf)                (Infos(cf) & TAG_ACTIVE_CSTR)
#define Is_Global_Cstr(cf)           (Infos(cf) & TAG_GLOBAL_CSTR)
#define Is_On_Global_Cstr_Stack(cf)  (Infos(cf) & TAG_GLOBAL_CSTR_STACK)

#define Set_Active(cf)                 (Infos(cf) |=  TAG_ACTIVE_CSTR);
#define Set_Non_Active(cf)             (Infos(cf) &= ~TAG_ACTIVE_CSTR);
#define Set_Global_Cstr(cf)            (Infos(cf) |=  TAG_GLOBAL_CSTR);
#define Set_On_Global_Cstr_Stack(cf)   (Infos(cf) |=  TAG_GLOBAL_CSTR_STACK);
#define Set_Off_Global_Cstr_Stack(cf)  (Infos(cf) &= ~TAG_GLOBAL_CSTR);


#define TAG_ACTIVE_CSTR         1
#define TAG_GLOBAL_CSTR         2
#define TAG_GLOBAL_CSTR_STACK   4


#define Cstr_Fct_To_WamWord(f)             ((WamWord) (f))
#define WamWord_To_Cstr_Fct(w)             ((Bool (*)()) (w))
#define WamWord_To_Enlargement_Fct(w)      ((void (*)()) (w))
#define WamWord_To_Test_Enlargement_Fct(w) ((Bool (*)()) (w))
#define WamWord_To_Reduction_Fct(w)        ((void (*)()) (w))


          /* Global Constraint Stack */

#define GLOBAL_CSTR_STACK_SIZE 20000

#define Global_Cstr_Stack_Push       (global_cstr_stack[GCS++] = CF);  
#define Global_Cstr_Stack_Pop        (CF = global_cstr_stack[--GCS]);

#define Is_Global_Cstr_Stack_Empty    (GCS == 0)
#define Set_Global_Cstr_Stack_Empty   (GCS = 0 );


          /* Argument Frame */

#define Frame_Variable(fv)         ((WamWord *)(AF[fv]))
#define Frame_Range_Parameter(fp)  ((Range *)  (AF[fp]))
#define Frame_Term_Parameter(fp)   ((VecWord)  (AF[fp]))


          /* Miscellaneous */

#define REDUCTION                   0
#define ENLARGEMENT                 1
#define REDUCTION_AFTER_ENLARGEMENT 2




#define ENV_VAR_VECTOR_MAX          "VECTORMAX"
#define DEFAULT_VECTOR_MAX          127


#define Decl_Fd_Install_Vars                                                \
     WamWord *CF;                                                           \
     WamWord *fdv_adr;


#define Decl_Fd_Constraint_Vars                                             \
     WamWord *AF=(WamWord *) AF_Pointer(CF);                                \
     WamWord word,*fdv_adr;                                                 \
     int     tr0, tr1, tr2, tr3, tr4, tr5, tr6, tr7,                        \
             tr8, tr9, tr10,tr11,tr12,tr13,tr14,tr15,                       \
             tr16,tr17,tr18,tr19,tr20,tr21,tr22,tr23;                       \
     Range   rr0, rr1, rr2, rr3, rr4, rr5, rr6, rr7,                        \
             rr8, rr9, rr10,rr11,rr12,rr13,rr14,rr15,                       \
             rr16,rr17,rr18,rr19,rr20,rr21,rr22,rr23;


#define Decl_Fd_Enlargement_Vars                                            \
     WamWord *AF=(WamWord *) AF_Pointer(CF);                                \
     WamWord *fdv_adr;


#define Decl_Fd_Test_Enlargement_Vars                                       \
     WamWord *AF=(WamWord *) AF_Pointer(CF);                                \
     WamWord *fdv_adr;


#define Decl_Fd_Reduction_Vars                                              \
     WamWord *AF=(WamWord *) AF_Pointer(CF);                                \
     WamWord *fdv_adr;


#define math_min(x,y)              ((x) <= (y) ? (x) : (y))
#define math_max(x,y)              ((x) >= (y) ? (x) : (y))


          /* Errors Messages */

#define ERR_ILLEGAL_RANGE_PARAM "FD Constraint: Illegal range parameter\n"

#define ERR_ILLEGAL_TERM_PARAM  "FD Constraint: Illegal term parameter\n"



/*---------------------------------*/
/* Type Definitions                */
/*---------------------------------*/

/*---------------------------------*/
/* Global Variables                */
/*---------------------------------*/


WamWord *last_CF;  /* this variable is trailed */


#ifdef FD_ENGINE

       AtomInf  *atom_infinity;
#else

extern AtomInf  *atom_infinity;

#endif



/*---------------------------------*/
/* Function Prototypes             */
/*---------------------------------*/

void      Init_Fd_Engine        (void);

void      Term_Fd_Engine        (void);

void      Push_Fd_Variable      (void);
void      Push_Fd_Int_Variable  (int n);

WamWord  *Check_For_Fd_Variable (WamWord start_word);

WamWord  *Create_C_Frame        (Bool (*cstr_fct)(),
				 void (*enlargement_fct)(),
				 Bool (*test_enlargement_fct)(),
				 void (*reduction_fct)(),
				 WamWord *AF);

void      Add_Record_In_Chain       (WamWord *fdv_adr,
				     int chain_nb,WamWord *CF);
void      Add_Record_In_Static_Chain(WamWord *fdv_adr,
				     WamWord *CF);

void      Init_Call_Constraint  (void);

Bool      Execute_Propagation             (void);
void      Execute_Enlargement_Propagation (void);

void      Cstrs_Block_Retraction  (WamWord *cb_adr);
Bool      Cstrs_Block_Addition    (WamWord *cb_adr);
int       Cstrs_Block_Size        (WamWord *cb_adr);

Bool      Tell_Range_Range      (WamWord *fdv_adr,Range *range);
Bool      Tell_Range_Integer    (WamWord *fdv_adr, int i, VecWord v);
Bool      Tell_Interval_Range   (WamWord *fdv_adr,Range *range);
Bool      Tell_Interval_Interval(WamWord *fdv_adr, int min, int max, VecWord v);
Bool      Tell_Interval_Integer (WamWord *fdv_adr, int i, VecWord v);
Bool      Tell_Integer_Range    (WamWord *fdv_adr, Range *range);
Bool      Tell_Integer_Interval (WamWord *fdv_adr, int min, int max, VecWord v);
Bool      Tell_Integer_Integer  (WamWord *fdv_adr, int i, VecWord v);


void      Enlarge_FDV           (WamWord *fdv_adr);
Bool      Is_Enlarged_FDV       (WamWord *fdv_adr);
void      Compute_Static_Domain (WamWord *fdv_adr);
void      Static_Cstrs_Execution(WamWord *fdv_adr);
void      Reduce_FDVs           (WamWord *fdv_adr);

Bool      Unify_FDV_And_FDV     (WamWord *fdv_adr1,WamWord *fdv_adr2);
Bool      Unify_FDV_And_INT     (WamWord *fdv_adr,int n) ;

int       Fd_Variable_Size      (WamWord *fdv_adr);

int       Copy_Fd_Variable      (WamWord *dst_adr,WamWord *fdv_adr);

Bool      Prolog_Range_To_Range (WamWord *adr,Range *range);

void      Write_Fd_Variable     (FILE *out,WamWord *fdv_adr);



/*---------------------------------*/
/* Auxiliary engine macros         */
/*---------------------------------*/

#define Is_An_FDV_Tagged_Word(word)     (Tag_Of(word)==FDV)


#define Fail_In_Constraint                                                  \
     return(FALSE);


#define Execute_Constraint(fail_code)                                       \
     if (!(*WamWord_To_Cstr_Fct(Cstr_Address(CF)))(CF))                     \
        { fail_code }


#define Enlarge_Constrained_Variables(cf)                                   \
     (*WamWord_To_Enlargement_Fct(Enlargement_Address(cf)))(cf) ;              


#define Test_Enlarged_Variables(cf)                                         \
     (*WamWord_To_Test_Enlargement_Fct(Test_Enlargement_Address(cf)))(cf)  


#define Reduce_Enlarged_Variables(cf)                                       \
     (*WamWord_To_Reduction_Fct(Reduction_Address(cf)))(cf) ;              




/*---------------------------------*/
/* FD engine macros (fd inst->C)   */
/*---------------------------------*/

          /* Interface with Prolog clauses instructions */

#define fd_set_x_AF(nb_arg,x)                                               \
    {                                                                       \
     X(x)=(WamWord) (AF=H);                                                 \
     H += nb_arg;                                                           \
    }


#define fd_set_y_AF(nb_arg,y)                                               \
    {                                                                       \
     Y(E,y)=(WamWord) (AF=H);                                               \
     H += nb_arg;                                                           \
    }


#define fd_x_variable_in_A_frame(x)                                         \
    {                                                                       \
     X(x)=Tag_Value(REF,H);                                                 \
     *AF++ =(WamWord) H;                                                    \
     Push_Fd_Variable();                                                    \
    }


#define fd_x_value_in_A_frame(x)                                            \
    {                                                                       \
     WamWord *fdv_adr=Check_For_Fd_Variable(X(x));                          \
     if (fdv_adr==NULL)                                                     \
         {fail}                                                             \
     *AF++=(WamWord) fdv_adr;                                               \
    }


#define fd_y_variable_in_A_frame(y)                                         \
    {                                                                       \
     Y(E,y)=Tag_Value(REF,H);                                               \
     *AF++ =(WamWord) H;                                                    \
     Push_Fd_Variable();                                                    \
    }


#define fd_y_value_in_A_frame(y)                                            \
    {                                                                       \
     WamWord *fdv_adr=Check_For_Fd_Variable(Y(E,y));                        \
     if (fdv_adr==NULL)                                                     \
         fail                                                               \
     *AF++=(WamWord) fdv_adr;                                               \
    }


#define fd_x_range_parameter_in_A_frame(x)                                  \
    {                                                                       \
     *AF=(WamWord) H;                                                       \
     H += sizeof(Range) / sizeof(WamWord);                                  \
     if (!Prolog_Range_To_Range(&X(x),(Range *) *AF))                       \
        {                                                                   \
         Lib1(printf,ERR_ILLEGAL_RANGE_PARAM);                              \
         fail                                                               \
        }                                                                   \
     AF++;                                                                  \
    }


#define fd_y_range_parameter_in_A_frame(y)                                  \
    {                                                                       \
     *AF=(WamWord) H;                                                       \
     H += sizeof(Range) / sizeof(WamWord);                                  \
     if (!Prolog_Range_To_Range(&Y(E,y),(Range *) *AF++))                   \
        {                                                                   \
         Lib1(printf,ERR_ILLEGAL_RANGE_PARAM);                              \
         fail                                                               \
        }                                                                   \
    }


#define fd_x_term_parameter_in_A_frame(x)                                   \
    {                                                                       \
     Deref(X(x),word,tag,adr)                                               \
     if (tag!=INT)                                                          \
        {                                                                   \
         Lib1(printf,ERR_ILLEGAL_TERM_PARAM);                               \
         fail                                                               \
        }                                                                   \
     *AF++ =UnTag_INT(word);                                                \
    }


#define fd_y_term_parameter_in_A_frame(y)                                   \
    {                                                                       \
     Deref(Y(E,y),word,tag,adr)                                             \
     if (tag!=INT)                                                          \
        {                                                                   \
         Lib1(printf,ERR_ILLEGAL_TERM_PARAM);                               \
         fail                                                               \
        }                                                                   \
     *AF++ =UnTag_INT(word);                                                \
    }


#define fd_install_constraint_with_x_AF(inst_nb,x)                          \
    {                                                                       \
     Fd_Install_Prototyp(inst_nb)                                           \
                                                                            \
     AF=(WamWord *) X(x);                                                   \
     CF=H;                              /* also assigned in install fcts */ \
     if (!Install_Fct_Name(inst_nb)(AF))                                    \
         fail                                                               \
    }


#define fd_install_constraint_with_y_AF(inst_nb,y)                          \
    {                                                                       \
     Fd_Install_Prototyp(inst_nb)                                           \
                                                                            \
     AF=(WamWord *) Y(E,y);                                                 \
     CF=H;                              /* also assigned in install fcts */ \
     if (!Install_Fct_Name(inst_nb)(AF))                                    \
         fail                                                               \
    }


#define fd_call_constraint                                                  \
    {                                                                       \
     Init_Call_Constraint();                                                \
     Execute_Constraint(fail)                                               \
     if (!Execute_Propagation())                                            \
         fail                                                               \
    }



          /* Install instructions */

#define fd_create_C_frame(cstr_nb)                                          \
    {                                                                       \
     Fd_Constraint_Prototyp(cstr_nb)                                        \
     Fd_Enlargement_Prototyp(cstr_nb)                                       \
     Fd_Test_Enlargement_Prototyp(cstr_nb)                                  \
     Fd_Reduction_Prototyp(cstr_nb)                                         \
                                                                            \
                         /* warning CF also assigned in caller predicate */ \
     CF=Create_C_Frame(Constraint_Fct_Name(cstr_nb),                        \
		       Enlargement_Fct_Name(cstr_nb),                       \
		       Test_Enlargement_Fct_Name(cstr_nb),                  \
                       Reduction_Fct_Name(cstr_nb),                         \
                       AF);                                                 \
     Trail_OV(&last_CF);                                                    \
     last_CF = CF;                                                          \
    }


#define fd_global_constraint                                                \
     Set_Global_Cstr(CF);


#define fd_static_constraint(fv)                                            \
    {                                                                       \
     fdv_adr=Frame_Variable(fv);                                            \
     Add_Record_In_Static_Chain(fdv_adr,CF);                                \
    }


#define fd_install_ind_sigma(fv)                                            \
    {                                                                       \
     fdv_adr=Frame_Variable(fv);                                            \
     Add_Record_In_Chain(fdv_adr,CHAIN_NB_SIGMA,CF);                        \
    }

 
#define fd_install_ind_def(fv)                                              \
    {                                                                       \
     fdv_adr=Frame_Variable(fv);                                            \
     Add_Record_In_Chain(fdv_adr,CHAIN_NB_DEF,CF);                          \
    }
 

#define fd_install_ind_min(fv)                                              \
    {                                                                       \
     fdv_adr=Frame_Variable(fv);                                            \
     Add_Record_In_Chain(fdv_adr,CHAIN_NB_MIN,CF);                          \
    }


#define fd_install_ind_max(fv)                                              \
    {                                                                       \
     fdv_adr=Frame_Variable(fv);                                            \
     Add_Record_In_Chain(fdv_adr,CHAIN_NB_MAX,CF);                          \
    }


#define fd_install_ind_min_max(fv)                                          \
    {                                                                       \
     fdv_adr=Frame_Variable(fv);                                            \
     Add_Record_In_Chain(fdv_adr,CHAIN_NB_MIN_MAX,CF);                      \
    }


#define fd_install_ind_val(fv)                                              \
    {                                                                       \
     fdv_adr=Frame_Variable(fv);                                            \
     Add_Record_In_Chain(fdv_adr,CHAIN_NB_VAL,CF);                          \
    }



          /* Constraint instructions */

#define fd_allocate                                                         \
    {                                                                       \
     save_H=H;                                                              \
     H+=vec_size;                                                           \
    }


#define fd_proceed                                                          \
    {                                                                       \
     return(TRUE);                                                          \
    }


#define fd_tell_integer(fv,tindex)                                          \
    {                                                                       \
     fdv_adr=(WamWord *) Frame_Variable(fv) ;                               \
                                                                            \
     switch(Mode(fdv_adr))                                                  \
        {                                                                   \
           case R_SPARSE:                                                   \
             if (!Tell_Range_Integer(fdv_adr,T(tindex),UnityA))             \
                Fail_In_Constraint                                          \
             break;                                                         \
           case R_INTERVAL:                                                 \
             if (!Tell_Interval_Integer(fdv_adr,T(tindex),UnityA))          \
                Fail_In_Constraint                                          \
             break;                                                         \
           case R_INTEGER:                                                  \
             if (!Tell_Integer_Integer(fdv_adr,T(tindex),UnityA))           \
                Fail_In_Constraint                                          \
             break;                                                         \
          default:                                                          \
	     Fail_In_Constraint                                             \
             break;                                                         \
	 }                                                                  \
     }


#define fd_tell_integer_value(fv,tindex,tvalue)                             \
    {                                                                       \
     fdv_adr=(WamWord *) Frame_Variable(fv) ;                               \
                                                                            \
     switch(Mode(fdv_adr))                                                  \
        {                                                                   \
           case R_SPARSE:                                                   \
             if (!Tell_Range_Integer(fdv_adr,T(tindex),T(tvalue)))          \
                Fail_In_Constraint                                          \
             break;                                                         \
           case R_INTERVAL:                                                 \
             if (!Tell_Interval_Integer(fdv_adr,T(tindex),T(tvalue)))       \
                Fail_In_Constraint                                          \
             break;                                                         \
           case R_INTEGER:                                                  \
             if (!Tell_Integer_Integer(fdv_adr,T(tindex),T(tvalue)))        \
                Fail_In_Constraint                                          \
             break;                                                         \
          default:                                                          \
             Fail_In_Constraint                                             \
             break;                                                         \
	 }                                                                  \
    }


#define fd_tell_interval(fv,tmin,tmax)                                      \
    {                                                                       \
     fdv_adr=(WamWord *) Frame_Variable(fv) ;                               \
                                                                            \
     switch(Mode(fdv_adr))                                                  \
        {                                                                   \
           case R_SPARSE:                                                   \
             save_H=H;                                                      \
             Init_Range_Interval(&R(0),T(tmin),T(tmax),UnityA);             \
             if (!Tell_Range_Range(fdv_adr,&R(0)))                          \
                Fail_In_Constraint                                          \
             break;                                                         \
           case R_INTERVAL:                                                 \
             if (!Tell_Interval_Interval(fdv_adr,T(tmin),T(tmax),UnityA))   \
                Fail_In_Constraint                                          \
             break;                                                         \
           case R_INTEGER:                                                  \
             if (!Tell_Integer_Interval(fdv_adr,T(tmin),T(tmax),UnityA))    \
                Fail_In_Constraint                                          \
             break;                                                         \
          default:                                                          \
             Fail_In_Constraint                                             \
             break;                                                         \
	 }                                                                  \
     }


#define fd_tell_interval_value(fv,tmin,tmax,tvalue)                         \
    {                                                                       \
     fdv_adr=(WamWord *) Frame_Variable(fv) ;                               \
                                                                            \
     switch(Mode(fdv_adr))                                                  \
        {                                                                   \
           case R_SPARSE:                                                   \
             save_H=H;                                                      \
             Init_Range_Interval(&R(0),T(tmin),T(tmax),T(tvalue));          \
             if (!Tell_Range_Range(fdv_adr,&R(0)))                          \
                Fail_In_Constraint                                          \
             break;                                                         \
           case R_INTERVAL:                                                 \
             if (!Tell_Interval_Interval(fdv_adr,T(tmin),T(tmax),T(tvalue)))\
                Fail_In_Constraint                                          \
             break;                                                         \
           case R_INTEGER:                                                  \
             if (!Tell_Integer_Interval(fdv_adr,T(tmin),T(tmax),T(tvalue))) \
                Fail_In_Constraint                                          \
             break;                                                         \
          default:                                                          \
             Fail_In_Constraint                                             \
             break;                                                         \
	 }                                                                  \
     }


#define fd_tell_range(fv,r)                                                 \
    {                                                                       \
     fdv_adr=(WamWord *) Frame_Variable(fv) ;                               \
                                                                            \
     switch(Mode(fdv_adr))                                                  \
        {                                                                   \
           case R_SPARSE:                                                   \
             if (!Tell_Range_Range(fdv_adr,&R(r)))                          \
                Fail_In_Constraint                                          \
             break;                                                         \
           case R_INTERVAL:                                                 \
             if (!Tell_Interval_Range(fdv_adr,&R(r)))                       \
                Fail_In_Constraint                                          \
             break;                                                         \
           case R_INTEGER:                                                  \
             if (!Tell_Integer_Range(fdv_adr,&R(r)))                        \
                Fail_In_Constraint                                          \
             break;                                                         \
          default:                                                          \
             Fail_In_Constraint                                             \
             break;                                                         \
	 }                                                                  \
     }


#define fd_enlarge_var(fv)                                                  \
    {                                                                       \
     fdv_adr=(WamWord *) Frame_Variable(fv) ;                               \
     Enlarge_FDV(fdv_adr);                                                  \
    }


#define get_test_enlargement_var(fv)                                        \
    Is_Enlarged_FDV((WamWord *) Frame_Variable(fv))


#define fd_test_enlargement_var(fv)                                         \
     return (get_test_enlargement_var(fv));


#define fd_reduce_vars(fv)                                                  \
    {                                                                       \
     fdv_adr=(WamWord *) Frame_Variable(fv) ;                               \
     Reduce_FDVs(fdv_adr);                                                  \
    }


#define fd_cstrs_block_start                                                \
    Trail_OV(&last_CF);                                                     \
    last_CF = NULL;


#define fd_cstrs_block_start_from(cb_adr)                                   \
    Trail_OV(&last_CF);                                                     \
    last_CF = cb_adr;


#define fd_cstrs_block_end(cb_adr)                                          \
    cb_adr = last_CF; 


#define fd_cstrs_block_retract(cb_adr)                                      \
    {                                                                       \
       if (cb_adr)                                                          \
           Cstrs_Block_Retraction(cb_adr);                                  \
    }     


#define fd_cstrs_block_tell(cb_adr)                                         \
    {                                                                       \
      if (cb_adr)                                                           \
         if (!Cstrs_Block_Addition(cb_adr))                                 \
            fail                                                            \
    }


#define fd_cstrs_block_size(cb_adr,size)                                    \
    size = Cstrs_Block_Size(cb_adr);
 


         /* Range */


#define fd_range_parameter(r,fp)                                            \
    Init_Range_Range(&R(r),Frame_Range_Parameter(fp));


#define fd_interval_range(r,tmin,tmax)                                      \
    Init_Range_Interval(&R(r),T(tmin),T(tmax),UnityA);


#define fd_comp_term(r,t)                                                   \
    Init_Range_Comp_Term(&R(r),T(t));                    


#define fd_ind_sigma(t,fv)                                                  \
    T(t) = Sigma(Frame_Variable(fv));


#define fd_ind_def(r,fv)                                                    \
    Init_Range_Range(&R(r),Range(Frame_Variable(fv)));


#define fd_ind_sigma_def(t,r,fv)                                            \
    {                                                                       \
      fdv_adr = Frame_Variable(fv);                                         \
      Init_Range_Range(&R(r),Range(fdv_adr));                               \
      T(t) = Sigma(fdv_adr);                                                \
    }


#define fd_ind_min(t,fv)                                                    \
    T(t) = Min(Frame_Variable(fv));


#define fd_ind_max(t,fv)                                                    \
    T(t) = Max(Frame_Variable(fv));


#define fd_ind_min_max(tmin,tmax,fv)                                        \
    {                                                                       \
     fdv_adr=Frame_Variable(fv);                                            \
     T(tmin)=Min(fdv_adr);                                                  \
     T(tmax)=Max(fdv_adr);                                                  \
    }


#define fd_ind_sigma_min(tsigma,tmin,fv)                                    \
    {                                                                       \
     fdv_adr=Frame_Variable(fv);                                            \
     T(tmin)=Min(fdv_adr);                                                  \
     T(tsigma)=Sigma(fdv_adr);                                              \
    }


#define fd_ind_sigma_max(tsigma,tmax,fv)                                    \
    {                                                                       \
     fdv_adr=Frame_Variable(fv);                                            \
     T(tmax)=Max(fdv_adr);                                                  \
     T(tsigma)=Sigma(fdv_adr);                                              \
    }


#define fd_ind_sigma_min_max(tsigma,tmin,tmax,fv)                           \
    {                                                                       \
     fdv_adr=Frame_Variable(fv);                                            \
     T(tsigma)=Sigma(fdv_adr);                                              \
     T(tmin)=Min(fdv_adr);                                                  \
     T(tmax)=Max(fdv_adr);                                                  \
    }


#define fd_ind_val(t,fv,l_else)                                             \
    {                                                                       \
     fdv_adr=Frame_Variable(fv);                                            \
     if (Mode(fdv_adr) == R_INTEGER)                                        \
         T(t)=Min(fdv_adr);                                                 \
     else                                                                   \
         goto Label_Name(l_else);                                           \
    }


#define fd_ind_sigma_val(tsigma,tval,fv,l_else)                             \
    {                                                                       \
     fdv_adr=Frame_Variable(fv);                                            \
     if (Mode(fdv_adr) == R_INTEGER)                                        \
       {                                                                    \
         T(tsigma) = Sigma(fdv_adr);                                        \
         T(tval)   = Min(fdv_adr);                                          \
       }                                                                    \
     else                                                                   \
         goto Label_Name(l_else);                                           \
    }


#define fd_add_range_range(r,r1)                                            \
     Add_Range_Range(&R(r),&R(r1));


#define fd_sub_range_range(r,r1)                                            \
     Sub_Range_Range(&R(r),&R(r1));


#define fd_mul_range_range(r,r1)                                            \
     Mul_Range_Range(&R(r),&R(r1));


#define fd_div_range_range(r,r1)                                            \
     Div_Range_Range(&R(r),&R(r1));


#define fd_add_range_term(r,t)                                              \
     Add_Range_Term(&R(r),T(t));


#define fd_sub_range_term(r,t)                                              \
     Sub_Range_Term(&R(r),T(t));


#define fd_mul_range_term(r,t)                                              \
     Mul_Range_Term(&R(r),T(t));


#define fd_div_range_term(r,t)                                              \
     Div_Range_Term(&R(r),T(t));


#define fd_le(r)                                                            \
     Range_LeA(&R(r));


#define fd_l(r)                                                             \
     Range_LA(&R(r));


#define fd_ge(r)                                                            \
     Range_GeA(&R(r));


#define fd_g(r)                                                             \
     Range_GA(&R(r));


#define fd_d(r)                                                             \
     Range_DA(&R(r));


#define fd_cut_l_range_term(r,t)                                            \
     Range_Cut_L_A_Term(&R(r),T(t));


#define fd_cut_le_range_term(r,t)                                           \
     Range_Cut_Le_A_Term(&R(r),T(t));


#define fd_cut_g_range_term(r,t)                                            \
     Range_Cut_G_A_Term(&R(r),T(t));


#define fd_cut_ge_range_term(r,t)                                           \
     Range_Cut_Ge_A_Term(&R(r),T(t));


#define fd_cut_d_range_term(r,t)                                            \
     Range_Cut_D_A_Term(&R(r),T(t));


#define fd_cut_np_range_term(r,t)                                           \
     Range_Cut_Np_A_Term(&R(r),T(t));


#define fd_cut_nnp_range_term(r,t)                                          \
     Range_Cut_Nnp_A_Term(&R(r),T(t));


#define fd_keep_l_range_term(r,t)                                           \
     Range_Keep_L_A_Term(&R(r),T(t));


#define fd_keep_le_range_term(r,t)                                          \
     Range_Keep_Le_A_Term(&R(r),T(t));


#define fd_keep_g_range_term(r,t)                                           \
     Range_Keep_G_A_Term(&R(r),T(t));


#define fd_keep_ge_range_term(r,t)                                          \
     Range_Keep_Ge_A_Term(&R(r),T(t));


#define fd_keep_d_range_term(r,t)                                           \
     Range_Keep_D_A_Term(&R(r),T(t));


#define fd_keep_np_range_term(r,t)                                          \
     Range_Keep_Np_A_Term(&R(r),T(t));


#define fd_keep_nnp_range_term(r,t)                                         \
     Range_Keep_Nnp_A_Term(&R(r),T(t));


#define fd_range_addA_range(r,r1)                                           \
     Range_AddA_Range(&R(r),&R(r1));


#define fd_range_mulA_range(r,r1)                                           \
     Range_MulA_Range(&R(r),&R(r1));


#define fd_range_addA_term(r,t)                                             \
     Range_AddA_Term(&R(r),T(t));


#define fd_range_mulA_term(r,t)                                             \
     Range_MulA_Term(&R(r),T(t));


#define fd_range_copy(r,r1)                                                 \
    Init_Range_Range(&R(r),&R(r1));


#define fd_range_fct(fct_name,r,args)                                       \
    {                                                                       \
     R(r).vec=NULL;                                                         \
     fct_name(&R(r),args);                                                  \
    }



          /* term */

#define fd_integer(t,n)                                                     \
     T(t)= n;


#define fd_term_parameter(t,fp)                                             \
     T(t)=Frame_Term_Parameter(fp);


#define fd_term_addA_term(t,t1)                                             \
     T(t) = AddA(T(t),T(t1));


#define fd_term_mulA_term(t,t1)                                             \
     T(t) = MulA(T(t),T(t1));


#define fd_add_term_term(t,t1)                                              \
     T(t) += T(t1);


#define fd_sub_term_term(t,t1)                                              \
     T(t) -= T(t1);


#define fd_mul_term_term(t,t1)                                              \
     T(t) = M_Mul(T(t),T(t1));


#define fd_floor_div_term_term(t,t1)                                        \
    T(t) = M_Floor_Div(T(t),T(t1));


#define fd_ceil_div_term_term(t,t1)                                         \
     T(t) = M_Ceil_Div(T(t),T(t1));


#define fd_term_mod_term(t,t1)                                              \
     T(t) = M_Mod(T(t),T(t1));


#define fd_term_copy(t,t1)                                                  \
     T(t) = T(t1);


#define fd_term_fct(fct_name,t,args)                                        \
     T(t)=fct_name(args);



#define arg_1(a1)                          a1
#define arg_2(a1,a2)                       a1,a2
#define arg_3(a1,a2,a3)                    a1,a2,a3
#define arg_4(a1,a2,a3,a4)                 a1,a2,a3,a4
#define arg_5(a1,a2,a3,a4,a5)              a1,a2,a3,a4,a5
#define arg_6(a1,a2,a3,a4,a5,a6)           a1,a2,a3,a4,a5,a6
#define arg_7(a1,a2,a3,a4,a5,a6,a7)        a1,a2,a3,a4,a5,a6,a7
#define arg_8(a1,a2,a3,a4,a5,a6,a7,a8)     a1,a2,a3,a4,a5,a6,a7,a8
#define arg_9(a1,a2,a3,a4,a5,a6,a7,a8,a9)  a1,a2,a3,a4,a5,a6,a7,a8,a9


#define rr(r)                     &R(r)                      /* by address */
#define tr(t)                     T(t)                       /* by value   */



/*---------------------------------*/
/* Interface with C files          */
/*---------------------------------*/

#define infinity                   INTERVAL_INFINITY


#define Label_Name(label)          fd_label##label



/* installation */
#define Install_Fct_Name(inst_nb)  Install_##inst_nb


#define Fd_Install_Prototyp(inst_nb)                                        \
    static Bool Install_Fct_Name(inst_nb)(WamWord *AF);


#define Begin_Fd_Install(inst_nb)                                           \
                                                                            \
    static Bool Install_Fct_Name(inst_nb)(WamWord *AF)                      \
    {                                                                       \
     Decl_Fd_Install_Vars


#define End_Fd_Install                                                      \
    }



/* constraint computation */
#define Constraint_Fct_Name(cstr_nb)  Constraint_##cstr_nb


#define Fd_Constraint_Prototyp(cstr_nb)                                     \
    static Bool Constraint_Fct_Name(cstr_nb)(WamWord *CF);


#define Begin_Fd_Constraint(cstr_nb)                                        \
                                                                            \
    static Bool Constraint_Fct_Name(cstr_nb)(WamWord *CF)                   \
    {                                                                       \
     Decl_Fd_Constraint_Vars


#define Fd_Label(label)                                                     \
         Label_Name(label):


#define End_Fd_Constraint                                                   \
    }


/* enlargement */
#define Enlargement_Fct_Name(cstr_nb)   Enlargement_##cstr_nb


#define Fd_Enlargement_Prototyp(cstr_nb)                                    \
    static void Enlargement_Fct_Name(cstr_nb)(WamWord *CF);


#define Begin_Fd_Enlargement(cstr_nb)                                       \
                                                                            \
    static void Enlargement_Fct_Name(cstr_nb)(WamWord *CF)                  \
    {                                                                       \
      Decl_Fd_Enlargement_Vars                                              


#define End_Fd_Enlargement                                                  \
    }



/* test enlargement */
#define Test_Enlargement_Fct_Name(cstr_nb)   Test_Enlargement_##cstr_nb


#define Fd_Test_Enlargement_Prototyp(cstr_nb)                               \
    static Bool Test_Enlargement_Fct_Name(cstr_nb)(WamWord *CF);


#define Begin_Fd_Test_Enlargement(cstr_nb)                                  \
                                                                            \
    static Bool Test_Enlargement_Fct_Name(cstr_nb)(WamWord *CF)             \
    {                                                                       \
      Decl_Fd_Test_Enlargement_Vars                                           


#define End_Fd_Test_Enlargement                                             \
    }



/* reduction */
#define Reduction_Fct_Name(cstr_nb)   Reduction_##cstr_nb


#define Fd_Reduction_Prototyp(cstr_nb)                                      \
    static void Reduction_Fct_Name(cstr_nb)(WamWord *CF);


#define Begin_Fd_Reduction(cstr_nb)                                         \
                                                                            \
    static void Reduction_Fct_Name(cstr_nb)(WamWord *CF)                    \
    {                                                                       \
      Decl_Fd_Reduction_Vars                                              


#define End_Fd_Reduction                                                    \
    }



/* DEBUG */


#define fd_print_fv(fv)   Range_Write(stdout,Range(Frame_Variable(fv)));










