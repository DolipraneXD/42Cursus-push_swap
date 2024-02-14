/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:20:10 by moel-fat          #+#    #+#             */
/*   Updated: 2024/02/14 20:05:06 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	split_fill(t_stack **stack, char *av)
{
	char		**holder;
	int			i;
	int			j;
	long int	nbr;

	holder = NULL;
	i = 0;
	j = -1;
	holder = ft_split(av, ' ');
	while (holder[i])
		i++;
	while (++j < i)
	{
		ft_check_int(holder);
		nbr = ft_atoil(holder[j]);
		if (check_dup(*stack, (int)nbr))
			ft_print_err();
		else if (check_dup(*stack, (int)nbr))
			ft_print_err();
		else
			ft_lstadd_backstack(stack, ft_lstnewstack((int)nbr));
	}
	ft_free(holder);
}

t_stack	*buildstack(int ac, char **av)
{
	t_stack		*a;
	int			i;

	i = 1;
	a = NULL;
	while (i < ac)
	{
		check_space(av[i]);
		split_fill(&a, av[i]);
		i++;
	}
	return (a);
}
