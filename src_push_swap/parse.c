/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:21:05 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:21:05 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

static long		ft_atol(const char *str)
{
	long	result;
	char	neg;

	result = 0;
	neg = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = 10 * result + (*str - '0');
		str++;
	}
	return ((long)(result * neg));
}

static int		free_2d(char **numbers)
{
	int		i;

	i = 0;
	while (numbers[i])
		free(numbers[i++]);
	free(numbers);
	return (1);
}

static int		is_not_numeric(char *nb)
{
	unsigned int	i;

	i = 0;
	if (nb[i] && (nb[i] == '-' || (nb[i] >= '0' && nb[i] <= '9')))
		i++;
	while (nb[i])
	{
		if (nb[i] < '0' || nb[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int				not_numeric(t_list **pile, char *arg)
{
	char	**numbers;
	int		i;
	long	nb;
	int		nb_int;

	numbers = ft_strsplit(arg, ' ');
	i = 0;
	while (numbers[i + 1])
		i++;
	while (i >= 0)
	{
		nb = ft_atol(numbers[i]);
		if (nb > 2147483647 || nb < -2147483648 || is_not_numeric(numbers[i]))
			return (free_2d(numbers));
		nb_int = nb;
		if (!(*pile))
			*pile = ft_lstnew((int *)&nb_int, sizeof(int *));
		else
			ft_lstadd(pile, ft_lstnew((int *)&nb_int, sizeof(int *)));
		i--;
	}
	free_2d(numbers);
	return (0);
}

int				got_doubles(t_list **pile)
{
	t_list		*cur;
	t_list		*cmp;

	cur = *pile;
	while (cur)
	{
		cmp = cur->next;
		while (cmp)
		{
			if (*(int *)cur->content == *(int *)cmp->content)
				return (1);
			cmp = cmp->next;
		}
		cur = cur->next;
	}
	return (0);
}
