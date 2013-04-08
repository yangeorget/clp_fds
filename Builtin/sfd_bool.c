/****************************************************************************
Prolog to Wam Compiler - Version 2.0
Daniel Diaz, Yan Georget
1998 - INRIA Rocquencourt - LOCO Project
File : sfd_bool.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"
#include "sfd_engine.h"

#include "sfd_bool.h"
#include "sfd_bool.usr"


#define ASCII_PRED "x=not y:(a;b)"
#define PRED       X783D6E6F7420793A28613B6229
#define ARITY      4

Begin_Public_Pred
      fd_set_x_AF(4,4)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(2)
      fd_x_value_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(3)
      fd_install_constraint_with_x_AF(1,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(2,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(3,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(4,4)
      fd_call_constraint
      proceed

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

      fd_integer(3,0)
      fd_integer(2,1)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
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
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(2)

      fd_integer(3,0)
      fd_integer(1,1)
      fd_term_parameter(0,1)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(2)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(2)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(2)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(3)

      fd_create_C_frame(3)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(3)

      fd_allocate
      fd_ind_sigma_def(2,3,2)
      fd_range_fct(not,1,arg_1(rr(3)))
      fd_term_parameter(3,3)
      fd_term_mulA_term(2,3)
      fd_range_addA_term(1,2)
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
      fd_ind_sigma_def(1,3,0)
      fd_range_fct(not,0,arg_1(rr(3)))
      fd_term_parameter(3,3)
      fd_term_mulA_term(1,3)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(4)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(4)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(4)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "x=not y"
#define PRED       X783D6E6F742079
#define ARITY      2

Begin_Public_Pred
      fd_set_x_AF(2,2)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_install_constraint_with_x_AF(5,2)
      fd_call_constraint
      fd_install_constraint_with_x_AF(6,2)
      fd_call_constraint
      fd_install_constraint_with_x_AF(7,2)
      fd_call_constraint
      fd_install_constraint_with_x_AF(8,2)
      fd_call_constraint
      proceed

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

      fd_integer(2,0)
      fd_integer(1,1)
      fd_tell_interval(0,2,1)
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
      fd_static_constraint(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(6)

      fd_integer(2,0)
      fd_integer(0,1)
      fd_tell_interval(1,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(6)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(6)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(6)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(7)

      fd_create_C_frame(7)
      fd_install_ind_def(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(7)

      fd_allocate
      fd_ind_def(2,1)
      fd_range_fct(not,1,arg_1(rr(2)))
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


Begin_Fd_Install(8)

      fd_create_C_frame(8)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(8)

      fd_allocate
      fd_ind_def(2,0)
      fd_range_fct(not,0,arg_1(rr(2)))
      fd_tell_range(1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(8)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(8)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(8)

      fd_reduce_vars(1)

End_Fd_Reduction



#define ASCII_PRED "x=y and z:(a;b)"
#define PRED       X783D7920616E64207A3A28613B6229
#define ARITY      5

Begin_Public_Pred
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(4)
      fd_install_constraint_with_x_AF(9,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(10,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(11,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(12,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(13,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(14,5)
      fd_call_constraint
      proceed

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

      fd_integer(3,0)
      fd_integer(2,1)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
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
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(10)

      fd_integer(3,0)
      fd_integer(1,1)
      fd_term_parameter(0,1)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(10)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(10)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(10)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(11)

      fd_create_C_frame(11)
      fd_static_constraint(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(11)

      fd_integer(2,0)
      fd_integer(1,1)
      fd_term_parameter(0,1)
      fd_tell_interval_value(3,2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(11)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(11)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(11)

      fd_reduce_vars(3)

End_Fd_Reduction


Begin_Fd_Install(12)

      fd_create_C_frame(12)
      fd_install_ind_def(2)
      fd_install_ind_def(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(12)

      fd_allocate
      fd_ind_sigma_def(2,5,2)
      fd_ind_sigma_def(3,4,3)
      fd_range_fct(and_r,1,arg_2(rr(5),rr(4)))
      fd_term_mulA_term(2,3)
      fd_term_parameter(3,4)
      fd_term_mulA_term(2,3)
      fd_range_addA_term(1,2)
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
      fd_install_ind_def(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(13)

      fd_allocate
      fd_ind_sigma_def(1,5,0)
      fd_ind_sigma_def(3,4,3)
      fd_range_fct(and_a,0,arg_2(rr(5),rr(4)))
      fd_term_mulA_term(1,3)
      fd_term_parameter(3,4)
      fd_term_mulA_term(1,3)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(13)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(13)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(13)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(14)

      fd_create_C_frame(14)
      fd_install_ind_def(0)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(14)

      fd_allocate
      fd_ind_sigma_def(1,5,0)
      fd_ind_sigma_def(2,4,2)
      fd_range_fct(and_a,0,arg_2(rr(5),rr(4)))
      fd_term_mulA_term(1,2)
      fd_term_parameter(2,4)
      fd_term_mulA_term(1,2)
      fd_range_addA_term(0,1)
      fd_tell_range(3,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(14)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(14)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(14)

      fd_reduce_vars(3)

End_Fd_Reduction



#define ASCII_PRED "x=y and z"
#define PRED       X783D7920616E64207A
#define ARITY      3

Begin_Public_Pred
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_install_constraint_with_x_AF(15,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(16,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(17,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(18,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(19,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(20,3)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(15)

      fd_create_C_frame(15)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(15)

      fd_integer(2,0)
      fd_integer(1,1)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(15)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(15)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(15)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(16)

      fd_create_C_frame(16)
      fd_static_constraint(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(16)

      fd_integer(2,0)
      fd_integer(0,1)
      fd_tell_interval(1,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(16)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(16)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(16)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(17)

      fd_create_C_frame(17)
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(17)

      fd_integer(1,0)
      fd_integer(0,1)
      fd_tell_interval(2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(17)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(17)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(17)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(18)

      fd_create_C_frame(18)
      fd_install_ind_def(1)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(18)

      fd_allocate
      fd_ind_def(3,1)
      fd_ind_def(2,2)
      fd_range_fct(and_r,1,arg_2(rr(3),rr(2)))
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(18)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(18)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(18)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(19)

      fd_create_C_frame(19)
      fd_install_ind_def(0)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(19)

      fd_allocate
      fd_ind_def(3,0)
      fd_ind_def(2,2)
      fd_range_fct(and_a,0,arg_2(rr(3),rr(2)))
      fd_tell_range(1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(19)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(19)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(19)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(20)

      fd_create_C_frame(20)
      fd_install_ind_def(0)
      fd_install_ind_def(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(20)

      fd_allocate
      fd_ind_def(3,0)
      fd_ind_def(1,1)
      fd_range_fct(and_a,0,arg_2(rr(3),rr(1)))
      fd_tell_range(2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(20)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(20)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(20)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "x=y or z:(a;b)"
#define PRED       X783D79206F72207A3A28613B6229
#define ARITY      5

Begin_Public_Pred
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(4)
      fd_install_constraint_with_x_AF(21,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(22,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(23,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(24,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(25,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(26,5)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(21)

      fd_create_C_frame(21)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(21)

      fd_integer(3,0)
      fd_integer(2,1)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(21)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(21)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(21)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(22)

      fd_create_C_frame(22)
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(22)

      fd_integer(3,0)
      fd_integer(1,1)
      fd_term_parameter(0,1)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(22)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(22)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(22)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(23)

      fd_create_C_frame(23)
      fd_static_constraint(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(23)

      fd_integer(2,0)
      fd_integer(1,1)
      fd_term_parameter(0,1)
      fd_tell_interval_value(3,2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(23)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(23)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(23)

      fd_reduce_vars(3)

End_Fd_Reduction


Begin_Fd_Install(24)

      fd_create_C_frame(24)
      fd_install_ind_def(2)
      fd_install_ind_def(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(24)

      fd_allocate
      fd_ind_sigma_def(2,5,2)
      fd_ind_sigma_def(3,4,3)
      fd_range_fct(or_r,1,arg_2(rr(5),rr(4)))
      fd_term_mulA_term(2,3)
      fd_term_parameter(3,4)
      fd_term_mulA_term(2,3)
      fd_range_addA_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(24)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(24)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(24)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(25)

      fd_create_C_frame(25)
      fd_install_ind_def(0)
      fd_install_ind_def(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(25)

      fd_allocate
      fd_ind_sigma_def(1,5,0)
      fd_ind_sigma_def(3,4,3)
      fd_range_fct(or_a,0,arg_2(rr(5),rr(4)))
      fd_term_mulA_term(1,3)
      fd_term_parameter(3,4)
      fd_term_mulA_term(1,3)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(25)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(25)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(25)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(26)

      fd_create_C_frame(26)
      fd_install_ind_def(0)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(26)

      fd_allocate
      fd_ind_sigma_def(1,5,0)
      fd_ind_sigma_def(2,4,2)
      fd_range_fct(or_a,0,arg_2(rr(5),rr(4)))
      fd_term_mulA_term(1,2)
      fd_term_parameter(2,4)
      fd_term_mulA_term(1,2)
      fd_range_addA_term(0,1)
      fd_tell_range(3,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(26)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(26)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(26)

      fd_reduce_vars(3)

End_Fd_Reduction



#define ASCII_PRED "x=y or z"
#define PRED       X783D79206F72207A
#define ARITY      3

Begin_Public_Pred
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_install_constraint_with_x_AF(27,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(28,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(29,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(30,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(31,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(32,3)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(27)

      fd_create_C_frame(27)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(27)

      fd_integer(2,0)
      fd_integer(1,1)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(27)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(27)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(27)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(28)

      fd_create_C_frame(28)
      fd_static_constraint(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(28)

      fd_integer(2,0)
      fd_integer(0,1)
      fd_tell_interval(1,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(28)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(28)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(28)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(29)

      fd_create_C_frame(29)
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(29)

      fd_integer(1,0)
      fd_integer(0,1)
      fd_tell_interval(2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(29)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(29)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(29)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(30)

      fd_create_C_frame(30)
      fd_install_ind_def(1)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(30)

      fd_allocate
      fd_ind_def(3,1)
      fd_ind_def(2,2)
      fd_range_fct(or_r,1,arg_2(rr(3),rr(2)))
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(30)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(30)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(30)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(31)

      fd_create_C_frame(31)
      fd_install_ind_def(0)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(31)

      fd_allocate
      fd_ind_def(3,0)
      fd_ind_def(2,2)
      fd_range_fct(or_a,0,arg_2(rr(3),rr(2)))
      fd_tell_range(1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(31)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(31)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(31)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(32)

      fd_create_C_frame(32)
      fd_install_ind_def(0)
      fd_install_ind_def(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(32)

      fd_allocate
      fd_ind_def(3,0)
      fd_ind_def(1,1)
      fd_range_fct(or_a,0,arg_2(rr(3),rr(1)))
      fd_tell_range(2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(32)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(32)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(32)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "x=y xor z:(a;b)"
#define PRED       X783D7920786F72207A3A28613B6229
#define ARITY      5

Begin_Public_Pred
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(4)
      fd_install_constraint_with_x_AF(33,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(34,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(35,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(36,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(37,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(38,5)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(33)

      fd_create_C_frame(33)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(33)

      fd_integer(3,0)
      fd_integer(2,1)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(33)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(33)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(33)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(34)

      fd_create_C_frame(34)
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(34)

      fd_integer(3,0)
      fd_integer(1,1)
      fd_term_parameter(0,1)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(34)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(34)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(34)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(35)

      fd_create_C_frame(35)
      fd_static_constraint(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(35)

      fd_integer(2,0)
      fd_integer(1,1)
      fd_term_parameter(0,1)
      fd_tell_interval_value(3,2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(35)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(35)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(35)

      fd_reduce_vars(3)

End_Fd_Reduction


Begin_Fd_Install(36)

      fd_create_C_frame(36)
      fd_install_ind_def(2)
      fd_install_ind_def(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(36)

      fd_allocate
      fd_ind_sigma_def(2,5,2)
      fd_ind_sigma_def(3,4,3)
      fd_range_fct(xor_r,1,arg_2(rr(5),rr(4)))
      fd_term_mulA_term(2,3)
      fd_term_parameter(3,4)
      fd_term_mulA_term(2,3)
      fd_range_addA_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(36)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(36)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(36)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(37)

      fd_create_C_frame(37)
      fd_install_ind_def(0)
      fd_install_ind_def(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(37)

      fd_allocate
      fd_ind_sigma_def(1,5,0)
      fd_ind_sigma_def(3,4,3)
      fd_range_fct(xor_a,0,arg_2(rr(5),rr(4)))
      fd_term_mulA_term(1,3)
      fd_term_parameter(3,4)
      fd_term_mulA_term(1,3)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(37)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(37)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(37)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(38)

      fd_create_C_frame(38)
      fd_install_ind_def(0)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(38)

      fd_allocate
      fd_ind_sigma_def(1,5,0)
      fd_ind_sigma_def(2,4,2)
      fd_range_fct(xor_a,0,arg_2(rr(5),rr(4)))
      fd_term_mulA_term(1,2)
      fd_term_parameter(2,4)
      fd_term_mulA_term(1,2)
      fd_range_addA_term(0,1)
      fd_tell_range(3,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(38)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(38)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(38)

      fd_reduce_vars(3)

End_Fd_Reduction



#define ASCII_PRED "x=y xor z"
#define PRED       X783D7920786F72207A
#define ARITY      3

Begin_Public_Pred
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_install_constraint_with_x_AF(39,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(40,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(41,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(42,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(43,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(44,3)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(39)

      fd_create_C_frame(39)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(39)

      fd_integer(2,0)
      fd_integer(1,1)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(39)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(39)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(39)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(40)

      fd_create_C_frame(40)
      fd_static_constraint(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(40)

      fd_integer(2,0)
      fd_integer(0,1)
      fd_tell_interval(1,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(40)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(40)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(40)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(41)

      fd_create_C_frame(41)
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(41)

      fd_integer(1,0)
      fd_integer(0,1)
      fd_tell_interval(2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(41)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(41)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(41)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(42)

      fd_create_C_frame(42)
      fd_install_ind_def(1)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(42)

      fd_allocate
      fd_ind_def(3,1)
      fd_ind_def(2,2)
      fd_range_fct(xor_r,1,arg_2(rr(3),rr(2)))
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(42)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(42)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(42)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(43)

      fd_create_C_frame(43)
      fd_install_ind_def(0)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(43)

      fd_allocate
      fd_ind_def(3,0)
      fd_ind_def(2,2)
      fd_range_fct(xor_a,0,arg_2(rr(3),rr(2)))
      fd_tell_range(1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(43)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(43)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(43)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(44)

      fd_create_C_frame(44)
      fd_install_ind_def(0)
      fd_install_ind_def(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(44)

      fd_allocate
      fd_ind_def(3,0)
      fd_ind_def(1,1)
      fd_range_fct(xor_a,0,arg_2(rr(3),rr(1)))
      fd_tell_range(2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(44)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(44)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(44)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "and"
#define PRED       X616E64
#define ARITY      2

Begin_Public_Pred
      switch_on_term(G_label(2),G_label(3),fail,G_label(1),fail)

label(1)
      try(5,1)          /* begin sub 1 */
      trust(7)

