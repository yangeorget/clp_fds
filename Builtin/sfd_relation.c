/****************************************************************************
Prolog to Wam Compiler - Version 2.0
Daniel Diaz, Yan Georget
1998 - INRIA Rocquencourt - LOCO Project
File : sfd_relation.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"
#include "sfd_engine.h"

#include "sfd_relation.h"
#include "sfd_relation.usr"


#define ASCII_PRED "element"
#define PRED       X656C656D656E74
#define ARITY      3

Begin_Public_Pred
      allocate(6)
      get_y_variable(3,0)
      get_y_variable(2,1)
      get_y_variable(0,2)
      put_y_value(2,0)
      put_y_variable(5,1)
      call(Pred_Name(X6C656E677468,2),0,1,"length",2)          /* begin sub 1 */
      put_y_variable(1,0)
      put_y_value(5,1)
      call(Pred_Name(X6C656E677468,2),0,2,"length",2)          /* begin sub 2 */
      put_y_variable(4,0)
      call(Pred_Name(X73656D6972696E675F756E697479,1),0,3,"semiring_unity",1)          /* begin sub 3 */
      put_y_value(1,0)
      put_y_value(4,1)
      call(Pred_Name(X6C6973745F6F66,2),0,4,"list_of",2)          /* begin sub 4 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_unsafe_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X656C656D656E74,4),1,"element",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "element"
#define PRED       X656C656D656E74
#define ARITY      4

Begin_Public_Pred
      allocate(5)
      get_y_variable(4,0)
      get_y_variable(1,1)
      get_y_variable(0,2)
      get_y_variable(3,3)
      put_y_value(1,0)
      put_y_variable(2,1)
      call(Pred_Name(X6C656E677468,2),0,1,"length",2)          /* begin sub 1 */
      put_y_value(0,0)
      put_y_value(2,1)
      call(Pred_Name(X6C656E677468,2),0,2,"length",2)          /* begin sub 2 */
      fd_set_x_AF(2,0)
      fd_y_value_in_A_frame(4)
      fd_y_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(1,0)
      fd_call_constraint
      put_y_value(4,0)
      put_y_value(3,1)
      put_y_unsafe_value(2,2)
      put_y_value(1,3)
      put_y_value(0,4)
      deallocate
      execute(Pred_Name(X656C656D656E7431,5),1,"element1",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(1)

      fd_create_C_frame(1)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(1)

      fd_integer(2,1)
      fd_term_parameter(1,1)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(1)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(1)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(1)

      fd_reduce_vars(0)

End_Fd_Reduction



#define ASCII_PRED "element1"
#define PRED       X656C656D656E7431
#define ARITY      5

Begin_Private_Pred
      pragma_c(Element1_5)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "relation"
#define PRED       X72656C6174696F6E
#define ARITY      2

Begin_Public_Pred
      allocate(4)
      get_y_variable(1,1)
      put_y_variable(3,1)
      put_y_variable(0,2)
      call(Pred_Name(X73706C6974,3),1,1,"split",3)          /* begin sub 1 */
      put_y_value(3,0)
      put_y_variable(2,1)
      call(Pred_Name(X6C696E65735F746F5F636F6C756D6E73,2),0,2,"lines_to_columns",2)          /* begin sub 2 */
      put_y_unsafe_value(2,0)
      put_y_value(1,1)
      put_y_unsafe_value(0,2)
      put_x_variable(3,3)
      deallocate
      execute(Pred_Name(X72656C6174696F6E6331,4),1,"relationc1",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "relationc1"
#define PRED       X72656C6174696F6E6331
#define ARITY      4

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_nil(1)
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(4)
      get_list(0)
      unify_x_variable(5)
      unify_y_variable(3)
      get_list(1)
      unify_x_variable(4)
      unify_y_variable(2)
      get_y_variable(1,2)
      get_y_variable(0,3)
      put_y_value(0,0)
      put_x_value(5,1)
      put_y_value(1,2)
      put_x_value(4,3)
      call(Pred_Name(X656C656D656E74,4),1,1,"element",4)          /* begin sub 1 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X72656C6174696F6E6331,4),1,"relationc1",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "split"
#define PRED       X73706C6974
#define ARITY      3

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_nil(1)
      get_nil(2)
      proceed

label(3)
      trust_me_else_fail

label(4)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      get_structure(X2C,2,3,",")
      unify_x_variable(4)
      unify_x_variable(3)
      get_list(1)
      unify_x_value(4)
      unify_x_variable(1)
      get_list(2)
      unify_x_value(3)
      unify_x_variable(2)
      execute(Pred_Name(X73706C6974,3),1,"split",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "v_element"
#define PRED       X765F656C656D656E74
#define ARITY      3

Begin_Public_Pred
      allocate(4)
      get_y_variable(3,0)
      get_y_variable(0,1)
      get_y_variable(2,2)
      put_y_value(0,0)
      put_y_variable(1,1)
      call(Pred_Name(X6C656E677468,2),0,1,"length",2)          /* begin sub 1 */
      fd_set_x_AF(2,0)
      fd_y_value_in_A_frame(3)
      fd_y_term_parameter_in_A_frame(1)
      fd_install_constraint_with_x_AF(2,0)
      fd_call_constraint
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_unsafe_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X765F656C656D656E7431,4),1,"v_element1",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(2)

      fd_create_C_frame(2)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(2)

      fd_integer(2,1)
      fd_term_parameter(1,1)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(2)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(2)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(2)

      fd_reduce_vars(0)

End_Fd_Reduction



#define ASCII_PRED "v_element1"
#define PRED       X765F656C656D656E7431
#define ARITY      4

Begin_Private_Pred
      pragma_c(V_Element1_4)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "v_relation"
#define PRED       X765F72656C6174696F6E
#define ARITY      2

Begin_Public_Pred
      allocate(2)
      get_y_variable(0,1)
      put_y_variable(1,1)
      call(Pred_Name(X6C696E65735F746F5F636F6C756D6E73,2),0,1,"lines_to_columns",2)          /* begin sub 1 */
      put_y_unsafe_value(1,0)
      put_y_value(0,1)
      put_x_variable(2,2)
      deallocate
      execute(Pred_Name(X765F72656C6174696F6E6331,3),1,"v_relationc1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "v_relationc1"
#define PRED       X765F72656C6174696F6E6331
#define ARITY      3

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_nil(1)
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(3)
      get_list(0)
      unify_x_variable(4)
      unify_y_variable(2)
      get_list(1)
      unify_x_variable(3)
      unify_y_variable(1)
      get_y_variable(0,2)
      put_y_value(0,0)
      put_x_value(4,1)
      put_x_value(3,2)
      call(Pred_Name(X765F656C656D656E74,3),1,1,"v_element",3)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X765F72656C6174696F6E6331,3),1,"v_relationc1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "nogood"
#define PRED       X6E6F676F6F64
#define ARITY      2

Begin_Public_Pred
      allocate(2)
      get_x_variable(2,0)
      put_y_variable(1,0)
      call(Pred_Name(X65717569765F65715F63737473,3),0,1,"equiv_eq_csts",3)          /* begin sub 1 */
      put_y_value(1,0)
      put_y_variable(0,1)
      call(Pred_Name(X616E64,2),0,2,"and",2)          /* begin sub 2 */
      fd_set_x_AF(1,0)
      fd_y_value_in_A_frame(0)
      fd_install_constraint_with_x_AF(3,0)
      fd_call_constraint
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(3)

      fd_create_C_frame(3)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(3)

      fd_integer(1,0)
      fd_tell_integer(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(3)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(3)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(3)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Init_Tables(sfd_relation)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X656C656D656E74,"element")
 Define_Atom(X656C656D656E7431,"element1")
 Define_Atom(X72656C6174696F6E,"relation")
 Define_Atom(X72656C6174696F6E6331,"relationc1")
 Define_Atom(X73706C6974,"split")
 Define_Atom(X2C,",")
 Define_Atom(X765F656C656D656E74,"v_element")
 Define_Atom(X765F656C656D656E7431,"v_element1")
 Define_Atom(X765F72656C6174696F6E,"v_relation")
 Define_Atom(X765F72656C6174696F6E6331,"v_relationc1")
 Define_Atom(X6E6F676F6F64,"nogood")


 Define_Pred(X656C656D656E74,3,1)

 Define_Pred(X656C656D656E74,4,1)

 Define_Pred(X656C656D656E7431,5,0)

 Define_Pred(X72656C6174696F6E,2,1)

 Define_Pred(X72656C6174696F6E6331,4,0)

 Define_Pred(X73706C6974,3,0)

 Define_Pred(X765F656C656D656E74,3,1)

 Define_Pred(X765F656C656D656E7431,4,0)

 Define_Pred(X765F72656C6174696F6E,2,1)

 Define_Pred(X765F72656C6174696F6E6331,3,0)

 Define_Pred(X6E6F676F6F64,2,1)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(sfd_relation)



End_Exec_Directives
