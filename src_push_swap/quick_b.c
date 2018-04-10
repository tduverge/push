/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   quick_b.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:21:06 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/10 15:52:44 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

float			calc_median_b(t_list *lst)
{
	int		min;
	int		max;

	min = content(lst);
	max = content(lst);
	while (lst)
	{
		if (content(lst) < min)
			min = content(lst);
		if (content(lst) > max)
			max = content(lst);
		lst = lst->next;
	}
	return ((float)(max + min) / 2);
}

static void		select_sort(t_list **a, t_list **b, int *step, int j)
{
	int		max;
	int		i;

	max = get_elem_max(*b);
	i = 0;
	while (i != 4)
	{
		if (content(*b) >= max - 3)
		{
			apply_actions_pshswp(a, b, PA, "pa\n");
			i += 1;
		}
		else
			apply_actions_pshswp(a, b, RB, "rrb\n");
	}
	step[j] = i;
	step[j + 1] = 0;
	ft_lstlen(*b) ? quick_b(a, b, step) : quick_a(a, b, step, 1);
}

void			quick_b(t_list **a, t_list **b, int *step)
{
	int		i;
	int		j;
	int		len;
	float	median;

	len = ft_lstlen(*b);
	if (!len)
		quick_a(a, b, step, 1);
	median = calc_median_b(*b);
	j = 0;
	while (step[j])
		j++;
	if (len <= 3)
		return (empty_b(a, b, step, j));
	else if (len <= 2)
		return (select_sort(a, b, step, j));
	i = 0;
	while (i < len / 2)
		if ((float)content(*b) > median && ++i)
			apply_actions_pshswp(a, b, PA, "pa\n");
		else
			apply_actions_pshswp(a, b, RB, "rb\n");
	step[j] = i;
	step[j + 1] = 0;
	ft_lstlen(*b) ? quick_b(a, b, step) : quick_a(a, b, step, 1);
}
