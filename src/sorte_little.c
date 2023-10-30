/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorte_little.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:51:53 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/10/24 14:23:20 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	moves_five(t_list **stack_s, t_list **stack_r, int pos_small)
{
	if (pos_small == 0)
		ft_push(stack_s, stack_r, "pb\n");
	else if (pos_small == 1)
	{
		ft_swap(stack_s, "sa\n");
		ft_push(stack_s, stack_r, "pb\n");
	}
	else if (pos_small == 2)
	{
		ft_rotate(stack_s, "ra\n");
		ft_rotate(stack_s, "ra\n");
		ft_push(stack_s, stack_r, "pb\n");
	}
	else if (pos_small == 3)
	{
		ft_rotate_reverse(stack_s, "rra\n");
		ft_rotate_reverse(stack_s, "rra\n");
		ft_push(stack_s, stack_r, "pb\n");
	}
	else if (pos_small == 4)
	{
		ft_rotate_reverse(stack_s, "rra\n");
		ft_push(stack_s, stack_r, "pb\n");
	}
}

static void	moves_four(t_list **stack_s, t_list **stack_r, int pos_small)
{
	if (pos_small == 0)
		ft_push(stack_s, stack_r, "pb\n");
	else if (pos_small == 1)
	{
		ft_swap(stack_s, "sa\n");
		ft_push(stack_s, stack_r, "pb\n");
	}
	else if (pos_small == 2)
	{
		ft_rotate(stack_s, "ra\n");
		ft_rotate(stack_s, "ra\n");
		ft_push(stack_s, stack_r, "pb\n");
	}
	else if (pos_small == 3)
	{
		ft_rotate_reverse(stack_s, "rra\n");
		ft_push(stack_s, stack_r, "pb\n");
	}
}

void	sort_two(t_list **stack)
{
	int	a;
	int	b;

	a = (*stack)->content;
	b = (*stack)->next->content;
	if (a > b)
		ft_swap(stack, "sa\n");
}

void	sort_three(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->content;
	b = (*stack)->next->content;
	c = (*stack)->next->next->content;
	if (a > b && b < c && a < c)
		ft_swap(stack, "sa\n");
	else if (a > b && b > c && a > c)
	{
		ft_rotate(stack, "ra\n");
		ft_swap(stack, "sa\n");
	}
	else if (a < b && b > c && a < c)
	{
		ft_rotate_reverse(stack, "rra\n");
		ft_swap(stack, "sa\n");
	}
	else if (a > b && b < c && a > c)
		ft_rotate(stack, "ra\n");
	else if (a < b && b > c && a > c)
		ft_rotate_reverse(stack, "rra\n");
}

void	sort_four_five(t_list **stack_s, t_list **stack_r)
{
	int	*list;
	int	pos_small;
	int	size;

	size = ft_lstsize(*stack_s);
	list = list_to_array(*stack_s);
	pos_small = smallest_number(list, size);
	if (size == 4)
	{
		moves_four(stack_s, stack_r, pos_small);
		sort_three(stack_s);
	}
	else if (size == 5)
	{
		moves_five(stack_s, stack_r, pos_small);
		size = ft_lstsize(*stack_s);
		free(list);
		list = list_to_array(*stack_s);
		pos_small = smallest_number(list, size);
		moves_four(stack_s, stack_r, pos_small);
		sort_three(stack_s);
		ft_push(stack_r, stack_s, "pa\n");
	}
	ft_push(stack_r, stack_s, "pa\n");
	free(list);
}
