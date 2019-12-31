/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 09:31:45 by hopham            #+#    #+#             */
/*   Updated: 2019/10/22 19:56:18 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		n_size(unsigned int nb)
{
	unsigned int	size;

	size = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		size++;
	}
	return (size + 1);
}

char			*ft_itoa(int n)
{
	char			*str;
	unsigned int	len;
	unsigned int	i;
	unsigned int	nb;

	nb = (n >= 0) ? (unsigned int)n : (unsigned int)(n * -1);
	len = n_size(nb);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1 + (n < 0 ? 1 : 0)))))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		len++;
	}
	i = len - 1;
	while (nb >= 10)
	{
		str[i--] = nb % 10 + '0';
		nb = nb / 10;
	}
	str[i] = nb % 10 + '0';
	str[len] = '\0';
	return (str);
}
