/*-------------------------------------------------------------------------*/
/* Prolog To Wam Compiler                INRIA Rocquencourt - CLoE Project */
/* C Run-time                                           Daniel Diaz - 1991 */
/*                                                                         */
/* Wam Implementation - Header file                                        */
/*                                                                         */
/* wam_engine.h                                                            */
/*-------------------------------------------------------------------------*/
#include <stdio.h>
#include <setjmp.h>

#include "bool.h"
#include "machine.h"

LibPrototype(extern int printf())




#ifdef NO_STACK_TEST
#   undef  M_Check_Stacks()
#   define M_Check_Stacks()
#endif




          /* see other includes in Global Variables section */



/*---------------------------------*/
/* Constants                       */
/*---------------------------------*/

     /* if you change version number, change also version in wamcc.pl */

#define WAM_VERSION                "3.0"
#define WAM_YEAR                   1999




          /* Read/Write Modes */

          /* if S==NULL iff we are in the write mode */

#define WRITE_MODE                 NULL




          /* Environment Frame */

#define ENVIR_STATIC_SIZE          2

#define CPE(e)                     ((WamCont)   (e[-1]))
#define EE(e)                      ((WamWord *) (e[-2]))
#define Y(e,y)                     ((WamWord)   (e[-3-(y)]))

#define ENVIR_NAMES                {"CPE","EE"}




          /* Choice Point Frame */

#define CHOICE_STATIC_SIZE         7

#define ALTB(b)                    ((CodePtr)   (b[-1]))
#define CPB(b)                     ((WamCont)   (b[-2]))
#define EB(b)                      ((WamWord *) (b[-3]))
#define BB(b)                      ((WamWord *) (b[-4]))
#define BCB(b)                     ((WamWord *) (b[-5]))
#define HB(b)                      ((WamWord *) (b[-6]))
#define TRB(b)                     ((WamWord *) (b[-7]))
#define AB(b,a)                    ((WamWord)   (b[-8-(a)]))

#define CHOICE_NAMES               {"ALTB","CPB","EB","BB","BCB","HB","TRB"}




          /* Wam Objects Manipulation */

          /* Trail Tags */

#define NB_OF_TRAIL_TAGS           4

#define TUV                        0           /* Trail Unbound Variable   */
#define TOV                        1           /* Trail One Value          */
#define TMV                        2           /* Trail Multiple Values    */
#define TFC                        3           /* Trail for Function Call  */

#define TRAIL_TAG_NAMES            {"TUV","TOV","TMV","TFC"}


#define Trail_Tag_Value(t,v)       ((unsigned long) (v) | (t))
#define Trail_Tag_Of(w)            ((unsigned long) (w) & 0x3)
#define Trail_Value_Of(w)          ((unsigned long) (w) & (~0x3))




          /* Functor/arity */

#define Functor_Arity(f,a)         ((Wam_Ptr(f) << ARITY_SIZE) + (a))
#define Functor_Of(word)           ((AtomInf *) Real_Ptr(((unsigned long) (word)) >> ARITY_SIZE)) 
#define Arity_Of(word)             ((word) & (MAX_ARITY-1))
#define Functor_Name(word)         (Functor_Of(word)->name)


#define Global_UnMove(t)           ((t)==FDV)




          /* Unbound Variables */

#define Make_Self_Ref(adr)         (Tag_Value(REF,adr))




          /* Constant */




          /* Integer */

#define INT_GREATEST_VALUE         ((int) ((1  << (32-TAG_SIZE-1))-1))
#define INT_LOWEST_VALUE           ((int) ((-INT_GREATEST_VALUE)-1))




          /* List */

#define OFFSET_CAR                 0

#define Car(adr)                   (((WamWord *) adr)[OFFSET_CAR])
#define Cdr(adr)                   (((WamWord *) adr)[OFFSET_CAR+1])




          /* Structure */

#define OFFSET_ARG                 1

#define Functor(adr)               (Functor_Of(Functor_And_Arity(adr)))
#define Arity(adr)                 (Arity_Of(Functor_And_Arity(adr)))
#define Functor_And_Arity(adr)     (((WamWord *) adr)[0])
#define Arg(adr,i)                 (((WamWord *) adr)[OFFSET_ARG+i])
                                                        /* i in 0..arity-1 */




          /* Stacks */

#define Global_Push(word)          (*H++=(WamWord) (word))

#define Global_Pop                 (*--H)




