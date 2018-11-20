/*
AUTHOR: Satya Sundar Sahu
DATE:   18-Nov-2018
DESCRIPTION:
	This File Contains Source Code of object display.
*/

#include <stdio.h>
#include "interface_subject.h"
#include "debug.h"

Observer_t obs_update;

/* Below Function will show data is display */

int display_data(int id, float temp, float time)
{
	printf("----------------------|\n");
	printf("| DISPLAY:%d-\n|--------------------|\n|\t\
Temp: %.2f\n|---------------------|\n|\tTime: %.2f\n|",id,temp,time);
	printf("----------------------|\n");
	return 0;
}

/* Below Function will call from subject<Weather station> 
*  through function pointer*/

void Update(int id, float temp, float time)
{
	int ret = -1;

	DBG_PRINT("I am in Update\n");
	ret = display_data(id,temp, time);
	if (ret == 0) {
		DBG_PRINT("display_data() success\n");
	}
}

/* Below Function Will call from Test Application */

int CreatDispObj()
{
	int ret = -1;

	obs_update.update = Update;
	ret = registerObserver(&obs_update);
	if (ret == -1) {
		printf("Err in registerObserver()\n");
		return -1;
	} else if (ret == 1) {
		printf("Wait some time. Station BUSY\n");
	} else {
		DBG_PRINT("Successfuly register\n");
	}
	
	return 0;
}

/* Below Function Will call from Test Application */

int DestDispObj(int disp_id)
{
	int ret = -1;

	//obs_update.update = Update;
	ret = removeObserver(disp_id);
	if (ret == -1) {
		printf("Err in removeObserver()\n");
		return -1;
	} else if (ret == 1) {
		printf("Wait some time. Station Busy\n");
	} else {
		DBG_PRINT("Successfuly remove\n");
	}
	
	return 0;
}

