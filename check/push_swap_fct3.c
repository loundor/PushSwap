/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fct3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:48:31 by stissera          #+#    #+#             */
/*   Updated: 2022/04/12 01:07:08 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
}

void	ra(t_stack *stack)
{
	rotate(stack);
}

void	rb(t_stack *stack)
{
	rotate(stack);
}

void	rr(t_stack *stack, t_stack *stack_b)
{
	rotate(stack);
	rotate(stack_b);
}

void	rra(t_stack *stack)
{
	rrotate(stack);
}
