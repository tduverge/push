/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   insertion_sort.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:21:05 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:21:05 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void		get_to(t_list **a, t_list **b, int i, int rev)
{
	if (rev)
		while (i--)
			apply_actions_pshswp(a, b, RRA, "rra\n");
	else if (i != -1)
		while (i--)
			apply_actions_pshswp(a, b, RA, "ra\n");
	else
		ft_printf("i is incorrect\n");
	apply_actions_pshswp(a, b, PB, "pb\n");
}

static void		nearest_between(t_list **a, t_list **b, int x, int y)
{
	int			i;
	int			j;
	int			len;
	int			rev;

	rev = 0;
	i = get_elem(*a, x);
	j = get_elem(*a, y);
	len = ft_lstlen(*a);
	if (i <= j && i != -1 && i > len - i)
	{
		i = len - i;
		rev = 1;
	}
	if (i > j && j != -1 && j > len - j)
	{
		j = len - j;
		rev = 1;
	}
	if (i != -1 && (j == -1 || i <= j))
		get_to(a, b, i, rev);
	else
		get_to(a, b, j, rev);
}

void			insertion_sort(t_list **a, t_list **b)
{
	nearest_between(a, b, get_elem_min(*a), get_elem_min(*a) + 1);
	nearest_between(a, b, get_elem_min(*a), -1);
	premade_ss(a, b);
	simple_sort(a, b, ft_lstlen(*a));
	apply_actions_pshswp(a, b, PA, "pa\n");
	apply_actions_pshswp(a, b, PA, "pa\n");
}
