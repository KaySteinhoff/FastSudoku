#include <stdio.h>
#include <stdlib.h>
#include <sudoku.h>

sBoard* ReadBoard(char *path)
{
	sBoard *board = malloc(sizeof(sBoard));

	if(!board)
		return NULL;

	FILE *fptr = fopen(path, "rb");

	if(!fptr)
	{
		free(board);
		return NULL;
	}

	char file[90];
	char *row;
	fread(&file, 90, 1, fptr);
	fclose(fptr);
	row = &file[0];

	for(int i = 0; i < 9; ++i)
	{
		int fieldRow = (i/3)*3;
		int cellRow = (i%3)*3;

		for(int j = 0; j < 9; ++j)
		{
			row[j] -= 48;
			board->numRows[i] |= 1<<row[j];
			board->numCols[j] |= 1<<row[j];
		}
		board->numRows[i] >>= 1;

		board->fields[0+fieldRow].cells[0+cellRow] = row[0];
		board->fields[0+fieldRow].cells[1+cellRow] = row[1];
		board->fields[0+fieldRow].cells[2+cellRow] = row[2];
		board->fields[0+fieldRow].numsUsed |= 1<<row[0];
		board->fields[0+fieldRow].numsUsed |= 1<<row[1];
		board->fields[0+fieldRow].numsUsed |= 1<<row[2];

		board->fields[1+fieldRow].cells[0+cellRow] = row[3];
		board->fields[1+fieldRow].cells[1+cellRow] = row[4];
		board->fields[1+fieldRow].cells[2+cellRow] = row[5];
		board->fields[1+fieldRow].numsUsed |= 1<<row[3];
		board->fields[1+fieldRow].numsUsed |= 1<<row[4];
		board->fields[1+fieldRow].numsUsed |= 1<<row[5];

		board->fields[2+fieldRow].cells[0+cellRow] = row[6];
		board->fields[2+fieldRow].cells[1+cellRow] = row[7];
		board->fields[2+fieldRow].cells[2+cellRow] = row[8];
		board->fields[2+fieldRow].numsUsed |= 1<<row[6];
		board->fields[2+fieldRow].numsUsed |= 1<<row[7];
		board->fields[2+fieldRow].numsUsed |= 1<<row[8];
		row += 10;
	}

	for(int i = 0; i < 9; ++i)
	{
		board->fields[i].numsUsed >>= 1;
		board->numCols[i] >>= 1;
	}

	return board;
}

void PrintBoard(sBoard *board)
{
	for(int i = 0; i < 9; ++i)
	{
		int fieldRow = (i/3)*3;
		int cellRow = (i%3)*3;

		if(i%3==0 && i != 0)
			printf("------------------------\n");
		printf("%d %d %d; %d %d %d; %d %d %d\n",
			board->fields[0+fieldRow].cells[0+cellRow],
			board->fields[0+fieldRow].cells[1+cellRow],
			board->fields[0+fieldRow].cells[2+cellRow],
			board->fields[1+fieldRow].cells[0+cellRow],
			board->fields[1+fieldRow].cells[1+cellRow],
			board->fields[1+fieldRow].cells[2+cellRow],
			board->fields[2+fieldRow].cells[0+cellRow],
			board->fields[2+fieldRow].cells[1+cellRow],
			board->fields[2+fieldRow].cells[2+cellRow]
		);
	}
}
