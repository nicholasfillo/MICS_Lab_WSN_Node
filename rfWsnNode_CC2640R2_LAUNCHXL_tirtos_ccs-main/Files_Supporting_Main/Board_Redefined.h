#ifndef __BOARD_H
#define __BOARD_H

#define Board_CC2640R2_LAUNCHXL

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/drivers/Board.h>

#define Board_initGeneral()     Board_init() /* deprecated */ //initialize the micro-controller (Usually present in the first line in main)

#include "CC2640R2_LAUNCHXL.h"

#define Board_shutDownExtFlash() CC2640R2_LAUNCHXL_shutDownExtFlash()  //Shut down program memory
#define Board_wakeUpExtFlash() CC2640R2_LAUNCHXL_wakeUpExtFlash()      //Wake up program memory

/* These #defines allow us to reuse TI-RTOS across other device families */

#define Board_ADC0              CC2640R2_LAUNCHXL_ADC0
#define Board_ADC1              CC2640R2_LAUNCHXL_ADC1                 // ADC

#define Board_ADCBUF0           CC2640R2_LAUNCHXL_ADCBUF0
#define Board_ADCBUF0CHANNEL0   CC2640R2_LAUNCHXL_ADCBUF0CHANNEL0
#define Board_ADCBUF0CHANNEL1   CC2640R2_LAUNCHXL_ADCBUF0CHANNEL1     // ADC buffers

#define Board_CRYPTO0           CC2640R2_LAUNCHXL_CRYPTO0
#define Board_AESCCM0           CC2640R2_LAUNCHXL_AESCCM0
#define Board_AESGCM0           CC2640R2_LAUNCHXL_AESGCM0
#define Board_AESCBC0           CC2640R2_LAUNCHXL_AESCBC0
#define Board_AESCTR0           CC2640R2_LAUNCHXL_AESCTR0
#define Board_AESECB0           CC2640R2_LAUNCHXL_AESECB0
#define Board_AESCTRDRBG0       CC2640R2_LAUNCHXL_AESCTRDRBG0
#define Board_TRNG0             CC2640R2_LAUNCHXL_TRNG0               // Encryption adn Decryption

#define Board_DIO0              CC2640R2_LAUNCHXL_DIO0
#define Board_DIO1_RFSW         CC2640R2_LAUNCHXL_DIO1_RFSW
#define Board_DIO12             CC2640R2_LAUNCHXL_DIO12
#define Board_DIO15             CC2640R2_LAUNCHXL_DIO15
#define Board_DIO16_TDO         CC2640R2_LAUNCHXL_DIO16_TDO
#define Board_DIO17_TDI         CC2640R2_LAUNCHXL_DIO17_TDI
#define Board_DIO21             CC2640R2_LAUNCHXL_DIO21
#define Board_DIO22             CC2640R2_LAUNCHXL_DIO22            // Pin Digital I/O

#define Board_DIO23_ANALOG      CC2640R2_LAUNCHXL_DIO23_ANALOG
#define Board_DIO24_ANALOG      CC2640R2_LAUNCHXL_DIO24_ANALOG
#define Board_DIO25_ANALOG      CC2640R2_LAUNCHXL_DIO25_ANALOG
#define Board_DIO26_ANALOG      CC2640R2_LAUNCHXL_DIO26_ANALOG
#define Board_DIO27_ANALOG      CC2640R2_LAUNCHXL_DIO27_ANALOG
#define Board_DIO28_ANALOG      CC2640R2_LAUNCHXL_DIO28_ANALOG
#define Board_DIO29_ANALOG      CC2640R2_LAUNCHXL_DIO29_ANALOG
#define Board_DIO30_ANALOG      CC2640R2_LAUNCHXL_DIO30_ANALOG     // Pin Analog and Digital I/O

#define Board_GPIO_BUTTON0      CC2640R2_LAUNCHXL_GPIO_S1
#define Board_GPIO_BUTTON1      CC2640R2_LAUNCHXL_GPIO_S2
#define Board_GPIO_BTN1         CC2640R2_LAUNCHXL_GPIO_S1
#define Board_GPIO_BTN2         CC2640R2_LAUNCHXL_GPIO_S2
#define Board_GPIO_LED0         CC2640R2_LAUNCHXL_GPIO_LED_RED
#define Board_GPIO_LED1         CC2640R2_LAUNCHXL_GPIO_LED_GREEN
#define Board_GPIO_LED2         CC2640R2_LAUNCHXL_GPIO_LED_RED
#define Board_GPIO_RLED         CC2640R2_LAUNCHXL_GPIO_LED_RED
#define Board_GPIO_GLED         CC2640R2_LAUNCHXL_GPIO_LED_GREEN
#define Board_GPIO_LED_ON       CC2640R2_LAUNCHXL_GPIO_LED_ON
#define Board_GPIO_LED_OFF      CC2640R2_LAUNCHXL_GPIO_LED_OFF
#define Board_GPIO_TMP116_EN    CC2640R2_LAUNCHXL_GPIO_TMP116_EN      //GPIO for buttons and LEDs

