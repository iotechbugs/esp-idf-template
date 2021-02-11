
#include <stdio.h>
#include "esp_types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"

#include "OneButton.h"

#define PIN_INPUT 23


extern "C" {
void app_main(void);
}

void click()
{
  Serial.println("Clicked ONCE");
}

void doubleClick()
{
  Serial.println("Clicked TWICE");
}

void longPress(){
  Serial.println("Long PRESS detected");
}

void app_main() {
	initArduino();
	Serial.begin(115200);
	OneButton button(PIN_INPUT, true);
	button.setPressTicks(5000);
	button.attachClick(click);
	button.attachDoubleClick(doubleClick);
	button.attachLongPressStart(longPress);
	while(true){
		button.tick();
		delay(10);
	}
}