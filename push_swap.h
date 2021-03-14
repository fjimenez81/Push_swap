/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 09:30:15 by fjimenez          #+#    #+#             */
/*   Updated: 2021/03/14 20:52:18 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "GNL/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct		s_stack
{
	int				elem;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_stacks
{
	t_stack			*a;
	t_stack			*b;
	char			**args;
	int				len;
	int				min;
	int				max;
}					t_stacks;

int					ft_parse_args(int ac, char **av, t_stacks *sts);
int					ft_create_node(char *s, t_stacks *sts);
int					ft_check_digit(char *s);
void				ft_free_tab(char **s);
void				ft_free_stack(t_stacks *sts);
t_stack				*ft_get_last_node(t_stack *st);
int					ft_check_duplicate(t_stack *check, int val);
void				ft_push_back(t_stack **sts, t_stack *new);
void				ft_push_front(t_stack **first, t_stack *second);
t_stack				*ft_pop_front(t_stack **st);
t_stack				*ft_pop_back(t_stack **st);
int					ft_handle_s(t_stack **st, char *s);
int					ft_handle_p(t_stack **first, t_stack **second, char *s);
int					ft_handle_r(t_stack **st, char *s);
int					ft_handle_rr(t_stack **st, char *s);
int					ft_check_maxnum(t_stack *st);
int					ft_check_minnum(t_stack *st);
int64_t				ft_ctm_atoi(const char *s);
int					ft_sorted(t_stack *st, int flag);
int					ft_stack_size(t_stack *st);
void				ft_search_min(t_stacks *sts);
void				ft_sort_three(t_stacks *sts);
void				ft_sort_fourty(t_stacks *sts);
void				ft_check_stb(t_stacks *sts);
void				ft_check_sta(t_stacks *sts);
void				ft_change_stack_a(t_stacks *sts, int max);
void				ft_change_stack_b(t_stacks *sts, int max);
int					ft_search_max(t_stacks *sts, int flag);

#endif
