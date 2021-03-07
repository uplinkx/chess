/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 02:19:41 by home              #+#    #+#             */
/*   Updated: 2021/03/07 14:34:26 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_new_game(int *game_map)
{
	game_map[0] = B_ROOK;
	game_map[1] = B_HORSE;
	game_map[2] = B_BISHOP;
	game_map[3] = B_QUEEN;
	game_map[4] = B_KING;
	game_map[5] = B_BISHOP;
	game_map[6] = B_HORSE;
	game_map[7] = B_ROOK;

	game_map[ 8] = B_PAWN;
	game_map[ 9] = B_PAWN;
	game_map[10] = B_PAWN;
	game_map[11] = B_PAWN;
	game_map[12] = B_PAWN;
	game_map[13] = B_PAWN;
	game_map[14] = B_PAWN;
	game_map[15] = B_PAWN;

	game_map[48] = W_PAWN;
	game_map[49] = W_PAWN;
	game_map[50] = W_PAWN;
	game_map[51] = W_PAWN;
	game_map[52] = W_PAWN;
	game_map[53] = W_PAWN;
	game_map[54] = W_PAWN;
	game_map[55] = W_PAWN;

	game_map[56] = W_ROOK;
	game_map[57] = W_HORSE;
	game_map[58] = W_BISHOP;
	game_map[59] = W_QUEEN;
	game_map[60] = W_KING;
	game_map[61] = W_BISHOP;
	game_map[62] = W_HORSE;
	game_map[63] = W_ROOK;
}
