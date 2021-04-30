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
	else if (!strcmp("-h", args[*optind]) || !strcmp("--help", args[*optind]))
	{
		return 'h';
	}
	else if ((!strcmp("--string", args[*optind]) || !strcmp("-s", args[*optind])) && *optind + 1 < nargs)
	{
       *optind += 1;
	   context.data = (uint8_t*)args[*optind];
	   context.ctx = (uint8_t*)ft_strjoin("string(", args[*optind]);
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
	else if (!strcmp("--print", args[*optind]) || !strcmp("-p", args[*optind]))
	{
		context.flags |= (1 << 3);
		return 'p';
	}
	context.fd = open(args[*optind], O_RDONLY);
	if (context.fd != -1)
	{
		context.ctx = (uint8_t*)ft_strjoin(context.hfun == 1 ? "MD5(" : "SHA256(", args[*optind]);
		context.data = readfile();
		if (!context.data)
			context.data = (uint8_t*)ft_strdup("");
		return 'f';
	}
	else
		return 'i';
	return 'b';
}
