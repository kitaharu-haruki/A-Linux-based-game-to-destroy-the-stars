#include<stdio.h>
#include"lcd.h"
#include"show_bmp.h"
#include"ts.h"
#include"rand_color.h"
#include"BFS_DFS.h"
#include"move.h"


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

			int num = 0;
			my_DFS(m,n,num);
			num = 0;
			
			move_of_down();
			update();
		}
		
	ts_uninit();
	lcd_uninit();

}
