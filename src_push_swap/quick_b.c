/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   quick_b.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 15:24:28 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 14:08:25 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

static float	calc_median_b(t_list *lst)
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
	return ((float)(min + max) / 2);
}

static void		empty_b(t_list **a, t_list **b, int *step, int j)
{
	int		len;

	len = ft_lstlen(*b);
	simple_sort_b(a, b, len);
	step[j] = len;
	step[j + 1] = 0;
	while (len--)
		apply_actions_pshswp(a, b, PA, "pa\n");
	quick_a(a, b, step, 1);
	return ;
}

void			quick_b(t_list **a, t_list **b, int *step)
{
	int		i;
	int		j;
	int		len;
	float	median;

	len = ft_lstlen(*b);
	median = calc_median_b(*b);
	j = 0;
	while (step[j])
		j++;
	if (len <= 3)
		return (empty_b(a, b, step, j));
	i = 0;
	while (i < (len + 1) / 2)
	{
		if ((float)content(*b) >= median && ++i)
			apply_actions_pshswp(a, b, PA, "pa\n");
		else
			apply_actions_pshswp(a, b, RB, "rb\n");
	}
	step[j] = i;
	step[j + 1] = 0;
	ft_lstlen(*b) ? quick_b(a, b, step) : quick_a(a, b, step, 1);
}
