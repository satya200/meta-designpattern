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

	ret = WeatherChange(12, 23);
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
	return 0;
}
