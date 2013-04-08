/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - LOCO Project  */
/* C Run-time                                          Daniel Diaz - 1992  */
/*                                                                         */
/* Modified by Yan Georget - June 1998                                     */
/* sfd_vector.c                                                            */
/*-------------------------------------------------------------------------*/

#include <stdio.h>
#include "bool.h"
#include "sfd_vector.h"
#include "wam_engine.h"

/*-------------------------------------------------------------------------*/
/* LEAST_SIGNIFICANT_ABIT                                                   */
/*                                                                         */
/*-------------------------------------------------------------------------*/
int Least_Significant_ABit(VecWord x)

{
 int bit=0;
 
 while (IsNullA(ValA(x,bit)))
    bit++ ;

 return bit;
}


/*-------------------------------------------------------------------------*/
/* MOST_SIGNIFICANT_ABIT                                                   */
/*                                                                         */
/*-------------------------------------------------------------------------*/
int Most_Significant_ABit(VecWord x)

{
 int bit=A_WD_SZ - 1;
 
 while (IsNullA(ValA(x,bit)))
    bit-- ;

 return bit;

}


/*-------------------------------------------------------------------------*/
/* BITS_NB_IN_VALUE                                                        */
/*                                                                         */
/*-------------------------------------------------------------------------*/
int Bits_Nb_In_Value(VecWord value)
{
  static int nb_bits_in_byte[256]=
         {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
          1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
          1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
          2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
          1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
          2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
          2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
          3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8};

  int nb_elem=0;

  nb_elem+=nb_bits_in_byte[ value      & 0xFF];
  nb_elem+=nb_bits_in_byte[(value>> 8) & 0xFF];
  nb_elem+=nb_bits_in_byte[(value>>16) & 0xFF];
  nb_elem+=nb_bits_in_byte[(value>>24) & 0xFF];

  return nb_elem;
}


/*-------------------------------------------------------------------------*/
/* VECTOR_MIN                                                              */
/*                                                                         */
/*-------------------------------------------------------------------------*/
int Vector_Min(Vector vec)
{
 Vector start, end;
 int    lsb;

 start=vec-1;
 end  =vec+vec_size;
 
 for(;;)
     if (*++start)
         break;
     else
         if (start>=end)
            return -1 ;

 lsb = Least_Significant_ABit(*start);

 return Word_Nb_And_Bit_Nb(start-vec,lsb) ; 
}


/*-------------------------------------------------------------------------*/
/* VECTOR_MAX                                                              */
/*                                                                         */
/*-------------------------------------------------------------------------*/
int Vector_Max(Vector vec)
{
 Vector start, end;
 int    msb;

 start=vec-1;
 end  =vec+vec_size;
 
 for(;;)
     if (*--end)
         break;
     else
         if (start>=end)
            return -1 ;

 msb = Most_Significant_ABit(*end);

 return Word_Nb_And_Bit_Nb(end-vec,msb) ; 
}


/*-------------------------------------------------------------------------*/
/* DEFINE_VECTOR_SIZE                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Define_Vector_Size(int max_val)

{
 vec_size    = M_Div(M_Mul(max_val,A_SIZE),WORD_SIZE)+1;
 vec_infinity= M_Div(M_Mul(vec_size,WORD_SIZE),A_SIZE)-1;
/*  Lib2(printf,"max_val %i\n", max_val); */
/*  Lib2(printf,"A_SIZE %i\n", A_SIZE); */
/*  Lib2(printf,"WORD_SIZE %i\n", WORD_SIZE); */
/*  Lib2(printf,"vec_size %i\n", vec_size); */
/*  Lib2(printf,"vec_infinity %i\n", vec_infinity);   */
}


/*-------------------------------------------------------------------------*/
/* VECTOR_NB_ELEM                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
int Vector_Nb_Elem(Vector vec)

{
  int n=0 ;

  BEGIN_ENUM_VECTORA(vec)
    n += (!IsNullA(vec_val)) ;
  END_ENUM_VECTORA

  return n ;
}


/*-------------------------------------------------------------------------*/
/* SET_VECTOR_FULL                                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Set_Vector_Full(Vector vec)

{
 Vector end=vec+vec_size;

 do
     *vec++ = ALL_1 ;
 while(vec<end);
}


/*-------------------------------------------------------------------------*/
/* SET_VECTOR_EMPTY                                                        */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Set_Vector_Empty(Vector vec)

{
 Vector end=vec+vec_size;

 do
     *vec++ = 0 ;
 while(vec<end);

}


