#include <stdio.h>
#include <stdlib.h>
#include "subject.h"
#include "interface_observer.h"
#include "interface_subject.h"

static WS *observer_head = NULL;
static int node_cnt = 1;
static int notify_flag = 0;

/* Below Function will register Observer in a Single Linked List */

int registerObserver(Observer_t *obs)
{
	//int ret = -1;
	WS *new_node = NULL;

	if (NULL == obs) {
		printf("Err ret in registerObserver()\n");
		return -1;
	}
	if (notify_flag == 1) {
		printf("Please wait Some time\n");
		return 1;
	}
	new_node = (WS *)malloc(sizeof(WS));
	if (NULL == new_node) {
		printf("Err in malloc\n");
		return -1;
	}
	if (NULL == observer_head) {
		new_node->next = NULL;
		new_node->display = obs;
		new_node->disp_id = node_cnt++;
		observer_head = new_node;
	} else {
		new_node->next = observer_head;
		new_node->display = obs;
		new_node->disp_id = node_cnt++;
		observer_head = new_node;
	}
	return 0;
}

/* Below Function will remove Observer from List */

int removeObserver(int disp_id)
{
	WS *tmp = observer_head;
	WS *prev = tmp;
	int ret = -1;

	if (tmp == NULL) {
		printf("NO object found. List is empty\n");
		return ret;
	}
	if (notify_flag == 1) {
		printf("Please wait Some time\n");
		return 1;
	}
	/* If Node Found at 1st Position */
	if (observer_head->disp_id == disp_id) {
		observer_head = observer_head->next;
		free(tmp);
		tmp = NULL;
		ret = 0;
	}
	/* Traversing each Node */
	while (tmp && (ret != 0)) {
		if (tmp->disp_id == disp_id) {
			prev->next = tmp->next;
			free(tmp); // Free memory block
			break;
		} else {
			prev = tmp;
			tmp = tmp->next; //Traversing linked list
		}
	}
	if (tmp == NULL) {
		printf("REQUESTED ID IS NOT PRESENT IN LIST\n");
	} else {
		tmp = NULL; // Dangling Pointer
	}
	return 0;
}

/* Below Function will Notify to Observer */

int notifyObservers(float temp, float time)
{
	WS *tmp = observer_head;
	int id = 0;
	if (tmp == NULL) {
		printf("NULL pointer\n");
		return -1;
	}
	printf("Notify Started Set Notify flag.....\n");
	notify_flag = 1;

	while (NULL != tmp) {
		id = tmp->disp_id;
		/* Calling Function using function pointer */
		tmp->display->update(id, temp, time);
		tmp = tmp->next;
	}
	notify_flag = 0;

	printf("Notify Done Clear Notify flag.....\n");
	return 0;
}

int WeatherChange(float temp, float time)
{
	int ret = -1;
	ret = notifyObservers(temp, time);
	if (ret == -1) {
		printf("Error return notifyObservers()\n");
		return -1;
	}
	return 0;
}
