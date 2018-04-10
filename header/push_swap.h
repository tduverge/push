/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 20:30:45 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/10 17:00:33 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/header/libft.h"
# include "../minilibx_macos/mlx.h"

# define SA 0
# define SB 1
# define SS 2
# define PA 10
# define PB 11
# define RA 20
# define RB 21
# define RR 22
# define RRA 30
# define RRB 31
# define RRR 32

typedef struct	s_param
{
	void			*mlx;
	void			*win;
	void			*img;
	int				max;
	int				elem;
	int				nb;
	char			v;
	char			g;
	char			stop;
	char			end;
	t_list			**a;
	t_list			**b;
	t_list			*commands;
}				t_param;
/*
 ** Parse functions
*/
int				not_numeric(t_list **pile, char *arg);
int				got_doubles(t_list **pile);

/*
 ** Action functions
*/
void			swap_pile(t_list **p);
void			push_pile(t_list **dst, t_list **src);
void			rotate_pile(t_list **p);
void			revrot_pile(t_list **p);
void			apply_actions(t_list **a, t_list **b, t_param *p);
void			apply_actions_pshswp(t_list **a, t_list **b, int cmd, char *v);
void			change_to_index(t_list *a);
int				premade_ss(t_list **a, t_list **b);
int				premade_rr(t_list **a, t_list **b);

/*
 ** Sort functions
*/
void			insertion_sort(t_list **a, t_list **b);
void			simple_sort(t_list **a, t_list **b, int len);
void			simple_sort_b(t_list **a, t_list **b, int len);
void			only_need_rotate(t_list **a, t_list **b, int len);
void			quicksort(t_list **a, t_list **b);
void			quick_a(t_list **a, t_list **b, int *step, int test);
void			quick_b(t_list **a, t_list **b, int *step);
void			change_step_2(t_list **a, t_list **b);
void			change_step_3(t_list **a, t_list **b);
void			change_step_4(t_list **a, t_list **b, int treat);

/*
 ** Getters
*/
int				content(t_list *lst);
int				get_elem(t_list *pile, int elem);
int				get_elem_first(t_list *pile);
int				get_elem_last(t_list *pile);
int				get_elem_min(t_list *pile);
int				get_elem_max(t_list *pile);

/*
 ** IO functions
*/
int				ft_is_sorted(t_list *pile);
int				ft_stepis_sorted(t_list *pile, int n);
int				ft_lstis_sorted(t_list *pile);
int				ft_lstis_inorder(t_list *pile);
int				ft_lstis_sorted_b(t_list *pile);
int				ft_lstis_inorder_b(t_list *pile);
int				is_valid_input(char *cmd);
void			print_lsts(int cmd, t_list *a, t_list *b);
int				graphic(t_list *a, t_list *b, t_param *p);
int				loop_funct(void *param);
int				key_funct(int keycode, void *param);
int				one_step(void *param);
void			option_g(t_list **a, t_list **b, t_param *p);
void			not_option_g(t_list **a, t_list **b, t_param *p);
float			calc_median_b(t_list *lst);
void			genius_insert(t_list **a, t_list **b);
void			empty_b(t_list **a, t_list **b, int *step, int j);
void			one_insert(t_list **a, t_list **b);
int				where_insert(t_list **b, int value);
int				how_many(t_list **a, t_list **b, int pos_in_a, int pos_in_b);

#endif
