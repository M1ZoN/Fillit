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






/*
** Placement check is very similar to checksides except
** that it looks at pieces that have already been placed.
** The board could be much larger than its original size
** so the given variable (x) is passed in to be used in pointer arithmetic.
** (x) is the total number of indexes in the board rows
** before the new line char. It subtracts/adds (x)
** (as well as -1 for the new line char)
** so that it can look at the next row below/above
** to check for the same letter of the current piece being placed. If it finds
** another letter, then it does not increase the side count. If the sidecount
** us not 6 or 8, then the current piece being placed must be picked up
** and the next tried instead.


int		check_try(char *piece, char c, int x)
{
	int		i;
	int		sides;

	i = -1;
	sides = 0;
	while (piece[++i])
	{
		if (piece[i] == c)
		{
			sides += (piece[i - 1] && (piece[i - 1] == c));
			sides += (piece[i + 1] && (piece[i + 1] == c));
			sides += (piece[i - x - 1] && (piece[i - x - 1] == c));
			sides += (piece[i + x + 1] && (piece[i + x + 1] == c));
		}
	}
	return (sides == 6 || sides == 8);
}
*/