/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmacias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 17:59:45 by tmacias           #+#    #+#             */
/*   Updated: 2020/02/01 15:49:07 by tmacias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	printusage(void)
{
	write(2, "usage: fillit file\n", 20);
}

int	isvalid(int bytesread, char *tet)
{
	int	c;
	int	h;

	c = 0;
	h = 0;
	if (bytesread < 20)
		return (0);
	while (c < 20 && h <= 4)
	{
		if (((c + 1) % 5 == 0 && tet[c] != '\n'))
			return (0);
		if (!(tet[c] == '.' || tet[c] == '#' || tet[c] == '\n'))
			return (0);
		if (tet[c] == '#' && ((c > 0 && tet[c - 1] == '#') || (c < 19 && tet[c + 1] == '#') ||
					(c - 5 >= 0 && tet[c - 5] == '#') || (c + 5 < 20 && tet[c + 5] == '#')))
		{
			h++;
		}
		else if (tet[c] == '#')
			return (0);
		c++;
	}
	return (h == 4 ? 1 : 0);
}

void	ft_freelst(t_list **lst)
{
	void	*tmp;

	while (*lst)
	{
		tmp = ft_lstpop(lst);
		free(tmp);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int 	isfirst;
		int		fd;
		int		bytesread;
		char	buf[25] = {0};
		t_list	*tetlist = NULL;

		isfirst = 1;
		bytesread = 0;
		if ((fd = open(av[1], O_RDONLY)) < 1)
			return (0);
		while ((bytesread = read(fd, buf, isfirst ? 20 : 21)) > 0)
		{
			buf[bytesread] = 0;
			if (isvalid(bytesread, !isfirst ? buf + 1 : buf))
			{
				ft_lstpush(&tetlist, ft_strdup(buf));
			}
			else
			{
				ft_freelst(&tetlist);
				printusage();
				return (0);
			}
			isfirst = 0;
		}	
		t_list	*test = tetlist;
		while (test)
		{
			printf("LIST\n||%s||\n", test->content);
			test = test->next;
		}
	}
	else
		printusage();
	return (0);
}