/*-------------------------------------------------------------------------*/
/* SET_VECTOR_COMP_TERM                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Set_Vector_Term(Vector vec, int n, VecWord v)
{
  Set_Vector_Empty(vec);
  Set_ValA_Vector(vec,n,v);
}


/*-------------------------------------------------------------------------*/
/* SET_VECTOR_COMP_TERM                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Set_Vector_Comp_Term(Vector vec, int n)
{
  Set_Vector_Full(vec);
  Set_ValA_Null_Vector(vec,n);
}


/*-------------------------------------------------------------------------*/
/* SET_VECTOR_INTERVAL                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Set_Vector_Interval(Vector vec, int min, int max)

{
     int n ;                                                           
	
     min = math_max(0,min);
     max = math_min(vec_infinity,max);

     Set_Vector_Empty(vec) ;
     
     for( n=min ; n<=max ; n++ )
       Set_ValA_Unity_Vector(vec,n);
}


/*-------------------------------------------------------------------------*/
/* SET_VECTOR_INTERVAL_VALUE                                               */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Set_Vector_Interval_Value(Vector vec, int min, int max, int value)

{
     int n ;                                                           
	
     min = math_max(0,min);
     max = math_min(vec_infinity,max);

     Set_Vector_Empty(vec) ;
     
     for( n=min ; n<=max ; n++ )
       Set_ValA_Vector(vec,n,value);
}


/*-------------------------------------------------------------------------*/
/* SET_VECTOR_COMP_INTERVAL                                                */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Set_Vector_Comp_Interval(Vector vec, int min, int max)

{
     int n ;                                                           

     min = math_max(0,min);
     max = math_min(vec_infinity,max);
		
     Set_Vector_Full(vec) ;

     for( n=min ; n<=max ; n++ )
	 Set_ValA_Null_Vector(vec,n);
}


/*-------------------------------------------------------------------------*/
/* VECTOR_COMP                                                             */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_Comp(Vector vec)
{
  BEGIN_ENUM_VECTORAA(vec)     
    if (IsNullA(vec_val))
      Set_ValA_Unity_Vector(vec,vec_elem);
    else
      Set_ValA_Null_Vector(vec,vec_elem);
  END_ENUM_VECTORAA
}


/*-------------------------------------------------------------------------*/
/* VECTOR_COPY                                                             */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_Copy(Vector vec,Vector vec1)

{
 Vector end=vec+vec_size;

 do
     *vec++ = *vec1++;
 while(vec<end);
}


/*-------------------------------------------------------------------------*/
/* VECTOR_CONTAIN_VECTOR                                                   */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Vector_Contain_Vector(Vector vec,Vector vec1)

{
  int i = -1 ;

  do
    {
      i++ ;
      if (!IsNullA(ValA_Vector(vec1,i)))
	if (IsNullA(ValA_Vector(vec,i)))
	  return FALSE ;
    }
  while (i<vec_infinity);
  
  return TRUE ;
}


/*-------------------------------------------------------------------------*/
/* VECTOR_CONTAIN_INTERVAL                                                 */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Vector_Contain_Interval(Vector vec, int min, int max)

{
  int i ;

  for(i = min ; i <= max ; i++)
    {
      if (IsNullA(ValA_Vector(vec,i)))
	return FALSE ;
    }

  return TRUE ;
}


/*-------------------------------------------------------------------------*/
/* VECTOR_INTERSECTION                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Vector_Intersection(Vector vec,Vector vec1)

{
  int i = 0 ;

  do
    {
      if (MulA(ValA_Vector(vec,i),ValA_Vector(vec1,i)) != NullA)
	return TRUE;
      i++;
    }
  while (i <= vec_infinity);
  
  return FALSE;
}


/*-------------------------------------------------------------------------*/
/* VECTOR_EQUAL                                                            */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Vector_Equal(Vector vec,Vector vec1)

{
 Vector end=vec+vec_size;

 do
   if (*vec++ != *vec1++) 
       return FALSE;
 while(vec<end);

 return TRUE ;
}


