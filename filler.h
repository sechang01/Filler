/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 22:22:11 by sechang           #+#    #+#             */
/*   Updated: 2018/09/26 14:52:01 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "Get_next_line/get_next_line.h"

typedef struct		s_data
{
	char			map[100][100];
	char			piece[100][100];
	int				m_x;
	int				m_y;
	int				p_x;
	int				p_y;
	int				pa_x;
	int				pa_y;
	char			player;
	char			ox;
	char			bigox;
	char			ox_b;
	char			bigox_b;
	char			b_x[5000];
	char			b_y[5000];
	int				b_index;
	char			bh_x[2][5000];
	char			bh_y[2][5000];
	int				bh_index[2];
	char			bp_x[5000];
	char			bp_y[5000];
	char			hmap[100][100];
	int				bp_i;
	int				k;
}					t_data;

int					store_map(char *line, t_data *data);
int					store_piece(char *line, t_data *data, int i);
int					scan_map_piece(t_data *data);


#endif
