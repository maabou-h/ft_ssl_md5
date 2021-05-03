#include "ssl.h"

struct ssl_ctx context;

int32_t parseargs(uint32_t nargs, uint8_t* args[])
{
	uint8_t opt = 0;
	uint32_t optind = 2;
	int32_t ret = 0;

    if (nargs < optind || (ft_strcmp("md5", (char*)args[optind-1]) && ft_strcmp("sha256", (char*)args[optind-1])))
    {
            ft_printf("no algo specified as first argument\n");
            return (-1);
    }
    context.hfun = !ft_strcmp("md5", (char*)args[optind-1]) ? 1 : 2;
    context.flags = 0;
    context.data = NULL;
    context.fd = 0;
	while (ret == 0 && (opt = ssl_getopt(nargs, (const char**)args, &optind)))
	{
		switch (opt)
		{
		case 'h':
            ft_printf("help menu\n");
			ret = 1;
			break;
        case 'b':
            ft_printf("bad usage\n");
			ret = 1;
			break;
        case 'i':
            ft_printf("ft_ssl: invalid file: %s\n", args[optind]);
            ret = 1;
            break;
        case 'e':
            return (0); 
        default:
            break;
		}
        if (ret)
			break ;
		optind++;
	}
    if (!context.data)
    {
        context.ctx = (uint8_t*)ft_strdup("(stdin");
        context.fd = 0;
        context.data = readfile();
        if (!context.data)
			context.data = (uint8_t*)ft_strdup("");
    }
    return (ret);
}

int main(int argc, char const* argv[])
{
    uint8_t ret = 1;

    if (argc >= 1)
    {
        if (!(ret = parseargs(argc, (uint8_t**)argv)))
        {
            if (context.hfun == 1)
               md5();
            else if (context.hfun == 2)
               sha256();
        }
		if (context.fd != -1)
			close(context.fd);
		if (context.data)
			free(context.data);
        if (context.ctx)
			free(context.ctx);
    }
    return (ret);
}
