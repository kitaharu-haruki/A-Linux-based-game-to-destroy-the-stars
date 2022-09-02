#include<stdlib.h>
#include<time.h>
#include"lcd.h"

int creat_rand_color(void)
{
	int color[] = {0x00FF0000,0X0000FF00,0X00000000,0X00FF0080,0X00C0C0C0};
	int i,j;
	srand(time(NULL));

	for(i=0;i<480;i+=48)
		{
			for(j=0;j<480;j+=48)
				{
					int r = rand()%5;
					lcd_draw_block(i,j,48,48,color[r]);
				}
		}
}
