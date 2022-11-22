#include "ilogger.h"

int
main(void)
{
	char *login = "NovoUsuario";
	char *PN = "PN9876";

	/* Examples of use */
	logger(LG_DEBUG, "%s jldsjf", "this is a debug");
	logger(LG_AUTHENTICATION, "%s %s", login, "Authenticated");
	logger(LG_IMAGE, "%s %s -- %s %s", login, "transfered", PN, "image");
	logger(LG_COMMUNICATION_MANAGER, "%s %s %s %s", login, "transfered", PN, "image");
	logger(LG_UI, "%s", "UI:)");
	logger(LG_GUI, "%s", "GUI:(");
	logger(99, "%s", "lsdjf;adjf");

	return EXIT_SUCCESS;
}
