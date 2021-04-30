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
            ft_printf("invalid file: %s\n", args[optind]);
            ret = 1;
            break;
        case 'e':
            ret = -1;
            break;  
        default:
            break;
		}
        if (ret && ret != -1)
			return (1);
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
    return (0);
}

int main(int argc, char const* argv[])
{
    if (argc >= 1)
    {
        if (parseargs(argc, (uint8_t**)argv))
            return (1);
         if (context.hfun == 1)
         {
            md5();
            return (0);
         }
         else if (context.hfun == 2)
         {
            sha256();
            return (0);
         }
    }
    return 1;
}
