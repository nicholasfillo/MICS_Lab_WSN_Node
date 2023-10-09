/***** Includes *****/
/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/System.h>
/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Event.h>
#include <ti/sysbios/knl/Clock.h>
/* TI-RTOS Header files */
#include <ti/drivers/PIN.h>
#include <ti/display/Display.h>
#include <ti/display/DisplayExt.h>
#include <ti/devices/DeviceFamily.h>
#include DeviceFamily_constructPath(driverlib/cpu.h)
/* Board Header files */
#include "Board_Redefined.h"
/* Application Header files */
#include "SceAdc.h"
#include "NodeTask.h"
#include "NodeRadioTask.h"
#include "Feature_Extraction.h"
#include <ti/drivers/ADC.h>
//#include "adcsinglechannel.c"
///////////////////////////////////////////////////////////////////////////////////////////
#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <math.h>
/* POSIX Header files */
#include <pthread.h>
/* Driver Header files */
#include <ti/drivers/ADC.h>
#include <ti/display/Display.h>
/* Example/Board Header files */
#include "Board_Redefined.h"
//clock header
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Clock.h>
//mailbox header
#include <xdc/runtime/Error.h>
#include <ti/sysbios/knl/Mailbox.h>

/* POSIX Header files */
#include <pthread.h>
/* Driver Header files */
#include <ti/drivers/ADC.h>
#include <ti/display/Display.h>
/* Example/Board Header files */
#include "Board_Redefined.h"
//clock header
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Clock.h>
//mailbox header
#include <xdc/runtime/Error.h>
#include <ti/sysbios/knl/Mailbox.h>
//Timer
#include <ti/drivers/GPIO.h>
#include <ti/drivers/timer/GPTimerCC26XX.h>
#include <ti/drivers/pin/PINCC26XX.h>

#include <ti/drivers/I2C.h>
#include "bmg250.h"
#include "bmg250_defs.h"
#include "MAX30102.h"


#include <ti/drivers/timer/GPTimerCC26XX.h>


GPTimerCC26XX_Handle hTimer;
bool proceed = false;





//Time and date include
#include <time.h>
#include <sys/_timespec.h>

/* Time Segment Variable Definitions */
float old_time_ms = 0;
float curr_time_ms = 0;
float time_seg_ms;

#define TASKSTACKSIZE       640

static Display_Handle display;

//adc single channel
GPTimerCC26XX_Handle hTimer;
//mailbox handle
Mailbox_Handle my_mailbox;

//message object
typedef struct MsgObj{ uint16_t id; uint16_t val; }MsgObj;

/* ADC sample count */
#define ADC_SAMPLE_COUNT  (10)
#define THREADSTACKSIZE   (768)

/* ADC initialization parameters*/
ADC_Handle adc1,
adc2,
adc3,
adc4,
adc5;




/* ADC conversion result variables */
uint16_t adcValue1,
adcValue2,
adcValue3,
adcValue4,
adcValue5,
threshold;
uint16_t min = 5000;
uint16_t max = 0;
uint16_t countForMin = 0;
bool flag = false;
bool trigger = false;
uint32_t adcValue1MicroVolt, adcValue2MicroVolt;
uint16_t adcValues[ADC_SAMPLE_COUNT];
uint32_t adcValuesMicroVolt[ADC_SAMPLE_COUNT];
int avgThreshold = 0;

static Display_Handle display;

uint32_t timer_val = 0;

/***** Defines *****/
#define NODE_TASK_STACK_SIZE 1024
#define NODE_TASK_PRIORITY   3

#define NODE_EVENT_ALL                  0xFFFFFFFF
#define NODE_EVENT_NEW_ADC_VALUE    (uint32_t)(1 << 0)
#define NODE_EVENT_UPDATE_LCD       (uint32_t)(1 << 1)
#define NODE_EVENT_TIMER            (uint32_t)(1 << 2)

/* A change mask of 0xFF0 means that changes in the lower 4 bits does not trigger a wakeup. */
#define NODE_ADCTASK_CHANGE_MASK                    0xFFF////change here 0xFF0

/* Minimum slow Report interval is 50s (in units of samplingTime)*/
#define NODE_ADCTASK_REPORTINTERVAL_SLOW                50
/* Minimum fast Report interval is 1s (in units of samplingTime) for 30s*/
#define NODE_ADCTASK_REPORTINTERVAL_FAST                5//5
#define NODE_ADCTASK_REPORTINTERVAL_FAST_DURIATION_MS   30000

#define NUM_EDDYSTONE_URLS      5





/***** Variable declarations *****/
static Task_Params nodeTaskParams; Task_Struct nodeTask; /* Not static so you can see in ROV */
static uint8_t nodeTaskStack[NODE_TASK_STACK_SIZE]; Event_Struct nodeEvent; /* Not static so you can see in ROV */
static Event_Handle nodeEventHandle;
static uint16_t latestAdcValue[11]; //ARRAY
//static uint16_t latestAdcValue; //ARRAY

/* Clock for the fast report timeout */
Clock_Struct fastReportTimeoutClock; /* not static so you can see in ROV */
static Clock_Handle fastReportTimeoutClockHandle;

/* Pin driver handle */
static PIN_Handle buttonPinHandle; static PIN_Handle ledPinHandle; static PIN_State buttonPinState; static PIN_State ledPinState;

/* Display driver handles */
static Display_Handle hDisplaySerial;

//static int countervalue;
//static uint16_t debugcounter = 0;
//static uint32_t test;

/* Enable the 3.3V power domain used by the LCD */
PIN_Config pinTable[] = {
#if !defined Board_CC1350STK
NODE_ACTIVITY_LED | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
#endif
PIN_TERMINATE };

/*Application button pin configuration table: - Buttons interrupts are configured to trigger on falling edge.*/
PIN_Config buttonPinTable[] = { Board_PIN_BUTTON0 | PIN_INPUT_EN | PIN_PULLUP | PIN_IRQ_NEGEDGE,
//#ifdef FEATURE_BLE_ADV
Board_PIN_BUTTON1 | PIN_INPUT_EN | PIN_PULLUP | PIN_IRQ_NEGEDGE,
//#endif
PIN_TERMINATE };

static uint8_t nodeAddress = 0;

