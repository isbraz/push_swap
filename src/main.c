/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:44:14 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/10/24 14:57:16 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	exit_function(t_list **stack_a, int flag)
{
	if (flag == 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_lstclear(stack_a);
		exit(EXIT_FAILURE);
	}
	if (flag == 1)
	{
		ft_lstclear(stack_a);
		exit(EXIT_FAILURE);
	}
}

static void	ft_create_stack(t_list **stack, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		lstadd_back(stack, lstnew(ft_atoi(argv[i])));
		i++;
	}
}

int	main(int ac, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	ft_create_stack(&stack_a, argv);
	if (!ft_check_argv(argv) || check_num(stack_a))
		exit_function(&stack_a, 0);
	if (ft_is_sorted(stack_a))
		exit_function(&stack_a, 1);
	if (ft_lstsize(stack_a) == 2)
		sort_two(&stack_a);
	else if (ft_lstsize(stack_a) == 3)
		sort_three(&stack_a);
	else if (ft_lstsize(stack_a) == 4 || ft_lstsize(stack_a) == 5)
		sort_four_five(&stack_a, &stack_b);
	else if (ft_lstsize(stack_a) > 5)
		ft_radix(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	exit(EXIT_SUCCESS);
}
