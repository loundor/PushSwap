/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 10:57:48 by stissera          #+#    #+#             */
/*   Updated: 2022/04/14 14:14:59 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ps_check_no_db(int *tab, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		while (j < len)
		{
			if (tab[j] == tab[i] && j != i)
				return ((int)0);
			j++;
		}
		i++;
		j = 0;
	}
	return ((int)1);
}

int	*ps_putarg(char **argv, int *tab, int argc)
{
	char	**tabchar;
	size_t	i;

	i = 0;
	if (argc == 2)
	{
		tabchar = ft_split(argv[0], ' ');
		tab = ps_putarg_next(tabchar, tab);
		while (tabchar[i])
		{
			free(tabchar[i]);
			i++;
		}
		free(tabchar);
	}
	else
	{
		tabchar = argv;
		tab = ps_putarg_next(tabchar, tab);
	}
	return (tab);
}

int	*ps_putarg_next(char **argv, int *tab)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		tab[i] = ft_atoi(argv[i]);
		if (argv[i][0] == '-' && tab[i] >= 0)
		{
			free(tab);
			write(1, "Error\n", 6);
			exit (0);
		}
		if (argv[i][0] != '-' && tab[i] < 0)
		{
			free(tab);
			write(1, "Error\n", 6);
			exit (0);
		}
		i++;
	}
	return (tab);
}

size_t	ft_check_tab_ai(char **arg, int argc)
{
	char	**tab;
	size_t	ret;
	size_t	i;

	i = 0;
	if (argc == 2)
	{
		tab = ft_split(arg[0], ' ');
		ret = ft_check_tab_ai_nbr(tab);
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	else
	{
		tab = arg;
		ret = ft_check_tab_ai_nbr(tab);
	}
	return (ret);
}

size_t	ft_check_tab_ai_nbr(char **arg)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (arg[i])
	{
		if (arg[i][j] == '-' || arg[i][j] == '+' || arg[i][j] == 0)
			j++;
		while (arg[i][j] != '\0')
		{
			if (!(arg[i][j] >= 48 && arg[i][j] <= 57))
			{
				write(1, "Error\n", 6);
				exit (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (i);
}