#define Board_GPTIMER0A         CC2640R2_LAUNCHXL_GPTIMER0A
#define Board_GPTIMER0B         CC2640R2_LAUNCHXL_GPTIMER0B
#define Board_GPTIMER1A         CC2640R2_LAUNCHXL_GPTIMER1A
#define Board_GPTIMER1B         CC2640R2_LAUNCHXL_GPTIMER1B
#define Board_GPTIMER2A         CC2640R2_LAUNCHXL_GPTIMER2A
#define Board_GPTIMER2B         CC2640R2_LAUNCHXL_GPTIMER2B
#define Board_GPTIMER3A         CC2640R2_LAUNCHXL_GPTIMER3A
#define Board_GPTIMER3B         CC2640R2_LAUNCHXL_GPTIMER3B  // 4 general-purpose timers; each 32-bit; can be split 2*16-bit

#define Board_I2C0              CC2640R2_LAUNCHXL_I2C0
#define Board_I2C_TMP           Board_I2C0

#define Board_I2S0              CC2640R2_LAUNCHXL_I2S0
#define Board_I2S_ADO           CC2640R2_LAUNCHXL_I2S_ADO
#define Board_I2S_ADI           CC2640R2_LAUNCHXL_I2S_ADI
#define Board_I2S_BCLK          CC2640R2_LAUNCHXL_I2S_BCLK
#define Board_I2S_MCLK          CC2640R2_LAUNCHXL_I2S_MCLK
#define Board_I2S_WCLK          CC2640R2_LAUNCHXL_I2S_WCLK       //Clocks

#define Board_NVSINTERNAL       CC2640R2_LAUNCHXL_NVSCC26XX0
#define Board_NVSEXTERNAL       CC2640R2_LAUNCHXL_NVSSPI25X0     //non-volatile storage internal/external

#define Board_PIN_BUTTON0       CC2640R2_LAUNCHXL_PIN_BTN1
#define Board_PIN_BUTTON1       CC2640R2_LAUNCHXL_PIN_BTN2
#define Board_PIN_BTN1          CC2640R2_LAUNCHXL_PIN_BTN1
#define Board_PIN_BTN2          CC2640R2_LAUNCHXL_PIN_BTN2
#define Board_PIN_LED0          CC2640R2_LAUNCHXL_PIN_RLED
#define Board_PIN_LED1          CC2640R2_LAUNCHXL_PIN_GLED
#define Board_PIN_LED2          CC2640R2_LAUNCHXL_PIN_RLED
#define Board_PIN_RLED          CC2640R2_LAUNCHXL_PIN_RLED
#define Board_PIN_GLED          CC2640R2_LAUNCHXL_PIN_GLED        // Pins for butons and LEDs

#define Board_PWM0              CC2640R2_LAUNCHXL_PWM0
#define Board_PWM1              CC2640R2_LAUNCHXL_PWM1
#define Board_PWM2              CC2640R2_LAUNCHXL_PWM2
#define Board_PWM3              CC2640R2_LAUNCHXL_PWM3
#define Board_PWM4              CC2640R2_LAUNCHXL_PWM4
#define Board_PWM5              CC2640R2_LAUNCHXL_PWM5
#define Board_PWM6              CC2640R2_LAUNCHXL_PWM6
#define Board_PWM7              CC2640R2_LAUNCHXL_PWM7          // PWM

#define Board_SD0               CC2640R2_LAUNCHXL_SDSPI0

#define Board_SPI0              CC2640R2_LAUNCHXL_SPI0
#define Board_SPI1              CC2640R2_LAUNCHXL_SPI1
#define Board_SPI_FLASH_CS      CC2640R2_LAUNCHXL_SPI_FLASH_CS
#define Board_FLASH_CS_ON       0
#define Board_FLASH_CS_OFF      1                                      // SPI

#define Board_SPI_MASTER        CC2640R2_LAUNCHXL_SPI0
#define Board_SPI_SLAVE         CC2640R2_LAUNCHXL_SPI0
#define Board_SPI_MASTER_READY  CC2640R2_LAUNCHXL_SPI_MASTER_READY
#define Board_SPI_SLAVE_READY   CC2640R2_LAUNCHXL_SPI_SLAVE_READY

#define Board_UART0             CC2640R2_LAUNCHXL_UART0

#define Board_WATCHDOG0         CC2640R2_LAUNCHXL_WATCHDOG0

#ifdef __cplusplus
}
#endif

#endif /* __BOARD_H */