/*-------------------------------------------------------------------------*/
/* VECTOR_ADDA_VECTOR                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/

void Vector_AddA_Vector(Vector vec,Vector vec1)
{
    int     enum_i,enum_j;            
     
    for(enum_i=0;enum_i<vec_size;enum_i++) 
      for(enum_j=0; enum_j<A_WD_SZ;enum_j++) 
	Add_ValA(vec[enum_i], enum_j, ValA(vec1[enum_i],enum_j)) ;
}


/*-------------------------------------------------------------------------*/
/* VECTOR_MULA_VECTOR                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_MulA_Vector(Vector vec,Vector vec1)
{
    int     enum_i,enum_j;            
     
    for(enum_i=0;enum_i<vec_size;enum_i++)  
      for(enum_j=0; enum_j<A_WD_SZ;enum_j++) 
	 Mul_ValA(vec[enum_i], enum_j, ValA(vec1[enum_i],enum_j)) ;
}


/*-------------------------------------------------------------------------*/
/* VECTOR_ADDA_TERM                                                        */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_AddA_Term(Vector vec,VecWord n)
{
    int     enum_i,enum_j;            
     
    for(enum_i=0;enum_i<vec_size;enum_i++)  
      for(enum_j=0; enum_j<A_WD_SZ;enum_j++) 
	 Add_ValA(vec[enum_i], enum_j, n) ;
}


/*-------------------------------------------------------------------------*/
/* VECTOR_MULA_TERM                                                        */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_MulA_Term(Vector vec,VecWord n)
{
  int     enum_i,enum_j;            
  
  for(enum_i=0;enum_i<vec_size;enum_i++)  
    for(enum_j=0; enum_j<A_WD_SZ;enum_j++) 
      Mul_ValA(vec[enum_i], enum_j, n) ;
}


/*-------------------------------------------------------------------------*/
/* VECTOR_CUT_L_A_TERM                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_Cut_L_A_Term(Vector vec,VecWord n)
{
  BEGIN_ENUM_VECTORA(vec)     
    if (LessA(vec_val,n))
      Set_ValA_Null(vec[enum_i],enum_j);
  END_ENUM_VECTORA
}


/*-------------------------------------------------------------------------*/
/* VECTOR_CUT_LE_A_TERM                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_Cut_Le_A_Term(Vector vec,VecWord n)
{
  BEGIN_ENUM_VECTORA(vec)     
    if (LessOrEqualA(vec_val,n))
      Set_ValA_Null(vec[enum_i],enum_j);
  END_ENUM_VECTORA
}


/*-------------------------------------------------------------------------*/
/* VECTOR_CUT_G_A_TERM                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_Cut_G_A_Term(Vector vec,VecWord n)
{
  BEGIN_ENUM_VECTORA(vec)     
    if (GreaterA(vec_val,n))
      Set_ValA_Null(vec[enum_i],enum_j);
  END_ENUM_VECTORA
}


/*-------------------------------------------------------------------------*/
/* VECTOR_CUT_GE_A_TERM                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_Cut_Ge_A_Term(Vector vec,VecWord n)
{
  BEGIN_ENUM_VECTORA(vec)     
    if (GreaterOrEqualA(vec_val,n))
      Set_ValA_Null(vec[enum_i],enum_j);
  END_ENUM_VECTORA
}

 
/*-------------------------------------------------------------------------*/
/* VECTOR_CUT_D_A_TERM                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_Cut_D_A_Term(Vector vec,VecWord n)
{
  BEGIN_ENUM_VECTORA(vec)     
    if (vec_val != n)
      Set_ValA_Null(vec[enum_i],enum_j);
  END_ENUM_VECTORA
}

 
/*-------------------------------------------------------------------------*/
/* VECTOR_CUT_NP_A_TERM                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_Cut_Np_A_Term(Vector vec,VecWord n)
{
  BEGIN_ENUM_VECTORA(vec)     
    if (IsNullA(MulA(vec_val,n)))
      Set_ValA_Null(vec[enum_i],enum_j);
  END_ENUM_VECTORA
}


/*-------------------------------------------------------------------------*/
/* VECTOR_CUT_NNP_A_TERM                                                   */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_Cut_Nnp_A_Term(Vector vec,VecWord n)
{
  BEGIN_ENUM_VECTORA(vec)     
    if (!IsNullA(MulA(vec_val,n)))
      Set_ValA_Null(vec[enum_i],enum_j);
  END_ENUM_VECTORA
}


