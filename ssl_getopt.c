#include "ssl.h"

uint8_t ssl_getopt(uint32_t nargs, char* args[], uint32_t *optind)
{
	int8_t ret = 0;

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
	else if (!strcmp("--quiet", args[*optind]) || !strcmp("-q", args[*optind]))
	{
		return 'q';
	}
	else if (!strcmp("--reverse", args[*optind]) || !strcmp("-r", args[*optind]))
	{
		return 'r';
	}
	ret = open(args[*optind], O_RDONLY);
	if (ret != -1)
		return 'f';
	else
		return 'i';
	return 'b';
}
