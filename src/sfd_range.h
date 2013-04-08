/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - LOCO Project  */
/* C Run-time                                          Daniel Diaz - 1992  */
/*                                                                         */
/* Modified by Yan Georget - June 1998                                     */
/* sfd_range.h                                                             */
/*-------------------------------------------------------------------------*/


#include "sfd_vector.h"



/*---------------------------------*/
/* Constants                       */
/*---------------------------------*/

/* MODES for fdv */
#define R_SPARSE        0
#define R_INTERVAL      1
#define R_INTEGER       2
#define R_EMPTY         3 


/*---------------------------------*/
/* Type Definitions                */
/*---------------------------------*/

typedef struct               /* Ranges are always handled through pointers */
    {
      VecWord    sigma;
      Vector     vec;
      int        min;
      int        max;
      int        mode;
    }Range;



/*---------------------------------*/
/* Function Prototypes             */
/*---------------------------------*/

void    Init_Range_Full            (Range *r);
void    Init_Range_Empty           (Range *r);
void    Init_Range_Term            (Range *r, int n, VecWord v);
void    Init_Range_Comp_Term       (Range *r, int n);
void    Init_Range_Interval        (Range *r, int min, int max, VecWord value);
void    Init_Range_Range           (Range *r, Range *r1);

void    Set_Range_Full             (Range *r);
void    Set_Range_Empty            (Range *r);
void    Set_Range_Term             (Range *r, int n, VecWord v);
void    Set_Range_Comp_Term        (Range *r, int n);
void    Set_Range_Interval         (Range *r, int min, int max, VecWord value);
void    Set_Range_Comp_Interval    (Range *r, int min, int max);

int     Range_Nb_Elem              (Range *range) ;
VecWord Value_Of_Int_In_Range      (Range *range,int n);

void    Range_Copy                 (Range *range,Range *range1);
Bool    Range_Contain              (Range *range,Range *range1);
Bool    Range_Intersection         (Range *range,Range *range1);
void    Range_From_Vector          (Range *range);
void    Range_Becomes_Sparse       (Range *range);

void    Range_AddA_Range           (Range *range,Range *range1);
void    Range_MulA_Range           (Range *range,Range *range1);

void    Range_AddA_Term            (Range *range,VecWord n);
void    Range_MulA_Term            (Range *range,VecWord n);

void    Range_Cut_L_A_Term         (Range *range,VecWord n);
void    Range_Cut_Le_A_Term        (Range *range,VecWord n);
void    Range_Cut_G_A_Term         (Range *range,VecWord n);
void    Range_Cut_Ge_A_Term        (Range *range,VecWord n);
void    Range_Cut_D_A_Term         (Range *range,VecWord n);
void    Range_Cut_Np_A_Term        (Range *range,VecWord n);
void    Range_Cut_Nnp_A_Term       (Range *range,VecWord n);

void    Range_Keep_L_A_Term        (Range *range,VecWord n);
void    Range_Keep_Le_A_Term       (Range *range,VecWord n);
void    Range_Keep_G_A_Term        (Range *range,VecWord n);
void    Range_Keep_Ge_A_Term       (Range *range,VecWord n);
void    Range_Keep_D_A_Term        (Range *range,VecWord n);
void    Range_Keep_Np_A_Term       (Range *range,VecWord n);
void    Range_Keep_Nnp_A_Term      (Range *range,VecWord n);

void    Range_LeA                 (Range *range);
void    Range_LA                  (Range *range);
void    Range_GeA                 (Range *range);
void    Range_GA                  (Range *range);
void    Range_DA                  (Range *range);

void    Add_Range_Range            (Range *range,Range *range1);
void    Sub_Range_Range            (Range *range,Range *range1);
void    Mul_Range_Range            (Range *range,Range *range1);
void    Div_Range_Range            (Range *range,Range *range1);

void    Add_Range_Term             (Range *range, int n);
void    Sub_Range_Term             (Range *range, int n);
void    Mul_Range_Term             (Range *range, int n);
void    Div_Range_Term             (Range *range, int n);

void    Range_Write                (FILE *out,Range *range);

void    Range_Value_Index          (Range *range, VecWord *bv, int *bi);
void    Sets_Range_Value_Index     (Range *range, int *bv, int *bi);













