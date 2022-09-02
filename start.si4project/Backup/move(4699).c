#include<stdio.h>
#include"move.h"
#include"lcd.h"


extern int star[10][10];

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

