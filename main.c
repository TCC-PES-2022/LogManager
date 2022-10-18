#include "ilogger.h"

int
main(void)
{
	char *log;
	char *login = "NovoUsuario";
	char *PN = "PN9876";
	/* Examples of use */
	logToFile(LG_AUTHENTICATION, "%s %s", login, "authenticated");
	logToFile(LG_IMAGE, "%s %s %s %s", login, "transfered", PN, "image");
	log = getLog();
	puts(log);

	/* REMEMBER: DEALLOCATE THE LOG BUFFER */
	free(log);

	return EXIT_SUCCESS;
}
