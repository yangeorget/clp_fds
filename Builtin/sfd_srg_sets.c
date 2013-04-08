/****************************************************************************
Prolog to Wam Compiler - Version 2.0
Daniel Diaz, Yan Georget
1998 - INRIA Rocquencourt - LOCO Project
File : sfd_srg_sets.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"
#include "sfd_engine.h"

#include "sfd_srg_sets.h"
#include "sfd_srg_sets.usr"


#define ASCII_PRED "sets_value_index"
#define PRED       X736574735F76616C75655F696E646578
#define ARITY      3

Begin_Public_Pred
      pragma_c(Sets_Value_Index_3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sets_value"
#define PRED       X736574735F76616C7565
#define ARITY      2

Begin_Public_Pred
      put_x_variable(2,2)
      execute(Pred_Name(X736574735F76616C75655F696E646578,3),1,"sets_value_index",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sets_index"
#define PRED       X736574735F696E646578
#define ARITY      2

Begin_Public_Pred
      get_x_variable(2,1)
      put_x_variable(1,1)
      execute(Pred_Name(X736574735F76616C75655F696E646578,3),1,"sets_value_index",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sets_indomain"
#define PRED       X736574735F696E646F6D61696E
#define ARITY      1

Begin_Public_Pred
      execute(Pred_Name(X736574735F696E646F6D61696E5F2461757831,1),1,"sets_indomain_$aux1",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sets_indomain_$aux1"
#define PRED       X736574735F696E646F6D61696E5F2461757831
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      allocate(1)
      get_y_bc_reg(0)
      call(Pred_Name(X7366645F69735F696E7374616E746961746564,1),0,1,"sfd_is_instantiated",1)          /* begin sub 1 */
      cut_y(0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      allocate(2)
      get_y_variable(1,0)
      put_y_value(1,0)
      put_y_variable(0,1)
      call(Pred_Name(X736574735F696E646578,2),1,2,"sets_index",2)          /* begin sub 2 */
      put_y_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X736574735F696E646F6D61696E5F2461757832,2),1,"sets_indomain_$aux2",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sets_indomain_$aux2"
#define PRED       X736574735F696E646F6D61696E5F2461757832
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      fd_set_x_AF(2,2)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(1)
      fd_install_constraint_with_x_AF(1,2)
      fd_call_constraint
      proceed

label(1)
      trust_me_else_fail
      allocate(2)
      get_y_variable(0,0)
      get_y_variable(1,1)
      call(Pred_Name(X62745F696E63,0),0,1,"bt_inc",0)          /* begin sub 1 */
      fd_set_x_AF(2,0)
      fd_y_value_in_A_frame(0)
      fd_y_term_parameter_in_A_frame(1)
      fd_install_constraint_with_x_AF(2,0)
      fd_call_constraint
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X736574735F696E646F6D61696E,1),1,"sets_indomain",1)

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

      fd_term_parameter(1,1)
      fd_tell_integer(0,1)
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
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(2)

      fd_allocate
      fd_term_parameter(1,1)
      fd_comp_term(1,1)
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



