/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_id.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 02:07:48 by home              #+#    #+#             */
/*   Updated: 2020/06/19 01:03:15 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIECE_ID_H
# define PIECE_ID_H

# define NONE		(0)

# define HOVER		(1)
# define POSSIBLE	(8)
# define SELECT		(9)

# define W_PAWN		(2)
# define W_ROOK		(3)
# define W_HORSE	(4)
# define W_BISHOP	(5)
# define W_QUEEN	(6)
# define W_KING		(7)

# define B_PAWN		(10)
# define B_ROOK		(11)
# define B_HORSE	(12)
# define B_BISHOP	(13)
# define B_QUEEN	(14)
# define B_KING		(15)

# define WHITE_TURN (0)
# define BLACK_TURN (1)

# define OUT_OF_BOUNDS (-1)

#endif
