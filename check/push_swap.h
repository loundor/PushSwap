/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:53:47 by stissera          #+#    #+#             */
/*   Updated: 2022/04/12 14:53:41 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				nbr;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_stack
{
	size_t			total;
	struct s_node	*first;
	struct s_node	*last;

}	t_stack;

typedef struct s_checker
{
	int					nbr_function;
	struct s_checker	*next;
}	t_checker;

typedef struct s_checker_p
{
	size_t				total;
	struct s_checker	*first;
	struct s_checker	*last;

}	t_checker_p;

size_t	ft_check_tab_ai(char **arg, int argc);
size_t	ft_check_tab_ai_nbr(char **arg);
int		*ps_sorttab(int *tab, size_t nbr);
void	ps_sorttab_next(size_t nbr, int *cpy);
int		*ps_putarg(char **argv, int	*tab, int argc);
int		*ps_putarg_next(char **argv, int *tab);
int		ps_check_no_db(int *tab, size_t len);
t_stack	*ps_write_struct(int *tab, size_t size);
t_node	*ps_do_node(int value, t_node *prev);
void	ps_free_all(t_stack *stack);
void	swap(t_stack *stack);
void	push(t_stack *stack_a, t_stack *stack_b);
void	push_step2(t_stack *b, t_node *tmp, t_node *tmp2);
void	push_step3(t_stack *b, t_node *tmp);
void	rotate(t_stack *stack);
void	rrotate(t_stack *stack);
void	ps_in_action(t_stack *stack_a, t_stack *stack_b);
void	ps_in_action_next(t_stack *stack_a, t_stack *stack_b, int count, int i);
int		ps_byte(int i);
void	check_action(t_stack *stack);
void	ps_swap_three(t_stack *stack);
void	ps_swap_ff(t_stack *stack_a, t_stack *stack_b);
int		rotate_faster(t_stack *stack, int nbr);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack, t_stack *stack_b);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack, t_stack *stack_b);
void	ps_check(t_stack *a);
int		add_check_node(char *b, t_checker_p *checker, t_stack *a, int i);
void	make_node_check(int func, t_checker_p *checker);
void	do_list(t_stack *a, t_stack *b, t_checker_p *check);
int		is_sort(t_stack *a);
int		ps_check_asc(t_stack *stack);
void	ps_free_all_chk(t_checker_p *stack);
int		take_error(t_stack *a, t_checker_p *check, int i);

#endif