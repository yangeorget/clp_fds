/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - LOCO Project  */
/* C Run-time                                          Daniel Diaz - 1992  */
/*                                                                         */
/* Modified by Yan Georget - June 1998                                     */
/* sfd_range.c                                                             */
/*-------------------------------------------------------------------------*/

#include <stdio.h>
#include "bool.h"
#include "sfd_range.h"
#include "wam_engine.h"


/*-------------------------------------------------------------------------*/
/* INIT_RANGE_FULL                                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Init_Range_Full(Range *r)
{                            
   r->vec = NULL;
   Set_Range_Full(r);
}


/*-------------------------------------------------------------------------*/
/* INIT_RANGE_EMPTY                                                        */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Init_Range_Empty(Range *r)
{                            
   r->vec = NULL;
   Set_Range_Empty(r);
}


/*-------------------------------------------------------------------------*/
/* INIT_RANGE_TERM                                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Init_Range_Term(Range *r, int n, VecWord v)
{                            
   r->vec = NULL;
   Set_Range_Term(r,n,v);
}


/*-------------------------------------------------------------------------*/
/* INIT_RANGE_COMP_TERM                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Init_Range_Comp_Term(Range *r, int n)
{         
  r->vec = NULL;
  Set_Range_Comp_Term(r,n);
}


/*-------------------------------------------------------------------------*/
/* INIT_RANGE_INTERVAL                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Init_Range_Interval(Range *r, int min, int max, VecWord value)
{                        
  r->vec = NULL;
  Set_Range_Interval(r,min,max,value);
}


/*-------------------------------------------------------------------------*/
/* INIT_RANGE_RANGE                                                        */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Init_Range_Range(Range *r, Range *r1)
{                        
  r->vec = NULL;
  Range_Copy(r,r1);
}


/*-------------------------------------------------------------------------*/
/* SET_RANGE_FULL                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Set_Range_Full(Range *r)
{                            
   r->min   = 0;
   r->max   = INTERVAL_INFINITY;
   r->sigma = UnityA;
   r->mode  = R_INTERVAL;
}


/*-------------------------------------------------------------------------*/
/* SET_RANGE_EMPTY                                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Set_Range_Empty(Range *r)
{                            
   r->mode  = R_EMPTY;
}


/*-------------------------------------------------------------------------*/
/* SET_RANGE_TERM                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Set_Range_Term(Range *r, int n, VecWord v)
{ 
  if (n<0 || n>INTERVAL_INFINITY)
    {
      Set_Range_Empty(r);
      return;
    }

   r->min   = n;
   r->max   = n;
   r->sigma = v ;
   r->mode  = R_INTEGER;
}


/*-------------------------------------------------------------------------*/
/* SET_RANGE_COMP_TERM                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Set_Range_Comp_Term(Range *r, int n)
{            
  if (n == 0) 
    {
      Set_Range_Interval(r,1,INTERVAL_INFINITY,UnityA);
      return;
    }

  if (n == INTERVAL_INFINITY)
    {
      Set_Range_Interval(r,0,INTERVAL_INFINITY-1,UnityA);
      return;
    }

  if (n == vec_infinity)
    {
      Set_Range_Interval(r,0,vec_infinity-1,UnityA);
      return;
    }

  if (n>0 && n<vec_infinity)
    {
      r->min   = 0;
      r->max   = vec_infinity;
      r->sigma = UnityA ;
      r->mode  = R_SPARSE;
      Vector_Allocate_If_Necessary(r->vec);
      Set_Vector_Comp_Term(r->vec,n);
    }
  else
    Set_Range_Full(r);
}


/*-------------------------------------------------------------------------*/
/* SET_RANGE_INTERVAL                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Set_Range_Interval(Range *r, int min, int max, VecWord value)
{           
  min = math_max(min,0);
  max = math_min(max,INTERVAL_INFINITY);

  if (max < min)
    {
      Set_Range_Empty(r);
      return;
    }

  if (min == max)
    {
      Set_Range_Term(r,min,value);
      return;
    }

  r->min   = min;
  r->max   = max;
  r->sigma = value ;
  r->mode  = R_INTERVAL;
}


/*-------------------------------------------------------------------------*/
/* SET_RANGE_COMP_INTERVAL                                                 */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Set_Range_Comp_Interval(Range *r, int min, int max)
{     
  min = math_max(min,0);
  max = math_min(max,vec_infinity);
  
  if (min == max)
    {
      Set_Range_Comp_Term(r,min);
      return;
    }
  
  if (max < min)
    {
      Set_Range_Full(r);
      return;
    }

  if (min == 0 && max == vec_infinity)
    {
      Set_Range_Empty(r);
      return;
    }

  if (min == 0)
    {
      Set_Range_Interval(r,max+1,vec_infinity,UnityA);
      return;
    }

  if (max == vec_infinity)
    {
      Set_Range_Interval(r,0,min-1,UnityA);
      return;
    }

  r->min   = 0;
  r->max   = vec_infinity;
  r->sigma = UnityA ;
  Vector_Allocate_If_Necessary(r->vec);
  Set_Vector_Comp_Interval(r->vec,min,max);
  r->mode  = R_SPARSE;
}


/*-------------------------------------------------------------------------*/
/* RANGE_NB_ELEM                                                           */
/*                                                                         */
/*-------------------------------------------------------------------------*/
int Range_Nb_Elem(Range *range)
{
  switch (range->mode) 
    {
    case R_EMPTY: 
      return 0;
    case R_INTEGER:
      return 1;
    case R_INTERVAL:
      return (range->max - range->min +1);
    case R_SPARSE:
      return Vector_Nb_Elem(range->vec) ;
    }
}



/*-------------------------------------------------------------------------*/
/* VALUE_OF_INT_IN_RANGE                                                   */
/*                                                                         */
/*-------------------------------------------------------------------------*/
VecWord Value_Of_Int_In_Range(Range *range,int n)

{
  switch (range->mode) 
    {
    case R_EMPTY: 
      return NullA;
    case R_INTEGER:
      return ((range->min == n)?(range->sigma):(NullA));
    case R_INTERVAL:
      return ((range->min <= n && n <= range->max)?(range->sigma):(NullA));
    case R_SPARSE:
      return Safe_ValA_Vector(range->vec,n) ;
    }
}


/*-------------------------------------------------------------------------*/
/* RANGE_COPY                                                              */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_Copy(Range *range,Range *range1)

