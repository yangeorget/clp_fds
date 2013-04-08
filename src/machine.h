/*-------------------------------------------------------------------------*/
/* Prolog To Wam Compiler                INRIA Rocquencourt - CLoE Project */
/* C Run-time                                           Daniel Diaz - 1994 */
/*                                                                         */
/* Machine Dependent Features - Header file                                */
/*                                                                         */
/* machine.h                                                               */
/*-------------------------------------------------------------------------*/

/*---------------------------------*/
/* Machine Type (for configure.c)  */
/*---------------------------------*/

#ifdef CONFIGURE

#   if defined(sun) && defined(sparc) && !defined(__svr4__)

#      define M_MACHINE            "sunos"
#      define M_sunos

#   elif defined(sun) && defined(sparc) && defined(__svr4__)

#      define M_MACHINE            "solaris"
#      define M_solaris

#   elif defined(__mips__) && defined(sony_news)

#      define M_MACHINE            "sony_news"
#      define M_sony_news

#   elif defined(__mips__) && defined(ultrix)

#      define M_MACHINE            "dec_ultrix"
#      define M_dec_ultrix

#   elif defined(__alpha) && defined(__osf__)

#      define M_MACHINE            "dec_alpha"
#      define M_dec_alpha

#   elif defined(__linux__) && !defined(__ELF__)

#      define M_MACHINE            "pc_linux_a_out"
#      define M_pc_linux_a_out

#   elif defined(__linux__) && defined(__ELF__)

#      define M_MACHINE            "pc_linux_elf"
#      define M_pc_linux_elf

#   elif defined(__NeXT__) && defined(mc68000)

#      define M_MACHINE            "NeXT_m68k"
#      define M_NeXT_m68k

#   elif defined(__NeXT__) && defined(__hppa__)

#      define M_MACHINE            "NeXT_hppa"
#      define M_NeXT_hppa

#   else

#      error "Unsupported architecture"

#   endif

#endif


#if defined(M_pc_linux_a_out) || defined(M_pc_linux_elf)

#   define M_pc_linux

#endif




/*---------------------------------*/
/* Gcc Specific Options            */
/*---------------------------------*/

#if defined(M_sony_news) || defined(M_dec_ultrix) || defined(M_dec_alpha)

#    define EXTRA_CFLAGS           "-fomit-frame-pointer"
                      /* for alpha if we suppress this, suppres $15 as reg */
#elif defined(M_pc_linux)

#    define EXTRA_CFLAGS           "-m486"

#elif defined(M_NeXT_hppa)

#    define EXTRA_CFLAGS           "-traditional-cpp"

#else

#    define EXTRA_CFLAGS           ""

#endif




/*---------------------------------*/
/* Asm Labels, Symbols and Gotos   */
/*---------------------------------*/

#if defined(M_sony_news) || defined(M_dec_ultrix) || defined(M_dec_alpha) ||\
    defined(M_pc_linux_elf) || defined(M_solaris)

#   define M_Asm_Symbol1(name)     #name
#   define M_Asm_Symbol(name)      M_Asm_Symbol1(name)

#else

#   define M_Asm_Symbol1(name)     "_"#name
#   define M_Asm_Symbol(name)      M_Asm_Symbol1(name)

#endif




#define M_Decl_Global_Label(name)  asm(".globl " M_Asm_Symbol(name));
#define M_Def_Label(name)          asm(M_Asm_Symbol(name) ":");



#if defined(M_sunos) || defined(M_solaris) || defined(M_dec_ultrix) || \
    defined(M_sony_news) || defined(M_NeXT_hppa) || defined(M_dec_alpha)

#    define M_Save_Control_Info
#    define M_Restore_Control_Info


#elif defined(M_pc_linux)

#    define M_Save_Control_Info
#    define M_Restore_Control_Info asm("leal -4096(%ebp),%esp"); 


#elif defined(M_NeXT_m68k)

