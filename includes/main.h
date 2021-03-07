/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 22:41:24 by home              #+#    #+#             */
/*   Updated: 2021/03/07 14:44:13 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <string.h>

# include <SDL2/SDL.h>
# include <SDL_image.h>

# include "SDLX.h"

# include "structs.h"
# include "piece_id.h"

void		SDLU_start(SDLX_Display *dest);
void		SDLU_close(SDLX_Display *display);

SDL_Rect	*carve_chess_texture(void);

void		set_new_game(int *game_map);

void		draw_game_state(t_game_state *game_state, SDLX_Display *display);
void		draw_hover_tile(t_game_state *game_state, SDLX_Display *display);
void		draw_select_tile(t_game_state *game_state, SDLX_Display *display);
void		draw_possible_tiles(t_game_state *game_state, SDLX_Display *display);
void		draw_grid(t_game_state *game_state, SDLX_Display *display);

void		toggle_pawn_moveset(t_game_state *game_state);
void		toggle_rook_moveset(t_game_state *game_state);
void		toggle_horse_moveset(t_game_state *game_state);
void		toggle_bishop_moveset(t_game_state *game_state);
void		toggle_queen_moveset(t_game_state *game_state);
void		toggle_king_moveset(t_game_state *game_state);

void		update_game_input(t_game_state *game_state);

void		process_user_input(t_game_state *game_state);

bool		black_piece(int piece_ID);
bool		white_piece(int piece_ID);
bool		same_as_turn(int piece, int turn);
int			screen_to_board(int x, int y);
void		move_by(int *dst, int delta_x, int delta_y);

#endif
