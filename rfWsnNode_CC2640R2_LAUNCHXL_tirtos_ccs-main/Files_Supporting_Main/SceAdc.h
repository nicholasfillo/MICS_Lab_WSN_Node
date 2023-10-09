#ifndef SCEADC_H_
#define SCEADC_H_

#include "stdint.h"
#include "sce/scif.h"


typedef void(*SceAdc_adcCallback)(uint16_t adcValue[], uint16_t size);

/* Initializes the SCE ADC sampling task.
 *
 * This loads the SCE with the ADC sampling task, sets the sampling time and the ADC change mask.
 * The ADC change mask can be used to mask the bits that needs to be changed for the ADC task to
 * signal, and potentially wake up, the CM3 with a new sensor value update.
 * The Minimun Report Interval will be used to send sensor data on a minimum interval in case sensor
 * data does not change within this time. The Minimun Report Interval can be set to 0 if no minimum
 * report interval is required.
 *
 * Note that this does not start the task, see SceAdc_start for starting a task.
 */
void SceAdc_init(uint32_t samplingTime, uint32_t minReportInterval, uint16_t adcChangeMask);

/* Sets the SCE ADC sampling task report interval and minimum change.
 *
 * The ADC change mask can be used to mask the bits that needs to be changed for the ADC task to
 * signal, and potentially wake up, the CM3 with a new sensor value update.
 * The Minimun Report Interval will be used to send sensor data on a minimum interval in case sensor
 * data does not change within this time. The Minimun Report Interval can be set to 0 if no minimum
 * report interval is required.
 *
 * Note that this can be called after the task has been started.
 */
void SceAdc_setReportInterval(uint32_t minReportInterval, uint16_t adcChangeMask);

/* Register the callback used for receiving the updated ADC value.
 *
 * Note that only one callback may be registered at a time.
 */
void SceAdc_registerAdcCallback(SceAdc_adcCallback callback);

/* Starts the SCE ADC sampling task.
 *
 * The task has to be initialized using SceAdc_init before being started. */
void SceAdc_start(void);


#endif /* SCEADC_H_ */
