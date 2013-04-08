/****************************************************************************
Prolog to Wam Compiler - Version 2.0
Daniel Diaz, Yan Georget
1998 - INRIA Rocquencourt - LOCO Project
File : sfd_enumeration.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"
#include "sfd_engine.h"

#include "sfd_enumeration.h"
#include "sfd_enumeration.usr"


#define ASCII_PRED "blevel"
#define PRED       X626C6576656C
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
      put_x_value(1,0)
      execute(Pred_Name(X73656D6972696E675F756E697479,1),0,"semiring_unity",1)

label(4)
      retry_me_else(6)

label(5)
      get_list(0)
      unify_x_variable(0)
      unify_nil
      neck_cut
      execute(Pred_Name(X7366645F76616C7565,2),0,"sfd_value",2)

label(6)
      trust_me_else_fail

label(7)
      allocate(4)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_y_variable(0,1)
      neck_cut
      put_y_variable(2,1)
      call(Pred_Name(X7366645F76616C7565,2),0,2,"sfd_value",2)          /* begin sub 2 */
      put_y_value(3,0)
      put_y_variable(1,1)
      call(Pred_Name(X626C6576656C,2),1,3,"blevel",2)          /* begin sub 3 */
      put_y_unsafe_value(2,0)
      put_y_unsafe_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X73656D6972696E675F6D756C,3),0,"semiring_mul",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "deleteff"
#define PRED       X64656C6574656666
#define ARITY      3

Begin_Public_Pred
      switch_on_term(G_label(2),fail,fail,G_label(1),fail)

label(1)
      try(3,1)          /* begin sub 1 */
      trust(5)

label(2)
      try_me_else(4)

label(3)
      get_list(0)
      unify_x_variable(0)
      unify_nil
      get_x_value(0,1)
      get_nil(2)
      neck_cut
      proceed

label(4)
      trust_me_else_fail

