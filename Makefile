CC = clang
override CFLAGS += -g -Wall -Wextra

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
OBJS = $(patsubst %.c, %.o, $(SRCS))

TorreDeHanoi: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o TorreDeHanoi.out

clean:
	rm -f $(OBJS) TorreDeHanoi.out
