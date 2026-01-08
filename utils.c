/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baharrou <baharrou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 10:20:06 by baharrou          #+#    #+#             */
/*   Updated: 2026/01/07 09:53:21 by baharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_free_stack(t_list *stack_a)
{
	t_list	*tmp;

	while (stack_a)
	{
		tmp = stack_a;
		stack_a = stack_a->next;
		free(tmp);
	}
}

void	ft_free_all(char **str, t_list *stack_a)
{
	if (str)
		ft_free(str);
	if (stack_a)
		ft_free_stack(stack_a);
}

long	ft_atol(char *str)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}

t_list	*ft_min(t_list *stack_a)
{
	long long	min;
	t_list		*node;

	min = LONG_MAX;
	node = NULL;
	while (stack_a)
	{
		if (stack_a->digit < min)
		{
			min = stack_a->digit;
			node = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (node);
}