#define ASCII_PRED "sets_labeling"
#define PRED       X736574735F6C6162656C696E67
#define ARITY      1

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
      allocate(1)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(0)
      call(Pred_Name(X736574735F696E646F6D61696E,1),1,1,"sets_indomain",1)          /* begin sub 1 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X736574735F6C6162656C696E67,1),1,"sets_labeling",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sets_labelingff"
#define PRED       X736574735F6C6162656C696E676666
#define ARITY      1

Begin_Public_Pred
      pragma_c(Sets_Labelingff_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sets_labelingff1"
#define PRED       X736574735F6C6162656C696E67666631
#define ARITY      2

Begin_Private_Pred
      allocate(1)
      get_y_variable(0,0)
      put_x_value(1,0)
      call(Pred_Name(X736574735F696E646F6D61696E,1),1,1,"sets_indomain",1)          /* begin sub 1 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X736574735F6C6162656C696E676666,1),1,"sets_labelingff",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sets_card_ge"
#define PRED       X736574735F636172645F6765
#define ARITY      2

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
      unify_x_variable(3)
      unify_x_variable(0)
      fd_set_x_AF(2,2)
      fd_x_value_in_A_frame(3)
      fd_x_term_parameter_in_A_frame(1)
      fd_install_constraint_with_x_AF(3,2)
      fd_call_constraint
      execute(Pred_Name(X736574735F636172645F6765,2),1,"sets_card_ge",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(3)

      fd_create_C_frame(3)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(3)

      fd_allocate
      fd_ind_def(3,0)
      fd_term_parameter(2,1)
      fd_range_fct(keep_card_ge,1,arg_2(rr(3),tr(2)))
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



#define ASCII_PRED "sets_card_g"
#define PRED       X736574735F636172645F67
#define ARITY      2

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
      unify_x_variable(3)
      unify_x_variable(0)
      fd_set_x_AF(2,2)
      fd_x_value_in_A_frame(3)
      fd_x_term_parameter_in_A_frame(1)
      fd_install_constraint_with_x_AF(4,2)
      fd_call_constraint
      execute(Pred_Name(X736574735F636172645F67,2),1,"sets_card_g",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(4)

      fd_create_C_frame(4)
      fd_install_ind_def(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(4)

      fd_allocate
      fd_ind_def(3,0)
      fd_term_parameter(2,1)
      fd_range_fct(keep_card_g,1,arg_2(rr(3),tr(2)))
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



#define ASCII_PRED "sets_max_sol"
#define PRED       X736574735F6D61785F736F6C
#define ARITY      1

Begin_Public_Pred
      put_structure(X736574735F6C6162656C696E67,1,1,"sets_labeling")
      unify_x_local_value(0)
      put_structure(X736574735F6C6162656C696E67,1,2,"sets_labeling")
      unify_x_local_value(0)
      execute(Pred_Name(X736574735F6D61785F736F6C,3),1,"sets_max_sol",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sets_max_sol"
#define PRED       X736574735F6D61785F736F6C
#define ARITY      3

Begin_Public_Pred
      put_integer(0,3)
      execute(Pred_Name(X736574735F6D61785F736F6C,4),1,"sets_max_sol",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sets_max_sol"
#define PRED       X736574735F6D61785F736F6C
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
      execute(Pred_Name(X736574735F6D61785F736F6C5F2461757833,5),1,"sets_max_sol_$aux3",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sets_max_sol_$aux3"
#define PRED       X736574735F6D61785F736F6C5F2461757833
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      allocate(6)
      get_y_variable(4,0)
      get_y_variable(5,1)
      get_y_variable(2,4)
      get_y_bc_reg(1)
      put_y_value(4,0)
      put_y_value(2,1)
      call(Pred_Name(X736574735F636172645F67,2),1,1,"sets_card_g",2)          /* begin sub 1 */
      put_y_value(5,0)
      call(Pred_Name(X63616C6C,1),0,2,"call",1)          /* begin sub 2 */
      put_y_value(4,0)
      put_y_variable(3,1)
      call(Pred_Name(X626C6576656C,2),0,3,"blevel",2)          /* begin sub 3 */
      put_y_value(3,0)
      put_y_variable(0,1)
      call(Pred_Name(X6E756D5F6269746E62,2),0,4,"num_bitnb",2)          /* begin sub 4 */
      math_load_y_value(0,1)
      math_load_y_value(2,0)
      builtin_2(gt,1,0)
      cut_y(1)
      put_constant(X246375725F6D6178,1,"$cur_max")
      put_y_unsafe_value(0,0)
      builtin_2(g_assign,1,0)
      fail

