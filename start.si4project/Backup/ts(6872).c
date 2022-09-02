#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>

int ts_fd = -1;
struct point
{
	int x,y;
}end;

int  ts_init(void)
{
	ts_fd =open("/dev/input/event0",O_RDWR);
	if(ts_fd < 0)
	{
		return -1;
	}
	return 0;
}

int ts_uninit(void)
{
	return close(ts_fd);
}


int get_touch(void)
{
	struct input_event in;

	while(1)
	{
		if(read(ts_fd,&in,sizeof(in))== sizeof(in)) //读取成功
			{
			//结构体解析
			if(in.type == EV_KEY && in.code == 0x14a) //表示有压力值
			{
				printf("type = %d,code = %d,value = %d\n",in.type,in.code,in.value);
				if(in.value > 0)
				{		//按下 记录
					continue;
				}
				else
				{
					break;
				}
						
			}
		}
	}
	return 1;
}

int get_touch_with_point(int *m,int*n)
{
	struct input_event in;
	end.x = end.y = -1; // 

	struct point temp;
	while(1)
	{
		if(read(ts_fd,&in,sizeof(in))== sizeof(in)) //读取成功
		{
			//结构体解析
			if(in.type == EV_ABS && in.code == ABS_X)
			{
				temp.x = in.value;
			}
			else if(in.type == EV_ABS && in.code == ABS_Y)
			{
				temp.y = in.value;
			}
			else if(in.type == EV_KEY && in.code == 0x14a) //表示有压力值
			{
				printf("type = %d,code = %d,value = %d\n",in.type,in.code,in.value);
				if(in.value > 0)
				{	
					continue;
				}
				else
				{
					end.x = temp.x;
					end.y = temp.y;
					*m = end.x;
					*n = end.y;
					printf("*m=%d,*n=%d\n",*m,*n);
					break;
				}			
			}
		}
	}
	return 1;
}


