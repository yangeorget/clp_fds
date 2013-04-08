/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - LOCO Project  */
/* C Run-time                                          Daniel Diaz - 1992  */
/*                                                                         */
/* Modified by Yan Georget - June 1998                                     */
/* sfd_vector.h                                                            */
/*-------------------------------------------------------------------------*/


#include "sfd_semiring.h"


/*---------------------------------*/
/* Constants                       */
/*---------------------------------*/

#define RANGE_TOP_STACK            H
#define INTERVAL_INFINITY          INT_GREATEST_VALUE



#ifndef WORD_SIZE
#   define WORD_SIZE                32
#endif


#if WORD_SIZE==32

#   define WORD_SIZE_BITS          5

#else

#   define WORD_SIZE_BITS          6

#endif



#ifndef M_Mul
#   define M_Mul(x,y)               ((x) * (y))
#endif

#ifndef M_Div
#   define M_Div(x,y)               ((x) / (y))
#endif

#ifndef M_Mod
#   define M_Mod(x,y)               ((x) % (y))
#endif



#ifndef Lib0
#    define Lib0(f)                 f()
#endif

#ifndef Lib1
#    define Lib1(f,a1)              f(a1)
#endif

#ifndef Lib2
#    define Lib2(f,a1,a2)           f(a1,a2)
#endif

#ifndef Lib3
#    define Lib3(f,a1,a2,a3)        f(a1,a2,a3)
#endif

#ifndef Lib4
#    define Lib4(f,a1,a2,a3,a4)     f(a1,a2,a3,a4)
#endif

#ifndef Lib5
#    define Lib5(f,a1,a2,a3,a4,a5)  f(a1,a2,a3,a4,a5)
#endif



#define ALL_1                      0xFFFFFFFF


#define M_Floor_Div(x,y)            (M_Div(x,y))
#define M_Ceil_Div(x,y)             (M_Div(((x) + (y) - 1),(y)))

#define math_min(x,y)              ((x) <= (y) ? (x) : (y))
#define math_max(x,y)              ((x) >= (y) ? (x) : (y))




#define Display_Vector_Too_Small                                            \
     Lib1(printf,MSG_VECTOR_TOO_SMALL);

#define MSG_VECTOR_TOO_SMALL    "Warning: Vector too small - maybe lost solutions\n"




/*---------------------------------*/
/* SFD constants                   */
/*---------------------------------*/

/* the following holds for all the lc-semirings */

#define A_NB          (1<<A_SIZE)                 /* nb of elements in A */
#define A_WD_SZ       (sizeof(WamWord)*8/A_SIZE)  /* nb of A elements in a Word */

#define NullA                  0
#define UnityA                 A_MASK

#define IsNullA(x)             (x == NullA)
#define IsUnityA(x)            (x == UnityA)      
/* #define GreaterOrEqualA(x,y)   (AddA(x,y) == x)  */
/* #define GreaterA(x,y)          ((x != y) && (AddA(x,y) == x))   */
/* #define LessOrEqualA(x,y)      (AddA(x,y) == y)  */
/* #define LessA(x,y)             ((x != y) && (AddA(x,y) == y))   */



/*---------------------------------*/
/* Type Definitions                */
/*---------------------------------*/


typedef  unsigned long VecWord;

typedef VecWord* Vector;



/*---------------------------------*/
/* Function Prototypes             */
/*---------------------------------*/

int      Most_Significant_ABit    (unsigned long x) ;
int      Least_Significant_ABit   (unsigned long x) ;
int      Bits_Nb_In_Value         (VecWord value);
int      Vector_Min               (Vector vec);
int      Vector_Max               (Vector vec);
int      Vector_Nb_Elem           (Vector vec) ;
void     Define_Vector_Size       (int max_val);

void     Set_Vector_Full             (Vector vec);
void     Set_Vector_Empty            (Vector vec);
void     Set_Vector_Term             (Vector vec, int n, VecWord v);
void     Set_Vector_Comp_Term        (Vector vec, int n);
void     Set_Vector_Interval         (Vector vec, int min, int max);
void     Set_Vector_Interval_Value   (Vector vec, int min, int max, int value);
void     Set_Vector_Comp_Interval    (Vector vec, int min, int max);
 
