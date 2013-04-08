/*-------------------------------------------------------------------------*/
/* Prolog To Wam Compiler                INRIA Rocquencourt - CLoE Project */
/* C Run-time                                           Daniel Diaz - 1994 */
/*                                                                         */
/* Architecture Definition - Description file                              */
/*                                                                         */
/* archi.def                                                               */
/*-------------------------------------------------------------------------*/

/*---------------------------------*/
/* Register Descriptions           */
/*---------------------------------*/



#define NB_OF_X_REGS               256

#define X(x)                       (reg_bank[x])
#define A(a)                       (reg_bank[a])


typedef WamWord *WamWordP;
typedef AtomInf *AtomInfP;

                                            /* global vars as regs         */
          /* FD Registers */
/* @reg 2 WamWordP AF */
/* @reg 2 WamWordP CF */


   /*--- Begin Register Generation ---*/

register WamWord 		*reg_bank asm ("ebx");

#define H			((WamWordP)	 (reg_bank[NB_OF_X_REGS+0]))
#define TR			((WamWordP)	 (reg_bank[NB_OF_X_REGS+1]))
#define TP			((WamWordP)	 (reg_bank[NB_OF_X_REGS+2]))
#define VECSZ			((WamWord)	 (reg_bank[NB_OF_X_REGS+3]))
#define CP			((WamCont)	 (reg_bank[NB_OF_X_REGS+4]))
#define B			((WamWordP)	 (reg_bank[NB_OF_X_REGS+5]))
#define DATE			((WamWord)	 (reg_bank[NB_OF_X_REGS+6]))
#define E			((WamWordP)	 (reg_bank[NB_OF_X_REGS+7]))
#define BC			((WamWordP)	 (reg_bank[NB_OF_X_REGS+8]))
#define S			((WamWordP)	 (reg_bank[NB_OF_X_REGS+9]))
#define NIL			((WamWord)	 (reg_bank[NB_OF_X_REGS+10]))
#define CMN			((WamWord)	 (reg_bank[NB_OF_X_REGS+11]))
#define STAMP			((WamWord)	 (reg_bank[NB_OF_X_REGS+12]))
#define SAVH			((WamWordP)	 (reg_bank[NB_OF_X_REGS+13]))
#define VECINF			((WamWord)	 (reg_bank[NB_OF_X_REGS+14]))


#define NB_OF_REGS          	15
#define NB_OF_ALLOC_REGS    	0
#define NB_OF_NOT_ALLOC_REGS	15
#define REG_BANK_SIZE       	(NB_OF_X_REGS+NB_OF_NOT_ALLOC_REGS)


#define Reg(i)			(((i)==0) ? (WamWord) H  	: \
				 ((i)==1) ? (WamWord) TR 	: \
				 ((i)==2) ? (WamWord) TP 	: \
				 ((i)==3) ? (WamWord) VECSZ	: \
				 ((i)==4) ? (WamWord) CP 	: \
				 ((i)==5) ? (WamWord) B  	: \
				 ((i)==6) ? (WamWord) DATE	: \
				 ((i)==7) ? (WamWord) E  	: \
				 ((i)==8) ? (WamWord) BC 	: \
				 ((i)==9) ? (WamWord) S  	: \
				 ((i)==10) ? (WamWord) NIL	: \
				 ((i)==11) ? (WamWord) CMN	: \
				 ((i)==12) ? (WamWord) STAMP	: \
				 ((i)==13) ? (WamWord) SAVH	: \
				            (WamWord) VECINF)

#ifdef WAM_ENGINE

       char    *reg_tbl[]=	{"H","TR","TP","VECSZ","CP","B","DATE","E","BC","S","NIL","CMN","STAMP","SAVH","VECINF"};

#else

extern char    *reg_tbl[];

#endif




#define NB_OF_USED_MACHINE_REGS 1




#define Save_Machine_Regs(buff_save)		\
    {               				\
     register long reg0 asm ("ebx");		\
     buff_save[0]=reg0;				\
    }




#define Restore_Machine_Regs(buff_save)	\
    {               				\
     register long reg0 asm ("ebx");		\
     reg0=buff_save[0];				\
    }


   /*--- End Register Generation ---*/


#define word_nil                   NIL
#define calling_module_nb          CMN


          /* FD macros */

#define save_H                     SAVH
#define vec_size                   VECSZ
#define vec_infinity               VECINF




