CC = gcc
CFLAGS = -I./include -Wall -Wextra

SRCS = src/parser/parser.c main.c
OBJS = $(SRCS:.c=.o)
TARGET = fscheck

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)