#ifndef _OBSERVER_H
#define _OBSERVER_H

typedef void (*update_display) (int temp, int time);

typedef struct observer
{
	update_display update;
}Observer_t;

#endif

