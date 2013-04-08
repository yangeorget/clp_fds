/****************************************************************************
Prolog to Wam Compiler - Version 2.0
Daniel Diaz, Yan Georget
1998 - INRIA Rocquencourt - LOCO Project
File : sfd_meta.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"
#include "sfd_engine.h"

#include "sfd_meta.h"
#include "sfd_meta.usr"


#define ASCII_PRED "b <=> x=c"
#define PRED       X62203C3D3E20783D63
#define ARITY      3

Begin_Public_Pred
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(1,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(2,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(3,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(4,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(5,3)
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

      fd_integer(2,0)
      fd_integer(1,1)
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


Begin_Fd_Install(2)

      fd_create_C_frame(2)
      fd_install_ind_sigma(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(2)

      fd_ind_sigma(1,1)
      fd_integer(3,0)
      fd_integer(2,1)
      fd_tell_interval_value(0,3,2,1)
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
      fd_install_ind_sigma(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(3)

      fd_ind_sigma(0,0)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_tell_interval_value(1,3,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(3)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(3)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(3)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(4)

      fd_create_C_frame(4)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(4)

      fd_allocate
      fd_ind_min_max(4,3,1)
      fd_term_parameter(2,2)
      fd_range_fct(equiv_eqc_r,1,arg_3(tr(4),tr(3),tr(2)))
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
      fd_install_ind_val(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(5)

      fd_allocate
      fd_ind_val(3,0,1)
      fd_term_parameter(2,2)
      fd_range_fct(equiv_eqc_a,0,arg_2(tr(3),tr(2)))
      fd_tell_range(1,0)

   Fd_Label(1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(5)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(5)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(5)

      fd_reduce_vars(1)

End_Fd_Reduction



#define ASCII_PRED "b <=> x=c:(a;b)"
#define PRED       X62203C3D3E20783D633A28613B6229
#define ARITY      5

Begin_Public_Pred
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_value_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(4)
      fd_install_constraint_with_x_AF(6,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(7,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(8,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(9,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(10,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(11,5)
      fd_call_constraint
      proceed

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

      fd_integer(3,0)
      fd_integer(2,1)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
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
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(7)

      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(7)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(7)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(7)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(8)

      fd_create_C_frame(8)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(8)

      fd_ind_sigma(1,2)
      fd_integer(3,0)
      fd_integer(2,1)
      fd_tell_interval_value(0,3,2,1)
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
      fd_install_ind_sigma(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(9)

      fd_ind_sigma(0,0)
      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(9)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(9)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(9)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(10)

      fd_create_C_frame(10)
      fd_install_ind_min_max(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(10)

      fd_allocate
      fd_ind_min_max(4,3,2)
      fd_term_parameter(2,3)
      fd_range_fct(equiv_eqc_r,1,arg_3(tr(4),tr(3),tr(2)))
      fd_term_parameter(2,4)
      fd_range_addA_term(1,2)
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
      fd_install_ind_val(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(11)

      fd_allocate
      fd_ind_val(3,0,1)
      fd_term_parameter(1,3)
      fd_range_fct(equiv_eqc_a,0,arg_2(tr(3),tr(1)))
      fd_term_parameter(1,4)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)

   Fd_Label(1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(11)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(11)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(11)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "b <=> x>c"
#define PRED       X62203C3D3E20783E63
#define ARITY      3

Begin_Public_Pred
      try_me_else(1)
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(12,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(13,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(14,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(15,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(16,3)
      fd_call_constraint
      proceed

label(1)
      trust_me_else_fail
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(23,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(24,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(25,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(26,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(27,3)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(12)

      fd_create_C_frame(12)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(12)

      fd_integer(2,0)
      fd_integer(1,1)
      fd_tell_interval(0,2,1)
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
      fd_install_ind_sigma(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(13)

      fd_ind_sigma(1,1)
      fd_integer(3,0)
      fd_integer(2,1)
      fd_tell_interval_value(0,3,2,1)
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
      fd_install_ind_sigma(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(14)

      fd_ind_sigma(0,0)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_tell_interval_value(1,3,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(14)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(14)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(14)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(15)

      fd_create_C_frame(15)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(15)

      fd_allocate
      fd_ind_min_max(4,3,1)
      fd_term_parameter(2,2)
      fd_range_fct(equiv_gc_r,1,arg_3(tr(4),tr(3),tr(2)))
      fd_tell_range(0,1)
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
      fd_install_ind_val(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(16)

      fd_allocate
      fd_ind_val(3,0,1)
      fd_term_parameter(2,2)
      fd_range_fct(equiv_gc_a,0,arg_2(tr(3),tr(2)))
      fd_tell_range(1,0)

   Fd_Label(1)
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


Begin_Fd_Install(23)

      fd_create_C_frame(23)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(23)

      fd_integer(2,0)
      fd_integer(1,1)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(23)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(23)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(23)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(24)

      fd_create_C_frame(24)
      fd_install_ind_sigma(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(24)

      fd_ind_sigma(1,1)
      fd_integer(3,0)
      fd_integer(2,1)
      fd_tell_interval_value(0,3,2,1)
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
      fd_install_ind_sigma(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(25)

      fd_ind_sigma(0,0)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_tell_interval_value(1,3,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(25)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(25)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(25)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(26)

      fd_create_C_frame(26)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(26)

      fd_allocate
      fd_ind_min_max(4,3,1)
      fd_term_parameter(2,2)
      fd_range_fct(equiv_gec_r,1,arg_3(tr(4),tr(3),tr(2)))
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(26)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(26)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(26)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(27)

      fd_create_C_frame(27)
      fd_install_ind_val(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(27)

      fd_allocate
      fd_ind_val(3,0,1)
      fd_term_parameter(2,2)
      fd_range_fct(equiv_gec_a,0,arg_2(tr(3),tr(2)))
      fd_tell_range(1,0)

   Fd_Label(1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(27)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(27)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(27)

      fd_reduce_vars(1)

End_Fd_Reduction



#define ASCII_PRED "b <=> x>c:(a;b)"
#define PRED       X62203C3D3E20783E633A28613B6229
#define ARITY      5

Begin_Public_Pred
      try_me_else(1)
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_value_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(4)
      fd_install_constraint_with_x_AF(17,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(18,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(19,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(20,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(21,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(22,5)
      fd_call_constraint
      proceed

label(1)
      trust_me_else_fail
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_value_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(4)
      fd_install_constraint_with_x_AF(28,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(29,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(30,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(31,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(32,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(33,5)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(17)

      fd_create_C_frame(17)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(17)

      fd_integer(3,0)
      fd_integer(2,1)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(17)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(17)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(17)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(18)

      fd_create_C_frame(18)
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(18)

      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(18)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(18)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(18)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(19)

      fd_create_C_frame(19)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(19)

      fd_ind_sigma(1,2)
      fd_integer(3,0)
      fd_integer(2,1)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(19)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(19)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(19)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(20)

      fd_create_C_frame(20)
      fd_install_ind_sigma(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(20)

      fd_ind_sigma(0,0)
      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_tell_interval_value(2,3,1,0)
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


Begin_Fd_Install(21)

      fd_create_C_frame(21)
      fd_install_ind_min_max(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(21)

      fd_allocate
      fd_ind_min_max(4,3,2)
      fd_term_parameter(2,3)
      fd_range_fct(equiv_gc_r,1,arg_3(tr(4),tr(3),tr(2)))
      fd_term_parameter(2,4)
      fd_range_addA_term(1,2)
      fd_tell_range(0,1)
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
      fd_install_ind_val(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(22)

      fd_allocate
      fd_ind_val(3,0,1)
      fd_term_parameter(1,3)
      fd_range_fct(equiv_gc_a,0,arg_2(tr(3),tr(1)))
      fd_term_parameter(1,4)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)

   Fd_Label(1)
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


Begin_Fd_Install(28)

      fd_create_C_frame(28)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(28)

      fd_integer(3,0)
      fd_integer(2,1)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(28)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(28)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(28)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(29)

      fd_create_C_frame(29)
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(29)

      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(2,3,1,0)
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
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(30)

      fd_ind_sigma(1,2)
      fd_integer(3,0)
      fd_integer(2,1)
      fd_tell_interval_value(0,3,2,1)
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
      fd_install_ind_sigma(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(31)

      fd_ind_sigma(0,0)
      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(31)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(31)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(31)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(32)

      fd_create_C_frame(32)
      fd_install_ind_min_max(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(32)

      fd_allocate
      fd_ind_min_max(4,3,2)
      fd_term_parameter(2,3)
      fd_range_fct(equiv_gec_r,1,arg_3(tr(4),tr(3),tr(2)))
      fd_term_parameter(2,4)
      fd_range_addA_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(32)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(32)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(32)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(33)

      fd_create_C_frame(33)
      fd_install_ind_val(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(33)

      fd_allocate
      fd_ind_val(3,0,1)
      fd_term_parameter(1,3)
      fd_range_fct(equiv_gec_a,0,arg_2(tr(3),tr(1)))
      fd_term_parameter(1,4)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)

   Fd_Label(1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(33)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(33)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(33)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "b <=> x=y"
#define PRED       X62203C3D3E20783D79
#define ARITY      3

Begin_Public_Pred
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_install_constraint_with_x_AF(34,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(35,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(36,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(37,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(38,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(39,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(40,3)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(34)

      fd_create_C_frame(34)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(34)

      fd_integer(2,0)
      fd_integer(1,1)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(34)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(34)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(34)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(35)

      fd_create_C_frame(35)
      fd_install_ind_sigma(1)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(35)

      fd_ind_sigma(1,1)
      fd_ind_sigma(4,2)
      fd_integer(3,0)
      fd_integer(2,1)
      fd_term_mulA_term(1,4)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(35)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(35)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(35)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(36)

      fd_create_C_frame(36)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(36)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,2)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(1,3,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(36)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(36)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(36)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(37)

      fd_create_C_frame(37)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(37)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,1)
      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(2,3,1,0)
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
      fd_install_ind_def(1)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(38)

      fd_allocate
      fd_ind_def(3,1)
      fd_ind_def(2,2)
      fd_range_fct(equiv_eq_r,1,arg_2(rr(3),rr(2)))
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(38)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(38)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(38)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(39)

      fd_create_C_frame(39)
      fd_install_ind_def(2)
      fd_install_ind_val(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(39)

      fd_allocate
      fd_ind_def(3,2)
      fd_ind_val(2,0,1)
      fd_range_fct(equiv_eq_a,0,arg_2(rr(3),tr(2)))
      fd_tell_range(1,0)

   Fd_Label(1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(39)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(39)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(39)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(40)

      fd_create_C_frame(40)
      fd_install_ind_def(1)
      fd_install_ind_val(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(40)

      fd_allocate
      fd_ind_def(3,1)
      fd_ind_val(1,0,1)
      fd_range_fct(equiv_eq_a,0,arg_2(rr(3),tr(1)))
      fd_tell_range(2,0)

   Fd_Label(1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(40)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(40)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(40)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "b <=> x=y:(a;b)"
#define PRED       X62203C3D3E20783D793A28613B6229
#define ARITY      5

Begin_Public_Pred
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(4)
      fd_install_constraint_with_x_AF(41,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(42,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(43,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(44,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(45,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(46,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(47,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(48,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(49,5)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(41)

      fd_create_C_frame(41)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(41)

      fd_integer(3,0)
      fd_integer(2,1)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(41)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(41)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(41)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(42)

      fd_create_C_frame(42)
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(42)

      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(42)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(42)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(42)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(43)

      fd_create_C_frame(43)
      fd_static_constraint(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(43)

      fd_integer(2,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(3,2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(43)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(43)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(43)

      fd_reduce_vars(3)

End_Fd_Reduction


Begin_Fd_Install(44)

      fd_create_C_frame(44)
      fd_install_ind_sigma(2)
      fd_install_ind_sigma(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(44)

      fd_ind_sigma(1,2)
      fd_ind_sigma(4,3)
      fd_integer(3,0)
      fd_integer(2,1)
      fd_term_mulA_term(1,4)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(44)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(44)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(44)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(45)

      fd_create_C_frame(45)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(45)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,3)
      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(45)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(45)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(45)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(46)

      fd_create_C_frame(46)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(46)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,2)
      fd_integer(2,0)
      fd_integer(1,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(3,2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(46)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(46)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(46)

      fd_reduce_vars(3)

End_Fd_Reduction


Begin_Fd_Install(47)

      fd_create_C_frame(47)
      fd_install_ind_def(2)
      fd_install_ind_def(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(47)

      fd_allocate
      fd_ind_def(3,2)
      fd_ind_def(2,3)
      fd_range_fct(equiv_eq_r,1,arg_2(rr(3),rr(2)))
      fd_term_parameter(2,4)
      fd_range_addA_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(47)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(47)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(47)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(48)

      fd_create_C_frame(48)
      fd_install_ind_def(3)
      fd_install_ind_val(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(48)

      fd_allocate
      fd_ind_def(3,3)
      fd_ind_val(1,0,1)
      fd_range_fct(equiv_eq_a,0,arg_2(rr(3),tr(1)))
      fd_term_parameter(1,4)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)

   Fd_Label(1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(48)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(48)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(48)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(49)

      fd_create_C_frame(49)
      fd_install_ind_def(2)
      fd_install_ind_val(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(49)

      fd_allocate
      fd_ind_def(2,2)
      fd_ind_val(1,0,1)
      fd_range_fct(equiv_eq_a,0,arg_2(rr(2),tr(1)))
      fd_term_parameter(1,4)
      fd_range_addA_term(0,1)
      fd_tell_range(3,0)

   Fd_Label(1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(49)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(49)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(49)

      fd_reduce_vars(3)

End_Fd_Reduction



#define ASCII_PRED "b <=> x>y"
#define PRED       X62203C3D3E20783E79
#define ARITY      3

Begin_Public_Pred
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_install_constraint_with_x_AF(50,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(51,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(52,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(53,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(54,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(55,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(56,3)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(50)

      fd_create_C_frame(50)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(50)

      fd_integer(2,0)
      fd_integer(1,1)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(50)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(50)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(50)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(51)

      fd_create_C_frame(51)
      fd_install_ind_sigma(1)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(51)

      fd_ind_sigma(1,1)
      fd_ind_sigma(4,2)
      fd_integer(3,0)
      fd_integer(2,1)
      fd_term_mulA_term(1,4)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(51)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(51)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(51)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(52)

      fd_create_C_frame(52)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(52)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,2)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(1,3,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(52)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(52)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(52)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(53)

      fd_create_C_frame(53)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(53)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,1)
      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(53)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(53)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(53)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(54)

      fd_create_C_frame(54)
      fd_install_ind_min_max(1)
      fd_install_ind_min_max(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(54)

      fd_allocate
      fd_ind_min_max(5,4,1)
      fd_ind_min_max(3,2,2)
      fd_range_fct(equiv_g_r,1,arg_4(tr(5),tr(4),tr(3),tr(2)))
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(54)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(54)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(54)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(55)

      fd_create_C_frame(55)
      fd_install_ind_def(2)
      fd_install_ind_val(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(55)

      fd_allocate
      fd_ind_def(3,2)
      fd_ind_val(2,0,1)
      fd_range_fct(equiv_g_a1,0,arg_2(rr(3),tr(2)))
      fd_tell_range(1,0)

   Fd_Label(1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(55)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(55)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(55)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(56)

      fd_create_C_frame(56)
      fd_install_ind_def(1)
      fd_install_ind_val(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(56)

      fd_allocate
      fd_ind_def(3,1)
      fd_ind_val(1,0,1)
      fd_range_fct(equiv_g_a2,0,arg_2(rr(3),tr(1)))
      fd_tell_range(2,0)

   Fd_Label(1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(56)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(56)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(56)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "b <=> x>y:(a;b)"
#define PRED       X62203C3D3E20783E793A28613B6229
#define ARITY      5

Begin_Public_Pred
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(4)
      fd_install_constraint_with_x_AF(57,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(58,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(59,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(60,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(61,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(62,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(63,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(64,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(65,5)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(57)

      fd_create_C_frame(57)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(57)

      fd_integer(3,0)
      fd_integer(2,1)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(57)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(57)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(57)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(58)

      fd_create_C_frame(58)
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(58)

      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(58)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(58)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(58)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(59)

      fd_create_C_frame(59)
      fd_static_constraint(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(59)

      fd_integer(2,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(3,2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(59)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(59)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(59)

      fd_reduce_vars(3)

End_Fd_Reduction


Begin_Fd_Install(60)

      fd_create_C_frame(60)
      fd_install_ind_sigma(2)
      fd_install_ind_sigma(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(60)

      fd_ind_sigma(1,2)
      fd_ind_sigma(4,3)
      fd_integer(3,0)
      fd_integer(2,1)
      fd_term_mulA_term(1,4)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(60)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(60)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(60)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(61)

      fd_create_C_frame(61)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(61)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,3)
      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(61)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(61)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(61)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(62)

      fd_create_C_frame(62)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(62)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,2)
      fd_integer(2,0)
      fd_integer(1,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(3,2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(62)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(62)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(62)

      fd_reduce_vars(3)

End_Fd_Reduction


Begin_Fd_Install(63)

      fd_create_C_frame(63)
      fd_install_ind_min_max(2)
      fd_install_ind_min_max(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(63)

      fd_allocate
      fd_ind_min_max(5,4,2)
      fd_ind_min_max(3,2,3)
      fd_range_fct(equiv_g_r,1,arg_4(tr(5),tr(4),tr(3),tr(2)))
      fd_term_parameter(2,4)
      fd_range_addA_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(63)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(63)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(63)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(64)

      fd_create_C_frame(64)
      fd_install_ind_def(3)
      fd_install_ind_val(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(64)

      fd_allocate
      fd_ind_def(3,3)
      fd_ind_val(1,0,1)
      fd_range_fct(equiv_g_a1,0,arg_2(rr(3),tr(1)))
      fd_term_parameter(1,4)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)

   Fd_Label(1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(64)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(64)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(64)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(65)

      fd_create_C_frame(65)
      fd_install_ind_def(2)
      fd_install_ind_val(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(65)

      fd_allocate
      fd_ind_def(2,2)
      fd_ind_val(1,0,1)
      fd_range_fct(equiv_g_a2,0,arg_2(rr(2),tr(1)))
      fd_term_parameter(1,4)
      fd_range_addA_term(0,1)
      fd_tell_range(3,0)

   Fd_Label(1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(65)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(65)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(65)

      fd_reduce_vars(3)

End_Fd_Reduction



#define ASCII_PRED "b <=> x>=y"
#define PRED       X62203C3D3E20783E3D79
#define ARITY      3

Begin_Public_Pred
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_install_constraint_with_x_AF(66,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(67,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(68,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(69,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(70,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(71,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(72,3)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(66)

      fd_create_C_frame(66)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(66)

      fd_integer(2,0)
      fd_integer(1,1)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(66)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(66)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(66)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(67)

      fd_create_C_frame(67)
      fd_install_ind_sigma(1)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(67)

      fd_ind_sigma(1,1)
      fd_ind_sigma(4,2)
      fd_integer(3,0)
      fd_integer(2,1)
      fd_term_mulA_term(1,4)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(67)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(67)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(67)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(68)

      fd_create_C_frame(68)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(68)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,2)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(1,3,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(68)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(68)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(68)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(69)

      fd_create_C_frame(69)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(69)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,1)
      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(69)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(69)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(69)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(70)

      fd_create_C_frame(70)
      fd_install_ind_min_max(1)
      fd_install_ind_min_max(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(70)

      fd_allocate
      fd_ind_min_max(5,4,1)
      fd_ind_min_max(3,2,2)
      fd_range_fct(equiv_ge_r,1,arg_4(tr(5),tr(4),tr(3),tr(2)))
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(70)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(70)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(70)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(71)

      fd_create_C_frame(71)
      fd_install_ind_def(2)
      fd_install_ind_val(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(71)

      fd_allocate
      fd_ind_def(3,2)
      fd_ind_val(2,0,1)
      fd_range_fct(equiv_ge_a1,0,arg_2(rr(3),tr(2)))
      fd_tell_range(1,0)

   Fd_Label(1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(71)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(71)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(71)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(72)

      fd_create_C_frame(72)
      fd_install_ind_def(1)
      fd_install_ind_val(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(72)

      fd_allocate
      fd_ind_def(3,1)
      fd_ind_val(1,0,1)
      fd_range_fct(equiv_ge_a2,0,arg_2(rr(3),tr(1)))
      fd_tell_range(2,0)

   Fd_Label(1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(72)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(72)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(72)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "b <=> x>=y:(a;b)"
#define PRED       X62203C3D3E20783E3D793A28613B6229
#define ARITY      5

Begin_Public_Pred
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(4)
      fd_install_constraint_with_x_AF(73,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(74,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(75,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(76,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(77,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(78,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(79,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(80,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(81,5)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(73)

      fd_create_C_frame(73)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(73)

      fd_integer(3,0)
      fd_integer(2,1)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(73)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(73)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(73)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(74)

      fd_create_C_frame(74)
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(74)

      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(74)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(74)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(74)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(75)

      fd_create_C_frame(75)
      fd_static_constraint(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(75)

      fd_integer(2,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(3,2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(75)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(75)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(75)

      fd_reduce_vars(3)

End_Fd_Reduction


Begin_Fd_Install(76)

      fd_create_C_frame(76)
      fd_install_ind_sigma(2)
      fd_install_ind_sigma(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(76)

      fd_ind_sigma(1,2)
      fd_ind_sigma(4,3)
      fd_integer(3,0)
      fd_integer(2,1)
      fd_term_mulA_term(1,4)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(76)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(76)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(76)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(77)

      fd_create_C_frame(77)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(77)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,3)
      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(77)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(77)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(77)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(78)

      fd_create_C_frame(78)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(78)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,2)
      fd_integer(2,0)
      fd_integer(1,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(3,2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(78)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(78)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(78)

      fd_reduce_vars(3)

End_Fd_Reduction


Begin_Fd_Install(79)

      fd_create_C_frame(79)
      fd_install_ind_min_max(2)
      fd_install_ind_min_max(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(79)

      fd_allocate
      fd_ind_min_max(5,4,2)
      fd_ind_min_max(3,2,3)
      fd_range_fct(equiv_ge_r,1,arg_4(tr(5),tr(4),tr(3),tr(2)))
      fd_term_parameter(2,4)
      fd_range_addA_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(79)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(79)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(79)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(80)

      fd_create_C_frame(80)
      fd_install_ind_def(3)
      fd_install_ind_val(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(80)

      fd_allocate
      fd_ind_def(3,3)
      fd_ind_val(1,0,1)
      fd_range_fct(equiv_ge_a1,0,arg_2(rr(3),tr(1)))
      fd_term_parameter(1,4)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)

   Fd_Label(1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(80)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(80)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(80)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(81)

      fd_create_C_frame(81)
      fd_install_ind_def(2)
      fd_install_ind_val(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(81)

      fd_allocate
      fd_ind_def(2,2)
      fd_ind_val(1,0,1)
      fd_range_fct(equiv_ge_a2,0,arg_2(rr(2),tr(1)))
      fd_term_parameter(1,4)
      fd_range_addA_term(0,1)
      fd_tell_range(3,0)

   Fd_Label(1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(81)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(81)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(81)

      fd_reduce_vars(3)

End_Fd_Reduction



#define ASCII_PRED "atmost"
#define PRED       X61746D6F7374
#define ARITY      3

Begin_Public_Pred
      allocate(3)
      get_y_variable(0,0)
      put_y_variable(2,0)
      call(Pred_Name(X65717569765F65715F637374,3),1,1,"equiv_eq_cst",3)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_variable(1,1)
      call(Pred_Name(X73756D,2),0,2,"sum",2)          /* begin sub 2 */
      fd_set_x_AF(2,0)
      fd_y_value_in_A_frame(1)
      fd_y_term_parameter_in_A_frame(0)
      fd_install_constraint_with_x_AF(82,0)
      fd_call_constraint
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(82)

      fd_create_C_frame(82)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(82)

      fd_integer(2,0)
      fd_term_parameter(1,1)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(82)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(82)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(82)

      fd_reduce_vars(0)

