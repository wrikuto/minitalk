CLIENT		= client
SERVER		= SERVER
SRC_C		= client.c
SRC_S		= server.c
OBJ_C		= $(SRC_C:.c=.o)
OBJ_S		= $(SRC_S:.c=.o)

FLAGS		= -Wall -Werror -Wextra
RM			= rm -f

all: $(SERVER) $(CLIENT)

$()