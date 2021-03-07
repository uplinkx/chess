/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset_horse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 04:59:15 by home              #+#    #+#             */
/*   Updated: 2021/03/07 15:00:18 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	toggle_horse_moveset(t_game_state *game_state)
{
	Uint32		i;
	int		try[8];

	i = screen_to_board(game_state->select_x, game_state->select_y);
	int j = 0;
	while (j < 8)
	{
		try[j] = i;
		j++;
	}

	move_by(&(try[0]), -1, -2);
	move_by(&(try[1]),  1, -2);

	move_by(&(try[2]), -2, -1);
	move_by(&(try[3]),  2, -1);

	move_by(&(try[4]), -2,  1);
	move_by(&(try[5]),  2,  1);

	move_by(&(try[6]), -1,  2);
	move_by(&(try[7]),  1,  2);

	i = 0;
	while (i < 8)
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