label(1)
      trust_me_else_fail
      allocate(1)
      get_y_variable(0,2)
      cut_x(3)
      put_constant(X246375725F6D6178,3,"$cur_max")
      put_x_variable(1,2)
      builtin_2(g_read,3,2)
      call(Pred_Name(X736574735F636172645F6765,2),1,5,"sets_card_ge",2)          /* begin sub 5 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X63616C6C,1),0,"call",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "wcs"
#define PRED       X776373
#define ARITY      2

Begin_Public_Pred
      allocate(3)
      get_y_variable(0,0)
      get_y_variable(2,1)
      put_y_value(2,0)
      put_y_variable(1,1)
      call(Pred_Name(X6C656E677468,2),0,1,"length",2)          /* begin sub 1 */
      math_load_y_value(1,1)
      put_integer(28,0)
      builtin_2(lt,1,0)
      put_constant(X7763735F76616C756573,1,"wcs_values")
      put_structure(X675F6172726179,1,0,"g_array")
      unify_y_local_value(2)
      builtin_2(g_assign,1,0)
      math_load_y_value(1,0)
      function_1(inc,0,0)
      put_integer(1,1)
      math_load_x_value(0,0)
      function_2(shl,0,1,0)
      function_1(dec,0,0)
      put_constant(X7763735F616C6C,1,"wcs_all")
      builtin_2(g_assign,1,0)
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X7763735F7374617274,1),1,"wcs_start",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "wcs_start"
#define PRED       X7763735F7374617274
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      allocate(2)
      get_y_variable(1,0)
      get_y_bc_reg(0)
      put_y_value(1,0)
      put_integer(1,1)
      call(Pred_Name(X7763735F76617273,2),1,1,"wcs_vars",2)          /* begin sub 1 */
      put_y_value(1,0)
      put_integer(1,1)
      call(Pred_Name(X7763735F657874656E64,2),1,2,"wcs_extend",2)          /* begin sub 2 */
      cut_y(0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      allocate(6)
      get_y_variable(0,0)
      get_y_bc_reg(1)
      put_constant(X7763735F6E6F676F6F645F73697A65,1,"wcs_nogood_size")
      put_y_variable(5,0)
      builtin_2(g_read,1,0)
      math_load_y_value(5,1)
      put_integer(0,0)
      builtin_2(neq,1,0)
      put_constant(X7763735F76616C756573,1,"wcs_values")
      put_structure(X675F6172726179,1,0,"g_array")
      unify_y_variable(4)
      builtin_2(g_read,1,0)
      put_y_variable(2,0)
      put_y_value(5,1)
      call(Pred_Name(X6C656E677468,2),0,3,"length",2)          /* begin sub 3 */
      put_y_variable(3,0)
      put_y_value(5,1)
      call(Pred_Name(X6C656E677468,2),0,4,"length",2)          /* begin sub 4 */
      put_y_value(2,0)
      put_y_value(0,1)
      call(Pred_Name(X707265666978,2),0,5,"prefix",2)          /* begin sub 5 */
      put_y_value(3,0)
      put_y_value(4,1)
      call(Pred_Name(X707265666978,2),0,6,"prefix",2)          /* begin sub 6 */
      put_y_value(3,0)
      put_y_value(2,1)
      call(Pred_Name(X6E6F676F6F64,2),0,7,"nogood",2)          /* begin sub 7 */
      cut_y(1)
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X7763735F7374617274,1),1,"wcs_start",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "wcs_vars"
#define PRED       X7763735F76617273
#define ARITY      2

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(7)
      get_list(0)
      unify_y_variable(3)
      unify_y_variable(1)
      math_load_x_value(1,1)
      function_1(dec,0,1)
      math_load_x_value(1,1)
      function_1(inc,1,1)
      get_y_variable(0,1)
      put_structure(X7763735F76616C756573,1,2,"wcs_values")
      unify_x_value(0)
      put_y_variable(6,1)
      builtin_2(g_read,2,1)
      put_constant(X7763735F616C6C,2,"wcs_all")
      put_y_variable(5,1)
      builtin_2(g_read,2,1)
      math_load_y_value(5,1)
      put_integer(1,2)
      math_load_x_value(0,0)
      function_2(shl,0,2,0)
      function_2(xor,0,1,0)
      get_y_variable(4,0)
      call(Pred_Name(X63737472735F626C6F636B5F7374617274,0),0,1,"cstrs_block_start",0)          /* begin sub 1 */
      put_y_value(3,0)
      put_y_value(6,1)
      put_y_value(5,2)
      put_y_value(4,3)
      call(Pred_Name(X783D633A28613B6229,4),0,2,"x=c:(a;b)",4)          /* begin sub 2 */
      put_y_variable(2,0)
      call(Pred_Name(X63737472735F626C6F636B5F656E64,1),0,3,"cstrs_block_end",1)          /* begin sub 3 */
      put_y_value(3,0)
      put_y_value(2,1)
      call(Pred_Name(X6664765F63737472735F626C6F636B5F707574,2),0,4,"fdv_cstrs_block_put",2)          /* begin sub 4 */
      put_y_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X7763735F76617273,2),1,"wcs_vars",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "wcs_extend"
