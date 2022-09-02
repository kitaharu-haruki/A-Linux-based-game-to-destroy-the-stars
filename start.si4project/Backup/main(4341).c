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
	lcd_init();
	ts_init();


	creat_rand_color(0,0);
	int m = 0;
	int n = 0;
	

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
					printf("game over!\n");
					for(int i = 0;i < 4;i++)
						{
							draw_word(print[i],200,500 + i * 48, 40,175,0x00FF0000);
						}
					
					break;  
				}
		}
		
	ts_uninit();
	lcd_uninit();

}
