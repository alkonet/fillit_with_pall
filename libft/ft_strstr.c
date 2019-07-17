/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:45:27 by gloggins          #+#    #+#             */
/*   Updated: 2019/04/10 14:43:54 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *find)
{
	unsigned int i;
	unsigned int j;

	if (!*find)
		return ((char*)str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == find[0])
		{
			j = 1;
			while (str[i + j] == find[j] && find[j] != '\0')
				j++;
			if (find[j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}
