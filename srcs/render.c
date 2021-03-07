/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 01:17:29 by home              #+#    #+#             */
/*   Updated: 2021/03/07 14:34:26 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	get_loc(int i, int *x, int *y)
{
	*x = i % 8;
	*y = i / 8;

	*y *= 64;
	*x *= 64;
}

void	draw_game_state(t_game_state *game_state, SDLX_Display *display)
{
	int			i;
	int			piece_type;
	SDL_Rect	rect;
	SDL_Rect	src_rect;

	i = 0;
	rect.x = 0;
	rect.y = 0;
	rect.h = 64;
	rect.w = 64;
	while (i < 64)
	{
		if (game_state->map[i] != NONE)
		{
			get_loc(i, &(rect.x), &(rect.y));
			piece_type = game_state->map[i];
			src_rect = game_state->src_rect[piece_type];
			SDL_RenderCopy(display->renderer, game_state->texture, &src_rect, &rect);
		}
		i++;
	}
}

void	draw_hover_tile(t_game_state *game_state, SDLX_Display *display)
{
	SDL_Rect	rect;

	rect.x = (game_state->mouse_x / 64) * 64;
	rect.y = (game_state->mouse_y / 64) * 64;
	rect.h = 64;
	rect.w = 64;
	SDL_RenderCopy(display->renderer, game_state->texture, &(game_state->src_rect[HOVER]), &rect);
}

void	draw_select_tile(t_game_state *game_state, SDLX_Display *display)
{
	SDL_Rect	rect;

	if (game_state->selected_piece == NULL)
		return ;
	rect.x = (game_state->select_x / 64) * 64;
	rect.y = (game_state->select_y / 64) * 64;
	rect.h = 64;
	rect.w = 64;
	SDL_RenderCopy(display->renderer, game_state->texture, &(game_state->src_rect[SELECT]), &rect);
}

void	draw_possible_tiles(t_game_state *game_state, SDLX_Display *display)
{
	int			i;
	SDL_Rect	rect;

	i = 0;
	rect.h = 64;
	rect.w = 64;
	while (i < 64)
	{
		if (game_state->possible_tiles[i] == 1)
		{
			get_loc(i, &(rect.x), &(rect.y));
			SDL_RenderCopy(display->renderer, game_state->texture, &(game_state->src_rect[POSSIBLE]), &rect);
		}
		i++;
	}
}

void	draw_grid(t_game_state *game_state, SDLX_Display *display)
{
	int	i;

	i = 0;
	SDL_SetRenderDrawColor(display->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	while (i < 8)
	{
		SDL_RenderDrawLine(display->renderer, i * 64, 0, i * 64, WIN_HEIGHT);
		SDL_RenderDrawLine(display->renderer, 0, i * 64, WIN_WIDTH, i * 64);
		i++;
	}
	SDL_SetRenderDrawColor(display->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	(void)game_state;
}
