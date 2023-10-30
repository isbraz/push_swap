/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorte_large.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:24:28 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/10/24 14:23:16 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_max(int len)
{
	int	length;
	int	max;

	max = 1;
	length = len;
	while ((length / 2) > 0) 
	{
		length /= 2;
		max++;
	}
	return (max);
}

void	ft_radix(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		len;
	int		max;
	int		i;
	int		j;

	index_list(stack_a);
	len = ft_lstsize(*stack_a);
	max = get_max(len);
	i = -1;
	while (++i < max)
	{
		j = -1;
		while (++j < len)
		{
			tmp = *stack_a;
			if ((tmp->content >> i) & 1)
				ft_rotate(stack_a, "ra\n");
			else
				ft_push(stack_a, stack_b, "pb\n");
		}
		while (ft_lstsize(*stack_b) != 0)
			ft_push(stack_b, stack_a, "pa\n");
	}
}