{
 range->sigma  = range1->sigma;
 range->min    = range1->min;
 range->max    = range1->max;
 range->mode   = range1->mode;

 if (range->mode == R_SPARSE)
   {
     Vector_Allocate_If_Necessary(range->vec);
     Vector_Copy(range->vec,range1->vec);
   }
}


/*-------------------------------------------------------------------------*/
/* RANGE_CONTAIN                                                           */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Range_Contain(Range *range,Range *range1)

{
 switch(range->mode)
   {
   case R_EMPTY:
     return (range1->mode = R_EMPTY);
     
   case R_INTEGER:
     switch(range1->mode)
       {
       case R_EMPTY:
	 return TRUE;
	 
       case R_INTEGER:
	   return (range->min == range1->min);
	 
       case R_INTERVAL:
       case R_SPARSE:
	 return FALSE;
       }

   case R_INTERVAL:
     switch(range1->mode)
       {
       case R_EMPTY:
	 return TRUE;
	 
       case R_INTEGER:
	 return ((range->min <= range1->min) && (range1->min <= range->max));
	 
       case R_INTERVAL: 
       case R_SPARSE:
	 return ((range->min <= range1->min) && (range1->max <= range->max));
       }

   case R_SPARSE:
     switch(range1->mode)
       {
       case R_EMPTY:
	 return TRUE;
	 
       case R_INTEGER:
	 return (!IsNullA(ValA_Vector(range->vec,range1->min)));
	 
       case R_INTERVAL:
	 return Vector_Contain_Interval(range->vec,range1->min,range1->max);
	 
       case R_SPARSE:
	 return Vector_Contain_Vector(range->vec,range1->vec);
       }
   }
}


/*-------------------------------------------------------------------------*/
/* RANGE_INTERSECTION                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Range_Intersection(Range *range,Range *range1)

{
  int i;

  switch (range->mode)
    {
    case R_EMPTY:
      return FALSE;
      
    case R_INTEGER:
      switch(range1->mode)
	{
	case R_EMPTY:
	  return FALSE;
	case R_INTEGER:
	  return ((range->min == range1->min) && 
		  (!IsNullA(MulA(range->sigma,range1->sigma))));
	case R_INTERVAL:
	  return ((range->min >= range1->min) && 
		  (range->min <= range1->max) &&
		  (!IsNullA(MulA(range->sigma,range1->sigma))));
	case R_SPARSE:
	  return (!IsNullA(MulA(Safe_ValA_Vector(range1->vec,range->min),range->sigma)));
	}
    case R_INTERVAL:
      switch(range1->mode)
	{
	case R_EMPTY:
	  return FALSE;
	case R_INTEGER:
	  return ((range1->min >= range->min) && 
		  (range1->min <= range->max) &&
		  (!IsNullA(MulA(range->sigma,range1->sigma))));
       case R_INTERVAL:
	 return ((range->max >= range1->min) && 
		 (range->min <= range1->max) &&
		 (!IsNullA(MulA(range->sigma,range1->sigma))));
	case R_SPARSE:
	  for (i = range->min; i <= range->max; i++)
	    if (!IsNullA(MulA(Safe_ValA_Vector(range1->vec,i),range->sigma)))
	      return TRUE;
	  return FALSE;
       }
   case R_SPARSE:
     switch(range1->mode)
       {
       case R_EMPTY:
	 return FALSE;
       case R_INTEGER:
	  return (!IsNullA(MulA(Safe_ValA_Vector(range->vec,range1->min),range1->sigma)));
       case R_INTERVAL:
	 for (i = range1->min; i <= range1->max; i++)
	    if (!IsNullA(MulA(Safe_ValA_Vector(range->vec,i),range1->sigma)))
	      return TRUE;
	  return FALSE;
       case R_SPARSE:
	 return Vector_Intersection(range->vec,range1->vec);
       }
   }
}


/*-------------------------------------------------------------------------*/
/* RANGE_FROM_VECTOR                                                       */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_From_Vector(Range *range)

{

 range->min = Vector_Min(range->vec) ;
 if (range->min == -1)
   {
     range->mode = R_EMPTY;
     return;
   }

 range->max = Vector_Max(range->vec) ;
 if (range->max == -1)
   {
     range->mode = R_EMPTY;
     return ;
   }

 if (range->min == range->max)
   {
     range->sigma = ValA_Vector(range->vec,range->min) ;
     range->mode = R_INTEGER;
   }
 else
   {
     range->sigma = Vector_Sigma(range->vec);
     range->mode = R_SPARSE;
   }
}


/*-------------------------------------------------------------------------*/
/* RANGE_BECOMES_SPARSE                                                    */
/*-------------------------------------------------------------------------*/
void Range_Becomes_Sparse(Range *range)

{
 switch (range->mode)
   {
   case R_SPARSE:
     break;

   case R_INTERVAL:
     Vector_Allocate_If_Necessary(range->vec);
     if (range->max <= vec_infinity)
       {
	 Set_Vector_Interval_Value(range->vec,range->min,range->max,range->sigma); 
       }
     else
       {
	 Set_Vector_Interval_Value(range->vec,range->min,vec_infinity,range->sigma);
       }
     break;

     case R_INTEGER:
       Vector_Allocate_If_Necessary(range->vec);
       Set_Vector_Empty(range->vec) ;
       if (range->min <= vec_infinity)
	 {
	   Set_ValA_Vector(range->vec,range->min,range->sigma);
	 }
       break;
       
   case R_EMPTY:
     Vector_Allocate_If_Necessary(range->vec);
     Set_Vector_Empty(range->vec);
     break;
   }
 range->mode = R_SPARSE;
}


/*-------------------------------------------------------------------------*/
/* RANGE_ADDA_RANGE                                                        */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_AddA_Range(Range *r,Range *r1)

