/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:49:06 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:49:11 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	char *cursor;
	long neg;
	long nb;

	neg = 1;
	nb = 0;
	cursor = (char *)str;
	while ((*cursor <= 13 && *cursor >= 9) || *cursor == ' ')
		cursor++;
	if (*cursor == '-' || *cursor == '+')
	{
		if (*cursor == '-')
			neg = -1;
		cursor++;
	}
	while (*cursor <= '9' && *cursor >= '0')
	{
		nb = 10 * nb + *cursor - '0';
		cursor++;
	}
	return ((int)(nb * neg));
}
