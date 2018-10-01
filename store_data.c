/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 13:11:26 by sechang           #+#    #+#             */
/*   Updated: 2018/09/30 18:24:55 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	store_map(char *line, t_data *data)
{
	int		i;
	int		k;
	int		row;

	row = ft_atoi(line);
	k = 0;
	i = 4;
	while (line[i] != '\n' && (line[i] == '.' || line[i] == 'o' ||
		line[i] == 'O' || line[i] == 'x' || line[i] == 'X'))
	{
		data->map[row][k++] = line[i];
		i++;
	}
	data->map[row][k] = '\0';
}

void	store_piece(char *line, t_data *data, int i)
{
	int		k;

	k = 0;
	while (line[k] != '\n' && (line[k] == '.' || line[k] == '*'))
	{
		data->piece[i][k] = line[k];
		k++;
	}
	data->piece[i][k] = '\0';
}

void	store_piece_norm(t_data *data, int k, char *s, int i)
{
	while (s[i] != ' ' && s[i])
		i++;
	data->p_y = ft_atoi(s + i);
	data->p_x = ft_atoi(s + (i + (data->p_y <= 9 ? 3 : 4)));
	i = -1;
	while (++i < data->p_y)
	{
		k = get_next_line(0, &s);
		store_piece(s, data, i);
		free(s);
	}
}

void	init_player(t_data *data, char s)
{
	data->player = (s == '1') ? 'O' : 'X';
	if (data->player == 'O')
	{
		data->ox = 'O';
		data->bigox = 'O';
		data->ox_b = 'x';
		data->bigox_b = 'X';
	}
	else if (data->player == 'X')
	{
		data->ox = 'X';
		data->bigox = 'X';
		data->ox_b = 'o';
		data->bigox_b = 'O';
	}
}

int		scan_map_piece(t_data *data, int k, char *s, int i)
{
	if (k <= 0)
		return (-1);
	else if (s[0] == '$')
	{
		if (ft_strstr(s, "sechang.filler"))
			init_player(data, s[10]);
	}
	else if (s[0] == 'P' && s[1] == 'l')
	{
		i = 1;
		while (s[i] != ' ' && s[i])
			i++;
		data->m_y = ft_atoi(s + i);
		data->m_x = ft_atoi(s + (i + (data->m_y <= 9 ? 3 : 4)));
	}
	else if ('0' <= s[0] && s[0] <= '9')
		store_map(s, data);
	else if (s[0] == 'P' && s[1] == 'i')
	{
		store_piece_norm(data, k, s, 1);
		free(s);
		return (-1);
	}
	free(s);
	return (0);
}
