#include "main.h"
int main(){
    #if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
    #endif
    OS_ENTER_CRITICAL();
    OS_ENTER_CRITICAL();
    OS_EXIT_CRITICAL();
    OS_EXIT_CRITICAL();

    return 0;
}