void     Vector_Copy              (Vector vec,Vector vec1);
Bool     Vector_Contain_Vector    (Vector vec,Vector vec1);
Bool     Vector_Contain_Interval  (Vector vec,int min,int max);
Bool     Vector_Equal             (Vector vec,Vector vec1);
Bool     Vector_Intersection      (Vector vec,Vector vec1);
void     Vector_Comp              (Vector vec);

void     Vector_AddA_Vector       (Vector vec,Vector vec1);
void     Vector_MulA_Vector       (Vector vec,Vector vec1);
void     Vector_AddA_Term         (Vector vec,VecWord n);
void     Vector_MulA_Term         (Vector vec,VecWord n);

void     Vector_Cut_L_A_Term      (Vector vec,VecWord n);
void     Vector_Cut_Le_A_Term     (Vector vec,VecWord n);
void     Vector_Cut_G_A_Term      (Vector vec,VecWord n);
void     Vector_Cut_Ge_A_Term     (Vector vec,VecWord n);
void     Vector_Cut_D_A_Term      (Vector vec,VecWord n);
void     Vector_Cut_Np_A_Term     (Vector vec,VecWord n);
void     Vector_Cut_Nnp_A_Term    (Vector vec,VecWord n);

void     Vector_Keep_L_A_Term     (Vector vec,VecWord n);
void     Vector_Keep_Le_A_Term    (Vector vec,VecWord n);
void     Vector_Keep_G_A_Term     (Vector vec,VecWord n);
void     Vector_Keep_Ge_A_Term    (Vector vec,VecWord n);
void     Vector_Keep_D_A_Term     (Vector vec,VecWord n);
void     Vector_Keep_Np_A_Term    (Vector vec,VecWord n);
void     Vector_Keep_Nnp_A_Term   (Vector vec,VecWord n);

VecWord  Vector_Sigma             (Vector vec);
void     Vector_LeA               (Vector vec);
void     Vector_LA                (Vector vec);
void     Vector_GeA               (Vector vec);
void     Vector_GA                (Vector vec);
void     Vector_DA                (Vector vec);

void     Add_Vector_Vector        (Vector vec, Vector vec1);
void     Sub_Vector_Vector        (Vector vec, Vector vec1);
void     Mul_Vector_Vector        (Vector vec, Vector vec1);
void     Div_Vector_Vector        (Vector vec, Vector vec1);

void     Add_Vector_Term          (Vector vec, int n);
void     Sub_Vector_Term          (Vector vec, int n);
void     Mul_Vector_Term          (Vector vec, int n);
void     Div_Vector_Term          (Vector vec, int n);

void     Vector_Value_Index       (Vector vec, VecWord *bv, int *bi);
void     Sets_Vector_Value_Index  (Vector vec, int *bn, int *bi);



/*---------------------------------*/
/* Word Management Macros          */
/*---------------------------------*/

#define ValA(w,i)  ((((VecWord) (w)) >> (((unsigned int) (i)) << A_SIZE_BITS)) & A_MASK)
 

#define Set_ValA(w,i,a)                 \
({                                      \
  unsigned int dec = (i)<<A_SIZE_BITS ; \
  (w) &= (VecWord) ~(A_MASK<<dec);      \
  (w) |= (VecWord) (a)<<dec ;           \
})


#define Set_ValA_Unity(w,i)             \
({                                      \
  unsigned int dec = (i)<<A_SIZE_BITS ; \
  (w) |= (VecWord) (A_MASK<<dec);       \
})


#define Set_ValA_Null(w,i)              \
({                                      \
  unsigned int dec = (i)<<A_SIZE_BITS ; \
  (w) &= (VecWord) ~(A_MASK<<dec);      \
})


#define Add_ValA(w,i,a)                 \
({                                      \
  VecWord na = AddA(ValA((w),(i)),(a)) ;\
  Set_ValA((w),(i),na) ;                \
})


#define Mul_ValA(w,i,a)                 \
({                                      \
  VecWord na = MulA(ValA((w),(i)),(a)) ;\
  Set_ValA((w),(i),na) ;                \
})



