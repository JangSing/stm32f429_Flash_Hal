#ifndef	__Register_H__
#define	__Register_H__

#include <stdint.h>

#include "Host.h"
#define RCC_BASE_ADDRESS        ((uint32_t)HostRcc)

#define GPIOA_BASE_ADDRESS      ((uint32_t)HostGpioA)
#define GPIOB_BASE_ADDRESS      ((uint32_t)HostGpioB)
#define GPIOC_BASE_ADDRESS      ((uint32_t)HostGpioC)
#define GPIOE_BASE_ADDRESS      ((uint32_t)HostGpioE)
#define GPIOF_BASE_ADDRESS      ((uint32_t)HostGpioF)
#define GPIOG_BASE_ADDRESS      ((uint32_t)HostGpioG)



// #define GPIOA_BASE_ADDRESS      (&HostGpioA)
// #define GPIOB_BASE_ADDRESS      (0x40020400)
// #define GPIOC_BASE_ADDRESS      (0x40020800)
// #define GPIOD_BASE_ADDRESS      (0x40020C00)
// #define GPIOE_BASE_ADDRESS      (0x40021000)
// #define GPIOF_BASE_ADDRESS      (0x40021400)


#endif	//__Register_H__