#include "fillit.h"

void	redo(char *board, char c)
{
	int i;

	i = -1;
	while (board[++i])
		if(board[i] == c)
			board[i] = '.';
}

/*
** place uses a while loop to come up with the length
** of each row of the current board to be printed
** and assigns that value to (x). Then it assigns
** piece's current index to the letter variable
** that will be passed to placement check.
** Then it starts to loop through the piece.
** It checks to see if we're at ('\0') for the board
** to break out of the loop. The ternary operators look for a new line char
** as we iterate through the current piece. If (x) is any number besides (3)
** or (4) then [i += (x - 4)] will set the index to the nl char of the board
** and then the iterations between (i) and (j) will match the order up again.
** It subtracts (4) because that is length of the piece's row w/o the nl char.
** If (x) = 3, (the smallest piece other than a square) then the board's index
** will be sent backwards by (1) to match the nl spot that the piece is on.
** It returns a call to placement check to make sure the current piece its just
** placed is correct and in a good spot, (1) if true, (0) is false.
*/

int		place(char *board, char *piece, int i)
{
	int		x;
	int		j;
	char	letter;

	j = 0;
	x = 0;
	while (board[x] != '\n' && board[x])
		x++;
	letter = piece[j];
	while (piece[j])
	{
		if (!board[i] && x != 3)
			break ;
		(piece[j] == '\n' && x == 3) ? i-- : i;
		(piece[j] == '\n' && x != 4 && x != 3) ? i += (x - 4) : i;
		board[i] = (board[i] == '.' && piece[j] > 64) ? piece[j] : board[i];
		i++;
		j++;
	}
	return (placement_check(board, letter, x) ? 1 : 0);
}

/*
** solve is where the backtracking occurs.
** First, it looks to see if we've encountered
** the NULL array at the end of pieces for a cue to stop.
** Then it takes the incoming piece and iterates
** to the first letter, cutting the string down as it increases the index.
** Then it iterates through the indexes on the board
** to begin backtracking. If place nor solve don't work
** the function tries placing the next piece instead,
** then the prior piece is picked up. If they both work,
** the board has been solved and (1) is returned to exit the function.
*/

int		solve(char *board, char **pieces)
{
	int	i;

	i = -1;
	if (!pieces[0])
		return (1);
	while (pieces[0] && pieces[0][0] < 64)
		pieces[0]++;
	while (board[++i])
	{
		if (place(board, *pieces, i) != 1 || (!solve(board, &pieces[1], -1)))
			pickup(&board[i], *pieces[0]);
		else
			return (1);
	}
	return (0);
}

void	builder(char *board, char **tetriminoes, int size)
{
	int i;
	int	flag;

	flag = 1;
	while (flag)
	{
		i = -1;
		while (++i < (size * (size + 1)))
		{
			if (i % (size + 1) == size)
				board[i] = '\n';
			else
				board[i] = '.';
		}
		board[i] = '\0';
		if (!solve(board, tetriminoes))
		{
			size++;
			board = ft_strnew(size * (size + 5));
		}
		else
		{
			ft_putstr(board);
			flag = 0;
		}
	}
}