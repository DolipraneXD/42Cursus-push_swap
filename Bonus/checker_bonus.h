/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:14:30 by moel-fat          #+#    #+#             */
/*   Updated: 2024/02/09 10:44:14 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "get_next_line.h"
# include "../libft/libft.h"

// **stack struct**
typedef struct s_stack
{
	int				data;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

// **Build Stack**
t_stack		*buildstack(int ac, char **av);
t_stack		*ft_lstnewstack(int data);
void		ft_lstadd_backstack(t_stack **lst, t_stack *new);
t_stack		*ft_lstlaststack(t_stack *lst);
int			ft_lstsizestack(t_stack *lst);
t_stack		*ft_lstbeforelast(t_stack *lst);
void		split_fill(t_stack **stack, char *av);

//**Rules bonus**
void		push_bonus(t_stack **from, t_stack **to);
void		pa_bonus(t_stack **a, t_stack **b);
void		pb_bonus(t_stack **a, t_stack **b);
void		rotate_bonus(t_stack **stack);
void		ra_bonus(t_stack **a);
void		rb_bonus(t_stack **b);
void		rr_bonus(t_stack **a, t_stack **b);
void		r_rotate_bonus(t_stack **stack);
void		rra_bonus(t_stack **a);
void		rrb_bonus(t_stack **b);
void		rrr_bonus(t_stack **a, t_stack **b);
void		swap_bonus(t_stack *stack);
void		sa_bonus(t_stack **a);
void		sb_bonus(t_stack **b);
void		ss_bonus(t_stack **a, t_stack **b);

// **utils**
void		ft_free(char **args);
void		free_stack(t_stack **stack);
void		free_everything(t_stack **a, t_stack **b);
void		check_space(char *str);
int			check_sorted(t_stack *stack);

// **Parssing tools**
void		ft_print_err(void);
int			ft_check_int(char **args);
long int	ft_atoil(char *str);
int			check_dup(t_stack *stack, int nbr);
int			ft_strcmp(char *s1, char *s2);
#endif