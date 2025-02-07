NAME_CLIENT  := client
NAME_SERVER  := server
CFLAGS       := -Wextra -Wall -Werror -Wunreachable-code -Ofast -g
LIBFT        := ft_libft

HEADERS      := -I ./include -I $(LIBFT)
LIBS         := -L$(LIBFT) -lft
SRCS_CLIENT  := src/client.c
SRCS_SERVER  := src/server.c
OBJS_CLIENT  := $(SRCS_CLIENT:.c=.o)
OBJS_SERVER  := $(SRCS_SERVER:.c=.o)

all: libft $(NAME_CLIENT) $(NAME_SERVER)

libft:
	make -C $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	@printf "Compilando: $(notdir $<)\n"

$(NAME_CLIENT): $(OBJS_CLIENT) Makefile $(LIBFT)
	$(CC) $(OBJS_CLIENT) $(LIBS) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER) Makefile $(LIBFT)
	$(CC) $(OBJS_SERVER) $(LIBS) -o $(NAME_SERVER)

clean:
	rm -rf $(OBJS_CLIENT) $(OBJS_SERVER)
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME_CLIENT) $(NAME_SERVER)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re libft
