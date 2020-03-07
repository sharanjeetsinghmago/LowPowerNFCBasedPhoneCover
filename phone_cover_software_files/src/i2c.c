#include "em_i2c.h"
#include "em_cmu.h"
#include "em_chip.h"
#include "em_gpio.h"
#include <stdbool.h>


#define I2C_ADDRESS 0xE2 // Update address

#define NFC_ADDR 0x55

void Init_I2C0(void)
{
	CMU_OscillatorEnable(cmuOsc_LFXO, true, true);      //Enable LXF0 clock oscillator

	CMU_ClockEnable(cmuClock_CORELE, true);                 //Enable clock to Low energy peripheral clock tree
	CMU_ClockEnable(cmuClock_HFPER, true);
	CMU_ClockEnable(cmuClock_I2C0, true);
	CMU_ClockEnable(cmuClock_GPIO, true);


	GPIO_PinModeSet(gpioPortD, 6, gpioModeWiredAndPullUp, 1);
	GPIO_PinModeSet(gpioPortD, 7, gpioModeWiredAndPullUp, 1);


	I2C0->ROUTE |= I2C_ROUTE_SDAPEN | I2C_ROUTE_SCLPEN | I2C_ROUTE_LOCATION_LOC1;
//	I2C0->ROUTE = (I2C0->ROUTE & (~_I2C_ROUTE_LOCATION_MASK)) | I2C_ROUTE_LOCATION_LOC1;


	I2C_Init_TypeDef i2cInit = I2C_INIT_DEFAULT;
	i2cInit.clhr = i2cClockHLRStandard;
	i2cInit.master = true;
	i2cInit.refFreq = 0;
	i2cInit.enable = false;
	i2cInit.freq = I2C_FREQ_STANDARD_MAX;



	I2C_Init(I2C0, &i2cInit);


	for(int i=0; i<9; i++)
	{
		GPIO_PinOutClear(gpioPortD, 6);
		GPIO_PinOutClear(gpioPortD, 7);
	}

	if(I2C0->STATE & I2C_STATE_BUSY)
	{
		I2C0->CMD = I2C_CMD_ABORT | I2C_CMD_CLEARPC | I2C_CMD_CLEARTX;
	}

	I2C_IntClear(I2C0,I2C0->IF);

	I2C_Enable(I2C0,true);
}

void writeByte_I2C0(uint8_t slave_addr, uint8_t data)
{
	I2C0->TXDATA = slave_addr << 1;

	I2C0->CMD = I2C_CMD_START;

	while((I2C0->IF & I2C_IF_ACK) == 0);

	I2C0->IFC |= I2C_IFC_ACK;


	I2C0->TXDATA = 0x01;

	while((I2C0->IF & I2C_IF_ACK) == 0);

	I2C0->IFC = I2C_IFC_ACK;


	I2C0->TXDATA = 0x03;

	 for(int i = 1; i < 1000000; i++)
	 {}

	while((I2C0->IF & I2C_IF_ACK) == 0);

	I2C0->IFC |= I2C_IFC_ACK;

/*	I2C0->TXDATA = 0x03;

	while((I2C0->IF & I2C_IF_ACK) == 0);

	I2C0->IFC |= I2C_IFC_ACK;*/


	I2C0->CMD = I2C_CMD_STOP;
}

//int main(void)
//{
//	CHIP_Init();
//
//	Init_I2C0();
//
//	writeByte_I2C0(NFC_ADDR, 0x01);
//
//	while(1)
//	{}
//
//}
