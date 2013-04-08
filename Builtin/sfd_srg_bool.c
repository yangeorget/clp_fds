/****************************************************************************
Prolog to Wam Compiler - Version 3.0
Daniel Diaz, Yan Georget
1999 - INRIA Rocquencourt - LOCO Project
File : sfd_srg_bool.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"
#include "sfd_engine.h"

#include "sfd_srg_bool.h"
#include "sfd_srg_bool.usr"


#define ASCII_PRED "bool_v_element"
#define PRED       X626F6F6C5F765F656C656D656E74
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
      fd_install_constraint_with_x_AF(1,0)
      fd_call_constraint
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_unsafe_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X626F6F6C5F765F656C656D656E7431,4),1,"bool_v_element1",4)

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



#define ASCII_PRED "bool_v_element1"
#define PRED       X626F6F6C5F765F656C656D656E7431
#define ARITY      4

Begin_Private_Pred
      pragma_c(Bool_V_Element1_4)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "bool_indomain"
#define PRED       X626F6F6C5F696E646F6D61696E
#define ARITY      1

Begin_Public_Pred
      allocate(2)
      get_y_variable(1,0)
      put_y_value(1,0)
      put_y_variable(0,1)
      call(Pred_Name(X7366645F6D696E,2),0,1,"sfd_min",2)          /* begin sub 1 */
      put_y_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X626F6F6C5F696E646F6D61696E5F2461757831,2),1,"bool_indomain_$aux1",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "bool_indomain_$aux1"
#define PRED       X626F6F6C5F696E646F6D61696E5F2461757831
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      fd_set_x_AF(2,2)
      fd_x_value_in_A_frame(0)
      fd_x_term_parameter_in_A_frame(1)
      fd_install_constraint_with_x_AF(2,2)
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
      fd_install_constraint_with_x_AF(3,0)
      fd_call_constraint
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X626F6F6C5F696E646F6D61696E,1),1,"bool_indomain",1)

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

      fd_term_parameter(1,1)
      fd_tell_integer(0,1)
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
      fd_static_constraint(0)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(3)

      fd_term_parameter(2,1)
      fd_integer(1,1)
      fd_add_term_term(2,1)
      fd_integer(1,infinity)
      fd_tell_interval(0,2,1)
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



#define ASCII_PRED "bool_labeling"
#define PRED       X626F6F6C5F6C6162656C696E67
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
      call(Pred_Name(X626F6F6C5F696E646F6D61696E,1),1,1,"bool_indomain",1)          /* begin sub 1 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X626F6F6C5F6C6162656C696E67,1),1,"bool_labeling",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "bool_labelingff"
#define PRED       X626F6F6C5F6C6162656C696E676666
#define ARITY      1

Begin_Public_Pred
      pragma_c(Bool_Labelingff_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "bool_labelingff1"
#define PRED       X626F6F6C5F6C6162656C696E67666631
#define ARITY      2

Begin_Private_Pred
      allocate(1)
      get_y_variable(0,0)
      put_x_value(1,0)
      call(Pred_Name(X626F6F6C5F696E646F6D61696E,1),1,1,"bool_indomain",1)          /* begin sub 1 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X626F6F6C5F6C6162656C696E676666,1),1,"bool_labelingff",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "bool_alldifferent"
#define PRED       X626F6F6C5F616C6C646966666572656E74
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
      unify_x_variable(1)
      unify_y_variable(0)
      put_y_value(0,0)
      call(Pred_Name(X626F6F6C5F6F75745F6F66,2),1,1,"bool_out_of",2)          /* begin sub 1 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X626F6F6C5F616C6C646966666572656E74,1),1,"bool_alldifferent",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "bool_out_of"
#define PRED       X626F6F6C5F6F75745F6F66
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
      allocate(2)
      get_list(0)
      unify_x_variable(2)
      unify_y_variable(1)
      get_y_variable(0,1)
      put_y_value(0,0)
      put_x_value(2,1)
      call(Pred_Name(X626F6F6C5F64696666,2),1,1,"bool_diff",2)          /* begin sub 1 */
      put_y_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X626F6F6C5F6F75745F6F66,2),1,"bool_out_of",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "bool_diff"
#define PRED       X626F6F6C5F64696666
#define ARITY      2

Begin_Public_Pred
      fd_set_x_AF(2,2)
      fd_x_value_in_A_frame(0)
      fd_x_value_in_A_frame(1)
      fd_install_constraint_with_x_AF(4,2)
      fd_call_constraint
      fd_install_constraint_with_x_AF(5,2)
      fd_call_constraint
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Fd_Install(4)

      fd_create_C_frame(4)
      fd_install_ind_val(1)
      fd_proceed

End_Fd_Install