label(5)
      allocate(5)
      get_list(0)
      unify_y_variable(4)
      unify_y_variable(3)
      get_y_variable(2,1)
      get_y_variable(1,2)
      put_y_value(4,0)
      put_y_variable(0,1)
      call(Pred_Name(X7366645F73697A65,2),0,2,"sfd_size",2)          /* begin sub 2 */
      put_y_value(4,0)
      put_y_value(3,1)
      put_y_value(2,2)
      put_y_value(1,3)
      put_y_unsafe_value(0,4)
      deallocate
      execute(Pred_Name(X64656C65746566665F2461757831,5),1,"deleteff_$aux1",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "deleteff_$aux1"
#define PRED       X64656C65746566665F2461757831
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      put_integer(1,0)
      builtin_2(term_eq,4,0)
      neck_cut
      put_x_value(1,0)
      put_x_value(2,1)
      put_x_value(3,2)
      execute(Pred_Name(X64656C6574656666,3),1,"deleteff",3)

label(1)
      trust_me_else_fail
      get_x_variable(7,0)
      get_x_variable(6,2)
      get_x_variable(5,3)
      put_x_value(1,0)
      put_x_value(7,1)
      put_x_value(4,2)
      put_x_value(6,3)
      put_nil(4)
      execute(Pred_Name(X64656C6574656666,6),1,"deleteff",6)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "deleteff"
#define PRED       X64656C6574656666
#define ARITY      6

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_x_value(1,3)
      get_x_value(4,5)
      neck_cut
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(8)
      get_list(0)
      unify_y_variable(7)
      unify_y_variable(6)
      get_y_variable(5,1)
      get_y_variable(4,2)
      get_y_variable(3,3)
      get_y_variable(2,4)
      get_y_variable(1,5)
      put_y_value(7,0)
      put_y_variable(0,1)
      call(Pred_Name(X7366645F73697A65,2),0,1,"sfd_size",2)          /* begin sub 1 */
      put_y_value(7,0)
      put_y_value(6,1)
      put_y_value(5,2)
      put_y_value(4,3)
      put_y_value(3,4)
      put_y_value(2,5)
      put_y_value(1,6)
      put_y_unsafe_value(0,7)
      deallocate
      execute(Pred_Name(X64656C65746566665F2461757832,8),1,"deleteff_$aux2",8)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "deleteff_$aux2"
#define PRED       X64656C65746566665F2461757832
#define ARITY      8

Begin_Private_Pred
      try_me_else(1)
      get_x_variable(9,0)
      get_x_variable(8,2)
      math_load_x_value(7,7)
      math_load_x_value(3,3)
      builtin_2(lte,7,3)
      neck_cut
      put_x_value(1,0)
      put_x_value(9,1)
      put_x_value(7,2)
      put_x_value(4,3)
      put_list(4)
      unify_x_local_value(8)
      unify_x_local_value(5)
      put_x_value(6,5)
      execute(Pred_Name(X64656C6574656666,6),1,"deleteff",6)

label(1)
      trust_me_else_fail
      get_x_variable(8,0)
      put_x_value(1,0)
      put_x_value(2,1)
      put_x_value(3,2)
      put_x_value(4,3)
      put_list(4)
      unify_x_local_value(8)
      unify_x_local_value(5)
      put_x_value(6,5)
      execute(Pred_Name(X64656C6574656666,6),1,"deleteff",6)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "indomain"
#define PRED       X696E646F6D61696E
#define ARITY      1

Begin_Public_Pred
      execute(Pred_Name(X696E646F6D61696E5F2461757833,1),1,"indomain_$aux3",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "indomain_$aux3"
#define PRED       X696E646F6D61696E5F2461757833
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
      call(Pred_Name(X7366645F696E646578,2),0,2,"sfd_index",2)          /* begin sub 2 */
      put_y_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X696E646F6D61696E5F2461757834,2),1,"indomain_$aux4",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "indomain_$aux4"
#define PRED       X696E646F6D61696E5F2461757834
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
      execute(Pred_Name(X696E646F6D61696E,1),1,"indomain",1)

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



#define ASCII_PRED "labeling"
#define PRED       X6C6162656C696E67
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
      call(Pred_Name(X696E646F6D61696E,1),1,1,"indomain",1)          /* begin sub 1 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X6C6162656C696E67,1),1,"labeling",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "labelingff"
#define PRED       X6C6162656C696E676666
#define ARITY      1

Begin_Public_Pred
      pragma_c(Labelingff_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "labelingff1"
#define PRED       X6C6162656C696E67666631
#define ARITY      2

Begin_Private_Pred
      allocate(1)
      get_y_variable(0,0)
      put_x_value(1,0)
      call(Pred_Name(X696E646F6D61696E,1),1,1,"indomain",1)          /* begin sub 1 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X6C6162656C696E676666,1),1,"labelingff",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(sfd_enumeration)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X626C6576656C,"blevel")
 Define_Atom(X64656C6574656666,"deleteff")
 Define_Atom(X64656C65746566665F2461757831,"deleteff_$aux1")
 Define_Atom(X64656C65746566665F2461757832,"deleteff_$aux2")
 Define_Atom(X696E646F6D61696E,"indomain")
 Define_Atom(X696E646F6D61696E5F2461757833,"indomain_$aux3")
 Define_Atom(X696E646F6D61696E5F2461757834,"indomain_$aux4")
 Define_Atom(X6C6162656C696E67,"labeling")
 Define_Atom(X6C6162656C696E676666,"labelingff")
 Define_Atom(X6C6162656C696E67666631,"labelingff1")


 Define_Pred(X626C6576656C,2,1)

 Define_Pred(X64656C6574656666,3,1)

 Define_Pred(X64656C65746566665F2461757831,5,0)

 Define_Pred(X64656C6574656666,6,0)

 Define_Pred(X64656C65746566665F2461757832,8,0)

 Define_Pred(X696E646F6D61696E,1,1)

 Define_Pred(X696E646F6D61696E5F2461757833,1,0)

 Define_Pred(X696E646F6D61696E5F2461757834,2,0)

 Define_Pred(X6C6162656C696E67,1,1)

 Define_Pred(X6C6162656C696E676666,1,1)

 Define_Pred(X6C6162656C696E67666631,2,0)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(sfd_enumeration)



End_Exec_Directives
