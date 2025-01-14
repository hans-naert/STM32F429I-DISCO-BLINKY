#include "cmsis_os2.h"                          // CMSIS RTOS header file
#include "Board_LED.h" 
 
/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_Name': Sample thread
 *---------------------------------------------------------------------------*/
 
osThreadId_t tid_Thread;                        // thread id
 
void Thread_LED2 (void *argument);                   // thread function
 
int Init_Thread_LED2 (void) {
 
  tid_Thread = osThreadNew(Thread_LED2, NULL, NULL);
  if (tid_Thread == NULL) {
    return(-1);
  }
 
  return(0);
}
 
void Thread_LED2 (void *argument) {
 
  while (1) {
    ; // Insert thread code here...
		 LED_On (1U);                                // Switch LED on
     osDelay (500U);                             // Delay 500 ms
     LED_Off (1U);                               // Switch off
     osDelay (500U);                             // Delay 500 ms
    osThreadYield();                            // suspend thread
  }
}
