/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 17:40:46 by sechang           #+#    #+#             */
/*   Updated: 2018/09/29 20:26:19 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	placepiece(t_data *data, int xp, int yp)
{
	int		i;
	int		x;
	int		y;
	int		hck;

	hck = 100;
	i = -1;
	while (++i < data->bp_i && (y = -1))
		while (++y < data->p_y && (x = -1))
			while (++x < data->p_x)
				if (data->hmap[data->bp_y[i] + y][data->
						bp_x[i] + x] < hck)
				{
					xp = data->bp_x[i];
					yp = data->bp_y[i];
					hck = data->hmap[data->bp_y[i] + y][data->
						bp_x[i] + x];
				}
	ft_printf("%d %d\n", yp, xp);
}

int		alldircheck(t_data *data, int y, int x, int heatnum)
{
	int		row;
	int		col;
	int		success;
	int		k;

	k = (data->k == 1) ? 0 : 1;
	success = 0;
	col = -1;
	while (col <= 1)
	{
		row = -1;
		while (row <= 1)
		{
			if (data->hmap[y + col][x + row] == '.')
			{
				data->hmap[y + col][x + row] = heatnum;
				data->bh_y[k][data->bh_index[k]] = y + col;
				data->bh_x[k][data->bh_index[k]++] = x + row;
				success = 1;
			}
			row++;
		}
		col++;
	}
	return (success == 1) ? 1 : 0;
}

int		heatmap_it(t_data *data)
{
	int		i;
	char	heatnum;
	int		complete;

	data->k = 0;
	heatnum = 2;
	complete = 1;
	memcpy(data->hmap, data->map, 10000);
	while (complete)
	{
		i = 0;
		complete = 0;
		while (i < data->bh_index[data->k])
		{
			complete = complete + alldircheck(data, data->bh_y[data->k][i],
					data->bh_x[data->k][i], heatnum);
			i++;
		}
		data->k = (data->k == 1) ? 0 : 1;
		heatnum++;
	}
	return (0);
}

int		piece_map_check(t_data *data, int i, int y, int x)
{
	int		pby;
	int		pbx;
	int		xi;
	int		yi;
	int		counter;

	counter = 0;
	yi = -1;
	while (++yi < data->p_y && (xi = -1))
	{
		pby = data->b_y[i] - (data->p_y - 1) + yi + y;
		while (++xi < data->p_x)
		{
			pbx = data->b_x[i] - (data->p_x - 1) + xi + x;
			if (data->piece[yi][xi] == '*' && ((data->map[pby][pbx] == data->ox_b ||
				data->map[pby][pbx] == data->bigox_b) || pby >= data->m_y ||
					pbx >= data->m_x || pby < 0 || pbx < 0))
				counter = 100;
			else if (data->piece[yi][xi] == '*' && (data->map[pby][pbx] == data->ox
				|| data->map[pby][pbx] == data->bigox))
				counter++;
		}
	}
	return (counter == 1) ? (1) : (0);
}

int		piece_to_bound(t_data *data)
{
	int		i;
	int		y;
	int		x;

	i = -1;
	while (++i < data->b_index && (y = -1))
		while (++y < data->p_y && (x = -1))
			while (++x < data->p_x)
			{
				if (data->piece[(data->p_y - 1) - y][(data->p_x - 1) - x]
						== '*' && piece_map_check(data, i, y, x) == 1)
				{
					data->bp_y[data->bp_i] = (data->b_y[i] -
							((data->p_y - 1) - y));
					data->bp_x[data->bp_i] = (data->b_x[i] -
							((data->p_x - 1) - x));
					(data->bp_i)++;
				}
			}
	return (0);
}
