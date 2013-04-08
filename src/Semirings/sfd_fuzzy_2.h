#define A_NAME        "Fuzzy 2"

#define AddA(x,y)     (math_max((x),(y)))  
#define MulA(x,y)     (math_min((x),(y)))  

#define A_SIZE        2    
#define A_SIZE_BITS   1     
#define A_WD_SZ_BITS  4     
#define A_MASK        0x03  

#define A_FORMAT      "%i" 

#define GreaterOrEqualA(x,y)   ((x) >= (y))
#define GreaterA(x,y)          ((x) > (y)) 
#define LessOrEqualA(x,y)      ((x) <= (y))
#define LessA(x,y)             ((x) < (y))
