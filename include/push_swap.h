/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:41:33 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/10/24 14:35:42 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int					content;
	struct s_list		*next;
}			t_list;

//utils functions
int			ft_strlen(const char *s);
long long	ft_atoi(char *s);
int			*list_to_array(t_list *stack);
int			smallest_number(int *list, int size);
void		ft_putstr_fd(char *s, int fd);
void		index_list(t_list **stack);

//check functions
int			ft_is_sorted(t_list *stack);
int			ft_check_argv(char **argv);
int			check_num(t_list *stack);

//list functions
t_list		*lstnew(int content);
void		lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst);
t_list		*lstlast(t_list *lst);
int			ft_lstsize(t_list *lst);
void		lstadd_front(t_list **lst, t_list *new);

//moves functions
void		ft_swap(t_list **stack, char *message);
void		ft_push(t_list **stack_a, t_list **stack_b, char *message);
void		ft_rotate(t_list **stack, char *message);
void		ft_rotate_reverse(t_list **stack, char *message);

//sort functions
void		sort_two(t_list **stack);
void		sort_three(t_list **stack_s);
void		sort_four_five(t_list **stack_s, t_list **stack_r);
void		ft_radix(t_list **stack_s, t_list **stack_r);

#endif