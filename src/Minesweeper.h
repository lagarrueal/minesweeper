/*!
	\file Minesweeper.h
	\version final
    \author Alexandre Lagarrue <lagarrueal@eisti.eu>
	\date december 19 2020
	\brief file that contains the definition of the structure
*/

#ifndef MINESWEEPER_H
#define MINESWEEPER_H

//including headers
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "board.h"
#include <stdio.h>

//defining constants in order to use the escape code
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

/*! struct sminesweeper
 * structure used for the minesweeper, including informations about the number of adjacent mines,
 * if a cell is a mine, if a cell is flagged and the character to display
 *\
*/
struct sminesweeper
{
    int isMine;         /*!< give the information if a cell contains a mine or not */
    int isFlagged;      /*!< give the information if a cell contains a flag or not */
    char display;       /*!< give information about the character to display*/ 
    int nbCloseMines;   /*!< give the information of the number of adjacent mine to a cell*/
};

#endif