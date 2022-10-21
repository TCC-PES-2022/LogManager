#ifndef LOGGER_H
#define LOGGER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>

#define LOG_SIZE 256

#define LOG_FILE "ariel.log"

/* Name of available Tags - change as needed */
static const char *tags_names[] = {
	"DEBUG", "AUTHENTICATION", "COMMUNICATION MANAGER", "IMAGE", "UI",
	"GUI", "UNKNOWN"
};

/* Tags - change as needed */
typedef enum module_tags {
	LG_DEBUG                 = 0,
	LG_AUTHENTICATION        = 1,
	LG_COMMUNICATION_MANAGER = 2,
	LG_IMAGE                 = 3,
	LG_UI                    = 4,
	LG_GUI                   = 5
} Tags;

/* Log system status return */
typedef enum logger_system {
	LG_OK    = 0,
	LG_ERROR = 1
} Logger_status;

/********************/
/* EXTERN FUNCTIONS */
/********************/

/* logger(tag number, string format, ...) */
Logger_status logger(Tags, const char *, ...);

#ifdef __cplusplus
}
#endif

#endif
