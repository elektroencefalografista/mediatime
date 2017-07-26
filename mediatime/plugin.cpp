#include "stdafx.h"
#include <windows.h>
#include <stdlib.h>

#define DLLEXPORT __declspec(dllexport)

extern "C" DLLEXPORT  int
__stdcall  GetMinRefreshInterval(){
	return 250;
}

extern "C" DLLEXPORT  char * 
__stdcall  function1(char *param1, char *param2) {
	static int time, min, sec;
	static char outbuf[40];
	static char secstr[3];
	time = atoi(param1);
	min = time / 60;
	sec = time % 60;

	if (min < 60) {
		itoa(min, outbuf, 10);
	} else {
		static int hour;
		hour = min / 60;
		min = min % 60;
		itoa(hour, outbuf, 10);
		strcat(outbuf, ":");
		static char minstr[3];
		if (min >= 10) {
			itoa(min, minstr, 10);
		} else {
			static char mintmp[3];
			itoa(min, mintmp, 10);
			strcpy(minstr, "0");
			strcat(minstr, mintmp);
		}
		strcat(outbuf, minstr);
	}

	if (sec >= 10) {
		itoa(sec, secstr, 10);
	} else {
		static char sectmp[3];
		itoa(sec, sectmp, 10);
		strcpy(secstr, "0");
		strcat(secstr, sectmp);
	}	

	strcat(outbuf, ":");
	strcat(outbuf, secstr);
    return outbuf;       
}