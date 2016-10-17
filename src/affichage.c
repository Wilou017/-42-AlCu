/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:08:37 by amaitre           #+#    #+#             */
/*   Updated: 2015/12/21 21:29:06 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void		ft_print(int i)
{
	if (i == 0)
	{
		ft_putstr("\033[96m          ',ggg,              ,gggg,\n");
		ft_putstr("         dP\"\"8I   ,dPYb,   ,88\"\"\"Y8b, Par: Aaverty\n");
		ft_putstr("         dP   88   IP'`Yb  d8\"     `Y8      et Amaitre\n");
		ft_putstr("        dP    88   I8  8I d8'   8b  d8\n");
		ft_putstr("       ,8'    88   I8  8',8I    \"Y88P'\n");
		ft_putstr("       d88888888   I8 dP I8'           gg      gg \n");
		ft_putstr(" __   ,8\"     88   I8dP  d8            I8      8I \n");
		ft_putstr("dP\"  ,8P      Y8   I8P   Y8,           I8,    ,8I \n");
		ft_putstr("Yb,_,dP       `8b,,d8b,_ `Yba,,_____, ,d8b,  ,d8b,\n");
		ft_putstr(" \"Y8P\"         `Y88P'\"Y88  `\"Y8888888 8P'\"Y88P\"`Y8");
		ft_putstr("\033[0m\n");
		return ;
	}
	else if (i == 1)
	{
		ft_putstr("[\033[92m------------------------------\033[0m]\n");
		ft_putstr("[\033[92m-------- A TON TOUR ----------\033[0m]\n");
		ft_putstr("[\033[92m------------------------------\033[0m]\n\n");
		return ;
	}
	ft_putstr("[\033[94m------------------------------\033[0m]  ()\n");
	ft_putstr("[\033[94m-------- A SON TOUR ----------\033[0m] /__\\\n");
	ft_putstr("[\033[94m------------------------------\033[0m]  ||\n\n");
}

void		ft_lose_win(int i)
{
	if (i == 0)
	{
		ft_putstr("\033[42m                              \033[0m\n");
		ft_putstr("\033[42m         \033[30mTu Gagnes !\033[48m          ");
		ft_putstr("\033[0m\n");
		ft_putstr("\033[42m                              \033[0m\033[0m\n\n");
	}
	else
	{
		ft_putstr("\033[41m                              \033[0m\n");
		ft_putstr("\033[41m          \033[30mTu Perds !\033[48m          ");
		ft_putstr("\033[0m\n");
		ft_putstr("\033[41m                              \033[0m\033[0m\n\n");
	}
}

int			ft_get_int(int stream)
{
	int		r;
	int		nb;
	char	str[12];
	int		i;

	r = 0;
	nb = 0;
	i = 0;
	r = read(stream, str, 12);
	if (r < 0)
		ft_putstr("read error");
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (i == 1)
		nb = ft_atoi(str);
	return (nb);
}
