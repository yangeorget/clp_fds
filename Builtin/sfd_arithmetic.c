/****************************************************************************
Prolog to Wam Compiler - Version 2.0
Daniel Diaz, Yan Georget
1998 - INRIA Rocquencourt - LOCO Project
File : sfd_arithmetic.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"
#include "sfd_engine.h"

#include "sfd_arithmetic.h"
#include "sfd_arithmetic.usr"


#define ASCII_PRED "x=choose(y,z)"
#define PRED       X783D63686F6F736528792C7A29
#define ARITY      3

Begin_Public_Pred
      allocate(4)
      get_y_variable(3,0)
      get_x_variable(3,1)
      get_y_variable(2,2)
      fd_set_x_AF(3,0)
      fd_y_value_in_A_frame(3)
      fd_x_value_in_A_frame(3)
      fd_y_value_in_A_frame(2)
      fd_install_constraint_with_x_AF(1,0)
      fd_call_constraint
      put_y_variable(1,0)
      put_y_value(3,1)
      put_x_value(3,2)
      call(Pred_Name(X62203C3D3E20783D79,3),0,1,"b <=> x=y",3)          /* begin sub 1 */
      put_y_variable(0,0)
      put_y_value(3,1)
      put_y_value(2,2)
      call(Pred_Name(X62203C3D3E20783D79,3),0,2,"b <=> x=y",3)          /* begin sub 2 */
      put_integer(1,0)
      put_y_unsafe_value(1,1)
      put_y_unsafe_value(0,2)
      deallocate
      execute(Pred_Name(X783D79206F72207A,3),0,"x=y or z",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(1)

      fd_create_C_frame(1)
      fd_install_ind_def(1)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(1)

      fd_allocate
      fd_ind_def(1,1)
      fd_ind_def(2,2)
      fd_range_addA_range(1,2)
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



#define ASCII_PRED "x=choose(y,z):(a;b)"
#define PRED       X783D63686F6F736528792C7A293A28613B6229
#define ARITY      5

Begin_Public_Pred
      allocate(6)
      get_y_variable(5,0)
      get_x_variable(5,1)
      get_y_variable(4,2)
      get_y_variable(1,3)
      get_y_variable(0,4)
      fd_set_x_AF(5,0)
      fd_y_value_in_A_frame(5)
      fd_y_term_parameter_in_A_frame(1)
      fd_x_value_in_A_frame(5)
      fd_y_value_in_A_frame(4)
      fd_y_term_parameter_in_A_frame(0)
      fd_install_constraint_with_x_AF(2,0)
      fd_call_constraint
      fd_install_constraint_with_x_AF(3,0)
      fd_call_constraint
      put_y_variable(3,0)
      put_y_value(5,1)
      put_x_value(5,2)
      call(Pred_Name(X62203C3D3E20783D79,3),0,1,"b <=> x=y",3)          /* begin sub 1 */
      put_y_variable(2,0)
      put_y_value(5,1)
      put_y_value(4,2)
      call(Pred_Name(X62203C3D3E20783D79,3),0,2,"b <=> x=y",3)          /* begin sub 2 */
      put_integer(1,0)
      put_y_unsafe_value(3,1)
      put_y_unsafe_value(2,2)
      put_y_value(1,3)
      put_y_value(0,4)
      deallocate
      execute(Pred_Name(X783D79206F72207A3A28613B6229,5),0,"x=y or z:(a;b)",5)

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

      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_parameter(1,1)
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
      fd_install_ind_def(2)
      fd_install_ind_def(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(3)

      fd_allocate
      fd_ind_sigma_def(2,1,2)
      fd_ind_sigma_def(3,4,3)
      fd_range_addA_range(1,4)
      fd_term_mulA_term(2,3)
      fd_term_parameter(3,4)
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



#define ASCII_PRED "x=min(y,z)"
#define PRED       X783D6D696E28792C7A29
#define ARITY      3

Begin_Public_Pred
      allocate(3)
      get_y_variable(2,0)
      get_y_variable(1,1)
      get_y_variable(0,2)
      put_y_value(1,0)
      put_y_value(2,1)
      call(Pred_Name(X783E3D79,2),1,1,"x>=y",2)          /* begin sub 1 */
      put_y_value(0,0)
      put_y_value(2,1)
      call(Pred_Name(X783E3D79,2),1,2,"x>=y",2)          /* begin sub 2 */
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X783D63686F6F736528792C7A29,3),1,"x=choose(y,z)",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "x=min(y,z):(a;b)"
#define PRED       X783D6D696E28792C7A293A28613B6229
#define ARITY      5

Begin_Public_Pred
      allocate(5)
      get_y_variable(4,0)
      get_y_variable(3,1)
      get_y_variable(2,2)
      get_y_variable(1,3)
      get_y_variable(0,4)
      put_y_value(3,0)
      put_y_value(4,1)
      put_y_value(1,2)
      put_y_value(0,3)
      call(Pred_Name(X783E3D793A28613B6229,4),1,1,"x>=y:(a;b)",4)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_value(4,1)
      put_y_value(1,2)
      put_y_value(0,3)
      call(Pred_Name(X783E3D793A28613B6229,4),1,2,"x>=y:(a;b)",4)          /* begin sub 2 */
      put_y_value(4,0)
      put_y_value(3,1)
      put_y_value(2,2)
      put_y_value(1,3)
      put_y_value(0,4)
      deallocate
      execute(Pred_Name(X783D63686F6F736528792C7A293A28613B6229,5),1,"x=choose(y,z):(a;b)",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "x=max(y,z)"
#define PRED       X783D6D617828792C7A29
#define ARITY      3

Begin_Public_Pred
      allocate(3)
      get_y_variable(2,0)
      get_y_variable(1,1)
      get_y_variable(0,2)
      put_y_value(2,0)
      put_y_value(1,1)
      call(Pred_Name(X783E3D79,2),1,1,"x>=y",2)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_value(0,1)
      call(Pred_Name(X783E3D79,2),1,2,"x>=y",2)          /* begin sub 2 */
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X783D63686F6F736528792C7A29,3),1,"x=choose(y,z)",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "x=max(y,z):(a;b)"
#define PRED       X783D6D617828792C7A293A28613B6229
#define ARITY      5

Begin_Public_Pred
      allocate(5)
      get_y_variable(4,0)
      get_y_variable(3,1)
      get_y_variable(2,2)
      get_y_variable(1,3)
      get_y_variable(0,4)
      put_y_value(4,0)
      put_y_value(3,1)
      put_y_value(1,2)
      put_y_value(0,3)
      call(Pred_Name(X783E3D793A28613B6229,4),1,1,"x>=y:(a;b)",4)          /* begin sub 1 */
      put_y_value(4,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      call(Pred_Name(X783E3D793A28613B6229,4),1,2,"x>=y:(a;b)",4)          /* begin sub 2 */
      put_y_value(4,0)
      put_y_value(3,1)
      put_y_value(2,2)
      put_y_value(1,3)
      put_y_value(0,4)
      deallocate
      execute(Pred_Name(X783D63686F6F736528792C7A293A28613B6229,5),1,"x=choose(y,z):(a;b)",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "x=c:(a;b)"
#define PRED       X783D633A28613B6229
#define ARITY      4

Begin_Public_Pred
      fd_set_x_AF(4,4)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(4,4)
      fd_call_constraint
      proceed

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

      fd_allocate
      fd_term_parameter(1,1)
      fd_interval_range(1,1,1)
      fd_term_parameter(2,2)
      fd_range_addA_term(1,2)
      fd_term_parameter(2,3)
      fd_range_mulA_term(1,2)
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



#define ASCII_PRED "x=c"
#define PRED       X783D63
#define ARITY      2

Begin_Public_Pred
      fd_set_x_AF(2,2)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(1)
      fd_install_constraint_with_x_AF(5,2)
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

      fd_term_parameter(1,1)
      fd_tell_integer(0,1)
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



#define ASCII_PRED "x<>c:(a;b)"
#define PRED       X783C3E633A28613B6229
#define ARITY      4

Begin_Public_Pred
      fd_set_x_AF(4,4)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(6,4)
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

      fd_allocate
      fd_term_parameter(1,1)
      fd_comp_term(1,1)
      fd_term_parameter(2,2)
      fd_range_addA_term(1,2)
      fd_term_parameter(2,3)
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



#define ASCII_PRED "x<>c"
#define PRED       X783C3E63
#define ARITY      2

Begin_Public_Pred
      fd_set_x_AF(2,2)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(1)
      fd_install_constraint_with_x_AF(7,2)
      fd_call_constraint
      proceed

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
      fd_term_parameter(1,1)
      fd_comp_term(1,1)
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



#define ASCII_PRED "x<>y:(a;b)"
#define PRED       X783C3E793A28613B6229
#define ARITY      4

Begin_Public_Pred
      fd_set_x_AF(4,4)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(2)
      fd_x_value_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(3)
      fd_install_constraint_with_x_AF(8,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(9,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(10,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(11,4)
      fd_call_constraint
      proceed

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

      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_parameter(1,1)
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
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(9)

      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
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
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(10)

      fd_allocate
      fd_ind_sigma_def(2,1,2)
      fd_d(1)
      fd_term_parameter(3,3)
      fd_term_mulA_term(2,3)
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
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(11)

      fd_allocate
      fd_ind_sigma_def(1,0,0)
      fd_d(0)
      fd_term_parameter(3,3)
      fd_term_mulA_term(1,3)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)
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



#define ASCII_PRED "x<>y"
#define PRED       X783C3E79
#define ARITY      2

Begin_Public_Pred
      fd_set_x_AF(2,2)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_install_constraint_with_x_AF(12,2)
      fd_call_constraint
      fd_install_constraint_with_x_AF(13,2)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(12)

      fd_create_C_frame(12)
      fd_install_ind_def(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(12)

      fd_allocate
      fd_ind_def(1,1)
      fd_d(1)
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
      fd_ind_def(0,0)
      fd_d(0)
      fd_tell_range(1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(13)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(13)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(13)

      fd_reduce_vars(1)

End_Fd_Reduction



#define ASCII_PRED "x=y:(a;b)"
#define PRED       X783D793A28613B6229
#define ARITY      4

Begin_Public_Pred
      fd_set_x_AF(4,4)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(2)
      fd_x_value_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(3)
      fd_install_constraint_with_x_AF(14,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(15,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(16,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(17,4)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(14)

      fd_create_C_frame(14)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(14)

      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
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


Begin_Fd_Install(15)

      fd_create_C_frame(15)
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(15)

      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(15)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(15)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(15)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(16)

      fd_create_C_frame(16)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(16)

      fd_allocate
      fd_ind_sigma_def(2,1,2)
      fd_term_parameter(3,3)
      fd_term_mulA_term(2,3)
      fd_range_addA_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(16)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(16)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(16)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(17)

      fd_create_C_frame(17)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(17)

      fd_allocate
      fd_ind_sigma_def(1,0,0)
      fd_term_parameter(3,3)
      fd_term_mulA_term(1,3)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)
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



#define ASCII_PRED "x=y"
#define PRED       X783D79
#define ARITY      2

Begin_Public_Pred
      fd_set_x_AF(2,2)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_install_constraint_with_x_AF(18,2)
      fd_call_constraint
      fd_install_constraint_with_x_AF(19,2)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(18)

      fd_create_C_frame(18)
      fd_install_ind_def(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(18)

      fd_allocate
      fd_ind_def(1,1)
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
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(19)

      fd_allocate
      fd_ind_def(0,0)
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



#define ASCII_PRED "x>y:(a;b)"
#define PRED       X783E793A28613B6229
#define ARITY      4

Begin_Public_Pred
      fd_set_x_AF(4,4)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(2)
      fd_x_value_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(3)
      fd_install_constraint_with_x_AF(20,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(21,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(22,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(23,4)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(20)

      fd_create_C_frame(20)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(20)

      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(20)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(20)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(20)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(21)

      fd_create_C_frame(21)
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(21)

      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(21)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(21)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(21)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(22)

      fd_create_C_frame(22)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(22)

      fd_allocate
      fd_ind_sigma_def(2,1,2)
      fd_g(1)
      fd_term_parameter(3,3)
      fd_term_mulA_term(2,3)
      fd_range_addA_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(22)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(22)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(22)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(23)

      fd_create_C_frame(23)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(23)

      fd_allocate
      fd_ind_sigma_def(1,0,0)
      fd_l(0)
      fd_term_parameter(3,3)
      fd_term_mulA_term(1,3)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(23)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(23)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(23)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "x>y"
#define PRED       X783E79
#define ARITY      2

Begin_Public_Pred
      fd_set_x_AF(2,2)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_install_constraint_with_x_AF(24,2)
      fd_call_constraint
      fd_install_constraint_with_x_AF(25,2)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(24)

      fd_create_C_frame(24)
      fd_install_ind_def(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(24)

      fd_allocate
      fd_ind_def(1,1)
      fd_g(1)
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
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(25)

      fd_allocate
      fd_ind_def(0,0)
      fd_l(0)
      fd_tell_range(1,0)
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



#define ASCII_PRED "x>=y:(a;b)"
#define PRED       X783E3D793A28613B6229
#define ARITY      4

Begin_Public_Pred
      fd_set_x_AF(4,4)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(2)
      fd_x_value_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(3)
      fd_install_constraint_with_x_AF(26,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(27,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(28,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(29,4)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(26)

      fd_create_C_frame(26)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(26)

      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
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
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(27)

      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(27)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(27)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(27)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(28)

      fd_create_C_frame(28)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(28)

      fd_allocate
      fd_ind_sigma_def(2,1,2)
      fd_ge(1)
      fd_term_parameter(3,3)
      fd_term_mulA_term(2,3)
      fd_range_addA_term(1,2)
      fd_tell_range(0,1)
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
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(29)

      fd_allocate
      fd_ind_sigma_def(1,0,0)
      fd_le(0)
      fd_term_parameter(3,3)
      fd_term_mulA_term(1,3)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)
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



#define ASCII_PRED "x>=y"
#define PRED       X783E3D79
#define ARITY      2

Begin_Public_Pred
      fd_set_x_AF(2,2)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_install_constraint_with_x_AF(30,2)
      fd_call_constraint
      fd_install_constraint_with_x_AF(31,2)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(30)

      fd_create_C_frame(30)
      fd_install_ind_def(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(30)

      fd_allocate
      fd_ind_def(1,1)
      fd_ge(1)
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
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(31)

      fd_allocate
      fd_ind_def(0,0)
      fd_le(0)
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



#define ASCII_PRED "x=y+c:(a;b)"
#define PRED       X783D792B633A28613B6229
#define ARITY      5
Begin_Public_Pred
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_value_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(4)
      fd_install_constraint_with_x_AF(32,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(33,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(34,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(35,5)
      fd_call_constraint
      proceed
End_Pred
#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(32)

      fd_create_C_frame(32)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(32)

      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
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
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(33)

      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(2,3,1,0)
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


Begin_Fd_Install(34)

      fd_create_C_frame(34)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(34)

      fd_allocate
      fd_ind_sigma_def(2,1,2)
      fd_term_parameter(3,3)
      fd_add_range_term(1,3)
      fd_term_parameter(3,4)
      fd_term_mulA_term(2,3)
      fd_range_addA_term(1,2)
      fd_tell_range(0,1)
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
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(35)

      fd_allocate
      fd_ind_sigma_def(1,0,0)
      fd_term_parameter(3,3)
      fd_sub_range_term(0,3)
      fd_term_parameter(3,4)
      fd_term_mulA_term(1,3)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(35)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(35)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(35)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "x=y+c"
#define PRED       X783D792B63
#define ARITY      3

Begin_Public_Pred
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(36,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(37,3)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(36)

      fd_create_C_frame(36)
      fd_install_ind_def(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(36)

      fd_allocate
      fd_ind_def(1,1)
      fd_term_parameter(2,2)
      fd_add_range_term(1,2)
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
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(37)

      fd_allocate
      fd_ind_def(0,0)
      fd_term_parameter(2,2)
      fd_sub_range_term(0,2)
      fd_tell_range(1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(37)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(37)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(37)

      fd_reduce_vars(1)

End_Fd_Reduction



#define ASCII_PRED "x>y+c:(a;b)"
#define PRED       X783E792B633A28613B6229
#define ARITY      5

Begin_Public_Pred
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_value_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(4)
      fd_install_constraint_with_x_AF(38,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(39,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(40,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(41,5)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(38)

      fd_create_C_frame(38)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(38)

      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
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
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(39)

      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(39)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(39)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(39)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(40)

      fd_create_C_frame(40)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(40)

      fd_allocate
      fd_ind_sigma_def(2,1,2)
      fd_term_parameter(3,3)
      fd_add_range_term(1,3)
      fd_g(1)
      fd_term_parameter(3,4)
      fd_term_mulA_term(2,3)
      fd_range_addA_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(40)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(40)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(40)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(41)

      fd_create_C_frame(41)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(41)

      fd_allocate
      fd_ind_sigma_def(1,0,0)
      fd_term_parameter(3,3)
      fd_sub_range_term(0,3)
      fd_l(0)
      fd_term_parameter(3,4)
      fd_term_mulA_term(1,3)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)
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



#define ASCII_PRED "x>y+c"
#define PRED       X783E792B63
#define ARITY      3

Begin_Public_Pred
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(42,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(43,3)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(42)

      fd_create_C_frame(42)
      fd_install_ind_def(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(42)

      fd_allocate
      fd_ind_def(1,1)
      fd_term_parameter(2,2)
      fd_add_range_term(1,2)
      fd_g(1)
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
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(43)

      fd_allocate
      fd_ind_def(0,0)
      fd_term_parameter(2,2)
      fd_sub_range_term(0,2)
      fd_l(0)
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



#define ASCII_PRED "x>=y+c:(a;b)"
#define PRED       X783E3D792B633A28613B6229
#define ARITY      5

Begin_Public_Pred
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_value_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(4)
      fd_install_constraint_with_x_AF(44,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(45,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(46,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(47,5)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(44)

      fd_create_C_frame(44)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(44)

      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_parameter(1,1)
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
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(45)

      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
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
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(46)

      fd_allocate
      fd_ind_sigma_def(2,1,2)
      fd_term_parameter(3,3)
      fd_add_range_term(1,3)
      fd_ge(1)
      fd_term_parameter(3,4)
      fd_term_mulA_term(2,3)
      fd_range_addA_term(1,2)
      fd_tell_range(0,1)
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


Begin_Fd_Install(47)

      fd_create_C_frame(47)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(47)

      fd_allocate
      fd_ind_sigma_def(1,0,0)
      fd_term_parameter(3,3)
      fd_sub_range_term(0,3)
      fd_le(0)
      fd_term_parameter(3,4)
      fd_term_mulA_term(1,3)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(47)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(47)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(47)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "x>=y+c"
#define PRED       X783E3D792B63
#define ARITY      3

Begin_Public_Pred
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(48,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(49,3)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(48)

      fd_create_C_frame(48)
      fd_install_ind_def(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(48)

      fd_allocate
      fd_ind_def(1,1)
      fd_term_parameter(2,2)
      fd_add_range_term(1,2)
      fd_ge(1)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(48)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(48)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(48)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(49)

      fd_create_C_frame(49)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(49)

      fd_allocate
      fd_ind_def(0,0)
      fd_term_parameter(2,2)
      fd_sub_range_term(0,2)
      fd_le(0)
      fd_tell_range(1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(49)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(49)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(49)

      fd_reduce_vars(1)

End_Fd_Reduction



#define ASCII_PRED "x=y+z:(a;b)"
#define PRED       X783D792B7A3A28613B6229
#define ARITY      5

Begin_Public_Pred
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(4)
      fd_install_constraint_with_x_AF(50,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(51,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(52,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(53,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(54,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(55,5)
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

      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
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
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(51)

      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(51)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(51)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(51)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(52)

      fd_create_C_frame(52)
      fd_static_constraint(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(52)

      fd_integer(2,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(3,2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(52)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(52)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(52)

      fd_reduce_vars(3)

End_Fd_Reduction


Begin_Fd_Install(53)

      fd_create_C_frame(53)
      fd_install_ind_def(2)
      fd_install_ind_def(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(53)

      fd_allocate
      fd_ind_sigma_def(2,1,2)
      fd_ind_sigma_def(3,4,3)
      fd_add_range_range(1,4)
      fd_term_mulA_term(2,3)
      fd_term_parameter(3,4)
      fd_term_mulA_term(2,3)
      fd_range_addA_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(53)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(53)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(53)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(54)

      fd_create_C_frame(54)
      fd_install_ind_def(0)
      fd_install_ind_def(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(54)

      fd_allocate
      fd_ind_sigma_def(1,0,0)
      fd_ind_sigma_def(3,4,3)
      fd_sub_range_range(0,4)
      fd_term_mulA_term(1,3)
      fd_term_parameter(3,4)
      fd_term_mulA_term(1,3)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(54)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(54)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(54)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(55)

      fd_create_C_frame(55)
      fd_install_ind_def(0)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(55)

      fd_allocate
      fd_ind_sigma_def(1,0,0)
      fd_ind_sigma_def(2,4,2)
      fd_sub_range_range(0,4)
      fd_term_mulA_term(1,2)
      fd_term_parameter(2,4)
      fd_term_mulA_term(1,2)
      fd_range_addA_term(0,1)
      fd_tell_range(3,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(55)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(55)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(55)

      fd_reduce_vars(3)

End_Fd_Reduction



#define ASCII_PRED "x=y+z"
#define PRED       X783D792B7A
#define ARITY      3

Begin_Public_Pred
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_install_constraint_with_x_AF(56,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(57,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(58,3)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(56)

      fd_create_C_frame(56)
      fd_install_ind_def(1)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(56)

      fd_allocate
      fd_ind_def(1,1)
      fd_ind_def(2,2)
      fd_add_range_range(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(56)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(56)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(56)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(57)

      fd_create_C_frame(57)
      fd_install_ind_def(0)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(57)

      fd_allocate
      fd_ind_def(0,0)
      fd_ind_def(2,2)
      fd_sub_range_range(0,2)
      fd_tell_range(1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(57)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(57)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(57)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(58)

      fd_create_C_frame(58)
      fd_install_ind_def(0)
      fd_install_ind_def(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(58)

      fd_allocate
      fd_ind_def(0,0)
      fd_ind_def(1,1)
      fd_sub_range_range(0,1)
      fd_tell_range(2,0)
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



#define ASCII_PRED "x>y+z:(a;b)"
#define PRED       X783E792B7A3A28613B6229
#define ARITY      5

Begin_Public_Pred
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(4)
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
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(59)

      fd_create_C_frame(59)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(59)

      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(59)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(59)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(59)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(60)

      fd_create_C_frame(60)
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(60)

      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(60)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(60)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(60)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(61)

      fd_create_C_frame(61)
      fd_static_constraint(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(61)

      fd_integer(2,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(3,2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(61)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(61)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(61)

      fd_reduce_vars(3)

End_Fd_Reduction


Begin_Fd_Install(62)

      fd_create_C_frame(62)
      fd_install_ind_def(2)
      fd_install_ind_def(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(62)

      fd_allocate
      fd_ind_sigma_def(2,1,2)
      fd_ind_sigma_def(3,4,3)
      fd_add_range_range(1,4)
      fd_g(1)
      fd_term_mulA_term(2,3)
      fd_term_parameter(3,4)
      fd_term_mulA_term(2,3)
      fd_range_addA_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(62)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(62)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(62)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(63)

      fd_create_C_frame(63)
      fd_install_ind_def(0)
      fd_install_ind_def(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(63)

      fd_allocate
      fd_ind_sigma_def(1,0,0)
      fd_ind_sigma_def(3,4,3)
      fd_sub_range_range(0,4)
      fd_l(0)
      fd_term_mulA_term(1,3)
      fd_term_parameter(3,4)
      fd_term_mulA_term(1,3)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(63)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(63)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(63)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(64)

      fd_create_C_frame(64)
      fd_install_ind_def(0)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(64)

      fd_allocate
      fd_ind_sigma_def(1,0,0)
      fd_ind_sigma_def(2,4,2)
      fd_sub_range_range(0,4)
      fd_l(0)
      fd_term_mulA_term(1,2)
      fd_term_parameter(2,4)
      fd_term_mulA_term(1,2)
      fd_range_addA_term(0,1)
      fd_tell_range(3,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(64)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(64)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(64)

      fd_reduce_vars(3)

End_Fd_Reduction



#define ASCII_PRED "x>y+z"
#define PRED       X783E792B7A
#define ARITY      3

Begin_Public_Pred
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_install_constraint_with_x_AF(65,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(66,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(67,3)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(65)

      fd_create_C_frame(65)
      fd_install_ind_def(1)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(65)

      fd_allocate
      fd_ind_def(1,1)
      fd_ind_def(2,2)
      fd_add_range_range(1,2)
      fd_g(1)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(65)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(65)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(65)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(66)

      fd_create_C_frame(66)
      fd_install_ind_def(0)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(66)

      fd_allocate
      fd_ind_def(0,0)
      fd_ind_def(2,2)
      fd_sub_range_range(0,2)
      fd_l(0)
      fd_tell_range(1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(66)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(66)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(66)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(67)

      fd_create_C_frame(67)
      fd_install_ind_def(0)
      fd_install_ind_def(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(67)

      fd_allocate
      fd_ind_def(0,0)
      fd_ind_def(1,1)
      fd_sub_range_range(0,1)
      fd_l(0)
      fd_tell_range(2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(67)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(67)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(67)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "x>=y+z:(a;b)"
#define PRED       X783E3D792B7A3A28613B6229
#define ARITY      5

Begin_Public_Pred
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(4)
      fd_install_constraint_with_x_AF(68,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(69,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(70,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(71,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(72,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(73,5)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(68)

      fd_create_C_frame(68)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(68)

      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(68)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(68)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(68)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(69)

      fd_create_C_frame(69)
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(69)

      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
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
      fd_static_constraint(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(70)

      fd_integer(2,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(3,2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(70)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(70)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(70)

      fd_reduce_vars(3)

End_Fd_Reduction


Begin_Fd_Install(71)

      fd_create_C_frame(71)
      fd_install_ind_def(2)
      fd_install_ind_def(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(71)

      fd_allocate
      fd_ind_sigma_def(2,1,2)
      fd_ind_sigma_def(3,4,3)
      fd_add_range_range(1,4)
      fd_ge(1)
      fd_term_mulA_term(2,3)
      fd_term_parameter(3,4)
      fd_term_mulA_term(2,3)
      fd_range_addA_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(71)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(71)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(71)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(72)

      fd_create_C_frame(72)
      fd_install_ind_def(0)
      fd_install_ind_def(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(72)

      fd_allocate
      fd_ind_sigma_def(1,0,0)
      fd_ind_sigma_def(3,4,3)
      fd_sub_range_range(0,4)
      fd_le(0)
      fd_term_mulA_term(1,3)
      fd_term_parameter(3,4)
      fd_term_mulA_term(1,3)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)
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


Begin_Fd_Install(73)

      fd_create_C_frame(73)
      fd_install_ind_def(0)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(73)

      fd_allocate
      fd_ind_sigma_def(1,0,0)
      fd_ind_sigma_def(2,4,2)
      fd_sub_range_range(0,4)
      fd_le(0)
      fd_term_mulA_term(1,2)
      fd_term_parameter(2,4)
      fd_term_mulA_term(1,2)
      fd_range_addA_term(0,1)
      fd_tell_range(3,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(73)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(73)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(73)

      fd_reduce_vars(3)

End_Fd_Reduction



#define ASCII_PRED "x>=y+z"
#define PRED       X783E3D792B7A
#define ARITY      3

Begin_Public_Pred
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_install_constraint_with_x_AF(74,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(75,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(76,3)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(74)

      fd_create_C_frame(74)
      fd_install_ind_def(1)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(74)

      fd_allocate
      fd_ind_def(1,1)
      fd_ind_def(2,2)
      fd_add_range_range(1,2)
      fd_ge(1)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(74)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(74)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(74)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(75)

      fd_create_C_frame(75)
      fd_install_ind_def(0)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(75)

      fd_allocate
      fd_ind_def(0,0)
      fd_ind_def(2,2)
      fd_sub_range_range(0,2)
      fd_le(0)
      fd_tell_range(1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(75)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(75)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(75)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(76)

      fd_create_C_frame(76)
      fd_install_ind_def(0)
      fd_install_ind_def(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(76)

      fd_allocate
      fd_ind_def(0,0)
      fd_ind_def(1,1)
      fd_sub_range_range(0,1)
      fd_le(0)
      fd_tell_range(2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(76)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(76)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(76)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "x=cy:(a;b)"
#define PRED       X783D63793A28613B6229
#define ARITY      5

Begin_Public_Pred
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_value_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(4)
      fd_install_constraint_with_x_AF(77,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(78,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(79,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(80,5)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(77)

      fd_create_C_frame(77)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(77)

      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(77)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(77)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(77)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(78)

      fd_create_C_frame(78)
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(78)

      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(78)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(78)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(78)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(79)

      fd_create_C_frame(79)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(79)

      fd_allocate
      fd_ind_sigma_def(2,1,2)
      fd_term_parameter(3,3)
      fd_mul_range_term(1,3)
      fd_term_parameter(3,4)
      fd_term_mulA_term(2,3)
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
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(80)

      fd_allocate
      fd_ind_sigma_def(1,0,0)
      fd_term_parameter(3,3)
      fd_div_range_term(0,3)
      fd_term_parameter(3,4)
      fd_term_mulA_term(1,3)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)
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



#define ASCII_PRED "x=cy"
#define PRED       X783D6379
#define ARITY      3

Begin_Public_Pred
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(1)
      fd_install_constraint_with_x_AF(81,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(82,3)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(81)

      fd_create_C_frame(81)
      fd_install_ind_def(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(81)

      fd_allocate
      fd_ind_def(1,1)
      fd_term_parameter(2,2)
      fd_mul_range_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(81)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(81)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(81)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(82)

      fd_create_C_frame(82)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(82)

      fd_allocate
      fd_ind_def(0,0)
      fd_term_parameter(2,2)
      fd_div_range_term(0,2)
      fd_tell_range(1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(82)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(82)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(82)

      fd_reduce_vars(1)

End_Fd_Reduction



#define ASCII_PRED "x>cy:(a;b)"
#define PRED       X783E63793A28613B6229
#define ARITY      5

Begin_Public_Pred
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_value_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(4)
      fd_install_constraint_with_x_AF(83,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(84,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(85,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(86,5)
      fd_call_constraint
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

      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
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


Begin_Fd_Install(84)

      fd_create_C_frame(84)
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(84)

      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(84)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(84)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(84)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(85)

      fd_create_C_frame(85)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(85)

      fd_allocate
      fd_ind_sigma_def(2,1,2)
      fd_term_parameter(3,3)
      fd_mul_range_term(1,3)
      fd_g(1)
      fd_term_parameter(3,4)
      fd_term_mulA_term(2,3)
      fd_range_addA_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(85)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(85)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(85)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(86)

      fd_create_C_frame(86)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(86)

      fd_allocate
      fd_ind_sigma_def(1,0,0)
      fd_term_parameter(3,3)
      fd_div_range_term(0,3)
      fd_l(0)
      fd_term_parameter(3,4)
      fd_term_mulA_term(1,3)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(86)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(86)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(86)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "x>cy"
#define PRED       X783E6379
#define ARITY      3

Begin_Public_Pred
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(1)
      fd_install_constraint_with_x_AF(87,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(88,3)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(87)

      fd_create_C_frame(87)
      fd_install_ind_def(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(87)

      fd_allocate
      fd_ind_def(1,1)
      fd_term_parameter(2,2)
      fd_mul_range_term(1,2)
      fd_g(1)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(87)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(87)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(87)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(88)

      fd_create_C_frame(88)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(88)

      fd_allocate
      fd_ind_def(0,0)
      fd_term_parameter(2,2)
      fd_div_range_term(0,2)
      fd_l(0)
      fd_tell_range(1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(88)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(88)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(88)

      fd_reduce_vars(1)

End_Fd_Reduction



#define ASCII_PRED "x>=cy:(a;b)"
#define PRED       X783E3D63793A28613B6229
#define ARITY      5

Begin_Public_Pred
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_value_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(1)
      fd_x_term_parameter_in_A_frame(4)
      fd_install_constraint_with_x_AF(89,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(90,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(91,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(92,5)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(89)

      fd_create_C_frame(89)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(89)

      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(89)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(89)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(89)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(90)

      fd_create_C_frame(90)
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(90)

      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(90)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(90)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(90)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(91)

      fd_create_C_frame(91)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(91)

      fd_allocate
      fd_ind_sigma_def(2,1,2)
      fd_term_parameter(3,3)
      fd_mul_range_term(1,3)
      fd_ge(1)
      fd_term_parameter(3,4)
      fd_term_mulA_term(2,3)
      fd_range_addA_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(91)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(91)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(91)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(92)

      fd_create_C_frame(92)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(92)

      fd_allocate
      fd_ind_sigma_def(1,0,0)
      fd_term_parameter(3,3)
      fd_div_range_term(0,3)
      fd_le(0)
      fd_term_parameter(3,4)
      fd_term_mulA_term(1,3)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(92)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(92)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(92)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "x>=cy"
#define PRED       X783E3D6379
#define ARITY      3

Begin_Public_Pred
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(1)
      fd_install_constraint_with_x_AF(93,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(94,3)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(93)

      fd_create_C_frame(93)
      fd_install_ind_def(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(93)

      fd_allocate
      fd_ind_def(1,1)
      fd_term_parameter(2,2)
      fd_mul_range_term(1,2)
      fd_ge(1)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(93)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(93)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(93)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(94)

      fd_create_C_frame(94)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(94)

      fd_allocate
      fd_ind_def(0,0)
      fd_term_parameter(2,2)
      fd_div_range_term(0,2)
      fd_le(0)
      fd_tell_range(1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(94)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(94)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(94)

      fd_reduce_vars(1)

End_Fd_Reduction



#define ASCII_PRED "x=yz:(a;b)"
#define PRED       X783D797A3A28613B6229
#define ARITY      5

Begin_Public_Pred
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(4)
      fd_install_constraint_with_x_AF(95,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(96,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(97,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(98,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(99,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(100,5)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(95)

      fd_create_C_frame(95)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(95)

      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(95)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(95)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(95)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(96)

      fd_create_C_frame(96)
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(96)

      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(96)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(96)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(96)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(97)

      fd_create_C_frame(97)
      fd_static_constraint(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(97)

      fd_integer(2,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(3,2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(97)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(97)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(97)

      fd_reduce_vars(3)

End_Fd_Reduction


Begin_Fd_Install(98)

      fd_create_C_frame(98)
      fd_install_ind_def(2)
      fd_install_ind_def(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(98)

      fd_allocate
      fd_ind_sigma_def(2,1,2)
      fd_ind_sigma_def(3,4,3)
      fd_mul_range_range(1,4)
      fd_term_mulA_term(2,3)
      fd_term_parameter(3,4)
      fd_term_mulA_term(2,3)
      fd_range_addA_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(98)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(98)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(98)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(99)

      fd_create_C_frame(99)
      fd_install_ind_def(0)
      fd_install_ind_def(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(99)

      fd_allocate
      fd_ind_sigma_def(1,0,0)
      fd_ind_sigma_def(3,4,3)
      fd_div_range_range(0,4)
      fd_term_mulA_term(1,3)
      fd_term_parameter(3,4)
      fd_term_mulA_term(1,3)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(99)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(99)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(99)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(100)

      fd_create_C_frame(100)
      fd_install_ind_def(0)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(100)

      fd_allocate
      fd_ind_sigma_def(1,0,0)
      fd_ind_sigma_def(2,4,2)
      fd_div_range_range(0,4)
      fd_term_mulA_term(1,2)
      fd_term_parameter(2,4)
      fd_term_mulA_term(1,2)
      fd_range_addA_term(0,1)
      fd_tell_range(3,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(100)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(100)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(100)

      fd_reduce_vars(3)

End_Fd_Reduction



#define ASCII_PRED "x=yz"
#define PRED       X783D797A
#define ARITY      3

Begin_Public_Pred
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_install_constraint_with_x_AF(101,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(102,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(103,3)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(101)

      fd_create_C_frame(101)
      fd_install_ind_def(1)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(101)

      fd_allocate
      fd_ind_def(1,1)
      fd_ind_def(2,2)
      fd_mul_range_range(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(101)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(101)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(101)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(102)

      fd_create_C_frame(102)
      fd_install_ind_def(0)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(102)

      fd_allocate
      fd_ind_def(0,0)
      fd_ind_def(2,2)
      fd_div_range_range(0,2)
      fd_tell_range(1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(102)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(102)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(102)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(103)

      fd_create_C_frame(103)
      fd_install_ind_def(0)
      fd_install_ind_def(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(103)

      fd_allocate
      fd_ind_def(0,0)
      fd_ind_def(1,1)
      fd_div_range_range(0,1)
      fd_tell_range(2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(103)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(103)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(103)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "x>yz:(a;b)"
#define PRED       X783E797A3A28613B6229
#define ARITY      5

Begin_Public_Pred
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(4)
      fd_install_constraint_with_x_AF(104,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(105,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(106,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(107,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(108,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(109,5)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(104)

      fd_create_C_frame(104)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(104)

      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(104)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(104)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(104)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(105)

      fd_create_C_frame(105)
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(105)

      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(105)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(105)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(105)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(106)

      fd_create_C_frame(106)
      fd_static_constraint(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(106)

      fd_integer(2,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(3,2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(106)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(106)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(106)

      fd_reduce_vars(3)

End_Fd_Reduction


Begin_Fd_Install(107)

      fd_create_C_frame(107)
      fd_install_ind_def(2)
      fd_install_ind_def(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(107)

      fd_allocate
      fd_ind_sigma_def(2,1,2)
      fd_ind_sigma_def(3,4,3)
      fd_mul_range_range(1,4)
      fd_g(1)
      fd_term_mulA_term(2,3)
      fd_term_parameter(3,4)
      fd_term_mulA_term(2,3)
      fd_range_addA_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(107)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(107)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(107)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(108)

      fd_create_C_frame(108)
      fd_install_ind_def(0)
      fd_install_ind_def(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(108)

      fd_allocate
      fd_ind_sigma_def(1,0,0)
      fd_ind_sigma_def(3,4,3)
      fd_div_range_range(0,4)
      fd_l(0)
      fd_term_mulA_term(1,3)
      fd_term_parameter(3,4)
      fd_term_mulA_term(1,3)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(108)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(108)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(108)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(109)

      fd_create_C_frame(109)
      fd_install_ind_def(0)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(109)

      fd_allocate
      fd_ind_sigma_def(1,0,0)
      fd_ind_sigma_def(2,4,2)
      fd_div_range_range(0,4)
      fd_l(0)
      fd_term_mulA_term(1,2)
      fd_term_parameter(2,4)
      fd_term_mulA_term(1,2)
      fd_range_addA_term(0,1)
      fd_tell_range(3,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(109)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(109)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(109)

      fd_reduce_vars(3)

End_Fd_Reduction



#define ASCII_PRED "x>yz"
#define PRED       X783E797A
#define ARITY      3

Begin_Public_Pred
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_install_constraint_with_x_AF(110,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(111,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(112,3)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(110)

      fd_create_C_frame(110)
      fd_install_ind_def(1)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(110)

      fd_allocate
      fd_ind_def(1,1)
      fd_ind_def(2,2)
      fd_mul_range_range(1,2)
      fd_g(1)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(110)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(110)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(110)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(111)

      fd_create_C_frame(111)
      fd_install_ind_def(0)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(111)

      fd_allocate
      fd_ind_def(0,0)
      fd_ind_def(2,2)
      fd_div_range_range(0,2)
      fd_l(0)
      fd_tell_range(1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(111)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(111)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(111)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(112)

      fd_create_C_frame(112)
      fd_install_ind_def(0)
      fd_install_ind_def(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(112)

      fd_allocate
      fd_ind_def(0,0)
      fd_ind_def(1,1)
      fd_div_range_range(0,1)
      fd_l(0)
      fd_tell_range(2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(112)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(112)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(112)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "x>=yz:(a;b)"
#define PRED       X783E3D797A3A28613B6229
#define ARITY      5

Begin_Public_Pred
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(4)
      fd_install_constraint_with_x_AF(113,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(114,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(115,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(116,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(117,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(118,5)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(113)

      fd_create_C_frame(113)
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(113)

      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_parameter(1,1)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(113)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(113)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(113)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(114)

      fd_create_C_frame(114)
      fd_static_constraint(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(114)

      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(114)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(114)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(114)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(115)

      fd_create_C_frame(115)
      fd_static_constraint(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(115)

      fd_integer(2,0)
      fd_integer(1,infinity)
      fd_term_parameter(0,1)
      fd_tell_interval_value(3,2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(115)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(115)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(115)

      fd_reduce_vars(3)

End_Fd_Reduction


Begin_Fd_Install(116)

      fd_create_C_frame(116)
      fd_install_ind_def(2)
      fd_install_ind_def(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(116)

      fd_allocate
      fd_ind_sigma_def(2,1,2)
      fd_ind_sigma_def(3,4,3)
      fd_mul_range_range(1,4)
      fd_ge(1)
      fd_term_mulA_term(2,3)
      fd_term_parameter(3,4)
      fd_term_mulA_term(2,3)
      fd_range_addA_term(1,2)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(116)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(116)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(116)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(117)

      fd_create_C_frame(117)
      fd_install_ind_def(0)
      fd_install_ind_def(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(117)

      fd_allocate
      fd_ind_sigma_def(1,0,0)
      fd_ind_sigma_def(3,4,3)
      fd_div_range_range(0,4)
      fd_le(0)
      fd_term_mulA_term(1,3)
      fd_term_parameter(3,4)
      fd_term_mulA_term(1,3)
      fd_range_addA_term(0,1)
      fd_tell_range(2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(117)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(117)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(117)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(118)

      fd_create_C_frame(118)
      fd_install_ind_def(0)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(118)

      fd_allocate
      fd_ind_sigma_def(1,0,0)
      fd_ind_sigma_def(2,4,2)
      fd_div_range_range(0,4)
      fd_le(0)
      fd_term_mulA_term(1,2)
      fd_term_parameter(2,4)
      fd_term_mulA_term(1,2)
      fd_range_addA_term(0,1)
      fd_tell_range(3,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(118)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(118)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(118)

      fd_reduce_vars(3)

End_Fd_Reduction



#define ASCII_PRED "x>=yz"
#define PRED       X783E3D797A
#define ARITY      3

Begin_Public_Pred
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_install_constraint_with_x_AF(119,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(120,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(121,3)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(119)

      fd_create_C_frame(119)
      fd_install_ind_def(1)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(119)

      fd_allocate
      fd_ind_def(1,1)
      fd_ind_def(2,2)
      fd_mul_range_range(1,2)
      fd_ge(1)
      fd_tell_range(0,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(119)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(119)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(119)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(120)

      fd_create_C_frame(120)
      fd_install_ind_def(0)
      fd_install_ind_def(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(120)

      fd_allocate
      fd_ind_def(0,0)
      fd_ind_def(2,2)
      fd_div_range_range(0,2)
      fd_le(0)
      fd_tell_range(1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(120)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(120)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(120)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(121)

      fd_create_C_frame(121)
      fd_install_ind_def(0)
      fd_install_ind_def(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(121)

      fd_allocate
      fd_ind_def(0,0)
      fd_ind_def(1,1)
      fd_div_range_range(0,1)
      fd_le(0)
      fd_tell_range(2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(121)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(121)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(121)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "pac xy=z"
#define PRED       X7061632078793D7A
#define ARITY      3

Begin_Public_Pred
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_install_constraint_with_x_AF(122,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(123,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(124,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(125,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(126,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(127,3)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(122)

      fd_create_C_frame(122)
      fd_install_ind_sigma(1)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(122)

      fd_ind_sigma(1,1)
      fd_ind_sigma(4,2)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_mulA_term(1,4)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(122)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(122)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(122)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(123)

      fd_create_C_frame(123)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(123)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,2)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(1,3,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(123)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(123)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(123)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(124)

      fd_create_C_frame(124)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(124)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,1)
      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(124)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(124)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(124)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(125)

      fd_create_C_frame(125)
      fd_install_ind_min_max(2)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(125)

      fd_ind_min_max(6,4,2)
      fd_ind_min_max(3,5,1)
      fd_term_fct(ceil_div0,2,arg_2(tr(6),tr(5)))
      fd_term_fct(floor_div0,1,arg_2(tr(4),tr(3)))
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(125)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(125)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(125)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(126)

      fd_create_C_frame(126)
      fd_install_ind_min_max(2)
      fd_install_ind_min_max(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(126)

      fd_ind_min_max(6,4,2)
      fd_ind_min_max(3,5,0)
      fd_term_fct(ceil_div0,2,arg_2(tr(6),tr(5)))
      fd_term_fct(floor_div0,0,arg_2(tr(4),tr(3)))
      fd_tell_interval(1,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(126)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(126)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(126)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(127)

      fd_create_C_frame(127)
      fd_install_ind_min_max(0)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(127)

      fd_ind_min_max(1,0,0)
      fd_ind_min_max(4,3,1)
      fd_mul_term_term(1,4)
      fd_mul_term_term(0,3)
      fd_tell_interval(2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(127)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(127)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(127)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "pac x=y"
#define PRED       X70616320783D79
#define ARITY      2

Begin_Public_Pred
      fd_set_x_AF(2,2)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_install_constraint_with_x_AF(128,2)
      fd_call_constraint
      fd_install_constraint_with_x_AF(129,2)
      fd_call_constraint
      fd_install_constraint_with_x_AF(130,2)
      fd_call_constraint
      fd_install_constraint_with_x_AF(131,2)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(128)

      fd_create_C_frame(128)
      fd_install_ind_sigma(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(128)

      fd_ind_sigma(1,1)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(128)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(128)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(128)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(129)

      fd_create_C_frame(129)
      fd_install_ind_sigma(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(129)

      fd_ind_sigma(0,0)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_tell_interval_value(1,3,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(129)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(129)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(129)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(130)

      fd_create_C_frame(130)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(130)

      fd_ind_min_max(2,1,1)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(130)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(130)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(130)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(131)

      fd_create_C_frame(131)
      fd_install_ind_min_max(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(131)

      fd_ind_min_max(2,0,0)
      fd_tell_interval(1,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(131)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(131)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(131)

      fd_reduce_vars(1)

End_Fd_Reduction



#define ASCII_PRED "pac x<>y"
#define PRED       X70616320783C3E79
#define ARITY      2

Begin_Public_Pred
      fd_set_x_AF(2,2)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_install_constraint_with_x_AF(132,2)
      fd_call_constraint
      fd_install_constraint_with_x_AF(133,2)
      fd_call_constraint
      fd_install_constraint_with_x_AF(134,2)
      fd_call_constraint
      fd_install_constraint_with_x_AF(135,2)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(132)

      fd_create_C_frame(132)
      fd_install_ind_sigma(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(132)

      fd_ind_sigma(1,1)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(132)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(132)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(132)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(133)

      fd_create_C_frame(133)
      fd_install_ind_sigma(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(133)

      fd_ind_sigma(0,0)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_tell_interval_value(1,3,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(133)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(133)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(133)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(134)

      fd_create_C_frame(134)
      fd_install_ind_val(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(134)

      fd_allocate
      fd_ind_val(1,1,1)
      fd_comp_term(1,1)
      fd_tell_range(0,1)

   Fd_Label(1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(134)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(134)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(134)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(135)

      fd_create_C_frame(135)
      fd_install_ind_val(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(135)

      fd_allocate
      fd_ind_val(0,0,1)
      fd_comp_term(0,0)
      fd_tell_range(1,0)

   Fd_Label(1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(135)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(135)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(135)

      fd_reduce_vars(1)

End_Fd_Reduction



#define ASCII_PRED "pac x>=y"
#define PRED       X70616320783E3D79
#define ARITY      2

Begin_Public_Pred
      fd_set_x_AF(2,2)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_install_constraint_with_x_AF(136,2)
      fd_call_constraint
      fd_install_constraint_with_x_AF(137,2)
      fd_call_constraint
      fd_install_constraint_with_x_AF(138,2)
      fd_call_constraint
      fd_install_constraint_with_x_AF(139,2)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(136)

      fd_create_C_frame(136)
      fd_install_ind_sigma(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(136)

      fd_ind_sigma(1,1)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(136)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(136)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(136)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(137)

      fd_create_C_frame(137)
      fd_install_ind_sigma(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(137)

      fd_ind_sigma(0,0)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_tell_interval_value(1,3,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(137)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(137)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(137)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(138)

      fd_create_C_frame(138)
      fd_install_ind_min(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(138)

      fd_ind_min(2,1)
      fd_integer(1,infinity)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(138)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(138)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(138)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(139)

      fd_create_C_frame(139)
      fd_install_ind_max(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(139)

      fd_ind_max(0,0)
      fd_integer(2,0)
      fd_tell_interval(1,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(139)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(139)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(139)

      fd_reduce_vars(1)

End_Fd_Reduction



#define ASCII_PRED "pac x>y"
#define PRED       X70616320783E79
#define ARITY      2

Begin_Public_Pred
      fd_set_x_AF(2,2)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_install_constraint_with_x_AF(140,2)
      fd_call_constraint
      fd_install_constraint_with_x_AF(141,2)
      fd_call_constraint
      fd_install_constraint_with_x_AF(142,2)
      fd_call_constraint
      fd_install_constraint_with_x_AF(143,2)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(140)

      fd_create_C_frame(140)
      fd_install_ind_sigma(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(140)

      fd_ind_sigma(1,1)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(140)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(140)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(140)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(141)

      fd_create_C_frame(141)
      fd_install_ind_sigma(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(141)

      fd_ind_sigma(0,0)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_tell_interval_value(1,3,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(141)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(141)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(141)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(142)

      fd_create_C_frame(142)
      fd_install_ind_min(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(142)

      fd_ind_min(2,1)
      fd_integer(1,1)
      fd_add_term_term(2,1)
      fd_integer(1,infinity)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(142)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(142)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(142)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(143)

      fd_create_C_frame(143)
      fd_install_ind_max(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(143)

      fd_ind_max(0,0)
      fd_integer(2,0)
      fd_integer(3,1)
      fd_sub_term_term(0,3)
      fd_tell_interval(1,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(143)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(143)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(143)

      fd_reduce_vars(1)

End_Fd_Reduction



#define ASCII_PRED "pac x+c=y"
#define PRED       X70616320782B633D79
#define ARITY      3

Begin_Public_Pred
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(1)
      fd_install_constraint_with_x_AF(144,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(145,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(146,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(147,3)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(144)

      fd_create_C_frame(144)
      fd_install_ind_sigma(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(144)

      fd_ind_sigma(1,1)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(144)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(144)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(144)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(145)

      fd_create_C_frame(145)
      fd_install_ind_sigma(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(145)

      fd_ind_sigma(0,0)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_tell_interval_value(1,3,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(145)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(145)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(145)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(146)

      fd_create_C_frame(146)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(146)

      fd_ind_min_max(2,1,1)
      fd_term_parameter(3,2)
      fd_sub_term_term(2,3)
      fd_sub_term_term(1,3)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(146)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(146)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(146)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(147)

      fd_create_C_frame(147)
      fd_install_ind_min_max(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(147)

      fd_ind_min_max(2,0,0)
      fd_term_parameter(3,2)
      fd_add_term_term(2,3)
      fd_add_term_term(0,3)
      fd_tell_interval(1,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(147)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(147)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(147)

      fd_reduce_vars(1)

End_Fd_Reduction



#define ASCII_PRED "pac ax=y"
#define PRED       X7061632061783D79
#define ARITY      3

Begin_Public_Pred
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(0)
      fd_install_constraint_with_x_AF(148,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(149,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(150,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(151,3)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(148)

      fd_create_C_frame(148)
      fd_install_ind_sigma(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(148)

      fd_ind_sigma(1,1)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(148)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(148)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(148)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(149)

      fd_create_C_frame(149)
      fd_install_ind_sigma(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(149)

      fd_ind_sigma(0,0)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_tell_interval_value(1,3,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(149)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(149)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(149)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(150)

      fd_create_C_frame(150)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(150)

      fd_ind_min_max(2,1,1)
      fd_term_parameter(3,2)
      fd_ceil_div_term_term(2,3)
      fd_floor_div_term_term(1,3)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(150)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(150)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(150)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(151)

      fd_create_C_frame(151)
      fd_install_ind_min_max(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(151)

      fd_ind_min_max(2,0,0)
      fd_term_parameter(3,2)
      fd_mul_term_term(2,3)
      fd_mul_term_term(0,3)
      fd_tell_interval(1,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(151)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(151)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(151)

      fd_reduce_vars(1)

End_Fd_Reduction



#define ASCII_PRED "pac ax+c=y"
#define PRED       X7061632061782B633D79
#define ARITY      4

Begin_Public_Pred
      fd_set_x_AF(4,4)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(3)
      fd_x_term_parameter_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(0)
      fd_install_constraint_with_x_AF(152,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(153,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(154,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(155,4)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(152)

      fd_create_C_frame(152)
      fd_install_ind_sigma(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(152)

      fd_ind_sigma(1,1)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(152)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(152)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(152)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(153)

      fd_create_C_frame(153)
      fd_install_ind_sigma(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(153)

      fd_ind_sigma(0,0)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_tell_interval_value(1,3,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(153)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(153)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(153)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(154)

      fd_create_C_frame(154)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(154)

      fd_ind_min_max(2,1,1)
      fd_term_parameter(4,2)
      fd_sub_term_term(2,4)
      fd_term_parameter(3,3)
      fd_ceil_div_term_term(2,3)
      fd_sub_term_term(1,4)
      fd_floor_div_term_term(1,3)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(154)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(154)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(154)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(155)

      fd_create_C_frame(155)
      fd_install_ind_min_max(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(155)

      fd_ind_min_max(2,0,0)
      fd_term_parameter(4,3)
      fd_mul_term_term(2,4)
      fd_term_parameter(3,2)
      fd_add_term_term(2,3)
      fd_mul_term_term(0,4)
      fd_add_term_term(0,3)
      fd_tell_interval(1,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(155)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(155)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(155)

      fd_reduce_vars(1)

End_Fd_Reduction



#define ASCII_PRED "pac ax+y+c=z"
#define PRED       X7061632061782B792B633D7A
#define ARITY      5

Begin_Public_Pred
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_x_value_in_A_frame(4)
      fd_x_term_parameter_in_A_frame(3)
      fd_x_term_parameter_in_A_frame(0)
      fd_install_constraint_with_x_AF(156,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(157,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(158,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(159,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(160,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(161,5)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(156)

      fd_create_C_frame(156)
      fd_install_ind_sigma(1)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(156)

      fd_ind_sigma(1,1)
      fd_ind_sigma(4,2)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_mulA_term(1,4)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(156)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(156)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(156)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(157)

      fd_create_C_frame(157)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(157)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,2)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(1,3,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(157)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(157)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(157)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(158)

      fd_create_C_frame(158)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(158)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,1)
      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(158)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(158)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(158)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(159)

      fd_create_C_frame(159)
      fd_install_ind_min_max(2)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(159)

      fd_ind_min_max(2,1,2)
      fd_ind_min_max(5,3,1)
      fd_sub_term_term(2,3)
      fd_term_parameter(4,3)
      fd_sub_term_term(2,4)
      fd_term_parameter(3,4)
      fd_ceil_div_term_term(2,3)
      fd_sub_term_term(1,5)
      fd_sub_term_term(1,4)
      fd_floor_div_term_term(1,3)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(159)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(159)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(159)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(160)

      fd_create_C_frame(160)
      fd_install_ind_min_max(2)
      fd_install_ind_min_max(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(160)

      fd_ind_min_max(2,0,2)
      fd_ind_min_max(5,6,0)
      fd_term_parameter(4,4)
      fd_term_copy(3,4)
      fd_mul_term_term(3,6)
      fd_sub_term_term(2,3)
      fd_term_parameter(3,3)
      fd_sub_term_term(2,3)
      fd_mul_term_term(4,5)
      fd_sub_term_term(0,4)
      fd_sub_term_term(0,3)
      fd_tell_interval(1,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(160)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(160)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(160)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(161)

      fd_create_C_frame(161)
      fd_install_ind_min_max(0)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(161)

      fd_ind_min_max(6,5,0)
      fd_ind_min_max(3,4,1)
      fd_term_parameter(0,4)
      fd_term_copy(1,0)
      fd_mul_term_term(1,6)
      fd_add_term_term(1,3)
      fd_term_parameter(3,3)
      fd_add_term_term(1,3)
      fd_mul_term_term(0,5)
      fd_add_term_term(0,4)
      fd_add_term_term(0,3)
      fd_tell_interval(2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(161)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(161)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(161)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "pac ax+by+c=z"
#define PRED       X7061632061782B62792B633D7A
#define ARITY      6

Begin_Public_Pred
      fd_set_x_AF(6,6)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(3)
      fd_x_value_in_A_frame(5)
      fd_x_term_parameter_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(4)
      fd_x_term_parameter_in_A_frame(0)
      fd_install_constraint_with_x_AF(162,6)
      fd_call_constraint
      fd_install_constraint_with_x_AF(163,6)
      fd_call_constraint
      fd_install_constraint_with_x_AF(164,6)
      fd_call_constraint
      fd_install_constraint_with_x_AF(165,6)
      fd_call_constraint
      fd_install_constraint_with_x_AF(166,6)
      fd_call_constraint
      fd_install_constraint_with_x_AF(167,6)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(162)

      fd_create_C_frame(162)
      fd_install_ind_sigma(1)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(162)

      fd_ind_sigma(1,1)
      fd_ind_sigma(4,2)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_mulA_term(1,4)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(162)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(162)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(162)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(163)

      fd_create_C_frame(163)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(163)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,2)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(1,3,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(163)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(163)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(163)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(164)

      fd_create_C_frame(164)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(164)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,1)
      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(164)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(164)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(164)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(165)

      fd_create_C_frame(165)
      fd_install_ind_min_max(2)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(165)

      fd_ind_min_max(2,1,2)
      fd_ind_min_max(6,3,1)
      fd_term_parameter(5,3)
      fd_mul_term_term(3,5)
      fd_sub_term_term(2,3)
      fd_term_parameter(4,4)
      fd_sub_term_term(2,4)
      fd_term_parameter(3,5)
      fd_ceil_div_term_term(2,3)
      fd_mul_term_term(5,6)
      fd_sub_term_term(1,5)
      fd_sub_term_term(1,4)
      fd_floor_div_term_term(1,3)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(165)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(165)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(165)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(166)

      fd_create_C_frame(166)
      fd_install_ind_min_max(2)
      fd_install_ind_min_max(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(166)

      fd_ind_min_max(2,0,2)
      fd_ind_min_max(6,4,0)
      fd_term_parameter(5,5)
      fd_term_copy(3,5)
      fd_mul_term_term(3,4)
      fd_sub_term_term(2,3)
      fd_term_parameter(4,4)
      fd_sub_term_term(2,4)
      fd_term_parameter(3,3)
      fd_ceil_div_term_term(2,3)
      fd_mul_term_term(5,6)
      fd_sub_term_term(0,5)
      fd_sub_term_term(0,4)
      fd_floor_div_term_term(0,3)
      fd_tell_interval(1,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(166)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(166)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(166)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(167)

      fd_create_C_frame(167)
      fd_install_ind_min_max(0)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(167)

      fd_ind_min_max(3,6,0)
      fd_ind_min_max(7,5,1)
      fd_term_parameter(0,5)
      fd_term_copy(1,0)
      fd_mul_term_term(1,3)
      fd_term_parameter(4,3)
      fd_term_copy(3,4)
      fd_mul_term_term(3,7)
      fd_add_term_term(1,3)
      fd_term_parameter(3,4)
      fd_add_term_term(1,3)
      fd_mul_term_term(0,6)
      fd_mul_term_term(4,5)
      fd_add_term_term(0,4)
      fd_add_term_term(0,3)
      fd_tell_interval(2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(167)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(167)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(167)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "pac x+y=z"
#define PRED       X70616320782B793D7A
#define ARITY      3

Begin_Public_Pred
      fd_set_x_AF(3,3)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_install_constraint_with_x_AF(168,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(169,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(170,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(171,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(172,3)
      fd_call_constraint
      fd_install_constraint_with_x_AF(173,3)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(168)

      fd_create_C_frame(168)
      fd_install_ind_sigma(1)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(168)

      fd_ind_sigma(1,1)
      fd_ind_sigma(4,2)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_mulA_term(1,4)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(168)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(168)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(168)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(169)

      fd_create_C_frame(169)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(169)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,2)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(1,3,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(169)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(169)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(169)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(170)

      fd_create_C_frame(170)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(170)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,1)
      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(170)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(170)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(170)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(171)

      fd_create_C_frame(171)
      fd_install_ind_min_max(2)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(171)

      fd_ind_min_max(2,1,2)
      fd_ind_min_max(3,4,1)
      fd_sub_term_term(2,4)
      fd_sub_term_term(1,3)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(171)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(171)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(171)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(172)

      fd_create_C_frame(172)
      fd_install_ind_min_max(2)
      fd_install_ind_min_max(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(172)

      fd_ind_min_max(2,0,2)
      fd_ind_min_max(3,4,0)
      fd_sub_term_term(2,4)
      fd_sub_term_term(0,3)
      fd_tell_interval(1,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(172)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(172)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(172)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(173)

      fd_create_C_frame(173)
      fd_install_ind_min_max(0)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(173)

      fd_ind_min_max(1,0,0)
      fd_ind_min_max(4,3,1)
      fd_add_term_term(1,4)
      fd_add_term_term(0,3)
      fd_tell_interval(2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(173)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(173)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(173)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "pac ax+y=z"
#define PRED       X7061632061782B793D7A
#define ARITY      4

Begin_Public_Pred
      fd_set_x_AF(4,4)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_x_value_in_A_frame(3)
      fd_x_term_parameter_in_A_frame(0)
      fd_install_constraint_with_x_AF(174,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(175,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(176,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(177,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(178,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(179,4)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(174)

      fd_create_C_frame(174)
      fd_install_ind_sigma(1)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(174)

      fd_ind_sigma(1,1)
      fd_ind_sigma(4,2)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_mulA_term(1,4)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(174)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(174)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(174)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(175)

      fd_create_C_frame(175)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(175)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,2)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(1,3,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(175)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(175)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(175)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(176)

      fd_create_C_frame(176)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(176)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,1)
      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(176)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(176)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(176)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(177)

      fd_create_C_frame(177)
      fd_install_ind_min_max(2)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(177)

      fd_ind_min_max(2,1,2)
      fd_ind_min_max(4,3,1)
      fd_sub_term_term(2,3)
      fd_term_parameter(3,3)
      fd_ceil_div_term_term(2,3)
      fd_sub_term_term(1,4)
      fd_floor_div_term_term(1,3)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(177)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(177)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(177)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(178)

      fd_create_C_frame(178)
      fd_install_ind_min_max(2)
      fd_install_ind_min_max(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(178)

      fd_ind_min_max(2,0,2)
      fd_ind_min_max(4,6,0)
      fd_term_parameter(3,3)
      fd_term_copy(5,3)
      fd_mul_term_term(5,6)
      fd_sub_term_term(2,5)
      fd_mul_term_term(3,4)
      fd_sub_term_term(0,3)
      fd_tell_interval(1,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(178)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(178)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(178)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(179)

      fd_create_C_frame(179)
      fd_install_ind_min_max(0)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(179)

      fd_ind_min_max(6,4,0)
      fd_ind_min_max(5,3,1)
      fd_term_parameter(0,3)
      fd_term_copy(1,0)
      fd_mul_term_term(1,6)
      fd_add_term_term(1,5)
      fd_mul_term_term(0,4)
      fd_add_term_term(0,3)
      fd_tell_interval(2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(179)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(179)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(179)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "pac x+y+c=z"
#define PRED       X70616320782B792B633D7A
#define ARITY      4

Begin_Public_Pred
      fd_set_x_AF(4,4)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(3)
      fd_x_term_parameter_in_A_frame(2)
      fd_install_constraint_with_x_AF(180,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(181,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(182,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(183,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(184,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(185,4)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(180)

      fd_create_C_frame(180)
      fd_install_ind_sigma(1)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(180)

      fd_ind_sigma(1,1)
      fd_ind_sigma(4,2)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_mulA_term(1,4)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(180)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(180)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(180)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(181)

      fd_create_C_frame(181)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(181)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,2)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(1,3,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(181)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(181)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(181)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(182)

      fd_create_C_frame(182)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(182)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,1)
      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(182)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(182)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(182)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(183)

      fd_create_C_frame(183)
      fd_install_ind_min_max(2)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(183)

      fd_ind_min_max(2,1,2)
      fd_ind_min_max(4,3,1)
      fd_sub_term_term(2,3)
      fd_term_parameter(3,3)
      fd_sub_term_term(2,3)
      fd_sub_term_term(1,4)
      fd_sub_term_term(1,3)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(183)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(183)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(183)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(184)

      fd_create_C_frame(184)
      fd_install_ind_min_max(2)
      fd_install_ind_min_max(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(184)

      fd_ind_min_max(2,0,2)
      fd_ind_min_max(4,3,0)
      fd_sub_term_term(2,3)
      fd_term_parameter(3,3)
      fd_sub_term_term(2,3)
      fd_sub_term_term(0,4)
      fd_sub_term_term(0,3)
      fd_tell_interval(1,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(184)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(184)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(184)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(185)

      fd_create_C_frame(185)
      fd_install_ind_min_max(0)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(185)

      fd_ind_min_max(1,0,0)
      fd_ind_min_max(3,4,1)
      fd_add_term_term(1,3)
      fd_term_parameter(3,3)
      fd_add_term_term(1,3)
      fd_add_term_term(0,4)
      fd_add_term_term(0,3)
      fd_tell_interval(2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(185)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(185)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(185)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "pac ax+by=z"
#define PRED       X7061632061782B62793D7A
#define ARITY      5

Begin_Public_Pred
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(3)
      fd_x_value_in_A_frame(4)
      fd_x_term_parameter_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(0)
      fd_install_constraint_with_x_AF(186,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(187,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(188,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(189,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(190,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(191,5)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(186)

      fd_create_C_frame(186)
      fd_install_ind_sigma(1)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(186)

      fd_ind_sigma(1,1)
      fd_ind_sigma(4,2)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_mulA_term(1,4)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(186)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(186)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(186)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(187)

      fd_create_C_frame(187)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(187)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,2)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(1,3,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(187)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(187)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(187)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(188)

      fd_create_C_frame(188)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(188)

      fd_ind_sigma(0,0)
      fd_ind_sigma(4,1)
      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(188)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(188)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(188)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(189)

      fd_create_C_frame(189)
      fd_install_ind_min_max(2)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(189)

      fd_ind_min_max(2,1,2)
      fd_ind_min_max(5,6,1)
      fd_term_parameter(4,3)
      fd_term_copy(3,4)
      fd_mul_term_term(3,6)
      fd_sub_term_term(2,3)
      fd_term_parameter(3,4)
      fd_ceil_div_term_term(2,3)
      fd_mul_term_term(4,5)
      fd_sub_term_term(1,4)
      fd_floor_div_term_term(1,3)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(189)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(189)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(189)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(190)

      fd_create_C_frame(190)
      fd_install_ind_min_max(2)
      fd_install_ind_min_max(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(190)

      fd_ind_min_max(2,0,2)
      fd_ind_min_max(5,6,0)
      fd_term_parameter(4,4)
      fd_term_copy(3,4)
      fd_mul_term_term(3,6)
      fd_sub_term_term(2,3)
      fd_term_parameter(3,3)
      fd_ceil_div_term_term(2,3)
      fd_mul_term_term(4,5)
      fd_sub_term_term(0,4)
      fd_floor_div_term_term(0,3)
      fd_tell_interval(1,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(190)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(190)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(190)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(191)

      fd_create_C_frame(191)
      fd_install_ind_min_max(0)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(191)

      fd_ind_min_max(3,5,0)
      fd_ind_min_max(7,4,1)
      fd_term_parameter(0,4)
      fd_term_copy(1,0)
      fd_mul_term_term(1,3)
      fd_term_parameter(3,3)
      fd_term_copy(6,3)
      fd_mul_term_term(6,7)
      fd_add_term_term(1,6)
      fd_mul_term_term(0,5)
      fd_mul_term_term(3,4)
      fd_add_term_term(0,3)
      fd_tell_interval(2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(191)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(191)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(191)

      fd_reduce_vars(2)

End_Fd_Reduction



#define ASCII_PRED "pac x+y+z=t"
#define PRED       X70616320782B792B7A3D74
#define ARITY      4

Begin_Public_Pred
      fd_set_x_AF(4,4)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_x_value_in_A_frame(3)
      fd_install_constraint_with_x_AF(192,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(193,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(194,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(195,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(196,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(197,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(198,4)
      fd_call_constraint
      fd_install_constraint_with_x_AF(199,4)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(192)

      fd_create_C_frame(192)
      fd_install_ind_sigma(1)
      fd_install_ind_sigma(2)
      fd_install_ind_sigma(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(192)

      fd_ind_sigma(1,1)
      fd_ind_sigma(5,2)
      fd_ind_sigma(4,3)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_mulA_term(1,5)
      fd_term_mulA_term(1,4)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(192)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(192)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(192)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(193)

      fd_create_C_frame(193)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(2)
      fd_install_ind_sigma(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(193)

      fd_ind_sigma(0,0)
      fd_ind_sigma(5,2)
      fd_ind_sigma(4,3)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_mulA_term(0,5)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(1,3,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(193)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(193)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(193)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(194)

      fd_create_C_frame(194)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(1)
      fd_install_ind_sigma(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(194)

      fd_ind_sigma(0,0)
      fd_ind_sigma(5,1)
      fd_ind_sigma(4,3)
      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_mulA_term(0,5)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(194)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(194)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(194)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(195)

      fd_create_C_frame(195)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(1)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(195)

      fd_ind_sigma(0,0)
      fd_ind_sigma(5,1)
      fd_ind_sigma(4,2)
      fd_integer(2,0)
      fd_integer(1,infinity)
      fd_term_mulA_term(0,5)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(3,2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(195)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(195)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(195)

      fd_reduce_vars(3)

End_Fd_Reduction


Begin_Fd_Install(196)

      fd_create_C_frame(196)
      fd_install_ind_min_max(3)
      fd_install_ind_min_max(1)
      fd_install_ind_min_max(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(196)

      fd_ind_min_max(2,1,3)
      fd_ind_min_max(4,6,1)
      fd_ind_min_max(3,5,2)
      fd_sub_term_term(2,6)
      fd_sub_term_term(2,5)
      fd_sub_term_term(1,4)
      fd_sub_term_term(1,3)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(196)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(196)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(196)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(197)

      fd_create_C_frame(197)
      fd_install_ind_min_max(3)
      fd_install_ind_min_max(0)
      fd_install_ind_min_max(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(197)

      fd_ind_min_max(2,0,3)
      fd_ind_min_max(4,6,0)
      fd_ind_min_max(3,5,2)
      fd_sub_term_term(2,6)
      fd_sub_term_term(2,5)
      fd_sub_term_term(0,4)
      fd_sub_term_term(0,3)
      fd_tell_interval(1,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(197)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(197)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(197)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(198)

      fd_create_C_frame(198)
      fd_install_ind_min_max(3)
      fd_install_ind_min_max(0)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(198)

      fd_ind_min_max(1,0,3)
      fd_ind_min_max(4,6,0)
      fd_ind_min_max(3,5,1)
      fd_sub_term_term(1,6)
      fd_sub_term_term(1,5)
      fd_sub_term_term(0,4)
      fd_sub_term_term(0,3)
      fd_tell_interval(2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(198)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(198)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(198)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(199)

      fd_create_C_frame(199)
      fd_install_ind_min_max(0)
      fd_install_ind_min_max(1)
      fd_install_ind_min_max(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(199)

      fd_ind_min_max(1,0,0)
      fd_ind_min_max(6,4,1)
      fd_ind_min_max(5,2,2)
      fd_add_term_term(1,6)
      fd_add_term_term(1,5)
      fd_add_term_term(0,4)
      fd_add_term_term(0,2)
      fd_tell_interval(3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(199)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(199)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(199)

      fd_reduce_vars(3)

End_Fd_Reduction



#define ASCII_PRED "pac ax+y+z=t"
#define PRED       X7061632061782B792B7A3D74
#define ARITY      5

Begin_Public_Pred
      fd_set_x_AF(5,5)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(2)
      fd_x_value_in_A_frame(3)
      fd_x_value_in_A_frame(4)
      fd_x_term_parameter_in_A_frame(0)
      fd_install_constraint_with_x_AF(200,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(201,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(202,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(203,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(204,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(205,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(206,5)
      fd_call_constraint
      fd_install_constraint_with_x_AF(207,5)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(200)

      fd_create_C_frame(200)
      fd_install_ind_sigma(1)
      fd_install_ind_sigma(2)
      fd_install_ind_sigma(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(200)

      fd_ind_sigma(1,1)
      fd_ind_sigma(5,2)
      fd_ind_sigma(4,3)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_mulA_term(1,5)
      fd_term_mulA_term(1,4)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(200)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(200)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(200)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(201)

      fd_create_C_frame(201)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(2)
      fd_install_ind_sigma(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(201)

      fd_ind_sigma(0,0)
      fd_ind_sigma(5,2)
      fd_ind_sigma(4,3)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_mulA_term(0,5)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(1,3,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(201)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(201)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(201)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(202)

      fd_create_C_frame(202)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(1)
      fd_install_ind_sigma(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(202)

      fd_ind_sigma(0,0)
      fd_ind_sigma(5,1)
      fd_ind_sigma(4,3)
      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_mulA_term(0,5)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(202)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(202)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(202)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(203)

      fd_create_C_frame(203)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(1)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(203)

      fd_ind_sigma(0,0)
      fd_ind_sigma(5,1)
      fd_ind_sigma(4,2)
      fd_integer(2,0)
      fd_integer(1,infinity)
      fd_term_mulA_term(0,5)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(3,2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(203)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(203)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(203)

      fd_reduce_vars(3)

End_Fd_Reduction


Begin_Fd_Install(204)

      fd_create_C_frame(204)
      fd_install_ind_min_max(3)
      fd_install_ind_min_max(1)
      fd_install_ind_min_max(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(204)

      fd_ind_min_max(2,1,3)
      fd_ind_min_max(5,6,1)
      fd_ind_min_max(4,3,2)
      fd_sub_term_term(2,6)
      fd_sub_term_term(2,3)
      fd_term_parameter(3,4)
      fd_ceil_div_term_term(2,3)
      fd_sub_term_term(1,5)
      fd_sub_term_term(1,4)
      fd_floor_div_term_term(1,3)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(204)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(204)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(204)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(205)

      fd_create_C_frame(205)
      fd_install_ind_min_max(3)
      fd_install_ind_min_max(0)
      fd_install_ind_min_max(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(205)

      fd_ind_min_max(2,0,3)
      fd_ind_min_max(5,8,0)
      fd_ind_min_max(3,6,2)
      fd_term_parameter(4,4)
      fd_term_copy(7,4)
      fd_mul_term_term(7,8)
      fd_sub_term_term(2,7)
      fd_sub_term_term(2,6)
      fd_mul_term_term(4,5)
      fd_sub_term_term(0,4)
      fd_sub_term_term(0,3)
      fd_tell_interval(1,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(205)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(205)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(205)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(206)

      fd_create_C_frame(206)
      fd_install_ind_min_max(3)
      fd_install_ind_min_max(0)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(206)

      fd_ind_min_max(1,0,3)
      fd_ind_min_max(5,8,0)
      fd_ind_min_max(3,6,1)
      fd_term_parameter(4,4)
      fd_term_copy(7,4)
      fd_mul_term_term(7,8)
      fd_sub_term_term(1,7)
      fd_sub_term_term(1,6)
      fd_mul_term_term(4,5)
      fd_sub_term_term(0,4)
      fd_sub_term_term(0,3)
      fd_tell_interval(2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(206)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(206)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(206)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(207)

      fd_create_C_frame(207)
      fd_install_ind_min_max(0)
      fd_install_ind_min_max(1)
      fd_install_ind_min_max(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(207)

      fd_ind_min_max(8,5,0)
      fd_ind_min_max(7,4,1)
      fd_ind_min_max(6,2,2)
      fd_term_parameter(0,4)
      fd_term_copy(1,0)
      fd_mul_term_term(1,8)
      fd_add_term_term(1,7)
      fd_add_term_term(1,6)
      fd_mul_term_term(0,5)
      fd_add_term_term(0,4)
      fd_add_term_term(0,2)
      fd_tell_interval(3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(207)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(207)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(207)

      fd_reduce_vars(3)

End_Fd_Reduction



#define ASCII_PRED "pac ax+by+z=t"
#define PRED       X7061632061782B62792B7A3D74
#define ARITY      6

Begin_Public_Pred
      fd_set_x_AF(6,6)
      fd_x_value_in_A_frame(1)
      fd_x_value_in_A_frame(3)
      fd_x_value_in_A_frame(4)
      fd_x_value_in_A_frame(5)
      fd_x_term_parameter_in_A_frame(2)
      fd_x_term_parameter_in_A_frame(0)
      fd_install_constraint_with_x_AF(208,6)
      fd_call_constraint
      fd_install_constraint_with_x_AF(209,6)
      fd_call_constraint
      fd_install_constraint_with_x_AF(210,6)
      fd_call_constraint
      fd_install_constraint_with_x_AF(211,6)
      fd_call_constraint
      fd_install_constraint_with_x_AF(212,6)
      fd_call_constraint
      fd_install_constraint_with_x_AF(213,6)
      fd_call_constraint
      fd_install_constraint_with_x_AF(214,6)
      fd_call_constraint
      fd_install_constraint_with_x_AF(215,6)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(208)

      fd_create_C_frame(208)
      fd_install_ind_sigma(1)
      fd_install_ind_sigma(2)
      fd_install_ind_sigma(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(208)

      fd_ind_sigma(1,1)
      fd_ind_sigma(5,2)
      fd_ind_sigma(4,3)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_mulA_term(1,5)
      fd_term_mulA_term(1,4)
      fd_tell_interval_value(0,3,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(208)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(208)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(208)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(209)

      fd_create_C_frame(209)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(2)
      fd_install_ind_sigma(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(209)

      fd_ind_sigma(0,0)
      fd_ind_sigma(5,2)
      fd_ind_sigma(4,3)
      fd_integer(3,0)
      fd_integer(2,infinity)
      fd_term_mulA_term(0,5)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(1,3,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(209)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(209)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(209)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(210)

      fd_create_C_frame(210)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(1)
      fd_install_ind_sigma(3)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(210)

      fd_ind_sigma(0,0)
      fd_ind_sigma(5,1)
      fd_ind_sigma(4,3)
      fd_integer(3,0)
      fd_integer(1,infinity)
      fd_term_mulA_term(0,5)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(2,3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(210)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(210)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(210)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(211)

      fd_create_C_frame(211)
      fd_install_ind_sigma(0)
      fd_install_ind_sigma(1)
      fd_install_ind_sigma(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(211)

      fd_ind_sigma(0,0)
      fd_ind_sigma(5,1)
      fd_ind_sigma(4,2)
      fd_integer(2,0)
      fd_integer(1,infinity)
      fd_term_mulA_term(0,5)
      fd_term_mulA_term(0,4)
      fd_tell_interval_value(3,2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(211)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(211)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(211)

      fd_reduce_vars(3)

End_Fd_Reduction


Begin_Fd_Install(212)

      fd_create_C_frame(212)
      fd_install_ind_min_max(3)
      fd_install_ind_min_max(1)
      fd_install_ind_min_max(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(212)

      fd_ind_min_max(2,1,3)
      fd_ind_min_max(6,8,1)
      fd_ind_min_max(4,3,2)
      fd_term_parameter(5,4)
      fd_term_copy(7,5)
      fd_mul_term_term(7,8)
      fd_sub_term_term(2,7)
      fd_sub_term_term(2,3)
      fd_term_parameter(3,5)
      fd_ceil_div_term_term(2,3)
      fd_mul_term_term(5,6)
      fd_sub_term_term(1,5)
      fd_sub_term_term(1,4)
      fd_floor_div_term_term(1,3)
      fd_tell_interval(0,2,1)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(212)

      fd_enlarge_var(0)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(212)

      fd_test_enlargement_var(0)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(212)

      fd_reduce_vars(0)

End_Fd_Reduction


Begin_Fd_Install(213)

      fd_create_C_frame(213)
      fd_install_ind_min_max(3)
      fd_install_ind_min_max(0)
      fd_install_ind_min_max(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(213)

      fd_ind_min_max(2,0,3)
      fd_ind_min_max(6,8,0)
      fd_ind_min_max(4,3,2)
      fd_term_parameter(5,5)
      fd_term_copy(7,5)
      fd_mul_term_term(7,8)
      fd_sub_term_term(2,7)
      fd_sub_term_term(2,3)
      fd_term_parameter(3,4)
      fd_ceil_div_term_term(2,3)
      fd_mul_term_term(5,6)
      fd_sub_term_term(0,5)
      fd_sub_term_term(0,4)
      fd_floor_div_term_term(0,3)
      fd_tell_interval(1,2,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(213)

      fd_enlarge_var(1)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(213)

      fd_test_enlargement_var(1)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(213)

      fd_reduce_vars(1)

End_Fd_Reduction


Begin_Fd_Install(214)

      fd_create_C_frame(214)
      fd_install_ind_min_max(3)
      fd_install_ind_min_max(0)
      fd_install_ind_min_max(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(214)

      fd_ind_min_max(1,0,3)
      fd_ind_min_max(6,7,0)
      fd_ind_min_max(4,8,1)
      fd_term_parameter(5,5)
      fd_term_copy(3,5)
      fd_mul_term_term(3,7)
      fd_sub_term_term(1,3)
      fd_term_parameter(3,4)
      fd_term_copy(7,3)
      fd_mul_term_term(7,8)
      fd_sub_term_term(1,7)
      fd_mul_term_term(5,6)
      fd_sub_term_term(0,5)
      fd_mul_term_term(3,4)
      fd_sub_term_term(0,3)
      fd_tell_interval(2,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(214)

      fd_enlarge_var(2)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(214)

      fd_test_enlargement_var(2)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(214)

      fd_reduce_vars(2)

End_Fd_Reduction


Begin_Fd_Install(215)

      fd_create_C_frame(215)
      fd_install_ind_min_max(0)
      fd_install_ind_min_max(1)
      fd_install_ind_min_max(2)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(215)

      fd_ind_min_max(4,6,0)
      fd_ind_min_max(9,5,1)
      fd_ind_min_max(7,2,2)
      fd_term_parameter(0,5)
      fd_term_copy(1,0)
      fd_mul_term_term(1,4)
      fd_term_parameter(4,4)
      fd_term_copy(8,4)
      fd_mul_term_term(8,9)
      fd_add_term_term(1,8)
      fd_add_term_term(1,7)
      fd_mul_term_term(0,6)
      fd_mul_term_term(4,5)
      fd_add_term_term(0,4)
      fd_add_term_term(0,2)
      fd_tell_interval(3,1,0)
      fd_proceed

End_Fd_Constraint


Begin_Fd_Enlargement(215)

      fd_enlarge_var(3)

End_Fd_Enlargement


Begin_Fd_Test_Enlargement(215)

      fd_test_enlargement_var(3)

End_Fd_Test_Enlargement


Begin_Fd_Reduction(215)

      fd_reduce_vars(3)

End_Fd_Reduction


Begin_Init_Tables(sfd_arithmetic)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X783D63686F6F736528792C7A29,"x=choose(y,z)")
 Define_Atom(X783D63686F6F736528792C7A293A28613B6229,"x=choose(y,z):(a;b)")
 Define_Atom(X783D6D696E28792C7A29,"x=min(y,z)")
 Define_Atom(X783D6D696E28792C7A293A28613B6229,"x=min(y,z):(a;b)")
 Define_Atom(X783D6D617828792C7A29,"x=max(y,z)")
 Define_Atom(X783D6D617828792C7A293A28613B6229,"x=max(y,z):(a;b)")
 Define_Atom(X783D633A28613B6229,"x=c:(a;b)")
 Define_Atom(X783D63,"x=c")
 Define_Atom(X783C3E633A28613B6229,"x<>c:(a;b)")
 Define_Atom(X783C3E63,"x<>c")
 Define_Atom(X783C3E793A28613B6229,"x<>y:(a;b)")
 Define_Atom(X783C3E79,"x<>y")
 Define_Atom(X783D793A28613B6229,"x=y:(a;b)")
 Define_Atom(X783D79,"x=y")
 Define_Atom(X783E793A28613B6229,"x>y:(a;b)")
 Define_Atom(X783E79,"x>y")
 Define_Atom(X783E3D793A28613B6229,"x>=y:(a;b)")
 Define_Atom(X783E3D79,"x>=y")
 Define_Atom(X783D792B633A28613B6229,"x=y+c:(a;b)")
 Define_Atom(X783D792B63,"x=y+c")
 Define_Atom(X783E792B633A28613B6229,"x>y+c:(a;b)")
 Define_Atom(X783E792B63,"x>y+c")
 Define_Atom(X783E3D792B633A28613B6229,"x>=y+c:(a;b)")
 Define_Atom(X783E3D792B63,"x>=y+c")
 Define_Atom(X783D792B7A3A28613B6229,"x=y+z:(a;b)")
 Define_Atom(X783D792B7A,"x=y+z")
 Define_Atom(X783E792B7A3A28613B6229,"x>y+z:(a;b)")
 Define_Atom(X783E792B7A,"x>y+z")
 Define_Atom(X783E3D792B7A3A28613B6229,"x>=y+z:(a;b)")
 Define_Atom(X783E3D792B7A,"x>=y+z")
 Define_Atom(X783D63793A28613B6229,"x=cy:(a;b)")
 Define_Atom(X783D6379,"x=cy")
 Define_Atom(X783E63793A28613B6229,"x>cy:(a;b)")
 Define_Atom(X783E6379,"x>cy")
 Define_Atom(X783E3D63793A28613B6229,"x>=cy:(a;b)")
 Define_Atom(X783E3D6379,"x>=cy")
 Define_Atom(X783D797A3A28613B6229,"x=yz:(a;b)")
 Define_Atom(X783D797A,"x=yz")
 Define_Atom(X783E797A3A28613B6229,"x>yz:(a;b)")
 Define_Atom(X783E797A,"x>yz")
 Define_Atom(X783E3D797A3A28613B6229,"x>=yz:(a;b)")
 Define_Atom(X783E3D797A,"x>=yz")
 Define_Atom(X7061632078793D7A,"pac xy=z")
 Define_Atom(X70616320783D79,"pac x=y")
 Define_Atom(X70616320783C3E79,"pac x<>y")
 Define_Atom(X70616320783E3D79,"pac x>=y")
 Define_Atom(X70616320783E79,"pac x>y")
 Define_Atom(X70616320782B633D79,"pac x+c=y")
 Define_Atom(X7061632061783D79,"pac ax=y")
 Define_Atom(X7061632061782B633D79,"pac ax+c=y")
 Define_Atom(X7061632061782B792B633D7A,"pac ax+y+c=z")
 Define_Atom(X7061632061782B62792B633D7A,"pac ax+by+c=z")
 Define_Atom(X70616320782B793D7A,"pac x+y=z")
 Define_Atom(X7061632061782B793D7A,"pac ax+y=z")
 Define_Atom(X70616320782B792B633D7A,"pac x+y+c=z")
 Define_Atom(X7061632061782B62793D7A,"pac ax+by=z")
 Define_Atom(X70616320782B792B7A3D74,"pac x+y+z=t")
 Define_Atom(X7061632061782B792B7A3D74,"pac ax+y+z=t")
 Define_Atom(X7061632061782B62792B7A3D74,"pac ax+by+z=t")


 Define_Pred(X783D63686F6F736528792C7A29,3,1)

 Define_Pred(X783D63686F6F736528792C7A293A28613B6229,5,1)

 Define_Pred(X783D6D696E28792C7A29,3,1)

 Define_Pred(X783D6D696E28792C7A293A28613B6229,5,1)

 Define_Pred(X783D6D617828792C7A29,3,1)

 Define_Pred(X783D6D617828792C7A293A28613B6229,5,1)

 Define_Pred(X783D633A28613B6229,4,1)

 Define_Pred(X783D63,2,1)

 Define_Pred(X783C3E633A28613B6229,4,1)

 Define_Pred(X783C3E63,2,1)

 Define_Pred(X783C3E793A28613B6229,4,1)

 Define_Pred(X783C3E79,2,1)

 Define_Pred(X783D793A28613B6229,4,1)

 Define_Pred(X783D79,2,1)

 Define_Pred(X783E793A28613B6229,4,1)

 Define_Pred(X783E79,2,1)

 Define_Pred(X783E3D793A28613B6229,4,1)

 Define_Pred(X783E3D79,2,1)

 Define_Pred(X783D792B633A28613B6229,5,1)

 Define_Pred(X783D792B63,3,1)

 Define_Pred(X783E792B633A28613B6229,5,1)

 Define_Pred(X783E792B63,3,1)

 Define_Pred(X783E3D792B633A28613B6229,5,1)

 Define_Pred(X783E3D792B63,3,1)

 Define_Pred(X783D792B7A3A28613B6229,5,1)

 Define_Pred(X783D792B7A,3,1)

 Define_Pred(X783E792B7A3A28613B6229,5,1)

 Define_Pred(X783E792B7A,3,1)

 Define_Pred(X783E3D792B7A3A28613B6229,5,1)

 Define_Pred(X783E3D792B7A,3,1)

 Define_Pred(X783D63793A28613B6229,5,1)

 Define_Pred(X783D6379,3,1)

 Define_Pred(X783E63793A28613B6229,5,1)

 Define_Pred(X783E6379,3,1)

 Define_Pred(X783E3D63793A28613B6229,5,1)

 Define_Pred(X783E3D6379,3,1)

 Define_Pred(X783D797A3A28613B6229,5,1)

 Define_Pred(X783D797A,3,1)

 Define_Pred(X783E797A3A28613B6229,5,1)

 Define_Pred(X783E797A,3,1)

 Define_Pred(X783E3D797A3A28613B6229,5,1)

 Define_Pred(X783E3D797A,3,1)

 Define_Pred(X7061632078793D7A,3,1)

 Define_Pred(X70616320783D79,2,1)

 Define_Pred(X70616320783C3E79,2,1)

 Define_Pred(X70616320783E3D79,2,1)

 Define_Pred(X70616320783E79,2,1)

 Define_Pred(X70616320782B633D79,3,1)

 Define_Pred(X7061632061783D79,3,1)

 Define_Pred(X7061632061782B633D79,4,1)

 Define_Pred(X7061632061782B792B633D7A,5,1)

 Define_Pred(X7061632061782B62792B633D7A,6,1)

 Define_Pred(X70616320782B793D7A,3,1)

 Define_Pred(X7061632061782B793D7A,4,1)

 Define_Pred(X70616320782B792B633D7A,4,1)

 Define_Pred(X7061632061782B62793D7A,5,1)

 Define_Pred(X70616320782B792B7A3D74,4,1)

 Define_Pred(X7061632061782B792B7A3D74,5,1)

 Define_Pred(X7061632061782B62792B7A3D74,6,1)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(sfd_arithmetic)



End_Exec_Directives