/***** Prototypes *****/
static void nodeTaskFunction(UArg arg0, UArg arg1);
static void updateLcd(void);
static void fastReportTimeoutCallback(UArg arg0);
static void adcCallback(uint16_t adcValue[], uint16_t size);
static void buttonCallback(PIN_Handle handle, PIN_Id pinId);

/***** Function definitions *****/
void NodeTask_init(void) {

    /* Create event used internally for state changes */
    Event_Params eventParam;
    Event_Params_init(&eventParam);
    Event_construct(&nodeEvent, &eventParam);
    nodeEventHandle = Event_handle(&nodeEvent);

    /* Create clock object which is used for fast report timeout */
    Clock_Params clkParams;
    Clock_Params_init(&clkParams);

    clkParams.period = 10;
    clkParams.startFlag = 1;
    Clock_construct(&fastReportTimeoutClock, fastReportTimeoutCallback, 1, &clkParams);
    fastReportTimeoutClockHandle = Clock_handle(&fastReportTimeoutClock);

    /* Create the node task */
    Task_Params_init(&nodeTaskParams);
    nodeTaskParams.stackSize = NODE_TASK_STACK_SIZE;
    nodeTaskParams.priority = NODE_TASK_PRIORITY;
    nodeTaskParams.stack = &nodeTaskStack;
    Task_construct(&nodeTask, nodeTaskFunction, &nodeTaskParams, NULL);
}

    static void nodeTaskFunction(UArg arg0, UArg arg1) {

    /* Initialize display and try to open both UART and LCD types of display. */
    Display_Params params; Display_Params_init(&params); params.lineClearMode = DISPLAY_CLEAR_BOTH;

    /* Open both an available LCD display and an UART display.
    * Whether the open call is successful depends on what is present in the
    * Display_config[] array of the board file.
    *
    * Removed hDisplayLCD
    *
    * Note that for SensorTag evaluation boards combined with the SHARP96x96
    * Watch DevPack, there is a pin conflict with UART such that one must be
    * excluded, and UART is preferred by default. To display on the Watch
    * DevPack, add the precompiler define BOARD_DISPLAY_EXCLUDE_UART.
    */
    hDisplaySerial = Display_open(Display_Type_UART, &params);
    /* Check if the selected Display type was found and successfully opened */
    if (hDisplaySerial)
    {
        Display_printf(hDisplaySerial, 0, 0, "Waiting for SCE ADC reading...");
    }
    /* Open LED pins */
    ledPinHandle = PIN_open(&ledPinState, pinTable);
    if (!ledPinHandle)
    {
        System_abort("Error initializing board 3.3V domain pins\n");
    }

    buttonPinHandle = PIN_open(&buttonPinState, buttonPinTable);
    if (!buttonPinHandle)
    {
        System_abort("Error initializing button pins\n");
    }
    /* Setup callback for button pins */
    if (PIN_registerIntCb(buttonPinHandle, &buttonCallback) != 0)
    {
        System_abort("Error registering button callback function");
    }
}

/* not used */
static void updateLcd(void) {

    static bool firstDisplay = true;
    /* get node address if not already done */
    if (firstDisplay == true)
    {
        nodeAddress = nodeRadioTask_getNodeAddr();
    }
    /* Print to UART clear screen, put cursor to beginning of terminal and print the header */
    if(firstDisplay == true)
    {
        Display_printf(hDisplaySerial, 0, 0,"Node ID: 0x%02x", nodeAddress);
        Display_printf(hDisplaySerial, 1, 0,"Channel 1    Channel 2    Channel 3    Channel 4    Channel5    Countervalue");
        firstDisplay = false;
    }
    Display_printf(hDisplaySerial, 0, 0, "%04d",latestAdcValue[9]);

    /* TALK TO THE OTHERS ABOUT THIS CALLBACK */
}

static void adcCallback(uint16_t adcValue[], uint16_t size) //change to array
{

/* Post event */
 //Event_post(nodeEventHandle, NODE_EVENT_NEW_ADC_VALUE);
}

/*
 *  ======== buttonCallback ========
 *  Pin interrupt Callback function board buttons configured in the pinTable.
 */
static void buttonCallback(PIN_Handle handle, PIN_Id pinId) {
    /* Debounce logic, only toggle if the button is still pushed (low) */
    CPUdelay(8000*50);

    if (PIN_getInputValue(Board_PIN_BUTTON0) == 0) {
    //start fast report and timeout
    SceAdc_setReportInterval(NODE_ADCTASK_REPORTINTERVAL_FAST, NODE_ADCTASK_CHANGE_MASK); Clock_start(fastReportTimeoutClockHandle); }

    else if (PIN_getInputValue(Board_PIN_BUTTON1) == 0) {
    /* update display */
    //Event_post(nodeEventHandle, NODE_EVENT_UPDATE_LCD);

    //start fast report and timeout
    SceAdc_setReportInterval(NODE_ADCTASK_REPORTINTERVAL_FAST, NODE_ADCTASK_CHANGE_MASK); Clock_start(fastReportTimeoutClockHandle); }

}