#define Trail_Push(word)           (*TR++=(WamWord) (word))

#define Trail_Pop                  (*--TR)




#define Is_A_Local_Adr(adr)        ((adr)>=Local_Stack)




          /* Miscellaneous */

#define Decl_Wam_Engine_Vars                                                \
     WamWord word,tag,*adr;                                                 \
     WamWord *AF,*CF;




          /* Error Messages */

#define ERR_DIRECTIVE_FAILED       "Warning: directive #%d failed in %s\n"




/*---------------------------------*/
/* Type Definitions                */
/*---------------------------------*/

typedef long    WamWord;               /* a wam word is a long (32/64 bits)*/

typedef void  (*CodePtr)();            /* a code pointer is an ptr to fct  */

typedef CodePtr WamCont;               /* a continuation is a code pointer */




/*---------------------------------*/
/* Global Variables                */
/*---------------------------------*/

#include "atom_pred.h"
#include "archi.h"
#include "builtin.h"

#ifdef DEBUG

#include "debugger.h"

#endif

#ifdef WAM_ENGINE

       int       unix_argc;
       char    **unix_argv;

       jmp_buf  *p_jumper;
       WamWord  *p_buff_save;

#else

extern int       unix_argc;
extern char    **unix_argv;

extern jmp_buf  *p_jumper;
extern WamWord  *p_buff_save;

#endif




/*---------------------------------*/
/* Function Prototypes             */
/*---------------------------------*/

void      Create_Choice_Point   (CodePtr codep_alt,int arity);
void      Update_Choice_Point   (CodePtr codep_alt,int arity);
void      Delete_Choice_Point   (int arity);

Bool      Get_Constant          (AtomInf *atom,WamWord start_word);
Bool      Get_Integer           (int n,WamWord start_word);
Bool      Get_Nil               (WamWord start_word);
Bool      Get_List              (WamWord start_word);
Bool      Get_Structure         (AtomInf *atom,int n,WamWord start_word);

void      Put_X_Variable        (int x,int a);
void      Put_Y_Variable        (int y,int a);
void      Put_Y_Unsafe_Value    (int y,int a);
void      Put_Constant          (AtomInf *atom,int a);
void      Put_List              (int a);
void      Put_Structure         (AtomInf *f,int n,int a);

void      Unify_Variable        (WamWord *start_adr);
Bool      Unify_Value           (WamWord  start_word);
Bool      Unify_Local_Value     (WamWord  start_word);
void      Unify_Void            (int n);
Bool      Unify_Constant        (AtomInf *atom);
Bool      Unify_Integer         (int n);
Bool      Unify_Nil             (void);

void      Allocate              (int n);

void      Set_Stack_Defaults    (char *name,char *env_var_name,
                                 int default_size_kb);
void      Init_Wam_Engine       (void);
void      Reinit_Wam_Engine     (void);
void      Term_Wam_Engine       (void);

void      Capture_Signal        (int sig);

void      Switch_Reg_Bank       (WamWord *new_reg_bank);

Bool      Call_Prolog           (CodePtr codep);
Bool      Call_Prolog_Next_Sol  (void);

void      Execute_A_Continuation(CodePtr codep);

Bool      Unify                 (WamWord start_u_word,WamWord start_v_word);

int       Term_Compare          (WamWord start_u_word,WamWord start_v_word);

int       Proper_List_Length    (WamWord start_word);

int       Term_Size             (WamWord start_word);

void      Copy_Term             (WamWord *dst_adr,WamWord *src_adr);

void      Copy_Contiguous_Term  (WamWord *dst_adr,WamWord *src_adr);

void      Fatal_Error           (char *format,...);




#define Mem_Word_Cpy(dst,src,nb)                                            \
    {                                                                       \
     register long *s=(long *) (src);                                       \
     register long *d=(long *) (dst);                                       \
     register int   counter=(nb);                                           \
                                                                            \
     while(counter--)                                                       \
         *d++ = *s++;                                                       \
    }




/*---------------------------------*/
/* Macros for debug                */
/*---------------------------------*/

#if DEBUG_LEVEL>=1

#define DBG_CLAUSE                 Debug_Clause();
#define DBG_BODY                   Debug_Body();
#define DBG_CALL(p,n,l)            Debug_Call(p,n,(l) ? DEBUG_LEVEL : -1);
#define DBG_PROCEED                Debug_Proceed(FALSE);
#define DBG_FAIL                   Debug_Fail();
#define DBG_PRED(p,n)              Debug_Pred(p,n);
#define DBG_SUB_PRED(p,n)          Debug_Sub_Pred(p,n);
#define DBG_RETRY                  Debug_Retry();