/*-------------------------------------------------------------------------*/
/* VECTOR_KEEP_L_A_TERM                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_Keep_L_A_Term(Vector vec,VecWord n)
{
  BEGIN_ENUM_VECTORA(vec)     
    if (!LessA(vec_val,n))
      Set_ValA_Null(vec[enum_i],enum_j);
  END_ENUM_VECTORA
}


/*-------------------------------------------------------------------------*/
/* VECTOR_KEEP_LE_A_TERM                                                   */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_Keep_Le_A_Term(Vector vec,VecWord n)
{
  BEGIN_ENUM_VECTORA(vec)     
    if (!LessOrEqualA(vec_val,n))
      Set_ValA_Null(vec[enum_i],enum_j);
  END_ENUM_VECTORA
}


/*-------------------------------------------------------------------------*/
/* VECTOR_KEEP_G_A_TERM                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_Keep_G_A_Term(Vector vec,VecWord n)
{
  BEGIN_ENUM_VECTORA(vec)     
    if (!GreaterA(vec_val,n))
      Set_ValA_Null(vec[enum_i],enum_j);
  END_ENUM_VECTORA
}


/*-------------------------------------------------------------------------*/
/* VECTOR_KEEP_GE_A_TERM                                                   */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_Keep_Ge_A_Term(Vector vec,VecWord n)
{
  BEGIN_ENUM_VECTORA(vec)     
    if (!GreaterOrEqualA(vec_val,n))
      Set_ValA_Null(vec[enum_i],enum_j);
  END_ENUM_VECTORA
}

 
/*-------------------------------------------------------------------------*/
/* VECTOR_KEEP_D_A_TERM                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_Keep_D_A_Term(Vector vec,VecWord n)
{
  BEGIN_ENUM_VECTORA(vec)     
    if (vec_val == n)
      Set_ValA_Null(vec[enum_i],enum_j);
  END_ENUM_VECTORA
}

 
/*-------------------------------------------------------------------------*/
/* VECTOR_KEEP_NP_A_TERM                                                   */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_Keep_Np_A_Term(Vector vec,VecWord n)
{
  BEGIN_ENUM_VECTORA(vec)     
    if (!IsNullA(MulA(vec_val,n)))
      Set_ValA_Null(vec[enum_i],enum_j);
  END_ENUM_VECTORA
}


/*-------------------------------------------------------------------------*/
/* VECTOR_KEEP_NNP_A_TERM                                                   */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_Keep_Nnp_A_Term(Vector vec,VecWord n)
{
  BEGIN_ENUM_VECTORA(vec)     
    if (IsNullA(MulA(vec_val,n)))
      Set_ValA_Null(vec[enum_i],enum_j);
  END_ENUM_VECTORA
}

  
/*-------------------------------------------------------------------------*/
/* VECTOR_SIGMA
/*                                                                         */
/*-------------------------------------------------------------------------*/
VecWord Vector_Sigma(Vector vec)
{
  VecWord sum = NullA;
 
  BEGIN_ENUM_VECTORA(vec)     
    sum = AddA(sum,vec_val) ;
  END_ENUM_VECTORA

  return sum ;
}


/*-------------------------------------------------------------------------*/
/* VECTOR_GEA
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_GeA(Vector vec)
{
  VecWord sum = NullA;
 
  BEGIN_ENUM_VECTORA(vec)     
    sum = AddA(sum,vec_val) ;
    Set_ValA(vec[enum_i],enum_j,sum) ;
  END_ENUM_VECTORA
}


/*-------------------------------------------------------------------------*/
/* VECTOR_GA                                                               */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_GA(Vector vec)
{
  VecWord sum = NullA;

  BEGIN_ENUM_VECTORA(vec)     
    Set_ValA(vec[enum_i],enum_j,sum) ;
    sum = AddA(sum,vec_val) ;
  END_ENUM_VECTORA
}


/*-------------------------------------------------------------------------*/
/* VECTOR_LEA                                                              */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_LeA(Vector vec)
{
  VecWord sum = NullA;

  BEGIN_REV_ENUM_VECTORA(vec)   
    sum = AddA(sum,vec_val) ;  
    Set_ValA(vec[enum_i],enum_j,sum) ;
  END_REV_ENUM_VECTORA
}


/*-------------------------------------------------------------------------*/
/* VECTOR_LA                                                               */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_LA(Vector vec)
{
  VecWord sum = NullA;

  BEGIN_REV_ENUM_VECTORA(vec)     
    Set_ValA(vec[enum_i],enum_j,sum) ;
    sum = AddA(sum,vec_val) ;
  END_REV_ENUM_VECTORA
}


