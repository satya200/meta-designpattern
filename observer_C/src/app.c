/*
AUTHOR : Satya Sundar Sahu
DATE: 20-Nov-2018

This File contains test application.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "subject.h"
#include "debug.h"

int CreatDispObj();
int DestDispObj(int);

int main()
{
	int ret = -1;
	int i = 0;
	float temp = 23.3;
	float time = 13.15;
	
	printf("******** APPLICATION STARTED *********\n");
	for (i = 0; i < 3; i++) {
		ret = CreatDispObj();
		if (-1 == ret) {
			printf("Err in ret CreatDispObj()\n");
			return -1;
		} else {
			printf("In app Success Registration\n");
		}
	}

	ret = WeatherChange(temp, time);
	if (-1 == ret) {
		printf("Err in ret WeatherChange()\n");
		return -1;
	} else {
		printf("Success WeatherChange()\n");
	}
	
	ret = DestDispObj(2);
	if (ret == -1) {
		printf("Err in destroy\n");
	}
	ret = WeatherChange(122, 233);
	if (-1 == ret) {
		printf("Err in ret WeatherChange()\n");
		return -1;
	} else {
		printf("Success WeatherChange()\n");
	}
	printf("******** APPLICATION END *********\n");
	//ret = DestDispObj(1);
	//ret = DestDispObj(3);
	return 0;
}
