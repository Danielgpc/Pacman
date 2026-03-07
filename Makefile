# Makefile for Pacman

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Isrc -I/opt/homebrew/include/ -D_THREAD_SAFE
LDFLAGS = -L/opt/homebrew/lib -lSDL2 -lSDL2_image

# Directory for object files and executable
OBJDIR = build

# Source files
SRCS = main.c src/video.c

# Object files (now prefixed to go in OBJDIR, with flattened names)
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))

# Tell Make where to find source files
VPATH = .:src

# Executable name
TARGET = $(OBJDIR)/Pacman

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(OBJDIR)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean run
