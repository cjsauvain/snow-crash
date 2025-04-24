NAME_S=server
NAME_C=client

OBJS_DIR= obj

SRCS_S = server.c
SRCS_C = client.c

OBJS_S=$(SRCS_S:%.c=$(OBJS_DIR)/%.o)
OBJS_C=$(SRCS_C:%.c=$(OBJS_DIR)/%.o)

$(OBJS_DIR)/%.o: %.c
	gcc -g -c $< -o $@

all: $(NAME_S) $(NAME_C)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(NAME_S): $(OBJS_DIR) $(OBJS_S)
	gcc $(OBJS_S) -o $(NAME_S) -g

$(NAME_C): $(OBJS_DIR) $(OBJS_C)
	gcc $(OBJS_C) -o $(NAME_C) -g

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME_S) $(NAME_C)

re: fclean all
