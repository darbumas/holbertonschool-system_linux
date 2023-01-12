#include "strace.h"

/**
 * ptrace_child - traces child process
 * @argv: argument vector
 * @env: environ for execve
 * Return: Nothing
 */
void ptrace_child(char **argv, char **env)
{
    ptrace(PTRACE_TRACEME, 0, 0, 0);
    kill(getpid(), SIGSTOP);
    if (execve(argv[1], argv + 1, env) == -1)
    {
        dprintf(STDERR_FILENO, "Execve failed: %d\n", errno);
        exit(-1);
    }
}

/**
 * wait_syscall - waits for a system call
 * @cpid: process id to await
 * Return: 0 if stopped, 1 if exited
 */
int wait_syscall(pid_t cpid)
{
    int stat;

    while (1)
    {
        ptrace(PTRACE_SYSCALL, cpid, 0, 0);
        waitpid(cpid, &stat, 0);
        if (WIFSTOPPED(stat) && WSTOPSIG(stat) & 0x80)
            return (0);
        if (WIFEXITED(stat))
            return (1);
    }
}

/**
 * ptrace_parent - for calls made by tracing parent
 * @cpid: child pid
 * Return: Nothing
 */
void ptrace_parent(pid_t cpid)
{
    int stat;
    struct user_regs_struct uregs;

    waitpid(cpid, &stat, 0);
    ptrace(PTRACE_SETOPTIONS, cpid, 0, PTRACE_O_TRACESYSGOOD);
    while (1)
    {
        if (wait_syscall(cpid))
            break;
        memset(&uregs, 0, sizeof(uregs));
        ptrace(PTRACE_GETREGS, cpid, 0, &uregs);
        printf("%lu\n", (long)uregs.orig_rax);
        if (wait_syscall(cpid))
            break;
    }
}

/**
 * main - program entry point
 * @argc: argument count
 * @argv: argument vector
 * @env: environment
 * Return: EXIT_SUCCESS or error
 */
int main(int argc, char **argv, char **env)
{
    pid_t cpid;

    if (argc < 2)
    {
        printf("Usage: %s command [args...]\n", argv[0]);
        return (EXIT_FAILURE);
    }
    setbuf(stdout, NULL);
    cpid = fork();
    if (cpid == -1)
    {
        dprintf(STDERR_FILENO, "Fork failed: %d\n", errno);
        exit(-1);
    }
    else if (!cpid)
        ptrace_child(argv, env);
    else
        ptrace_parent(cpid);
    return (0);
}
