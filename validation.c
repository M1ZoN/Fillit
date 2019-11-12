#include "fillit.h"

int		valid_chars(char *str)
{
	int i;
	int	dots;
	int	sharps;

	i = 0;
	while (str[i] == '.' || str[i] == '#')
	{
		dots += (str[i] == '.');
		sharps += (str[i] == '#');
		i++;
	}
	return ((dots == 12) && (sharps == 4) && (ft_strlen(str) == 20));
}

int		valid_tetrimino(char *tet, char letter)
{
	int		i;
	int		n;

	i = -1;
	n = 0;
	while (tet[++i])
	{
		if (tet[i] == '#')
		{
			tet[i] = letter;
			n += (tet[i - 1] && (tet[i - 1] == '#' || tet[i - 1] == letter));
			n += (tet[i + 1] && (tet[i + 1] == '#' || tet[i + 1] == letter));
			n += (tet[i + 4] && (tet[i + 4] == '#' || tet[i + 4] == letter));
			n += (tet[i - 4] && (tet[i - 4] == '#' || tet[i - 4] == letter));
		}
	}
	return (n == 6 || n == 8);
}

int		valid_input(char	**tetriminoes)
{
	int		i;
	int		flag;
	char	letter;

	i = 0;
	flag = 1;
	letter = 'A';
	while (tetriminoes[i] && flag)
	{
		flag = (valid_chars(tetriminoes[i]) && valid_tetrimino(tetriminoes[i], letter++));
		i++;
	}	
	return(flag);
}
