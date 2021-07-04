#include <stdio.h>

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day);
/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(){
	int year = 2019;
	int month = 4;
	int day = 19;
	int today = day_of_year(year, month, day);
	printf("Today is the %dth day of the year.\n", today);
	month_day(year, today, &month, &day);
	printf("From this, we can deduce that we're in the ");
	printf("%dth day of the %dth month.\n", day, month);
	return 0;
}

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
/* update: check for valid month and day values  */
int day_of_year(int year, int month, int day){
	int i, leap;

	leap = (year%4==0 && year%100!=0) || year%400==0;

	/* update: check for valid month and day values */
	if(day<1 || day>daytab[leap][month] || month<1 || month>12)
		return -1;

	for(i=1; i<month; i++)
		day += daytab[leap][i];
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday){
	int i, leap;

	leap = (year%4==0 && year%100!=0) || year%400==0;

	for(i=1; yearday>daytab[leap][i]; i++)
		yearday -= daytab[leap][i];

	/* update: check for valid month and day values*/
	if(i<1 || i>12 || yearday > daytab[leap][i] || yearday<1){
		*pmonth = -1;
		*pday = -1;
	}

	*pmonth = i;
	*pday = yearday;
}