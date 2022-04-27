/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:56:14 by stissera          #+#    #+#             */
/*   Updated: 2022/04/12 14:43:15 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	size_t	i;
	int		*tab;
	t_stack	*stack_a;

	if (argc < 2)
		exit (0);
	stack_a = NULL;
	argv++;
	i = ft_check_tab_ai(argv, argc);
	tab = (int *)malloc(sizeof(int) * i);
	tab = ps_putarg(argv, tab, argc);
	if (!ps_check_no_db(tab, i))
	{
		free(tab);
		write(1, "Error\n", 6);
		exit(0);
	}
	tab = ps_sorttab(tab, i);
	stack_a = ps_write_struct(tab, i);
	free(tab);
	check_action(stack_a);
	if (stack_a->total != 0)
		ps_free_all(stack_a);
	free(stack_a);
	return (0);
}

void	check_action(t_stack *stack)
{
	t_stack	*stack_b;

	if (ps_check_asc(stack))
		return ;
	stack_b = malloc(sizeof(t_stack) * 1);
	if (!stack_b)
		return ;
	stack_b->total = 0;
	if (stack->total == 2)
	{
		if (stack->first->nbr > stack->first->next->nbr)
			sa(stack);
	}
	else if (stack->total == 3)
		ps_swap_three(stack);
	else if (stack->total == 4 || stack->total == 5)
		ps_swap_ff(stack, stack_b);
	else
	{
		ps_in_action(stack, stack_b);
	}
	free(stack_b);
}

void	ps_free_all(t_stack *stack)
{
	t_node	*tmp;

	stack->first->previous = NULL;
	if (stack->total > 1)
	{
		while (stack->last != NULL)
		{
			if (stack->last->previous != NULL)
				tmp = stack->last->previous;
			else
				tmp = NULL;
			free(stack->last);
			stack->last = tmp;
		}
	}
	else
		free(stack->first);
}

t_stack	*ps_write_struct(int *tab, size_t size)
{
	t_stack	*stack;
	t_node	*tmp;
	size_t	i;

	i = 0;
	stack = malloc(sizeof(t_stack) * 1);
	if (!stack)
		return (0);
	stack->total = size;
	stack->first = ps_do_node(tab[i], NULL);
	tmp = stack->first;
	while (++i < size)
	{
		tmp->next = ps_do_node(tab[i], tmp);
		tmp = tmp->next;
	}
	stack->last = tmp;
	stack->last->next = stack->first;
	stack->first->previous = stack->last;
	return (stack);
}

t_node	*ps_do_node(int value, t_node *prev)
{
	t_node	*new;

	new = malloc(sizeof(t_node) * 1);
	if (!new)
		return (NULL);
	new->nbr = value;
	new->previous = prev;
	if (prev)
		prev->next = new;
	return (new);
}
