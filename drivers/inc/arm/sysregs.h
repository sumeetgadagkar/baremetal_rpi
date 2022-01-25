#ifndef SYSREGS_H
#define SYSREGS_H


//----------------------------------------------
// SCR_EL3 (Secure Configration Register) 32 bits Pg.2648 of ARMv8-A architecture profile
//----------------------------------------------
//    [31:14] RES0,
//    TWE[13] 0 - do not trap WFE instruction to EL3
//    TWI[12] 0 - do not trap WFI instruction to EL3
//    ST[11] 1  - do not trap secure access EL1
//    RW[10] 1  - EL2 is AArch64(must also program SCR_EL2)
//    SIF[9] 0  - secure state fetches are permitted
//    HEC[8] 0  - turn off HVC instruction at EL3, EL2 and non-secure EL1 (current exception is taken to current EL)
//    SMD[7] 0  - secure monitor disable
//    [6] RES0
//    [5:4] RES1
//    EA[3] 0   - do not route SError and external abort interrupts to EL3
//    FIQ[2] 0  - do not route FIQ interrupt to EL3
//    IRQ[1] 0  - do not route IRQ interrupt to EL3
//    NS[0] 0   - EL0 and EL1 are in secure state (allowing them access to secure memory)
#define SCR_EL3_ST                              (1 << 11)
#define SCR_EL3_RW                              (1 << 10)
#define SCR_EL3_5_4                             (3 << 4)
#define SCR_EL3_VALUE                           (SCR_EL3_ST | SCR_EL3_RW | SCR_EL3_5_4)

//----------------------------------------------
// ELR_EL3 (Exception Link Register (EL3)) 64 bits Pg.351 of ARMv8-A architecture profile
//----------------------------------------------
//    [63:0]'el1_entry'- stores the address to jump to on executing eret in EL3
// NOTE : This is done in start.S

//----------------------------------------------
// SPSR_EL3 (Saved Program Status Register (EL3)) 32 bits Pg.389 of ARMv8-A architecture profile
//----------------------------------------------
//    [8:6] 1     - mask SError, FIQ and IRQ
//    M[3:0] 0101 - AArch64 state (Exception level and selected SP) that an exception was taken from (EL1h) and will return to on execution of eret
#define SPSR_EL3_MASK_ALL                       (7 << 6)
#define SPSR_EL3_EL1h                           (5 << 0)
#define SPSR_EL3_VALUE                          (SPSR_EL3_MASK_ALL | SPSR_EL3_EL1h)

//----------------------------------------------
// HCR_EL2 (Hypervisor Configuration Register) 64 bits Pg.2487 of ARMv8-A architecture profile
//----------------------------------------------
//    [64:39] RES0
//    MIOCNCE[38] 0
//    TEA[37] 0 - do not route synchronous exteral abort exceptions from EL0 and EL1 to EL2
//    TERR[36]0 - do not trap accesses to error record registers from Non-secure EL1 to EL2
//    [35:34]RES0
//    ID[33] 0  - This control has no effect on stage 2 of the Non-secure EL1&0 translation regime
//    CD[32] 0  - This control has no effect on stage 2 of the Non-secure EL1&0 translation regime for data accesses and translation table walks
//    RW[31] 1  - The Execution state for EL1 is AArch64
//    TRVM[30] 0 - do not trap virtual memory control reads to EL2
//    HCD[29] RES0
//    [28:0] 0 - no exceptions are trapped in EL2
#define HCR_EL2_RW                              (1 << 31)
#define HCR_EL2_VALUE                           HCR_EL2_RW

//----------------------------------------------
// SCTLR_EL1 (System Control Register (EL1)) 32 bits Pg.2654 of ARMv8-A architecture profile
//----------------------------------------------
//    [31:30] RES0
//    [29:28] RES1
//    [27] RES0
//    UCI[26] 0    - Any attempt to execute a DC CVAU, DC CIVAC, DC CVAC, DC CVAP, or IC IVAU instruction at EL0 using AArch64 is trapped to EL1
//    EE[25] 0     - Explicit data accesses at EL1, and stage 1 translation table walks in the EL1&0 translation regime are little-endian
//    E0E[24] 0    - Explicit data accesses at EL0 are little-endian
//    [23:22] RES1
//    [21] RES0
//    [20] RES1
//    WXN[19] 0    - This control has no effect on memory access permissions
//    nTWE[18] 0   - Any attempt to execute a WFE instruction at EL0 is trapped to EL1, if the instruction would otherwise have caused the PE to enter a low-power state
//    [17] RES0
//    nTWI[16] 0   - Any attempt to execute a WFI instruction at EL0 is trapped to EL1, if the instruction would otherwise have caused the PE to enter a low-power state
//    UCT[15] 0    - Accesses to the CTR_EL0 from EL0 using AArch64 are trapped to EL1
//    DZE[14] 0    - Any attempt to execute a DC ZVA instruction at EL0 using AArch64 is trapped to EL1
//    [13] RES0
//    I[12] 0      - Instruction cache disabled
//    [11] RES1
//    [10] RES0
//    UMA[9] 0     - Any attempt at EL0 using AArch64 to execute an MRS, MSR(register), or MSR(immediate) instruction that accesses the DAIF is trapped to EL1
//    SED[8] 0     - SETEND instruction execution is enabled at EL0 using AArch32
//    ITD[7] 0     - All IT instruction functionality is enabled at EL0 using AArch32
//    [6] RES0
//    CP15BEN[5] 0 - EL0 using AArch32: EL0 execution of the CP15DMB, CP15DSB, and CP15ISB instructions is UNDEFINED
//    SA0[4] 0     - SP Alignment check enable for EL0 : disabled
//    SA[3] 0      - SP Alignment check enable for EL1 : disabled
//    C[2] 0       - Data cache disabled
//    A[1]         - Alignment check disabled
//    M[0]         - MMU disable
#define SCTLR_EL1_RESERVED                  ((3 << 28) | (3 << 22) | (1 << 20) | (1 << 11))
#define SCTLR_EL1_EE_LITTLE_ENDIAN          (0 << 25)
#define SCTLR_EL1_EOE_LITTLE_ENDIAN         (0 << 24)
#define SCTLR_EL1_I_CACHE_DISABLED          (0 << 12)
#define SCTLR_EL1_D_CACHE_DISABLED          (0 << 2)
#define SCTLR_EL1_MMU_DISABLED              (0 << 0)
#define SCTLR_EL1_MMU_ENABLED               (1 << 0)

#define SCTLR_EL1_VALUE                     (SCTLR_EL1_RESERVED | SCTLR_EL1_EE_LITTLE_ENDIAN | SCTLR_EL1_I_CACHE_DISABLED | SCTLR_EL1_D_CACHE_DISABLED | SCTLR_EL1_MMU_DISABLED)

#endif