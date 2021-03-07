/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 21:49:34 by home              #+#    #+#             */
/*   Updated: 2021/03/07 14:34:26 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	white_piece(int piece_ID)
{
	bool	result;

	result = false;
	if (W_PAWN <= piece_ID && piece_ID <= W_KING)
		result = true;
	return (result);
}

bool	black_piece(int piece_ID)
{
	bool	result;

	result = false;
	if (B_PAWN <= piece_ID && piece_ID <= B_KING)
		result = true;
	return (result);
}

bool	same_as_turn(int piece, int turn)
{
	bool	result;

	result = false;
	if (turn % 2 == WHITE_TURN && white_piece(piece) == true)
		result = true;
	if (turn % 2 == BLACK_TURN && black_piece(piece) == true)
		result = true;
	return (result);
}

int		screen_to_board(int x, int y)
{
	int	row;
	int	col;

	col = x / 64;
	row = y / 64;

	return (row * 8 + col);
}

void	move_by(int *dst, int delta_x, int delta_y)
{
	int	x;
	int	y;

	x = *dst % 8 + delta_x;
	y = *dst / 8 + delta_y;
	if (0 <= x && x < 8 &&
		0 <= y && y < 8)
		*dst += delta_y * 8 + delta_x;
	else
		*dst = OUT_OF_BOUNDS;
}
