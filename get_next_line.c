/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:01:12 by snakajim          #+#    #+#             */
/*   Updated: 2024/07/19 11:26:46 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	t_string	ret;	//t_stringってなんだあ？
	int			c;
	
	ret	= (t_string){NULL, 0, 0};	//この代入の意味とは？
	while (1)
	{
		c = ft_getc(fd);	//ここでは何をしているのか？
		if (c == 2){	//Cが２だとどうなるのか？
			free(ret.str);
			return NULL;
		}
		if (c == EOF)	//EOFってなんじゃあ
			break;	//なんでbreakなんやねん
		c = ft_putc(&ret, c);	//putcってなんじゃあ
		if (c == -1)
			return NULL;
		if (c == '\n')
			break;
	}
	if (ret.len > 0)	//これはどういう状況？
		c = ft_putc(&ret, '\0');
	if (c == -1)	//これもどういう状況？
		return NULL;
	return ret.str;
}