#include "ilogger.h"

/*************************/
/* FUNCTION DECLARATIONS */
/*************************/

Logger_status logger(Tags, const char *, ...);
static const char *tags(int);
static char *wday(int);
static int month(int);
static int year(int);

/********************/
/* EXTERN FUNCTIONS */
/********************/

Logger_status
logger(Tags tag, const char *message, ...)
{
	char log_string[LOG_SIZE];
	time_t rawtime;
	struct tm *info;
	FILE *log_file;
	va_list pargs;

	/* open log file */
	log_file = fopen(LOG_FILE, "ab+");
	if (!log_file)
		return LG_ERROR;

	/* setting time and date information */
	time(&rawtime);
	info = localtime(&rawtime);

	/* processing arguments list */
	va_start(pargs, message);
	vsprintf(log_string, message, pargs);
	va_end(pargs);

	/* convert log message to string and save to file */
	fprintf(log_file, "%d/%d/%d %s %02d:%02d:%02d - [%s]: %s\n",
	year(info->tm_year), month(info->tm_mon), info->tm_mday,
	wday(info->tm_wday), info->tm_hour, info->tm_min, info->tm_sec,
	tags(tag), log_string);

	fclose(log_file);

	return LG_OK;
}

/********************/
/* STATIC FUNCTIONS */
/********************/

/************************** Convertion functions ******************************/

static const char *
tags(int tag)
{
	switch (tag) {
		case 0:
			return tags_names[0];
			break;
		case 1:
			return tags_names[1];
			break;
		case 2:
			return tags_names[2];
			break;
		case 3:
			return tags_names[3];
			break;
		case 4:
			return tags_names[4];
			break;
		case 5:
			return tags_names[5];
			break;
		default:
			return tags_names[6];
			break;
	}
	/* unreacheable */
	return "ERROR";
}

static char *
wday(int weekday)
{
	switch (weekday) {
		case 0:
			return "Sunday";
			break;
		case 1:
			return "Monday";
			break;
		case 2:
			return "Tuesday";
			break;
		case 3:
			return "Wednesday";
			break;
		case 4:
			return "Thurday";
			break;
		case 5:
			return "Friday";
			break;
		case 6:
			return "Saturday";
			break;
		default:
			break;
	}
	/* unreacheable */
	return "Err";
}

static int
month(int mon)
{
	return mon + 1;
}


static int
year(int tm_year)
{
	return tm_year + 1900;
}