/*-------------------------------------------------------------------------*/
/* VECTOR_DA                                                               */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_DA(Vector vec)
{
  Vector temp ;
 
  Temporary_Vector_Allocate(temp) ;
  Vector_Copy(temp,vec) ;

  Vector_GA(temp) ;
  Vector_LA(vec) ;
  Vector_AddA_Vector(vec,temp) ;

  Temporary_Vector_Free(temp) ;
}


/*-------------------------------------------------------------------------*/
/* ADD_VECTOR_VECTOR                                                       */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Add_Vector_Vector(Vector vec, Vector vec1)
{
  Vector temp ;
  int    enum_i,enum_j;   
  int    k ;
  int    n = 0 ;

  Temporary_Vector_Allocate(temp) ;
  Set_Vector_Empty(temp) ;

  for(enum_i=0;enum_i<vec_size;enum_i++)    
    for(enum_j=0; enum_j<A_WD_SZ;enum_j++)
      {
	for(k=0 ; k <= n ; k++)
	  Add_ValA(temp[enum_i],enum_j,
		   MulA(ValA_Vector(vec,k),ValA_Vector(vec1,n-k))) ;
	n++ ;
      }

  Vector_Copy(vec,temp) ;
  Temporary_Vector_Free(temp) ;
}


/*-------------------------------------------------------------------------*/
/* SUB_VECTOR_VECTOR                                                       */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Sub_Vector_Vector(Vector vec, Vector vec1)
{
  Vector temp ;
  int    enum_i,enum_j;   
  int    k ;
  int    n = 0 ;

  Temporary_Vector_Allocate(temp) ;
  Set_Vector_Empty(temp) ;

  for(enum_i=0;enum_i<vec_size;enum_i++)    
    for(enum_j=0; enum_j<A_WD_SZ;enum_j++)
      {
	for(k=n ; k <= vec_infinity ; k++)
	  Add_ValA(temp[enum_i],enum_j,
		   MulA(ValA_Vector(vec,k),ValA_Vector(vec1,k-n))) ;
	n++ ;
      }
  Vector_Copy(vec,temp) ;
  Temporary_Vector_Free(temp) ;
}


/*-------------------------------------------------------------------------*/
/* MUL_VECTOR_VECTOR                                                       */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Mul_Vector_Vector(Vector vec, Vector vec1)
{
  Vector temp ;   
  int    k,l ;

  Temporary_Vector_Allocate(temp) ;
  Set_Vector_Empty(temp) ;

  Add_ValA_Vector(temp,0,MulA(ValA_Vector(vec,0),Vector_Sigma(vec1))) ;
  Add_ValA_Vector(temp,0,MulA(Vector_Sigma(vec),ValA_Vector(vec1,0))) ;
	
  for(l=1;l<=vec_infinity;l++)    
    for(k=1 ; k <= M_Div(vec_infinity,l) ; k++)
      Add_ValA_Vector(temp,M_Mul(k,l),
		      MulA(ValA_Vector(vec,k),ValA_Vector(vec1,l))) ;

  Vector_Copy(vec,temp) ;
  Temporary_Vector_Free(temp) ;
}


/*-------------------------------------------------------------------------*/
/* DIV_VECTOR_VECTOR                                                       */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Div_Vector_Vector(Vector vec, Vector vec1)
{
  Vector temp ;
  int    k,l ;

  Temporary_Vector_Allocate(temp) ;
  Set_Vector_Empty(temp) ;

  Add_ValA_Vector(temp,0,MulA(Vector_Sigma(vec1),ValA_Vector(vec,0))) ;
  for(l=0 ; l<= vec_infinity ; l++)
      Add_ValA_Vector(temp,l,MulA(ValA_Vector(vec1,0),ValA_Vector(vec,0))) ;

  for(k=1 ; k <= vec_infinity ; k++)
    for(l=1 ; l <= M_Div(vec_infinity,k) ; l++)
	Add_ValA_Vector(temp,k,
			MulA(ValA_Vector(vec,M_Mul(k,l)),
			     ValA_Vector(vec1,l))) ;
	
  Vector_Copy(vec,temp) ;
  Temporary_Vector_Free(temp) ;
}


