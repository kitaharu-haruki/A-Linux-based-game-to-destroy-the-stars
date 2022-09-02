#include<stdio.h>
#include"move.h"
#include"lcd.h"


extern int star[10][10];
int move_of_down(void)
{
	int i, j, temp;
		for(i = 0;i < 10;i++)
			{
				for(j = 9; j > 0;j--)
					{
						if(star[j][i] == -1)
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
