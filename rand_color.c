#include<stdlib.h>
#include<time.h>
#include"rand_color.h"
#include"lcd.h"

int star[10][10] = {0};
extern int score;
extern unsigned char number[10][116];

int creat_rand_color(int x0,int y0)
{
	lcd_draw_block(0,0,800,480,0X00FFFFFF);
	int color[] = {0x00FF0000,0X0000FF00,0X00EEC900,0X009400D3,0X001E90FF};//确定颜色
	int i,j,r;
	srand(time(NULL));//生成随机数函数
/*
	设置色块数目为10*10
*/
	for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
				{
					r = rand()%5;
					star[i][j] = color[r];
				}
		}
	/*
		设置随机颜色
	*/
	for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
				{
					lcd_draw_block(x0+i*48+2,y0+j*48+2,44,44,star[i][j]);
				}
		}
}

int print_score(int one,int ten,int hunderd,int thousand)
{
	lcd_draw_block(100,500+3*35,195,50,0x00FFFFFF);
	one = score%10;
	ten = (score/10)%10;
	hunderd = (score/100)%10;
	thousand = (score/1000)%10;
	draw_word(number[thousand],100,500 + 3 * 35, 32,116,0x00000000);	//输出数字
	draw_word(number[hunderd],100,500 + 4 * 35, 32,116,0x00000000);
	draw_word(number[ten],100,500 + 5 * 35, 32,116,0x00000000);
	draw_word(number[one],100,500 + 6 * 35, 32,116,0x00000000);
	
	return 1;
}
