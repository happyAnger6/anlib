#include "unp.h"

int main(int argc, char *argv[])
{
    if(argc<3)
    {
        printf("usage:%s <server> <proto>\r\n", argv[0]);
        return -1;
    }

    char str[INET_ADDRSTRLEN];
    struct servent *pServer;
    if((pServer = getservbyname(argv[1], argv[2]))==NULL)
    {
        printf("get serve for name:%s error:%s\r\n", *argv, hstrerror(h_errno));
        return -1;
    }

    union t_u{
        short a;
        char s[2];
    }t;
    short port = ntohs((short)pServer->s_port);
    t.a = port;
    int i;
    for(i = 0; i < 2; i++)
        printf("%x\r\n", t.s[i]);
    printf("server name:%s port:%d %x\r\n", pServer->s_name, port, port);
    return 0;

    
}