#    define M_Save_Control_Info
#    define M_Restore_Control_Info asm("lea a6@(-4096),sp"); 

#endif




#if defined(M_sunos)|| defined(M_solaris) || defined(M_dec_ultrix) || \
    defined(M_sony_news) || defined(M_NeXT_hppa)

#    define M_Direct_Goto(lab)     {lab(); return;}
#    define M_Indirect_Goto(p_lab) {(* ((void (*)()) p_lab))();return;}

/* also possible for Sparc with gcc */
/*  #define M_Indirect_Goto(p_lab) {goto *(void*)p_lab;} */


#elif defined(M_dec_alpha)

#    define M_Direct_Goto(lab)     {asm("lda $28," M_Asm_Symbol(lab));      \
                                    asm("jmp $31,($28)," M_Asm_Symbol(lab));\
                                    return;}
#    define M_Indirect_Goto(p_lab) {goto *(void *) p_lab;}


#elif defined(M_pc_linux)

#    ifdef __GNUC__

#    define M_Direct_Goto(lab)     {asm("jmp " M_Asm_Symbol(lab)); return;}
#    define M_Indirect_Goto(p_lab) {goto *(void *) p_lab;}

#    else

     int lab_adr_486;

#    define M_Direct_Goto(lab)     {asm("jmp " M_Asm_Symbol(lab));return;}
#    define M_Indirect_Goto(p_lab) {lab_adr_486=(int) p_lab;                \
                                    asm("movl _lab_adr_486,%eax");          \
                                    asm("jmp *%eax");}
#    endif


#elif defined(M_NeXT_m68k)

#    ifdef __GNUC__

#    define M_Direct_Goto(lab)     {asm("jmp " M_Asm_Symbol(lab)); return;}
#    define M_Indirect_Goto(p_lab) {goto *(void *) p_lab;}

#    else

     int lab_adr_68k;

#    define M_Direct_Goto(lab)     {asm("jmp " M_Asm_Symbol(lab));return;}
#    define M_Indirect_Goto(p_lab) {lab_adr_68k=(int) p_lab;                \
                                    asm("movel _lab_adr_68k,a0");           \
                                    asm("jmp a0@"); return;}
#    endif

#endif




/*---------------------------------*/
/* Register Definitions            */
/*---------------------------------*/

#if defined(M_sunos) && !defined(NO_REGS)

#    define M_USED_REGS            {"g1","g5","g6","g7",0}
#    define M_SAVE_REGS_BEFORE_LIB_C_CALLS

#elif defined(M_solaris) && !defined(NO_REGS)

#    define M_USED_REGS            {"g1","g5","g6","g7",0}
#    define M_SAVE_REGS_BEFORE_LIB_C_CALLS

#elif (defined(M_dec_ultrix) || defined(M_sony_news)) && !defined(NO_REGS)

#    define M_USED_REGS            {"s0","s1","s2","s3","s4","s5","s6","s7",\
                                    0}

#elif defined(M_dec_alpha) && !defined(NO_REGS)

#    define M_USED_REGS            {"$9","$10","$11","$12","$13","$14",\
                                    "$15",0}

#elif defined(M_pc_linux) && !defined(NO_REGS)

#    define M_USED_REGS            {"ebx",0}

#else

#    define M_USED_REGS            {0}

#endif




          /* C library calls default macros */


#ifdef M_SAVE_REGS_BEFORE_LIB_C_CALLS

#    define LibPrototype(p)         p;

#    define Lib_CallD               (* ((double (*)()) Lib_Call))

     int    Lib_Call();

#    define Lib0(f)                 Lib_Call(f)
#    define Lib1(f,a1)              Lib_Call(f,a1)
#    define Lib2(f,a1,a2)           Lib_Call(f,a1,a2)
#    define Lib3(f,a1,a2,a3)        Lib_Call(f,a1,a2,a3)
#    define Lib4(f,a1,a2,a3,a4)     Lib_Call(f,a1,a2,a3,a4)
#    define Lib5(f,a1,a2,a3,a4,a5)  Lib_Call(f,a1,a2,a3,a4,a5)


