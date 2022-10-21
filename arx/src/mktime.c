/*	mktime.c
 *	ansi mktime
 *
 *	V01-001 sep 01 1991	Reinhold	original
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <time.h>

#define	YEARDAYS	365l
#define	DAYHOURS	24l
#define	HOURMINUTES	60l
#define	MINUTESECONDS	60l
#define	HOURSECONDS	(HOURMINUTES*MINUTESECONDS)
#define	DAYSECONDS	(DAYHOURS*HOURSECONDS)
#define	EPOCH		(25567l*DAYSECONDS)
enum month {
	JANUARY=0, FEBRUARY, MARCH,
	APRIL, MAY, JUNE,
	JULY, AUGUST, SEPTEMBER,
	OCTOBER, NOVEMBER, DECEMBER
	};

time_t	mktime (tp)
	struct tm *tp;

{
time_t		t;
static int	months[] =
		{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

t	=  tp->tm_year * YEARDAYS;
t	+= (tp->tm_year-1) / 4;
t	+= months[tp->tm_mon];
t	+= tp->tm_year % 4 == 0 && tp->tm_mon > FEBRUARY ? 1 : 0;
t	+= tp->tm_mday-1;
t	*= DAYSECONDS;
t	+= tp->tm_hour * HOURSECONDS;
t	+= tp->tm_min * MINUTESECONDS;
t	+= tp->tm_sec;
t	-= EPOCH;
return t;
}