/*---------------------------------*/
/* Vector Management Macros        */
/*---------------------------------*/

#define Word_Nb(n)                                                          \
     (((unsigned int) (n)) >> A_WD_SZ_BITS)


#define ABit_Nb(n)                                                          \
     (((unsigned int) (n)) & ((((VecWord) 1) << A_WD_SZ_BITS)-1))


#define Word_Nb_And_Bit_Nb(w,b)                                             \
     ((((VecWord) (w)) << A_WD_SZ_BITS)|((unsigned int) (b)))


#define ValA_Vector(vec,n)                                                  \
     (ValA(vec[Word_Nb((n))],ABit_Nb((n))))


#define Safe_ValA_Vector(vec,n)                                             \
     (0<=n && n<=vec_infinity)?(ValA(vec[Word_Nb((n))],ABit_Nb((n)))):NullA


#define Set_ValA_Vector(vec,n,a)                                            \
     (Set_ValA((vec)[Word_Nb((n))],ABit_Nb((n)),a))


#define Set_ValA_Null_Vector(vec,n)                                         \
     (Set_ValA_Null((vec)[Word_Nb((n))],ABit_Nb((n))))


#define Set_ValA_Unity_Vector(vec,n)                                        \
     (Set_ValA_Unity((vec)[Word_Nb((n))],ABit_Nb((n))))


#define Add_ValA_Vector(vec,n,a)                                            \
     (Add_ValA((vec)[Word_Nb((n))],ABit_Nb((n)),(a)))


#define Mul_ValA_Vector(vec,n,a)                                            \
     (Mul_ValA((vec)[Word_Nb((n))],ABit_Nb((n)),(a)))



#define Vector_Allocate_If_Necessary(vec)                                   \
    ({                                                                      \
     if ((vec)==NULL)                                                       \
         Vector_Allocate((vec));                                            \
    })


#define Vector_Allocate(vec)                                                \
    ({                                                                      \
     vec=(Vector) RANGE_TOP_STACK;                                          \
     RANGE_TOP_STACK += vec_size;                                           \
    })


#define Temporary_Vector_Allocate(vec)                                      \
    Vector_Allocate(vec)


#define Temporary_Vector_Free(vec)                                          \
    ({                                                                      \
       RANGE_TOP_STACK = RANGE_TOP_STACK-vec_size;                          \
    })


#define BEGIN_ENUM_VECTORA(vec)                                             \
   ({                                                                       \
     VecWord     vec_val;                                                   \
     int     enum_i,enum_j;                                                 \
     for(enum_i=0;enum_i<vec_size;enum_i++)                                 \
        {                                                                   \
         for(enum_j=0; enum_j<A_WD_SZ;enum_j++)                             \
	    {                                                               \
	     vec_val = ValA(vec[enum_i],enum_j);                            \

#define END_ENUM_VECTORA                                                    \
            }                                                               \
        }                                                                   \
   });


#define BEGIN_ENUM_VECTORAA(vec)                                            \
   ({                                                                       \
     VecWord     vec_val;                                                   \
     int     enum_i,enum_j;                                                 \
     int     vec_elem=0 ;                                                   \
     for(enum_i=0;enum_i<vec_size;enum_i++)                                 \
        {                                                                   \
         for(enum_j=0; enum_j<A_WD_SZ;enum_j++)                             \
	    {                                                               \
	     vec_val = ValA(vec[enum_i],enum_j);                            \
	    
#define END_ENUM_VECTORAA                                                   \
             vec_elem++ ;                                                   \
            }                                                               \
        }                                                                   \
   });


#define BEGIN_REV_ENUM_VECTORA(vec)                                         \
   ({                                                                       \
     VecWord     vec_val;                                                   \
     int     enum_i,enum_j;                                                 \
     for(enum_i=vec_size-1;enum_i>=0;enum_i--)                              \
        {                                                                   \
         for(enum_j=A_WD_SZ; --enum_j>=0;)                                  \
	    {                                                               \
	     vec_val = ValA(vec[enum_i],enum_j);                            \

#define END_REV_ENUM_VECTORA                                                \
            }                                                               \
        }                                                                   \
   });



