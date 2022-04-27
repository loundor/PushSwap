/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:54:19 by stissera          #+#    #+#             */
/*   Updated: 2022/04/12 00:41:45 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->first->nbr;
	stack->first->nbr = stack->first->next->nbr;
	stack->first->next->nbr = tmp;
}

void	push(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = stack_a->first;
	tmp2 = NULL;
	if (stack_a->total > 1)
	{
		stack_a->last->next = stack_a->first->next;
		stack_a->first->next->previous = stack_a->last;
		stack_a->first = stack_a->first->next;
		stack_a->total--;
	}
	else
	{
		stack_a->first = NULL;
		stack_a->last = NULL;
		stack_a->total = 0;
	}
	push_step2(stack_b, tmp, tmp2);
}

void	push_step2(t_stack *b, t_node *tmp, t_node *tmp2)
{
	if (b->total < 2)
	{
		if (b->total == 0)
		{
			b->first = tmp;
			b->first->previous = b->first;
			b->first->next = b->first;
		}
		else
		{
			tmp2 = b->first;
			b->first = tmp;
			b->last = tmp2;
			b->first->next = b->last;
			b->first->previous = b->last;
			b->last->next = b->first;
			b->last->previous = b->first;
		}
		b->total++;
	}
	else
	{
		push_step3(b, tmp);
	}
}

void	push_step3(t_stack *b, t_node *tmp)
{
		tmp->next = b->first;
		tmp->previous = b->last;
		b->first = tmp;
		b->last->next = b->first;
		b->first->next->previous = b->first;
		b->total++;
}

void	rotate(t_stack *stack)
{
	stack->first = stack->first->next;
	stack->last = stack->last->next;
}
