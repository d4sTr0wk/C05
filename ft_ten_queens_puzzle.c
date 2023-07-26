#include <unistd.h>

void	print_matrix(int matrix[][10])
{
	int		i;
	int		j;
	char	print;

	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
		{
			if (matrix[i][j] == 1)
			{
				print = i + '0';
				write(1, &print, 1);
			}
			i++;
		}
		j++;
	}
}

int	check_column(int matrix[][10], int column, int row)
{
	int	i;

	i = 0;
	while (i < column)
	{
		if (matrix[row][i++] == 1)
			return (0);
	}
	return (1);
}

int	check_diagonal(int matrix[][10], int column, int row)
{
	int	i;
	int	j;

	i = row + 1;
	j = column - 1;
	while (i < 10 && j >= 0)
	{
		if (matrix[i][j] == 1)
			return (0);
		++i;
		--j;
	}
	i = row - 1;
	j = column - 1;
	while (i >= 0 && j >= 0)
	{
		if (matrix[i][j] == 1)
			return (0);
		--i;
		--j;
	}
	return (1);
}

void	recursive(int *results, int matrix[][10], int column,
		int *first_time_newline)
{
	int	row;

	row = 0;
	while (row < 10)
	{
		if (check_column(matrix, column, row)
			&& check_diagonal(matrix, column, row))
		{
			matrix[row][column] = 1;
			if (column == 9)
			{
				if (*first_time_newline)
					*first_time_newline = 0;
				else
					write(1, "\n", 1);
				print_matrix(matrix);
				(*results)++;
			}
			else
				recursive(results, matrix, column + 1, first_time_newline);
		}
		matrix[row][column] = 0;
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	results;
	int	matrix[10][10];
	int	i;
	int	j;
	int	first_time_newline;

	results = 0;
	i = 0;
	first_time_newline = 1;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	recursive(&results, matrix, 0, &first_time_newline);
	return (results);
}
//#include<stdio.h>
// int main()
// {
//     printf("\n%d", ft_ten_queens_puzzle());
// }
