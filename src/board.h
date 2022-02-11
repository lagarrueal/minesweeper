/*!
	\file board.h
	\version final
	\author Alexandre Lagarrue <lagarrueal@eisti.eu>
	\date december 19 2020 
	\brief file which contains prototypes of functions
*/

#ifndef BOARD_H
#define BOARD_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "Minesweeper.h"

/*!
	\fn struct sminesweeper** initializeBoard(struct sminesweeper** , int int_rows , int int_columns , int nb_mines)
	\version final
	\author Alexandre Lagarrue <lagarrueal@eisti.eu>
	\date december 19 2020
	\brief initialize each cell of the board
    \param struct sminesweeper** 
    \param int int_rows
    \param int int_columns
    \param int nb_mines
	\return the initialized structure
*/
struct sminesweeper** initializeBoard(struct sminesweeper** , int int_rows , int int_columns , int nb_mines);

/*!
	\fn void displayBoard(struct sminesweeper** , int int_rows , int int_columns)
	\version final
	\author Alexandre Lagarrue <lagarrueal@eisti.eu>
	\date december 19 2020
	\brief display the board
    \param struct sminesweeper** 
    \param int int_rows
    \param int int_columns
*/
void displayBoard(struct sminesweeper** , int int_rows , int int_columns);

/*!
	\fn void displayLostBoard(struct sminesweeper** , int int_rows , int int_columns )
	\version final
	\author Alexandre Lagarrue <lagarrueal@eisti.eu>
	\date december 19 2020
	\brief display the board in case the player loses the game
    \param struct sminesweeper** 
    \param int int_rows
    \param int int_columns
*/
void displayLostBoard(struct sminesweeper** , int int_rows , int int_columns );

/*!
	\fn char* saisieChaine(void)
	\version final
	\author Alexandre Lagarrue <lagarrueal@eisti.eu>
	\date december 19 2020
	\brief calculate the number of mines around a cell
    \param struct sminesweeper** 
    \param int int_rows
    \param int int_columns
    \param int pos_x
    \param int pos_y
	\return number of adjacents mines
*/
int numberCloseMines(struct sminesweeper** , int int_rows , int int_columns , int pos_x , int pos_y);



#endif