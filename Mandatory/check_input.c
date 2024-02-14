/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:04:30 by moel-fat          #+#    #+#             */
/*   Updated: 2024/02/14 10:23:11 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_int(char **args)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (args[i])
	{
		if (!ft_strlen(args[i]))
			ft_print_err();
		j = 0;
		if ((args[i][j] == '-' || args[i][j] == '+') && args[i][j + 1])
			j++;
		while (args[i][j])
		{
			if (args[i][j] < '0' || args [i][j] > '9')
			{
				ft_print_err();
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

long int	ft_atoil(char *str)
{
	int			i;
	int			sign;
	long int	rest;

	i = 0;
	rest = 0;
	sign = 1;
	while (str[i] != '\0' && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		rest = rest * 10 + (str[i] - '0');
		if (rest > 2147483648 && sign == -1)
			ft_print_err();
		if (rest > INT_MAX && sign == 1)
			ft_print_err();
		i++;
	}
	return (rest * sign);
}

int	check_dup(t_stack *stack, int nbr)
{
	while (stack)
	{
		if (stack->data == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}
