/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 15:48:00 by amaitre           #+#    #+#             */
/*   Updated: 2016/01/04 00:14:08 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int nb)
{
	int len;

	len = 0;
	if (nb < 0)
	{
		len = 1;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}