End_Fd_Reduction



#define ASCII_PRED "atleast"
#define PRED       X61746C65617374
#define ARITY      3

Begin_Public_Pred
      allocate(3)
      get_y_variable(0,0)
      put_y_variable(2,0)
      call(Pred_Name(X65717569765F65715F637374,3),1,1,"equiv_eq_cst",3)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_variable(1,1)
      call(Pred_Name(X73756D,2),0,2,"sum",2)          /* begin sub 2 */
      fd_set_x_AF(2,0)
      fd_y_value_in_A_frame(1)
      fd_y_term_parameter_in_A_frame(0)
      fd_install_constraint_with_x_AF(83,0)
      fd_call_constraint
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(83)

      fd_create_C_frame(83)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(83)

      fd_term_parameter(2,1)
      fd_integer(1,infinity)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(83)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(83)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(83)

      fd_reduce_vars(0)

End_Fd_Reduction



#define ASCII_PRED "exactly"
#define PRED       X65786163746C79
#define ARITY      3

Begin_Public_Pred
      allocate(3)
      get_y_variable(0,0)
      put_y_variable(2,0)
      call(Pred_Name(X65717569765F65715F637374,3),1,1,"equiv_eq_cst",3)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_variable(1,1)
      call(Pred_Name(X73756D,2),0,2,"sum",2)          /* begin sub 2 */
      fd_set_x_AF(2,0)
      fd_y_value_in_A_frame(1)
      fd_y_term_parameter_in_A_frame(0)
      fd_install_constraint_with_x_AF(84,0)
      fd_call_constraint
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(84)

      fd_create_C_frame(84)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(84)

      fd_term_parameter(1,1)
      fd_tell_integer(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(84)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(84)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(84)

      fd_reduce_vars(0)

End_Fd_Reduction



#define ASCII_PRED "equiv_eq_cst"
#define PRED       X65717569765F65715F637374
#define ARITY      3

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
      allocate(3)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(2)
      get_list(1)
      unify_x_variable(1)
      unify_y_variable(1)
      get_y_variable(0,2)
      put_y_value(0,2)
      call(Pred_Name(X62203C3D3E20783D63,3),1,1,"b <=> x=c",3)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X65717569765F65715F637374,3),1,"equiv_eq_cst",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "equiv_eq_csts"
