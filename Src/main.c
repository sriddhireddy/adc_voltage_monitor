#include "adc_driver.h"
#include "uart_driver.h"
#include "systick_driver.h"

#define ADC_VREF			(3.3f)
#define ADC_MAX_VALUE		(4095.0f)

int main(void)
{
	uint32_t analogValue;
	uint32_t millivolts;

	UART_Init();
	ADC_Init();

    UART_WriteString("Voltage Monitor Started\r\n");

    while(1){
    	analogValue = ADC_Read();

    	UART_WriteString("ADC Value: ");

    	UART_WriteUInt(analogValue);

    	UART_WriteString("\r\n");

    	UART_WriteString("Voltage: ");

    	millivolts = (analogValue * 3300U) / 4095U;

//    	uint32_t volts = millivolts / 1000;
//    	uint32_t milli = millivolts % 1000;

    	UART_WriteUInt(millivolts);
    	UART_WriteString(" mV");

    	UART_WriteString("\r\n\r\n");
    	for(volatile uint32_t i=0; i<1000000; i++){}

    }

}

