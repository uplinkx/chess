/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 03:50:13 by home              #+#    #+#             */
/*   Updated: 2021/03/07 14:34:26 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	toggle_moveset( t_game_state *game_state)
{
	if (*(game_state->selected_piece) == B_BISHOP || *(game_state->selected_piece) == W_BISHOP)
		toggle_bishop_moveset(game_state);
	else if (*(game_state->selected_piece) == B_HORSE || *(game_state->selected_piece) == W_HORSE)
		toggle_horse_moveset(game_state);
	else if (*(game_state->selected_piece) == B_KING || *(game_state->selected_piece) == W_KING)
		toggle_king_moveset(game_state);
	else if (*(game_state->selected_piece) == B_PAWN || *(game_state->selected_piece) == W_PAWN)
		toggle_pawn_moveset(game_state);
	else if (*(game_state->selected_piece) == B_QUEEN || *(game_state->selected_piece) == W_QUEEN)
		toggle_queen_moveset(game_state);
	else if (*(game_state->selected_piece) == B_ROOK || *(game_state->selected_piece) == W_ROOK)
		toggle_rook_moveset(game_state);
}

void	reset_to_no_selection(t_game_state *game_state)
{
	bzero(game_state->possible_tiles, sizeof(game_state->possible_tiles));
	game_state->selected_piece = NULL;
	game_state->select_x = -1;
	game_state->select_y = -1;

	game_state->move_to_x = -1;
	game_state->move_to_y = -1;
}

bool	valid_selection(t_game_state *game_state)
{
	bool	result;
	int		piece;

	result = false;
	if (game_state->select_x < 0 || game_state->select_y < 0)
		result = false;
	else if (game_state->selected_piece == NULL)
	{
		piece = game_state->map[screen_to_board(game_state->select_x, game_state->select_y)];
		if (game_state->turn % 2 == WHITE_TURN && white_piece(piece) == true)
			result = true;
		if (game_state->turn % 2 == BLACK_TURN && black_piece(piece) == true)
			result = true;
	}
	return (result);
}

bool	move_valid(t_game_state *game_state)
{
	bool	result;
	int		move_to_index;

	result = false;
	if (game_state->move_to_x < 0 || game_state->move_to_y < 0)
		result = false;

	move_to_index = screen_to_board(game_state->move_to_x, game_state->move_to_y);
	if (game_state->possible_tiles[move_to_index] != 0)
		result = true;

	return (result);
}

void	update_game_input(t_game_state *game_state)
{
	if (game_state->selected_piece != NULL && game_state->move_to_x != -1)
	{
		if (move_valid(game_state) == true)
		{
			game_state->map[screen_to_board(game_state->move_to_x, game_state->move_to_y)] = *(game_state->selected_piece);
			*game_state->selected_piece = 0;
			game_state->turn++;
		}
		reset_to_no_selection(game_state);
	}

	if (game_state->selected_piece == NULL)
	{
		if (valid_selection(game_state) == true)
		{
			game_state->selected_piece = &(game_state->map[screen_to_board(game_state->select_x, game_state->select_y)]);
			toggle_moveset(game_state);
		}
		else
			reset_to_no_selection(game_state);
	}
}
