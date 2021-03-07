/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 22:40:46 by home              #+#    #+#             */
/*   Updated: 2021/03/07 15:25:24 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <emscripten.h>

void	game_state_initialize(t_game_state *game_state, SDLX_Display *display)
{
	game_state->active = true;
	game_state->texture = IMG_LoadTexture(display->renderer, "resources/chess_texture.png");
	bzero(game_state->map, sizeof(game_state->map));
	bzero(game_state->map, sizeof(game_state->possible_tiles));

	set_new_game(game_state->map);

	game_state->src_rect = carve_chess_texture();

	game_state->turn = 0;

	game_state->selected_piece = NULL;
	game_state->select_x = -1;
	game_state->select_y = -1;

	game_state->move_to_x = -1;
	game_state->move_to_y = -1;
}

void	main_loop(void *v_cxt)
{
	t_game_state	*cxt;
	SDLX_Display	*display;

	cxt = v_cxt;
	display = SDLX_GetDisplay();
	process_user_input(cxt);
	update_game_input(cxt);

	draw_game_state(cxt, display);
	draw_grid(cxt, display);
	draw_hover_tile(cxt, display);
	draw_select_tile(cxt, display);
	draw_possible_tiles(cxt, display);

	SDL_RenderPresent(display->renderer);
	SDL_RenderClear(display->renderer);
}

int	main(void)
{
	SDLX_Display		*display;
	t_game_state		cxt;

	printf("White goes first!\n");
	printf("Castling, pawn promotion, and en passant aren't yet implemented.\n");

	display = SDLX_GetDisplay();
	game_state_initialize(&cxt, display);
	emscripten_set_main_loop_arg(main_loop, (void *)&(cxt), 60, SDL_TRUE);
	return (0);
}
