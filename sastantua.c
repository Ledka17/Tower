/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 13:12:00 by sbessa            #+#    #+#             */
/*   Updated: 2018/09/24 18:27:23 by sbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		jp_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int		ksymbol(int size)
{
	int	ksym;
	int	i_grade;
	int	k_grade;

	ksym = 1;
	i_grade = 1;
	k_grade = 4;
	while (i_grade <= size)
	{
		ksym += 2 * (1 + i_grade) + 2;
		i_grade++;
		ksym += k_grade;
		if (i_grade % 2 == 0 && i_grade < size)
			k_grade += 2;
	}
	ksym -= k_grade;
	return (ksym - ((size - 1) / 2) * 2);
}

void	ft_signs(int s, int k, int sym, int r)
{
	int	i;
	int	d;
	int	f;

	ft_putchar('/');
	i = 2;
	f = k - 2;
	if (s % 2 == 0)
		d = s - 1;
	else
		d = s;
	while (i < sym)
	{
		if (f == s && r >= (k - d) && i > (sym - d) / 2 && i <= (sym + d) / 2)
			if (s >= 5 && r == k - (d + 1) / 2 && i == (sym + d) / 2 - 1)
				ft_putchar('$');
			else
				ft_putchar('|');
		else
			ft_putchar('*');
		i++;
	}
	ft_putchar('\\');
}

void	ft_space(int k)
{
	int	i;

	i = 1;
	while (i <= k)
	{
		ft_putchar(' ');
		i++;
	}
}

void	sastantua(int size)
{
	int	sym;
	int	i_rows;
	int	i_grade;
	int	row;

	if (size < 1)
		return ;
	i_grade = 1;
	sym = 1;
	while (i_grade <= size)
	{
		i_rows = i_grade + 2;
		row = 0;
		while (row < i_rows)
		{
			sym += 2;
			ft_space((ksymbol(size) - sym) / 2);
			ft_signs(size, i_grade + 2, sym, row);
			ft_putchar('\n');
			row++;
		}
		i_grade++;
		sym += 2 * ((i_grade - 2) / 2) + 4;
	}
}
