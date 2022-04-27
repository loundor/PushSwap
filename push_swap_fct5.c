/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fct6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:13:30 by stissera          #+#    #+#             */
/*   Updated: 2022/04/14 14:15:03 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ps_sorttab(int *tab, size_t nbr)
{
	size_t	index;
	size_t	i;
	int		*cpy;

	cpy = (int *)malloc(sizeof(int) * nbr);
	if (!nbr)
		return (0);
	index = 0;
	while (index < nbr)
	{
		cpy[index] = tab[index];
		index++;
	}
	ps_sorttab_next(nbr, cpy);
	index = -1;
	i = 0;
	while (++index < nbr)
	{
		while (tab[index] != cpy[i])
			i++;
		tab[index] = i + 1;
		i = 0;
	}
	free(cpy);
	return (tab);
}

void	ps_sorttab_next(size_t nbr, int *cpy)
{
	int		tmp;
	size_t	index;

	tmp = 0;
	index = 0;
	while (index < nbr - 1)
	{
		if (cpy[index] > cpy[index + 1])
		{
			tmp = cpy[index];
			cpy[index] = cpy[index + 1];
			cpy[index + 1] = tmp;
			index = 0;
			continue ;
		}
		index++;
	}
}
