<<<<<<< HEAD
#ifndef _SIGNALS_H
#define _SIGNALS_H

#include <signal.h>
=======
#ifndef SIGNALS_H
#define SIGNALS_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
>>>>>>> ee705a90ba363a1ff994a480a9d1043763fdaad3

int handle_signal(void);
void (*current_handler_signal(void))(int);
int handle_sigaction(void);
void (*current_handler_sigaction(void))(int);
int trace_signal_sender(void);
<<<<<<< HEAD
int pid_exits(pid_t pid);
=======
int pid_exist(pid_t pid);
>>>>>>> ee705a90ba363a1ff994a480a9d1043763fdaad3

#endif
