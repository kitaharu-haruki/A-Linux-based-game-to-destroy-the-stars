#include<stdlib.h>
#include<time.h>
#include"rand_color.h"
#include"lcd.h"

int star[10][10] = {0};

int creat_rand_color(int x0,int y0)
{
	lcd_draw_block(0,0,800,480,0X00FFFFFF);
	int color[] = {0x00FF0000,0X0000FF00,0X00EEC900,0X009400D3,0X001E90FF};
	int i,j,r;
	srand(time(NULL));

	

	for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
				{
					r = rand()%5;
					star[i][j] = color[r];
				}
		}
	for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
				{
					lcd_draw_block(x0+i*48+2,y0+j*48+2,44,44,star[i][j]);
				}
		}
}
