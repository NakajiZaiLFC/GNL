/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:01:07 by snakajim          #+#    #+#             */
/*   Updated: 2024/07/19 13:41:05 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_getc(int fd)
{
	static char		buf[BUFFER_SIZE];	//以下三行の"static"全部どういうこっちゃねん
	static char		*bufp;
	static ssize_t	n;

	if (n == 0)
	{
		n = read(fd, buf, BUFFER_SIZE);	//readってなんやねん
		if (n == -1)
		{
			n = 0;	//なんで初期化化するの？
			return -2;	//なんで"-2"をリターンするんや
		}
		else if (n == 0)
			return EOF;	//ここもどういう状況なのよ
		bufp = buf;	//ここでは一体何が代入されているのか？
	}
	n--;	//ここのデクリメントは何を企図しているのか？
	return (unsigned char)*bufp++;	//ちょっといみわからない。何をリターンしているのか。
}

	//↓これの引数自体が何を意味しているのか不明
int	ft_putc(t_string *str, char c)
{
	char	*new_str;
	size_t	capa;

	if (str->str == NULL || str->len + 1 > str->capa)
	{
		if (str->capa > 0)
			capa = str->capa * 2;	//0以上だったら2をかけて何をしたいんだろう
		else
			capa = 2;
		new_str = malloc(capa);
		if (new_str == NULL)
			return -1;	//なんで-1をリターンしているんだろう
		ft_memcpy(new_str, str->str, str->len);	//この引数の意味は何だろう
		free(str->str);
		str->str = new_str;	//以下二行、なぜフリーした後にここで代入しているのか意味不明
		str->capa = capa;
	}
	str->str[str->len++] = c;
	return c;	//そもそもこの関数自体何をしたいのか、何をリターンしてるのかもよくわからない。
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*buf;
	unsigned char	*str;

	if(dst == NULL && src == NULL)
		return NULL;
	i = 0;
	buf = (unsigned char *)dst;
	str = (unsigned char *)src;
	while (i < n)
	{
		buf[i] = str[i];
		i++;
	}
	return buf;
}

//	mallocが多いのでしっかりとフリーして、リークやセグフォを起こさないようにデータの流れやテストケースを踏まえて確認する。