label(2)
      try_me_else(4)

label(3)
      get_nil(0)
      fd_set_x_AF(1,0)
      fd_x_value_in_A_frame(1)
      fd_install_constraint_with_x_AF(45,0)
      fd_call_constraint
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_list(0)
      unify_x_variable(0)
      unify_nil
      neck_cut
      execute(Pred_Name(X783D79,2),0,"x=y",2)

label(6)
      trust_me_else_fail

label(7)
      allocate(3)
      get_list(0)
      unify_y_variable(1)
      unify_x_variable(0)
      get_y_variable(2,1)
      put_y_variable(0,1)
      call(Pred_Name(X616E64,2),1,2,"and",2)          /* begin sub 2 */
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_unsafe_value(0,2)
      deallocate
      execute(Pred_Name(X783D7920616E64207A,3),1,"x=y and z",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(45)

      fd_create_C_frame(45)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(45)

      fd_integer(1,1)
      fd_tell_integer(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(45)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(45)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(45)

      fd_reduce_vars(0)

End_Fd_Reduction



#define ASCII_PRED "or"
#define PRED       X6F72
#define ARITY      2

Begin_Public_Pred
      switch_on_term(G_label(2),G_label(3),fail,G_label(1),fail)

label(1)
      try(5,1)          /* begin sub 1 */
      trust(7)

label(2)
      try_me_else(4)

label(3)
      get_nil(0)
      fd_set_x_AF(1,0)
      fd_x_value_in_A_frame(1)
      fd_install_constraint_with_x_AF(46,0)
      fd_call_constraint
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_list(0)
      unify_x_variable(0)
      unify_nil
      neck_cut
      execute(Pred_Name(X783D79,2),0,"x=y",2)

label(6)
      trust_me_else_fail

label(7)
      allocate(3)
      get_list(0)
      unify_y_variable(1)
      unify_x_variable(0)
      get_y_variable(2,1)
      put_y_variable(0,1)
      call(Pred_Name(X6F72,2),1,2,"or",2)          /* begin sub 2 */
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_unsafe_value(0,2)
      deallocate
      execute(Pred_Name(X783D79206F72207A,3),1,"x=y or z",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(46)

      fd_create_C_frame(46)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(46)

      fd_integer(1,0)
      fd_tell_integer(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(46)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(46)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(46)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Init_Tables(sfd_bool)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X783D6E6F7420793A28613B6229,"x=not y:(a;b)")
 Define_Atom(X783D6E6F742079,"x=not y")
 Define_Atom(X783D7920616E64207A3A28613B6229,"x=y and z:(a;b)")
 Define_Atom(X783D7920616E64207A,"x=y and z")
 Define_Atom(X783D79206F72207A3A28613B6229,"x=y or z:(a;b)")
 Define_Atom(X783D79206F72207A,"x=y or z")
 Define_Atom(X783D7920786F72207A3A28613B6229,"x=y xor z:(a;b)")
 Define_Atom(X783D7920786F72207A,"x=y xor z")
 Define_Atom(X616E64,"and")
 Define_Atom(X6F72,"or")


 Define_Pred(X783D6E6F7420793A28613B6229,4,1)

 Define_Pred(X783D6E6F742079,2,1)

 Define_Pred(X783D7920616E64207A3A28613B6229,5,1)

 Define_Pred(X783D7920616E64207A,3,1)

 Define_Pred(X783D79206F72207A3A28613B6229,5,1)

 Define_Pred(X783D79206F72207A,3,1)

 Define_Pred(X783D7920786F72207A3A28613B6229,5,1)

 Define_Pred(X783D7920786F72207A,3,1)

 Define_Pred(X616E64,2,1)

 Define_Pred(X6F72,2,1)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(sfd_bool)



End_Exec_Directives