/*---------------------------------*/
/* Tag Descriptions                */
/*---------------------------------*/




   /*--- Begin Tag Generation ---*/

#define TAG_SIZE   		3
#define VALUE_SIZE 		29

#define INT        		0 
#define FDV        		1 
#define REF        		2 
#define CST        		3 
#define LST        		4 
#define STC        		5 

#define MALLOC_MASK 		0
#define STACK_MASK  		0
#define MALLOC_START 		0x8000000

#define Tag_Value(t,v)		(((unsigned long) (v) << 3) | (t))
#define Tag_Of(w)     		((unsigned long) (w) & 0x7)

#define UnTag_Integer(w) 	((int) (((long) (w) >> 3)))
#define UnTag_Unsigned(w)	((unsigned) (((unsigned long) (w) >> 3)))
#define UnTag_Stack(w)   	((WamWord *) (((unsigned long) (w) >> 3) | STACK_MASK))
#define UnTag_Malloc(w)  	((unsigned long) (((unsigned long) (w) >> 3) | MALLOC_MASK))

#define NB_OF_TAGS       	6

#define Tag_INT(v)  		Tag_Value(INT,v)
#define UnTag_INT(w) 		UnTag_Integer(w)

#define Tag_FDV(v)  		Tag_Value(FDV,v)
#define UnTag_FDV(w) 		UnTag_Stack(w)

#define Tag_REF(v)  		Tag_Value(REF,v)
#define UnTag_REF(w) 		UnTag_Stack(w)

#define Tag_CST(v)  		Tag_Value(CST,v)
#define UnTag_CST(w) 		((AtomInfP) UnTag_Malloc(w))

#define Tag_LST(v)  		Tag_Value(LST,v)
#define UnTag_LST(w) 		UnTag_Stack(w)

#define Tag_STC(v)  		Tag_Value(STC,v)
#define UnTag_STC(w) 		UnTag_Stack(w)


typedef enum
    {
     INTEGER,
     UNSIGNED,
     STACK,
     MALLOC
    }TypTag;

typedef struct
    {
     char    *name;
     TypTag   type;
    }InfTag;


#ifdef WAM_ENGINE

       InfTag   tag_tbl[]=	{{"INT",INTEGER},
				 {"FDV",STACK},
				 {"REF",STACK},
				 {"CST",MALLOC},
				 {"LST",STACK},
				 {"STC",STACK}};

#else

extern InfTag   tag_tbl[];

#endif


   /*--- End Tag Generation ---*/





/*---------------------------------*/
/* Stack Descriptions              */
/*---------------------------------*/


#define KBytes_To_Wam_Words(kb)    ((1024*kb+sizeof(WamWord)-1)/sizeof(WamWord))

#define Wam_Words_To_KBytes(ww)    (ww*sizeof(WamWord)/1024)

#define Local_Top                  ((B>=E) ? B : E)



   /*--- Begin Stack Generation ---*/

#define NB_OF_STACKS 		3

#define Trail_Stack       	(stk_tbl[0].stack)
#define Trail_Size        	(stk_tbl[0].size)
#define Trail_Offset(adr) 	((WamWord *)(adr)-Trail_Stack)
#define Trail_Used_Size   	Trail_Offset(TR)

#define Global_Stack       	(stk_tbl[1].stack)
#define Global_Size        	(stk_tbl[1].size)
#define Global_Offset(adr) 	((WamWord *)(adr)-Global_Stack)
#define Global_Used_Size   	Global_Offset(H)

#define Local_Stack       	(stk_tbl[2].stack)
#define Local_Size        	(stk_tbl[2].size)
#define Local_Offset(adr) 	((WamWord *)(adr)-Local_Stack)
#define Local_Used_Size   	Local_Offset(Local_Top)


#define Stack_Top(s)       	(((s)==0) ? TR : ((s)==1) ? H : Local_Top)

typedef struct
    {
     char    *name;
     char    *env_var_name;
     int      default_size; 	/* in WamWords */
     int      size;         	/* in WamWords */
     WamWord *stack;
    }InfStack;


#ifdef WAM_ENGINE

       InfStack  stk_tbl[]=	{{"trail","TRAILSZ",131072,0,NULL},
				 {"global","GLOBALSZ",1048576,0,NULL},
				 {"local","LOCALSZ",262144,0,NULL}};

#else

extern InfStack stk_tbl[];

#endif


   /*--- End Stack Generation ---*/

