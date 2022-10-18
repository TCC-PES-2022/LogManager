#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>

#define LOG_SIZE 256

#define LOG_FILE "ariel.log"

/* module to log */
typedef enum module_tags {
	LG_DEBUG                 = 0,
	LG_AUTHENTICATION        = 1,
	LG_COMMUNICATION_MANAGER = 2,
	LG_IMAGE                 = 3,
	LG_UI                    = 4,
	LG_GUI                   = 5
} Tags;

typedef enum logger_system {
	LG_OK    = 0,
	LG_ERROR = 1
} Logger_status;

/* extern functions */
Logger_status logToFile(Tags, const char *, ...);
char *getLog(void); /* DYNAMIC MEMORY ALLOCATION HERE!! DESALLOCATE AFTER USE */

#endif
