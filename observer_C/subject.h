#ifndef _SUBJECT_H
#define _SUBJECT_H

#include "interface_subject.h"
#include "interface_observer.h"

#define MAX_NODE 10

typedef struct WS_List_Node
{
	unsigned int id;
	Observer_t *display;	
	struct WS_List_Node *next;	
}WS;

int notifyObservers(int, int);

#endif