{
  int     i;
  int     temp_min;
  int     temp_max;
  VecWord temp_sigma;

  switch (r1->mode)
    {
    case R_EMPTY:
      return;

    case R_INTEGER:
     switch (r->mode)
	{
	case R_EMPTY:
	  r->min   = r1->min;
	  r->max   = r1->min;
	  r->sigma = r1->sigma;
	  r->mode  = R_INTEGER;
	  return ;

	case R_INTEGER:
	  if (r->min == r1->min)
	    {
	      r->sigma = AddA(r->sigma,r1->sigma);
	    }
	  else
	    {
	      if (r->min > vec_infinity || r1->min > vec_infinity)
		{
		  r->mode = R_EMPTY;
		}
	      else
		{
		  Vector_Allocate_If_Necessary(r->vec);
		  Set_Vector_Empty(r->vec) ;
		  Set_ValA_Vector(r->vec,r->min,r->sigma);
		  Set_ValA_Vector(r->vec,r1->min,r1->sigma);
		  r->min   = math_min(r->min,r1->min);
		  r->max   = math_max(r->min,r1->min);
		  r->sigma = AddA(r->sigma,r1->sigma);
		  r->mode  = R_SPARSE;
		}
	    }
	  return;

	case R_INTERVAL:
	  Range_Becomes_Sparse(r);
	  Add_ValA_Vector(r->vec,r1->min,r1->sigma);
	  r->min   = math_min(r->min,r1->min);
	  r->max   = math_max(r->max,r1->min);
	  r->sigma = AddA(r->sigma,r1->sigma);
	  return;
	      
	case R_SPARSE:
	  if (r1->min <= vec_infinity)
	    {
	      Add_ValA_Vector(r->vec,r1->min,r1->sigma);
	      r->min   = math_min(r->min,r1->min);
	      r->max   = math_max(r->max,r1->min);
	      r->sigma = AddA(r->sigma,r1->sigma);
	    }
	  else
	    {
	      r->mode = R_EMPTY;
	    }
	  return;	      
	}

    case R_INTERVAL:
      switch (r->mode)
	{
	case R_EMPTY:
	  r->min   = r1->min;
	  r->max   = r1->max; 
	  r->sigma = r1->sigma;
	  r->mode  = R_INTERVAL;
	  return ;

	case R_INTEGER:
	  temp_min   = r1->min;
	  temp_sigma = r1->sigma;
	  Range_Copy(r,r1);
	  Range_Becomes_Sparse(r);
	  Add_ValA_Vector(r->vec,temp_min,temp_sigma);
	  r->min   = math_min(r->min,temp_min);
	  r->max   = math_max(r->max,temp_min);
	  r->sigma = AddA(r->sigma,temp_sigma);
	  return;

	case R_INTERVAL:
	  Range_Becomes_Sparse(r);
	  for (i = r1->min; i <= r1->max; i++)
	    Add_ValA_Vector(r->vec,i,r1->sigma);
	  r->min   = math_min(r->min,r1->min);
	  r->max   = math_max(r->max,r1->max);
	  r->sigma = AddA(r->sigma,r1->sigma);
	  return;
	  
	case R_SPARSE:
	  if (r1->max <= vec_infinity)
	    {
	      for (i = r1->min; i <= r1->max; i++)
		Add_ValA_Vector(r->vec,i,r1->sigma);
	      r->min   = math_min(r->min,r1->min);
	      r->max   = math_max(r->max,r1->max);
	      r->sigma = AddA(r->sigma,r1->sigma);
	    }
	  else
	    {
	      r->mode = R_EMPTY;
	    }
	  return;
	}

    case R_SPARSE:
      switch (r->mode)
	{
	case R_EMPTY:
	  Range_Copy(r,r1) ;
	  return ;

	case R_INTEGER:
	  if (r->min <= vec_infinity)
	    {
	      temp_min   = r->min;
	      temp_sigma = r->sigma;
	      Range_Copy(r,r1);
	      Add_ValA_Vector(r->vec,temp_min,temp_sigma);
	      r->min   = math_min(r->min,temp_min);
	      r->max   = math_max(r->max,temp_min);
	      r->sigma = AddA(r->sigma,temp_sigma);
	    }
	  else
	    {
	      r->mode = R_EMPTY;
	    }
	  return;

	case R_INTERVAL:
	  if (r->max <= vec_infinity)
	    {
	      temp_min   = r->min;
	      temp_max   = r->max;
	      temp_sigma = r->sigma;
	      Range_Copy(r,r1);
	      for (i = temp_min; i <= temp_max; i++)
		Add_ValA_Vector(r->vec,i,r1->sigma);
	      r->min   = math_min(r->min,temp_min);
	      r->max   = math_max(r->max,temp_max);
	      r->sigma = AddA(r->sigma,temp_sigma);
	    }
	  else
	    {
	      r->mode = R_EMPTY;
	    }
	  return;

	case R_SPARSE:
	  Vector_AddA_Vector(r->vec, r1->vec);
	  r->min   = math_min(r->min,r1->min);
	  r->max   = math_max(r->max,r1->max);
	  r->sigma = AddA(r->sigma, r1->sigma) ;
	  return;
	}
    }
}


/*-------------------------------------------------------------------------*/
/* RANGE_MULA_RANGE                                                        */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_MulA_Range(Range *r,Range *r1)

