#include <stdio.h>
#include "lcd.h"
#include "show_bmp.h"
#include "ts.h"
#include"rand_color.h"

int main()
{
	lcd_init();
	ts_init();


	creat_rand_color();

	get_touch_with_point();
	ts_uninit();
	lcd_uninit();

}
