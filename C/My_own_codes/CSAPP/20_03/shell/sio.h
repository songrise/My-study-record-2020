#include <sys/types.h>
#include <string.h>
#include <unistd.h>

#ifndef _SIO_H
#define _SIO_H
ssize_t Sio_puts(char s[]);
ssize_t Sio_putl(long v);
void Sio_error(char s[]);
#endif