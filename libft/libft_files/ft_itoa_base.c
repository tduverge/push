/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:50:29 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:50:29 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

static int		ft_len(long n, int base)
{
	int i;
	int save;

	i = 0;
	if (n < 0 && base == 10)
	{
		n = -n;
		i = 1;
	}
	else if (n < 0)
	{
		n = 2147483648 + n;
		save = (int)n;
		n = save;
	}
	if (n < base)
		return (1 + i);
	return (1 + i + ft_len(n / base, base));
}

static void		ft_putnbr_in_tab(long n, int base, int len, char *res)
{
	if (n >= base)
		ft_putnbr_in_tab(n / base, base, len - 1, res);
	if (n % base < 10)
		res[len - 1] = n % base + '0';
	else
		res[len - 1] = n % base + 'A' - 10;
}

char			*ft_itoa_base(int value, int base)
{
	int		len;
	char	*res;
	long	n;
	int		save;

	n = value;
	len = ft_len(n, base);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	res[len] = '\0';
	if (n < 0 && base == 10)
	{
		n = -n;
		res[0] = '-';
	}
	else if (n < 0)
	{
		n = 2147483648 + n;
		save = (int)n;
		n = save;
	}
	ft_putnbr_in_tab(n, base, len, res);
	return (res);
}
