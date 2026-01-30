/*
*Steps for creating starup file
*1. create a vector table( all exception handlers are mandatory )
*2.write start up code which initialises .data and .bss sections in SRAM
*3.calls main()
*/


#include<stdint.h>
//d:\buildEnvironment\tools\arm-gnu-toolchain-15.2.rel1-mingw-w64-x86_64-arm-none-eabi\bin\arm-none-eabi-gcc.exe -c .\stm32_startup.c
#define SRAM_START  0x20000000U
#define SRAM_SIZE   (96 * 1024)     //96 kb
#define SRAM_END    (SRAM_START + SRAM_SIZE)

#define STACK_START SRAM_END
void Reset_handler(void);
void NMI_handler(void)              __attribute__ ((weak, alias ("Default_handler")));
void HardFault_handler(void)        __attribute__ ((weak, alias ("Default_handler")));
void MemManage_handler(void)        __attribute__ ((weak, alias ("Default_handler")));
void BusFault_handler(void)         __attribute__ ((weak, alias ("Default_handler")));
void UsageFault_handler(void)       __attribute__ ((weak, alias ("Default_handler")));
void SVCall_handler(void)           __attribute__ ((weak, alias ("Default_handler")));
void DebugMonitor_handler(void)     __attribute__ ((weak, alias ("Default_handler")));
void PendSV_handler(void)           __attribute__ ((weak, alias ("Default_handler")));
void Systick_handler(void)          __attribute__ ((weak, alias ("Default_handler")));


uint32_t vectors[] __attribute__ ((section (".isr_vector"))) =  {
    STACK_START,                        //0x00
    (uint32_t)&Reset_handler,           //0x04
    (uint32_t)&NMI_handler,             //0x08
    (uint32_t)&HardFault_handler,       //0x0C
    (uint32_t)&MemManage_handler,       //0x10
    (uint32_t)&BusFault_handler,        //0x14
    (uint32_t)&UsageFault_handler,      //0x18
    0,                                  //0x1C
    0,                                  //0x20
    0,                                  //0x24
    0,                                  //0x28
    (uint32_t)&SVCall_handler,          //0x2C
    (uint32_t)&DebugMonitor_handler,    //0x30
    0,                                  //0x34
    (uint32_t)&PendSV_handler,          //0x38
    (uint32_t)&Systick_handler          //0x3C
};


void Reset_handler(void){

    //copy .daata section to SRAM

    //Initiliase the .bss section to zero in SRAM

    //call init function of std library (if required)
    
    //call mian()
}

    
void Default_handler(void){
    while(1);
}