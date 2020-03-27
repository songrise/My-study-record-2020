//compile in linux
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
// #include <builtin.h>

#define MAXLINE 128
#define MAXARGS 16

int initHandlers(void);
int parseline(char *bufchar, char **argv);
void eval(char *cmdline);
int builtin_command(char **argv);
void unix_error(char *msg);

int errno;
char *environ[];

int main(int argc, char const *argv[], char *envp[])
{
    initHandlers();
    char cmdline[MAXLINE];
    printf("Mini Shell for testing\n");
    while (1)
    {

        printf("> ");
        fgets(cmdline, MAXLINE, stdin);
        if (feof(stdin))
            exit(0);

        eval(cmdline);
    }
}


void eval(char *cmdline)
{
    char *argv[MAXARGS];
    char buf[MAXLINE];
    int bg;
    pid_t pid;

    strcpy(buf, cmdline);
    bg = parseline(buf, argv);
    if (argv[0] == NULL)
        return; //ignore empty lines

    if (!builtin_command(argv))
    {
        if ((pid = fork()) == 0)
        {
            if (execve(argv[0], argv, environ) < 0)
            {
                printf("%s command not found.\n", argv[0]);
                exit(0);
            }
        }
        //parent waits
        if (!bg)
        {
            int status;
            if (waitpid(pid, &status, 0) < 0)
                unix_error("waitfg: waitpid error");
        }
        else
        {
            printf("%d %s", pid, cmdline);
        }
    }

    return;
}

int builtin_command(char **argv)
{
    if (!strcmp(argv[0], "quit"))
        exit(0);
    if (!strcmp(argv[0], "&"))
        return 1;

    return 0;
}

int parseline(char *buf, char **argv)
{
    char *delim;
    int argc;
    int bg;

    buf[strlen(buf) - 1] = ' '; //replace trailling '\n' with white space

    while (*buf && (*buf == ' '))
        buf++;

    //bulid argv list
    argc = 0;
    while ((delim = strchr(buf, ' ')))
    {
        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf && (*buf == ' '))
            buf++;
    }
    argv[argc] = NULL;

    if (argc == 0)
        return 1;

    if ((bg = (*argv[argc - 1] == '&')) != 0)
        argv[--argc] = NULL;

    return bg;
}

void unix_error(char *msg) /* Unix-style error */
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(0);
}


