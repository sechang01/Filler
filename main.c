/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:32:49 by sechang           #+#    #+#             */
/*   Updated: 2018/09/29 21:22:38 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <ncurses.h>

void	visualise(int option)
{
	if (option == 1)
	{
		newterm(NULL, stderr, stdin);
		start_color();
		init_pair(1, COLOR_WHITE, COLOR_BLACK);
		init_pair(2, COLOR_BLACK, COLOR_GREEN);
		init_pair(3, COLOR_BLACK, COLOR_YELLOW);
	}
	else if (option == 2)
	{
		clear();
	}
	else if (option == 3)
	{
		sleep(3);
		endwin();
	}
	else
		return;
}

void	visvis(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	visualise(2);
	while (y < data->m_y)
	{
		x = 0;
		while (x < data->m_x)
		{
			if (data->map[y][x] == '.')
				attron(COLOR_PAIR(1));
			else if (data->map[y][x] == 'X')
				attron(COLOR_PAIR(2));
			else if (data->map[y][x] == 'O')
				attron(COLOR_PAIR(3));
			printw("%2c", data->map[y][x]);
			x++;
		}
		printw("\n");
		y++;
	}
	refresh();
	usleep(data->slp);
}

int		filler_initall(t_data *data)
{
	data->m_y = 0;
	data->m_x = 0;
	data->b_index = 0;
	data->bp_i = 0;
	data->bh_index[0] = 0;
	data->bh_index[1] = 0;
	data->k = 0;
	data->slp = 33333;
	return (0);
}

void	filler_initzero(t_data *data)
{
	ft_memset((void *)data->map, 0, 10000);
	ft_memset((void *)data->piece, 0, 10000);
	data->p_x = 0;
	data->p_y = 0;
	data->pa_x = 0;
	data->pa_y = 0;
	ft_memset((void *)data->b_x, 0, 10000);
	ft_memset((void *)data->b_y, 0, 10000);
	data->b_index = 0;
	ft_memset((void *)data->bh_x, 0, 10000);
	ft_memset((void *)data->bh_y, 0, 10000);
	ft_memset((void *)data->bh_index, 0, sizeof(data->bh_index));
	ft_memset((void *)data->bp_x, 0, 10000);
	ft_memset((void *)data->bp_y, 0, 10000);
	ft_memset((void *)data->hmap, 0, 10000);
	data->bp_i = 0;
	data->k = 0;
	if (data->m_x > 50)
		data->slp = 888;
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		 k;
	char 	*line;
	int		vis;

	if (!(data = malloc(sizeof(t_data) * 1)))
		return (0);
	vis = filler_initall(data);
	if (argc >= 2)
		if (!(ft_strcmp(argv[1], "-v")) && ((vis = 1)))
		   visualise(1);	
	while ((k = get_next_line(0, &line)))
	{
		if (scan_map_piece(data, k, line, 0) == -1)
		{
			analyze_boundary(data, -1, -1);
			piece_to_bound(data);
			heatmap_it(data);
			placepiece(data, 0, 0);
			if (vis == 1)
				visvis(data);
			filler_initzero(data);
		}
	}
	(vis == 1) ? visualise(3) : visualise(0);
	return (0);
}

