/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 22:56:31 by home              #+#    #+#             */
/*   Updated: 2021/03/07 14:34:26 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	process_user_input(t_game_state *game_state)
{
	SDL_Event		e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
			game_state->active = false;
		else if (e.type == SDL_MOUSEMOTION)
			SDL_GetMouseState(&(game_state->mouse_x), &(game_state->mouse_y));
		else if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			if (e.button.button == SDL_BUTTON_LEFT && game_state->selected_piece == NULL)
				SDL_GetMouseState(&(game_state->select_x), &(game_state->select_y));
			else if (e.button.button == SDL_BUTTON_LEFT && game_state->selected_piece != NULL)
				SDL_GetMouseState(&(game_state->move_to_x), &(game_state->move_to_y));
		}
	}
}