Begin_Fd_Constraint(4)

      fd_allocate
      fd_ind_val(1,1,1)
      fd_comp_term(1,1)
      fd_tell_range(0,1)

   Fd_Label(1)
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
      fd_ind_val(0,0,1)
      fd_comp_term(0,0)
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



#define ASCII_PRED "bool_global_alldifferent"
#define PRED       X626F6F6C5F676C6F62616C5F616C6C646966666572656E74
#define ARITY      1

Begin_Public_Pred
      allocate(2)
      get_y_variable(0,0)
      put_y_value(0,0)
      put_y_variable(1,1)
      call(Pred_Name(X6C656E677468,2),0,1,"length",2)          /* begin sub 1 */
      put_y_unsafe_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X626F6F6C5F676C6F62616C5F616C6C646966666572656E745F617578,2),1,"bool_global_alldifferent_aux",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "bool_global_alldifferent_aux"
#define PRED       X626F6F6C5F676C6F62616C5F616C6C646966666572656E745F617578
#define ARITY      2

Begin_Private_Pred
      pragma_c(Bool_Global_Alldifferent_Aux_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "bool_global_alldifferent2"
#define PRED       X626F6F6C5F676C6F62616C5F616C6C646966666572656E7432
#define ARITY      1

Begin_Public_Pred
      allocate(2)
      get_y_variable(0,0)
      put_y_value(0,0)
      put_y_variable(1,1)
      call(Pred_Name(X6C656E677468,2),0,1,"length",2)          /* begin sub 1 */
      put_y_unsafe_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X626F6F6C5F676C6F62616C5F616C6C646966666572656E74325F617578,2),1,"bool_global_alldifferent2_aux",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "bool_global_alldifferent2_aux"
#define PRED       X626F6F6C5F676C6F62616C5F616C6C646966666572656E74325F617578
#define ARITY      2

