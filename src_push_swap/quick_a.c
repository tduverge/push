/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   quick_a.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 15:12:52 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 22:36:58 by tduverge    ###    #+. /#+    ###.fr     */
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
	int		j;

	i = 0;
	j = 2;
	while (step[i + 1])
		i++;
	if (!ft_stepis_sorted(*a, 2))
		apply_actions_pshswp(a, b, SA, "sa\n");
	while (j--)
		apply_actions_pshswp(a, b, RA, "ra\n");
	step[i] = 0;
	treat == 2 ? quick_a(a, b, step, 1) : 0;
	return ;
}

static void		change_step_3(t_list **a, t_list **b, int *step, int treat)
{
	int		i;
	int		j;

	i = 0;
	j = 3;
	while (step[i + 1])
		i++;
	if (ft_stepis_sorted(*a, 3))
		while (j--)
			apply_actions_pshswp(a, b, RA, "ra\n");
	else
		sort_3(a, b, step);
	step[i] = 0;
	treat == 3 ? quick_a(a, b, step, 1) : 0;
	return ;
}

static void		change_step_4(t_list **a, t_list **b, int *step, int treat)
{
	int		max;
	int		min;
	t_list	*tmp;

	tmp = *a;
	max = content(tmp);
	min = content(tmp);
	while (treat--)
	{
		if (content(tmp) > max)
			max = content(tmp);
		if (content(tmp) < min)
			min = content(tmp);
		tmp = tmp->next;
	}
	if (content(*a) == min || content((*a)->next) == min)
	{
		if (content((*a)->next) == min)
			apply_actions_pshswp(a, b, SA, "sa\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
		change_step_3(a, b, step, 4);
	}
	else if (content(*a) == max || content((*a)->next) == max)
	{
		if (content((*a)->next) == max)
			apply_actions_pshswp(a, b, SA, "sa\n");
		apply_actions_pshswp(a, b, PB, "pb\n");
		change_step_3(a, b, step, 4);
		apply_actions_pshswp(a, b, PA, "pa\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
	}
	else
	{
		apply_actions_pshswp(a, b, PB, "pb\n");
		apply_actions_pshswp(a, b, PB, "pb\n");
		if (content(*b) < content((*b)->next))
		{
			if (content(*a) == max)
				apply_actions_pshswp(a, b, SS, "ss\n");
			else
				apply_actions_pshswp(a, b, SB, "sb\n");
		}
		if (content(*a) == max)
			apply_actions_pshswp(a, b, SA, "sa\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
		apply_actions_pshswp(a, b, PA, "pa\n");
		apply_actions_pshswp(a, b, PA, "pa\n");
		change_step_3(a, b, step, 4);
	}
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
	if (treat == 4)
	{
		change_step_4(a, b, step, treat);
		return ;
	}
	else if (treat == 3)
	{
		change_step_3(a, b, step, treat);
		return ;
	}
	else if (treat == 2)
	{
		change_step_2(a, b, step, treat);
		return ;
	}
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
