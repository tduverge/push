/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   premade_moves.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:21:05 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:21:05 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

int		premade_rr(t_list **a, t_list **b)
{
	if (ft_lstlen(*a) < 2 || ft_lstlen(*b) < 2)
		return (0);
	if (content(*a) < content((*a)->next) && content(*b) > content((*b)->next))
		apply_actions_pshswp(a, b, RR, "rr\n");
	else if (content(*a) > content((*a)->next))
		apply_actions_pshswp(a, b, RA, "ra\n");
	else if (content(*b) > content((*b)->next))
		apply_actions_pshswp(a, b, RB, "rb\n");
	return (1);
}

int		premade_ss(t_list **a, t_list **b)
{
	if (ft_lstlen(*a) < 2 || ft_lstlen(*b) < 2)
		return (0);
	if (content(*a) > content((*a)->next) && content(*b) < content((*b)->next))
		apply_actions_pshswp(a, b, SS, "ss\n");
	else if (content(*a) > content((*a)->next))
		apply_actions_pshswp(a, b, SA, "sa\n");
	else if (*b && content(*b) < content((*b)->next))
		apply_actions_pshswp(a, b, SB, "sb\n");
	return (1);
}
