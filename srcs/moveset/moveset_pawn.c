/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset_pawn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 04:59:15 by home              #+#    #+#             */
/*   Updated: 2021/03/07 15:00:53 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	toggle_pawn_moveset(t_game_state *game_state)
{
	int		i;
	int		try[4];
	int		delta;

	i = screen_to_board(game_state->select_x, game_state->select_y);
	int j = 0;
	while (j < 4)
	{
		try[j] = i;
		j++;
	}

	delta = 1;
	if (game_state->turn % 2 == WHITE_TURN)
		delta = -1;

	move_by(&(try[0]),  0, (delta));
	if ( game_state->map[try[0]] != NONE)
		try[0] = OUT_OF_BOUNDS;

	move_by(&(try[1]),  0, (delta) * 2);
	if (game_state->turn % 2 == WHITE_TURN && i / 8 != 6)
		try[1] = OUT_OF_BOUNDS;
	if (game_state->turn % 2 == BLACK_TURN && i / 8 != 1)
		try[1] = OUT_OF_BOUNDS;

	if (try[0] == OUT_OF_BOUNDS) //if something is in front of the pawn it can't move 2 places
		try[1] = OUT_OF_BOUNDS;

	move_by(&(try[2]), -1, (delta));
	move_by(&(try[3]),  1, (delta));
	if (try[2] != OUT_OF_BOUNDS && game_state->map[try[2]] == NONE)
		try[2] = OUT_OF_BOUNDS;
	if (try[3] != OUT_OF_BOUNDS && game_state->map[try[3]] == NONE)
		try[3] = OUT_OF_BOUNDS;

	i = 0;
	while (i < 4)
	{
		if (try[i] != OUT_OF_BOUNDS)
		{
			game_state->possible_tiles[try[i]] = 1;
			if (same_as_turn(game_state->map[try[i]], game_state->turn) == true)
				game_state->possible_tiles[try[i]] = 0;
		}
		i++;
	}
}
