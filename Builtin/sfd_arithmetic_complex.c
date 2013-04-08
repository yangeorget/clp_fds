/****************************************************************************
Prolog to Wam Compiler - Version 2.0
Daniel Diaz, Yan Georget
1998 - INRIA Rocquencourt - LOCO Project
File : sfd_arithmetic_complex.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"
#include "sfd_engine.h"

#include "sfd_arithmetic_complex.h"
#include "sfd_arithmetic_complex.usr"


#define ASCII_PRED "alldifferent"
#define PRED       X616C6C646966666572656E74
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
      call(Pred_Name(X6F75745F6F66,2),1,1,"out_of",2)          /* begin sub 1 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X616C6C646966666572656E74,1),1,"alldifferent",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "out_of"
#define PRED       X6F75745F6F66
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
      call(Pred_Name(X783C3E79,2),0,1,"x<>y",2)          /* begin sub 1 */
      put_y_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X6F75745F6F66,2),1,"out_of",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "increasing"
#define PRED       X696E6372656173696E67
#define ARITY      1

Begin_Public_Pred
      switch_on_term(G_label(2),G_label(3),fail,G_label(1),fail)

label(1)
      try(5,1)          /* begin sub 1 */
      trust(7)

label(2)
      try_me_else(4)

label(3)
      get_nil(0)
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_list(0)
      unify_void(1)
      unify_nil
      neck_cut
      proceed

label(6)
      trust_me_else_fail

