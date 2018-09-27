/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:32:49 by sechang           #+#    #+#             */
/*   Updated: 2018/09/26 17:47:16 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// b_index and all needs to be initialized to zero! malloc for struct pointer?

int	test(t_data *data);

int	placepiece(t_data *data, int xp, int yp)
{
	int	i;
	int	x;
	int	y;
	char hck;

	hck = 1;
	i = 0;
	while (i < data->bp_i)
	{
		y = 0;
		while (y < data->p_y)
		{
			x = 0;
			while (x < data->p_x)
			{
				if (data->hmap[data->b_y[data->bp_i + y]][data->
						b_x[data->bp_i + x]] > hck)
				{
					xp = data->b_x[data->bp_i];
					yp = data->b_y[data->bp_i];
					hck = data->hmap[data->b_y[data->bp_i + y]][data->
						b_x[data->bp_i+ x]];
				}
				x++;
			}
			y++;
		}
		i++;
	}
	printf("---------------------------------- %d, %d\n", yp, xp);
	return (0);
}

int	alldircheck(t_data *data, int y, int x, int heatnum)
{
	int	row;
	int	col;
	int	success;
	int	k;

	k = (data->k == 1) ? 0 : 1;
//	printf("entering alldircheck\n");
	success = 0;
	col = -1;
	while (col <= 1)
	{
		row = -1;
		while (row <= 1)
		{
//			printf("y=%c\n", data->hmap[y + col][x + row]);
			if (data->hmap[y + col][x + row] == '.')
			{
				printf("inside%d\n", heatnum);
				data->hmap[y + col][x + row] = heatnum;
				data->bh_y[k][data->bh_index[k]] = y + col;
				data->bh_x[k][data->bh_index[k]] = x + row;
				data->bh_index[k]++;
				success = 1;
				printf("y=%c\n", data->hmap[y + col][x + row]);
			}
			row++;
		}
		col++;
	}
//	return (0);
	return (success == 1) ? 1 : 0;
}

int	heatmap_it(t_data *data)
{
	int	i;
//	int	k;
	char	heatnum;
	int complete;

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
		printf("data->k[%d]\n", data->k);
		heatnum++;
//		printf ("complete=%d\n", complete);
	}
	test(data);
	return (0);
}

int	piece_map_check(t_data *data, int i, int y, int x)
{
	int	pby;
	int	pbx;
	int	xi;
	int	yi;
	int	counter;

	counter = 0;
	yi = 0;
	printf("p m check\n");
	while (yi < data->p_y) 
	{
		pby = data->b_y[i] - (data->p_y - 1) + yi + y;
		xi = 0;
		while (xi < data->p_x)
		{
			pbx = data->b_x[i] - (data->p_x - 1) + xi + x;
			printf("dbxi=%ddbyi=%d\n",data->b_x[i], data->b_y[i]);
			printf("yi=%d, xi=%d\n", yi, xi);
				printf("pby=%d pbx= %d, i=%d,  x=%d,xi=%d,y=%d,yi=%d\n", pby, pbx,i,x,xi,y,yi);
			if (data->piece[yi][xi] == '*' && (data->map[pby][pbx] == data->ox
						|| data->map[pby][pbx] == data->bigox))
			{
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~inside\n");
//				printf("pby=%d pbx= %d, i=%d,  x=%d,xi=%d,y=%d,yi=%d\n", pby, pbx,i,x,xi,y,yi);
				counter++;
			}
			xi++;
		}
		yi++;
	}
	return (counter == 1) ? (1) : (0) ;
}

int	piece_to_bound(t_data *data)
{
	int	i;
	int	y;
	int	x;
	
	i = 0;
	while (i < data->b_index)
	{
		y = 0;
		while (y < data->p_y)
		{
			x = 0;
			while (x < data->p_x)
			{
	//			printf("hmm is it working?\n");
				if (data->piece[(data->p_y - 1) - y][(data->p_x - 1) - x] == '*'//)
					&& piece_map_check(data, i, y, x) == 1)
				{

		printf("i=%d\n", i);
					printf("data_py[%d], data_px[%d] == '*' \n", (data->p_y - 1) - y, (data->p_x - 1) - x);
//					printf("we in\n");
					printf("y: %d\n", (data->b_y[i] - ((data->p_y - 1) - y)));
					printf("x: %d\n", (data->b_x[i] - ((data->p_x - 1) - x)));

					data->bp_y[data->bp_i] = (data->b_y[i] - ((data->p_y - 1) - y));
					data->bp_x[data->bp_i] = (data->b_x[i] - ((data->p_x - 1) - x));
					(data->bp_i)++;
				}
				x++;
			}
			y++;
		}
		i++;
	}
	printf("bp_i= %d\n", data->bp_i);
	return (0);
}

int	bound_dir_scanb(t_data *data, int cpy_y, int cpy_x)
{
	if (data->map[cpy_y][cpy_x] == '.')
	{
	//	data->b_y[data->b_index] = cpy_y;
	//	data->b_x[data->b_index] = cpy_x;
//		data->b_index++;
		return (1);
	}
	return (0);
}

int	bound_dir_scana(t_data *data, int y, int x)
{
	int	cpy_x;
	int	cpy_y;

	//scan north
	if (y == 0)
	{
		cpy_x = x;
		cpy_y = y + data->m_y - 1;
		if (bound_dir_scanb(data, cpy_y, cpy_x))
			return (1);
	}
	else
	{
		cpy_x = x;
		cpy_y = y - 1;
		if (bound_dir_scanb(data, cpy_y, cpy_x))
			return (1);
	}
	//scan east
	cpy_x = x + 1;
	cpy_y = y;
	if (bound_dir_scanb(data, cpy_y, cpy_x))
		return (1);
	//scan south
	cpy_x = x;
	cpy_y = y + 1;
	if (bound_dir_scanb(data, cpy_y, cpy_x))
		return (1);
	//scan west
	if (x == 0)
	{
		cpy_x = x + data->m_x - 1;
		cpy_y = y;
		if (bound_dir_scanb(data, cpy_y, cpy_x))
			return (1);
	}
	else
	{
		cpy_x = x - 1;
		cpy_y = y;
		if (bound_dir_scanb(data, cpy_y, cpy_x))
			return (1);
	}
	return (0);
}

int	analyze_boundary(t_data *data)
{
	int x;
	int	y;

	y = 0;
	while (y < data->m_y)
	{
		x = 0;
		while (x < data->m_x)
		{
			if (data->map[y][x] == data->ox || data->map[y][x] == data->bigox)
			{
				if (bound_dir_scana(data, y, x))
				{
					data->b_y[data->b_index] = y;
					data->b_x[data->b_index] = x;
					data->b_index++;
				}
			} // if player 2 'X' :
			else if (data->map[y][x] == data->ox_b || data->map[y][x] == data->bigox_b)
			{
				if (bound_dir_scana(data, y, x))
				{
					data->bh_y[0][data->bh_index[0]] = y;
					data->bh_x[0][data->bh_index[0]] = x;
					printf("BH_index[%d]=%d, %d\n", data->bh_index[0], data->bh_y[0][data->bh_index[0]], data->bh_x[0][data->bh_index[0]]);
					data->bh_index[0]++;
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	analyze_piecex(t_data *data)
{
	int	y;
	int	x;
	int	counter;
	int	max;

	y = 0;
	max = 0;
	while (y < data->p_y) //data->piece[y][x])
	{
		x = 0;
		counter = 0;
		while (x < data->p_x) //data->piece[y][x])
		{
			if (data->piece[y][x] == '*')
				counter++;
			x++;
		}
		if (counter > max)
			max = counter;
		y++;
	}
	data->pa_x = max;
	return (0);
}

int	analyze_piecey(t_data *data)
{
	int	y;
	int	x;
	int	counter;
	int	max;


	x = 0;
	max = 0;
	while (x < data->p_x)
	{
		y = 0;
		counter = 0;
		while (y < data->p_y)
		{
			if (data->piece[y][x] == '*')
				counter++;
			y++;
		}
		if (counter > max)
			max = counter;
		x++;
	}
	data->pa_y = max;
	return (0);
}

int	store_map(char *line, t_data *data)
{
	int	i;
	int	k;
	int	row;

	row = ft_atoi(line);
	k = 0;
	i = 4;
	while (line[i] != '\n' && (line[i] == '.' || line[i] == 'o' || line[i] == 'O' ||
				line[i] == 'x' || line[i] == 'X'))
	{
		data->map[row][k++] = line[i];
		i++;
	}
	data->map[row][k] = '\0';
//	printf("%s\n", data.map[row]);
	return (0);
}

int	store_piece(char *line, t_data *data, int i)
{
//	int	i;
	int	k;

	k = 0;
//	i = 0;
//	printf("Entering store piece\n");
	while (line[k] != '\n' && (line[k] == '.' || line[k] == '*'))
	{
		data->piece[i][k] = line[k];
		k++;
	}
	data->piece[i][k] = '\0';
//	printf("%d\n", i);
//	printf("%s\n", data->piece[i]);
	return (0);
}

//int id_piece()
//{
//}

int		test(t_data *data)
{
	int	i;
	int	k;

	i = 0;
	printf("\n\n\n");
	while (i < 15)
	{
		k = 0;
//		while (k < 16)
//		{
		printf("%s", data->map[i]);
//			k++;
//		}
		printf("\n");
		i++;
	}
	printf("\n\n\n");

	i = 0;
	printf("\n\n\n");
	while (i < 15)
	{
		k = 0;
//		while (k < 16)
//		{
		printf("%s", data->hmap[i]);
//			k++;
//		}
		printf("\n");
		i++;
	}
	printf("\n\n\n");

	i = 0;

//	printf("%s", data->piece[i]);
	while (*(data->piece[i]) == '.' || *(data->piece[i]) == '*')
	{
		printf("%s\n", data->piece[i]);
		i++;
	}
	printf("Done\n");
//	exit(1);
	
	int q;
	
	q = 0;
	while (q < data->b_index)
	{
		printf("b_index[%d]= %d, %d\n", q, data->b_y[q], data->b_x[q]);
		q++;
	}
	q = 0;
	while (q < data->bp_i)
	{
		printf("bp_index[%d]= %d, %d\n", q, data->bp_y[q], data->bp_x[q]);
		q++;
	}
	return (0);
}

int	scan_map_piece(t_data *data)
{
	int	i;
	int	k;
	char	*s;

	k = get_next_line(0, &s);
	if (k <= 0)
		return (-1);
//		break;
	else if (s[0] == '$')
	{
		if (!(strcmp((s + 23), "sechang.filler")))
			data->player = (s[10] == 1) ? 'O' : 'X' ;
	}
	else if (s[0] == 'P' && s[1] == 'l')
	{
		i = 1;
		while (s[i] != ' ' && s[i])
			i++;
		data->m_y = ft_atoi(s + i);
//		while (s[i] != ' ' && s[i])
//			i++;
		data->m_x = ft_atoi(s + (i + (data->m_y <= 9 ? 3 : 4)));
		printf("my=%dmx=%d\n", data->m_y, data->m_x);
	}
	else if ('0' <= s[0] && s[0] <= '9')
	{
		store_map(s, data);
	}
	else if (s[0] == 'P' && s[1] == 'i')
	{
//		printf("entering Pi ... \n");
		i = 1;
		while (s[i] != ' ' && s[i])
			i++;
		data->p_y = ft_atoi(s + i);
		data->p_x = ft_atoi(s + (i + (data->p_y <= 9 ? 3 : 4)));
		printf("py=%dpx=%d\n", data->p_y, data->p_x);
//		printf("%d\n", data->p_y);
		i = -1;
		while (++i < data->p_y)
		{
			k = get_next_line(0, &s);
			store_piece(s, data, i);
		}
		analyze_piecex(data);
		analyze_piecey(data);
		analyze_boundary(data);
		piece_to_bound(data);
		heatmap_it(data);
		placepiece(data, 0, 0);
		printf("pax=%dpay=%d", data->pa_x, data->pa_y);
		return (-1);
//		break ;
	}
	free(s);
//	printf("8 2\n");
	return (0);
}

int	main(void)
{
	t_data	*data;


	if (!(data = malloc(sizeof(t_data) * 1)))
		return (0);
	data->b_index = 0;
	data->bp_i = 0;
	data->bh_index[0] = 0;
	data->bh_index[1] = 0;
	data->ox = 'o';   //player 1 is o, player 2 is x;
	data->ox = 'O';
	data->ox_b = 'x';
	data->bigox_b = 'X';
//	ft_bzero(data.map);
//	ft_bzero(data.piece);
	while (1)
	{
		if (scan_map_piece(data) == -1)
		{
			test(data);
			break;
		}
	}
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	return (0);
}