{
  int     i;
  VecWord v;

  int     temp_min;
  int     temp_max;
  VecWord temp_sigma;

  switch (r1->mode)
    {
    case R_EMPTY:
      r->mode = R_EMPTY;
      return;

    case R_INTEGER:
     switch (r->mode)
	{
	case R_EMPTY:
	  return ;

	case R_INTEGER:
	  if (r->min == r1->min)
	    {
	      r->sigma = MulA(r->sigma,r1->sigma);
	      if (IsNullA(r->sigma))
		r->mode = R_EMPTY;
	    }
	  else
	    {
	      r->mode = R_EMPTY;
	    }
	  return;

	case R_INTERVAL:
	  if (r->min <= r1->min && r1->min <= r->max)
	    {
	      r->sigma = MulA(r->sigma,r1->sigma);
	      if (IsNullA(r->sigma))
		{
		  r->mode = R_EMPTY;
		}
	      else
		{
		  r->min   = r1->min;
		  r->max   = r1->min;
		  r->mode  = R_INTEGER;
		}
	    }
	  else
	    {
	      r->mode = R_EMPTY;
	    }
	  return;

	case R_SPARSE:
	  v = MulA(ValA_Vector(r->vec,r1->min),r1->sigma);
	  if (IsNullA(v))
	    {
	      r->mode = R_EMPTY;
	    }
	  else
	    {
	      r->sigma = v;
	      r->min   = r1->min;
	      r->max   = r1->min;
	      r->mode  = R_INTEGER;
	    }
	  return;
	}

    case R_INTERVAL:
      switch (r->mode)
	{
	case R_EMPTY:
	  return ;

	case R_INTEGER:
	  if (r1->min <= r->min && r->min <= r1->max)
	    {
	      r->sigma = MulA(r->sigma,r1->sigma);
	      if (IsNullA(r->sigma))
		r->mode = R_EMPTY;
	    }
	  else
	    {
	      r->mode = R_EMPTY;
	    }
	  return;
	  
	case R_INTERVAL:
	  r->min   = math_max(r->min,r1->min);
	  r->max   = math_min(r->max,r1->max);
	  r->sigma = MulA(r->sigma,r1->sigma);
	  if (IsNullA(r->sigma) || (r->min > r->max))
	    {
	      r->mode = R_EMPTY;
	    }
	  else
	    {
	      if (r->min == r->max)
		r->mode = R_INTEGER;
	    }
	  return;

	case R_SPARSE:
	  r1->max = math_min(r1->max,vec_infinity);
	  if (r1->min <= r1->max)
	    {
	      for (i = 0 ; i < r1->min ; i++)
		Set_ValA_Null_Vector(r->vec,i);
	      for (i = r1->max + 1 ; i <= vec_infinity ; i++)
		Set_ValA_Null_Vector(r->vec,i);
	      for (i = r1->min; i <= r1->max; i++)
		Mul_ValA_Vector(r->vec,i,r1->sigma);
	      Range_From_Vector(r);
	    }
	  else
	    {
	      r->mode = R_EMPTY;
	    }
	  return;
	}

    case R_SPARSE:
      switch (r->mode)
	{
	case R_EMPTY:
	  return ;

	case R_INTEGER:
	  if (r->min <= vec_infinity)
	    {
	      r->sigma = MulA(r->sigma,ValA_Vector(r1->vec,r->min));
	      if (IsNullA(r->sigma))
		r->mode = R_EMPTY;
	    }
	  else
	    {
	      r->mode = R_EMPTY;
	    }
	  return;

	case R_INTERVAL:
	  r->min = math_max(r->min, r1->min);
	  r->max = math_min(r->max, r1->max);
	  if (r->min == r->max)
	    {
	      r->sigma = MulA(r->sigma,ValA_Vector(r1->vec,r->min));
	      if (IsNullA(r->sigma))
		r->mode = R_EMPTY;
	      else 
		r->mode = R_INTEGER;
	    }
	  else
	    {
	      Range_Becomes_Sparse(r);
	      Vector_MulA_Vector(r->vec,r1->vec);
	      Range_From_Vector(r);
	    }
	  return;

	case R_SPARSE:
	  Vector_MulA_Vector(r->vec, r1->vec);
	  Range_From_Vector(r);
	  return;
	}
    }
}



