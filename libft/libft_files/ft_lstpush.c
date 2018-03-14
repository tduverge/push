/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstpush.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 10:02:09 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 10:09:22 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	t_list		*cur;

	cur = *alst;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}
