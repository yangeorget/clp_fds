/****************************************************************************
Prolog to Wam Compiler - Version 2.0
Daniel Diaz, Yan Georget
1998 - INRIA Rocquencourt - LOCO Project
File : sfd_domain.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"
#include "sfd_engine.h"

#include "sfd_domain.h"
#include "sfd_domain.usr"


#define ASCII_PRED "fd_unify"
#define PRED       X66645F756E696679
#define ARITY      2

Begin_Public_Pred
      fd_set_x_AF(2,2)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_install_constraint_with_x_AF(1,2)
      fd_call_constraint
      fd_install_constraint_with_x_AF(2,2)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(1)

      fd_create_C_frame(1)
      fd_install_ind_def(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(1)

      fd_allocate
      fd_ind_def(1,1)
      fd_tell_range(0,1)
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


Begin_Fd_Install(2)

      fd_create_C_frame(2)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(2)

      fd_allocate
      fd_ind_def(0,0)
      fd_tell_range(1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(2)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(2)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(2)

      fd_reduce_vars(1)

End_Fd_Reduction



#define ASCII_PRED "fd_var"
#define PRED       X66645F766172
#define ARITY      1

Begin_Public_Pred
      pragma_c(Fd_Var_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "fd_vector_max"
#define PRED       X66645F766563746F725F6D6178
#define ARITY      1

Begin_Public_Pred
      pragma_c(Fd_Vector_Max_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "fd_infinity"
#define PRED       X66645F696E66696E697479
#define ARITY      1

Begin_Public_Pred
      pragma_c(get_integer(infinity,0))
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sfd_value_index"
#define PRED       X7366645F76616C75655F696E646578
#define ARITY      3

Begin_Public_Pred
      pragma_c(Sfd_Value_Index_3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sfd_value"
#define PRED       X7366645F76616C7565
#define ARITY      2

Begin_Public_Pred
      put_x_variable(2,2)
      execute(Pred_Name(X7366645F76616C75655F696E646578,3),1,"sfd_value_index",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sfd_index"
#define PRED       X7366645F696E646578
#define ARITY      2

Begin_Public_Pred
      get_x_variable(2,1)
      put_x_variable(1,1)
      execute(Pred_Name(X7366645F76616C75655F696E646578,3),1,"sfd_value_index",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sfd_is_instantiated"
#define PRED       X7366645F69735F696E7374616E746961746564
#define ARITY      1

Begin_Public_Pred
      pragma_c(Sfd_Is_Instantiated_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sfd_min"
#define PRED       X7366645F6D696E
#define ARITY      2

Begin_Public_Pred
      pragma_c(Sfd_Min_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sfd_max"
#define PRED       X7366645F6D6178
#define ARITY      2

Begin_Public_Pred
      pragma_c(Sfd_Max_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sfd_size"
#define PRED       X7366645F73697A65
#define ARITY      2

Begin_Public_Pred
      pragma_c(Sfd_Size_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sfd_2int"
#define PRED       X7366645F32696E74
#define ARITY      2

Begin_Public_Pred
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
      allocate(2)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(1)
      get_list(1)
      unify_x_variable(1)
      unify_y_variable(0)
      call(Pred_Name(X7366645F32696E745F617578,2),1,1,"sfd_2int_aux",2)          /* begin sub 1 */
      put_y_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X7366645F32696E74,2),1,"sfd_2int",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sfd_2int_aux"
#define PRED       X7366645F32696E745F617578
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      allocate(3)
      get_y_variable(1,0)
      get_y_variable(0,1)
      get_y_bc_reg(2)
      put_y_value(1,0)
      call(Pred_Name(X7366645F69735F696E7374616E746961746564,1),1,1,"sfd_is_instantiated",1)          /* begin sub 1 */
      cut_y(2)
      put_y_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X7366645F696E646578,2),1,"sfd_index",2)

