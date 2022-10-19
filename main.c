#include "ilogger.h"

int
main(void)
{
	char *login = "NovoUsuario";
	char *PN = "PN9876";

	/* Examples of use */
	logger(LG_AUTHENTICATION, "%s %s", login, "authenticated");
	logger(LG_IMAGE, "%s %s %s %s", login, "transfered", PN, "image");
	logger(LG_COMMUNICATION_MANAGER, "%s %s %s %s", login, "transfered", PN, "image");

	return EXIT_SUCCESS;
}
