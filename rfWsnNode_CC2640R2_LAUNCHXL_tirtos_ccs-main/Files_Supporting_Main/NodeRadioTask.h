#ifndef TASKS_NODERADIOTASKTASK_H_
#define TASKS_NODERADIOTASKTASK_H_

#include "stdint.h"
#ifdef USE_DMM
#include <ti/sysbios/knl/Task.h>
#endif /* USE_DMM */

#define NODE_ACTIVITY_LED Board_PIN_LED0

enum NodeRadioOperationStatus {
    NodeRadioStatus_Success,
    NodeRadioStatus_Failed,
    NodeRadioStatus_FailedNotConnected,
};

/* Initializes the NodeRadioTask and creates all TI-RTOS objects */
#ifndef USE_DMM
void NodeRadioTask_init(void);
#else
Task_Handle* NodeRadioTask_init(void);
#endif

/* Sends an ADC value to the concentrator */
enum NodeRadioOperationStatus NodeRadioTask_sendAdcData(uint16_t data[]);

/* Get node address, return 0 if node address has not been set */
uint8_t nodeRadioTask_getNodeAddr(void);

#if defined(USE_DMM) && !defined(USE_DMM_BLE_SP)
/* Set node address */
void nodeRadioTask_setNodeAddr(uint8_t newNodeAddress);

/* Set concentrator LED toggle bit in msg and send msg */
void nodeRadioTask_setConcLedToggle(bool concLedToggle);
#endif /* USE_DMM && !USE_DMM_BLE_SP */
#endif /* TASKS_NODERADIOTASKTASK_H_ */
