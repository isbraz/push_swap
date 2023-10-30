/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:10:11 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/10/24 14:23:01 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_num(t_list *stack)
{
	t_list	*current;
	t_list	*runner;

	current = stack;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->content == runner->content)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

int	ft_is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_check_argv(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		if ((argv[i][0] == '-' || argv[i][0] == '+') \
		&& ft_strlen(argv[i]) == 1)
			return (0);
		j = 0;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
