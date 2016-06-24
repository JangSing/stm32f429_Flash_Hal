#include <malloc.h>
#include "unity.h"
#include "RCC.h"
#include "Host.h"
#include "Gpio.h"


void setUp(void)
{
  HostRcc = malloc(sizeof(RCC_TypeDef));
  //GPIOA - GPIOK(11 GPIOs in total for STM32F429ZI
  HostGpioA=malloc(sizeof(0x400 *11 ));
  HostGpioB=HostGpioA + 0x400;
  HostGpioC=HostGpioB + 0x400;
  HostGpioD=HostGpioC + 0x400;
  HostGpioE=HostGpioD + 0x400;
  HostGpioF=HostGpioE + 0x400;
  HostGpioG=HostGpioF + 0x400;
}

void tearDown(void)
{
  free(HostRcc);
  free(HostGpioA);

  HostRcc=NULL;
  HostGpioA=NULL;
  HostGpioB=NULL;
  HostGpioC=NULL;
  HostGpioD=NULL;
  HostGpioE=NULL;
  HostGpioF=NULL;
  HostGpioG=NULL;
}

void test_module_generator_needs_to_be_implemented(void)
{
	RCC->RCC_AHB1ENR=0;
  RCC->RCC_AHB1RSTR=0xffffffff;
  
  gpioUnresetEnableClock(PORTB);
  TEST_ASSERT_EQUAL(0,(RCC->RCC_AHB1RSTR>>1)&1);
  TEST_ASSERT_EQUAL(1,(RCC->RCC_AHB1ENR>>1)&1);
  // TEST_ASSERT_EQUAL(0,(RCC->RCC_AHB1RSTR>>6)&1);
  // TEST_ASSERT_EQUAL(1,(RCC->RCC_AHB1ENR>>6)&1);
}
