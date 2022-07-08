#ifndef _SIGNALS_H
#define _SIGNALS_H

#include <signal.h>

int handle_signal(void);
void (*current_handler_signal(void))(int);
int handle_sigaction(void);
void (*current_handler_sigaction(void))(int);
int trace_signal_sender(void);
int pid_exits(pid_t pid);

#endif
