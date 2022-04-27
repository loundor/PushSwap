/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:11:01 by stissera          #+#    #+#             */
/*   Updated: 2022/04/12 01:57:47 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ps_in_action(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	test;
	size_t	move;
	size_t	round;
	int		i;
	int		count;

	i = ps_byte((int)stack_a->total);
	count = -1;
	while (++count < i)
	{
		move = 0;
		round = stack_a->total;
		while (move++ < round)
		{
			test.first = stack_a->first;
			if ((test.first->nbr >> count) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		move = stack_b->total;
		ps_in_action_next(stack_a, stack_b, count, i);
	}
}

void	ps_in_action_next(t_stack *stack_a, t_stack *stack_b, int count, int i)
{
	int		move;
	t_stack	test;

	move = stack_b->total + 1;
	while (--move != 0)
	{
		test.first = stack_b->first;
		if (!((test.first->nbr >> (count + 1)) & 1) && count != i - 1)
		{
			rb(stack_b);
		}
		else
		{
			pa(stack_a, stack_b);
		}
	}
}

int	ps_byte(int i)
{
	int	ret;

	ret = 0;
	while (i >> ret)
		ret++;
	return (ret);
}

void	make_node_check(int func, t_checker_p *checker)
{
	t_checker	*cnode;

	cnode = malloc(sizeof(t_checker) * 1);
	if (!cnode)
		return ;
	cnode->nbr_function = func;
	if (checker->total == 1)
	{
		checker->first = cnode;
		checker->last = cnode;
		checker->total = 2;
	}
	else
	{
		checker->total += 1;
		checker->last->next = cnode;
		checker->last = cnode;
	}
}
