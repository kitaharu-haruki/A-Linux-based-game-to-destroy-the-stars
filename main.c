#include<stdio.h>
#include"lcd.h"
#include"show_bmp.h"
#include"ts.h"
#include"rand_color.h"
#include"BFS_DFS.h"
#include"move.h"
#include"font.h"

extern int score;
int target = 0;

int main()
{
	lcd_init();//打开开发板屏幕
	ts_init();//打开开发板触屏

	show_bmp("./start.bmp");
	for(int i = 0;i < 5;i++)
		{
			draw_word(game[i],75,75 + i * 32, 32,224,0x00FFFFFF);	//输出 start：
		}
	game_start();				//点击start后开始游戏；

	
	int flag = 1;
	int difficulty = 150;
	while(flag == 1)
		{
						//初始化色块
			creat_rand_color(0,0);

			int i,j = 753;					//在触摸屏右上角画一个叉；
			for(i=2;i<46;i++)
				{
					lcd_draw_block(i,j,3,1,0x00FF0000);
					j++;
				}
			j--;
			for(i=2;i<46;i++)
				{
					lcd_draw_block(i,j,3,1,0x00FF0000);
					j--;
				}

			
			target += difficulty;
			difficulty += 15;
			for(int i = 0;i < 3;i++)
				{
					draw_word(print[i],50,500 + i * 35, 32,116,0x00000000);	//输出 目标：
				}
			int one = target%10;
			int ten = (target/10)%10;
			int hunderd = (target/100)%10;
			int thousand = (target/1000)%10;
			draw_word(number[thousand],50,500 + 3 * 35, 32,116,0x00000000);	//输出数字
			draw_word(number[hunderd],50,500 + 4 * 35, 32,116,0x00000000);
			draw_word(number[ten ],50,500 + 5 * 35, 32,116,0x00000000);
			draw_word(number[one],50,500 + 6 * 35, 32,116,0x00000000);
			
			for(int i = 3;i < 6;i++)
				{
					draw_word(print[i],100,500 + (i-3)* 35, 32,116,0x00000000);	//输出 目标：
				}

			
			int m = 0;
			int n = 0;
			
		//
			while(1)
				{
					print_score(one,ten,hunderd,thousand);		//输出现有的总分；

					get_touch_with_point(&m,&n);			//获取当前手指点击处的绝对坐标；
					my_DFS(m,n);					//深度优先遍历来删除与点击处相连的相同颜色的色块

					int number = 9;
					while(number--)						//通过循环来更新数组中的数据和屏幕上的色块；
						{
							move_of_down();
							
							update();
						}
					
					number = 9;
					while(number--)
						{
							move_of_left_or_right();		//将数组中数据为零的那一列向边缘移动；
							update();						//更新色块；
						}

					print_score(one,ten,hunderd,thousand);			//更新分数；
					
					int ret = my_BFS();				//广度优先遍历判断是否还有相同颜色的相连色块；
					if(ret == 0)
						{
							if(score >= target)		//若现有的总分大于目标，则输出下一关选项；
								{
									for(int i = 0;i < 3;i++)
										{
											draw_word(next[i],300,500 + i * 32, 32,116,0x00000000);   //输出： 下一关
										}
									for(int i = 3;i < 7;i++)
										{
											draw_word(next[i],400,500 + (i-3) * 32, 32,116,0x00000000);		//输出： 结束游戏；
										}
									flag = aigan();
									if(flag == -1)		//若按到了屏幕右上角的x，立即结束程序；
										{
											show_bmp("./stop.bmp");
											break;
										}
								}
							else
								{
									for(int i=0;i<5;i++)
										{
											draw_word(over[i],170,550 + i * 40, 32,224,0x00FF0000);			//输出：game 
										}
									for(int i=5;i<10;i++)
										{
											draw_word(over[i],270,560 + (i-4) * 40, 32,224,0x00FF0000);			//输出：over！
										}
									for(int i = 3;i < 7;i++)
										{
											draw_word(next[i],400,500 + (i-3) * 32, 32,116,0x00000000);			//输出： 结束游戏；
										}
									flag = aigan();
									if(flag == -1)
										{
											show_bmp("./stop.bmp");				//如果返回值为-1，表示为非正常结束；
											break;
										}
								}	
							break;  
						}
				}
		}
	if(flag == 0)
		{
			show_bmp("./touma.bmp");  //显示正常结束的图片；
		}
	
	ts_uninit();
	lcd_uninit();

}
