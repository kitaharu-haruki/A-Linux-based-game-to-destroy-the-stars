消灭星星：
		1.通过rand函数生成伪随机数，通过伪随机数的值%5，得到对应的颜色数组的下标；
		2.将对应的颜色值赋给一个10*10的二维数组，在通过画块函数在屏幕上生成对应的颜色；
		3.获取手指点在触摸屏上的绝对坐标值，确定对应的二维数组元素，通过深度优先算法将其附近的相同颜色的色块刷白；
		4.置换同一列中被刷白的色块与未被刷白的色块的二维数组颜色，然后刷新屏幕，实现下落效果；
		5.判定每一列最底下的数组元素是否为白，若是，表明该列已为空；交换左右列不为空的数组元素；刷新屏幕，实现色块左右移的效果；
		6.通过广度优先遍历判断现存的每个未被刷白的色块附近是否有颜色相同的色块；若有，则游戏继续；否则，游戏结束；
		
函数原型，功能：
	1.int my_DFS(int x,int y)
		通过获得的坐标判断色块在二维数组中的位置，然后进入深度优先遍历；
		
		
	2.int DFS(int x, int y, int color,int num)
		深度优先遍历，若附近有相同颜色的色块，将自身置为-1，num++，进入递归；
		若附近没有颜色相同的色块，且num>0,说明至少有两个色块颜色相同，将自身置为-1；
		
	3.int my_BFS(void)
	广度优先遍历判断现存的每个未被刷白的色块附近是否有颜色相同的色块的个数，若个数大于0，游戏继续，若等于0，游戏结束；
	
	4.int BFS(int x,int y,int num)
	判断附近是否有相同的色块，若有，num++;
	
	5.int lcd_init(void)
	打开屏幕，开启映射；
	
	6.ts_init();//打开开发板触屏
	
	7.int lcd_uninit(void)
	解除映射，关闭屏幕
	
	8.void lcd_draw_point(int x,int y,int color)
	画点函数；
	
	9.void lcd_draw_block(int x0,int y0,int lenth,int high,int color)
	循环调用画点函数实现画块；
	
	10.void draw_word(unsigned char *name,int x0,int y0, int len,int size,int color)
	在屏幕上输出文字；
	
	11.int move_of_down(void)
	上下移动色块
	
	12.int update(void)
	刷新屏幕
	
	13.int move_of_left_or_right(void)
	左右移动色块
	
	14.int aigan(void)
	获取点击区坐标，决定是否继续游戏；
	
	15.int game_start(void)
	获取点击区坐标，跳过开始画面，开始游戏；
	
	16.int creat_rand_color(int x0,int y0)
	在屏幕上生成随机色块；
	
	17.int print_score(int one,int ten,int hunderd,int thousand)
	在屏幕上输出获得的总分；
	
	18.int show_bmp(char *pathname)
	在屏幕上输出开始界面，结束界面，中途退出界面；
	
	19.int get_touch_with_point(int *m,int*n)
	获取手指点击处的绝对坐标值；
