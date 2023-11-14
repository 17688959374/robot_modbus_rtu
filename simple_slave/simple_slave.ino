/**
 *  Modbus slave example 1:
 *  The purpose of this example is to link a data array
 *  from the Arduino to an external device.
 *
 *  Recommended Modbus Master: QModbus
 *  http://qmodbus.sourceforge.net/
 */

#include <ModbusRtu.h>

// data array for modbus network sharing
uint16_t au16data[2] = {
  3,1 };
  

/**
 *  Modbus object declaration
 *  u8id : node id = 0 for master, = 1..247 for slave
 *  port : serial port
 *  u8txenpin : 0 for RS-232 and USB-FTDI 
 *               or any pin number > 1 for RS-485
 */
Modbus slave; // this is slave @1 and RS-232 or USB-FTDI

void setup() {
//set up the slave, 1 is ID and second 1 is RS485model,4 means the enable pin of max485
 slave=Modbus(1,1,4);
//start the slave and set baud rate
 slave.begin(9600);

}

void loop() {
  slave.poll( au16data, 2 );
  //begin the communication,1 is the length of the array
}
