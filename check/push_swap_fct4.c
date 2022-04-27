/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fct4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:15:42 by stissera          #+#    #+#             */
/*   Updated: 2022/04/12 01:11:16 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	rrb(t_stack *stack)
{
	rrotate(stack);
}

void	rrr(t_stack *stack, t_stack *stack_b)
{
	rrotate(stack);
	rrotate(stack_b);
}

void	ps_free_all(t_stack *stack)
{
	t_node	*tmp;

	if (stack->total == 0)
		return ;
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