Begin_Private_Pred
      pragma_c(Bool_Global_Alldifferent2_Aux_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "bool_minof"
#define PRED       X626F6F6C5F6D696E6F66
#define ARITY      2

Begin_Public_Pred
      allocate(4)
      get_y_variable(2,0)
      get_y_variable(1,1)
      get_y_bc_reg(0)
      put_y_variable(3,0)
      call(Pred_Name(X66645F696E66696E697479,1),0,1,"fd_infinity",1)          /* begin sub 1 */
      put_constant(X246375725F6D696E,1,"$cur_min")
      put_y_unsafe_value(3,0)
      builtin_2(g_assign,1,0)
      call(Pred_Name(X726570656174,0),0,2,"repeat",0)          /* begin sub 2 */
      put_constant(X246375725F6D696E,1,"$cur_min")
      put_x_variable(3,0)
      builtin_2(g_read,1,0)
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_unsafe_value(0,2)
      deallocate
      execute(Pred_Name(X626F6F6C5F6D696E6F665F2461757832,4),1,"bool_minof_$aux2",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "bool_minof_$aux2"
#define PRED       X626F6F6C5F6D696E6F665F2461757832
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      allocate(4)
      get_y_variable(3,0)
      get_y_variable(1,1)
      get_y_bc_reg(2)
      put_x_value(3,0)
      put_y_value(1,1)
      call(Pred_Name(X70616320783E79,2),0,1,"pac x>y",2)          /* begin sub 1 */
      put_y_value(3,0)
      call(Pred_Name(X63616C6C,1),0,2,"call",1)          /* begin sub 2 */
      cut_y(2)
      put_y_value(1,0)
      put_y_variable(0,1)
      call(Pred_Name(X7366645F6D696E,2),0,3,"sfd_min",2)          /* begin sub 3 */
      put_constant(X246375725F6D696E,1,"$cur_min")
      put_y_unsafe_value(0,0)
      builtin_2(g_assign,1,0)
      fail

label(1)
      trust_me_else_fail
      cut_x(2)
      get_x_value(3,1)
      execute(Pred_Name(X63616C6C,1),0,"call",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "bool_maxof"
#define PRED       X626F6F6C5F6D61786F66
#define ARITY      2

Begin_Public_Pred
      allocate(3)
      get_y_variable(2,0)
      get_y_variable(1,1)
      get_y_bc_reg(0)
      put_constant(X246375725F6D6178,1,"$cur_max")
      put_integer(0,0)
      builtin_2(g_assign,1,0)
      call(Pred_Name(X726570656174,0),0,1,"repeat",0)          /* begin sub 1 */
      put_constant(X246375725F6D6178,1,"$cur_max")
      put_x_variable(3,0)
      builtin_2(g_read,1,0)
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_unsafe_value(0,2)
      deallocate
      execute(Pred_Name(X626F6F6C5F6D61786F665F2461757833,4),1,"bool_maxof_$aux3",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "bool_maxof_$aux3"
#define PRED       X626F6F6C5F6D61786F665F2461757833
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      allocate(4)
      get_y_variable(3,0)
      get_y_variable(1,1)
      get_y_bc_reg(2)
      put_y_value(1,0)
      put_x_value(3,1)
      call(Pred_Name(X70616320783E79,2),0,1,"pac x>y",2)          /* begin sub 1 */
      put_y_value(3,0)
      call(Pred_Name(X63616C6C,1),0,2,"call",1)          /* begin sub 2 */
      cut_y(2)
      put_y_value(1,0)
      put_y_variable(0,1)
      call(Pred_Name(X7366645F6D6178,2),0,3,"sfd_max",2)          /* begin sub 3 */
      put_constant(X246375725F6D6178,1,"$cur_max")
      put_y_unsafe_value(0,0)
      builtin_2(g_assign,1,0)
      fail

label(1)
      trust_me_else_fail
      cut_x(2)
      get_x_value(3,1)
      execute(Pred_Name(X63616C6C,1),0,"call",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(sfd_srg_bool)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X626F6F6C5F765F656C656D656E74,"bool_v_element")
 Define_Atom(X626F6F6C5F765F656C656D656E7431,"bool_v_element1")
 Define_Atom(X626F6F6C5F696E646F6D61696E,"bool_indomain")
 Define_Atom(X626F6F6C5F696E646F6D61696E5F2461757831,"bool_indomain_$aux1")
 Define_Atom(X626F6F6C5F6C6162656C696E67,"bool_labeling")
 Define_Atom(X626F6F6C5F6C6162656C696E676666,"bool_labelingff")
 Define_Atom(X626F6F6C5F6C6162656C696E67666631,"bool_labelingff1")
 Define_Atom(X626F6F6C5F616C6C646966666572656E74,"bool_alldifferent")
 Define_Atom(X626F6F6C5F6F75745F6F66,"bool_out_of")
 Define_Atom(X626F6F6C5F64696666,"bool_diff")
 Define_Atom(X626F6F6C5F676C6F62616C5F616C6C646966666572656E74,"bool_global_alldifferent")
 Define_Atom(X626F6F6C5F676C6F62616C5F616C6C646966666572656E745F617578,"bool_global_alldifferent_aux")
 Define_Atom(X626F6F6C5F676C6F62616C5F616C6C646966666572656E7432,"bool_global_alldifferent2")
 Define_Atom(X626F6F6C5F676C6F62616C5F616C6C646966666572656E74325F617578,"bool_global_alldifferent2_aux")
 Define_Atom(X626F6F6C5F6D696E6F66,"bool_minof")
 Define_Atom(X246375725F6D696E,"$cur_min")
 Define_Atom(X626F6F6C5F6D696E6F665F2461757832,"bool_minof_$aux2")
 Define_Atom(X626F6F6C5F6D61786F66,"bool_maxof")
 Define_Atom(X246375725F6D6178,"$cur_max")
 Define_Atom(X626F6F6C5F6D61786F665F2461757833,"bool_maxof_$aux3")


 Define_Pred(X626F6F6C5F765F656C656D656E74,3,1)

 Define_Pred(X626F6F6C5F765F656C656D656E7431,4,0)

 Define_Pred(X626F6F6C5F696E646F6D61696E,1,1)

 Define_Pred(X626F6F6C5F696E646F6D61696E5F2461757831,2,0)

 Define_Pred(X626F6F6C5F6C6162656C696E67,1,1)

 Define_Pred(X626F6F6C5F6C6162656C696E676666,1,1)

 Define_Pred(X626F6F6C5F6C6162656C696E67666631,2,0)

 Define_Pred(X626F6F6C5F616C6C646966666572656E74,1,1)

 Define_Pred(X626F6F6C5F6F75745F6F66,2,1)

 Define_Pred(X626F6F6C5F64696666,2,1)

 Define_Pred(X626F6F6C5F676C6F62616C5F616C6C646966666572656E74,1,1)

 Define_Pred(X626F6F6C5F676C6F62616C5F616C6C646966666572656E745F617578,2,0)

 Define_Pred(X626F6F6C5F676C6F62616C5F616C6C646966666572656E7432,1,1)

 Define_Pred(X626F6F6C5F676C6F62616C5F616C6C646966666572656E74325F617578,2,0)

 Define_Pred(X626F6F6C5F6D696E6F66,2,1)

 Define_Pred(X626F6F6C5F6D696E6F665F2461757832,4,0)

 Define_Pred(X626F6F6C5F6D61786F66,2,1)

 Define_Pred(X626F6F6C5F6D61786F665F2461757833,4,0)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(sfd_srg_bool)



End_Exec_Directives
