#define A_NAME = "Fuzzy 32"

#define AddA(x,y)       (math_max((x),(y)))  
#define MulA(x,y)       (math_min((x),(y)))  

#define A_SIZE        32    
#define A_SIZE_BITS   5    
#define A_WD_SZ_BITS  0     
#define A_MASK        ((VecWord) 0xFFFFFFFF)

#define A_FORMAT      "%8x"

#define GreaterOrEqualA(x,y)   ((x) >= (y))
#define GreaterA(x,y)          ((x) > (y)) 
#define LessOrEqualA(x,y)      ((x) <= (y))
#define LessA(x,y)             ((x) < (y))