/*-------------------------------------------------------------------------*/
/* RANGE_ADDA_TERM                                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_AddA_Term(Range *range,VecWord n)

{   
  if (IsNullA(n))
    return;
  
  if (IsUnityA(n))
    {
      range->sigma = UnityA;
      range->min = 0;
      range->max = INTERVAL_INFINITY;
      range->mode = R_INTERVAL;
      return;
    }

  switch(range->mode)
    {
    case R_EMPTY:
      range->min = 0;
      range->max = INTERVAL_INFINITY;
      range->sigma = n;
      range->mode = R_INTERVAL;
      return;
	
    case R_INTEGER:
      if (LessOrEqualA(range->sigma,n))
	{
	  range->min = 0;
	  range->max = INTERVAL_INFINITY;
	  range->sigma = n;
	  range->mode = R_INTERVAL;
	}
      else
	{
	  Range_Becomes_Sparse(range);
	  Vector_AddA_Term(range->vec,n);
	  range->min   = 0;
	  range->max   = vec_infinity;
	  range->sigma = AddA(range->sigma,n);
	}
      return;
      
    case R_INTERVAL:
      if (range->min == 0 && range->max == INTERVAL_INFINITY)
	{
	  range->sigma = AddA(range->sigma,n);
	  return;
	}
      if (LessOrEqualA(range->sigma,n))
	{
	  range->min = 0;
	  range->max = INTERVAL_INFINITY;
	  range->sigma = n;
	  return;
	}
      Range_Becomes_Sparse(range);
      Vector_AddA_Term(range->vec,n);
      range->min   = 0;
      range->max   = vec_infinity;
      range->sigma = AddA(range->sigma,n);
      return;
	  
    case R_SPARSE:
      Vector_AddA_Term(range->vec,n);
      range->min   = 0;
      range->max   = vec_infinity;
      range->sigma = AddA(range->sigma,n) ;
      return;
    }
}


/*-------------------------------------------------------------------------*/
/* RANGE_MULA_TERM                                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_MulA_Term(Range *range,VecWord n)

{   
  if (IsUnityA(n))
    return;

  if (IsNullA(n))
    {
      range->mode = R_EMPTY;
      return;
    }

  switch(range->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER: case R_INTERVAL:
      range->sigma == MulA(range->sigma,n);
      if (IsNullA(range->sigma))
	range->mode = R_EMPTY;
      return;
      
    case R_SPARSE:
      Vector_MulA_Term(range->vec,n);
      Range_From_Vector(range);
      return;
    }
}


/*-------------------------------------------------------------------------*/
/* RANGE_CUT_L_A_TERM                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_Cut_L_A_Term(Range *range,VecWord n)

{                
  if (IsNullA(n))
    return;

  if (IsUnityA(n))
    {
      range->mode = R_EMPTY;
      return;
    }

  switch(range->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER: case R_INTERVAL:
      if (LessA(range->sigma,n))
	range->mode = R_EMPTY;
      return;
      
    case R_SPARSE:
      Vector_Cut_L_A_Term(range->vec,n);
      Range_From_Vector(range);
      return;
    }
}

/*-------------------------------------------------------------------------*/
/* RANGE_CUT_LE_A_TERM                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_Cut_Le_A_Term(Range *range,VecWord n)

{                
  switch(range->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER: case R_INTERVAL:
      if (LessOrEqualA(range->sigma,n))
	range->mode = R_EMPTY;
      return;
      
    case R_SPARSE:
      Vector_Cut_Le_A_Term(range->vec,n);
      Range_From_Vector(range);
      return;
    }
}

/*-------------------------------------------------------------------------*/
/* RANGE_CUT_G_A_TERM                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_Cut_G_A_Term(Range *range,VecWord n)

{                
  if (IsUnityA(n))
    return;

  if (IsNullA(n))
    {
      range->mode = R_EMPTY;
      return;
    }

  switch(range->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER: case R_INTERVAL:
      if (GreaterA(range->sigma,n))
	range->mode = R_EMPTY;
      return;
      
    case R_SPARSE:
      Vector_Cut_G_A_Term(range->vec,n);
      Range_From_Vector(range);
      return;
    }
}


/*-------------------------------------------------------------------------*/
/* RANGE_CUT_GE_A_TERM                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_Cut_Ge_A_Term(Range *range,VecWord n)

{                
  switch(range->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER: case R_INTERVAL:
      if (GreaterOrEqualA(range->sigma,n))
	range->mode = R_EMPTY;
      return;
      
    case R_SPARSE:
      Vector_Cut_Ge_A_Term(range->vec,n);
      Range_From_Vector(range);
      return;
    }
}


/*-------------------------------------------------------------------------*/
/* RANGE_CUT_D_A_TERM                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_Cut_D_A_Term(Range *range,VecWord n)

{                
  switch(range->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER: case R_INTERVAL:
      if (range->sigma != n)
	range->mode = R_EMPTY;
      return;
      
    case R_SPARSE:
      Vector_Cut_D_A_Term(range->vec,n);
      Range_From_Vector(range);
      return;
    }
} 


/*-------------------------------------------------------------------------*/
/* RANGE_CUT_NP_A_TERM                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_Cut_Np_A_Term(Range *range,VecWord n)

{                
  if (IsUnityA(n))
    return;

  if (IsNullA(n))
    {
      range->mode = R_EMPTY;
      return;
    }

  switch(range->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER: case R_INTERVAL:
      if (IsNullA(MulA(range->sigma,n)))
	range->mode = R_EMPTY;
      return;
      
    case R_SPARSE:
      Vector_Cut_Np_A_Term(range->vec,n);
      Range_From_Vector(range);
      return;
    }
}


/*-------------------------------------------------------------------------*/
/* RANGE_CUT_NNP_A_TERM                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_Cut_Nnp_A_Term(Range *range,VecWord n)

{                
  if (IsNullA(n))
    return;

  if (IsUnityA(n))
    {
      range->mode = R_EMPTY;
      return;
    }

  switch(range->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER: case R_INTERVAL:
      if (!IsNullA(MulA(range->sigma,n)))
	range->mode = R_EMPTY;
      return;
      
    case R_SPARSE:
      Vector_Cut_Nnp_A_Term(range->vec,n);
      Range_From_Vector(range);
      return;
    }
}


/*-------------------------------------------------------------------------*/
/* RANGE_KEEP_L_A_TERM                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_Keep_L_A_Term(Range *range,VecWord n)

{                
  if (IsUnityA(n))
    return;

  if (IsNullA(n))
    {
      range->mode = R_EMPTY;
      return;
    }

  switch(range->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER: case R_INTERVAL:
      if (!LessA(range->sigma,n))
	range->mode = R_EMPTY;
      return;
      
    case R_SPARSE:
      Vector_Keep_L_A_Term(range->vec,n);
      Range_From_Vector(range);
      return;
    }
}


/*-------------------------------------------------------------------------*/
/* RANGE_KEEP_LE_A_TERM                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_Keep_Le_A_Term(Range *range,VecWord n)

{                
  switch(range->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER: case R_INTERVAL:
      if (!LessOrEqualA(range->sigma,n))
	range->mode = R_EMPTY;
      return;
      
    case R_SPARSE:
      Vector_Keep_Le_A_Term(range->vec,n);
      Range_From_Vector(range);
      return;
    }
}


/*-------------------------------------------------------------------------*/
/* RANGE_KEEP_G_A_TERM                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_Keep_G_A_Term(Range *range,VecWord n)

{                
  if (IsNullA(n))
    return;

  if (IsUnityA(n))
    {
      range->mode = R_EMPTY;
      return;
    }

  switch(range->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER: case R_INTERVAL:
      if (!GreaterA(range->sigma,n))
	range->mode = R_EMPTY;
      return;
      
    case R_SPARSE:
      Vector_Keep_G_A_Term(range->vec,n);
      Range_From_Vector(range);
      return;
    }
}


/*-------------------------------------------------------------------------*/
/* RANGE_KEEP_GE_A_TERM                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_Keep_Ge_A_Term(Range *range,VecWord n)

{                
  switch(range->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER: case R_INTERVAL:
      if (!GreaterOrEqualA(range->sigma,n))
	range->mode = R_EMPTY;
      return;
      
    case R_SPARSE:
      Vector_Keep_Ge_A_Term(range->vec,n);
      Range_From_Vector(range);
      return;
    }
}


/*-------------------------------------------------------------------------*/
/* RANGE_KEEP_D_A_TERM                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_Keep_D_A_Term(Range *range,VecWord n)

{                
  switch(range->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER: case R_INTERVAL:
      if (range->sigma == n)
	range->mode = R_EMPTY;
      return;
      
    case R_SPARSE:
      Vector_Keep_D_A_Term(range->vec,n);
      Range_From_Vector(range);
      return;
    }
} 


/*-------------------------------------------------------------------------*/
/* RANGE_KEEP_NP_A_TERM                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_Keep_Np_A_Term(Range *range,VecWord n)

{                
  if (IsNullA(n))
    return;

  if (IsUnityA(n))
    {
      range->mode = R_EMPTY;
      return;
    }

  switch(range->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER: case R_INTERVAL:
      if (!IsNullA(MulA(range->sigma,n)))
	range->mode = R_EMPTY;
      return;
      
    case R_SPARSE:
      Vector_Keep_Np_A_Term(range->vec,n);
      Range_From_Vector(range);
      return;
    }
}


/*-------------------------------------------------------------------------*/
/* RANGE_KEEP_NNP_A_TERM                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_Keep_Nnp_A_Term(Range *range,VecWord n)

{                
  if (IsUnityA(n))
    return;

  if (IsNullA(n))
    {
      range->mode = R_EMPTY;
      return;
    }

  switch(range->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER: case R_INTERVAL:
      if (IsNullA(MulA(range->sigma,n)))
	range->mode = R_EMPTY;
      return;
      
    case R_SPARSE:
      Vector_Keep_Nnp_A_Term(range->vec,n);
      Range_From_Vector(range);
      return;
    }
}


/*-------------------------------------------------------------------------*/
/* RANGE_LEA                                                               */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_LeA(Range *range)

