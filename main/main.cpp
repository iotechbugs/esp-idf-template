
#include <stdio.h>
#include "esp_types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"

// To enable CPP support
extern "C" {
void app_main(void);
}


// Main function or entry point
void app_main() {
	initArduino();
	Serial.begin(115200);
	while(true){
		// Similar arduino loop
		Serial.println("Test");
		delay(1000);
	}
}