/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 10:48:29 by amaitre           #+#    #+#             */
/*   Updated: 2016/01/21 21:20:56 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int		ft_error(void)
{
	ft_putstr("ERROR\n");
	return (1);
}

void	ft_game_bis(t_board *board)
{
	if (board->odd == 0)
	{
		ft_putstr("Entrer votre nombre: ");
		board->nb = ft_get_int(0);
	}
	else
		board->nb = ft_select_nb(board->array, board->line);
	if (board->odd == 1)
	{
		ft_putstr("Retire: ");
		ft_putnbr(board->nb);
		ft_putstr("\n");
	}
	board->tmp = ft_remouve(board->array, board->line, board->nb);
	if (board->tmp == NULL && board->odd == 0)
		ft_putstr("[\033[31m-- Essaye un autre chiffre --\033[0m]\n\n");
}

void	ft_game(t_board *board)
{
	while (ft_strlen(board->array[0]) > 0)
	{
		board->line = ft_select_line(board->array);
		ft_show_tab(board->array, board->line, 0, 1);
		board->tmp = NULL;
		if (board->odd == 0)
			ft_print(1);
		else
			ft_print(2);
		while (board->tmp == NULL)
			ft_game_bis(board);
		board->array = board->tmp;
		if (board->odd == 1)
			board->odd = 0;
		else
			board->odd = 1;
		ft_putstr("\n\n");
	}
}

int		main(int argc, t_tab argv)
{
	t_board	*board;
	int		created;

	created = 0;
	board = (t_board *)malloc(sizeof(t_board));
	if (argc == 2)
		created = ft_creatlist(1, argv[1], &board);
	else if (argc == 1)
		created = ft_creatlist(0, argv[1], &board);
	if (created == 0)
		return (ft_error());
	board = ft_init(*(board->lst));
	if (board == NULL)
		return (ft_error());
	ft_print(0);
	ft_game(board);
	if (board->odd == 0)
		ft_lose_win(0);
	else
		ft_lose_win(1);
	return (0);
}