{ 
  switch(range->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER: 
      if (range->min !=0)
	{
	  range->max = range->min;
	  range->min = 0;
	  range->mode = R_INTERVAL;
	}
      return;

    case R_INTERVAL:
      range->min = 0;
      return;
      
    case R_SPARSE:
      Vector_LeA(range->vec);
      range->min = 0;
      return;
    }
}


/*-------------------------------------------------------------------------*/
/* RANGE_LA                                                                */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_LA(Range *range)

{   
  switch(range->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER: 
      if (range->min == 0)
	{
	  range->mode = R_EMPTY;
	  return;
	}
      if (range->min == 1)
	{
	  range->min = 0;
	  range->max = 0;
	  return;
	}
      range->max = range->min-1;
      range->min = 0;
      range->mode = R_INTERVAL;
      return ;

    case R_INTERVAL:
      if (range->max == 1)
	{
	  range->max = 0;
	  range->mode = R_INTEGER;
	}
      range->min = 0;
      (range->max)--;
      return;
      
    case R_SPARSE:
      Vector_LA(range->vec);
      (range->max)--;
      range->min = 0;
      return;
    }
}


/*-------------------------------------------------------------------------*/
/* RANGE_GEA                                                               */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_GeA(Range *range)

{ 
  switch(range->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER: 
      if (range->min !=vec_infinity)
	{
	  range->max = vec_infinity;
	  range->mode = R_INTERVAL;
	}
      return;

    case R_INTERVAL:
      range->max = vec_infinity;
      return;
      
    case R_SPARSE:
      Vector_GeA(range->vec);
      range->max = vec_infinity;
      return;
    }
}


/*-------------------------------------------------------------------------*/
/* RANGE_GA                                                                */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_GA(Range *range)

{   
  switch(range->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER: 
      if (range->min == vec_infinity)
	{
	  range->mode = R_EMPTY;
	  return;
	}
      if (range->min == vec_infinity-1)
	{
	  range->min = vec_infinity;
	  range->max = vec_infinity;	  
	  return;
	}
      (range->min)++;
      range->max = vec_infinity;
      range->mode = R_INTERVAL;
      return ;

    case R_INTERVAL:
      if (range->min == vec_infinity-1)
	{
	  range->min = vec_infinity;
	  range->max = vec_infinity;	  
	  range->mode = R_INTEGER;
	  return;
	}
      (range->min)++;
      range->max = vec_infinity;
      return;
      
    case R_SPARSE:
      Vector_GA(range->vec);
      (range->min)++;
      range->max = vec_infinity;
      return;
    }
}


/*-------------------------------------------------------------------------*/
/* RANGE_DA                                                                */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_DA(Range *range)

{  
  switch(range->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER: 
      if (range->min == 0)
	{
	  range->min = 1;
	  range->max = INTERVAL_INFINITY;
	  range->mode = R_INTERVAL;
	  return;
	}
      if (range->min == INTERVAL_INFINITY)
	{
	  range->min = 0;
	  range->max = INTERVAL_INFINITY-1;
	  range->mode = R_INTERVAL;
	  return;
	}

      Set_Range_Comp_Term(range,range->min);
      Range_MulA_Term(range,range->sigma);
      return;

    case R_INTERVAL:
      range->min = 0;
      range->max = INTERVAL_INFINITY;
      return;
	      
    case R_SPARSE:
      Vector_DA(range->vec);
      range->min = 0;
      range->max = vec_infinity;
      return;
    }
}