label(7)
      allocate(2)
      get_list(0)
      unify_x_variable(1)
      unify_x_variable(0)
      get_list(0)
      unify_y_variable(1)
      unify_y_variable(0)
      put_y_value(1,0)
      call(Pred_Name(X70616320783E3D79,2),0,2,"pac x>=y",2)          /* begin sub 2 */
      put_list(0)
      unify_y_value(1)
      unify_y_value(0)
      deallocate
      execute(Pred_Name(X696E6372656173696E67,1),1,"increasing",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "decreasing"
#define PRED       X64656372656173696E67
#define ARITY      1

Begin_Public_Pred
      switch_on_term(G_label(2),G_label(3),fail,G_label(1),fail)

label(1)
      try(5,1)          /* begin sub 1 */
      trust(7)

label(2)
      try_me_else(4)

label(3)
      get_nil(0)
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_list(0)
      unify_void(1)
      unify_nil
      neck_cut
      proceed

label(6)
      trust_me_else_fail

label(7)
      allocate(2)
      get_list(0)
      unify_x_variable(0)
      unify_x_variable(1)
      get_list(1)
      unify_y_variable(1)
      unify_y_variable(0)
      put_y_value(1,1)
      call(Pred_Name(X70616320783E3D79,2),0,2,"pac x>=y",2)          /* begin sub 2 */
      put_list(0)
      unify_y_value(1)
      unify_y_value(0)
      deallocate
      execute(Pred_Name(X64656372656173696E67,1),1,"decreasing",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "strictly_increasing"
#define PRED       X7374726963746C795F696E6372656173696E67
#define ARITY      1

Begin_Public_Pred
      switch_on_term(G_label(2),G_label(3),fail,G_label(1),fail)

label(1)
      try(5,1)          /* begin sub 1 */
      trust(7)

label(2)
      try_me_else(4)

label(3)
      get_nil(0)
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_list(0)
      unify_void(1)
      unify_nil
      neck_cut
      proceed

label(6)
      trust_me_else_fail

label(7)
      allocate(2)
      get_list(0)
      unify_x_variable(1)
      unify_x_variable(0)
      get_list(0)
      unify_y_variable(1)
      unify_y_variable(0)
      put_y_value(1,0)
      call(Pred_Name(X70616320783E79,2),0,2,"pac x>y",2)          /* begin sub 2 */
      put_list(0)
      unify_y_value(1)
      unify_y_value(0)
      deallocate
      execute(Pred_Name(X7374726963746C795F696E6372656173696E67,1),1,"strictly_increasing",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "strictly_decreasing"
#define PRED       X7374726963746C795F64656372656173696E67
#define ARITY      1

Begin_Public_Pred
      switch_on_term(G_label(2),G_label(3),fail,G_label(1),fail)

label(1)
      try(5,1)          /* begin sub 1 */
      trust(7)

label(2)
      try_me_else(4)

label(3)
      get_nil(0)
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_list(0)
      unify_void(1)
      unify_nil
      neck_cut
      proceed

label(6)
      trust_me_else_fail

label(7)
      allocate(2)
      get_list(0)
      unify_x_variable(0)
      unify_x_variable(1)
      get_list(1)
      unify_y_variable(1)
      unify_y_variable(0)
      put_y_value(1,1)
      call(Pred_Name(X70616320783E79,2),0,2,"pac x>y",2)          /* begin sub 2 */
      put_list(0)
      unify_y_value(1)
      unify_y_value(0)
      deallocate
      execute(Pred_Name(X7374726963746C795F64656372656173696E67,1),1,"strictly_decreasing",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sum"
#define PRED       X73756D
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
      fd_install_constraint_with_x_AF(1,0)
      fd_call_constraint
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_list(0)
      unify_x_variable(0)
      unify_nil
      neck_cut
      execute(Pred_Name(X70616320783D79,2),0,"pac x=y",2)

label(6)
      trust_me_else_fail

label(7)
      allocate(3)
      get_list(0)
      unify_y_variable(2)
      unify_x_variable(0)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(2)
      get_y_variable(0,1)
      neck_cut
      put_list(0)
      unify_x_value(3)
      unify_x_value(2)
      put_y_variable(1,1)
      call(Pred_Name(X73756D,2),1,2,"sum",2)          /* begin sub 2 */
      put_y_value(2,0)
      put_y_unsafe_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X70616320782B793D7A,3),0,"pac x+y=z",3)

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

      fd_integer(1,0)
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



#define ASCII_PRED "choose"
#define PRED       X63686F6F7365
#define ARITY      2

Begin_Public_Pred
      switch_on_term(G_label(2),fail,fail,G_label(1),fail)

label(1)
      try(3,1)          /* begin sub 1 */
      trust(5)

label(2)
      try_me_else(4)

label(3)
      get_list(0)
      unify_x_variable(2)
      unify_nil
      neck_cut
      put_x_value(1,0)
      put_x_value(2,1)
      execute(Pred_Name(X783D79,2),0,"x=y",2)

label(4)
      trust_me_else_fail

label(5)
      allocate(3)
      get_list(0)
      unify_y_variable(1)
      unify_x_variable(0)
      get_y_variable(2,1)
      put_y_variable(0,1)
      call(Pred_Name(X63686F6F7365,2),1,2,"choose",2)          /* begin sub 2 */
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_unsafe_value(0,2)
      deallocate
      execute(Pred_Name(X783D63686F6F736528792C7A29,3),0,"x=choose(y,z)",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "min"
#define PRED       X6D696E
#define ARITY      2

Begin_Public_Pred
      switch_on_term(G_label(2),fail,fail,G_label(1),fail)

label(1)
      try(3,1)          /* begin sub 1 */
      trust(5)

label(2)
      try_me_else(4)

label(3)
      get_list(0)
      unify_x_variable(2)
      unify_nil
      neck_cut
      put_x_value(1,0)
      put_x_value(2,1)
      execute(Pred_Name(X783D79,2),0,"x=y",2)

label(4)
      trust_me_else_fail

label(5)
      allocate(3)
      get_list(0)
      unify_y_variable(1)
      unify_x_variable(0)
      get_y_variable(2,1)
      put_y_variable(0,1)
      call(Pred_Name(X6D696E,2),1,2,"min",2)          /* begin sub 2 */
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_unsafe_value(0,2)
      deallocate
      execute(Pred_Name(X783D6D696E28792C7A29,3),0,"x=min(y,z)",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "max"
#define PRED       X6D6178
#define ARITY      2

Begin_Public_Pred
      switch_on_term(G_label(2),fail,fail,G_label(1),fail)

label(1)
      try(3,1)          /* begin sub 1 */
      trust(5)

label(2)
      try_me_else(4)

label(3)
      get_list(0)
      unify_x_variable(2)
      unify_nil
      neck_cut
      put_x_value(1,0)
      put_x_value(2,1)
      execute(Pred_Name(X783D79,2),0,"x=y",2)

label(4)
      trust_me_else_fail

label(5)
      allocate(3)
      get_list(0)
      unify_y_variable(1)
      unify_x_variable(0)
      get_y_variable(2,1)
      put_y_variable(0,1)
      call(Pred_Name(X6D6178,2),1,2,"max",2)          /* begin sub 2 */
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_unsafe_value(0,2)
      deallocate
      execute(Pred_Name(X783D6D617828792C7A29,3),0,"x=max(y,z)",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(sfd_arithmetic_complex)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X616C6C646966666572656E74,"alldifferent")
 Define_Atom(X6F75745F6F66,"out_of")
 Define_Atom(X696E6372656173696E67,"increasing")
 Define_Atom(X64656372656173696E67,"decreasing")
 Define_Atom(X7374726963746C795F696E6372656173696E67,"strictly_increasing")
 Define_Atom(X7374726963746C795F64656372656173696E67,"strictly_decreasing")
 Define_Atom(X73756D,"sum")
 Define_Atom(X63686F6F7365,"choose")
 Define_Atom(X6D696E,"min")
 Define_Atom(X6D6178,"max")


 Define_Pred(X616C6C646966666572656E74,1,1)

 Define_Pred(X6F75745F6F66,2,1)

 Define_Pred(X696E6372656173696E67,1,1)

 Define_Pred(X64656372656173696E67,1,1)

 Define_Pred(X7374726963746C795F696E6372656173696E67,1,1)

 Define_Pred(X7374726963746C795F64656372656173696E67,1,1)

 Define_Pred(X73756D,2,1)

 Define_Pred(X63686F6F7365,2,1)

 Define_Pred(X6D696E,2,1)

 Define_Pred(X6D6178,2,1)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(sfd_arithmetic_complex)



End_Exec_Directives