#else

#define DBG_CLAUSE
#define DBG_BODY
#define DBG_CALL(p,n,l)
#define DBG_PROCEED
#define DBG_FAIL
#define DBG_PRED(p,n)
#define DBG_SUB_PRED(p,n)
#define DBG_RETRY


#endif




#if DEBUG_LEVEL==2

#define DBG_INST(i)                Debug_Wam_Inst(i);

#else

#define DBG_INST(i)

#endif




/*---------------------------------*/
/* Auxiliary engine macros         */
/*---------------------------------*/

          /*---------------------------------------------------------------*/
          /* Deref dereferences the word start_word and sets :             */
          /*   word : dereferenced word                                    */
          /*   tag  : dereferenced word's tag                              */
          /*   adr  : only if tag==REF then adr==value==self adress        */
          /*---------------------------------------------------------------*/

#define Deref(start_word,word,tag,adr)                                      \
    {                                                                       \
     WamWord *working_adr;                                                  \
     word=start_word;                                                       \
     adr=NULL;                                                              \
     for(;;)                                                                \
        {                                                                   \
         tag=Tag_Of(word);                                                  \
         if (tag!=REF || (working_adr=UnTag_REF(word))==adr)                \
             break;                                                         \
                                                                            \
         adr=working_adr;                                                   \
         word=*adr;                                                         \
        }                                                                   \
    }




          /* Trail Stack Management */

#define Word_Needs_Trailing(adr)           ((adr)<(WamWord *) HB(B) ||      \
                                            (Is_A_Local_Adr(adr) && (adr)<B))



#define Bind_UV(adr,word)                                                   \
    {                                                                       \
     if (Word_Needs_Trailing(adr))                                          \
         Trail_UV(adr)                                                      \
     *(adr)=(word);                                                         \
    }




#define Bind_OV(adr,word)                                                   \
    {                                                                       \
     if (Word_Needs_Trailing(adr))                                          \
         Trail_OV(adr)                                                      \
     *(adr)=(word);                                                         \
    }




#define Bind_MV(adr,nb,real_adr)                                            \
    {                                                                       \
     if (Word_Needs_Trailing(adr))                                          \
         Trail_MV(adr,nb)                                                   \
     Mem_Word_Cpy(adr,real_adr,nb)                                          \
    }




#define Trail_UV(adr)                                                       \
     Trail_Push(Trail_Tag_Value(TUV,adr));                                  \




#define Trail_OV(adr)                                                       \
    {                                                                       \
     Trail_Push(*adr);                                                      \
     Trail_Push(Trail_Tag_Value(TOV,adr));                                  \
    }




#define Trail_MV(adr,nb)                                                    \
    {                                                                       \
     Mem_Word_Cpy(TR,adr,nb)                                                \
     TR+=nb;                                                                \
     Trail_Push(nb);                                                        \
     Trail_Push(Trail_Tag_Value(TMV,adr));                                  \
    }




#define Trail_FC(fct)                                                       \
     Trail_Push(Trail_Tag_Value(TFC,fct));




            /* Globalization */

#define Globalize_Local_Unbound_Var(adr)                                    \
    {                                                                       \
     Bind_UV(adr,Tag_Value(REF,H))                                          \
     word=Make_Self_Ref(H);                                                 \
     Global_Push(word);                                                     \
    }                                                                       \




            /* Control */

#define Call_Execute_Prefix                                                 \
    {                                                                       \
     BC=B;                                                                  \
    }




/*---------------------------------*/
/* Wam engine macros (wam inst->C) */
/*---------------------------------*/

#define dbg_clause                                                          \
     DBG_CLAUSE




#define dbg_body                                                            \
     DBG_BODY




