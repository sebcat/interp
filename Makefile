CC=clang
RM?=rm -f
SRCS=interp.c syscalls.c main.c
OBJS=$(SRCS:.c=.o)
CFLAGS?=-Wall -Os
TARGET=bc

.PHONY: clean

all: $(TARGET) $(TARGET)_stripped

$(OBJS): $(SRCS)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -nostdlib -mstackrealign -o $(TARGET) $(OBJS)

$(TARGET)_stripped: $(TARGET)
	strip -s -R .note.gnu.build-id -R .eh_frame_hdr -R .eh_frame -R .comment -o $(TARGET)_stripped $(TARGET)

clean:
	$(RM) $(OBJS) $(TARGET) $(TARGET)_stripped
