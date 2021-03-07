/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 22:05:38 by home              #+#    #+#             */
/*   Updated: 2020/06/19 00:56:34 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <SDL2/SDL.h>
# include <stdbool.h>

typedef struct	s_display
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
}				t_display;

typedef struct	s_game_state
{
	bool		active;
	int			turn;

	SDL_Texture	*texture;
	SDL_Rect	*src_rect;

	int			map[64];
	int			possible_tiles[64];

//Maybe make this itself a structure.
	int			mouse_x;
	int			mouse_y;

	int			*selected_piece;

	int			select_x;
	int			select_y;

	int			move_to_x;
	int			move_to_y;
}				t_game_state;


#endif
