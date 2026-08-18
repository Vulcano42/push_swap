/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thialima <thialima@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 22:58:41 by thialima          #+#    #+#             */
/*   Updated: 2026/08/15 23:28:17 by thialima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	disorder_bp(t_stack *a)
{
	long	mistakes;
	long	pairs;
	int		i;
	int		j;

	pairs = (long)a->size * (a->size - 1) / 2;
	if (pairs == 0)
		return (0);
	mistakes = 0;
	i = -1;
	while (++i < a->size)
	{
		j = i;
		while (++j < a->size)
			if (a->v[i] > a->v[j])
				mistakes++;
	}
	return ((int)((mistakes * 10000 + pairs / 2) / pairs));
}
