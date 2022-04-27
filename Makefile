LIBFT_DIR	= 	./libft
LIBFT		= 	$(LIBFT_DIR)/libft.a

CC			= 	gcc
FLAGS		= 	-Wall -Werror -Wextra

# PUSHSWAP
NAME		= 	push_swap
SRCS		= 	push_swap_sort.c \
				push_swap_utils.c \
				push_swap_fct.c \
				push_swap_fct2.c \
				push_swap_fct3.c \
				push_swap_fct4.c \
				push_swap_fct5.c \
				push_swap.c
OBJS		= 	$(addprefix ./, ${SRCS:.c=.o})
HEADER		= 	-I./ -I$(LIBFT_DIR)

# BONUS
NAMEB		=	checker
SRCSB		=	push_swap_sort.c \
				push_swap_utils.c \
				push_swap_fct.c \
				push_swap_fct2.c \
				push_swap_fct3.c \
				push_swap_fct4.c \
				push_swap_fct5.c \
				push_swap_fct6.c \
				checker.c
OBJSB		=	$(addprefix ./check/, ${SRCSB:.c=.o})
# HEADERB		=	-I./checker -I$(LIBFT_DIR)

.c.o	:
			${CC} ${FLAGS} -c ${HEADER} $< -o ${<:.c=.o}

$(NAME)	:	${OBJS} $(LIBFT)
			$(CC) $(FLAGS) -I./ $(OBJS) ${LIBFT} -o $@

$(NAMEB):	${OBJSB} ${LIBFT}
			$(CC) $(FLAGS) -I./ $(OBJSB) $(LIBFT) -o $@

$(LIBFT):
			make -C $(LIBFT_DIR)

all		: 	${NAME}

bonus	:	all ${NAMEB}

clean	:
			make clean -C $(LIBFT_DIR)
			rm -f ${OBJS}
			rm -f ${OBJSB}

fclean	:	clean
			make fclean -C $(LIBFT_DIR)
			rm -f ${NAME}
			rm -f ${NAMEB}

re		:	fclean all

.PHONY	:	all clean fclean re
