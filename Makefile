# Variables
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Source files for mandatory part
SRCS = \
ft_printf.c \
handler.c \
handler2.c \
utils.c

# Source files for bonus part
BONUS_SRCS = \
file1_bonus.c \
file2_bonus.c \
file3_bonus.c

# Object files
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# libft directory
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_OBJS = $(patsubst $(LIBFT_DIR)/%.c, %.o, $(wildcard $(LIBFT_DIR)/*.c))

# Default rule
all: $(NAME)

# Compile libft and create the main archive
$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT) .
	@ar x $(LIBFT)  # Extract object files from libft.a
	@echo "Creating $(NAME) with object files:"
	@echo "$(AR) $(NAME) $(OBJS) *.o"  # Echo the ar command
	@$(AR) $(NAME) $(OBJS) *.o  # Combine libft objects with ft_printf objects
	@rm -f *.o  # Clean up extracted libft object files

# Bonus rule
bonus: $(OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT) .
	@ar x $(LIBFT)  # Extract object files from libft.a
	@echo "Creating $(NAME) with object files:"
	@echo "$(AR) $(NAME) $(OBJS) $(BONUS_OBJS) *.o"  # Echo the ar command
	@$(AR) $(NAME) $(OBJS) $(BONUS_OBJS) *.o
	@rm -f *.o

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

# Clean everything, including the library
fclean: clean
	$(RM) $(NAME) $(LIBFT)
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild everything from scratch
re: fclean all

.PHONY: all clean fclean re bonus
