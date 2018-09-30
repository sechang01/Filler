/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 20:23:55 by sechang           #+#    #+#             */
/*   Updated: 2018/09/29 20:24:57 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		bound_dir_scana(t_data *data, int y, int x)
{
	if (y == 0)
	{
		if (data->map[y + data->m_y - 1][x] == '.')
			return (1);
	}
	else
	{
		if (data->map[y - 1][x] == '.')
			return (1);
	}
	if (data->map[y][x + 1] == '.')
		return (1);
	if (data->map[y + 1][x] == '.')
		return (1);
	if (x == 0)
	{
		if (data->map[y][data->m_x - 1] == '.')
			return (1);
	}
	else
	{
		if (data->map[y][x - 1] == '.')
			return (1);
	}
	return (0);
}

void	analyze_boundary(t_data *data, int y, int x)
{
	while (++y < data->m_y && (x = -1))
	{
		while (++x < data->m_x)
		{
			if (data->map[y][x] == data->ox ||
				data->map[y][x] == data->bigox)
			{
				if (bound_dir_scana(data, y, x))
				{
					data->b_y[data->b_index] = y;
					data->b_x[data->b_index++] = x;
				}
			}
			else if (data->map[y][x] == data->ox_b ||
				data->map[y][x] == data->bigox_b)
			{
				if (bound_dir_scana(data, y, x))
				{
					data->bh_y[0][data->bh_index[0]] = y;
					data->bh_x[0][data->bh_index[0]++] = x;
				}
			}
		}
	}
}
