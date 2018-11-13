#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "subject.h"

int CreatDispObj();

int main()
{
	int ret = -1;
	
	printf("******** APPLICATION STARTED *********\n");
	ret = CreatDispObj();
	if (-1 == ret) {
		printf("Err in ret CreatDispObj()\n");
		return -1;
	} else {
		printf("Success Registration\n");
	}

	ret = WeatherChange(12, 23);
	if (-1 == ret) {
		printf("Err in ret WeatherChange()\n");
		return -1;
	} else {
		printf("Success WeatherChange()\n");
	}
	printf("******** APPLICATION END *********\n");
	return 0;
}
