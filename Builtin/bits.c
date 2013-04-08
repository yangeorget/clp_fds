/****************************************************************************
Prolog to Wam Compiler - Version 2.0
Daniel Diaz, Yan Georget
1998 - INRIA Rocquencourt - LOCO Project
File : bits.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"
#include "sfd_engine.h"

#include "bits.h"
#include "bits.usr"


#define ASCII_PRED "num_bitnb"
#define PRED       X6E756D5F6269746E62
#define ARITY      2

Begin_Public_Pred
      try_me_else(2)
      switch_on_term(G_label(1),fail,G_label(1),fail,fail)

label(1)
      get_integer(0,0)
      get_integer(0,1)
      neck_cut
      proceed

label(2)
      trust_me_else_fail
      allocate(3)
      get_y_variable(2,1)
      math_load_x_value(0,0)
      put_integer(1,1)
      function_2(and,1,0,1)
      get_y_variable(1,1)
      math_load_x_value(0,0)
      put_integer(1,1)
      function_2(shr,0,0,1)
      put_y_variable(0,1)
      call(Pred_Name(X6E756D5F6269746E62,2),1,1,"num_bitnb",2)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_unsafe_value(1,1)
      put_y_unsafe_value(0,2)
      deallocate
      execute(Pred_Name(X6E756D5F6269746E625F2461757831,3),1,"num_bitnb_$aux1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "num_bitnb_$aux1"
#define PRED       X6E756D5F6269746E625F2461757831
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      put_integer(1,3)
      builtin_2(term_eq,1,3)
      neck_cut
      math_load_x_value(2,2)
      function_1(inc,1,2)
      get_x_value(0,1)
      proceed

label(1)
      trust_me_else_fail
      math_load_x_value(2,2)
      get_x_value(0,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "bitnb_num"
#define PRED       X6269746E625F6E756D
#define ARITY      3

Begin_Public_Pred
      try_me_else(2)
      switch_on_term(G_label(1),fail,G_label(1),fail,fail)

label(1)
      get_integer(0,0)
      get_integer(0,2)
      neck_cut
      proceed

label(2)
      retry_me_else(3)
      get_x_value(0,1)
      neck_cut
      put_integer(1,1)
      math_load_x_value(0,0)
      function_2(shl,0,1,0)
      function_1(dec,0,0)
      get_x_value(2,0)
      proceed

label(3)
      retry_me_else(4)
      allocate(2)
      get_y_variable(1,2)
      math_load_x_value(1,1)
      function_1(dec,1,1)
      math_load_x_value(0,0)
      function_1(dec,0,0)
      put_y_variable(0,2)
      call(Pred_Name(X6269746E625F6E756D,3),1,1,"bitnb_num",3)          /* begin sub 1 */
      math_load_y_value(0,1)
      put_integer(1,0)
      function_2(shl,0,1,0)
      function_1(inc,0,0)
      get_y_value(1,0)
      deallocate
      proceed

label(4)
      trust_me_else_fail
      allocate(2)
      get_y_variable(1,2)
      math_load_x_value(1,1)
      function_1(dec,1,1)
      put_y_variable(0,2)
      call(Pred_Name(X6269746E625F6E756D,3),1,2,"bitnb_num",3)          /* begin sub 2 */
      math_load_y_value(0,1)
      put_integer(1,0)
      function_2(shl,0,1,0)
      get_y_value(1,0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "skip_null"
#define PRED       X736B69705F6E756C6C
#define ARITY      4

Begin_Public_Pred
      math_load_x_value(0,0)
      put_integer(1,4)
      function_2(and,4,0,4)
      execute(Pred_Name(X736B69705F6E756C6C5F2461757832,5),1,"skip_null_$aux2",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "skip_null_$aux2"
#define PRED       X736B69705F6E756C6C5F2461757832
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      put_integer(1,5)
      builtin_2(term_eq,4,5)
      neck_cut
      get_x_value(1,3)
      get_x_value(0,2)
      proceed

label(1)
      trust_me_else_fail
      math_load_x_value(0,0)
      put_integer(1,4)
      function_2(shr,0,0,4)
      math_load_x_value(1,1)
      function_1(inc,1,1)
      execute(Pred_Name(X736B69705F6E756C6C,4),1,"skip_null",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(bits)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X6E756D5F6269746E62,"num_bitnb")
 Define_Atom(X6E756D5F6269746E625F2461757831,"num_bitnb_$aux1")
 Define_Atom(X6269746E625F6E756D,"bitnb_num")
 Define_Atom(X736B69705F6E756C6C,"skip_null")
 Define_Atom(X736B69705F6E756C6C5F2461757832,"skip_null_$aux2")


 Define_Pred(X6E756D5F6269746E62,2,1)

 Define_Pred(X6E756D5F6269746E625F2461757831,3,0)

 Define_Pred(X6269746E625F6E756D,3,1)

 Define_Pred(X736B69705F6E756C6C,4,1)

 Define_Pred(X736B69705F6E756C6C5F2461757832,5,0)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(bits)



End_Exec_Directives
