/* Simple LED task demo, using timed delays:
 *
 * The LED on PC13 is toggled in task1.
 */
#include "FreeRTOS.h"
#include "task.h"

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/cm3/systick.h>

extern void vApplicationStackOverflowHook(
	xTaskHandle *pxTask,
	signed portCHAR *pcTaskName);

void vApplicationStackOverflowHook(
  xTaskHandle *pxTask __attribute((unused)),
  signed portCHAR *pcTaskName __attribute((unused))) 
{
	for(;;);	// Loop forever here..
}

static void task1(void *args __attribute((unused))) 
{

	for (;;) {
		gpio_toggle(GPIOA,GPIO5);
		vTaskDelay(pdMS_TO_TICKS(500));
	}
}

int main(void) {

	/* set the system clock to 84MHZ*/
	rcc_clock_setup_pll(&rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_84MHZ]);

	/*set GPIO A5 as output (led on nucleo)*/
	rcc_periph_clock_enable(RCC_GPIOA);
	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO5);

	/* create a task*/
	xTaskCreate(task1,"LED",100,NULL,configMAX_PRIORITIES-1,NULL);

	/* start the scheduler*/
	vTaskStartScheduler();

	for (;;);
	return 0;
}

// End
