# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
LDFLAGS = -lreadline
SRCS = pipex.c builtins.c tools.c toolss.c readline.c stack_init.c stack_tools.c enogh.c
OBJS = $(SRCS:.c=.o)
TARGET = my_program  # Replace with your desired output name

# Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
