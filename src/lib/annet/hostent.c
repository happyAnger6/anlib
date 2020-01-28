#include "unp.h"

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        printf("usage:%s <hostnamelists>\r\n", argv[0]);
        return -1;
    }

    char str[INET_ADDRSTRLEN];
    struct hostent *phost;
    char **pptr;
    while(--argc)
    {
        if((phost = gethostbyname(*(++argv)))==NULL) 
        {
            printf("get host for name:%s error:%s\r\n", *argv, hstrerror(h_errno));
            continue;
        }

        printf("hostname:%s\r\n", *argv);
        printf("canocial name:%s\r\n", phost->h_name);
        for(pptr = phost->h_aliases; *pptr != NULL; pptr++)
        {
            printf("alias:%s\r\n", *pptr);
        }

        switch(phost->h_addrtype)
        {
            case AF_INET:
                for(pptr = phost->h_addr_list; *pptr != NULL; pptr++)
                {
                    printf("\t address:%s \r\n", inet_ntop(AF_INET, *pptr, str, sizeof(str)));
                }
                break;
           default:
                printf("unkonw addrtype:%d\r\n", phost->h_addrtype);
                break;
        }
    }

    return 0;
}
