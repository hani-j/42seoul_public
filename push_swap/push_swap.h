/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:05:33 by hjeong            #+#    #+#             */
/*   Updated: 2022/06/23 10:09:25 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				index;
	struct s_node	*prenode;
	struct s_node	*nextnode;
}	t_node;

typedef struct s_stack
{
	int				current_count;
	struct s_node	*topnode;
	struct s_node	*tailnode;
}	t_stack;

int				ft_isdigit(int c);
int				ft_atoi(const char *str);
void			set_astack(t_stack *astack, int *arr, int c);
void			sort_check(int *arr, int num);
void			set_array(t_stack *astack, char **argv, int *arr, int c);

t_node			*create_node(int index);
void			push_node_front(t_stack *stack, t_node *newnode);
void			push_node_back(t_stack *stack, t_node *newnode);
t_node			*pop_node_front(t_stack *stack);
t_node			*pop_node_back(t_stack *stack);

t_stack			*create_stack(void);
void			sa_sb(t_stack *stack, char c);
void			ss(t_stack *astack, t_stack *bstack);
void			pa_pb(t_stack *astack, t_stack *bstack, char c);
void			ra_rb(t_stack *stack, char c);
void			rr(t_stack *astack, t_stack *bstack);
void			rra_rrb(t_stack *stack, char c);
void			rrr(t_stack *astack, t_stack *bstack);

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				ft_count(char const *s, char c);
int				ft_splitlen(char const *s, char c);
char			**ft_splitfree(char **split, int index);
char			**ft_split(char const *s, char c);

void			sort_stack(t_stack *astack, t_stack *bstack);
void			lessthan3(t_stack *astack);
void			lessthan5(t_stack *astack, t_stack *bstack);
void			set012(t_stack *stack, int	*arr);
int				search_node_index(t_stack *stack, int num);

void			morethan5(t_stack *astack, t_stack *bstack);
void			sort_btoa(t_stack *a, t_stack *b);
int				rra_check(t_stack *stack);
void			ra_sort_atob(t_stack *a, t_stack *b, int chunk);
void			rra_sort_atob(t_stack *a, t_stack *b, int chunk);

int				main(int argc, char **argv);
void			print_error(void);
int				arr_count(char **argv);
void			get_command(t_stack *astack, t_stack *bstack);

#endif