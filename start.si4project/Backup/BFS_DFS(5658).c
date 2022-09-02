#include<stdio.h>
#include"BFS_DFS.h"
#include"lcd.h"
#include"rand_color.h"

extern int star[10][10];

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
			color = star[i][j];
			if(color != -1)
				{
					DFS(i,j,color,num);
				}
			
			return 1;
		}
	
}

int DFS(int x, int y, int color,int num)
{
	printf("num=%d\n",num);
	printf("x=%d,y=%d\n",x,y);
	int n[2] = {-1,1};
	int i;
	
	for(i=0;i<2;i++)
		{
			if(x > 0 && x < 9)
				{
					if(star[ x + n[i]][ y ] == color)
						{
							star[x][y] = -1;
							num++;
							lcd_draw_block(x*48+2,y*48+2,44,44,star[x][y]);
							DFS(x+n[i],y,color,num);
						}
				}
			else if(x == 0 && i == 1)
				{
					if(star[ x + n[i]][ y ] == color)
						{
							star[x][y] = -1;
							num++;
							lcd_draw_block(x*48+2,y*48+2,44,44,star[x][y]);
							DFS(x+n[i],y,color,num);
						}
				}
			else if(x == 9 && i == 0)
				{
					if(star[ x + n[i]][ y ] == color)
						{
							star[x][y] = -1;
							num++;
							lcd_draw_block(x*48+2,y*48+2,44,44,star[x][y]);
							DFS(x+n[i],y,color,num);
						}
				}
			
		}
	
	for(i=0;i<2;i++)
		{
			if(y > 0 && y < 9)
				{
					if(star[x][y+n[i]] == color)
						{
							star[x][y] = -1;
							num++;
							lcd_draw_block(x*48+2,y*48+2,44,44,star[x][y]);
							DFS(x,y+n[i],color,num);
						}
				}
			else if(y == 0 && i ==1)
				{
					if(star[x][y+n[i]] == color)
						{
							star[x][y] = -1;
							num++;
							lcd_draw_block(x*48+2,y*48+2,44,44,star[x][y]);
							DFS(x,y+n[i],color,num);
						}
				}
			else if(y == 9 && i == 0)
				{
					if(star[x][y+n[i]] == color)
						{
							star[x][y] = -1;
							num++;
							lcd_draw_block(x*48+2,y*48+2,44,44,star[x][y]);
							DFS(x,y+n[i],color,num);
						}
				}
		}

	if(num > 0)
		{
			star[x][y] = -1;
			lcd_draw_block(x*48+2,y*48+2,44,44,star[x][y]);
		}
}


int my_BFS(void)
{
	int num = 0,sum = 0;
	int x,y;

	for(x = 0;x < 10;x++)
		{
			for(y = 0;y < 10;y++)
				{
					if(star[x][y] != -1)
						sum += BFS(x,y,num);
				}
		}
	
	return sum;
}

int BFS(int x,int y,int num)
{
	int n[2] = {-1,1};
	int i;
	
	for(i=0;i<2;i++)
		{
			if(x > 0 && x < 9)
				{
					if(star[ x + n[i]][ y ] == star[x][y])
						{
							num++;
						}
				}
			else if(x == 0 && i == 1)
				{
					if(star[ x + n[i]][ y ] == star[x][y])
						{
							num++;
						}
				}
			else if(x == 9 && i == 0)
				{
					if(star[ x + n[i]][ y ] == star[x][y])
						{
							num++;
						}
				}
			
		}
	
	for(i=0;i<2;i++)
		{
			if(y > 0 && y < 9)
				{
					if(star[x][y+n[i]] == star[x][y])
						{
							num++;
						}
				}
			else if(y == 0 && i ==1)
				{
					if(star[x][y+n[i]] == star[x][y])
						{
							num++;
						}
				}
			else if(y == 9 && i == 0)
				{
					if(star[x][y+n[i]] == star[x][y])
						{
							num++;
						}
				}
		}

	return num;
}
