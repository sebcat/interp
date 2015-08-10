CC=clang
SRCS=interp.c syscalls.c main.c
OBJS=$(SRCS:.c=.o)
CFLAGS?=-Wall -Os
TARGET=bc

.PHONY: clean

all: $(TARGET)

$(OBJS): $(SRCS)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -s -nostdlib -mstackrealign -o $(TARGET) $(OBJS)

clean:
	$(RM) $(OBJS) bc
