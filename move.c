#include<stdio.h>
#include"move.h"
#include"lcd.h"
#include"ts.h"

extern int star[10][10];
extern int target;
extern int score;

/*
	函数原型 int move_of_down(void)
	函数功能 控制色块下落
	函数参数
		void
*/
int move_of_down(void)
{
	int i, j, temp;
		for(i = 0;i < 10;i++)
			{
				for(j = 9; j > 0;j--)
					{
						if(star[j][i] == -1 && star[j-1][i] != -1)
							{
								temp = star[j-1][i];
								star[j - 1][i] = star[j][i];
								star[j][i] = temp;
							}
						else
							continue;
					}
			}
		return 1;
}

/*
	函数原型 int update(void)
	函数功能 更新色块信息
	函数参数
		void
*/
int update(void)
{
	int i,j;
	for(i=0;i<10;i++)
		{
			for(j=9;j >= 0;j--)
				{
					if(star[j][i] != -1)
						{
							lcd_draw_block(j*48+2,i*48+2,44,44,star[j][i]);
						}
					else if(star[j][i] == -1)
						lcd_draw_block(j*48+2,i*48+2,44,44,0x00FFFFFF);
				}
		}
			
	return 1;
}

/*
	函数原型 int move_of_left_or_right(void)
	函数功能 判断行是向左还是向右移动
	函数参数 
*/
int move_of_left_or_right(void)
{
	int j;

	for(j = 4;j > 0;j--)
		{
			if(star[9][j] == -1 && star[9][j - 1] != -1 )
				move_of_left(j);
		}
	for(j = 5;j < 9;j++)
		{
			if(star[9][j] == -1 && star[9][j + 1] != -1 )
				move_of_right(j);
		}

	

}

/*
	函数原型 int move_of_left(int j)
	函数功能 色块整体向左移动
	函数参数 
		j 色块列
*/
int move_of_left(int j)
{
	int i,temp = 0;

	for(i = 9;i >= 0;i--)
		{
			temp = star[i][j-1];
			star[i][j-1] = star[i][j];
			star[i][j] = temp;
		}
}

/*
	函数原型 int move_of_right(int j)
	函数功能 色块整体向左移动
	函数参数 
		j 色块列
*/
int move_of_right(int j)
{
	int i,temp = 0;

	for(i = 9;i >= 0;i--)
		{
			temp = star[i][j+1];
			star[i][j+1] = star[i][j];
			star[i][j] = temp;
		}
}

/*
	函数原型 int aigan(void)
	函数功能 操纵游戏再次开始
	函数参数
*/
int aigan(void)
{
	int r = 1;
	int x = -1,y = -1;

	while(r)
		{
			get_touch_with_point(&x,&y);	// 获取点击绝对坐标
			if(x == -1 && y == -1)
				{
					perror("get point error");
					return 0;
				}

			if(y>=0 && y<=60 && x>=960 && x<=1024)	//点击到叉的绝对值坐标时,退出
				{
					printf("x=%d,y=%d\n",x,y);
					r = 0;
					return -1;
				}
			else if(y>=370 && y<=420 && x>=610 && x<=750)	//点击到"下一关"的绝对坐标时,继续游戏
				{
					if(score > target)
						{
							printf("x=%d,y=%d\n",x,y);
							r = 0;
							return 1;
						}
					
				}
			else if(y>=480 && y<=550 && x>=610 && x<=790)	//点击到退出游戏的绝对坐标时,退出
				{
					printf("x=%d,y=%d\n",x,y);
					r = 0;
					return 0;
				}
		}
}

/*
	函数原型 int game_start(void)
	函数功能 开始游戏
	函数参数
*/
int game_start(void)
{
	int r = 1;
	int x = -1,y = -1;

	while(r)
		{
			get_touch_with_point(&x,&y);	// 获取点击绝对坐标
			if(x == -1 && y == -1)
				{
					perror("get point error");
					return 0;
				}

			if(y>=80 && y<=180 && x>=70 && x<=320)	//点击到"start"的绝对坐标范围则进入游戏
				{
					printf("x=%d,y=%d\n",x,y);
					r = 0;
					return 1;
				}
		}
}

