#include "ilogger.h"

/*************************/
/* FUNCTION DECLARATIONS */
/*************************/

Logger_status logToFile(Tags, const char *, ...);
char *getLog(void);
static char *tags(int);
static char *wday(int);
static int month(int);
static int year(int);

/********************/
/* EXTERN FUNCTIONS */
/********************/

Logger_status
logToFile(Tags tag, const char *message, ...)
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

char *
getLog(void)
{
	char *ret;
	long file_size;
	FILE *log_file;

	log_file = fopen(LOG_FILE, "r");

	/* get size of file */
	fseek(log_file, 0, SEEK_END);
	file_size = ftell(log_file);
	rewind(log_file);

	/* DYNAMIC MEMORY ALLOCATION */
	ret = (char *) malloc(sizeof(char) * file_size);

	/* get file content */
	fread(ret, 1, file_size, log_file);

	fclose(log_file);

	return ret;
}

/********************/
/* STATIC FUNCTIONS */
/********************/

/************************** Convertion functions ******************************/

static char *
tags(int tag)
{
	switch (tag) {
		case LG_DEBUG:
			return "DEBUG";
			break;
		case LG_AUTHENTICATION:
			return "AUTHENTICATION";
			break;
		case LG_COMMUNICATION_MANAGER:
			return "COMMUNICATION MANAGER";
			break;
		case LG_IMAGE:
			return "IMAGE";
			break;
		case LG_UI:
			return "UI";
			break;
		case LG_GUI:
			return "GUI";
			break;
		default:
			return "UNKNOWN";
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