#define PRED       X65717569765F65715F63737473
#define ARITY      3

Begin_Public_Pred
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
      allocate(3)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(2)
      get_list(1)
      unify_x_variable(1)
      unify_y_variable(1)
      get_list(2)
      unify_x_variable(2)
      unify_y_variable(0)
      call(Pred_Name(X62203C3D3E20783D63,3),1,1,"b <=> x=c",3)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X65717569765F65715F63737473,3),1,"equiv_eq_csts",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(sfd_meta)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X62203C3D3E20783D63,"b <=> x=c")
 Define_Atom(X62203C3D3E20783D633A28613B6229,"b <=> x=c:(a;b)")
 Define_Atom(X62203C3D3E20783E63,"b <=> x>c")
 Define_Atom(X62203C3D3E20783E633A28613B6229,"b <=> x>c:(a;b)")
 Define_Atom(X62203C3D3E20783D79,"b <=> x=y")
 Define_Atom(X62203C3D3E20783D793A28613B6229,"b <=> x=y:(a;b)")
 Define_Atom(X62203C3D3E20783E79,"b <=> x>y")
 Define_Atom(X62203C3D3E20783E793A28613B6229,"b <=> x>y:(a;b)")
 Define_Atom(X62203C3D3E20783E3D79,"b <=> x>=y")
 Define_Atom(X62203C3D3E20783E3D793A28613B6229,"b <=> x>=y:(a;b)")
 Define_Atom(X61746D6F7374,"atmost")
 Define_Atom(X61746C65617374,"atleast")
 Define_Atom(X65786163746C79,"exactly")
 Define_Atom(X65717569765F65715F637374,"equiv_eq_cst")
 Define_Atom(X65717569765F65715F63737473,"equiv_eq_csts")


 Define_Pred(X62203C3D3E20783D63,3,1)

 Define_Pred(X62203C3D3E20783D633A28613B6229,5,1)

 Define_Pred(X62203C3D3E20783E63,3,1)

 Define_Pred(X62203C3D3E20783E633A28613B6229,5,1)

 Define_Pred(X62203C3D3E20783D79,3,1)

 Define_Pred(X62203C3D3E20783D793A28613B6229,5,1)

 Define_Pred(X62203C3D3E20783E79,3,1)

 Define_Pred(X62203C3D3E20783E793A28613B6229,5,1)

 Define_Pred(X62203C3D3E20783E3D79,3,1)

 Define_Pred(X62203C3D3E20783E3D793A28613B6229,5,1)

 Define_Pred(X61746D6F7374,3,1)

 Define_Pred(X61746C65617374,3,1)

 Define_Pred(X65786163746C79,3,1)

 Define_Pred(X65717569765F65715F637374,3,1)

 Define_Pred(X65717569765F65715F63737473,3,1)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(sfd_meta)



End_Exec_Directives
