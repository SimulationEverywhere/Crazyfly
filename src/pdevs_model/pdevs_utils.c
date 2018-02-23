
#include <stdbool.h>
#include <led.h>

bool ledOn = false;


void time_loop() {
    int i, j;
    j = 0;
    while (j < 100) {
	i = 0;
	while (i < 100000) {
	    __asm__("");
	    i++;
	}
	j++;
    }
}

void setLed_1() {
    ledInit();

    ledSet(LED_RED_L,   0);
    ledSet(LED_RED_R,   0);
    ledSet(LED_BLUE_L,  0);
    ledSet(LED_GREEN_L, 0);
    ledSet(LED_GREEN_R, 1);

    /*time_loop();*/
}

void setLed_2() {
    ledInit();

    ledSet(LED_RED_L,   0);
    ledSet(LED_RED_R,   0);
    ledSet(LED_BLUE_L,  0);
    ledSet(LED_GREEN_L, 1);
    ledSet(LED_GREEN_R, 0);

    /*time_loop();*/
}

void setLed_3() {
    ledInit();

    ledSet(LED_RED_L,   0);
    ledSet(LED_RED_R,   0);
    ledSet(LED_BLUE_L,  0);
    ledSet(LED_GREEN_L, 1);
    ledSet(LED_GREEN_R, 1);

    time_loop();
}

void setLed_4() {
    ledInit();

    ledSet(LED_RED_L,   0);
    ledSet(LED_RED_R,   0);
    ledSet(LED_BLUE_L,  1);
    ledSet(LED_GREEN_L, 0);
    ledSet(LED_GREEN_R, 0);

    time_loop();
}

void setLed_5() {
    ledInit();

    ledSet(LED_RED_L,   0);
    ledSet(LED_RED_R,   0);
    ledSet(LED_BLUE_L,  1);
    ledSet(LED_GREEN_L, 0);
    ledSet(LED_GREEN_R, 1);

    time_loop();
}

void setLed_6() {
    ledInit();

    ledSet(LED_RED_L,   0);
    ledSet(LED_RED_R,   0);
    ledSet(LED_BLUE_L,  1);
    ledSet(LED_GREEN_L, 1);
    ledSet(LED_GREEN_R, 0);

    time_loop();
}

void setLed_7() {
    ledInit();

    ledSet(LED_RED_L,   0);
    ledSet(LED_RED_R,   0);
    ledSet(LED_BLUE_L,  1);
    ledSet(LED_GREEN_L, 1);
    ledSet(LED_GREEN_R, 1);

    time_loop();
}

void setLed_8() {
    ledInit();

    ledSet(LED_RED_L,   0);
    ledSet(LED_RED_R,   1);
    ledSet(LED_BLUE_L,  0);
    ledSet(LED_GREEN_L, 0);
    ledSet(LED_GREEN_R, 0);

    /*time_loop();*/
}

void setLed_9() {
    ledInit();

    ledSet(LED_RED_L,   0);
    ledSet(LED_RED_R,   1);
    ledSet(LED_BLUE_L,  0);
    ledSet(LED_GREEN_L, 0);
    ledSet(LED_GREEN_R, 1);

    time_loop();
}

void setLed_10() {
    ledInit();

    ledSet(LED_RED_L,   0);
    ledSet(LED_RED_R,   1);
    ledSet(LED_BLUE_L,  0);
    ledSet(LED_GREEN_L, 1);
    ledSet(LED_GREEN_R, 0);

    time_loop();
}

void setLed_11() {
    ledInit();

    ledSet(LED_RED_L,   0);
    ledSet(LED_RED_R,   1);
    ledSet(LED_BLUE_L,  0);
    ledSet(LED_GREEN_L, 1);
    ledSet(LED_GREEN_R, 1);

    time_loop();
}

