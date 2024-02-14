/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:14:09 by moel-fat          #+#    #+#             */
/*   Updated: 2024/02/09 10:44:55 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	applytherole(t_stack **a, t_stack **b, char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		sa_bonus(a);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb_bonus(b);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss_bonus(a, b);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa_bonus(a, b);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb_bonus(a, b);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra_bonus(a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb_bonus(b);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr_bonus(a, b);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra_bonus(a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb_bonus(b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr_bonus(a, b);
	else
		ft_print_err();
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*str;

	if (ac < 2)
		return (0);
	b = NULL;
	a = buildstack(ac, av);
	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		applytherole(&a, &b, str);
	}
	if (check_sorted(a) && (b == NULL))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free(str);
	free_everything(&a, &b);
}
