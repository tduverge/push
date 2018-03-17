/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   quick_b.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:21:06 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:21:06 by tduverge    ###    #+. /#+    ###.fr     */
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

static int		select_sort_sens(t_list **b)
{
	t_list		*tmp;
	int			max;
	int			pos[2];
	int			i;
	int			len;

	tmp = *b;
	max = get_elem_max(*b);
	pos[0] = -1;
	i = 0;
	len = ft_lstlen(*b);
	while (tmp)
	{
		if (content(tmp) >= max - 3 && pos[0] == -1)
			pos[0] = i;
		if (content(tmp) >= max - 3)
			pos[1] = i;
		tmp = tmp->next;
		i++;
	}
	return (pos[0] > len - pos[1] ? 1 : 0);
}

static void		select_sort(t_list **a, t_list **b, int *step, int j)
{
	int		max;
	int		sens;
	int		i;

	max = get_elem_max(*b);
	sens = select_sort_sens(b);
	i = 0;
	while (i != 4)
	{
		if (content(*b) >= max - 3)
		{
			apply_actions_pshswp(a, b, PA, "pa\n");
			i += 1;
		}
		else if (sens == 0)
			apply_actions_pshswp(a, b, RB, "rb\n");
		else
			apply_actions_pshswp(a, b, RRB, "rrb\n");
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
	else if (len <= 25)
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