#define PRED       X7763735F657874656E64
#define ARITY      2

Begin_Private_Pred
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
      unify_x_variable(0)
      unify_x_variable(5)
      get_x_variable(2,1)
      math_load_x_value(2,2)
      function_1(inc,3,2)
      put_integer(1,1)
      math_load_x_value(2,2)
      function_2(shl,1,1,2)
      function_1(dec,4,1)
      put_x_value(5,1)
      execute(Pred_Name(X7763735F657874656E645F2461757834,5),1,"wcs_extend_$aux4",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "wcs_extend_$aux4"
#define PRED       X7763735F657874656E645F2461757834
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      allocate(3)
      get_x_variable(5,0)
      get_y_variable(1,1)
      get_y_variable(0,3)
      get_y_bc_reg(2)
      put_constant(X6765,0,"ge")
      put_list(1)
      unify_x_local_value(5)
      unify_nil
      put_x_value(4,2)
      call(Pred_Name(X6B656570,3),0,1,"keep",3)          /* begin sub 1 */
      cut_y(2)
      put_y_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X7763735F657874656E64,2),1,"wcs_extend",2)

label(1)
      trust_me_else_fail
      allocate(5)
      get_y_variable(4,0)
      get_y_variable(3,1)
      get_y_variable(2,2)
      get_y_variable(1,3)
      get_y_variable(0,4)
      call(Pred_Name(X62745F696E63,0),0,2,"bt_inc",0)          /* begin sub 2 */
      put_y_value(4,0)
      put_y_value(3,1)
      put_y_value(2,2)
      put_y_value(1,3)
      put_y_value(0,4)
      deallocate
      execute(Pred_Name(X7763735F657874656E645F617578,5),1,"wcs_extend_aux",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "wcs_extend_aux"
#define PRED       X7763735F657874656E645F617578
#define ARITY      5

Begin_Private_Pred
      get_x_variable(5,2)
      get_x_variable(2,3)
      get_x_variable(3,4)
      math_load_x_value(5,5)
      function_1(dec,4,5)
      execute(Pred_Name(X7763735F657874656E645F6175785F2461757835,5),1,"wcs_extend_aux_$aux5",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "wcs_extend_aux_$aux5"
#define PRED       X7763735F657874656E645F6175785F2461757835
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      allocate(7)
      get_y_variable(5,0)
      get_y_variable(1,1)
      get_y_variable(0,2)
      get_y_variable(6,3)
      get_y_variable(4,4)
      get_y_bc_reg(2)
      put_y_value(5,0)
      call(Pred_Name(X6664765F63737472735F626C6F636B5F72657472616374,1),0,1,"fdv_cstrs_block_retract",1)          /* begin sub 1 */
      put_constant(X6765,0,"ge")
      put_list(1)
      unify_y_local_value(5)
      unify_nil
      put_y_value(6,2)
      call(Pred_Name(X6B656570,3),0,2,"keep",3)          /* begin sub 2 */
      put_list(0)
      unify_y_local_value(5)
      unify_nil
      call(Pred_Name(X736574735F6D61785F736F6C,1),1,3,"sets_max_sol",1)          /* begin sub 3 */
      put_y_value(5,0)
      put_y_variable(3,1)
      call(Pred_Name(X7366645F6D696E,2),0,4,"sfd_min",2)          /* begin sub 4 */
      put_structure(X7763735F76616C756573,1,1,"wcs_values")
      unify_y_local_value(4)
      put_y_unsafe_value(3,0)
      builtin_2(g_assign,1,0)
      cut_y(2)
      put_y_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X7763735F657874656E64,2),1,"wcs_extend",2)

