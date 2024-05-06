# FastSudoku

This sudoku solver is made to be as fast as possible. It is not finished yet though. The only sudokus I tested were of the difficulty easy and should there only be multiple options the sudoku will loop forever.

## How it works

The algorithm relies heavily on bit manipulation. Thus the main file contains 10 #defines declaring the bit position for 1-9 and The state of all numbers being used.

Thus the algorithim can be splir into two parts: Reading and itterating.

## Reading

The solver creates a sBoard struct holding an array of 9 sFields, 9 uint16_t for the rows and 9 uint16_t for the columns.
The sField holds a uint16_t for all used numbers in the current field and an array of 9 uint8_t for the cells.

It now reads the input file row by row.

During each row it loops once through the char array read from the file, subtracting 48 and or-ing the proper numRows[y] and numCols[x] with the read value.
It is important to note that during reading the values are rolled 

Each itteration it is checked if the current field is filled out by checking the numsUsed variables against the FULL #define in main.
Should they be equal the itteration is skipped as all cells are filled. It is also check if the current cell is filled with a number. Should this be true it is also skipped as we don't overwrite filled cells.

After this the numRow