#define get_x_variable(x,a)                                                 \
    {                                                                       \
     DBG_INST("get_x_variable(" #x "," #a ")")                              \
     X(x)=A(a);                                                             \
    }




#define get_x_value(x,a)                                                    \
    {                                                                       \
     DBG_INST("get_x_value(" #x "," #a ")")                                 \
     if (!Unify(X(x),A(a)))                                                 \
         goto lab_fail;                                                     \
    }




#define get_y_variable(y,a)                                                 \
    {                                                                       \
     DBG_INST("get_y_variable(" #y "," #a ")")                              \
     Y(E,y)=A(a);                                                           \
    }




#define get_y_value(y,a)                                                    \
    {                                                                       \
     DBG_INST("get_y_value(" #y "," #a ")")                                 \
     if (!Unify(Y(E,y),A(a)))                                               \
         goto lab_fail;                                                     \
    }




#define get_constant(c,a,dbg_c)                                             \
    {                                                                       \
     DBG_INST("get_constant(" dbg_c "," #a ")")                             \
     if (!Get_Constant(c,A(a)))                                             \
         goto lab_fail;                                                     \
    }




#define get_integer(n,a)                                                    \
    {                                                                       \
     DBG_INST("get_integer(" #n "," #a ")")                                 \
     if (!Get_Integer(n,A(a)))                                              \
         goto lab_fail;                                                     \
    }




#define get_nil(a)                                                          \
    {                                                                       \
     DBG_INST("get_nil(" #a ")")                                            \
     if (!Get_Nil(A(a)))                                                    \
         goto lab_fail;                                                     \
    }




#define get_list(a)                                                         \
    {                                                                       \
     DBG_INST("get_list(" #a ")")                                           \
     if (!Get_List(A(a)))                                                   \
         goto lab_fail;                                                     \
    }




#define get_structure(f,n,a,dbg_f)                                          \
    {                                                                       \
     DBG_INST("get_structure(" dbg_f "/" #n "," #a ")")                     \
     if (!Get_Structure(f,n,A(a)))                                          \
         goto lab_fail;                                                     \
    }




#define put_x_variable(x,a)                                                 \
    {                                                                       \
     DBG_INST("put_x_variable(" #x "," #a ")")                              \
     Put_X_Variable(x,a);                                                   \
    }




#define put_x_value(x,a)                                                    \
    {                                                                       \
     DBG_INST("put_x_value(" #x "," #a ")")                                 \
     A(a)=X(x);                                                             \
    }




#define put_y_variable(y,a)                                                 \
    {                                                                       \
     DBG_INST("put_y_variable(" #y "," #a ")")                              \
     Put_Y_Variable(y,a);                                                   \
    }




#define put_y_value(y,a)                                                    \
    {                                                                       \
     DBG_INST("put_y_value(" #y "," #a ")")                                 \
     A(a)=Y(E,y);                                                           \
    }




#define put_y_unsafe_value(y,a)                                             \
    {                                                                       \
     DBG_INST("put_y_unsafe_value(" #y "," #a ")")                          \
     Put_Y_Unsafe_Value(y,a);                                               \
    }




#define put_constant(c,a,dbg_c)                                             \
    {                                                                       \
     DBG_INST("put_constant(" dbg_c "," #a ")")                             \
     Put_Constant(c,a);                                                     \
    }




#define put_integer(n,a)                                                    \
    {                                                                       \
     DBG_INST("put_integer(" #n "," #a ")")                                 \
     A(a)=Tag_Value(INT,n);                                                 \
    }




#define put_nil(a)                                                          \
    {                                                                       \
     DBG_INST("put_nil(" #a ")")                                            \
     A(a)=word_nil;                                                         \
    }




#define put_list(a)                                                         \
    {                                                                       \
     DBG_INST("put_list(" #a ")")                                           \
     Put_List(a);                                                           \
    }




#define put_structure(f,n,a,dbg_f)                                          \
    {                                                                       \
     DBG_INST("put_structure(" dbg_f "/" #n "," #a ")")                     \
     Put_Structure(f,n,a);                                                  \
    }




#define unify_x_variable(x)                                                 \
    {                                                                       \
     DBG_INST("unify_x_variable(" #x ")")                                   \
     Unify_Variable(&X(x));                                                 \
    }




#define unify_x_value(x)                                                    \
    {                                                                       \
     DBG_INST("unify_x_value(" #x ")")                                      \
     if (!Unify_Value(X(x)))                                                \
         goto lab_fail;                                                     \
    }




#define unify_x_local_value(x)                                              \
    {                                                                       \
     DBG_INST("unify_x_local_value(" #x ")")                                \
     if (!Unify_Local_Value(X(x)))                                          \
         goto lab_fail;                                                     \
    }




#define unify_y_variable(y)                                                 \
    {                                                                       \
     DBG_INST("unify_y_variable(" #y ")")                                   \
     Unify_Variable(&Y(E,y));                                               \
    }





#define unify_y_value(y)                                                    \
    {                                                                       \
     DBG_INST("unify_y_value(" #y ")")                                      \
     if (!Unify_Value(Y(E,y)))                                              \
         goto lab_fail;                                                     \
    }




#define unify_y_local_value(y)                                              \
    {                                                                       \
     DBG_INST("unify_y_local_value(" #y ")")                                \
     if (!Unify_Local_Value(Y(E,y)))                                        \
         goto lab_fail;                                                     \
    }




#define unify_void(n)                                                       \
    {                                                                       \
     DBG_INST("unify_void(" #n ")")                                         \
     Unify_Void(n);                                                         \
    }




#define unify_constant(c,dbg_c)                                             \
    {                                                                       \
     DBG_INST("unify_constant(" dbg_c ")")                                  \
     if (!Unify_Constant(c))                                                \
         goto lab_fail;                                                     \
    }




#define unify_integer(n)                                                    \
    {                                                                       \
     DBG_INST("unify_integer(" #n ")")                                      \
     if (!Unify_Integer(n))                                                 \
         goto lab_fail;                                                     \
    }




#define unify_nil                                                           \
    {                                                                       \
     DBG_INST("unify_nil")                                                  \
     if (!Unify_Nil())                                                      \
         goto lab_fail;                                                     \
    }




#define allocate(n)                                                         \
    {                                                                       \
     DBG_INST("allocate(" #n ")")                                           \
     Allocate(n);                                                           \
    }




#define deallocate                                                          \
    {                                                                       \
     DBG_INST("deallocate")                                                 \
     CP=(WamCont)   CPE(E);                                                 \
     E =(WamWord *) EE(E); /* warning E must be the last element restored */\
    }




#define call(p,local,subp,dbg_name,dbg_arity)                               \
    {                                                                       \
     Prototype(Prefix(Sub_Pred_Name(PRED,ARITY,subp)))                      \
     Prototype(Prefix(p))                                                   \
     DBG_INST("call(" dbg_name "/" #dbg_arity ")")                          \
     if (local==0)                                                          \
         calling_module_nb=module_nb;                                       \
     Call_Execute_Prefix                                                    \
     CP =(WamCont) Prefix(Sub_Pred_Name(PRED,ARITY,subp));                  \
     DBG_CALL(dbg_name,dbg_arity,local)                                     \
     M_Direct_Goto(Prefix(p))                                               \
    }                                                                       \
 End_Pred                                                                   \
 Begin_Sub_Pred(subp)                                                       \
     DBG_SUB_PRED(ASCII_PRED,ARITY)




#define execute(p,local,dbg_name,dbg_arity)                                 \
    {                                                                       \
     Prototype(Prefix(p))                                                   \
     DBG_INST("execute(" dbg_name "/" #dbg_arity ")")                       \
     if (local==0)                                                          \
         calling_module_nb=module_nb;                                       \
     Call_Execute_Prefix                                                    \
     DBG_CALL(dbg_name,dbg_arity,local)                                     \
     M_Direct_Goto(Prefix(p))                                               \
    }




#define proceed                                                             \
    {                                                                       \
     DBG_INST("proceed")                                                    \
     DBG_PROCEED                                                            \
     M_Indirect_Goto(CP)                                                    \
    }




#define Fail_Primitive                                                      \
    {                                                                       \
     M_Indirect_Goto(ALTB(B))                                               \
    }





#define fail Fail_Like_Wam




#define Fail_Like_Bool                                                      \
     return(FALSE);




#define Fail_Like_Wam                                                       \
    {                                                                       \
     DBG_INST("fail")                                                       \
     DBG_FAIL                                                               \
     Fail_Primitive                                                         \
    }



#define switch_on_term(c_var,c_cst,c_int,c_lst,c_stc)                       \
    {                                                                       \
     DBG_INST("switch_on_term("                                             \
              #c_var "," #c_cst "," #c_int "," #c_lst "," #c_stc ")")       \
     Deref(A(0),word,tag,adr)                                               \
     A(0)=word;                                                             \
     switch(tag)                                                            \
        {                                                                   \
         case INT:                                                          \
             c_int                                                          \
             break;                                                         \
                                                                            \
         case REF:                                                          \
         case FDV:                                                          \
             c_var                                                          \
             break;                                                         \
                                                                            \
         case CST:                                                          \
             c_cst                                                          \
             break;                                                         \
                                                                            \
         case LST:                                                          \
             c_lst                                                          \
             break;                                                         \
                                                                            \
         default:               /* STC */                                   \
             c_stc                                                          \
             break;                                                         \
        }                                                                   \
    }




          /*---------------------------------------------------------------*/
          /* switch_on_constant always occurs after a switch_on_term, thus */
          /* A(0) is dereferenced and has been updated with its deref word */
          /* Similary for switch_on_integer/structure.                     */
          /*---------------------------------------------------------------*/

#define switch_on_constant(lab,dbg_lst)                                     \
    {                                                                       \
     DBG_INST("switch_on_constant(" dbg_lst ")")                            \
     if (adr=(WamWord *) Hash_Fast_Find_Int(                                \
              Swt_Table_Name(PRED,ARITY,lab,cst),(long) UnTag_CST(A(0))))   \
         M_Indirect_Goto(((SwtInf *) adr)->c.codep)                         \
     goto lab_fail;                                                         \
    }



         /* C switch for switch_on_integer */

#define G_label(lab)                                                        \
    {                                                                       \
     Prototype(Prefix(Label_Pred_Name(PRED,ARITY,lab)))                     \
     M_Direct_Goto(Prefix(Label_Pred_Name(PRED,ARITY,lab)))                 \
    }





#define i(i,lab)                                                            \
     case i:                                                                \
         {                                                                  \
          Prototype(Prefix(Label_Pred_Name(PRED,ARITY,lab)))                \
          M_Direct_Goto(Prefix(Label_Pred_Name(PRED,ARITY,lab)))            \
          break;                                                            \
         }




#define lst(l)                                                              \
    { l                                                                     \
     default:                                                               \
         goto lab_fail;                                                     \
    }




#define switch_on_integer(lst,dbg_lst)                                      \
    {                                                                       \
     DBG_INST("switch_on_integer(" dbg_lst ")")                             \
     switch(UnTag_INT(A(0))) lst                                            \
    }




#define switch_on_structure(lab,dbg_lst)                                    \
    {                                                                       \
     DBG_INST("switch_on_strucutre(" dbg_lst ")")                           \
     if (adr=(WamWord *) Hash_Fast_Find_Int(                                \
                            Swt_Table_Name(PRED,ARITY,lab,stc),             \
                            Functor_And_Arity(UnTag_STC(A(0)))))            \
         M_Indirect_Goto(((SwtInf *) adr)->c.codep)                         \
     goto lab_fail;                                                         \
    }




#define try_me_else(lab)                                                    \
    {                                                                       \
     Prototype(Prefix(Label_Pred_Name(PRED,ARITY,lab)))                     \
     DBG_INST("try_me_else(" #lab ")")                                      \
     Create_Choice_Point((CodePtr) Prefix(Label_Pred_Name(PRED,ARITY,lab)), \
                         ARITY);                                            \
    }




#define retry_me_else(lab)                                                  \
    {                                                                       \
     Prototype(Prefix(Label_Pred_Name(PRED,ARITY,lab)))                     \
     DBG_INST("retry_me_else(" #lab ")")                                    \
     DBG_RETRY                                                              \
     Update_Choice_Point((CodePtr) Prefix(Label_Pred_Name(PRED,ARITY,lab)), \
                         ARITY);                                            \
    }




#define trust_me_else_fail                                                  \
    {                                                                       \
     DBG_INST("trust_me_else_fail")                                         \
     DBG_RETRY                                                              \
     Delete_Choice_Point(ARITY);                                            \
    }




#define try(lab,subp)                                                       \
    {                                                                       \
     Prototype(Prefix(Label_Pred_Name(PRED,ARITY,lab)))                     \
     Prototype(Prefix(Sub_Pred_Name(PRED,ARITY,subp)))                      \
     DBG_INST("try(" #lab ")")                                              \
     Create_Choice_Point((CodePtr) Prefix(Sub_Pred_Name(PRED,ARITY,subp)),  \
                         ARITY);                                            \
     M_Direct_Goto(Prefix(Label_Pred_Name(PRED,ARITY,lab)))                 \
    }                                                                       \
 End_Pred                                                                   \
 Begin_Sub_Pred(subp)




#define retry(lab,subp)                                                     \
    {                                                                       \
     Prototype(Prefix(Label_Pred_Name(PRED,ARITY,lab)))                     \
     Prototype(Prefix(Sub_Pred_Name(PRED,ARITY,subp)))                      \
     DBG_INST("retry(" #lab ")")                                            \
     DBG_RETRY                                                              \
     Update_Choice_Point((CodePtr) Prefix(Sub_Pred_Name(PRED,ARITY,subp)),  \
                         ARITY);                                            \
     M_Direct_Goto(Prefix(Label_Pred_Name(PRED,ARITY,lab)))                 \
    }                                                                       \
 End_Pred                                                                   \
 Begin_Sub_Pred(subp)




#define trust(lab)                                                          \
    {                                                                       \
     Prototype(Prefix(Label_Pred_Name(PRED,ARITY,lab)))                     \
     DBG_INST("trust(" #lab ")")                                            \
     DBG_RETRY                                                              \
     Delete_Choice_Point(ARITY);                                            \
     M_Direct_Goto(Prefix(Label_Pred_Name(PRED,ARITY,lab)))                 \
    }




          /* Wam Extensions */

#define neck_cut                                                            \
    {                                                                       \
     DBG_INST("neck_cut")                                                   \
     B=BC;                                                                  \
    }




#define get_x_bc_reg(x)                                                     \
    {                                                                       \
     DBG_INST("get_x_bc_reg(" #x ")")                                       \
     X(x)=Tag_Value(INT,BC);                                                \
    }




#define get_y_bc_reg(y)                                                     \
    {                                                                       \
     DBG_INST("get_y_bc_reg(" #y ")")                                       \
     Y(E,y)=Tag_Value(INT,BC);                                              \
    }




#define cut_x(x)                                                            \
    {                                                                       \
     DBG_INST("cut_x(" #x ")")                                              \
     B=UnTag_REF(X(x));      /* warning UnTag_REF since stack adr as INT */ \
    }




#define cut_y(y)                                                            \
    {                                                                       \
     DBG_INST("cut_y(" #y ")")                                              \
     B=UnTag_REF(Y(E,y));    /* warning UnTag_REF since stack adr as INT */ \
    }




#ifndef FAST_MATH




#define math_load_x_value(x,a)                                              \
    {                                                                       \
     DBG_INST("math_load_x_value(" #x "," #a ")")                           \
     Deref(X(x),word,tag,adr)                                               \
     if (tag!=INT && !Load_Math_Expression(word,&word))                     \
         goto lab_fail;                                                     \
                                                                            \
     A(a)=word;                                                             \
    }




#define math_load_y_value(y,a)                                              \
    {                                                                       \
     DBG_INST("math_load_y_value(" #y "," #a ")")                           \
     Deref(Y(E,y),word,tag,adr)                                             \
     if (tag!=INT && !Load_Math_Expression(word,&word))                     \
         goto lab_fail;                                                     \
                                                                            \
     A(a)=word;                                                             \
    }




#else




#define math_load_x_value(x,a)                                              \
    {                                                                       \
     DBG_INST("math_load_x_value(" #x "," #a ")")                           \
     Deref(X(x),word,tag,adr)                                               \
     A(a)=word;                                                             \
    }




#define math_load_y_value(y,a)                                              \
    {                                                                       \
     DBG_INST("math_load_y_value(" #y "," #a ")")                           \
     Deref(Y(E,y),word,tag,adr)                                             \
     A(a)=word;                                                             \
    }




#endif




#define function_1(name,x,x1)                                               \
    {                                                                       \
     DBG_INST("function_1(" #name "," #x "," #x1 ")")                       \
     X(x)=CPP_CAT(Fct_1_,name)(X(x1));                                      \
    }




#define function_2(name,x,x1,x2)                                            \
    {                                                                       \
     DBG_INST("function_2(" #name "," #x "," #x1 "," #x2 ")")               \
     X(x)=CPP_CAT(Fct_2_,name)(X(x1),X(x2));                                \
    }




#define builtin_1(name,x1)                                                  \
    {                                                                       \
     DBG_INST("builtin_1(" #name "," #x1 ")")                               \
     if (!CPP_CAT(Blt_1_,name)(X(x1)))                                      \
         goto lab_fail;                                                     \
    }




#define builtin_2(name,x1,x2)                                               \
    {                                                                       \
     DBG_INST("builtin_2(" #name "," #x1 "," #x2 ")")                       \
     if (!CPP_CAT(Blt_2_,name)(X(x1),X(x2)))                                \
         goto lab_fail;                                                     \
    }




#define builtin_3(name,x1,x2,x3)                                            \
    {                                                                       \
     DBG_INST("builtin_3(" #name "," #x1 "," #x2 "," #x3 ")")               \
     if (!CPP_CAT(Blt_3_,name)(X(x1),X(x2),X(x3)))                          \
         goto lab_fail;                                                     \
    }




#define pragma_c(code)             {code}




/*---------------------------------*/
/* Interface with C files          */
/*---------------------------------*/

#define CPP_CAT1(x,y)              x##y
#define CPP_CAT(x,y)               CPP_CAT1(x,y)

#define CPP_STRING1(s)             #s
#define CPP_STRING(s)              CPP_STRING1(s)




#define Pred_Name(p,n)             CPP_CAT(p,CPP_CAT(_,n))
#define Label_Pred_Name(p,n,l)     CPP_CAT(Pred_Name(p,n),_lab_##l)
#define Sub_Pred_Name(p,n,s)       CPP_CAT(Pred_Name(p,n),_sub_##s)
#define Swt_Table_Name(p,n,l,t)    CPP_CAT(Pred_Name(p,n),_##l##_##t)



#define Prefix(p)                  CPP_CAT(_,p)

#define Prototype(fct)             static int fct(void);


#define Begin_Public_Pred                                                   \
                                                                            \
    int Pred_Name(PRED,ARITY)(void)                                         \
    {                                                                       \
     Decl_Wam_Engine_Vars                                                   \
     Prototype(Prefix(Pred_Name(PRED,ARITY)))                               \
     M_Decl_Global_Label(Prefix(Pred_Name(PRED,ARITY)))                     \
     M_Def_Label(Prefix(Pred_Name(PRED,ARITY)))                             \
     M_Restore_Control_Info                                                 \
     M_Check_Stacks();                                                      \
     DBG_PRED(ASCII_PRED,ARITY)




#define Begin_Private_Pred                                                  \
                                                                            \
    static int Pred_Name(PRED,ARITY)(void)                                  \
    {                                                                       \
     Decl_Wam_Engine_Vars                                                   \
     Prototype(Prefix(Pred_Name(PRED,ARITY)))                               \
     M_Def_Label(Prefix(Pred_Name(PRED,ARITY)))                             \
     M_Restore_Control_Info                                                 \
     M_Check_Stacks();                                                      \
     DBG_PRED(ASCII_PRED,ARITY)




#define Begin_Sub_Pred(subp)                                                \
                                                                            \
    static int Sub_Pred_Name(PRED,ARITY,subp)(void)                         \
    {                                                                       \
     Decl_Wam_Engine_Vars                                                   \
     Prototype(Prefix(Sub_Pred_Name(PRED,ARITY,subp)))                      \
     M_Def_Label(Prefix(Sub_Pred_Name(PRED,ARITY,subp)))                    \
     M_Restore_Control_Info                                                 \
     M_Check_Stacks();




#define Begin_Static_Wam_Code(fct)                                          \
                                                                            \
    static int fct(void)                                                    \
    {                                                                       \
     Decl_Wam_Engine_Vars                                                   \
     M_Def_Label(Prefix(fct))                                               \
     M_Restore_Control_Info                                                 \
     M_Check_Stacks();                                                      \




#define label(lab)                                                          \
        {                                                                   \
         Prototype(Prefix(Label_Pred_Name(PRED,ARITY,lab)))                 \
         M_Direct_Goto(Prefix(Label_Pred_Name(PRED,ARITY,lab)))             \
        }                                                                   \
    End_Pred                                                                \
                                                                            \
    Begin_Static_Wam_Code(Label_Pred_Name(PRED,ARITY,lab))                  \
          DBG_INST("label(" #lab ")")




#define End_Pred                                                            \
     lab_fail:                                                              \
        fail                                                                \
    }




#define Exec_Directives_Of_Module(module)                                   \
    {                                                                       \
     Exec_Directives_Prototyp(module)                                       \
     CPP_CAT(module,_Exec_Directives)();                                    \
    }




#define Exec_Directives_Prototyp(module)                                    \
    void CPP_CAT(module,_Exec_Directives)(void);




#define Begin_Exec_Directives(module)                                       \
    void CPP_CAT(module,_Exec_Directives)(void)                             \
    {




#define Exec_Directive(nb,execpred)                                         \
    {                                                                       \
     Prototype(Prefix(execpred))                                            \
     if (!Call_Prolog((CodePtr) Prefix(execpred)))                          \
         Lib3(printf,ERR_DIRECTIVE_FAILED,nb,module_name);                  \
    }




#define End_Exec_Directives                                                 \
    }

