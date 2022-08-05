#include <stdio.h>
#include <math.h>
#include <time.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

int main() {
  stdio_init_all();
  adc_init();
  adc_gpio_init(28);
  adc_select_input(2);

  float T0 = 298;
  float Rt0 = 10000;
  float beta = 3977;
  float Vd = 3.3 / (4095);
  float adcread = 0;

  while (1) {
    float val = adc_read();
    float Vd = 3.3 / 4095;
    float adcval = Vd * val;
    float Rt = 10000 / ((3.3/adcval)-1);
    float temperatura = beta / (log(Rt/Rt0)+(beta/T0));
    float tempcelcius = temperatura - 273.15;
    printf ("La temperatura es: %.2f grados celius \n", tempcelcius);
    sleep_ms(2000);
  }

}
