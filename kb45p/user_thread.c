#include "ch.h"
#include "hal.h"

#include "bootloader.h"

static THD_WORKING_AREA(waButtonThread, 32);
static THD_FUNCTION(buttonThread, arg) {
  (void)arg;
  chRegSetThreadName("bootloadButton");

  while(true) {
    if(palReadPad(GPIOB, GPIOB_BUTTON) == PAL_HIGH) {
      // bootloader_jump();
      /* Do not do bootloader_jump: on STM32F042 jumping from user
       * code does not work.
       * Will rely on the fact that the button is also BOOT0 button,
       * and it will still be pressed after reset, so we enter
       * the bootloader because of this.
       * Ergo, just request a reset.
       */
      NVIC_SystemReset();
    }
    chThdSleepMilliseconds(500);
  }
}

void early_init_hook(void) {
  chThdCreateStatic(waButtonThread, sizeof(waButtonThread), LOWPRIO, buttonThread, NULL);
}

void bootloader_jump(void) {
	palSetPadMode(GPIOB, GPIOB_BUTTON, PAL_MODE_OUTPUT_PUSHPULL);
	palSetPad(GPIOB, GPIOB_BUTTON);
	chThdSleepMilliseconds(10);
	NVIC_SystemReset();
}