#include <stdio.h>
#include <sudoku.h>
#include <sys/time.h>

#define S_1 0b0000000000000001
#define S_2 0b0000000000000010
#define S_3 0b0000000000000100
#define S_4 0b0000000000001000
#define S_5 0b0000000000010000
#define S_6 0b0000000000100000
#define S_7 0b0000000001000000
#define S_8 0b0000000010000000
#define S_9 0b0000000100000000
#define FULL (S_1 | S_2 | S_3 | S_4 | S_5 | S_6 | S_7 | S_8 | S_9)

int SetValue(sBoard *board, int x, int y)
{
	int fieldIndex = (y/3)*3+(x/3);
	int cellIndex = (y%3)*3+(x%3);

	if(board->fields[fieldIndex].numsUsed == FULL || board->fields[fieldIndex].cells[cellIndex] > 0)
		return 0;

	int candidate = (board->numRows[y] | board->numCols[x] | board->fields[fieldIndex].numsUsed) ^ FULL;

	switch(candidate)
	{
		case S_1:
			board->fields[fieldIndex].cells[cellIndex] = 1;
			break;
		case S_2:
			board->fields[fieldIndex].cells[cellIndex] = 2;
			break;
		case S_3:
			board->fields[fieldIndex].cells[cellIndex] = 3;
			break;
		case S_4:
			board->fields[fieldIndex].cells[cellIndex] = 4;
			break;
		case S_5:
			board->fields[fieldIndex].cells[cellIndex] = 5;
			break;
		case S_6:
			board->fields[fieldIndex].cells[cellIndex] = 6;
			break;
		case S_7:
			board->fields[fieldIndex].cells[cellIndex] = 7;
			break;
		case S_8:
			board->fields[fieldIndex].cells[cellIndex] = 8;
			break;
		case S_9:
			board->fields[fieldIndex].cells[cellIndex] = 9;
			break;
		default:
			return 1;
	}
	board->numRows[y] |= candidate;
	board->numCols[x] |= candidate;
	board->fields[fieldIndex].numsUsed |= candidate;

	return 0;
}

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("Please pass a sudoku file!\n");
		return -1;
	}
	int modifying = 1;
	struct timeval start, end;

	gettimeofday(&start, NULL);
	sBoard *board = ReadBoard(argv[1]);

	while(modifying)
	{
		modifying = 0;
		for(int y = 0; y < 9; ++y)
			for(int x = 0; x < 9; ++x)
				modifying |= SetValue(board, x, y);
	}
	gettimeofday(&end, NULL);

	PrintBoard(board);
	printf("Process took %d microseconds\n", end.tv_usec-start.tv_usec);

	return 0;
}
