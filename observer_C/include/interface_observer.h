#ifndef _OBSERVER_H
#define _OBSERVER_H

typedef void (*update_display) (int id, int temp, int time);

typedef struct observer
{
	int disp_id;
	update_display update;
}Observer_t;

#endif

