/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   quick_a.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 15:12:52 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 16:56:54 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

static float	calc_median_a(t_list *lst, int treat)
{
	int		min;
	int		max;

	min = content(lst);
	max = content(lst);
	while (treat--)
	{
		if (content(lst) < min)
			min = content(lst);
		if (content(lst) > max)
			max = content(lst);
		lst = lst->next;
	}
	return ((float)(min + max) / 2);
}

void			change_step_2(t_list **a, t_list **b, int *step, int treat)
{
	int		i;

	i = 0;
	while (step[i + 1])
		i++;
	if (!ft_stepis_sorted(*a, treat))
		apply_actions_pshswp(a, b, SA, "sa\n");
	while (treat--)
		apply_actions_pshswp(a, b, RA, "ra\n");
	step[i] = 0;
	quick_a(a, b, step, 1);
	return ;
}

static void		change_step_3(t_list **a, t_list **b, int *step, int treat)
{
	int		i;

	i = 0;
	while (step[i + 1])
		i++;
	if (ft_stepis_sorted(*a, treat))
		while (treat--)
			apply_actions_pshswp(a, b, RA, "ra\n");
	else
	{
		sort_3(a, b, step);
		return ;
	}
	step[i] = 0;
	quick_a(a, b, step, 1);
	return ;
}

static void		rotate_or_push_a(t_list **a, t_list **b, int c, int *i)
{
	if (!c)
		apply_actions_pshswp(a, b, RA, "ra\n");
	else
		apply_actions_pshswp(a, b, PB, "pb\n");
	(*i)++;
}

void			quick_a(t_list **a, t_list **b, int *step, int test)
{
	int		treat;
	int		i;
	int		j;
	int		k;
	float	median;

	i = 0;
	while (step[i + 1])
		i++;
	treat = step[i];
	median = calc_median_a(*a, treat);
	if (treat == 3)
		change_step_3(a, b, step, treat);
	else if (treat == 2)
		change_step_2(a, b, step, treat);
	j = 0;
	k = 0;
	while (treat-- && k < (step[i] + 1) / 2)
		((float)content(*a)) > median ? rotate_or_push_a(a, b, 0, &j) :
			rotate_or_push_a(a, b, 1, &k);
	step[i] = step[i] / 2;
	while (j-- && test)
		apply_actions_pshswp(a, b, RRA, "rra\n");
	step[0] ? quick_b(a, b, step) : 0;
}
