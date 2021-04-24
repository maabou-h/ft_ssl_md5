#include "ssl.h"

uint8_t ssl_getopt(uint32_t nargs, char* args[], uint32_t *optind)
{
    if (*optind == nargs)
        return 'e';
	if (!strcmp("-h", args[*optind]) || !strcmp("--help", args[*optind]))
	{
		return 'h';
	}
	else if ((!strcmp("--string", args[*optind]) || !strcmp("-s", args[*optind])) && *optind + 1 < nargs)
	{
       *optind += 1;
		return 's';
	}
	return 'b';
}