#include "Rcc.h"
#include "Gpio.h"

void DMA2UnresetEnableClock(){
	Rcc->RCC_AHB1RSTR &= ~ DMA2RST; 	//Reseting
	Rcc->RCC_AHB1ENR  &= ~DMA2EN;
	Rcc->RCC_AHB1ENR  |= DMA2EN;		//Enable Clock
}


void gpioUnresetEnableClock(GPIO* port){
	int valToShift = ((int)port - GPIOA_BASE_ADDRESS)/(0x400);

	Rcc->RCC_AHB1RSTR &= ~(1 << (valToShift));
	Rcc->RCC_AHB1ENR |= (1 << (valToShift));
}
