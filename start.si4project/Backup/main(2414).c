#include<stdio.h>
#include"lcd.h"
#include"show_bmp.h"
#include"ts.h"
#include"rand_color.h"
#include"BFS_DFS.h"
#include"move.h"
#include"font.h"


int main()
{
	lcd_init();//打开开发板屏幕
	ts_init();//打开开发板触屏

	//初始化色块
	creat_rand_color(0,0);
	

	int m = 0;
	int n = 0;
	
/*
	实现色块消除、移动以及死局判断
*/
	while(1)
		{
			get_touch_with_point(&m,&n);

			my_DFS(m,n);
			
			int number = 9;
			while(number--)
				{
					move_of_down();
					
					update();
				}
			
			number = 9;
			while(number--)
				{
					move_of_left_or_right();
					update();
				}

			int ret = my_BFS();
			if(ret == 0)
				{
					for(int i = 0;i < 4;i++)
						{
							show_bmp("./touma.bmp");
							draw_word(print[i],350,500 + i * 48, 32,116,0x00FF0000);
						}
					for(int i = 4;i < 9;i++)
						{
							draw_word(print[i],400,550 + (i-4) * 48, 32,116,0x00FF0000);
						}
					printf("game over!\n");
					break;  
				}
		}
		
	ts_uninit();
	lcd_uninit();

}
