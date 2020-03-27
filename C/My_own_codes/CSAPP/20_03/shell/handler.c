#include <signal.h>
#include "sio.h"
extern void unix_error(char *msg);

typedef void (*sighandler_t)(int);
void SIGTSTP_handler(void);
void SIGINT_handler(void);

int initHandlers(void)
{
    signal(SIGTSTP, SIG_IGN);       //ignore ctrl+z
    signal(SIGINT, SIGINT_handler); // printa message before exit.
}

// void SIGTSTP_handler(void)
// {
//     Sio_puts("Use quit command to quit!\n");
// }
void SIGINT_handler(void)
{
    Sio_puts(" *Shell Terminated.*\n");
    _exit(0);
}