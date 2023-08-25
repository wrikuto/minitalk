CLIENT		= client
SERVER		= server
LIBFT		= ./libft/libft.a
PRINTF		= ./ft_printf/libftprintf.a
SRC_C		= client.c
SRC_S		= server.c
OBJ_C		= $(SRC_C:.c=.o)
OBJ_S		= $(SRC_S:.c=.o)

CC			= cc
FLAGS		= -Wall -Werror -Wextra
RM			= rm -f

all: $(SERVER) $(CLIENT)

$(SERVER) $(CLIENT): $(OBJ_C) $(OBJ_S) $(LIBFT) $(PRINTF)
		${CC} ${FLAGS} ${OBJ_S} ${LIBFT} ${PRINTF} -o ${SERVER}
		${CC} ${FLAGS} ${OBJ_C} ${LIBFT} ${PRINTF} -o ${CLIENT}

$(LIBFT):
		$(MAKE) -C ./libft

$(PRINTF):
		$(MAKE) -C ./ft_printf

clean:
		$(MAKE) clean -C ./libft
		$(MAKE) clean -C ./ft_printf
		rm -f *.o

fclean: clean
		$(MAKE) fclean -C ./libft
		$(MAKE) fclean -C ./ft_printf
		rm -f $(CLIENT) $(SERVER)

re:		fclean all

.PHONY: all clean fclean re