static void fastReportTimeoutCallback(UArg arg0) {
    //stop fast report
    SceAdc_setReportInterval(NODE_ADCTASK_REPORTINTERVAL_SLOW, NODE_ADCTASK_CHANGE_MASK);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////adc single channel

void timerCallback(GPTimerCC26XX_Handle handle, GPTimerCC26XX_IntMask interruptMask) {
    // interrupt callback code goes here. Minimize processing in interrupt.
    proceed = true;
    Event_post(nodeEventHandle, NODE_EVENT_TIMER);
}


void init_indv_adc(ADC_Handle adc, ADC_Params params, CC2640R2_LAUNCHXL_ADCName adcname) {
    adc = ADC_open(adcname, &params);
    if (adc == NULL) {
    Display_printf(display, 0, 0, "Error initializing ADC0\n");
    }
}

void init_all_adc()
{
    ADC_init();
    ADC_Params params;
    ADC_Params_init(&params);
    //adc1=adc_open(Board_ADC1, &params);
    adc1 = ADC_open(Board_ADC0, &params);
    if (adc1 == NULL) {
        Display_printf(display, 0, 0, "Error initializing ADC0\n");
    }

    adc2 = ADC_open( CC2640R2_LAUNCHXL_ADC1, &params);
    if (adc2 == NULL) {
        Display_printf(hDisplaySerial, 0, 0, "Error initializing ADC1\n");
    }

    adc3 = ADC_open(CC2640R2_LAUNCHXL_ADC2, &params);
    if (adc3 == NULL) {
        Display_printf(hDisplaySerial, 0, 0, "Error initializing ADC1\n");
    }

    adc4 = ADC_open( CC2640R2_LAUNCHXL_ADC3, &params);
    if (adc4 == NULL) { 
        Display_printf(hDisplaySerial, 0, 0, "Error initializing ADC1\n");  //Error Initializing adc4???
    }

    adc5 = ADC_open( CC2640R2_LAUNCHXL_ADC4, &params);
    if (adc5 == NULL) { 
        Display_printf(hDisplaySerial, 0, 0, "Error initializing ADC1\n");
    }
}

void close_all_adc()
{
    ADC_close(adc1);
    ADC_close(adc2);
    ADC_close(adc3);
    ADC_close(adc4);
    ADC_close(adc5);
}


void read_adc()
{
    //ADC_Handle adc;
    //ADC_Params params;
    int_fast16_t res;



    //ADC_init();
    //ADC_Params_init(&params);
    //adc = ADC_open(Board_ADC0, &params);

    //if (adc == NULL)
    //{
    //Display_printf(display, 0, 0, "Error initializing ADC0\n");
    //while (1);
    //}
    /* Blocking mode conversion */
    /* converting ADC 1*/
    //res = ADC_convert(adc1, &adcValue1);
    //if (res == ADC_STATUS_SUCCESS)
    //{
    //    adcValue2MicroVolt = ADC_convertRawToMicroVolts(adc1, adcValue1);
    //}
    //else
    //{
    //    Display_printf(hDisplaySerial, 0, 0, "ADC0 convert failed\n");
    //}
    //ADC_close(adc);

    //ADC_Params_init(&params);
    //adc = ADC_open( CC2640R2_LAUNCHXL_ADC1, &params);
    //adc1=adc_open(Board_ADC1, &params);
    //if (adc == NULL)
    //{
        //Display_printf(hDisplaySerial, 0, 0, "Error initializing ADC1\n");
    //while (1);
    //}

    /* Blocking mode conversion */
    /* converting ADC 2*/
    res = ADC_convert(adc2, &adcValue2);
    if (res == ADC_STATUS_SUCCESS) {
        adcValue2MicroVolt = ADC_convertRawToMicroVolts(adc2, adcValue2);
    }
    else {
        Display_printf(hDisplaySerial, 0, 0, "ADC0 convert failed\n");
    }

    //ADC_close(adc);

    //ADC_Params_init(&params);
    //adc = ADC_open( CC2640R2_LAUNCHXL_ADC2, &params);
    //adc1=adc_open(Board_ADC1, &params);
    //if (adc == NULL)
    //{
        //Display_printf(hDisplaySerial, 0, 0, "Error initializing ADC1\n");
        //while (1);
    //}

    /* Blocking mode conversion */
    /* converting ADC 3*/
    //res = ADC_convert(adc3, &adcValue3);
    //if (res == ADC_STATUS_SUCCESS)
    //{
    //    adcValue2MicroVolt = ADC_convertRawToMicroVolts(adc3, adcValue3);
    //}
    //else
    //{
    //    Display_printf(hDisplaySerial, 0, 0, "ADC0 convert failed\n");
    //}

    //ADC_close(adc);

    //ADC_Params_init(&params);
    //adc = ADC_open( CC2640R2_LAUNCHXL_ADC3, &params);
    //adc1=adc_open(Board_ADC1, &params);
    //if (adc == NULL)
    //{ Display_printf(hDisplaySerial, 0, 0, "Error initializing ADC1\n");
    //while (1);
    //}

    /* Blocking mode conversion */
    /* converting ADC 4*/
    //res = ADC_convert(adc4, &adcValue4);
    //
    //if (res == ADC_STATUS_SUCCESS)
    //{
    //    adcValue2MicroVolt = ADC_convertRawToMicroVolts(adc4, adcValue4);
    //}
    //else
    //{
    //    Display_printf(hDisplaySerial, 0, 0, "ADC0 convert failed\n");
    //    }

    //ADC_close(adc);

    //ADC_Params_init(&params);
    //adc = ADC_open( CC2640R2_LAUNCHXL_ADC4, &params);
    //adc1=adc_open(Board_ADC1, &params);
    //if (adc == NULL)
    //{ Display_printf(hDisplaySerial, 0, 0, "Error initializing ADC1\n");
    //while (1);
    //}

    /* Blocking mode conversion */
    /* converting ADC 5*/
    //res = ADC_convert(adc5, &adcValue5); // converting
    //if (res == ADC_STATUS_SUCCESS)
    //{ adcValue2MicroVolt = ADC_convertRawToMicroVolts(adc5, adcValue5);
    //}
    //else
    //{ Display_printf(hDisplaySerial, 0, 0, "ADC0 convert failed\n");
    //}

    //ADC_close(adc); // turn off ADC

    latestAdcValue[9]=adcValue2;
    Display_printf(hDisplaySerial, 0, 0, "%d analog\n", latestAdcValue[9]);

    /* Post event */
    //Event_post(nodeEventHandle, NODE_EVENT_NEW_ADC_VALUE);

}

void tmr_callback(UArg arg0) {
    //place a message in the queue
    MsgObj msg;
    msg.id = 1;
    msg.val = 1;
    timer_val++;
    Mailbox_post(my_mailbox,&msg,BIOS_NO_WAIT);
}
//////////Clock_getTicks

/* === I2C Transaction Constants === */
#define I2C_MAX_WRITE               0x04
#define I2C_MAX_READ                0x07

/*  ======== TMP Registers ======== */
#define TMP117_ADDR_GND_TEMPSENSOR  0x48
#define TMP117_RESULT_REG           0x00

/* =========BMA400 Registers and values ==========*/
#define BMA400_ADDR_ACCELEROMETER   0x14
#define BMA400_CHIP_ID              0x00
#define BMA400_CHECK_STATUS         0x03
#define BMA400_ACC_CONFIG           0x19
#define BMA400_RESULT_REG_START     0x04
#define BMA400_ACC_CONFIG1          0x1A

#define VALUE_INTO_ACC_CONFIG       0x02

/* =========BMG250 Registers and values ==========*/
#define BMG250_ADDR_GYRO            0x68
#define BMG250_CHIP_ID              0x00
#define BMG250_CHECK_STATUS         0x03
#define BMG250_GYRO_CONFIG          0x0042 // range
#define BMG250_RESULT_REG_START     0x0012
#define BMG250_GYRO_CONFIG1         0x0043 // odr

#define VALUE_INTO_GYRO_CONFIG      0x02

/* =========BMI270 Registers and values ==========*/
#define BMI270_ADDR_GYRO            0x68
#define BMI270_CHIP_ID              0x00
#define BMI270_CHIP_ID_CHECK        0x24
#define BMI270_PWR_CONFIG           0x7D
#define BMI270_NOR_PWR              0x0E
#define BMI270_CHECK_STATUS         0x03
#define BMI270_GYRO_CONFIG          0x0042 // range
#define BMI270_RESULT_REG_START     0x0012
#define BMI270_GYRO_CONFIG1         0x0043 // odr

#define VALUE_INTO_BMI270_GYRO_CONFIG      0x02

typedef enum{sitting,
standing} position;


uint8_t txBuffer[I2C_MAX_WRITE];
uint8_t rxBuffer[I2C_MAX_READ];
I2C_Handle i2c;
I2C_Params i2cParams;
I2C_Transaction i2cTransaction;


void *mainThread(void *arg0) {

    uint16_t rawAcc_x, rawAcc_y, rawAcc_z;
    uint16_t datacounter=0;
    int realAcc_x, realAcc_y, realAcc_z;
    float initialOffset_x, initialOffset_y, initialOffset_z;
    static int sampleCount = 0;

    //Acceleration Array and Values
    float acceleration_x, acceleration_y, acceleration_z, acceleration_magnitude;
    float acceleration_x_arr[4] = {0.0, 0.0, 0.0, 0.0};
    float acceleration_y_arr[4] = {0.0, 0.0, 0.0, 0.0};
    float acceleration_z_arr[4] = {0.0, 0.0, 0.0, 0.0};
    float acceleration_magnitude_arr[4] = {0.0, 0.0, 0.0, 0.0};

    //Gyroscope Array and Values
    float gyro_x, gyro_y, gyro_z, gyro_magnitude;
    float gyro_x_arr[4] = {0.0, 0.0, 0.0, 0.0};
    float gyro_y_arr[4] = {0.0, 0.0, 0.0, 0.0};
    float gyro_z_arr[4] = {0.0, 0.0, 0.0, 0.0};
    float gyro_magnitude_arr[4] = {0.0, 0.0, 0.0, 0.0};

    //Feature_Extraction* feature_extraction;
    //feature_extraction->input_arr_size = 4;

    Feature_Extraction feature_extraction_instance;
    Feature_Extraction *feature_extraction = &feature_extraction_instance;
    feature_extraction->input_arr_size = 4;

    uint8_t status;
    uint8_t arrayPtr = 0;


    uint8_t increment = 0;
    position piggy = sitting;
    time_t curTime = 0;
    char *curTimeStr = "Www Mmm dd hh:mm:ss yyyy\n";

    /* Call driver init functions */
    GPIO_init();
    I2C_init();

    /* Configure the LED and if applicable, the TMP116_EN pin */
    GPIO_setConfig(Board_GPIO_LED0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    #ifdef Board_GPIO_TMP116_EN
        GPIO_setConfig(Board_GPIO_TMP116_EN, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_HIGH); /////////////////////
        /* 1.5 ms reset time for the TMP116 */
        sleep(1);
    #endif

    /* Turn on user LED */
    GPIO_write(Board_GPIO_LED0, Board_GPIO_LED_ON);
    Display_printf(hDisplaySerial, 0, 0, "Starting the temperature sensor.");

    /* Create I2C for usage */
    I2C_Params_init(&i2cParams);
    i2cParams.bitRate = I2C_400kHz;
    i2c = I2C_open(Board_I2C_TMP, &i2cParams);

    if (i2c == NULL) {
        Display_printf(hDisplaySerial, 0, 0, "Error Initializing I2C\n");
    }
    else {
        Display_printf(hDisplaySerial, 0, 0, "I2C Initialized!\n");
    }

    /* Common Setup */
    i2cTransaction.writeBuf = txBuffer;
    i2cTransaction.readBuf = rxBuffer;

    /* I2C setup for BMA400 */
    i2cTransaction.slaveAddress = BMA400_ADDR_ACCELEROMETER; // determine the slave address

    /*  Accelerometer Checks  */
    /* Check if the accelerometer is connected */
    i2cTransaction.writeCount = 1;
    i2cTransaction.readCount = 1;
    txBuffer[0] = BMA400_CHIP_ID;
    if (I2C_transfer( i2c, &i2cTransaction) && i2cTransaction.slaveAddress == BMA400_ADDR_ACCELEROMETER) {
        if (rxBuffer[0] == 0x90) {
            Display_printf(hDisplaySerial, 0, 0, "BMA400 Accelerometer Communication OK");
        }
        else {
            Display_printf(hDisplaySerial, 0, 0, "BMA400 Accelerometer Communication Not OK");
        }
    }
    else {
        Display_printf(hDisplaySerial, 0, 0, "Error. No Accelerometer sensor found!");
    }

    /* Change the mode from sleep mode to normal mode by writing into registers */
    i2cTransaction.writeCount = 2;
    i2cTransaction.readCount = 1;
    txBuffer[0] = BMA400_ACC_CONFIG;
    txBuffer[1] = VALUE_INTO_ACC_CONFIG;
    if (I2C_transfer(i2c, &i2cTransaction)) {
        Display_printf(hDisplaySerial, 0, 0, "Normal Mode Configured");
    }

    /* Verify and check the mode of the accelerometer */
    i2cTransaction.writeCount = 1;
    i2cTransaction.readCount = 1;
    txBuffer[0] = BMA400_CHECK_STATUS;
    if (I2C_transfer(i2c, &i2cTransaction) && i2cTransaction.slaveAddress == BMA400_ADDR_ACCELEROMETER) {
        status = (rxBuffer[0] >> 1) & 0x03;
        if (status == 2) {
            Display_printf(hDisplaySerial, 0, 0, "Normal Mode");
        }
        else if (status == 1) {
            Display_printf(hDisplaySerial, 0, 0, "Low Power Mode");
        }
        else if (status == 0) {
            Display_printf(hDisplaySerial, 0, 0, "Sleep Mode");
        }
    }
    else {
        Display_printf(hDisplaySerial, 0, 0, "Error. Mode Undetermined");
    }

    /* Verify and check the range (acceleration)*/
    i2cTransaction.writeCount = 1;
    i2cTransaction.readCount = 1;
    txBuffer[0] = BMA400_ACC_CONFIG1;
    if (I2C_transfer(i2c, &i2cTransaction)) {
        uint8_t range;
        range = rxBuffer[0] >> 6;
        int b;
        int accrange = 1;
        for (b = 0; b <= range; b++) {
            accrange = accrange * 2;
        }

        Display_printf(hDisplaySerial, 0, 0, "ACC range: %d g", accrange);
    }


    /* I2C setup for BMG250 (Gyroscope)*/
    int8_t bmg250_i2c_read(uint8_t dev_id, uint8_t reg_addr, uint8_t *data, uint16_t len);
    int8_t bmg250_i2c_write(uint8_t dev_id, uint8_t reg_addr, uint8_t *data, uint16_t len);
    void bmg250_i2c_delay_ms(uint32_t period);

    i2cTransaction.slaveAddress = BMG250_ADDR_GYRO; // determine the slave address

    /* Check if the gyroscope is connected */
    i2cTransaction.writeCount = 1;
    i2cTransaction.readCount = 1;
    txBuffer[0] = BMG250_CHIP_ID;
    if (I2C_transfer(i2c, &i2cTransaction) && i2cTransaction.slaveAddress == BMG250_ADDR_GYRO) {
        if (rxBuffer[0] == 0xD5) {
            Display_printf(hDisplaySerial, 0, 0, "BMG250 Gyroscope Communication OK");
        }
        else {
            Display_printf(hDisplaySerial, 0, 0, "BMG250 Communication Not OK");
        }
    }
    else {
        Display_printf(hDisplaySerial, 0, 0, "Error. No Gyroscope sensor found!");
    }

    /* Change the mode from sleep mode to normal mode by writing into registers */

    struct bmg250_dev  bmg250;
    struct bmg250_cfg  bmg250cfg;
    struct bmg250_sensor_data bmg250data;
    bmg250.intf = BMG250_I2C_INTF;
    bmg250.dev_id=0x68;
    bmg250.chip_id=0xD5;
    bmg250.power_mode=0x15;
    bmg250.read=bmg250_i2c_read;
    bmg250.write=bmg250_i2c_write;
    bmg250.delay_ms=bmg250_i2c_delay_ms;


    uint8_t x = bmg250_init(&bmg250);
    uint8_t y = bmg250_set_power_mode(&bmg250);
    uint8_t z = bmg250_get_regs(0x03, rxBuffer, 1, &bmg250);
    if(z==0) {
        status=rxBuffer[0]>>2 & 0x03;
        if (status == 3) {
           Display_printf(hDisplaySerial, 0, 0, "Fast Start Up");
        }
        else if (status == 2) {
            Display_printf(hDisplaySerial, 0, 0, "Reserved");
        }
        else if (status == 1) {
            Display_printf(hDisplaySerial, 0, 0, "Normal Mode");
        }
        else if (status == 0) {
            Display_printf(hDisplaySerial, 0, 0, "Suspend Mode");
        }
    }

    bmg250cfg.odr=BMG250_ODR_100HZ;
    bmg250cfg.bw=BMG250_BW_NORMAL_MODE;
    bmg250cfg.range=BMG250_RANGE_500_DPS;

    z = bmg250_set_sensor_settings(&bmg250cfg, &bmg250);
    z = bmg250_get_sensor_settings(&bmg250cfg, &bmg250);

    /* Verify and check the mode of the gyroscope */
    i2cTransaction.writeCount = 1;
    i2cTransaction.readCount = 1;
    txBuffer[0] = BMG250_CHECK_STATUS;
    if (I2C_transfer(i2c, &i2cTransaction) && i2cTransaction.slaveAddress == BMG250_ADDR_GYRO) {
        int a;
        a = rxBuffer[0];
        status = (rxBuffer[0] >> 2) & 0x03;
        if (status == 2) {
            Display_printf(hDisplaySerial, 0, 0, "Normal Mode");
        }
        else if (status == 1) {
            Display_printf(hDisplaySerial, 0, 0, "Low Power Mode");
        }
        else if (status == 0) {
            Display_printf(hDisplaySerial, 0, 0, "Sleep Mode");
        }
    }
    else {
        Display_printf(hDisplaySerial, 0, 0, "Error. Mode Undetermined");
    }

    /* Verify and check the range (gyroscope)*/
    i2cTransaction.writeCount = 1;
    i2cTransaction.readCount = 1;
    txBuffer[0] = BMG250_GYRO_CONFIG1;
    if (I2C_transfer(i2c, &i2cTransaction)) {
        uint8_t gyrorange;
        gyrorange = rxBuffer[0] >> 6;
        int gyrob;
        int gyroaccrange = 1;
        for (gyrob = 0; gyrob <= gyrorange; gyrob++) {
            gyroaccrange = gyroaccrange * 2;
        }

        Display_printf(hDisplaySerial, 0, 0, "ayroACC range: %d g", gyroaccrange);
    }

    /* I2C setup for BMI270 */
    i2cTransaction.slaveAddress = BMI270_ADDR_GYRO; // determine the slave address
    /* Check if the gyroscope is connected */
    i2cTransaction.writeCount = 1;
    i2cTransaction.readCount = 1;
    txBuffer[0] = BMI270_CHIP_ID;
    if (I2C_transfer(i2c, &i2cTransaction) && i2cTransaction.slaveAddress == BMI270_ADDR_GYRO) {
        if (rxBuffer[0] == 0x24) {
            Display_printf(hDisplaySerial, 0, 0, "BMI270 Gyroscope Communication OK");
        }
        else {
            Display_printf(hDisplaySerial, 0, 0, "BMI270 Gyroscope Communication Not OK");
        }
    }
    else {
        Display_printf(hDisplaySerial, 0, 0, "Error. No ACC / Gyroscope sensor found!");
    }

    /* Change the mode from sleep mode to normal mode by writing into registers */
    i2cTransaction.writeCount = 2;
    i2cTransaction.readCount = 1;
    txBuffer[0] = 0x7D;
    txBuffer[1] = 0x0E;
    if (I2C_transfer(i2c, &i2cTransaction)) {
        Display_printf(hDisplaySerial, 0, 0, "Normal Mode Configured");
    }

    i2cTransaction.writeCount = 2;
    i2cTransaction.readCount = 1;
    txBuffer[0] = 0x7C;
    txBuffer[1] = 0x00;
    if (I2C_transfer(i2c, &i2cTransaction)) {
        Display_printf(hDisplaySerial, 0, 0, "Power Saved");
    }

    i2cTransaction.writeCount = 2;
    i2cTransaction.readCount = 1;
    txBuffer[0] = 0x59;
    txBuffer[1] = 0x00;
    if (I2C_transfer(i2c, &i2cTransaction)) {
        Display_printf(hDisplaySerial, 0, 0, "Prepare loading");
    }

    i2cTransaction.writeCount = 1;
    i2cTransaction.readCount = 7;
    txBuffer[0] = 0x5E;
    if (I2C_transfer(i2c, &i2cTransaction) && i2cTransaction.slaveAddress == BMI270_ADDR_GYRO) {   
        int a[8];
        a[0]=rxBuffer[0];
        a[1]=rxBuffer[1];
        a[2]=rxBuffer[2];
        a[3]=rxBuffer[3];
    }

    i2cTransaction.writeCount = 2;
    i2cTransaction.readCount = 1;
    txBuffer[0] = 0x59;
    txBuffer[1] = 0x01;
    if (I2C_transfer(i2c, &i2cTransaction)) {
        Display_printf(hDisplaySerial, 0, 0, "Prepare loading");
    }

    i2cTransaction.writeCount = 1;
    i2cTransaction.readCount = 1;
    txBuffer[0] = 0x21;
    if (I2C_transfer(i2c, &i2cTransaction) && i2cTransaction.slaveAddress == BMI270_ADDR_GYRO) {
        int a[1];

        a[0] = rxBuffer[0];

        if ((rxBuffer[0] & 0x01) == 0)
            Display_printf(hDisplaySerial, 0, 0, "Initilization Success");
    }

    /* Verify and check the mode of the gyroscope */
    i2cTransaction.writeCount = 1;
    i2cTransaction.readCount = 1;
    txBuffer[0] = 0x7D;
    if (I2C_transfer(i2c, &i2cTransaction) && i2cTransaction.slaveAddress == BMI270_ADDR_GYRO) {
        int a;
        a = rxBuffer[0];
        status = (rxBuffer[0] >> 2) & 0x03;
        if (status == 2) {
            Display_printf(hDisplaySerial, 0, 0, "Normal Mode");
        }
        else if (status == 1) {
            Display_printf(hDisplaySerial, 0, 0, "Low Power Mode");
        }
        else if (status == 0) {
            Display_printf(hDisplaySerial, 0, 0, "Sleep Mode");
        }
    }
    else {
        Display_printf(hDisplaySerial, 0, 0, "Error. Mode Undetermined");
        //while(1);
    }

    /* Verify and check the range (gyroscope)*/
    i2cTransaction.writeCount = 1;
    i2cTransaction.readCount = 1;
    txBuffer[0] = BMG250_GYRO_CONFIG1;
    if (I2C_transfer(i2c, &i2cTransaction)) {
        uint8_t gyrorange;
        gyrorange = rxBuffer[0] >> 6;
        int gyrob;
        int gyroaccrange = 1;
        for (gyrob = 0; gyrob <= gyrorange; gyrob++) {
            gyroaccrange = gyroaccrange * 2;
        }

        Display_printf(hDisplaySerial, 0, 0, "ayroACC range: %d g", gyroaccrange);
    }

    //GPTimerCC26XX_Params params;
    //GPTimerCC26XX_Params_init(&params);
    //params.width          = GPT_CONFIG_32BIT;
    //params.mode           = GPT_MODE_PERIODIC_UP;
    //params.debugStallMode = GPTimerCC26XX_DEBUG_STALL_OFF;
    //hTimer = GPTimerCC26XX_open(Board_GPTIMER0A, &params);
    //if(hTimer == NULL) {
    //}
    //GPTimerCC26XX_Value loadVal = 4799999;
    //GPTimerCC26XX_setLoadValue(hTimer, loadVal);
    //GPTimerCC26XX_registerInterrupt(hTimer, timerCallback, GPT_INT_TIMEOUT);
    //GPTimerCC26XX_start(hTimer);

    /* Initialize all of the Analog to Digital converters */
    init_all_adc();


    /*Start of Infinite while loop. This while loop is where the Gyroscope and Acellerometer will continuously take in data and calculate the behavior of the pig*/
    while (1) {

        read_adc();

        /* I2C setup for TMP117 */
        i2cTransaction.slaveAddress = TMP117_ADDR_GND_TEMPSENSOR;
        i2cTransaction.writeCount = 1;
        i2cTransaction.readCount = 2;

        /* Test accelerometer connectivity */
        bool accelerometerConnected = false;

        i2cTransaction.slaveAddress = BMA400_ADDR_ACCELEROMETER;
        i2cTransaction.writeCount = 0;
        i2cTransaction.readCount = 1;

        if (I2C_transfer(i2c, &i2cTransaction)) {
            accelerometerConnected = true;
        }

        /* Read Accelerometer */
        i2cTransaction.writeCount = 1;
        i2cTransaction.readCount = 6;

        // CALIBRATION
        while ((sampleCount < 1024) && (accelerometerConnected)) {

            txBuffer[0] = BMA400_RESULT_REG_START;
            if (I2C_transfer(i2c, &i2cTransaction)) {

                rawAcc_x = (rxBuffer[1] << 8) | (rxBuffer[0]);
                rawAcc_y = (rxBuffer[3] << 8) | (rxBuffer[2]);
                rawAcc_z = (rxBuffer[5] << 8) | (rxBuffer[4]);
                latestAdcValue[1] = rawAcc_x;
                latestAdcValue[2] = rawAcc_y;
                latestAdcValue[3] = rawAcc_z;
                realAcc_x = (int) rawAcc_x;
                realAcc_y = (int) rawAcc_y;
                realAcc_z = (int) rawAcc_z;
                if ((int) rawAcc_x > 2047) {
                    realAcc_x = (int) rawAcc_x - 4096;
                }
                if ((int) rawAcc_y > 2047) {
                    realAcc_y = (int) rawAcc_y - 4096;
                }
                if ((int) rawAcc_z > 2047) {
                    realAcc_z = (int) rawAcc_z - 4096;
                }
                //Why this number? --> 0.019178
                initialOffset_x += realAcc_x * 0.019178;
                Display_printf(hDisplaySerial, 0, 0, "offsetx: %f f", initialOffset_x);
                initialOffset_y += realAcc_y * 0.019178;
                initialOffset_z += realAcc_z * 0.019178;
                sampleCount++;
            }
            else {
                accelerometerConnected = false;
            }

            if (sampleCount == 1024) {
                //Divide values by 1024 (samples) to get average
                initialOffset_x = initialOffset_x / 1024.0;
                initialOffset_y = initialOffset_y / 1024.0;
                initialOffset_z = initialOffset_z / 1024.0;
                sampleCount++;
            }

        }

        //END OF CALIBRATION

        txBuffer[0] = BMA400_RESULT_REG_START;
        if (I2C_transfer(i2c, &i2cTransaction)) {
            rawAcc_x = (rxBuffer[1] << 8) | (rxBuffer[0]);
            rawAcc_y = (rxBuffer[3] << 8) | (rxBuffer[2]);
            rawAcc_z = (rxBuffer[5] << 8) | (rxBuffer[4]);
            latestAdcValue[1] = rawAcc_x;
            latestAdcValue[2] = rawAcc_y;
            latestAdcValue[3] = rawAcc_z;
            realAcc_x = (int) rawAcc_x;
            realAcc_y = (int) rawAcc_y;
            realAcc_z = (int) rawAcc_z;
            if ((int) rawAcc_x > 2047) {
                realAcc_x = (int) rawAcc_x - 4096;
            }
            if ((int) rawAcc_y > 2047) {
                realAcc_y = (int) rawAcc_y - 4096;
            }
            if ((int) rawAcc_z > 2047) {
                realAcc_z = (int) rawAcc_z - 4096;
            }
            
            int i;
            //Acceleration Values
            //Steps: 
            //      1.) Find the desired acceleration value (Ex: acceleraton_x)
            //      2.) Populate the corresponding field in the Feature Extraction Array with the acceleration value
            //      3.) Add the acceleration value to the coresponding array and pop the oldest value
            //      4.) Set the acceleration array to the input array of the feature extraction struct and find all corresponing acceleration features using the extract_time_domain_features function

            //Acceleration X
            acceleration_x = (realAcc_x) * 0.019178;                    
            feature_extraction->accel_x.acc_x = acceleration_x;
            for (i = 1; i < 3; i ++) {
                acceleration_x_arr[i + 1] = acceleration_x_arr[i];
            }  
            acceleration_x_arr[0] = acceleration_x;
            for (i = 0; i < 4; i ++) {
                feature_extraction->input_arr[i] = acceleration_x_arr[i];
            }
            extract_time_domain_features(feature_extraction, ACC_X);
            Display_printf(hDisplaySerial, 0, 0, "Accelerometer Euclidian: %f ", feature_extraction->accel_x.acc_x_euclidian_norm);

            //Acceleration Y
            acceleration_y = (realAcc_y) * 0.019178;
            feature_extraction->accel_y.acc_y = acceleration_y;
            for (i = 1; i < 3; i ++) {
                acceleration_y_arr[i + 1] = acceleration_y_arr[i]; 
            }  
            acceleration_y_arr[0] = acceleration_y;
            for (i = 0; i < 4; i ++) {
                feature_extraction->input_arr[i] = acceleration_y_arr[i];
            }
            extract_time_domain_features(feature_extraction, ACC_Y);

            //Acceleration Z
            acceleration_z = (realAcc_z) * 0.019178;
            feature_extraction->accel_z.acc_z = acceleration_z;
            for (i = 1; i < 3; i ++) {
                acceleration_z_arr[i + 1] = acceleration_z_arr[i]; 
            }  
            acceleration_z_arr[0] = acceleration_z;
            for (i = 0; i < 4; i ++) {
                feature_extraction->input_arr[i] = acceleration_z_arr[i];
            }
            extract_time_domain_features(feature_extraction, ACC_Z);

            //Acceleration Magnitude
            acceleration_magnitude = sqrtf((acceleration_x * acceleration_x) + (acceleration_y * acceleration_y) + (acceleration_z * acceleration_y));
            feature_extraction->accel_mag.acc_magnitude = acceleration_magnitude;
            for (i = 1; i < 3; i ++) {
                acceleration_magnitude_arr[i + 1] = acceleration_magnitude_arr[i]; 
            }  
            acceleration_magnitude_arr[0] = acceleration_magnitude;
            for (i = 0; i < 4; i ++) {
                feature_extraction->input_arr[i] = acceleration_magnitude_arr[i];
            }
            extract_time_domain_features(feature_extraction, ACC_MAG);
        }
        else {
            Display_printf(hDisplaySerial, 0, 0, "I2C Bus fault. No Acc Data Read.");
        }
        /* Get the time and calculate the current time segment */

        //////////////////////////////////////////////////////////////////////////////////bma400
        //???

        if (acceleration_z > 11) {
            piggy = sitting;
        }
        else if (acceleration_z < 9) {
            piggy = standing;
        }

        if (piggy == standing) {
            //Display_printf(hDisplaySerial, 0, 0, "This pig is most likely standing/moving\n");
        }
        else {
            //Display_printf(hDisplaySerial, 0, 0, "This pig is most likely sitting/sleeping\n");
        }


        /* Read Gyroscope */
        bool gyroConnected = false;

        i2cTransaction.slaveAddress = BMG250_ADDR_GYRO;
        i2cTransaction.writeCount = 0;
        i2cTransaction.readCount = 1;

        if (I2C_transfer(i2c, &i2cTransaction)) {
            gyroConnected = true;
        }
        if(!gyroConnected) {
            //while(1)
            /* Error GyroScope didn't connect */
        }

        //int32_t temperature_bmg250;


        z=bmg250_get_sensor_data(BMG250_DATA_SEL,&bmg250data,&bmg250);
        bmg250.delay_ms(45);
        bmg250data.sensortime=0;// will delete later
        
        //Gyroscope Values
        //Steps: 
        //      1.) Find the desired gyroscope value (Ex: gyro_x)
        //      2.) Populate the corresponding field in the Feature Extraction Array with the gyroscope value
        //      3.) Add the gyroscope value to the coresponding array and pop the oldest value
        //      4.) Set the gyroscope array to the input array of the feature extraction struct and find all corresponing gyroscope features using the extract_time_domain_features function
        int i;

        //Gyroscope X
        bmg250data.x = gyro_x;
        feature_extraction->gyro_x.gyro_x = gyro_x;
        for (i = 1; i < 3; i ++) {
            gyro_x_arr[i + 1] = gyro_x_arr[i];
        }  
        gyro_x_arr[0] = gyro_x;
        for (i = 0; i < 4; i ++) {
            feature_extraction->input_arr[i] = gyro_x_arr[i];
        }
        extract_time_domain_features(feature_extraction, GYRO_X);

        //Gyroscope Y
        bmg250data.y = gyro_y;
        feature_extraction->gyro_y.gyro_y = gyro_y;
        for (i = 1; i < 3; i ++) {
            gyro_y_arr[i + 1] = gyro_y_arr[i];
        }  
        gyro_y_arr[0] = gyro_y;
        for (i = 0; i < 4; i ++) {
            feature_extraction->input_arr[i] = gyro_y_arr[i];
        }
        extract_time_domain_features(feature_extraction, GYRO_Y);

        //Gyroscope Z
        bmg250data.y = gyro_z;
        feature_extraction->gyro_z.gyro_z = gyro_z;
        for (i = 1; i < 3; i ++) {
            gyro_z_arr[i + 1] = gyro_z_arr[i];
        }  
        gyro_z_arr[0] = gyro_z;
        for (i = 0; i < 4; i ++) {
            feature_extraction->input_arr[i] = gyro_z_arr[i];
        }
        extract_time_domain_features(feature_extraction, GYRO_Z);

        //Gyroscope Magnitude
        gyro_magnitude = sqrtf((gyro_x * gyro_x) + (gyro_y * gyro_y) + (gyro_z * gyro_z));
        feature_extraction->gyro_mag.gyro_magnitude = gyro_magnitude;
        for (i = 1; i < 3; i ++) {
            gyro_magnitude_arr[i + 1] = gyro_magnitude_arr[i];
        }  
        gyro_magnitude_arr[0] = gyro_magnitude;
        for (i = 0; i < 4; i ++) {
            feature_extraction->input_arr[i] = gyro_magnitude_arr[i];
        }
        extract_time_domain_features(feature_extraction, GYRO_MAG);

        Display_printf(hDisplaySerial, 0, 0, "BMG250_GYRO_data  X: %d \t Y: %d \t Z: %d \t Sensor-time : %lu\n", (bmg250data.x), (bmg250data.y), (bmg250data.z), (long long) bmg250data.sensortime);
        latestAdcValue[5] = bmg250data.x;
        latestAdcValue[6] = bmg250data.y;
        latestAdcValue[7] = bmg250data.z;

        uint32_t events = Event_pend(nodeEventHandle, 0, NODE_EVENT_ALL, BIOS_WAIT_FOREVER);

        while(!proceed) {
         //idle
         bmg250_i2c_delay_ms(1);
        }
        proceed = false;

        curTime = time(&curTime);

        old_time_ms = curr_time_ms;
        struct timespec tm;
        clock_settime(CLOCK_REALTIME, &tm);
        clock_gettime(CLOCK_REALTIME, &tm);

        curr_time_ms = (float) tm.tv_nsec / 1000000;

        if (curr_time_ms > old_time_ms)
            time_seg_ms = curr_time_ms - old_time_ms;
        else
            time_seg_ms = 1000 - old_time_ms + curr_time_ms;
        curTimeStr = ctime(&curTime);

        //Display_printf(hDisplaySerial, 0, 0, "Acceleration (m/s2): %f(X) %f(Y) %f(Z) Time: %lu(s)", (acceleration_x - initialOffset_x), (acceleration_y - initialOffset_y), (acceleration_z - initialOffset_z), (long long)curTime);
        Display_printf(hDisplaySerial, 0, 0, "Acceleration (m/s2): %f(X) %f(Y) %f(Z) Time: %lu(s) Time Segment: %f(ms)", (acceleration_x), (acceleration_y), (acceleration_z), (long long) curTime, (float) time_seg_ms);
            NodeRadioTask_sendAdcData(latestAdcValue); // send data from transmitter to receiver
            datacounter++;
            Display_printf(hDisplaySerial, 0, 0, "Counter: %u\n", datacounter);
            latestAdcValue[8]=datacounter;
            //Event_post(nodeEventHandle, NODE_EVENT_NEW_ADC_VALUE);

            //usleep(10000); //sleep for 1 seconds
    }

    I2C_close(i2c);
    close_all_adc();
    return (NULL);
}



int8_t bmg250_i2c_read(uint8_t dev_id, uint8_t reg_addr, uint8_t *data, uint16_t len)
{
    if ((data == NULL) || (len == 0) || (len > 32)) {
            return -1;
        }

        i2cTransaction.slaveAddress = BMG250_ADDR_GYRO;
        i2cTransaction.writeCount = 1;
        i2cTransaction.readCount = len;
        txBuffer[0] = reg_addr;

        if(!I2C_transfer(i2c, &i2cTransaction)) {
            return -1;
        }
        else {
            int i;
            for(i=0; i<len;i++)
            {
            data[i] = rxBuffer[i];

        }
         //   data=rxBuffer;
        }

        return 0;
}

int8_t bmg250_i2c_write(uint8_t dev_id, uint8_t reg_addr, uint8_t *data, uint16_t len)
{

    if ((data == NULL) || (len == 0) || (len > 32)) {
           return -1;
       }

       i2cTransaction.slaveAddress = BMG250_ADDR_GYRO;
       i2cTransaction.writeCount = len + 1;
       i2cTransaction.readCount = 0;
       txBuffer[0] = reg_addr;

       int i;
       for (i = 0; i < len; i++) {
           txBuffer[i+1] = data[i];
       }

       if(!I2C_transfer(i2c, &i2cTransaction)) {
           return -1;
       }

       return 0;

}

void bmg250_i2c_delay_ms(uint32_t period)
{
    usleep(period*1000);
}

