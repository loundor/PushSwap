/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fct4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:15:42 by stissera          #+#    #+#             */
/*   Updated: 2022/04/09 20:56:04 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ps_swap_three(t_stack *stack)
{
	if (stack->first->nbr < stack->first->next->nbr
		&& stack->first->next->nbr > stack->first->next->next->nbr)
	{
		if (stack->first->nbr < stack->first->next->next->nbr)
		{
			sa(stack);
			ra(stack);
		}
		if (stack->first->nbr > stack->first->next->next->nbr)
			rra(stack);
	}
	if (stack->first->nbr > stack->first->next->nbr
		&& stack->first->next->nbr < stack->first->next->next->nbr)
	{
		if (stack->first->nbr > stack->first->next->next->nbr)
			ra(stack);
		if (stack->first->nbr > stack->first->next->nbr)
			sa(stack);
	}
	if (stack->first->nbr > stack->first->next->nbr
		&& stack->first->next->nbr > stack->first->next->next->nbr)
	{
		sa(stack);
		rra(stack);
	}
}

void	ps_swap_ff(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (++i <= 2)
	{
		if (rotate_faster(stack_a, i) == 1)
		{
			while (stack_a->first->nbr != i)
				ra(stack_a);
			pb(stack_a, stack_b);
		}
		else
		{
			while (stack_a->first->nbr != i)
				rra(stack_a);
			pb(stack_a, stack_b);
		}
		if (stack_a->total == 3)
			i = 3;
	}
	ps_swap_three(stack_a);
	while (stack_b->total != 0)
		pa(stack_a, stack_b);
}

int	rotate_faster(t_stack *stack, int nbr)
{
	t_stack	test;
	int		a;
	int		b;

	test.first = stack->first;
	test.last = stack->last;
	a = 0;
	b = 0;
	while (test.first->nbr != nbr && test.first->nbr != stack->last->nbr)
	{
		a++;
		test.first = test.first->next;
	}
	test.first = stack->first;
	while (test.first->nbr != nbr && test.first != stack->first->next)
	{
		b++;
		test.first = test.first->previous;
	}
	if (a < b || a == b)
		return (1);
	return (0);
}

int	ps_check_asc(t_stack *stack)
{
	t_stack	tmp;

	tmp.first = stack->first;
	while (tmp.first != stack->last)
	{
		if (tmp.first->nbr > tmp.first->next->nbr)
			return (0);
		tmp.first = tmp.first->next;
	}
	return (1);
}
