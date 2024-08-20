CC = gcc
override CFLAGS += -g -Wno-everything

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
OBJS = $(patsubst %.c, %.o, $(SRCS))

main:
	#$(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o tower

clean:
	rm -f $(OBJS) tower
