/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:00:50 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/10/24 14:23:29 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	bubble_sort(int *array, int length)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	get_indexes(int *array, int length)
{
	int	*copy;
	int	index;
	int	j;

	index = -1;
	copy = malloc(sizeof(int) * length);
	if (!copy)
		return ;
	while (++index < length)
		copy[index] = array[index];
	bubble_sort(copy, length);
	index = -1;
	while (++index < length)
	{
		j = -1;
		while (++j < length)
		{
			if (array[index] == copy[j])
				array[index] = j;
		}
	}
	free(copy);
}

void	index_list(t_list **stack)
{
	t_list	*tmp;
	int		*array;
	int		i;

	array = list_to_array(*stack);
	get_indexes(array, ft_lstsize(*stack));
	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->content = array[i++];
		tmp = tmp->next;
	}
	free(array);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
