/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carve_chess_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 00:56:57 by home              #+#    #+#             */
/*   Updated: 2021/03/07 14:34:26 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

SDL_Rect	*carve_chess_texture()
{
	int			col;
	int			row;
	SDL_Rect	*result;

	row = 0;
	result = malloc(sizeof(*result) * (8 * 2));
	while (row < 2)
	{
		col = 0;
		while (col < 8)
		{
			result[row * 8 + col].h = 16;
			result[row * 8 + col].w = 16;
			result[row * 8 + col].x = (col * 16);
			result[row * 8 + col].y = (row * 16);
			col++;
		}
		row++;
	}

	return (result);
}