/*-------------------------------------------------------------------------*/
/* ADD_VECTOR_TERM                                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Add_Vector_Term(Vector vec, int n)
{
  int bdec = (n%A_WD_SZ)*A_SIZE ;
  int wdec = (n/A_WD_SZ);
  int enum_i ;
  VecWord save = 0;
  VecWord temp = 0;

  if (n==0)
    return;

  if (n<0) 
    Sub_Vector_Term(vec,-n) ;
  else
    {
      for (enum_i=0;enum_i<vec_size;enum_i++)
	{
	  temp = vec[enum_i] ;
	  vec[enum_i] = (vec[enum_i]<<bdec)|save ;
	  save = (WORD_SIZE-bdec < 32) ? temp>>(WORD_SIZE-bdec) : 0 ;
	}
      for (enum_i=vec_size-1; enum_i >=wdec ; enum_i--)
	{
	  vec[enum_i] = vec[enum_i-wdec] ;
	}
      for (enum_i=0 ; enum_i<wdec ; enum_i++)
	{
	  vec[enum_i] = 0;
	}
    }
}


/*-------------------------------------------------------------------------*/
/* SUB_VECTOR_TERM                                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Sub_Vector_Term(Vector vec, int n)
{
  int bdec = (n%A_WD_SZ)*A_SIZE ;
  int wdec = (n/A_WD_SZ);
  int enum_i ;
  VecWord save = 0 ;
  VecWord temp = 0;

  if (n==0)
    return;

  if (n<0) 
    Add_Vector_Term(vec,-n) ;
  else
    {
      for (enum_i=vec_size-1;enum_i>=0;enum_i--)
	{
	  temp = vec[enum_i] ;
	  vec[enum_i] = (vec[enum_i]>>bdec)|save ;
	  save = (WORD_SIZE-bdec < 32) ? temp<<(WORD_SIZE-bdec) : 0 ;
	}
      for (enum_i=0; enum_i<vec_size-wdec ; enum_i++)
	{
	  vec[enum_i] = vec[enum_i+wdec] ;
	}
      for (enum_i=vec_size-1 ; enum_i>=vec_size-wdec ; enum_i--)
	{
	  vec[enum_i] = 0;
	}
    }
}


/*-------------------------------------------------------------------------*/
/* MUL_VECTOR_TERM                                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Mul_Vector_Term(Vector vec, int n)
{
  Vector temp ;
  int    i ;

  if (n==1)
    return;
  
  if (n==0)
    {
      Set_Vector_Term(vec,0,Vector_Sigma(vec));
      return;
    }

  Temporary_Vector_Allocate(temp) ;
  Set_Vector_Empty(temp) ;

  for(i=0; i<= M_Div(vec_infinity,n) ; i++) 
      Set_ValA_Vector(temp,M_Mul(n,i),ValA_Vector(vec,i)) ;

  Vector_Copy(vec,temp) ;
  Temporary_Vector_Free(temp) ;
}


/*-------------------------------------------------------------------------*/
/* DIV_VECTOR_TERM                                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Div_Vector_Term(Vector vec, int n)
{
  Vector temp ;
  int    i ;
  VecWord v0;

  if (n==1)
    return;
  
  if (n==0)
    {
      v0 = ValA_Vector(vec,0);
      if (IsNullA(v0))
	Set_Vector_Empty(vec);
      else
	{
	  Set_Vector_Full(vec);
	  Vector_MulA_Term(vec,v0);
        }
      return;
    }

  Temporary_Vector_Allocate(temp) ;
  Set_Vector_Empty(temp) ;

  for(i=0; i<= M_Div(vec_infinity,n) ; i++) 
    Set_ValA_Vector(temp,i,ValA_Vector(vec,M_Mul(i,n))) ;
  
  Vector_Copy(vec,temp) ;
  Temporary_Vector_Free(temp) ;
}


/*-------------------------------------------------------------------------*/
/* VECTOR_VALUE_INDEX                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Vector_Value_Index(Vector vec, VecWord *bv, int *bi)
{
  *bi = 0 ;
  *bv = ValA_Vector(vec,0) ;

  BEGIN_ENUM_VECTORAA(vec) 
   if (vec_val != *bv)
    if (GreaterA(vec_val,*bv))
      {
	*bv = vec_val ;
	*bi = vec_elem ;
      }
  END_ENUM_VECTORAA   
}


/*-------------------------------------------------------------------------*/
/* SETS_VECTOR_VALUE_INDEX                                                 */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Sets_Vector_Value_Index(Vector vec, int *bn, int *bi)
{
  int n ;

  *bi = 0 ;
  *bn = Bits_Nb_In_Value(ValA_Vector(vec,0)) ;

  BEGIN_ENUM_VECTORAA(vec) 
    n = Bits_Nb_In_Value(vec_val) ;
    if (n > *bn)
      {
	*bn = n ;
	*bi = vec_elem ;
      }
  END_ENUM_VECTORAA 
}









