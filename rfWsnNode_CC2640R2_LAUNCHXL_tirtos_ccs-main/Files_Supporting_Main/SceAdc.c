/***** Includes *****/
#include "SceAdc.h"

/* XDCtools Header files */ 
#include <xdc/std.h>
#include <xdc/runtime/System.h>

/* SCE Header files */
#include "sce/scif.h"
#include "sce/scif_framework.h"
#include "sce/scif_osal_tirtos.h"


/***** Variable declarations *****/
static SceAdc_adcCallback adcCallback;


/***** Prototypes *****/
static void ctrlReadyCallback(void);
static void taskAlertCallback(void);


/***** Function definitions *****/
void SceAdc_init(uint32_t samplingTime, uint32_t minReportInterval, uint16_t adcChangeMask) {
    // Initialize the Sensor Controller
    scifOsalInit();
    scifOsalRegisterCtrlReadyCallback(ctrlReadyCallback);
    scifOsalRegisterTaskAlertCallback(taskAlertCallback);
    scifInit(&scifDriverSetup);
    scifStartRtcTicksNow(samplingTime);//can be sampling time /8


    SCIF_ADC_SAMPLE_CFG_T* pCfg = scifGetTaskStruct(SCIF_ADC_SAMPLE_TASK_ID, SCIF_STRUCT_CFG);
    pCfg->changeMask = adcChangeMask;
    //Set minimum report interval in units of samplingTime
    pCfg->minReportInterval = minReportInterval;
}

void SceAdc_setReportInterval(uint32_t minReportInterval, uint16_t adcChangeMask) {
    //Set the report interval and min change in the SC config structure
    SCIF_ADC_SAMPLE_CFG_T* pCfg = scifGetTaskStruct(SCIF_ADC_SAMPLE_TASK_ID, SCIF_STRUCT_CFG);
    pCfg->changeMask = adcChangeMask;
    //Set minimum report interval in units of samplingTime
    pCfg->minReportInterval = minReportInterval;
}

void SceAdc_start(void) {
    // Start task
    scifStartTasksNbl((1 <<SCIF_ADC_SAMPLE_TASK_ID));
}

void SceAdc_registerAdcCallback(SceAdc_adcCallback callback) {
    adcCallback = callback;
}

static void ctrlReadyCallback(void) {
    /* Do nothing */
}

static void taskAlertCallback(void) {//////////////////////keep iterating

    /* Clear the ALERT interrupt source */
    scifClearAlertIntSource();

    /* Only handle the periodic event alert */
    if (scifGetAlertEvents() & (1 << SCIF_ADC_SAMPLE_TASK_ID))
    {

        /* Get the SCE "output" structure */
        SCIF_ADC_SAMPLE_OUTPUT_T* pOutput = scifGetTaskStruct(SCIF_ADC_SAMPLE_TASK_ID, SCIF_STRUCT_OUTPUT);

        /* Send new ADC value to application via callback */
        if (adcCallback)
        {

            adcCallback(pOutput->pAdcValue, 2);
           // adcCallback(pOutput->pAdcValue[0]);

        }
    }

    /* Acknowledge the alert event */
    scifAckAlertEvents();
}
