/****************************************************************************
Prolog to Wam Compiler - Version 2.0
Daniel Diaz, Yan Georget
1998 - INRIA Rocquencourt - LOCO Project
File : sfd_optimization.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"
#include "sfd_engine.h"

#include "sfd_optimization.h"
#include "sfd_optimization.usr"


#define ASCII_PRED "cut"
#define PRED       X637574
#define ARITY      3

Begin_Public_Pred
      try_me_else(1)
      get_nil(1)
      proceed

label(1)
      trust_me_else_fail
      switch_on_term(G_label(3),G_label(2),fail,fail,fail)

label(2)
      switch_on_constant(2,"[(le,4),(l,6),(ge,8),(g,10),(d,12),(np,14),(nnp,16)]")

label(3)
      try_me_else(5)

label(4)
      get_constant(X6C65,0,"le")
      get_list(1)
      unify_x_variable(3)
      unify_x_variable(1)
      fd_set_x_AF(2,0)
      fd_x_value_in_A_frame(3)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(1,0)
      fd_call_constraint
      put_constant(X6C65,0,"le")
      execute(Pred_Name(X637574,3),1,"cut",3)

label(5)
      retry_me_else(7)

label(6)
      get_constant(X6C,0,"l")
      get_list(1)
      unify_x_variable(3)
      unify_x_variable(1)
      fd_set_x_AF(2,0)
      fd_x_value_in_A_frame(3)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(2,0)
      fd_call_constraint
      put_constant(X6C,0,"l")
      execute(Pred_Name(X637574,3),1,"cut",3)

label(7)
      retry_me_else(9)

label(8)
      get_constant(X6765,0,"ge")
      get_list(1)
      unify_x_variable(3)
      unify_x_variable(1)
      fd_set_x_AF(2,0)
      fd_x_value_in_A_frame(3)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(3,0)
      fd_call_constraint
      put_constant(X6765,0,"ge")
      execute(Pred_Name(X637574,3),1,"cut",3)

label(9)
      retry_me_else(11)

label(10)
      get_constant(X67,0,"g")
      get_list(1)
      unify_x_variable(3)
      unify_x_variable(1)
      fd_set_x_AF(2,0)
      fd_x_value_in_A_frame(3)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(4,0)
      fd_call_constraint
      put_constant(X67,0,"g")
      execute(Pred_Name(X637574,3),1,"cut",3)

label(11)
      retry_me_else(13)

label(12)
      get_constant(X64,0,"d")
      get_list(1)
      unify_x_variable(3)
      unify_x_variable(1)
      fd_set_x_AF(2,0)
      fd_x_value_in_A_frame(3)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(5,0)
      fd_call_constraint
      put_constant(X64,0,"d")
      execute(Pred_Name(X637574,3),1,"cut",3)

label(13)
      retry_me_else(15)

label(14)
      get_constant(X6E70,0,"np")
      get_list(1)
      unify_x_variable(3)
      unify_x_variable(1)
      fd_set_x_AF(2,0)
      fd_x_value_in_A_frame(3)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(6,0)
      fd_call_constraint
      put_constant(X6E70,0,"np")
      execute(Pred_Name(X637574,3),1,"cut",3)

label(15)
      trust_me_else_fail

label(16)
      get_constant(X6E6E70,0,"nnp")
      get_list(1)
      unify_x_variable(3)
      unify_x_variable(1)
      fd_set_x_AF(2,0)
      fd_x_value_in_A_frame(3)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(7,0)
      fd_call_constraint
      put_constant(X6E6E70,0,"nnp")
      execute(Pred_Name(X637574,3),1,"cut",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(1)

      fd_create_C_frame(1)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(1)

      fd_allocate
      fd_ind_def(1,0)
      fd_term_parameter(2,1)
      fd_cut_le_range_term(1,2)
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
      fd_ind_def(1,0)
      fd_term_parameter(2,1)
      fd_cut_l_range_term(1,2)
      fd_tell_range(0,1)
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


Begin_Fd_Install(3)

      fd_create_C_frame(3)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(3)

      fd_allocate
      fd_ind_def(1,0)
      fd_term_parameter(2,1)
      fd_cut_ge_range_term(1,2)
      fd_tell_range(0,1)
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


Begin_Fd_Install(4)

      fd_create_C_frame(4)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(4)

      fd_allocate
      fd_ind_def(1,0)
      fd_term_parameter(2,1)
      fd_cut_g_range_term(1,2)
      fd_tell_range(0,1)
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


Begin_Fd_Install(5)

      fd_create_C_frame(5)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(5)

      fd_allocate
      fd_ind_def(1,0)
      fd_term_parameter(2,1)
      fd_cut_d_range_term(1,2)
      fd_tell_range(0,1)
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


Begin_Fd_Install(6)

      fd_create_C_frame(6)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(6)

      fd_allocate
      fd_ind_def(1,0)
      fd_term_parameter(2,1)
      fd_cut_np_range_term(1,2)
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


Begin_Fd_Install(7)

      fd_create_C_frame(7)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(7)

      fd_allocate
      fd_ind_def(1,0)
      fd_term_parameter(2,1)
      fd_cut_nnp_range_term(1,2)
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



#define ASCII_PRED "keep"
#define PRED       X6B656570
#define ARITY      3

Begin_Public_Pred
      try_me_else(1)
      get_nil(1)
      proceed

label(1)
      trust_me_else_fail
      switch_on_term(G_label(3),G_label(2),fail,fail,fail)

label(2)
      switch_on_constant(2,"[(le,4),(l,6),(ge,8),(g,10),(d,12),(np,14),(nnp,16)]")

label(3)
      try_me_else(5)

label(4)
      get_constant(X6C65,0,"le")
      get_list(1)
      unify_x_variable(3)
      unify_x_variable(1)
      fd_set_x_AF(2,0)
      fd_x_value_in_A_frame(3)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(8,0)
      fd_call_constraint
      put_constant(X6C65,0,"le")
      execute(Pred_Name(X6B656570,3),1,"keep",3)

label(5)
      retry_me_else(7)

label(6)
      get_constant(X6C,0,"l")
      get_list(1)
      unify_x_variable(3)
      unify_x_variable(1)
      fd_set_x_AF(2,0)
      fd_x_value_in_A_frame(3)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(9,0)
      fd_call_constraint
      put_constant(X6C,0,"l")
      execute(Pred_Name(X6B656570,3),1,"keep",3)

label(7)
      retry_me_else(9)

label(8)
      get_constant(X6765,0,"ge")
      get_list(1)
      unify_x_variable(3)
      unify_x_variable(1)
      fd_set_x_AF(2,0)
      fd_x_value_in_A_frame(3)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(10,0)
      fd_call_constraint
      put_constant(X6765,0,"ge")
      execute(Pred_Name(X6B656570,3),1,"keep",3)

label(9)
      retry_me_else(11)

label(10)
      get_constant(X67,0,"g")
      get_list(1)
      unify_x_variable(3)
      unify_x_variable(1)
      fd_set_x_AF(2,0)
      fd_x_value_in_A_frame(3)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(11,0)
      fd_call_constraint
      put_constant(X67,0,"g")
      execute(Pred_Name(X6B656570,3),1,"keep",3)

label(11)
      retry_me_else(13)

label(12)
      get_constant(X64,0,"d")
      get_list(1)
      unify_x_variable(3)
      unify_x_variable(1)
      fd_set_x_AF(2,0)
      fd_x_value_in_A_frame(3)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(12,0)
      fd_call_constraint
      put_constant(X64,0,"d")
      execute(Pred_Name(X6B656570,3),1,"keep",3)

label(13)
      retry_me_else(15)

label(14)
      get_constant(X6E70,0,"np")
      get_list(1)
      unify_x_variable(3)
      unify_x_variable(1)
      fd_set_x_AF(2,0)
      fd_x_value_in_A_frame(3)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(13,0)
      fd_call_constraint
      put_constant(X6E70,0,"np")
      execute(Pred_Name(X6B656570,3),1,"keep",3)

label(15)
      trust_me_else_fail

label(16)
      get_constant(X6E6E70,0,"nnp")
      get_list(1)
      unify_x_variable(3)
      unify_x_variable(1)
      fd_set_x_AF(2,0)
      fd_x_value_in_A_frame(3)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(14,0)
      fd_call_constraint
      put_constant(X6E6E70,0,"nnp")
      execute(Pred_Name(X6B656570,3),1,"keep",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(8)

      fd_create_C_frame(8)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(8)

      fd_allocate
      fd_ind_def(1,0)
      fd_term_parameter(2,1)
      fd_keep_le_range_term(1,2)
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


Begin_Fd_Install(9)

      fd_create_C_frame(9)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(9)

      fd_allocate
      fd_ind_def(1,0)
      fd_term_parameter(2,1)
      fd_keep_l_range_term(1,2)
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


Begin_Fd_Install(10)

      fd_create_C_frame(10)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(10)

      fd_allocate
      fd_ind_def(1,0)
      fd_term_parameter(2,1)
      fd_keep_ge_range_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(10)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(10)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(10)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(11)

      fd_create_C_frame(11)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(11)

      fd_allocate
      fd_ind_def(1,0)
      fd_term_parameter(2,1)
      fd_keep_g_range_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(11)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(11)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(11)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(12)

      fd_create_C_frame(12)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(12)

      fd_allocate
      fd_ind_def(1,0)
      fd_term_parameter(2,1)
      fd_keep_d_range_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(12)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(12)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(12)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(13)

      fd_create_C_frame(13)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(13)

      fd_allocate
      fd_ind_def(1,0)
      fd_term_parameter(2,1)
      fd_keep_np_range_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(13)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(13)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(13)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(14)

      fd_create_C_frame(14)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(14)

      fd_allocate
      fd_ind_def(1,0)
      fd_term_parameter(2,1)
      fd_keep_nnp_range_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(14)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(14)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(14)

      fd_reduce_vars(0)

End_Fd_Reduction



#define ASCII_PRED "max_sol"
#define PRED       X6D61785F736F6C
#define ARITY      1

Begin_Public_Pred
      put_structure(X6C6162656C696E67,1,1,"labeling")
      unify_x_local_value(0)
      put_structure(X6C6162656C696E67,1,2,"labeling")
      unify_x_local_value(0)
      execute(Pred_Name(X6D61785F736F6C,3),1,"max_sol",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "max_sol"
#define PRED       X6D61785F736F6C
#define ARITY      3

Begin_Public_Pred
      allocate(4)
      get_y_variable(3,0)
      get_y_variable(2,1)
      get_y_variable(1,2)
      put_y_variable(0,0)
      call(Pred_Name(X73656D6972696E675F6E756C6C,1),0,1,"semiring_null",1)          /* begin sub 1 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_unsafe_value(0,3)
      deallocate
      execute(Pred_Name(X6D61785F736F6C,4),1,"max_sol",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "max_sol"
#define PRED       X6D61785F736F6C
#define ARITY      4

Begin_Public_Pred
      allocate(4)
      get_y_variable(3,0)
      get_y_variable(2,1)
      get_y_variable(1,2)
      get_y_bc_reg(0)
      put_constant(X246375725F6D6178,0,"$cur_max")
      builtin_2(g_assign,0,3)
      call(Pred_Name(X726570656174,0),0,1,"repeat",0)          /* begin sub 1 */
      put_constant(X246375725F6D6178,1,"$cur_max")
      put_x_variable(4,0)
      builtin_2(g_read,1,0)
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_unsafe_value(0,3)
      deallocate
      execute(Pred_Name(X6D61785F736F6C5F2461757831,5),1,"max_sol_$aux1",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "max_sol_$aux1"
#define PRED       X6D61785F736F6C5F2461757831
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      allocate(4)
      get_y_variable(1,0)
      get_y_variable(3,1)
      get_y_bc_reg(2)
      put_constant(X67,0,"g")
      put_y_value(1,1)
      put_x_value(4,2)
      call(Pred_Name(X6B656570,3),1,1,"keep",3)          /* begin sub 1 */
      put_y_value(3,0)
      call(Pred_Name(X63616C6C,1),0,2,"call",1)          /* begin sub 2 */
      cut_y(2)
      put_y_value(1,0)
      put_y_variable(0,1)
      call(Pred_Name(X626C6576656C,2),0,3,"blevel",2)          /* begin sub 3 */
      put_constant(X246375725F6D6178,1,"$cur_max")
      put_y_unsafe_value(0,0)
      builtin_2(g_assign,1,0)
      fail

label(1)
      trust_me_else_fail
      allocate(1)
      get_x_variable(5,0)
      get_y_variable(0,2)
      cut_x(3)
      put_constant(X246375725F6D6178,1,"$cur_max")
      put_x_variable(2,0)
      builtin_2(g_read,1,0)
      put_constant(X6765,0,"ge")
      put_x_value(5,1)
      call(Pred_Name(X6B656570,3),1,4,"keep",3)          /* begin sub 4 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X63616C6C,1),0,"call",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(sfd_optimization)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X637574,"cut")
 Define_Atom(X6C65,"le")
 Define_Atom(X6C,"l")
 Define_Atom(X6765,"ge")
 Define_Atom(X67,"g")
 Define_Atom(X64,"d")
 Define_Atom(X6E70,"np")
 Define_Atom(X6E6E70,"nnp")
 Define_Atom(X6B656570,"keep")
 Define_Atom(X6D61785F736F6C,"max_sol")
 Define_Atom(X6C6162656C696E67,"labeling")
 Define_Atom(X246375725F6D6178,"$cur_max")
 Define_Atom(X6D61785F736F6C5F2461757831,"max_sol_$aux1")


 Define_Pred(X637574,3,1)
 Define_Switch_CST_Table(Swt_Table_Name(X637574,3,2,cst),7)
     Define_Switch_CST(X6C65,Label_Pred_Name(X637574,3,4))
     Define_Switch_CST(X6C,Label_Pred_Name(X637574,3,6))
     Define_Switch_CST(X6765,Label_Pred_Name(X637574,3,8))
     Define_Switch_CST(X67,Label_Pred_Name(X637574,3,10))
     Define_Switch_CST(X64,Label_Pred_Name(X637574,3,12))
     Define_Switch_CST(X6E70,Label_Pred_Name(X637574,3,14))
     Define_Switch_CST(X6E6E70,Label_Pred_Name(X637574,3,16))

 Define_Pred(X6B656570,3,1)
 Define_Switch_CST_Table(Swt_Table_Name(X6B656570,3,2,cst),7)
     Define_Switch_CST(X6C65,Label_Pred_Name(X6B656570,3,4))
     Define_Switch_CST(X6C,Label_Pred_Name(X6B656570,3,6))
     Define_Switch_CST(X6765,Label_Pred_Name(X6B656570,3,8))
     Define_Switch_CST(X67,Label_Pred_Name(X6B656570,3,10))
     Define_Switch_CST(X64,Label_Pred_Name(X6B656570,3,12))
     Define_Switch_CST(X6E70,Label_Pred_Name(X6B656570,3,14))
     Define_Switch_CST(X6E6E70,Label_Pred_Name(X6B656570,3,16))

 Define_Pred(X6D61785F736F6C,1,1)

 Define_Pred(X6D61785F736F6C,3,1)

 Define_Pred(X6D61785F736F6C,4,1)

 Define_Pred(X6D61785F736F6C5F2461757831,5,0)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(sfd_optimization)



End_Exec_Directives
