#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H

#include <stdint.h>

typedef struct sField
{
	uint16_t numsUsed;
	uint8_t cells[9];
}sField;

typedef struct sBoard
{
	uint16_t fieldsFilled;
	uint16_t numRows[9];
	uint16_t numCols[9];
	sField fields[9];
}sBoard;

sBoard* ReadBoard(char *path);
void PrintBoard(sBoard *board);

#endif
