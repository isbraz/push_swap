/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:46:41 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/10/24 14:23:13 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_list **stack, char *message)
{
	t_list	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	ft_putstr_fd(message, 1);
}

void	ft_push(t_list **stack_s, t_list **stack_r, char *message)
{
	t_list	*tmp;

	if (!*stack_s)
		return ;
	tmp = *stack_s;
	*stack_s = (*stack_s)->next;
	tmp->next = *stack_r;
	*stack_r = tmp;
	ft_putstr_fd(message, 1);
}

void	ft_rotate(t_list **stack, char *message)
{
	t_list	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	lstadd_back(stack, tmp);
	tmp->next = NULL;
	ft_putstr_fd(message, 1);
}

void	ft_rotate_reverse(t_list **stack, char *message)
{
	t_list	*last;
	t_list	*first;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = lstlast(*stack);
	while (first->next->next)
		first = first->next;
	first->next = NULL;
	lstadd_front(stack, last);
	ft_putstr_fd(message, 1);
}