/*-------------------------------------------------------------------------*/
/* ADD_RANGE_RANGE                                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Add_Range_Range(Range *r, Range *r1)

{  
  int     temp_min;
  int     temp_max;
  VecWord temp_sigma;
  Range   temp_r;
 
  switch (r1->mode)
    {
    case R_EMPTY:
      r->mode = R_EMPTY;
      return;

    case R_INTEGER:
     switch (r->mode)
	{
	case R_EMPTY:
	  return ;

	case R_INTEGER: case R_INTERVAL:
	  r->sigma = MulA(r->sigma,r1->sigma);
	  if (IsNullA(r->sigma))
	    {
	      r->mode = R_EMPTY;
	    }
	  else
	    {
	      r->min += r1->min;
	      r->max += r1->min;
	    }
	  return;
	      
	case R_SPARSE:
	  Add_Vector_Term(r->vec,r1->min) ;
	  Vector_MulA_Term(r->vec,r1->sigma);
	  Range_From_Vector(r);
	  return;	      
	}

    case R_INTERVAL:
      switch (r->mode)
	{
	case R_EMPTY:
	  r->mode  = R_EMPTY;
	  return ;

	case R_INTEGER: case R_INTERVAL:
	  r->sigma = MulA(r->sigma,r1->sigma);
	  if (IsNullA(r->sigma))
	    {
	      r->mode = R_EMPTY;
	    }
	  else
	    {
	      r->max += r1->max;
	      r->min += r1->min;
	      r->mode = R_INTERVAL;
	    }
	  return;
	  
	case R_SPARSE:
	 Init_Range_Range(&temp_r,r1);
	 Range_Becomes_Sparse(&temp_r);
	 Add_Vector_Vector(r->vec,temp_r.vec);
	 Range_From_Vector(r);
	 return;
	}

    case R_SPARSE:
      switch (r->mode)
	{
	case R_EMPTY:
	  r->mode = R_EMPTY;
	  return ;

	case R_INTEGER:
	  temp_min = r->min;
	  temp_sigma = r->sigma;
	  Range_Copy(r,r1);
	  Add_Vector_Term(r->vec,temp_min) ;
	  Vector_MulA_Term(r->vec,temp_sigma);
	  Range_From_Vector(r);
	  return;

	case R_INTERVAL:
	  Range_Becomes_Sparse(r);
	case R_SPARSE:
	  Add_Vector_Vector(r->vec,r1->vec);
	  Range_From_Vector(r);
	  return;
	}
    }
}


/*-------------------------------------------------------------------------*/
/* SUB_RANGE_RANGE                                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Sub_Range_Range(Range *r, Range *r1)

{  
  int     temp_min;
  int     temp_max;
  VecWord temp_sigma;
  Range   temp_r;
 
  switch (r1->mode)
    {
    case R_EMPTY:
      r->mode = R_EMPTY;
      return;

    case R_INTEGER:
     switch (r->mode)
	{
	case R_EMPTY:
	  return ;

	case R_INTEGER: case R_INTERVAL:
	  r->sigma = MulA(r->sigma,r1->sigma);
	  if (IsNullA(r->sigma))
	    {
	      r->mode = R_EMPTY;
	      return;
	    }
	  else
	    {
	      r->min -= r1->min;
	      r->max -= r1->min;
	      if (r->max < 0)
		{
		  r->mode = R_EMPTY;
		  return;
		}
	      
	      if (r->min < 0)
		r->min = 0;
	      
	      if (r->min == r->max)
		r->mode = R_INTEGER;
	      else 
		r->mode = R_INTERVAL;
	    }
	  return;
	      
	case R_SPARSE:
	  Sub_Vector_Term(r->vec,r1->min) ;
	  Vector_MulA_Term(r->vec,r1->sigma);
	  Range_From_Vector(r);
	  return;	      
	}

    case R_INTERVAL:
      switch (r->mode)
	{
	case R_EMPTY:
	  r->mode  = R_EMPTY;
	  return ;

	case R_INTEGER: case R_INTERVAL:
	  r->sigma = MulA(r->sigma,r1->sigma);
	  if (IsNullA(r->sigma))
	    {
	      r->mode = R_EMPTY;
	    }
	  else
	    {
	      r->min -= r1->max;
	      r->max -= r1->min;
	      if (r->max < 0)
		{
		  r->mode = R_EMPTY;
		  return;
		}

	      if (r->min < 0)
		r->min = 0;

	      if (r->min == r->max)
		r->mode = R_INTEGER;
	      else
		r->mode = R_INTERVAL;
	    }
	  return;
	  
	case R_SPARSE:
	 Init_Range_Range(&temp_r,r1);
	 Range_Becomes_Sparse(&temp_r);
	 Sub_Vector_Vector(r->vec,temp_r.vec);
	 Range_From_Vector(r);
	 return;
	}

    case R_SPARSE:
      switch (r->mode)
	{
	case R_EMPTY:
	  r->mode = R_EMPTY;
	  return ;

	case R_INTEGER: case R_INTERVAL: 
	  Range_Becomes_Sparse(r);
	case R_SPARSE:
	  Sub_Vector_Vector(r->vec,r1->vec);
	  Range_From_Vector(r);
	  return;
	}
    }
}


/*-------------------------------------------------------------------------*/
/* MUL_RANGE_RANGE                                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Mul_Range_Range(Range *r, Range *r1)

{  
  int     temp_min;
  int     temp_max;
  VecWord temp_sigma;
  Range   temp_r;
 
  switch (r1->mode)
    {
    case R_EMPTY:
      r->mode = R_EMPTY;
      return;

    case R_INTEGER:
     switch (r->mode)
	{
	case R_EMPTY:
	  return ;

	case R_INTEGER:
	  r->sigma = MulA(r->sigma,r1->sigma);
	  if (IsNullA(r->sigma))
	    {
	      r->mode = R_EMPTY;
	    }
	  else
	    {
	      r->min = M_Mul(r->min,r1->min);
	      r->max = r->min;
	    }
	  return;

	case R_INTERVAL:
	 Range_Becomes_Sparse(r);
	 Mul_Vector_Term(r->vec,r1->min) ;
	 Vector_MulA_Term(r->vec,r1->sigma);
	 Range_From_Vector(r);
	 return;
	      
	case R_SPARSE:
	  Mul_Vector_Term(r->vec,r1->min) ;
	  Vector_MulA_Term(r->vec,r1->sigma);
	  Range_From_Vector(r);
	  return;	      
	}

    case R_INTERVAL:
      switch (r->mode)
	{
	case R_EMPTY:
	  r->mode  = R_EMPTY;
	  return ;

	case R_INTEGER:
	  temp_min = r->min;
	  temp_sigma = r->sigma;
	  Range_Copy(r,r1);
	  Range_Becomes_Sparse(r);
	  Mul_Vector_Term(r->vec,temp_min) ;
	  Vector_MulA_Term(r->vec,temp_sigma);
	  Range_From_Vector(r);
	  return;

	case R_INTERVAL:
	  Range_Becomes_Sparse(r);
	  Init_Range_Range(&temp_r,r1);
	  Range_Becomes_Sparse(&temp_r);
	  Mul_Vector_Vector(r->vec,temp_r.vec);
	  Range_From_Vector(r);
	  return;
	  
	case R_SPARSE:
	 Init_Range_Range(&temp_r,r1);
	 Range_Becomes_Sparse(&temp_r);
	 Mul_Vector_Vector(r->vec,temp_r.vec);
	 Range_From_Vector(r);
	 return;
	}

    case R_SPARSE:
      switch (r->mode)
	{
	case R_EMPTY:
	  r->mode = R_EMPTY;
	  return ;

	case R_INTEGER:
	  temp_min = r->min;
	  temp_sigma = r->sigma;
	  Range_Copy(r,r1);
	  Mul_Vector_Term(r->vec,temp_min) ;
	  Vector_MulA_Term(r->vec,temp_sigma);
	  Range_From_Vector(r);
	  return;

	case R_INTERVAL:
	  Range_Becomes_Sparse(r);
	case R_SPARSE:
	  Mul_Vector_Vector(r->vec,r1->vec);
	  Range_From_Vector(r);
	  return;
	}
    }
}


/*-------------------------------------------------------------------------*/
/* DIV_RANGE_RANGE                                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Div_Range_Range(Range *r, Range *r1)

{  
  int     temp_min;
  int     temp_max;
  VecWord temp_sigma;
  Range   temp_r;
 
  switch (r1->mode)
    {
    case R_EMPTY:
      r->mode = R_EMPTY;
      return;

    case R_INTEGER:
     switch (r->mode)
	{
	case R_EMPTY:
	  return ;

	case R_INTEGER:
	  r->sigma = MulA(r->sigma,r1->sigma);
	  if (IsNullA(r->sigma))
	    {
	      r->mode = R_EMPTY;
	    }
	  else
	    {
	      if (r1->min == 0)
		{
		  if (r->min == 0)
		    {
		      r->max = INTERVAL_INFINITY;
		      r->mode = R_INTERVAL;
		    }
		  else
		    {
		      r->mode = R_EMPTY;
		    }
		}
	      else
		{
		  if (M_Mod(r->min,r1->min))
		    {
		      r->mode = R_EMPTY;
		    }
		  else
		    {
		      r->min = M_Div(r->min,r1->min);
		      r->max = r->min;
		    }
		}
	    }
	  return;

	case R_INTERVAL:
	 Range_Becomes_Sparse(r);
	 Div_Vector_Term(r->vec,r1->min) ;
	 Vector_MulA_Term(r->vec,r1->sigma);
	 Range_From_Vector(r);
	 return;
	      
	case R_SPARSE:
	  Div_Vector_Term(r->vec,r1->min) ;
	  Vector_MulA_Term(r->vec,r1->sigma);
	  Range_From_Vector(r);
	  return;	      
	}

    case R_INTERVAL:
      switch (r->mode)
	{
	case R_EMPTY:
	  r->mode  = R_EMPTY;
	  return ;

	case R_INTEGER:
	  temp_min = r->min;
	  temp_sigma = r->sigma;
	  Range_Copy(r,r1);
	  Range_Becomes_Sparse(r);
	  Div_Vector_Term(r->vec,temp_min) ;
	  Vector_MulA_Term(r->vec,temp_sigma);
	  Range_From_Vector(r);
	  return;

	case R_INTERVAL:
	  Range_Becomes_Sparse(r);
	case R_SPARSE:
	 Init_Range_Range(&temp_r,r1);
	 Range_Becomes_Sparse(&temp_r);
	 Div_Vector_Vector(r->vec,temp_r.vec);
	 Range_From_Vector(r);
	 return;
	}

    case R_SPARSE:
      switch (r->mode)
	{
	case R_EMPTY:
	  r->mode = R_EMPTY;
	  return ;

	case R_INTEGER: case R_INTERVAL:
	  Range_Becomes_Sparse(r);
	case R_SPARSE:
	  Div_Vector_Vector(r->vec,r1->vec);
	  Range_From_Vector(r);
	  return;
	}
    }
}


/*-------------------------------------------------------------------------*/
/* ADD_RANGE_TERM                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Add_Range_Term(Range *r,int n)

{    
  switch(r->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER: case R_INTERVAL:
      r->min += n;
      r->max += n;
      return;
      
    case R_SPARSE:
      Add_Vector_Term(r->vec,n);
      Range_From_Vector(r);
      return;
    }
}


/*-------------------------------------------------------------------------*/
/* SUB_RANGE_TERM                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Sub_Range_Term(Range *r,int n)

{    
  switch(r->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER:
      r->min -= n;
      if (r->min < 0)
	r->mode = R_EMPTY;
      r->max = r->min;
      return;
      
    case R_INTERVAL:
      r->min = math_max(0,r->min - n);
      r->max -= n;
      if (r->min > r->max)
	r->mode = R_EMPTY;
      if (r->min == r->max)
	r->mode = R_INTEGER;
      return;
      
    case R_SPARSE:
      Sub_Vector_Term(r->vec,n);
      Range_From_Vector(r);
      return;
    }
}


/*-------------------------------------------------------------------------*/
/* MUL_RANGE_TERM                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Mul_Range_Term(Range *r, int n)

{           
  if (n == 0)
    {
      r->max = r->min = 0;
      r->mode = R_INTEGER;
      return;
    }
  
  switch(r->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER:
      r->max = r->min = M_Mul(r->min,n);
      return;
      
    case R_INTERVAL:
     Range_Becomes_Sparse(r);
    case R_SPARSE:
      Mul_Vector_Term(r->vec,n);
      Range_From_Vector(r);
      return;
    }
}

/*-------------------------------------------------------------------------*/
/* DIV_RANGE_TERM                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Div_Range_Term(Range *r, int n)

{                 
  if (n == 0)
    {
      if (r->min > 0)
	{
	  r->mode = R_EMPTY;
	}
      else
	{
	  r->max = INTERVAL_INFINITY;
	  r->sigma = Value_Of_Int_In_Range(r,0);
	  r->mode = R_INTERVAL;
	}
      return;
    }
  
  switch(r->mode)
    {
    case R_EMPTY:
      return;
      
    case R_INTEGER:
      if (M_Mod(r->min,n))
	{
	  r->mode = R_EMPTY;
	  return;
	}
      r->max = r->min = M_Div(r->min,n);
      return;
      
    case R_INTERVAL:
      Range_Becomes_Sparse(r);
    case R_SPARSE:
      Div_Vector_Term(r->vec,n);
      Range_From_Vector(r);
      return;
    }
}



/*-------------------------------------------------------------------------*/
/* RANGE_WRITE                                                             */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_Write(FILE *out,Range *range)

