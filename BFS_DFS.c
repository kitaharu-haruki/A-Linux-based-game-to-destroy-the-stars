#include<stdio.h>
#include"BFS_DFS.h"
#include"lcd.h"
#include"rand_color.h"

extern int star[10][10];
int score = 0;

/*
	函数原型 int my_DFS(int x,int y)
	函数功能 判断所点击颜色
	函数参数
		x 行坐标
		y 列坐标
	
*/
int my_DFS(int x,int y)
{
	if(x  > 600)
		{
			return 0;
		}
	else
		{
			int num = 0;
			int i=0,j=0,color;
			i = y/60;
			j = x/60;
			printf("i=%d,j=%d\n",i,j);
			if(i>=0 && i<10 && j>=0 && j<10)		//避免读到的数据过大，导致数组越界，发生段错误；
				{
					color = star[i][j];
					if(color != -1)				//只有数组中数据不为-1时，才能进入深度优先遍历，进行删除操作；
						{
							DFS(i,j,color,num);
						}
				}
			
			
			return 1;
		}
	
}
/*
	函数原型 int DFS(int x, int y, int color,int num)
	函数功能 深度遍历消除并记分
	函数参数 
		x 行坐标
		y 列坐标
		color 颜色
		num 消除数目
		
*/
int DFS(int x, int y, int color,int num)
{
	printf("num=%d\n",num);
	printf("x=%d,y=%d\n",x,y);
	int n[2] = {-1,1};
	int i;
	
	for(i=0;i<2;i++)	// 对上下相邻色块进行遍历(屏幕显示)
		{
			if(x > 0 && x < 9)	//判断点击处是否在10*10的区域内
				{
					if(star[x + n[i]][y] == color)	//判断上下色块是否与点击色块相同
						{
							star[x][y] = -1;			//如果相同，将当前位置的数据置为-1，刷白，然后进入附近颜色相同的数组位置
							num++;
							lcd_draw_block(x*48+2,y*48+2,44,44,star[x][y]);	
							DFS(x+n[i],y,color,num);
						}
				}
			else if(x == 0 && i == 1)	//色块位于最上边
				{
					if(star[x + n[i]][y] == color)
						{
							star[x][y] = -1;			//同67行；
							num++;
							lcd_draw_block(x*48+2,y*48+2,44,44,star[x][y]);
							DFS(x+n[i],y,color,num);
						}
				}
			else if(x == 9 && i == 0)	//色块位于最下边
				{
					if(star[x + n[i]][y] == color)
						{
							star[x][y] = -1;					//同67行；
							num++;
							lcd_draw_block(x*48+2,y*48+2,44,44,star[x][y]);
							DFS(x+n[i],y,color,num);
						}
				}
			
		}
	
	for(i=0;i<2;i++)	//对左右相邻色块进行遍历
		{
			if(y > 0 && y < 9)	
				{
					if(star[x][y+n[i]] == color)
						{	
							star[x][y] = -1;				//同67行；
							num++;
							lcd_draw_block(x*48+2,y*48+2,44,44,star[x][y]);
							DFS(x,y+n[i],color,num);
						}
				}
			else if(y == 0 && i ==1)	//色块位于最左边
				{
					if(star[x][y+n[i]] == color)
						{
							star[x][y] = -1;					//同67行；
							num++;
							lcd_draw_block(x*48+2,y*48+2,44,44,star[x][y]);
							DFS(x,y+n[i],color,num);
						}
				}
			else if(y == 9 && i == 0)	//色块位于最右边
				{
					if(star[x][y+n[i]] == color)
						{
							star[x][y] = -1;					//同67行；
							num++;
							lcd_draw_block(x*48+2,y*48+2,44,44,star[x][y]);
							DFS(x,y+n[i],color,num);
						}
				}
		}

	if(num > 0)
		{
			score += 2;	//分数
			star[x][y] = -1;
			lcd_draw_block(x*48+2,y*48+2,44,44,star[x][y]);	//消除色块
		}
	printf("score = %d\n",score);
}

/*
	函数原型 int my_BFS(void)
	函数功能 对剩余色块进行广度遍历
	函数参数
*/
int my_BFS(void)
{
	int num = 0,sum = 0;
	int x,y;

	for(x = 0;x < 10;x++)
		{
			for(y = 0;y < 10;y++)
				{
					if(star[x][y] != -1)
						sum += BFS(x,y,num);	//接收广度优先遍历的返回值
				}
		}
	
	return sum;
}

/*
	函数原型 int BFS(int x,int y,int num)
	函数功能 广度遍历判断色块附近是否有相同颜色以及判断左右是否存在空缺
	函数参数 
		x 行坐标
		y 列坐标
		num 数目
*/
int BFS(int x,int y,int num)
{
	int n[2] = {-1,1};
	int i;
	
	for(i=0;i<2;i++)	//遍历上下是否色块
		{
			if(x > 0 && x < 9)
				{
					if(star[x + n[i]][y] == star[x][y])	//判断上下是否有色块
						{
							num++;
						}
				}
			else if(x == 0 && i == 1)	//如果是最上方的色块
				{
					if(star[x + n[i]][y] == star[x][y])
						{
							num++;
						}
				}
			else if(x == 9 && i == 0)	//如果是最下方的色块
				{
					if(star[x + n[i]][y] == star[x][y])
						{
							num++;
						}
				}
			
		}
	
	for(i=0;i<2;i++)	//遍历左右是否色块
		{
			if(y > 0 && y < 9)
				{
					if(star[x][y+n[i]] == star[x][y])	//判断左右是否有色块
						{
							num++;
						}
				}
			else if(y == 0 && i ==1)	//如果是最左边的色块
				{
					if(star[x][y+n[i]] == star[x][y])	
						{
							num++;
						}
				}
			else if(y == 9 && i == 0)	//如果是最右边的色块
				{
					if(star[x][y+n[i]] == star[x][y])	
						{
							num++;
						}
				}
		}

	return num;
}
