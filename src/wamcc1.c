/****************************************************************************
Prolog to Wam Compiler - Version 2.0
Daniel Diaz, Yan Georget
1998 - INRIA Rocquencourt - LOCO Project
File : wamcc1.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"
#include "sfd_engine.h"

#include "wamcc1.h"
#include "wamcc1.usr"


#define ASCII_PRED "sucre_syntaxique"
#define PRED       X73756372655F73796E74617869717565
#define ARITY      5

Begin_Public_Pred
      allocate(8)
      get_y_variable(6,0)
      get_y_variable(5,1)
      get_y_variable(3,2)
      get_y_variable(2,3)
      get_y_variable(4,4)
      get_y_bc_reg(0)
      put_y_value(6,0)
      put_y_variable(7,1)
      call(Pred_Name(X73756372655F73796E746178697175655F2461757831,2),1,1,"sucre_syntaxique_$aux1",2)          /* begin sub 1 */
      put_y_unsafe_value(7,2)
      put_x_variable(3,1)
      put_x_variable(4,0)
      builtin_3(functor,2,1,0)
      put_y_value(6,0)
      put_y_value(5,1)
      put_y_value(4,2)
      put_y_variable(1,5)
      call(Pred_Name(X73756372655F73796E746178697175655F2461757832,6),1,2,"sucre_syntaxique_$aux2",6)          /* begin sub 2 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      call(Pred_Name(X73756372655F73796E746178697175655F2461757833,3),1,3,"sucre_syntaxique_$aux3",3)          /* begin sub 3 */
      cut_y(0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sucre_syntaxique_$aux3"
#define PRED       X73756372655F73796E746178697175655F2461757833
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      get_x_variable(4,0)
      get_x_variable(3,1)
      put_constant(X6E6F5F696E6C696E65,1,"no_inline")
      put_constant(X66,0,"f")
      builtin_2(g_read,1,0)
      neck_cut
      put_x_value(2,0)
      put_x_value(4,1)
      put_x_value(3,2)
      execute(Pred_Name(X6E6F726D616C6973655F666463,3),1,"normalise_fdc",3)

label(1)
      trust_me_else_fail
      get_x_value(2,0)
      get_nil(1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sucre_syntaxique_$aux2"
#define PRED       X73756372655F73796E746178697175655F2461757832
#define ARITY      6

Begin_Private_Pred
      try_me_else(1)
      allocate(5)
      get_y_variable(3,0)
      get_y_variable(0,1)
      get_y_variable(1,2)
      get_y_variable(2,5)
      get_y_bc_reg(4)
      put_constant(X64796E,0,"dyn")
      put_x_value(3,1)
      put_x_value(4,2)
      call(Pred_Name(X746573745F707265645F696E666F,3),0,1,"test_pred_info",3)          /* begin sub 1 */
      cut_y(4)
      put_constant(X6E625F636C617573655F64796E,0,"nb_clause_dyn")
      put_constant(X2464796E5F,1,"$dyn_")
      put_structure(X6173736572747A,1,2,"assertz")
      unify_y_local_value(3)
      put_y_value(2,3)
      call(Pred_Name(X6D616B655F7370656369616C5F636C61757365,4),0,2,"make_special_clause",4)          /* begin sub 2 */
      put_y_value(1,0)
      get_y_value(0,0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      allocate(4)
      get_y_variable(2,1)
      get_y_variable(0,2)
      get_y_variable(1,5)
      put_y_variable(3,1)
      call(Pred_Name(X6E6F726D616C6973655F63757473,2),1,3,"normalise_cuts",2)          /* begin sub 3 */
      put_y_unsafe_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X6E6F726D616C6973655F616C7473,4),1,"normalise_alts",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sucre_syntaxique_$aux1"
#define PRED       X73756372655F73796E746178697175655F2461757831
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      get_structure(X3A2D,2,0,":-")
      unify_x_local_value(1)
      unify_void(1)
      proceed

label(1)
      trust_me_else_fail
      get_x_value(1,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_cuts"
#define PRED       X6E6F726D616C6973655F63757473
#define ARITY      2

Begin_Private_Pred
      try_me_else(2)
      switch_on_term(G_label(1),fail,fail,fail,G_label(1))

label(1)
      allocate(5)
      get_structure(X3A2D,2,0,":-")
      unify_y_variable(4)
      unify_x_variable(0)
      get_y_variable(3,1)
      put_y_variable(2,1)
      put_y_variable(1,2)
      put_y_variable(0,3)
      call(Pred_Name(X6E6F726D616C6973655F6375747331,4),1,1,"normalise_cuts1",4)          /* begin sub 1 */
      put_y_value(4,0)
      put_y_value(3,1)
      put_y_unsafe_value(2,2)
      put_y_unsafe_value(1,3)
      put_y_unsafe_value(0,4)
      deallocate
      execute(Pred_Name(X6E6F726D616C6973655F637574735F2461757834,5),1,"normalise_cuts_$aux4",5)

label(2)
      trust_me_else_fail
      get_x_value(0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_cuts_$aux4"
#define PRED       X6E6F726D616C6973655F637574735F2461757834
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      put_constant(X74,5,"t")
      builtin_2(term_eq,4,5)
      neck_cut
      get_structure(X3A2D,2,1,":-")
      unify_x_local_value(0)
      unify_x_variable(0)
      get_structure(X2C,2,0,",")
      unify_x_variable(0)
      unify_x_local_value(3)
      get_structure(X246765745F62635F726567,1,0,"$get_bc_reg")
      unify_x_local_value(2)
      proceed

label(1)
      trust_me_else_fail
      get_structure(X3A2D,2,1,":-")
      unify_x_local_value(0)
      unify_x_local_value(3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_cuts1"
#define PRED       X6E6F726D616C6973655F6375747331
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      get_structure(X63616C6C,1,2,"call")
      unify_x_local_value(0)
      builtin_1(var,0)
      proceed

label(1)
      retry_me_else(16)
      switch_on_term(G_label(4),G_label(15),fail,fail,G_label(2))

label(2)
      switch_on_structure(2,"[((;)/2,3),((->)/2,7),((\+)/1,9),((,)/2,11)]")

label(3)
      try(5,1)          /* begin sub 1 */
      trust(13)

label(4)
      try_me_else(6)

label(5)
      allocate(4)
      get_structure(X3B,2,0,";")
      unify_x_variable(0)
      unify_y_variable(3)
      get_structure(X2D3E,2,0,"->")
      unify_x_variable(4)
      unify_x_variable(0)
      get_y_variable(2,1)
      get_y_variable(0,3)
      get_structure(X3B,2,2,";")
      unify_x_variable(1)
      unify_y_variable(1)
      get_structure(X2C,2,1,",")
      unify_x_variable(1)
      unify_x_variable(2)
      get_structure(X246765745F62635F726567,1,1,"$get_bc_reg")
      unify_x_variable(1)
      get_structure(X2C,2,2,",")
      unify_x_value(4)
      unify_x_variable(2)
      get_structure(X2C,2,2,",")
      unify_x_variable(3)
      unify_x_variable(2)
      get_structure(X24637574,1,3,"$cut")
      unify_x_value(1)
      put_y_value(2,1)
      put_y_value(0,3)
      call(Pred_Name(X6E6F726D616C6973655F6375747331,4),1,2,"normalise_cuts1",4)          /* begin sub 2 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X6E6F726D616C6973655F6375747331,4),1,"normalise_cuts1",4)

label(6)
      retry_me_else(8)

label(7)
      get_structure(X2D3E,2,0,"->")
      unify_x_variable(5)
      unify_x_variable(0)
      get_structure(X3B,2,2,";")
      unify_x_variable(2)
      unify_constant(X6661696C,"fail")
      get_structure(X2C,2,2,",")
      unify_x_variable(4)
      unify_x_variable(2)
      get_structure(X246765745F62635F726567,1,4,"$get_bc_reg")
      unify_x_variable(4)
      get_structure(X2C,2,2,",")
      unify_x_value(5)
      unify_x_variable(2)
      get_structure(X2C,2,2,",")
      unify_x_variable(5)
      unify_x_variable(2)
      get_structure(X24637574,1,5,"$cut")
      unify_x_value(4)
      execute(Pred_Name(X6E6F726D616C6973655F6375747331,4),1,"normalise_cuts1",4)

label(8)
      retry_me_else(10)

label(9)
      get_structure(X5C2B,1,0,"\\+")
      unify_x_variable(0)
      put_structure(X2D3E,2,4,"->")
      unify_x_value(0)
      unify_constant(X6661696C,"fail")
      put_structure(X3B,2,0,";")
      unify_x_value(4)
      unify_constant(X74727565,"true")
      execute(Pred_Name(X6E6F726D616C6973655F6375747331,4),1,"normalise_cuts1",4)

label(10)
      retry_me_else(12)

label(11)
      allocate(4)
      get_structure(X2C,2,0,",")
      unify_x_variable(0)
      unify_y_variable(3)
      get_y_variable(2,1)
      get_structure(X2C,2,2,",")
      unify_x_variable(2)
      unify_y_variable(1)
      get_y_variable(0,3)
      put_y_value(2,1)
      put_y_value(0,3)
      call(Pred_Name(X6E6F726D616C6973655F6375747331,4),1,3,"normalise_cuts1",4)          /* begin sub 3 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X6E6F726D616C6973655F6375747331,4),1,"normalise_cuts1",4)

label(12)
      retry_me_else(14)

label(13)
      allocate(4)
      get_structure(X3B,2,0,";")
      unify_x_variable(0)
      unify_y_variable(3)
      get_y_variable(2,1)
      get_structure(X3B,2,2,";")
      unify_x_variable(2)
      unify_y_variable(1)
      get_y_variable(0,3)
      put_y_value(2,1)
      put_y_value(0,3)
      call(Pred_Name(X6E6F726D616C6973655F6375747331,4),1,4,"normalise_cuts1",4)          /* begin sub 4 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X6E6F726D616C6973655F6375747331,4),1,"normalise_cuts1",4)

label(14)
      trust_me_else_fail

label(15)
      get_constant(X21,0,"!")
      get_structure(X24637574,1,2,"$cut")
      unify_x_local_value(1)
      get_constant(X74,3,"t")
      proceed

label(16)
      trust_me_else_fail
      get_x_variable(1,2)
      put_x_variable(2,5)
      put_x_variable(3,4)
      builtin_3(functor,0,5,4)
      execute(Pred_Name(X6E6F726D616C6973655F63757473315F2461757835,4),1,"normalise_cuts1_$aux5",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_cuts1_$aux5"
#define PRED       X6E6F726D616C6973655F63757473315F2461757835
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      allocate(3)
      get_y_variable(0,0)
      get_y_variable(1,1)
      get_y_bc_reg(2)
      put_constant(X64796E,0,"dyn")
      put_x_value(2,1)
      put_x_value(3,2)
      call(Pred_Name(X746573745F707265645F696E666F,3),0,1,"test_pred_info",3)          /* begin sub 1 */
      cut_y(2)
      put_y_value(1,0)
      get_structure(X63616C6C,1,0,"call")
      unify_y_local_value(0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      get_x_value(0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_alts"
#define PRED       X6E6F726D616C6973655F616C7473
#define ARITY      4

Begin_Private_Pred
      try_me_else(2)
      switch_on_term(G_label(1),fail,fail,fail,G_label(1))

label(1)
      allocate(3)
      get_structure(X3A2D,2,0,":-")
      unify_x_variable(4)
      unify_x_variable(0)
      get_structure(X3A2D,2,2,":-")
      unify_x_value(4)
      unify_y_variable(2)
      get_x_variable(5,3)
      put_x_variable(2,6)
      put_x_variable(3,3)
      builtin_3(functor,4,6,3)
      put_x_value(4,3)
      put_y_variable(1,4)
      put_y_variable(0,6)
      call(Pred_Name(X6E6F726D616C6973655F616C747331,7),1,1,"normalise_alts1",7)          /* begin sub 1 */
      put_constant(X6465627567,1,"debug")
      put_x_variable(3,0)
      builtin_2(g_read,1,0)
      put_y_value(2,0)
      put_y_unsafe_value(1,1)
      put_y_unsafe_value(0,2)
      deallocate
      execute(Pred_Name(X6E6F726D616C6973655F616C74735F2461757836,4),1,"normalise_alts_$aux6",4)

label(2)
      trust_me_else_fail
      get_x_value(0,2)
      get_x_value(1,3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_alts_$aux6"
#define PRED       X6E6F726D616C6973655F616C74735F2461757836
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      math_load_x_value(3,3)
      put_integer(0,2)
      builtin_2(eq,3,2)
      neck_cut
      get_x_value(1,0)
      proceed

label(1)
      trust_me_else_fail
      get_x_variable(6,2)
      put_x_variable(2,5)
      put_x_variable(3,4)
      builtin_3(functor,6,5,4)
      execute(Pred_Name(X6E6F726D616C6973655F616C74735F2461757837,4),1,"normalise_alts_$aux7",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_alts_$aux7"
#define PRED       X6E6F726D616C6973655F616C74735F2461757837
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      allocate(3)
      get_y_variable(1,0)
      get_y_variable(0,1)
      get_y_bc_reg(2)
      put_constant(X646566,0,"def")
      put_x_value(2,1)
      put_x_value(3,2)
      call(Pred_Name(X746573745F707265645F696E666F,3),0,1,"test_pred_info",3)          /* begin sub 1 */
      cut_y(2)
      put_y_value(1,0)
      get_y_value(0,0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      get_structure(X2C,2,0,",")
      unify_x_local_value(1)
      unify_constant(X246462675F74727565,"$dbg_true")
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_alts1"
#define PRED       X6E6F726D616C6973655F616C747331
#define ARITY      7

Begin_Private_Pred
      try_me_else(1)
      get_structure(X63616C6C,1,4,"call")
      unify_x_local_value(0)
      get_x_value(1,5)
      get_structure(X63616C6C,1,6,"call")
      unify_void(1)
      builtin_1(var,0)
      proceed

label(1)
      retry_me_else(7)
      switch_on_term(G_label(3),fail,fail,fail,G_label(2))

label(2)
      switch_on_structure(2,"[((,)/2,4),((;)/2,6)]")

label(3)
      try_me_else(5)

label(4)
      allocate(8)
      get_structure(X2C,2,0,",")
      unify_y_variable(3)
      unify_y_variable(7)
      get_y_variable(5,2)
      get_y_variable(4,3)
      get_structure(X2C,2,4,",")
      unify_x_variable(4)
      unify_y_variable(2)
      get_y_variable(1,5)
      get_y_variable(0,6)
      put_y_value(3,0)
      put_y_value(5,2)
      put_structure(X2C,2,3,",")
      unify_y_local_value(4)
      unify_y_value(7)
      put_y_variable(6,5)
      put_x_variable(6,6)
      call(Pred_Name(X6E6F726D616C6973655F616C747331,7),1,1,"normalise_alts1",7)          /* begin sub 1 */
      put_y_value(7,0)
      put_y_unsafe_value(6,1)
      put_y_value(5,2)
      put_structure(X2C,2,3,",")
      unify_y_local_value(4)
      unify_y_value(3)
      put_y_value(2,4)
      put_y_value(1,5)
      put_y_value(0,6)
      deallocate
      execute(Pred_Name(X6E6F726D616C6973655F616C747331,7),1,"normalise_alts1",7)

label(5)
      trust_me_else_fail

label(6)
      allocate(15)
      get_structure(X3B,2,0,";")
      unify_y_variable(4)
      unify_y_variable(3)
      get_y_variable(1,1)
      get_y_variable(9,3)
      get_y_variable(2,4)
      get_y_variable(0,5)
      get_y_value(2,6)
      put_constant(X617578,1,"aux")
      put_y_variable(14,0)
      builtin_2(g_read,1,0)
      math_load_y_value(14,0)
      function_1(inc,0,0)
      put_constant(X617578,1,"aux")
      builtin_2(g_assign,1,0)
      put_x_value(2,0)
      put_y_variable(12,1)
      call(Pred_Name(X6E6F726D616C6973655F616C7473315F2461757838,2),1,2,"normalise_alts1_$aux8",2)          /* begin sub 2 */
      put_y_value(14,0)
      put_y_variable(13,1)
      call(Pred_Name(X6E756D6265725F61746F6D,2),0,3,"number_atom",2)          /* begin sub 3 */
      put_constant(X24617578,0,"$aux")
      put_y_value(13,1)
      put_y_variable(10,2)
      call(Pred_Name(X61746F6D5F636F6E636174,3),0,4,"atom_concat",3)          /* begin sub 4 */
      put_y_value(12,0)
      put_constant(X5F,1,"_")
      put_y_variable(11,2)
      call(Pred_Name(X61746F6D5F636F6E636174,3),0,5,"atom_concat",3)          /* begin sub 5 */
      put_y_value(11,0)
      put_y_value(10,1)
      put_y_variable(6,2)
      call(Pred_Name(X61746F6D5F636F6E636174,3),0,6,"atom_concat",3)          /* begin sub 6 */
      put_y_value(9,0)
      put_nil(1)
      put_y_variable(8,2)
      call(Pred_Name(X6C73745F766172,3),1,7,"lst_var",3)          /* begin sub 7 */
      put_structure(X3B,2,0,";")
      unify_y_value(4)
      unify_y_value(3)
      put_nil(1)
      put_y_variable(7,2)
      call(Pred_Name(X6C73745F766172,3),1,8,"lst_var",3)          /* begin sub 8 */
      put_y_value(8,0)
      put_y_value(7,1)
      put_y_variable(5,2)
      call(Pred_Name(X656E735F696E746572,3),0,9,"ens_inter",3)          /* begin sub 9 */
      put_y_value(2,1)
      put_list(0)
      unify_y_local_value(6)
      unify_y_local_value(5)
      builtin_2(term_univ,1,0)
      put_y_value(2,4)
      put_x_variable(1,3)
      put_x_variable(2,0)
      builtin_3(functor,4,3,0)
      put_constant(X646566,0,"def")
      call(Pred_Name(X7365745F707265645F696E666F,3),0,10,"set_pred_info",3)          /* begin sub 10 */
      put_structure(X3B,2,0,";")
      unify_y_value(4)
      unify_y_value(3)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X6C696E656172697365,4),1,"linearise",4)

label(7)
      trust_me_else_fail
      get_x_value(0,4)
      get_x_value(1,5)
      get_x_value(0,6)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_alts1_$aux8"
#define PRED       X6E6F726D616C6973655F616C7473315F2461757838
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      allocate(4)
      get_y_variable(1,0)
      get_y_variable(0,1)
      get_y_bc_reg(3)
      put_y_value(1,0)
      put_y_variable(2,1)
      put_integer(5,2)
      put_constant(X5F24617578,3,"_$aux")
      call(Pred_Name(X7375625F61746F6D,4),0,1,"sub_atom",4)          /* begin sub 1 */
      cut_y(3)
      math_load_y_value(2,0)
      function_1(dec,2,0)
      put_y_value(1,0)
      put_integer(1,1)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X7375625F61746F6D,4),0,"sub_atom",4)

label(1)
      trust_me_else_fail
      get_x_value(0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "linearise"
#define PRED       X6C696E656172697365
#define ARITY      4

Begin_Private_Pred
      execute(Pred_Name(X6C696E6561726973655F2461757839,4),1,"linearise_$aux9",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "linearise_$aux9"
#define PRED       X6C696E6561726973655F2461757839
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      allocate(4)
      get_y_variable(2,1)
      get_y_variable(0,3)
      get_structure(X3B,2,0,";")
      unify_y_variable(3)
      unify_x_variable(0)
      neck_cut
      put_y_value(2,1)
      put_y_variable(1,3)
      call(Pred_Name(X6C696E656172697365,4),1,1,"linearise",4)          /* begin sub 1 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_unsafe_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X6C696E65617269736531,4),1,"linearise1",4)

label(1)
      trust_me_else_fail
      execute(Pred_Name(X6C696E65617269736531,4),1,"linearise1",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "linearise1"
#define PRED       X6C696E65617269736531
#define ARITY      4

Begin_Private_Pred
      execute(Pred_Name(X6C696E656172697365315F246175783130,4),1,"linearise1_$aux10",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "linearise1_$aux10"
#define PRED       X6C696E656172697365315F246175783130
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      put_constant(X6661696C,1,"fail")
      builtin_2(term_eq,0,1)
      neck_cut
      get_x_value(2,3)
      proceed

label(1)
      trust_me_else_fail
      allocate(3)
      get_x_variable(4,0)
      get_y_variable(0,2)
      get_y_variable(2,3)
      put_structure(X3A2D,2,0,":-")
      unify_x_local_value(1)
      unify_x_local_value(4)
      put_y_variable(1,1)
      call(Pred_Name(X636F70795F7465726D,2),0,1,"copy_term",2)          /* begin sub 1 */
      put_y_value(2,0)
      get_list(0)
      unify_y_local_value(1)
      unify_y_local_value(0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "lst_var"
#define PRED       X6C73745F766172
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      get_x_variable(3,0)
      builtin_1(var,3)
      neck_cut
      put_x_value(1,0)
      put_x_value(3,1)
      execute(Pred_Name(X656E735F616A6F7574,3),0,"ens_ajout",3)

label(1)
      trust_me_else_fail
      get_x_variable(5,0)
      get_x_variable(3,1)
      get_x_variable(4,2)
      put_x_variable(0,2)
      put_x_variable(1,0)
      builtin_3(functor,5,2,0)
      put_integer(1,0)
      put_x_value(5,2)
      execute(Pred_Name(X6C73745F7661725F61726773,5),1,"lst_var_args",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "lst_var_args"
#define PRED       X6C73745F7661725F61726773
#define ARITY      5

Begin_Private_Pred
      execute(Pred_Name(X6C73745F7661725F617267735F246175783131,5),1,"lst_var_args_$aux11",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "lst_var_args_$aux11"
#define PRED       X6C73745F7661725F617267735F246175783131
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      allocate(5)
      get_y_variable(4,0)
      get_y_variable(3,1)
      get_y_variable(2,2)
      get_y_variable(0,4)
      math_load_y_value(4,1)
      math_load_y_value(3,0)
      builtin_2(lte,1,0)
      neck_cut
      put_y_value(4,4)
      put_y_value(2,2)
      put_x_variable(0,1)
      builtin_3(arg,4,2,1)
      put_x_value(3,1)
      put_y_variable(1,2)
      call(Pred_Name(X6C73745F766172,3),1,1,"lst_var",3)          /* begin sub 1 */
      math_load_y_value(4,0)
      function_1(inc,0,0)
      put_y_value(3,1)
      put_y_value(2,2)
      put_y_unsafe_value(1,3)
      put_y_value(0,4)
      deallocate
      execute(Pred_Name(X6C73745F7661725F61726773,5),1,"lst_var_args",5)

label(1)
      trust_me_else_fail
      get_x_value(3,4)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_fdc"
#define PRED       X6E6F726D616C6973655F666463
#define ARITY      3

Begin_Private_Pred
      try_me_else(2)
      switch_on_term(G_label(1),fail,fail,fail,G_label(1))

label(1)
      allocate(3)
      get_structure(X3A2D,2,0,":-")
      unify_x_variable(3)
      unify_x_variable(0)
      get_structure(X3A2D,2,1,":-")
      unify_x_value(3)
      unify_x_variable(4)
      get_x_variable(5,2)
      put_nil(1)
      put_y_variable(2,2)
      put_y_variable(1,3)
      put_y_variable(0,6)
      call(Pred_Name(X6E6F726D616C6973655F66646331,7),1,1,"normalise_fdc1",7)          /* begin sub 1 */
      put_y_unsafe_value(2,0)
      put_y_unsafe_value(1,1)
      put_y_unsafe_value(0,2)
      deallocate
      execute(Pred_Name(X6E6F726D616C6973655F6664635F246175783132,3),1,"normalise_fdc_$aux12",3)

label(2)
      trust_me_else_fail
      get_x_value(0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_fdc_$aux12"
#define PRED       X6E6F726D616C6973655F6664635F246175783132
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      allocate(4)
      get_y_variable(1,0)
      get_y_variable(3,1)
      put_nil(0)
      builtin_2(term_neq,2,0)
      neck_cut
      put_x_value(2,0)
      put_y_variable(2,1)
      put_y_variable(0,2)
      call(Pred_Name(X637265655F66645F415F6672616D65,3),1,1,"cree_fd_A_frame",3)          /* begin sub 1 */
      put_y_value(3,0)
      get_structure(X2C,2,0,",")
      unify_x_variable(0)
      unify_y_local_value(0)
      get_structure(X2466645F7365745F4146,2,0,"$fd_set_AF")
      unify_y_local_value(2)
      unify_y_local_value(1)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_fdc1"
#define PRED       X6E6F726D616C6973655F66646331
#define ARITY      7

Begin_Private_Pred
      try_me_else(18)
      switch_on_term(G_label(2),fail,fail,fail,G_label(1))

label(1)
      switch_on_structure(1,"[((,)/2,3),((in)/2,5),((#=)/2,7),((#\=)/2,9),((#>=)/2,11),((#>)/2,13),((#<=)/2,15),((#<)/2,17)]")

label(2)
      try_me_else(4)

label(3)
      allocate(9)
      get_structure(X2C,2,0,",")
      unify_x_variable(0)
      unify_y_variable(8)
      get_y_variable(6,2)
      get_y_variable(5,3)
      get_structure(X2C,2,4,",")
      unify_x_variable(4)
      unify_y_variable(4)
      get_y_variable(0,5)
      get_y_variable(3,6)
      put_y_value(6,2)
      put_y_value(5,3)
      put_y_variable(2,5)
      put_y_variable(7,6)
      call(Pred_Name(X6E6F726D616C6973655F66646331,7),1,1,"normalise_fdc1",7)          /* begin sub 1 */
      put_y_value(8,0)
      put_y_value(7,1)
      put_y_value(6,2)
      put_y_value(5,3)
      put_y_value(4,4)
      put_y_variable(1,5)
      put_y_value(3,6)
      call(Pred_Name(X6E6F726D616C6973655F66646331,7),1,2,"normalise_fdc1",7)          /* begin sub 2 */
      put_y_unsafe_value(2,0)
      put_y_unsafe_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X617070656E64,3),0,"append",3)

label(4)
      retry_me_else(6)

label(5)
      allocate(13)
      get_structure(X696E,2,0,"in")
      unify_y_variable(12)
      unify_x_variable(0)
      get_y_variable(4,1)
      get_y_variable(3,2)
      get_y_variable(2,3)
      get_y_variable(1,4)
      get_y_variable(8,5)
      get_y_variable(9,6)
      put_y_variable(11,1)
      put_y_variable(7,2)
      call(Pred_Name(X6E6F726D616C6973655F666463315F246175783133,3),1,3,"normalise_fdc1_$aux13",3)          /* begin sub 3 */
      put_constant(X6E6F5F666463,1,"no_fdc")
      put_y_variable(0,0)
      builtin_2(g_read,1,0)
      math_load_y_value(0,0)
      function_1(inc,0,0)
      put_constant(X6E6F5F666463,1,"no_fdc")
      builtin_2(g_assign,1,0)
      put_y_value(4,0)
      put_constant(X6676,1,"fv")
      put_y_value(12,2)
      put_integer(-1,3)
      put_y_variable(10,4)
      put_y_variable(6,5)
      call(Pred_Name(X6E6F5F66645F617267,6),1,4,"no_fd_arg",6)          /* begin sub 4 */
      put_list(0)
      unify_y_local_value(11)
      unify_nil
      put_y_value(10,1)
      put_list(2)
      unify_y_variable(5)
      unify_nil
      put_y_value(9,3)
      call(Pred_Name(X7472616974655F66645F617267,4),1,5,"traite_fd_arg",4)          /* begin sub 5 */
      put_y_value(8,0)
      get_list(0)
      unify_x_variable(0)
      unify_nil
      get_structure(X63737472,4,0,"cstr")
      unify_y_local_value(0)
      unify_y_local_value(7)
      unify_x_variable(0)
      unify_y_value(5)
      get_structure(X6676,1,0,"fv")
      unify_y_local_value(6)
      put_y_value(4,0)
      put_y_value(3,1)
      put_y_value(2,2)
      put_y_value(1,3)
      put_y_unsafe_value(0,4)
      deallocate
      execute(Pred_Name(X6E6F726D616C6973655F666463315F246175783134,5),1,"normalise_fdc1_$aux14",5)

label(6)
      retry_me_else(8)

label(7)
      allocate(1)
      get_structure(X233D,2,0,"#=")
      unify_x_variable(0)
      unify_x_variable(7)
      get_y_variable(0,4)
      get_nil(5)
      get_x_value(1,6)
      put_x_value(7,1)
      put_y_value(0,2)
      call(Pred_Name(X7472616E73665F6571,3),1,6,"transf_eq",3)          /* begin sub 6 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X6E6F726D616C6973655F666463315F246175783135,1),1,"normalise_fdc1_$aux15",1)

label(8)
      retry_me_else(10)

label(9)
      allocate(1)
      get_structure(X235C3D,2,0,"#\\=")
      unify_x_variable(0)
      unify_x_variable(7)
      get_y_variable(0,4)
      get_nil(5)
      get_x_value(1,6)
      put_x_value(7,1)
      put_y_value(0,2)
      call(Pred_Name(X7472616E73665F6E65,3),1,7,"transf_ne",3)          /* begin sub 7 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X6E6F726D616C6973655F666463315F246175783136,1),1,"normalise_fdc1_$aux16",1)

label(10)
      retry_me_else(12)

label(11)
      allocate(1)
      get_structure(X233E3D,2,0,"#>=")
      unify_x_variable(0)
      unify_x_variable(7)
      get_y_variable(0,4)
      get_nil(5)
      get_x_value(1,6)
      put_x_value(7,1)
      put_y_value(0,2)
      call(Pred_Name(X7472616E73665F6765,3),1,8,"transf_ge",3)          /* begin sub 8 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X6E6F726D616C6973655F666463315F246175783137,1),1,"normalise_fdc1_$aux17",1)

label(12)
      retry_me_else(14)

label(13)
      allocate(1)
      get_structure(X233E,2,0,"#>")
      unify_x_variable(0)
      unify_x_variable(7)
      get_y_variable(0,4)
      get_nil(5)
      get_x_value(1,6)
      put_x_value(7,1)
      put_y_value(0,2)
      call(Pred_Name(X7472616E73665F67,3),1,9,"transf_g",3)          /* begin sub 9 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X6E6F726D616C6973655F666463315F246175783138,1),1,"normalise_fdc1_$aux18",1)

label(14)
      retry_me_else(16)

label(15)
      allocate(1)
      get_structure(X233C3D,2,0,"#<=")
      unify_x_variable(7)
      unify_x_variable(0)
      get_y_variable(0,4)
      get_nil(5)
      get_x_value(1,6)
      put_x_value(7,1)
      put_y_value(0,2)
      call(Pred_Name(X7472616E73665F6765,3),1,10,"transf_ge",3)          /* begin sub 10 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X6E6F726D616C6973655F666463315F246175783139,1),1,"normalise_fdc1_$aux19",1)

label(16)
      trust_me_else_fail

label(17)
      allocate(1)
      get_structure(X233C,2,0,"#<")
      unify_x_variable(7)
      unify_x_variable(0)
      get_y_variable(0,4)
      get_nil(5)
      get_x_value(1,6)
      put_x_value(7,1)
      put_y_value(0,2)
      call(Pred_Name(X7472616E73665F67,3),1,11,"transf_g",3)          /* begin sub 11 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X6E6F726D616C6973655F666463315F246175783230,1),1,"normalise_fdc1_$aux20",1)

label(18)
      trust_me_else_fail
      get_x_value(0,4)
      get_nil(5)
      get_x_value(1,6)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_fdc1_$aux14"
#define PRED       X6E6F726D616C6973655F666463315F246175783134
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      put_nil(5)
      builtin_2(term_eq,0,5)
      neck_cut
      get_structure(X2C,2,3,",")
      unify_x_local_value(2)
      unify_x_variable(0)
      get_structure(X2466645F63737472,2,0,"$fd_cstr")
      unify_x_local_value(4)
      unify_x_local_value(1)
      proceed

label(1)
      trust_me_else_fail
      get_structure(X2466645F63737472,2,3,"$fd_cstr")
      unify_x_local_value(4)
      unify_x_local_value(1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_fdc1_$aux13"
#define PRED       X6E6F726D616C6973655F666463315F246175783133
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      builtin_1(nonvar,0)
      get_structure(X6E6F5F6F707432,1,0,"no_opt2")
      unify_x_local_value(1)
      neck_cut
      get_integer(0,2)
      proceed

label(1)
      trust_me_else_fail
      get_x_value(0,1)
      get_integer(1,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_fdc1_$aux15"
#define PRED       X6E6F726D616C6973655F666463315F246175783135
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      allocate(0)
      put_constant(X766572626F7365,2,"verbose")
      put_constant(X74,1,"t")
      builtin_2(g_read,2,1)
      neck_cut
      call(Pred_Name(X7772697465,1),0,1,"write",1)          /* begin sub 1 */
      call(Pred_Name(X6E6C,0),0,2,"nl",0)          /* begin sub 2 */
      deallocate
      execute(Pred_Name(X6E6C,0),0,"nl",0)

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_fdc1_$aux16"
#define PRED       X6E6F726D616C6973655F666463315F246175783136
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      allocate(0)
      put_constant(X766572626F7365,2,"verbose")
      put_constant(X74,1,"t")
      builtin_2(g_read,2,1)
      neck_cut
      call(Pred_Name(X7772697465,1),0,1,"write",1)          /* begin sub 1 */
      call(Pred_Name(X6E6C,0),0,2,"nl",0)          /* begin sub 2 */
      deallocate
      execute(Pred_Name(X6E6C,0),0,"nl",0)

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_fdc1_$aux17"
#define PRED       X6E6F726D616C6973655F666463315F246175783137
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      allocate(0)
      put_constant(X766572626F7365,2,"verbose")
      put_constant(X74,1,"t")
      builtin_2(g_read,2,1)
      neck_cut
      call(Pred_Name(X7772697465,1),0,1,"write",1)          /* begin sub 1 */
      call(Pred_Name(X6E6C,0),0,2,"nl",0)          /* begin sub 2 */
      deallocate
      execute(Pred_Name(X6E6C,0),0,"nl",0)

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_fdc1_$aux18"
#define PRED       X6E6F726D616C6973655F666463315F246175783138
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      allocate(0)
      put_constant(X766572626F7365,2,"verbose")
      put_constant(X74,1,"t")
      builtin_2(g_read,2,1)
      neck_cut
      call(Pred_Name(X7772697465,1),0,1,"write",1)          /* begin sub 1 */
      call(Pred_Name(X6E6C,0),0,2,"nl",0)          /* begin sub 2 */
      deallocate
      execute(Pred_Name(X6E6C,0),0,"nl",0)

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_fdc1_$aux19"
#define PRED       X6E6F726D616C6973655F666463315F246175783139
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      allocate(0)
      put_constant(X766572626F7365,2,"verbose")
      put_constant(X74,1,"t")
      builtin_2(g_read,2,1)
      neck_cut
      call(Pred_Name(X7772697465,1),0,1,"write",1)          /* begin sub 1 */
      call(Pred_Name(X6E6C,0),0,2,"nl",0)          /* begin sub 2 */
      deallocate
      execute(Pred_Name(X6E6C,0),0,"nl",0)

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_fdc1_$aux20"
#define PRED       X6E6F726D616C6973655F666463315F246175783230
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      allocate(0)
      put_constant(X766572626F7365,2,"verbose")
      put_constant(X74,1,"t")
      builtin_2(g_read,2,1)
      neck_cut
      call(Pred_Name(X7772697465,1),0,1,"write",1)          /* begin sub 1 */
      call(Pred_Name(X6E6C,0),0,2,"nl",0)          /* begin sub 2 */
      deallocate
      execute(Pred_Name(X6E6C,0),0,"nl",0)

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "traite_fd_arg"
#define PRED       X7472616974655F66645F617267
#define ARITY      4

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(3),fail,G_label(1),fail)

label(1)
      try(5,1)          /* begin sub 1 */
      trust(7)

label(2)
      try_me_else(4)

label(3)
      get_nil(0)
      get_nil(2)
      get_x_value(1,3)
      proceed

label(4)
      retry_me_else(6)

label(5)
      allocate(9)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_y_variable(7,1)
      get_list(2)
      unify_x_variable(1)
      unify_y_variable(1)
      get_y_variable(0,3)
      get_y_bc_reg(8)
      put_y_variable(6,2)
      put_y_variable(5,3)
      put_y_variable(4,4)
      call(Pred_Name(X7472616974655F66645F6172675F246175783231,5),1,2,"traite_fd_arg_$aux21",5)          /* begin sub 2 */
      cut_y(8)
      put_y_value(7,0)
      put_structure(X6670,1,1,"fp")
      unify_y_local_value(6)
      put_y_value(5,2)
      put_integer(-1,3)
      put_y_variable(2,4)
      put_y_value(4,5)
      call(Pred_Name(X6E6F5F66645F617267,6),1,3,"no_fd_arg",6)          /* begin sub 3 */
      put_y_value(3,0)
      put_y_unsafe_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X7472616974655F66645F617267,4),1,"traite_fd_arg",4)

label(6)
      trust_me_else_fail

label(7)
      allocate(7)
      get_list(0)
      unify_x_variable(4)
      unify_y_variable(3)
      get_list(2)
      unify_y_variable(6)
      unify_y_variable(1)
      get_y_variable(0,3)
      put_list(0)
      unify_y_variable(5)
      unify_x_variable(2)
      builtin_2(term_univ,4,0)
      put_x_value(1,0)
      put_y_value(5,1)
      put_y_variable(4,3)
      put_y_variable(2,4)
      call(Pred_Name(X7472616974655F66645F6172675F246175783232,5),1,4,"traite_fd_arg_$aux22",5)          /* begin sub 4 */
      put_y_value(6,1)
      put_list(0)
      unify_y_value(5)
      unify_y_local_value(4)
      builtin_2(term_univ,1,0)
      put_y_value(3,0)
      put_y_unsafe_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X7472616974655F66645F617267,4),1,"traite_fd_arg",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "traite_fd_arg_$aux21"
#define PRED       X7472616974655F66645F6172675F246175783231
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      builtin_1(var,0)
      get_x_value(0,3)
      get_constant(X74,2,"t")
      get_structure(X6670,2,1,"fp")
      unify_x_local_value(4)
      unify_constant(X74,"t")
      proceed

label(1)
      trust_me_else_fail
      get_list(0)
      unify_x_local_value(3)
      unify_void(1)
      get_constant(X72,2,"r")
      get_list(1)
      unify_x_variable(0)
      unify_nil
      get_structure(X6670,2,0,"fp")
      unify_x_local_value(4)
      unify_constant(X72,"r")
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "traite_fd_arg_$aux22"
#define PRED       X7472616974655F66645F6172675F246175783232
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      allocate(6)
      get_y_variable(3,0)
      get_y_variable(5,2)
      get_y_variable(1,3)
      get_y_variable(2,4)
      get_y_bc_reg(4)
      put_x_value(1,0)
      call(Pred_Name(X7472616974655F66645F6172675F246175783233,1),1,1,"traite_fd_arg_$aux23",1)          /* begin sub 1 */
      put_y_value(5,0)
      get_list(0)
      unify_x_variable(2)
      unify_nil
      builtin_1(var,2)
      cut_y(4)
      put_y_value(3,0)
      put_constant(X6676,1,"fv")
      put_integer(-1,3)
      put_y_value(2,4)
      put_y_variable(0,5)
      call(Pred_Name(X6E6F5F66645F617267,6),1,2,"no_fd_arg",6)          /* begin sub 2 */
      put_y_value(1,0)
      get_list(0)
      unify_x_variable(0)
      unify_nil
      get_structure(X6676,1,0,"fv")
      unify_y_local_value(0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      get_x_variable(5,0)
      put_x_value(2,0)
      put_x_value(5,1)
      put_x_value(3,2)
      put_x_value(4,3)
      execute(Pred_Name(X7472616974655F66645F617267,4),1,"traite_fd_arg",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "traite_fd_arg_$aux23"
#define PRED       X7472616974655F66645F6172675F246175783233
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      get_constant(X7369676D61,0,"sigma")
      proceed

label(1)
      retry_me_else(2)
      get_constant(X646566,0,"def")
      proceed

label(2)
      retry_me_else(3)
      get_constant(X6D696E,0,"min")
      proceed

label(3)
      retry_me_else(4)
      get_constant(X6D6178,0,"max")
      proceed

label(4)
      trust_me_else_fail
      get_constant(X76616C,0,"val")
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "no_fd_arg"
#define PRED       X6E6F5F66645F617267
#define ARITY      6

Begin_Private_Pred
      try_me_else(2)
      switch_on_term(G_label(1),G_label(1),fail,fail,fail)

label(1)
      get_nil(0)
      get_list(4)
      unify_x_variable(0)
      unify_nil
      get_structure(X617267,3,0,"arg")
      unify_x_local_value(1)
      unify_x_local_value(2)
      unify_x_variable(1)
      get_x_value(1,5)
      math_load_x_value(3,3)
      function_1(inc,0,3)
      get_x_value(1,0)
      proceed

label(2)
      retry_me_else(3)
      get_x_value(0,4)
      get_list(0)
      unify_x_variable(0)
      unify_void(1)
      get_structure(X617267,3,0,"arg")
      unify_x_local_value(1)
      unify_x_variable(0)
      unify_x_local_value(5)
      builtin_2(term_eq,2,0)
      proceed

label(3)
      trust_me_else_fail
      switch_on_term(G_label(4),fail,fail,G_label(4),fail)

label(4)
      get_list(0)
      unify_x_variable(6)
      unify_x_variable(0)
      get_list(4)
      unify_x_value(6)
      unify_x_variable(4)
      get_structure(X617267,3,6,"arg")
      unify_void(2)
      unify_x_variable(3)
      execute(Pred_Name(X6E6F5F66645F617267,6),1,"no_fd_arg",6)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "cree_fd_A_frame"
#define PRED       X637265655F66645F415F6672616D65
#define ARITY      3

Begin_Private_Pred
      switch_on_term(G_label(1),fail,fail,G_label(1),fail)

label(1)
      allocate(4)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_structure(X617267,3,0,"arg")
      unify_x_variable(0)
      unify_x_variable(3)
      unify_void(1)
      get_y_variable(2,1)
      get_y_variable(1,2)
      put_x_value(3,1)
      put_y_variable(0,2)
      call(Pred_Name(X637265655F66645F415F6672616D655F246175783234,3),1,1,"cree_fd_A_frame_$aux24",3)          /* begin sub 1 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_unsafe_value(0,3)
      deallocate
      execute(Pred_Name(X637265655F66645F415F6672616D655F246175783235,4),1,"cree_fd_A_frame_$aux25",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "cree_fd_A_frame_$aux25"
#define PRED       X637265655F66645F415F6672616D655F246175783235
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      put_nil(4)
      builtin_2(term_eq,0,4)
      neck_cut
      get_x_value(3,2)
      get_integer(1,1)
      proceed

label(1)
      trust_me_else_fail
      allocate(5)
      get_y_variable(4,1)
      get_y_variable(2,2)
      get_y_variable(1,3)
      put_y_variable(3,1)
      put_y_variable(0,2)
      call(Pred_Name(X637265655F66645F415F6672616D65,3),1,1,"cree_fd_A_frame",3)          /* begin sub 1 */
      math_load_y_value(3,0)
      function_1(inc,0,0)
      get_y_value(4,0)
      put_y_value(2,0)
      get_structure(X2C,2,0,",")
      unify_y_local_value(1)
      unify_y_local_value(0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "cree_fd_A_frame_$aux24"
#define PRED       X637265655F66645F415F6672616D655F246175783234
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      get_structure(X6670,1,0,"fp")
      unify_x_variable(0)
      neck_cut
      get_structure(X2466645F6670,2,2,"$fd_fp")
      unify_x_local_value(1)
      unify_x_value(0)
      proceed

label(1)
      trust_me_else_fail
      get_structure(X2466645F6676,1,2,"$fd_fv")
      unify_x_local_value(1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "transf_eq"
#define PRED       X7472616E73665F6571
#define ARITY      3

Begin_Private_Pred
      allocate(7)
      get_structure(X2C,2,2,",")
      unify_x_variable(6)
      unify_x_variable(2)
      get_structure(X2C,2,2,",")
      unify_y_variable(4)
      unify_y_variable(0)
      put_y_variable(6,2)
      put_y_variable(5,3)
      put_y_variable(3,4)
      put_y_variable(2,5)
      call(Pred_Name(X6E6F726D616C697A65,7),1,1,"normalize",7)          /* begin sub 1 */
      put_y_value(6,0)
      put_y_value(5,1)
      put_y_variable(1,2)
      put_y_value(4,3)
      call(Pred_Name(X65715F766172,4),1,2,"eq_var",4)          /* begin sub 2 */
      put_y_unsafe_value(3,0)
      put_y_unsafe_value(2,1)
      put_y_unsafe_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X65715F766172,4),1,"eq_var",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "transf_ne"
#define PRED       X7472616E73665F6E65
#define ARITY      3

Begin_Private_Pred
      allocate(8)
      get_structure(X2C,2,2,",")
      unify_x_variable(6)
      unify_x_variable(2)
      get_structure(X2C,2,2,",")
      unify_y_variable(4)
      unify_x_variable(2)
      get_structure(X2C,2,2,",")
      unify_y_variable(0)
      unify_x_variable(2)
      get_structure(X70616320783C3E79,2,2,"pac x<>y")
      unify_y_variable(5)
      unify_y_variable(1)
      put_y_variable(7,2)
      put_y_variable(6,3)
      put_y_variable(3,4)
      put_y_variable(2,5)
      call(Pred_Name(X6E6F726D616C697A65,7),1,1,"normalize",7)          /* begin sub 1 */
      put_y_value(7,0)
      put_y_value(6,1)
      put_y_value(5,2)
      put_y_value(4,3)
      call(Pred_Name(X65715F766172,4),1,2,"eq_var",4)          /* begin sub 2 */
      put_y_unsafe_value(3,0)
      put_y_unsafe_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X65715F766172,4),1,"eq_var",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "transf_ge"
#define PRED       X7472616E73665F6765
#define ARITY      3

Begin_Private_Pred
      allocate(8)
      get_structure(X2C,2,2,",")
      unify_x_variable(6)
      unify_x_variable(2)
      get_structure(X2C,2,2,",")
      unify_y_variable(4)
      unify_x_variable(2)
      get_structure(X2C,2,2,",")
      unify_y_variable(0)
      unify_x_variable(2)
      get_structure(X70616320783E3D79,2,2,"pac x>=y")
      unify_y_variable(5)
      unify_y_variable(1)
      put_y_variable(7,2)
      put_y_variable(6,3)
      put_y_variable(3,4)
      put_y_variable(2,5)
      call(Pred_Name(X6E6F726D616C697A65,7),1,1,"normalize",7)          /* begin sub 1 */
      put_y_value(7,0)
      put_y_value(6,1)
      put_y_value(5,2)
      put_y_value(4,3)
      call(Pred_Name(X65715F766172,4),1,2,"eq_var",4)          /* begin sub 2 */
      put_y_unsafe_value(3,0)
      put_y_unsafe_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X65715F766172,4),1,"eq_var",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "transf_g"
#define PRED       X7472616E73665F67
#define ARITY      3

Begin_Private_Pred
      allocate(8)
      get_structure(X2C,2,2,",")
      unify_x_variable(6)
      unify_x_variable(2)
      get_structure(X2C,2,2,",")
      unify_y_variable(4)
      unify_x_variable(2)
      get_structure(X2C,2,2,",")
      unify_y_variable(0)
      unify_x_variable(2)
      get_structure(X70616320783E79,2,2,"pac x>y")
      unify_y_variable(5)
      unify_y_variable(1)
      put_y_variable(7,2)
      put_y_variable(6,3)
      put_y_variable(3,4)
      put_y_variable(2,5)
      call(Pred_Name(X6E6F726D616C697A65,7),1,1,"normalize",7)          /* begin sub 1 */
      put_y_value(7,0)
      put_y_value(6,1)
      put_y_value(5,2)
      put_y_value(4,3)
      call(Pred_Name(X65715F766172,4),1,2,"eq_var",4)          /* begin sub 2 */
      put_y_unsafe_value(3,0)
      put_y_unsafe_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X65715F766172,4),1,"eq_var",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "eq_var"
#define PRED       X65715F766172
#define ARITY      4

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(3),fail,G_label(1),fail)

label(1)
      try(5,1)          /* begin sub 1 */
      retry(7,2)          /* begin sub 2 */
      trust(9)

label(2)
      try_me_else(4)

label(3)
      get_nil(0)
      get_x_value(1,2)
      get_constant(X74727565,3,"true")
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_list(0)
      unify_x_variable(0)
      unify_nil
      get_structure(X2A,2,0,"*")
      unify_x_variable(0)
      unify_x_variable(7)
      get_x_variable(6,1)
      get_x_variable(5,2)
      get_x_variable(4,3)
      put_x_value(7,1)
      put_x_value(6,2)
      put_x_value(5,3)
      execute(Pred_Name(X65715F7661725F246175783236,5),1,"eq_var_$aux26",5)

label(6)
      retry_me_else(8)

label(7)
      get_list(0)
      unify_x_variable(0)
      unify_x_variable(4)
      get_structure(X2A,2,0,"*")
      unify_x_variable(0)
      unify_x_variable(9)
      get_list(4)
      unify_x_variable(4)
      unify_nil
      get_structure(X2A,2,4,"*")
      unify_x_variable(8)
      unify_x_variable(7)
      get_x_variable(4,1)
      get_x_variable(5,2)
      get_x_variable(6,3)
      put_x_value(9,1)
      put_x_value(8,2)
      put_x_value(7,3)
      execute(Pred_Name(X65715F7661725F246175783238,7),1,"eq_var_$aux28",7)

label(8)
      trust_me_else_fail

label(9)
      allocate(7)
      get_list(0)
      unify_x_variable(4)
      unify_x_variable(0)
      get_structure(X2A,2,4,"*")
      unify_y_variable(6)
      unify_y_variable(5)
      get_list(0)
      unify_x_variable(4)
      unify_x_variable(0)
      get_structure(X2A,2,4,"*")
      unify_y_variable(4)
      unify_y_variable(3)
      get_y_variable(2,2)
      get_structure(X2C,2,3,",")
      unify_y_variable(1)
      unify_x_variable(3)
      put_y_variable(0,2)
      call(Pred_Name(X65715F766172,4),1,3,"eq_var",4)          /* begin sub 3 */
      put_y_value(6,0)
      put_y_value(5,1)
      put_y_value(4,2)
      put_y_value(3,3)
      put_y_value(2,4)
      put_y_value(1,5)
      put_y_unsafe_value(0,6)
      deallocate
      execute(Pred_Name(X65715F7661725F246175783332,7),1,"eq_var_$aux32",7)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "eq_var_$aux26"
#define PRED       X65715F7661725F246175783236
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      get_integer(0,2)
      neck_cut
      put_x_value(3,2)
      put_x_value(4,3)
      execute(Pred_Name(X65715F7661725F246175783237,4),1,"eq_var_$aux27",4)

label(1)
      retry_me_else(2)
      get_integer(1,0)
      neck_cut
      get_structure(X70616320782B633D79,3,4,"pac x+c=y")
      unify_x_local_value(1)
      unify_x_local_value(2)
      unify_x_local_value(3)
      proceed

label(2)
      trust_me_else_fail
      get_structure(X7061632061782B633D79,4,4,"pac ax+c=y")
      unify_x_local_value(0)
      unify_x_local_value(1)
      unify_x_local_value(2)
      unify_x_local_value(3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "eq_var_$aux27"
#define PRED       X65715F7661725F246175783237
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      get_integer(1,0)
      neck_cut
      get_x_value(2,1)
      get_constant(X74727565,3,"true")
      proceed

label(1)
      trust_me_else_fail
      get_structure(X7061632061783D79,3,3,"pac ax=y")
      unify_x_local_value(0)
      unify_x_local_value(1)
      unify_x_local_value(2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "eq_var_$aux28"
#define PRED       X65715F7661725F246175783238
#define ARITY      7

Begin_Private_Pred
      try_me_else(1)
      get_integer(0,4)
      neck_cut
      put_x_value(5,4)
      put_x_value(6,5)
      execute(Pred_Name(X65715F7661725F246175783239,6),1,"eq_var_$aux29",6)

label(1)
      retry_me_else(2)
      get_integer(1,0)
      neck_cut
      put_x_value(1,0)
      put_x_value(2,1)
      put_x_value(3,2)
      put_x_value(4,3)
      put_x_value(5,4)
      put_x_value(6,5)
      execute(Pred_Name(X65715F7661725F246175783331,6),1,"eq_var_$aux31",6)

label(2)
      retry_me_else(3)
      get_integer(1,2)
      neck_cut
      get_structure(X7061632061782B792B633D7A,5,6,"pac ax+y+c=z")
      unify_x_local_value(0)
      unify_x_local_value(1)
      unify_x_local_value(3)
      unify_x_local_value(4)
      unify_x_local_value(5)
      proceed

label(3)
      trust_me_else_fail
      get_structure(X7061632061782B62792B633D7A,6,6,"pac ax+by+c=z")
      unify_x_local_value(0)
      unify_x_local_value(1)
      unify_x_local_value(2)
      unify_x_local_value(3)
      unify_x_local_value(4)
      unify_x_local_value(5)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "eq_var_$aux29"
#define PRED       X65715F7661725F246175783239
#define ARITY      6

Begin_Private_Pred
      try_me_else(1)
      get_integer(1,0)
      neck_cut
      put_x_value(1,0)
      put_x_value(2,1)
      put_x_value(3,2)
      put_x_value(4,3)
      put_x_value(5,4)
      execute(Pred_Name(X65715F7661725F246175783330,5),1,"eq_var_$aux30",5)

label(1)
      retry_me_else(2)
      get_integer(1,2)
      neck_cut
      get_structure(X7061632061782B793D7A,4,5,"pac ax+y=z")
      unify_x_local_value(0)
      unify_x_local_value(1)
      unify_x_local_value(3)
      unify_x_local_value(4)
      proceed

label(2)
      trust_me_else_fail
      get_structure(X7061632061782B62793D7A,5,5,"pac ax+by=z")
      unify_x_local_value(0)
      unify_x_local_value(1)
      unify_x_local_value(2)
      unify_x_local_value(3)
      unify_x_local_value(4)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "eq_var_$aux30"
#define PRED       X65715F7661725F246175783330
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      get_integer(1,1)
      neck_cut
      get_structure(X70616320782B793D7A,3,4,"pac x+y=z")
      unify_x_local_value(0)
      unify_x_local_value(2)
      unify_x_local_value(3)
      proceed

label(1)
      trust_me_else_fail
      get_structure(X7061632061782B793D7A,4,4,"pac ax+y=z")
      unify_x_local_value(1)
      unify_x_local_value(2)
      unify_x_local_value(0)
      unify_x_local_value(3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "eq_var_$aux31"
#define PRED       X65715F7661725F246175783331
#define ARITY      6

Begin_Private_Pred
      try_me_else(1)
      get_integer(1,1)
      neck_cut
      get_structure(X70616320782B792B633D7A,4,5,"pac x+y+c=z")
      unify_x_local_value(0)
      unify_x_local_value(2)
      unify_x_local_value(3)
      unify_x_local_value(4)
      proceed

label(1)
      trust_me_else_fail
      get_structure(X7061632061782B792B633D7A,5,5,"pac ax+y+c=z")
      unify_x_local_value(1)
      unify_x_local_value(2)
      unify_x_local_value(0)
      unify_x_local_value(3)
      unify_x_local_value(4)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "eq_var_$aux32"
#define PRED       X65715F7661725F246175783332
#define ARITY      7

Begin_Private_Pred
      try_me_else(1)
      get_integer(1,0)
      neck_cut
      put_x_value(1,0)
      put_x_value(2,1)
      put_x_value(3,2)
      put_x_value(4,3)
      put_x_value(5,4)
      put_x_value(6,5)
      execute(Pred_Name(X65715F7661725F246175783333,6),1,"eq_var_$aux33",6)

label(1)
      retry_me_else(2)
      get_integer(1,2)
      neck_cut
      get_structure(X7061632061782B792B7A3D74,5,5,"pac ax+y+z=t")
      unify_x_local_value(0)
      unify_x_local_value(1)
      unify_x_local_value(3)
      unify_x_local_value(6)
      unify_x_local_value(4)
      proceed

label(2)
      trust_me_else_fail
      get_structure(X7061632061782B62792B7A3D74,6,5,"pac ax+by+z=t")
      unify_x_local_value(0)
      unify_x_local_value(1)
      unify_x_local_value(2)
      unify_x_local_value(3)
      unify_x_local_value(6)
      unify_x_local_value(4)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "eq_var_$aux33"
#define PRED       X65715F7661725F246175783333
#define ARITY      6

Begin_Private_Pred
      try_me_else(1)
      get_integer(1,1)
      neck_cut
      get_structure(X70616320782B792B7A3D74,4,4,"pac x+y+z=t")
      unify_x_local_value(0)
      unify_x_local_value(2)
      unify_x_local_value(5)
      unify_x_local_value(3)
      proceed

label(1)
      trust_me_else_fail
      get_structure(X7061632061782B792B7A3D74,5,4,"pac ax+y+z=t")
      unify_x_local_value(1)
      unify_x_local_value(2)
      unify_x_local_value(0)
      unify_x_local_value(5)
      unify_x_local_value(3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalize"
#define PRED       X6E6F726D616C697A65
#define ARITY      7

Begin_Private_Pred
      allocate(11)
      get_x_variable(7,0)
      get_y_variable(4,2)
      get_y_variable(10,3)
      get_y_variable(1,4)
      get_y_variable(9,5)
      get_y_bc_reg(0)
      put_structure(X2D,2,0,"-")
      unify_x_local_value(7)
      unify_x_local_value(1)
      put_integer(1,1)
      put_y_variable(7,2)
      put_y_variable(8,3)
      put_x_value(6,4)
      call(Pred_Name(X6E6F726D616C697A6531,5),1,1,"normalize1",5)          /* begin sub 1 */
      put_y_value(10,0)
      put_y_value(9,1)
      put_y_value(8,2)
      call(Pred_Name(X6E6F726D616C697A655F246175783334,3),1,2,"normalize_$aux34",3)          /* begin sub 2 */
      put_y_value(7,0)
      put_y_variable(6,1)
      put_y_variable(3,2)
      call(Pred_Name(X73706C6974,3),1,3,"split",3)          /* begin sub 3 */
      put_y_value(6,0)
      put_y_variable(5,1)
      call(Pred_Name(X736F7274,2),0,4,"sort",2)          /* begin sub 4 */
      put_y_value(5,0)
      put_nil(1)
      put_y_value(4,2)
      call(Pred_Name(X72657665727365,3),1,5,"reverse",3)          /* begin sub 5 */
      put_y_value(3,0)
      put_y_variable(2,1)
      call(Pred_Name(X736F7274,2),0,6,"sort",2)          /* begin sub 6 */
      put_y_value(2,0)
      put_nil(1)
      put_y_value(1,2)
      call(Pred_Name(X72657665727365,3),1,7,"reverse",3)          /* begin sub 7 */
      cut_y(0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalize_$aux34"
#define PRED       X6E6F726D616C697A655F246175783334
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      math_load_x_value(2,2)
      put_integer(0,3)
      builtin_2(gte,2,3)
      neck_cut
      get_x_value(2,0)
      get_integer(0,1)
      proceed

label(1)
      trust_me_else_fail
      get_integer(0,0)
      math_load_x_value(2,2)
      function_1(neg,0,2)
      get_x_value(1,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalize1"
#define PRED       X6E6F726D616C697A6531
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      allocate(9)
      get_y_variable(7,1)
      get_y_variable(3,2)
      get_y_variable(2,3)
      get_structure(X2C,2,4,",")
      unify_x_variable(4)
      unify_y_variable(6)
      builtin_1(nonvar,0)
      get_structure(X2B,2,0,"+")
      unify_x_variable(0)
      unify_y_variable(8)
      neck_cut
      put_y_value(7,1)
      put_y_variable(5,2)
      put_y_variable(1,3)
      call(Pred_Name(X6E6F726D616C697A6531,5),1,1,"normalize1",5)          /* begin sub 1 */
      put_y_value(8,0)
      put_y_value(7,1)
      put_y_variable(4,2)
      put_y_variable(0,3)
      put_y_value(6,4)
      call(Pred_Name(X6E6F726D616C697A6531,5),1,2,"normalize1",5)          /* begin sub 2 */
      put_y_value(5,0)
      put_y_value(4,1)
      put_y_value(3,2)
      call(Pred_Name(X617070656E645F776974685F616464,3),1,3,"append_with_add",3)          /* begin sub 3 */
      math_load_y_value(1,1)
      math_load_y_value(0,0)
      function_2(add,0,1,0)
      get_y_value(2,0)
      deallocate
      proceed

label(1)
      retry_me_else(2)
      allocate(9)
      get_y_variable(3,2)
      get_y_variable(2,3)
      get_structure(X2C,2,4,",")
      unify_x_variable(4)
      unify_y_variable(6)
      builtin_1(nonvar,0)
      get_structure(X2D,2,0,"-")
      unify_x_variable(0)
      unify_y_variable(8)
      neck_cut
      math_load_x_value(1,1)
      function_1(neg,2,1)
      get_y_variable(7,2)
      put_y_variable(5,2)
      put_y_variable(1,3)
      call(Pred_Name(X6E6F726D616C697A6531,5),1,4,"normalize1",5)          /* begin sub 4 */
      put_y_value(8,0)
      put_y_value(7,1)
      put_y_variable(4,2)
      put_y_variable(0,3)
      put_y_value(6,4)
      call(Pred_Name(X6E6F726D616C697A6531,5),1,5,"normalize1",5)          /* begin sub 5 */
      put_y_value(5,0)
      put_y_value(4,1)
      put_y_value(3,2)
      call(Pred_Name(X617070656E645F776974685F616464,3),1,6,"append_with_add",3)          /* begin sub 6 */
      math_load_y_value(1,1)
      math_load_y_value(0,0)
      function_2(add,0,1,0)
      get_y_value(2,0)
      deallocate
      proceed

label(2)
      retry_me_else(3)
      get_x_variable(5,0)
      get_x_variable(0,1)
      get_list(2)
      unify_x_variable(1)
      unify_nil
      get_structure(X2A,2,1,"*")
      unify_x_variable(1)
      unify_x_variable(2)
      get_integer(0,3)
      get_x_variable(3,4)
      builtin_1(nonvar,5)
      get_structure(X2A,2,5,"*")
      unify_x_variable(4)
      unify_x_variable(5)
      neck_cut
      execute(Pred_Name(X6E6F726D616C697A65315F246175783335,6),1,"normalize1_$aux35",6)

label(3)
      retry_me_else(4)
      get_nil(2)
      get_constant(X74727565,4,"true")
      builtin_1(integer,0)
      neck_cut
      math_load_x_value(1,1)
      math_load_x_value(0,0)
      function_2(mul,0,1,0)
      get_x_value(3,0)
      proceed

label(4)
      trust_me_else_fail
      get_list(2)
      unify_x_variable(2)
      unify_nil
      get_structure(X2A,2,2,"*")
      unify_x_local_value(1)
      unify_x_local_value(0)
      get_integer(0,3)
      get_constant(X74727565,4,"true")
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalize1_$aux35"
#define PRED       X6E6F726D616C697A65315F246175783335
#define ARITY      6

Begin_Private_Pred
      try_me_else(1)
      builtin_1(integer,4)
      neck_cut
      math_load_x_value(0,0)
      math_load_x_value(4,4)
      function_2(mul,0,0,4)
      get_x_value(1,0)
      get_x_value(5,2)
      get_constant(X74727565,3,"true")
      proceed

label(1)
      trust_me_else_fail
      get_x_value(0,1)
      get_structure(X7061632061783D79,3,3,"pac ax=y")
      unify_x_local_value(4)
      unify_x_local_value(5)
      unify_x_local_value(2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "append_with_add"
#define PRED       X617070656E645F776974685F616464
#define ARITY      3

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_x_value(1,2)
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(3)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(2)
      get_structure(X2A,2,0,"*")
      unify_x_variable(4)
      unify_x_variable(3)
      get_y_variable(0,2)
      put_x_value(1,0)
      put_x_value(4,1)
      put_x_value(3,2)
      put_y_variable(1,3)
      call(Pred_Name(X73756D5F696E5F6C697374,4),1,1,"sum_in_list",4)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_unsafe_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X617070656E645F776974685F616464,3),1,"append_with_add",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sum_in_list"
#define PRED       X73756D5F696E5F6C697374
#define ARITY      4

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(3),fail,G_label(1),fail)

label(1)
      try(5,1)          /* begin sub 1 */
      trust(7)

label(2)
      try_me_else(4)

label(3)
      get_nil(0)
      get_list(3)
      unify_x_variable(0)
      unify_nil
      get_structure(X2A,2,0,"*")
      unify_x_local_value(1)
      unify_x_local_value(2)
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_list(0)
      unify_x_variable(0)
      unify_x_variable(5)
      get_structure(X2A,2,0,"*")
      unify_x_variable(0)
      unify_x_variable(4)
      get_list(3)
      unify_x_variable(3)
      unify_x_value(5)
      get_structure(X2A,2,3,"*")
      unify_x_variable(3)
      unify_x_value(4)
      builtin_2(term_eq,4,2)
      math_load_x_value(0,0)
      math_load_x_value(1,1)
      function_2(add,0,0,1)
      get_x_value(3,0)
      proceed

label(6)
      trust_me_else_fail

label(7)
      get_list(0)
      unify_x_variable(4)
      unify_x_variable(0)
      get_list(3)
      unify_x_value(4)
      unify_x_variable(3)
      execute(Pred_Name(X73756D5F696E5F6C697374,4),1,"sum_in_list",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "split"
#define PRED       X73706C6974
#define ARITY      3

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(3),fail,G_label(1),fail)

label(1)
      try(5,1)          /* begin sub 1 */
      retry(7,2)          /* begin sub 2 */
      trust(9)

label(2)
      try_me_else(4)

label(3)
      get_nil(0)
      get_nil(1)
      get_nil(2)
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      get_structure(X2A,2,3,"*")
      unify_x_variable(4)
      unify_x_variable(3)
      get_list(1)
      unify_x_variable(5)
      unify_x_variable(1)
      get_structure(X2A,2,5,"*")
      unify_x_value(4)
      unify_x_value(3)
      math_load_x_value(4,4)
      put_integer(0,3)
      builtin_2(gt,4,3)
      execute(Pred_Name(X73706C6974,3),1,"split",3)

label(6)
      retry_me_else(8)

label(7)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      get_structure(X2A,2,3,"*")
      unify_x_variable(3)
      unify_x_variable(5)
      get_list(2)
      unify_x_variable(4)
      unify_x_variable(2)
      get_structure(X2A,2,4,"*")
      unify_x_variable(4)
      unify_x_value(5)
      math_load_x_value(3,3)
      put_integer(0,5)
      builtin_2(lt,3,5)
      math_load_x_value(3,3)
      function_1(neg,3,3)
      get_x_value(4,3)
      execute(Pred_Name(X73706C6974,3),1,"split",3)

label(8)
      trust_me_else_fail

label(9)
      get_list(0)
      unify_void(1)
      unify_x_variable(0)
      execute(Pred_Name(X73706C6974,3),1,"split",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "reverse"
#define PRED       X72657665727365
#define ARITY      3

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_x_value(1,2)
      proceed

label(3)
      trust_me_else_fail

label(4)
      get_list(0)
      unify_x_variable(4)
      unify_x_variable(0)
      get_x_variable(3,1)
      put_list(1)
      unify_x_value(4)
      unify_x_local_value(3)
      execute(Pred_Name(X72657665727365,3),1,"reverse",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(wamcc1)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X73756372655F73796E74617869717565,"sucre_syntaxique")
 Define_Atom(X73756372655F73796E746178697175655F2461757833,"sucre_syntaxique_$aux3")
 Define_Atom(X6E6F5F696E6C696E65,"no_inline")
 Define_Atom(X66,"f")
 Define_Atom(X73756372655F73796E746178697175655F2461757832,"sucre_syntaxique_$aux2")
 Define_Atom(X64796E,"dyn")
 Define_Atom(X6E625F636C617573655F64796E,"nb_clause_dyn")
 Define_Atom(X2464796E5F,"$dyn_")
 Define_Atom(X6173736572747A,"assertz")
 Define_Atom(X73756372655F73796E746178697175655F2461757831,"sucre_syntaxique_$aux1")
 Define_Atom(X3A2D,":-")
 Define_Atom(X6E6F726D616C6973655F63757473,"normalise_cuts")
 Define_Atom(X6E6F726D616C6973655F637574735F2461757834,"normalise_cuts_$aux4")
 Define_Atom(X74,"t")
 Define_Atom(X2C,",")
 Define_Atom(X246765745F62635F726567,"$get_bc_reg")
 Define_Atom(X6E6F726D616C6973655F6375747331,"normalise_cuts1")
 Define_Atom(X63616C6C,"call")
 Define_Atom(X3B,";")
 Define_Atom(X2D3E,"->")
 Define_Atom(X24637574,"$cut")
 Define_Atom(X6661696C,"fail")
 Define_Atom(X5C2B,"\\+")
 Define_Atom(X74727565,"true")
 Define_Atom(X21,"!")
 Define_Atom(X6E6F726D616C6973655F63757473315F2461757835,"normalise_cuts1_$aux5")
 Define_Atom(X6E6F726D616C6973655F616C7473,"normalise_alts")
 Define_Atom(X6465627567,"debug")
 Define_Atom(X6E6F726D616C6973655F616C74735F2461757836,"normalise_alts_$aux6")
 Define_Atom(X6E6F726D616C6973655F616C74735F2461757837,"normalise_alts_$aux7")
 Define_Atom(X646566,"def")
 Define_Atom(X246462675F74727565,"$dbg_true")
 Define_Atom(X6E6F726D616C6973655F616C747331,"normalise_alts1")
 Define_Atom(X617578,"aux")
 Define_Atom(X24617578,"$aux")
 Define_Atom(X5F,"_")
 Define_Atom(X6E6F726D616C6973655F616C7473315F2461757838,"normalise_alts1_$aux8")
 Define_Atom(X5F24617578,"_$aux")
 Define_Atom(X6C696E656172697365,"linearise")
 Define_Atom(X6C696E6561726973655F2461757839,"linearise_$aux9")
 Define_Atom(X6C696E65617269736531,"linearise1")
 Define_Atom(X6C696E656172697365315F246175783130,"linearise1_$aux10")
 Define_Atom(X6C73745F766172,"lst_var")
 Define_Atom(X6C73745F7661725F61726773,"lst_var_args")
 Define_Atom(X6C73745F7661725F617267735F246175783131,"lst_var_args_$aux11")
 Define_Atom(X6E6F726D616C6973655F666463,"normalise_fdc")
 Define_Atom(X6E6F726D616C6973655F6664635F246175783132,"normalise_fdc_$aux12")
 Define_Atom(X2466645F7365745F4146,"$fd_set_AF")
 Define_Atom(X6E6F726D616C6973655F66646331,"normalise_fdc1")
 Define_Atom(X696E,"in")
 Define_Atom(X6E6F5F666463,"no_fdc")
 Define_Atom(X6676,"fv")
 Define_Atom(X63737472,"cstr")
 Define_Atom(X233D,"#=")
 Define_Atom(X235C3D,"#\\=")
 Define_Atom(X233E3D,"#>=")
 Define_Atom(X233E,"#>")
 Define_Atom(X233C3D,"#<=")
 Define_Atom(X233C,"#<")
 Define_Atom(X6E6F726D616C6973655F666463315F246175783134,"normalise_fdc1_$aux14")
 Define_Atom(X2466645F63737472,"$fd_cstr")
 Define_Atom(X6E6F726D616C6973655F666463315F246175783133,"normalise_fdc1_$aux13")
 Define_Atom(X6E6F5F6F707432,"no_opt2")
 Define_Atom(X6E6F726D616C6973655F666463315F246175783135,"normalise_fdc1_$aux15")
 Define_Atom(X766572626F7365,"verbose")
 Define_Atom(X6E6F726D616C6973655F666463315F246175783136,"normalise_fdc1_$aux16")
 Define_Atom(X6E6F726D616C6973655F666463315F246175783137,"normalise_fdc1_$aux17")
 Define_Atom(X6E6F726D616C6973655F666463315F246175783138,"normalise_fdc1_$aux18")
 Define_Atom(X6E6F726D616C6973655F666463315F246175783139,"normalise_fdc1_$aux19")
 Define_Atom(X6E6F726D616C6973655F666463315F246175783230,"normalise_fdc1_$aux20")
 Define_Atom(X7472616974655F66645F617267,"traite_fd_arg")
 Define_Atom(X6670,"fp")
 Define_Atom(X7472616974655F66645F6172675F246175783231,"traite_fd_arg_$aux21")
 Define_Atom(X72,"r")
 Define_Atom(X7472616974655F66645F6172675F246175783232,"traite_fd_arg_$aux22")
 Define_Atom(X7472616974655F66645F6172675F246175783233,"traite_fd_arg_$aux23")
 Define_Atom(X7369676D61,"sigma")
 Define_Atom(X6D696E,"min")
 Define_Atom(X6D6178,"max")
 Define_Atom(X76616C,"val")
 Define_Atom(X6E6F5F66645F617267,"no_fd_arg")
 Define_Atom(X617267,"arg")
 Define_Atom(X637265655F66645F415F6672616D65,"cree_fd_A_frame")
 Define_Atom(X637265655F66645F415F6672616D655F246175783235,"cree_fd_A_frame_$aux25")
 Define_Atom(X637265655F66645F415F6672616D655F246175783234,"cree_fd_A_frame_$aux24")
 Define_Atom(X2466645F6670,"$fd_fp")
 Define_Atom(X2466645F6676,"$fd_fv")
 Define_Atom(X7472616E73665F6571,"transf_eq")
 Define_Atom(X7472616E73665F6E65,"transf_ne")
 Define_Atom(X70616320783C3E79,"pac x<>y")
 Define_Atom(X7472616E73665F6765,"transf_ge")
 Define_Atom(X70616320783E3D79,"pac x>=y")
 Define_Atom(X7472616E73665F67,"transf_g")
 Define_Atom(X70616320783E79,"pac x>y")
 Define_Atom(X65715F766172,"eq_var")
 Define_Atom(X2A,"*")
 Define_Atom(X65715F7661725F246175783236,"eq_var_$aux26")
 Define_Atom(X70616320782B633D79,"pac x+c=y")
 Define_Atom(X7061632061782B633D79,"pac ax+c=y")
 Define_Atom(X65715F7661725F246175783237,"eq_var_$aux27")
 Define_Atom(X7061632061783D79,"pac ax=y")
 Define_Atom(X65715F7661725F246175783238,"eq_var_$aux28")
 Define_Atom(X7061632061782B792B633D7A,"pac ax+y+c=z")
 Define_Atom(X7061632061782B62792B633D7A,"pac ax+by+c=z")
 Define_Atom(X65715F7661725F246175783239,"eq_var_$aux29")
 Define_Atom(X7061632061782B793D7A,"pac ax+y=z")
 Define_Atom(X7061632061782B62793D7A,"pac ax+by=z")
 Define_Atom(X65715F7661725F246175783330,"eq_var_$aux30")
 Define_Atom(X70616320782B793D7A,"pac x+y=z")
 Define_Atom(X65715F7661725F246175783331,"eq_var_$aux31")
 Define_Atom(X70616320782B792B633D7A,"pac x+y+c=z")
 Define_Atom(X65715F7661725F246175783332,"eq_var_$aux32")
 Define_Atom(X7061632061782B792B7A3D74,"pac ax+y+z=t")
 Define_Atom(X7061632061782B62792B7A3D74,"pac ax+by+z=t")
 Define_Atom(X65715F7661725F246175783333,"eq_var_$aux33")
 Define_Atom(X70616320782B792B7A3D74,"pac x+y+z=t")
 Define_Atom(X6E6F726D616C697A65,"normalize")
 Define_Atom(X2D,"-")
 Define_Atom(X6E6F726D616C697A655F246175783334,"normalize_$aux34")
 Define_Atom(X6E6F726D616C697A6531,"normalize1")
 Define_Atom(X2B,"+")
 Define_Atom(X6E6F726D616C697A65315F246175783335,"normalize1_$aux35")
 Define_Atom(X617070656E645F776974685F616464,"append_with_add")
 Define_Atom(X73756D5F696E5F6C697374,"sum_in_list")
 Define_Atom(X73706C6974,"split")
 Define_Atom(X72657665727365,"reverse")


 Define_Pred(X73756372655F73796E74617869717565,5,1)

 Define_Pred(X73756372655F73796E746178697175655F2461757833,3,0)

 Define_Pred(X73756372655F73796E746178697175655F2461757832,6,0)

 Define_Pred(X73756372655F73796E746178697175655F2461757831,2,0)

 Define_Pred(X6E6F726D616C6973655F63757473,2,0)

 Define_Pred(X6E6F726D616C6973655F637574735F2461757834,5,0)

 Define_Pred(X6E6F726D616C6973655F6375747331,4,0)
 Define_Switch_STC_Table(Swt_Table_Name(X6E6F726D616C6973655F6375747331,4,2,stc),4)
     Define_Switch_STC(X3B,2,Label_Pred_Name(X6E6F726D616C6973655F6375747331,4,3))
     Define_Switch_STC(X2D3E,2,Label_Pred_Name(X6E6F726D616C6973655F6375747331,4,7))
     Define_Switch_STC(X5C2B,1,Label_Pred_Name(X6E6F726D616C6973655F6375747331,4,9))
     Define_Switch_STC(X2C,2,Label_Pred_Name(X6E6F726D616C6973655F6375747331,4,11))

 Define_Pred(X6E6F726D616C6973655F63757473315F2461757835,4,0)

 Define_Pred(X6E6F726D616C6973655F616C7473,4,0)

 Define_Pred(X6E6F726D616C6973655F616C74735F2461757836,4,0)

 Define_Pred(X6E6F726D616C6973655F616C74735F2461757837,4,0)

 Define_Pred(X6E6F726D616C6973655F616C747331,7,0)
 Define_Switch_STC_Table(Swt_Table_Name(X6E6F726D616C6973655F616C747331,7,2,stc),2)
     Define_Switch_STC(X2C,2,Label_Pred_Name(X6E6F726D616C6973655F616C747331,7,4))
     Define_Switch_STC(X3B,2,Label_Pred_Name(X6E6F726D616C6973655F616C747331,7,6))

 Define_Pred(X6E6F726D616C6973655F616C7473315F2461757838,2,0)

 Define_Pred(X6C696E656172697365,4,0)

 Define_Pred(X6C696E6561726973655F2461757839,4,0)

 Define_Pred(X6C696E65617269736531,4,0)

 Define_Pred(X6C696E656172697365315F246175783130,4,0)

 Define_Pred(X6C73745F766172,3,0)

 Define_Pred(X6C73745F7661725F61726773,5,0)

 Define_Pred(X6C73745F7661725F617267735F246175783131,5,0)

 Define_Pred(X6E6F726D616C6973655F666463,3,0)

 Define_Pred(X6E6F726D616C6973655F6664635F246175783132,3,0)

 Define_Pred(X6E6F726D616C6973655F66646331,7,0)
 Define_Switch_STC_Table(Swt_Table_Name(X6E6F726D616C6973655F66646331,7,1,stc),8)
     Define_Switch_STC(X2C,2,Label_Pred_Name(X6E6F726D616C6973655F66646331,7,3))
     Define_Switch_STC(X696E,2,Label_Pred_Name(X6E6F726D616C6973655F66646331,7,5))
     Define_Switch_STC(X233D,2,Label_Pred_Name(X6E6F726D616C6973655F66646331,7,7))
     Define_Switch_STC(X235C3D,2,Label_Pred_Name(X6E6F726D616C6973655F66646331,7,9))
     Define_Switch_STC(X233E3D,2,Label_Pred_Name(X6E6F726D616C6973655F66646331,7,11))
     Define_Switch_STC(X233E,2,Label_Pred_Name(X6E6F726D616C6973655F66646331,7,13))
     Define_Switch_STC(X233C3D,2,Label_Pred_Name(X6E6F726D616C6973655F66646331,7,15))
     Define_Switch_STC(X233C,2,Label_Pred_Name(X6E6F726D616C6973655F66646331,7,17))

 Define_Pred(X6E6F726D616C6973655F666463315F246175783134,5,0)

 Define_Pred(X6E6F726D616C6973655F666463315F246175783133,3,0)

 Define_Pred(X6E6F726D616C6973655F666463315F246175783135,1,0)

 Define_Pred(X6E6F726D616C6973655F666463315F246175783136,1,0)

 Define_Pred(X6E6F726D616C6973655F666463315F246175783137,1,0)

 Define_Pred(X6E6F726D616C6973655F666463315F246175783138,1,0)

 Define_Pred(X6E6F726D616C6973655F666463315F246175783139,1,0)

 Define_Pred(X6E6F726D616C6973655F666463315F246175783230,1,0)

 Define_Pred(X7472616974655F66645F617267,4,0)

 Define_Pred(X7472616974655F66645F6172675F246175783231,5,0)

 Define_Pred(X7472616974655F66645F6172675F246175783232,5,0)

 Define_Pred(X7472616974655F66645F6172675F246175783233,1,0)

 Define_Pred(X6E6F5F66645F617267,6,0)

 Define_Pred(X637265655F66645F415F6672616D65,3,0)

 Define_Pred(X637265655F66645F415F6672616D655F246175783235,4,0)

 Define_Pred(X637265655F66645F415F6672616D655F246175783234,3,0)

 Define_Pred(X7472616E73665F6571,3,0)

 Define_Pred(X7472616E73665F6E65,3,0)

 Define_Pred(X7472616E73665F6765,3,0)

 Define_Pred(X7472616E73665F67,3,0)

 Define_Pred(X65715F766172,4,0)

 Define_Pred(X65715F7661725F246175783236,5,0)

 Define_Pred(X65715F7661725F246175783237,4,0)

 Define_Pred(X65715F7661725F246175783238,7,0)

 Define_Pred(X65715F7661725F246175783239,6,0)

 Define_Pred(X65715F7661725F246175783330,5,0)

 Define_Pred(X65715F7661725F246175783331,6,0)

 Define_Pred(X65715F7661725F246175783332,7,0)

 Define_Pred(X65715F7661725F246175783333,6,0)

 Define_Pred(X6E6F726D616C697A65,7,0)

 Define_Pred(X6E6F726D616C697A655F246175783334,3,0)

 Define_Pred(X6E6F726D616C697A6531,5,0)

 Define_Pred(X6E6F726D616C697A65315F246175783335,6,0)

 Define_Pred(X617070656E645F776974685F616464,3,0)

 Define_Pred(X73756D5F696E5F6C697374,4,0)

 Define_Pred(X73706C6974,3,0)

 Define_Pred(X72657665727365,3,0)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(wamcc1)



End_Exec_Directives
