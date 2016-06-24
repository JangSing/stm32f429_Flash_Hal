
#include "stm32f4xx_hal_flash.h"
#include "stm32f4xx_hal_flash_ex.h"
#include "stm32f4xx.h"
#include <stdint.h>

#define ADDRESS_SECTOR_18 0x08140000
#define DATA_PROGRAM 	  2015

void flashEraseInit(FLASH_EraseInitTypeDef *eraseInit,
					uint32_t eraseType,
					uint32_t whichBank,
					uint32_t whichSector,
					uint32_t NumOfSector,
					uint32_t VolRange){

	eraseInit->TypeErase=eraseType;
	eraseInit->Banks=whichBank;
	eraseInit->Sector=whichSector;
	eraseInit->NbSectors=NumOfSector;
	eraseInit->VoltageRange=VolRange;
}

int main(void)
{
	HAL_StatusTypeDef status;
	FLASH_EraseInitTypeDef eraseInit;
	uint32_t sectorError;
	uint32_t *ptr=ADDRESS_SECTOR_18;
	uint32_t checkCR;
	int guard=0;
	while(1){
		status=HAL_FLASH_Unlock();
		//this guard function is to program the Flash
		if(guard){
			while(status==HAL_BUSY);
			status=HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, ADDRESS_SECTOR_18, DATA_PROGRAM);
			while(status==HAL_BUSY);
			guard=0;
		}
		//this guard function is to sector erase the Flash
		if(guard){
			flashEraseInit(&eraseInit,
							FLASH_TYPEERASE_SECTORS,
							0,
							FLASH_SECTOR_18,
							1,
							FLASH_VOLTAGE_RANGE_3);

			while(status==HAL_BUSY);
			HAL_FLASHEx_Erase(&eraseInit,&sectorError);
			while(status==HAL_BUSY);
			guard=0;
		}
		//this guard function is to Mass erase the Flash
		if(guard){
			flashEraseInit(&eraseInit,
							FLASH_TYPEERASE_MASSERASE,
							0,
							0,
							1,
							FLASH_VOLTAGE_RANGE_3);

			while(status==HAL_BUSY);
			HAL_FLASHEx_Erase(&eraseInit,&sectorError);
			while(status==HAL_BUSY);
			guard=0;
		}



		status=HAL_FLASH_Lock();

	}




}