#    define LibD0(f)                Lib_CallD(f)               
#    define LibD1(f,a1)             Lib_CallD(f,a1)            
#    define LibD2(f,a1,a2)          Lib_CallD(f,a1,a2)         
#    define LibD3(f,a1,a2,a3)       Lib_CallD(f,a1,a2,a3)      
#    define LibD4(f,a1,a2,a3,a4)    Lib_CallD(f,a1,a2,a3,a4)   
#    define LibD5(f,a1,a2,a3,a4,a5) Lib_CallD(f,a1,a2,a3,a4,a5)

#else

#    define LibPrototype(p)

#    define Lib0(f)                 f()
#    define Lib1(f,a1)              f(a1)
#    define Lib2(f,a1,a2)           f(a1,a2)
#    define Lib3(f,a1,a2,a3)        f(a1,a2,a3)
#    define Lib4(f,a1,a2,a3,a4)     f(a1,a2,a3,a4)
#    define Lib5(f,a1,a2,a3,a4,a5)  f(a1,a2,a3,a4,a5)

#    define LibD0(f)                f()
#    define LibD1(f,a1)             f(a1)
#    define LibD2(f,a1,a2)          f(a1,a2)
#    define LibD3(f,a1,a2,a3)       f(a1,a2,a3)
#    define LibD4(f,a1,a2,a3,a4)    f(a1,a2,a3,a4)
#    define LibD5(f,a1,a2,a3,a4,a5) f(a1,a2,a3,a4,a5)

#endif




/*---------------------------------*/
/* Stacks Management               */
/*---------------------------------*/

#if defined(M_sunos) || defined(M_solaris) || defined(M_pc_linux)

#   define M_USE_MMAP
#   define M_MMAP_HIGH_ADR         0x0ffff000
#   define M_Check_Stacks()

#elif defined(M_dec_ultrix)

#   define M_USE_SHM
#   define M_SHM_HIGH_ADR          0x0ffff000
#   define M_Check_Stacks()

#elif defined(M_dec_alpha)

#   define M_USE_MMAP
#   define M_MMAP_HIGH_ADR         0x3f800000000ULL
#   define M_Check_Stacks()        

#else

#   define M_USE_MALLOC
#   define M_Check_Stacks()        M_Check_Magic_Words()

#endif




#if defined(M_USE_MALLOC) || defined(M_pc_linux)

#   define M_USE_MAGIC_NB_TO_DETECT_STACK_NAME
    void   M_Check_Magic_Words(void);

#endif

#define M_SECURITY_MARGIN          128                      /* in WamWords */
#define M_MAGIC                    0x12345678




/*---------------------------------*/
/* Mul, Div and Rem                */
/*---------------------------------*/

#if defined(M_sunos) || defined(M_solaris)

    double fmod(double x,double y);

#   define M_Mul(x,y)   ((long) ((double) (x) * (y)))
#   define M_Div(x,y)   ((long) ((double) (x) / (y)))
#   define M_Mod(x,y)   ((x) - M_Mul(M_Div((x),(y)),(y)))

#else

#   define M_Mul(x,y)   ((x) * (y))
#   define M_Div(x,y)   ((x) / (y))
#   define M_Mod(x,y)   ((x) % (y))

#endif




/*---------------------------------*/
/* Miscellaneous (compatibility)   */
/*---------------------------------*/

#if defined(M_sony_news) || defined(M_dec_ultrix) ||                        \
    defined(M_NeXT_m68k) || defined(M_NeXT_hppa)

#   define strdup(s)  strcpy(malloc(strlen(s)+1),s)

#endif




/*---------------------------------*/
/* Function Prototypes             */
/*---------------------------------*/
