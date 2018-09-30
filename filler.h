/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 22:22:11 by sechang           #+#    #+#             */
/*   Updated: 2018/09/29 17:08:23 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "Libft/inc/libft.h"

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
	char			b_x[10000];
	char			b_y[10000];
	int				b_index;
	char			bh_x[2][10000];
	char			bh_y[2][10000];
	int				bh_index[2];
	char			bp_x[10000];
	char			bp_y[10000];
	char			hmap[100][100];
	int				bp_i;
	int				k;
	int				slp;
}					t_data;

void				store_map(char *line, t_data *data);
void				store_piece(char *line, t_data *data, int i);
void				store_piece_norm(t_data *data, int k, char *s, int i);
void				init_player(t_data *data, char s);
int					scan_map_piece(t_data *data, int k, char *s, int i);
int					piece_map_check(t_data *data, int i, int y, int x);
int					piece_to_bound(t_data *data);
int					bound_dir_scana(t_data *data, int y, int x);
void				analyze_boundary(t_data *data, int y, int x);
void				placepiece(t_data *data, int xp, int yp);
int					alldircheck(t_data *data, int y, int x, int heatnum);
int					heatmap_it(t_data *data);
int					filler_initall(t_data *data);
void				filler_initzero(t_data *data);
void				visualise(int option);
void				visvis(t_data *data);

#endif
