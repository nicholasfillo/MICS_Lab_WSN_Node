#ifndef RADIOPROTOCOL_H_
#define RADIOPROTOCOL_H_

#include "stdint.h"
#include "easylink/EasyLink.h"

#define RADIO_CONCENTRATOR_ADDRESS     0x00

/*
 * Uncomment to change the modulation away from the default found in the 
 * EASYLINK_PARAM_CONFIG macro in easylink_config.h
 *
 * Valid values can be found in the EasyLink_PhyType enum in EasyLink.h
 */
//#define DEFINED_RADIO_EASYLINK_MODULATION     EasyLink_Phy_Custom

#define RADIO_PACKET_TYPE_ACK_PACKET             0
#define RADIO_PACKET_TYPE_ADC_SENSOR_PACKET      1
#define RADIO_PACKET_TYPE_DM_SENSOR_PACKET       2

struct PacketHeader {
    uint8_t sourceAddress;
    uint8_t packetType;
};

struct AdcSensorPacket {
    struct PacketHeader header;
    uint16_t adcValue;//// change this to array///////////////////////////////////////////////////  uint16_t adcValue[];
};

struct DualModeSensorPacket {
    struct PacketHeader header;
    uint16_t adcValue[9]; //change to array
    uint16_t batt;
    uint32_t time100MiliSec;
    uint8_t button;
    bool concLedToggle;
};

struct AckPacket {
    struct PacketHeader header;
};

#endif /* RADIOPROTOCOL_H_ */
