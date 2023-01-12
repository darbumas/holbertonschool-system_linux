CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -g -std=gnu99
CTAGS = ctags
TAGS = .tags
RM = rm -f
.PHONY: all clean distclean tags strace_0 strace_1 strace_2 strace_3

all: strace_0 strace_1 strace_2 strace_3

clean:
	$(RM) strace_0 strace_1 strace_2 strace_3

distclean: clean
	$(RM) $(TAGS)

tags:
	$(CTAGS) -f $(TAGS) -R

strace_0: SRC/strace_0.c
		$(CC) $(CFLAGS) $^ -o $@

strace_1: SRC/strace_1.c
		$(CC) $(CFLAGS) $^ -o $@

strace_2: SRC/strace_2.c
		$(CC) $(CFLAGS) $^ -o $@

strace_3: SRC/strace_3.c
		$(CC) $(CFLAGS) $^ -o $@
