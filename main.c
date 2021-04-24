#include "ssl.h"

int32_t parseargs(uint32_t nargs, uint8_t* args[])
{
	uint8_t opt = 0;
	uint32_t optind = 2;
	int32_t ret = 0;
    uint32_t a = 0;
    uint8_t stdin = 1;

    if (nargs < optind || (strcmp("md5", (char*)args[optind-1]) && strcmp("sha256", (char*)args[optind-1])))
        {
            printf("no algo specified as first argument\n");
            return (-1);
        }
    a = !strcmp("md5", (char*)args[optind-1]) ? 1 : 2;
	while (ret == 0 && (opt = ssl_getopt(nargs, (char**)args, &optind)))
	{
		switch (opt)
		{
		case 'h':
            printf("help menu\n");
			ret = 1;
			break;
        case 'b':
            printf("bad usage\n");
			ret = 1;
			break;
        case 'f':
            printf("reading from file: %s\n", args[optind]);
            ret = 0;
            stdin = 0;
            break;
        case 'q':
            printf("quiet mode\n");
            ret = 0;
            break ;
        case 'r':
            printf("reverse format\n");
            ret = 0;
            break ;
        case 'i':
            printf("invalid file: %s\n", args[optind]);
            ret = 0;
            stdin = 0;
            break;
        case 's':
            stdin = 0;
            printf("option s with %s\n", args[optind]);
            if (a == 2)
                sha256(args[optind]);
            else
                md5(args[optind]);
			ret = 0;
			break;
        case 'e':
            if (stdin)
                printf("reading from stdin\n");
            ret = 1;
            break;
			if (ret)
				return (-1);
		}
		optind++;
	}
    return (0);
}

int main(int argc, char **argv)
{
    uint8_t *msg;
    int i;
 
    if (argc > 1)
    {
        i = parseargs(argc, (uint8_t**)argv);
            return (0);
         if (!strcmp(argv[1], "md5"))
         {
            msg = (uint8_t*)argv[2];
            md5(msg);
            return 0;
         }
         else if (!strcmp(argv[1], "sha256"))
         {
            printf("starting sha256\n");
            msg = (uint8_t*)argv[2];
            sha256(msg);
            return 0;
         }
    }
    return 1;
}
