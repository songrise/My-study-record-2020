#include <signal.h>
int initHandlers(void);
extern void unix_error(char *msg);

typedef void (*sighandler_t)(int);

int initHandlers(void)
{
    signal(SIGINT, SIG_IGN); //ignore ctrl+z
}
