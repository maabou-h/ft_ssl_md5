#include "ssl.h"

uint8_t *readfile(void)
{
	char	buffer[64];
	uint8_t* rbuf = NULL;
	uint8_t* tbuf = NULL;
	int8_t ret;
	
	ft_bzero(&buffer, 64);
	while ((ret = read(context.fd, &buffer, 63)) > 0)
	{
		if (rbuf != NULL)
		{
			printf("%lu\n", strlen((char*)rbuf));
			tbuf = (uint8_t*)ft_strdup((char*)rbuf);
			free(rbuf);
			rbuf = (uint8_t*)ft_strjoin((char*)tbuf, (char*)buffer);
			free(tbuf);
		}
		else
			rbuf = (uint8_t*)ft_strdup((char*)buffer);
		ft_bzero(&buffer, 64);
	}
	return rbuf;
}

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
	   context.data = (uint8_t*)args[*optind];
		return 's';
	}
	else if (!strcmp("--quiet", args[*optind]) || !strcmp("-q", args[*optind]))
	{
		context.flags |= (1 << 1);
		return 'q';
	}
	else if (!strcmp("--reverse", args[*optind]) || !strcmp("-r", args[*optind]))
	{
		context.flags |= (1 << 2);
		return 'r';
	}
	context.fd = open(args[*optind], O_RDONLY);
	if (context.fd != -1)
	{
		context.data = readfile();
		context.flags |= (1 << 8);
		printf("%s\n", context.data);
		return 'f';
	}
	else
		return 'i';
	return 'b';
}