label(1)
      trust_me_else_fail
      builtin_1(integer,1)
      fd_set_x_AF(2,2)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(1)
      fd_install_constraint_with_x_AF(3,2)
      fd_call_constraint
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

      fd_term_parameter(1,1)
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



#define ASCII_PRED "interval_domain"
#define PRED       X696E74657276616C5F646F6D61696E
#define ARITY      3

Begin_Public_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      proceed

label(3)
      trust_me_else_fail

label(4)
      get_list(0)
      unify_x_variable(4)
      unify_x_variable(0)
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(4)
      fd_x_term_parameter_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(4,3)
      fd_call_constraint
      execute(Pred_Name(X696E74657276616C5F646F6D61696E,3),1,"interval_domain",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(4)

      fd_create_C_frame(4)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(4)

      fd_term_parameter(2,1)
      fd_term_parameter(1,2)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(4)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(4)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(4)

      fd_reduce_vars(0)

End_Fd_Reduction



#define ASCII_PRED "interval_domain"
#define PRED       X696E74657276616C5F646F6D61696E
#define ARITY      4

Begin_Public_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      proceed

label(3)
      trust_me_else_fail

label(4)
      get_list(0)
      unify_x_variable(5)
      unify_x_variable(0)
      fd_set_x_AF(4,4)
      fd_x_value_in_A_frame(5)
      fd_x_term_parameter_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(3)
      fd_install_constraint_with_x_AF(5,4)
      fd_call_constraint
      execute(Pred_Name(X696E74657276616C5F646F6D61696E,4),1,"interval_domain",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(5)

      fd_create_C_frame(5)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(5)

      fd_term_parameter(3,1)
      fd_term_parameter(2,2)
      fd_term_parameter(1,3)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(5)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(5)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(5)

      fd_reduce_vars(0)

End_Fd_Reduction



#define ASCII_PRED "sparse_domain"
#define PRED       X7370617273655F646F6D61696E
#define ARITY      5

Begin_Public_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      proceed

label(3)
      trust_me_else_fail

label(4)
      get_list(0)
      unify_x_variable(6)
      unify_x_variable(0)
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(6)
      fd_x_term_parameter_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(4)
      fd_x_term_parameter_in_A_frame(3)
      fd_install_constraint_with_x_AF(6,5)
      fd_call_constraint
      execute(Pred_Name(X7370617273655F646F6D61696E,5),1,"sparse_domain",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(6)

      fd_create_C_frame(6)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(6)

      fd_allocate
      fd_term_parameter(2,1)
      fd_term_parameter(1,2)
      fd_interval_range(1,2,1)
      fd_term_parameter(2,3)
      fd_range_addA_term(1,2)
      fd_term_parameter(2,4)
      fd_range_mulA_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(6)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(6)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(6)

      fd_reduce_vars(0)

End_Fd_Reduction



#define ASCII_PRED "sparse_domain"
#define PRED       X7370617273655F646F6D61696E
#define ARITY      4

Begin_Public_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      proceed

label(3)
      trust_me_else_fail

label(4)
      get_list(0)
      unify_x_variable(5)
      unify_x_variable(0)
      fd_set_x_AF(4,4)
      fd_x_value_in_A_frame(5)
      fd_x_range_parameter_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(7,4)
      fd_call_constraint
      execute(Pred_Name(X7370617273655F646F6D61696E,4),1,"sparse_domain",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(7)

      fd_create_C_frame(7)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(7)

      fd_allocate
      fd_range_parameter(1,1)
      fd_term_parameter(2,2)
      fd_range_addA_term(1,2)
      fd_term_parameter(2,3)
      fd_range_mulA_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(7)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(7)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(7)

      fd_reduce_vars(0)

End_Fd_Reduction



#define ASCII_PRED "sparse_domain"
#define PRED       X7370617273655F646F6D61696E
#define ARITY      3

Begin_Public_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(3)
      get_list(0)
      unify_x_variable(3)
      unify_y_variable(2)
      get_y_variable(1,1)
      get_y_variable(0,2)
      fd_set_x_AF(2,0)
      fd_x_value_in_A_frame(3)
      fd_y_range_parameter_in_A_frame(1)
      fd_install_constraint_with_x_AF(8,0)
      fd_call_constraint
      put_y_value(1,0)
      put_y_value(0,1)
      put_x_value(3,2)
      call(Pred_Name(X7365745F646F6D61696E,3),1,1,"set_domain",3)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X7370617273655F646F6D61696E,3),1,"sparse_domain",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(8)

      fd_create_C_frame(8)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(8)

      fd_allocate
      fd_range_parameter(1,1)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(8)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(8)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(8)

      fd_reduce_vars(0)

End_Fd_Reduction



#define ASCII_PRED "set_domain"
#define PRED       X7365745F646F6D61696E
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
      get_list(0)
      unify_x_variable(5)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(4)
      unify_x_variable(1)
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(5)
      fd_x_term_parameter_in_A_frame(4)
      fd_install_constraint_with_x_AF(9,3)
      fd_call_constraint
      execute(Pred_Name(X7365745F646F6D61696E,3),1,"set_domain",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(9)

      fd_create_C_frame(9)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(9)

      fd_allocate
      fd_term_parameter(1,1)
      fd_comp_term(1,1)
      fd_term_parameter(2,2)
      fd_range_addA_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(9)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(9)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(9)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Init_Tables(sfd_domain)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X66645F756E696679,"fd_unify")
 Define_Atom(X66645F766172,"fd_var")
 Define_Atom(X66645F766563746F725F6D6178,"fd_vector_max")
 Define_Atom(X66645F696E66696E697479,"fd_infinity")
 Define_Atom(X7366645F76616C75655F696E646578,"sfd_value_index")
 Define_Atom(X7366645F76616C7565,"sfd_value")
 Define_Atom(X7366645F696E646578,"sfd_index")
 Define_Atom(X7366645F69735F696E7374616E746961746564,"sfd_is_instantiated")
 Define_Atom(X7366645F6D696E,"sfd_min")
 Define_Atom(X7366645F6D6178,"sfd_max")
 Define_Atom(X7366645F73697A65,"sfd_size")
 Define_Atom(X7366645F32696E74,"sfd_2int")
 Define_Atom(X7366645F32696E745F617578,"sfd_2int_aux")
 Define_Atom(X696E74657276616C5F646F6D61696E,"interval_domain")
 Define_Atom(X7370617273655F646F6D61696E,"sparse_domain")
 Define_Atom(X7365745F646F6D61696E,"set_domain")


 Define_Pred(X66645F756E696679,2,1)

 Define_Pred(X66645F766172,1,1)

 Define_Pred(X66645F766563746F725F6D6178,1,1)

 Define_Pred(X66645F696E66696E697479,1,1)

 Define_Pred(X7366645F76616C75655F696E646578,3,1)

 Define_Pred(X7366645F76616C7565,2,1)

 Define_Pred(X7366645F696E646578,2,1)

 Define_Pred(X7366645F69735F696E7374616E746961746564,1,1)

 Define_Pred(X7366645F6D696E,2,1)

 Define_Pred(X7366645F6D6178,2,1)

 Define_Pred(X7366645F73697A65,2,1)

 Define_Pred(X7366645F32696E74,2,1)

 Define_Pred(X7366645F32696E745F617578,2,0)

 Define_Pred(X696E74657276616C5F646F6D61696E,3,1)

 Define_Pred(X696E74657276616C5F646F6D61696E,4,1)

 Define_Pred(X7370617273655F646F6D61696E,5,1)

 Define_Pred(X7370617273655F646F6D61696E,4,1)

 Define_Pred(X7370617273655F646F6D61696E,3,1)

 Define_Pred(X7365745F646F6D61696E,3,0)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(sfd_domain)



End_Exec_Directives
