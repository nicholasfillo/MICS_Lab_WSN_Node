#include <xdc/std.h>
#include <xdc/runtime/System.h>                     /* XDCtools Header files */

#include <ti/sysbios/BIOS.h>
#include <ti/display/Display.h>
#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerCC26XX.h>           /* BIOS Header files */

#include "Files_Supporting_Main/Board_Redefined.h"                                  /* Board Header files */

#include "Files_Supporting_Main/NodeRadioTask.h"
#include "Files_Supporting_Main/NodeTask.h"
#include <ti/drivers/ADC.h>                         /* Application Header files */ //Function definition is in ADC.c

#include <stdint.h>

#include <pthread.h>                                /* POSIX Header files */
#include <ti/drivers/Board.h>                       /* Example/Board Header files */

extern void *mainThread(void *arg0);

#define THREADSTACKSIZE    2048                     /* Stack size in bytes */


/*--- Main Function ---*/
int main(void)
{
    /* Call driver init functions. */
    Board_initGeneral(); //initialize the settings in general on the board (CC2640R2) such as pins
    Display_init(); //initialize the display settings on the board

    /* Initialize sensor node tasks */
    NodeRadioTask_init(); // initialize settings such as create nodes for data to transmit
    NodeTask_init(); // initialize settings such as create nodes for internal data processing

    /* created thread */
    pthread_t           thread;
        /* parameters needed to set up a thread */
        pthread_attr_t      attrs;
        struct sched_param  priParam;
        int                 retc;

        /* Call driver init functions */
        //Board_init();

        /* Initialize the attributes structure with default values */
        pthread_attr_init(&attrs);

        /* Set priority, detach state, and stack size attributes */
        priParam.sched_priority = 1;  // execute this thread first (1 means the first)
        retc = pthread_attr_setschedparam(&attrs, &priParam);
        retc |= pthread_attr_setdetachstate(&attrs, PTHREAD_CREATE_DETACHED); // the thread is detached, it is not joinable
        retc |= pthread_attr_setstacksize(&attrs, THREADSTACKSIZE); // thread size 1024 as states above
        if (retc != 0) {
            /* failed to set attributes */
            while (1) {}
        }
        retc = pthread_create(&thread, &attrs, mainThread, NULL); // create a thread
        if (retc != 0) {
            /* pthread_create() failed */
            while (1) {}
        }

    BIOS_start(); //initialize hardwares during booting process (start BIOS)
    return (0);
}
