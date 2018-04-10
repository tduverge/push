/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:22:05 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/10 15:05:23 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void		print_lst(char l, t_list *lst)
{
	ft_putchar(l);
	if (!lst)
	{
		ft_putstr(" : \n");
		return ;
	}
	ft_putstr(" : | ");
	while (lst->next)
	{
		ft_putnbr(*(int *)lst->content);
		ft_putstr(" | ");
		lst = lst->next;
	}
	ft_putnbr(*(int *)lst->content);
	ft_putstr(" |\n");
}

static void		print_cmdpnrr(int cmd)
{
	if (cmd / 10 == 1)
	{
		if (cmd % 10 == 0)
			ft_putstr("pa\n");
		else if (cmd % 10 == 1)
			ft_putstr("pb\n");
	}
	else
	{
		if (cmd % 10 == 0)
			ft_putstr("rra\n");
		else if (cmd % 10 == 1)
			ft_putstr("rrb\n");
		else if (cmd % 10 == 2)
			ft_putstr("rrr\n");
	}
}

static void		print_cmd(int cmd)
{
	if (cmd / 10 == 0)
	{
		if (cmd % 10 == 0)
			ft_putstr("sa\n");
		else if (cmd % 10 == 1)
			ft_putstr("sb\n");
		else
			ft_putstr("ss\n");
	}
	else if (cmd / 10 == 1)
		print_cmdpnrr(cmd);
	else if (cmd / 10 == 2)
	{
		if (cmd % 10 == 0)
			ft_putstr("ra\n");
		else if (cmd % 10 == 1)
			ft_putstr("rb\n");
		else
			ft_putstr("rr\n");
	}
	else if (cmd / 10 == 3)
		print_cmdpnrr(cmd);
}

void			print_lsts(int cmd, t_list *a, t_list *b)
{
	ft_putstr("------------------------------\n");
	print_cmd(cmd);
	print_lst('a', a);
	print_lst('b', b);
	ft_putstr("------------------------------\n");
}