void setLed_Police() {
    ledInit();

    int i = 0;
    int j = 0;

    ledSet(LED_RED_L,   0);
    ledSet(LED_RED_R,   0);
    ledSet(LED_BLUE_L,  1);
    ledSet(LED_GREEN_L, 0);
    ledSet(LED_GREEN_R, 0);

    while (j < 100) {
      if (i == 65000) {
    	i = 0;
    	j++;
      }
      i++;
    }

    i = 0; j = 0;

    ledSet(LED_RED_L,   1);
    ledSet(LED_BLUE_L,  0);

    while (j < 100) {
      if (i == 65000) {
    	i = 0;
    	j++;
      }
      i++;
    }

    i = 0; j = 0;

    ledSet(LED_RED_L,   0);
    ledSet(LED_BLUE_L,  1);

    while (j < 100) {
      if (i == 65000) {
    	i = 0;
    	j++;
      }
      i++;
    }

    i = 0; j = 0;

    ledSet(LED_RED_L,   1);
    ledSet(LED_BLUE_L,  0);

    while (j < 100) {
      if (i == 65000) {
    	i = 0;
    	j++;
      }
      i++;
    }

    ledSet(LED_RED_L,   0);
    ledSet(LED_BLUE_L,  0);

    while (j < 50) {
      if (i == 65000) {
    	i = 0;
    	j++;
      }
      i++;
    }

    ledSet(LED_RED_L,   1);
    ledSet(LED_BLUE_L,  1);

    while (j < 150) {
      if (i == 65000) {
    	i = 0;
    	j++;
      }
      i++;
    }
}

void setLed_Amb() {
    ledInit();

    int i = 0;
    int j = 0;

    ledSet(LED_RED_L,   0);
    ledSet(LED_RED_R,   1);
    ledSet(LED_BLUE_L,  0);
    ledSet(LED_GREEN_L, 0);
    ledSet(LED_GREEN_R, 0);

    while (j < 100) {
      if (i == 65000) {
    	i = 0;
    	j++;
      }
      i++;
    }

    i = 0; j = 0;

    ledSet(LED_RED_L,   1);
    ledSet(LED_RED_R,  0);

    while (j < 100) {
      if (i == 65000) {
    	i = 0;
    	j++;
      }
      i++;
    }

    i = 0; j = 0;

    ledSet(LED_RED_L,   0);
    ledSet(LED_RED_R,  1);

    while (j < 100) {
      if (i == 65000) {
    	i = 0;
    	j++;
      }
      i++;
    }

    i = 0; j = 0;

    ledSet(LED_RED_L,   1);
    ledSet(LED_RED_R,  0);

    while (j < 100) {
      if (i == 65000) {
    	i = 0;
    	j++;
      }
      i++;
    }

    setLed_3();
}

void setLed_Switch() {
	ledInit();

//    if((led_count%1000) == 0) {
//        ledOn = !ledOn;
//    }
//
//    led_count++;

	ledOn = !ledOn;

	if (ledOn) {
		ledSet(LED_BLUE_L, 1);
		ledSet(LED_RED_L, 1);
		ledSet(LED_RED_R, 0);
	} else {
		ledSet(LED_BLUE_L, 0);
		ledSet(LED_RED_L, 0);
		ledSet(LED_RED_R, 1);
	}
}

void setLed_ON() {
	ledSet(LED_BLUE_L, 1);
	ledSet(LED_RED_L, 1);
	ledSet(LED_RED_R, 0);
    ledSet(LED_GREEN_L, 0);
    ledSet(LED_GREEN_R, 0);

    int i = 0;
    int j = 0;

    while (j < 200) {
      if (i == 65000) {
    	i = 0;
    	j++;
      }
      i++;
    }

	ledSet(LED_BLUE_L, 0);
	ledSet(LED_RED_L, 0);
	ledSet(LED_RED_R, 0);
}
void setLed_OFF() {
	ledSet(LED_BLUE_L, 1);
	ledSet(LED_RED_L, 0);
	ledSet(LED_RED_R, 1);
    ledSet(LED_GREEN_L, 0);
    ledSet(LED_GREEN_R, 0);

    int i = 0;
    int j = 0;

    while (j < 200) {
      if (i == 65000) {
    	i = 0;
    	j++;
      }
      i++;
    }

	ledSet(LED_BLUE_L, 0);
	ledSet(LED_RED_L, 0);
	ledSet(LED_RED_R, 0);
}
