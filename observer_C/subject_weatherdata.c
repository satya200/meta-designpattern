#include <stdio.h>
#include <stdlib.h>
#include "subject.h"
#include "interface_observer.h"
#include "interface_subject.h"

static WS *observer_head = NULL;
static int node_cnt = 0;

int registerObserver(Observer_t *obs)
{
	int ret = -1;
	WS *new_node = NULL;

	if (NULL == obs) {
		printf("Err ret in registerObserver()\n");
		return -1;
	}
	new_node = (WS *)malloc(sizeof(Observer_t));
	if (NULL == new_node) {
		printf("Err in malloc\n");
		return -1;
	}
	if (NULL == observer_head) {
		printf("fast node\n");
		new_node->next = NULL;
		(*new_node).display = obs;
		observer_head = new_node;
	} else {
		new_node->next = observer_head;
		(*new_node).display = obs;
		observer_head = new_node;
	}
	return 0;
}

int removeObserver(Observer_t *obs)
{
	if (NULL == obs) {
		printf("Err ret in removeObserver()\n");
		return -1;
	}
	return 0;
}

int notifyObservers(int temp, int time)
{
	WS *tmp = observer_head;
	if (tmp == NULL) {
		printf("NULL pointer\n");
		return -1;
	}
	printf("Notify Started.....\n");
	while (NULL != tmp) {
		tmp->display->update(temp, time);
		tmp = tmp->next;
	}
	printf("Notify Done.....\n");
	return 0;
}

int WeatherChange(int temp, int time)
{
	int ret = -1;
	ret = notifyObservers(temp, time);
	if (ret == -1) {
		printf("Error return notifyObservers()\n");
		return -1;
	}
	return 0;
}
