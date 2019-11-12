#include "fillit.h"

int		does_fit(char *piece, char c, int x)
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

int		try_to_put(char *board, char *tetrimino, int i)
{
	int		j;
	int		n;
	char	letter;

	j = 0;
	n = 0;
	while (board[n] != '\n' && board[n])
		n++;
	letter = tetrimino[j];
	while (tetrimino[j])
	{
		if (!board[i] && n != 3)
			break ;
		i -= (tetrimino[j] == '\n' && n == 3);
		i += (tetrimino[j] == '\n' && n != 4 && n != 3) * (n - 4);
		if (board[i] == '.' && tetrimino[j] > 64)
			board[i] = tetrimino[j];
		i++;
		j++;
	}
	return does_fit(board, letter, n);
}

void	redo(char *board, char c)
{
	int i;

	i = -1;
	while (board[++i])
		if(board[i] == c)
			board[i] = '.';
}

int		solvable(char *board, char **tetriminoes, int i)
{
	int	j;

	j = 0;
	if (!tetriminoes[0])
		return (1);
	while(tetriminoes[0] && tetriminoes[0][j] < 'A')
		j++;
	while (board[++i])
	{
		if(!try_to_put(board, tetriminoes[0][j], i) && (!solvable(board, &tetriminoes[1], -1)))
			redo(&board[i], tetriminoes[0][j]);
		else
			return (1);
	}
	return (0);
}


void	create_map(char *board, char **tetriminoes, int board_size, int flag)
{
	int	i;

	i = -1;
	while (flag)
	{
		board = ft_strnew(board_size * (board_size + 1));
		while (i < board_size * (board_size + 1))
		{
			if (i % (board_size + 1) == board_size)
				board[i] = '\n';
			else
				board[i] = '.';
		}
		board[i] = '\0';
		if (!solvable(board, tetriminoes, -1))
			board_size++;
		else
		{
			ft_putendl(board);
			flag = 0;	
		}
	}
}
