#include "../includes/client_info.h"

char * client_prompt()
{
	char * prompt = "promt";
	// forma del promt usuario@servidor //
	printf("%s",KBLD);
	printf("%s",KCYN);
	printf("%s%s%s","agustin", "@",  "hostname");
	printf("%s",KMAG);
	printf(" %s%s", "password", " $");
	printf("%s",KNRM);

	return prompt;
}
