#include <stdio.h>
#include "interface_subject.h"

Observer_t obs_update;

int display_data(int temp, int time)
{
	printf("DISPLAY:-\nTemp: %d\nTime: %d\n",temp,time);
	return 0;
}

void Update(int temp, int time)
{
	int ret = -1;

	printf("I am in Update\n");
	ret = display_data(temp, time);	
}

int CreatDispObj()
{
	int ret = -1;

	obs_update.update = Update;
	ret = registerObserver(&obs_update);
	if (ret == -1) {
		printf("Err in registerObserver()\n");
		return -1;
	} else {
		printf("Successfuly register\n");
	}
	
	return 0;
}

int DestDispObj()
{
	int ret = -1;

	obs_update.update = Update;
	ret = removeObserver(&obs_update);
	if (ret == -1) {
		printf("Err in removeObserver()\n");
		return -1;
	} else {
		printf("Successfuly remove\n");
	}
	
	return 0;
}