label(1)
      trust_me_else_fail
      allocate(1)
      get_y_variable(0,4)
      call(Pred_Name(X62745F696E63,0),0,5,"bt_inc",0)          /* begin sub 5 */
      put_constant(X7763735F6E6F676F6F645F73697A65,1,"wcs_nogood_size")
      put_y_value(0,0)
      builtin_2(g_assign,1,0)
      fail

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(sfd_srg_sets)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X736574735F76616C75655F696E646578,"sets_value_index")
 Define_Atom(X736574735F76616C7565,"sets_value")
 Define_Atom(X736574735F696E646578,"sets_index")
 Define_Atom(X736574735F696E646F6D61696E,"sets_indomain")
 Define_Atom(X736574735F696E646F6D61696E5F2461757831,"sets_indomain_$aux1")
 Define_Atom(X736574735F696E646F6D61696E5F2461757832,"sets_indomain_$aux2")
 Define_Atom(X736574735F6C6162656C696E67,"sets_labeling")
 Define_Atom(X736574735F6C6162656C696E676666,"sets_labelingff")
 Define_Atom(X736574735F6C6162656C696E67666631,"sets_labelingff1")
 Define_Atom(X736574735F636172645F6765,"sets_card_ge")
 Define_Atom(X736574735F636172645F67,"sets_card_g")
 Define_Atom(X736574735F6D61785F736F6C,"sets_max_sol")
 Define_Atom(X246375725F6D6178,"$cur_max")
 Define_Atom(X736574735F6D61785F736F6C5F2461757833,"sets_max_sol_$aux3")
 Define_Atom(X776373,"wcs")
 Define_Atom(X7763735F76616C756573,"wcs_values")
 Define_Atom(X675F6172726179,"g_array")
 Define_Atom(X7763735F616C6C,"wcs_all")
 Define_Atom(X7763735F7374617274,"wcs_start")
 Define_Atom(X7763735F6E6F676F6F645F73697A65,"wcs_nogood_size")
 Define_Atom(X7763735F76617273,"wcs_vars")
 Define_Atom(X7763735F657874656E64,"wcs_extend")
 Define_Atom(X7763735F657874656E645F2461757834,"wcs_extend_$aux4")
 Define_Atom(X6765,"ge")
 Define_Atom(X7763735F657874656E645F617578,"wcs_extend_aux")
 Define_Atom(X7763735F657874656E645F6175785F2461757835,"wcs_extend_aux_$aux5")


 Define_Pred(X736574735F76616C75655F696E646578,3,1)

 Define_Pred(X736574735F76616C7565,2,1)

 Define_Pred(X736574735F696E646578,2,1)

 Define_Pred(X736574735F696E646F6D61696E,1,1)

 Define_Pred(X736574735F696E646F6D61696E5F2461757831,1,0)

 Define_Pred(X736574735F696E646F6D61696E5F2461757832,2,0)

 Define_Pred(X736574735F6C6162656C696E67,1,1)

 Define_Pred(X736574735F6C6162656C696E676666,1,1)

 Define_Pred(X736574735F6C6162656C696E67666631,2,0)

 Define_Pred(X736574735F636172645F6765,2,1)

 Define_Pred(X736574735F636172645F67,2,1)

 Define_Pred(X736574735F6D61785F736F6C,1,1)

 Define_Pred(X736574735F6D61785F736F6C,3,1)

 Define_Pred(X736574735F6D61785F736F6C,4,1)

 Define_Pred(X736574735F6D61785F736F6C5F2461757833,5,0)

 Define_Pred(X776373,2,1)

 Define_Pred(X7763735F7374617274,1,0)

 Define_Pred(X7763735F76617273,2,0)

 Define_Pred(X7763735F657874656E64,2,0)

 Define_Pred(X7763735F657874656E645F2461757834,5,0)

 Define_Pred(X7763735F657874656E645F617578,5,0)

 Define_Pred(X7763735F657874656E645F6175785F2461757835,5,0)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(sfd_srg_sets)



End_Exec_Directives