{
 extern int fprintf(FILE *f,const char *format,...);
 
 switch(range->mode)
   {
   case R_EMPTY:
     Lib2(fprintf,out,"<empty range>");
     return;
     
   case R_INTEGER:
     Lib3(fprintf,out,"%i->", range->min);
     Lib3(fprintf,out,A_FORMAT,  range->sigma);
     return;
     
   case R_INTERVAL:
      Lib4(fprintf,out,"%i..%i->", range->min,range->max);
      Lib3(fprintf,out,A_FORMAT,  range->sigma);
      return;
      
    case R_SPARSE:
      BEGIN_ENUM_VECTORA((range->vec))
        Lib3(fprintf,out,A_FORMAT,vec_val);
        Lib2(fprintf,out," ");
      END_ENUM_VECTORA  
      return;
   }
}


/*-------------------------------------------------------------------------*/
/* RANGE_VALUE_INDEX                                                       */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Range_Value_Index(Range *range, VecWord *bv, int *bi)
{
  switch(range->mode)
   {
   case R_EMPTY:
     *bi = -1;
     *bv = NullA;
     return;
     
   case R_INTEGER: case R_INTERVAL:
     *bi = range->min;
     *bv = range->sigma;
     return;
     
      
    case R_SPARSE:
      Vector_Value_Index(range->vec,bv,bi) ;
      return;
   }
}


/*-------------------------------------------------------------------------*/
/* SETS_RANGE_VALUE_INDEX                                                  */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Sets_Range_Value_Index(Range *range, int *bn, int *bi)
{
  switch(range->mode)
   {
   case R_EMPTY:
     *bi = -1;
     *bn = 0;
     return;
     
   case R_INTEGER: case R_INTERVAL:
     *bi = range->min;
     *bn = Bits_Nb_In_Value(range->sigma);
     return;     
      
    case R_SPARSE:
      Sets_Vector_Value_Index(range->vec,bn,bi) ;
      return;
   }
}






