/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset_bishop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 04:59:15 by home              #+#    #+#             */
/*   Updated: 2021/03/07 14:34:26 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	toggle_bishop_moveset(t_game_state *game_state)
{
	int		i;
	int		try;

	i = screen_to_board(game_state->select_x, game_state->select_y);
	try = i;
	move_by(&try, -1, -1);
	while (try != OUT_OF_BOUNDS)
	{
		if (game_state->map[try] != NONE)
		{
			if (same_as_turn(game_state->map[try], game_state->turn) == false)
				game_state->possible_tiles[try] = 1;
			break ;
		}
		game_state->possible_tiles[try] = 1;
		move_by(&try, -1, -1);
	}
	try = i;
	move_by(&try, 1, -1);
	while (try != OUT_OF_BOUNDS)
	{
		if (game_state->map[try] != NONE)
		{
			if (same_as_turn(game_state->map[try], game_state->turn) == false)
				game_state->possible_tiles[try] = 1;
			break ;
		}
		game_state->possible_tiles[try] = 1;
		move_by(&try, 1, -1);
	}
	try = i;
	move_by(&try, 1, 1);
	while (try != OUT_OF_BOUNDS)
	{
		if (game_state->map[try] != NONE)
		{
			if (same_as_turn(game_state->map[try], game_state->turn) == false)
				game_state->possible_tiles[try] = 1;
			break ;
		}
		game_state->possible_tiles[try] = 1;
		move_by(&try, 1, 1);
	}
	try = i;
	move_by(&try, -1, 1);
	while (try != OUT_OF_BOUNDS)
	{
		if (game_state->map[try] != NONE)
		{
			if (same_as_turn(game_state->map[try], game_state->turn) == false)
				game_state->possible_tiles[try] = 1;
			break ;
		}
		game_state->possible_tiles[try] = 1;
		move_by(&try, -1, 1);
	}
}
