/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:56:14 by stissera          #+#    #+#             */
/*   Updated: 2022/04/12 14:53:45 by stissera         ###   ########.fr       */
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
	ps_check(stack_a);
	ps_free_all(stack_a);
	free(stack_a);
	return (0);
}

void	ps_check(t_stack *a)
{
	t_checker_p	checker;
	t_stack		b;
	char		buff[128];
	int			i;

	i = 1;
	b.total = 0;
	checker.total = 1;
	while (i != 0)
	{
		ft_memset(buff, '\0', 127);
		i = read(0, buff, 127);
		i = add_check_node(buff, &checker, a, i);
	}
	while (--checker.total != 0)
	{
		do_list(a, &b, &checker);
	}
	checker.first = checker.last;
	if (b.total != 0 || !ps_check_asc(a))
		write(1, "KO\n", 3);
	else if (ps_check_asc(a))
		write(1, "OK\n", 3);
	ps_free_all(&b);
	ps_free_all_chk(&checker);
}

void	do_list(t_stack *a, t_stack *b, t_checker_p *check)
{
	if (check->first->nbr_function == 1)
		sa(a);
	else if (check->first->nbr_function == 2)
		sb(b);
	else if (check->first->nbr_function == 3)
		ss(a, b);
	else if (check->first->nbr_function == 4)
		pa(b, a);
	else if (check->first->nbr_function == 5)
		pb(a, b);
	else if (check->first->nbr_function == 6)
		ra(a);
	else if (check->first->nbr_function == 7)
		rb(b);
	else if (check->first->nbr_function == 8)
		rr(a, b);
	else if (check->first->nbr_function == 9)
		rra(a);
	else if (check->first->nbr_function == 10)
		rrb(b);
	else if (check->first->nbr_function == 11)
		rrr(a, b);
	check->first = check->first->next;
}

int	take_error(t_stack *a, t_checker_p *check, int i)
{
	if (i != 0)
	{
		ps_free_all(a);
		check->total--;
		ps_free_all_chk(check);
		free(a);
		exit(0);
	}
	return (0);
}

int	add_check_node(char *b, t_checker_p *checker, t_stack *a, int i)
{
	if (b[0] == 's' && b[1] == 'a' && b[2] == '\n')
		make_node_check(1, checker);
	else if (b[0] == 's' && b[1] == 'b' && b[2] == '\n')
		make_node_check(2, checker);
	else if (b[0] == 's' && b[1] == 's' && b[2] == '\n')
		make_node_check(3, checker);
	else if (b[0] == 'p' && b[1] == 'a' && b[2] == '\n')
		make_node_check(4, checker);
	else if (b[0] == 'p' && b[1] == 'b' && b[2] == '\n')
		make_node_check(5, checker);
	else if (b[0] == 'r' && b[1] == 'a' && b[2] == '\n')
		make_node_check(6, checker);
	else if (b[0] == 'r' && b[1] == 'b' && b[2] == '\n')
		make_node_check(7, checker);
	else if (b[0] == 'r' && b[1] == 'r' && b[2] == '\n')
		make_node_check(8, checker);
	else if (b[0] == 'r' && b[1] == 'r' && b[2] == 'a' && b[3] == '\n')
		make_node_check(9, checker);
	else if (b[0] == 'r' && b[1] == 'r' && b[2] == 'b' && b[3] == '\n')
		make_node_check(10, checker);
	else if (b[0] == 'r' && b[1] == 'r' && b[2] == 'r' && b[3] == '\n')
		make_node_check(11, checker);
	else
		return (take_error(a, checker, i));
	return (1);
}
