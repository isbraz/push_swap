/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:18:10 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/10/24 14:28:55 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (0);
	while (s[j] == '0' && s[j] != '\0')
		j++;
	while (s[i] != '\0')
		i++;
	return (i - j);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

long long	ft_atoi(char *s)
{
	long long	i;
	long long	res;
	long long	sign;

	i = 0;
	res = 0;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9' && s[i])
	{
		res *= 10;
		res += s[i] - 48;
		i++;
	}
	if ((res * sign) > INT_MAX || (res * sign) < INT_MIN || ft_strlen(s) > 11)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	return (sign * res);
}

int	*list_to_array(t_list *stack)
{
	int	*list;
	int	i;

	i = 0;
	list = malloc(sizeof(int) * ft_lstsize(stack));
	if (!list)
		return (NULL);
	while (stack)
	{
		list[i] = stack->content;
		stack = stack->next;
		i++;
	}
	return (list);
}

int	smallest_number(int *list, int size)
{
	int	i;
	int	smallest;
	int	small_index;

	i = 0;
	small_index = 0;
	smallest = list[i];
	while (i < size)
	{
		if (list[i] < smallest)
		{
			smallest = list[i];
			small_index = i;
		}
		i++;
	}
	return (small_index);
}
