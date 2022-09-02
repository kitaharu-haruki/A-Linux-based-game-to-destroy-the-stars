#ifndef _TS_H_
#define _TS_H_

int  ts_init(void);

int ts_uninit(void);

int get_touch(void);

int get_touch_with_point(int *m,int*n);


#endif
