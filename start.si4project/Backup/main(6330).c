#include <stdio.h>
#include "lcd.h"
#include "show_bmp.h"
#include "ts.h"
#include "zi.h"
int main(int argc,char *argv[])
{
	lcd_init();
	ts_init();
	int ret = get_touch_with_point();

	int i;
	for(i=0;i<5;i++)
	{
		draw_word(name[i], 50, 50+i*24, 24, 24*42/8, 0x00FF0000);
	}
	ts_uninit();
	lcd_uninit();

}
