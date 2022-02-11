/*!
	\file Minesweeper.c
	\version final
	\author Alexandre Lagarrue <lagarrueal@eisti.eu>
	\date december 19 2020 
	\brief main file
*/

#include "Minesweeper.h"
#include "board.h"


int main(int argc, char const *argv[])
{
    //setting the base time for the use of rand
    srand(time(NULL));

    //variables
    int nb_rows;
    int nb_rowsReturn;
    int nb_columns;
    int nb_columnsReturn;
    int nb_mines;
    int nb_minesReturn;
    int int_nbRemainingMines;
    int pos_x;
    int pos_xReturn;
    int pos_y;
    int pos_yReturn;
    int i;
    char char_userChoice;
    int char_userChoiceReturn;

    //since the program isn't (yet) working with rectangular board, numbers of rows and columns needs to be the same
    //so there's a test right after the input
    printf("%s\n" , "Since the program isn't working properly, please enter the same number of rows and columns");
    printf("%s\n" , "Please enter the number of rows");
    nb_rowsReturn = scanf("%d" , &nb_rows);
    //testing that the number of rows is valid
    while (nb_rows < 0 || nb_rowsReturn != 1)
    {
        printf( "%s\n" , "The number of rows is not valid, please enter a correct number of rows");
        nb_rowsReturn = scanf("%d" , &nb_rows);
    }
    printf("%s\n" , "Please enter the number of columns");
    nb_columnsReturn = scanf("%d" , &nb_columns);
    //testing that the number of columns is THE SAME as the number of rows
    while (nb_columns != nb_rows || nb_columnsReturn != 1)
    {
        printf( "%s\n" , "The number of columns is not valid, please enter a correct number of rows");
        nb_columnsReturn = scanf("%d" , &nb_columns);
    }
    //input of the number of mine and testing that
    //there is AT LEAST one empty cell
    printf("%s\n" , "Please enter the number of mines");
    nb_minesReturn = scanf("%d" , &nb_mines);
    while (nb_mines >= nb_rows * nb_columns || nb_minesReturn != 1)
    {
        printf( "%s\n\n" , "There are more mines than available cells or as much mines as available cells, please enter a correct number of mines");
        nb_minesReturn = scanf("%d" , &nb_mines);
    }
    

    /*creating the board*/
    struct sminesweeper** board;

    board = malloc (nb_columns * sizeof(struct sminesweeper));

    for ( i = 0; i < nb_columns; i++)
    {
        board[i]= malloc(nb_rows * sizeof(struct sminesweeper));
    }

    /*initialising the board by randomly putting mines in it*/
    initializeBoard(board, nb_rows , nb_columns , nb_mines);

    printf("%s\n\n" , "Here is the board filled with mines, good luck and have fun finding them !");
    /*display the board*/
    displayBoard(board , nb_rows , nb_columns);

    int_nbRemainingMines = (nb_rows * nb_columns )- nb_mines;

    //do loop in order to play while you don't discover a mine and while you 
    //haven't discovered all the cell that are not mines
    do
    {
    //input of row you want to play in and testing the input
    printf("\n%s\n" , "Select the row in which you want to play");
    pos_xReturn = scanf("%d" , &pos_x);
    while (pos_x > nb_columns - 1|| pos_x < 0 || pos_xReturn != 1)
    {
        printf( "%s\n" , "Your input isn't valid, please do it again");
        pos_xReturn = scanf("%d" , &pos_x);
    }
    //input of column you want to play in and testing the input
    printf("%s\n" , "Select the column in which you want to play");
    pos_yReturn = scanf("%d" , &pos_y);
    while (pos_y > nb_rows- 1 || pos_y < 0 || pos_yReturn != 1)
    {
        printf( "%s\n" , "Your input isn't valid, please do it again");
        pos_yReturn = scanf("%d" , &pos_y);
    }
    //printing a message containing the cell you played in
    printf("You chose the cell [%d,%d]\n" , pos_x , pos_y);

    //input of the user's choice depending if he wants to discover the cell or flag the cell
    //and testing the input
    printf("Do you want to place a flag or discover it ? F for flag , D for discover : ");
    getchar();
    char_userChoiceReturn = scanf("%c" , &char_userChoice);
    printf("%c" , char_userChoice);
    while (((char_userChoice != 'D') || ((char_userChoice != 'F') ))&& (char_userChoiceReturn != 1))  
    {
        printf("%s\n" , "Your input is invalid, please type F to put a flag or D to discover the cell");
        char_userChoiceReturn = scanf(" %s" , &char_userChoice);
        printf("%c\n" , char_userChoice);
    }
    // if the input is 'F', places a Flag on the cell you chose
    if (char_userChoice == 'F')
    {
        board[pos_x][pos_y].isFlagged = 1;
        displayBoard(board , nb_rows , nb_columns);
    }
    //if the user chose to discover the cell
    else if (char_userChoice == 'D')
    {
        //and if the cell has a mine in it
        if (board[pos_x][pos_y].isMine == 1)
        {
            //display the board, printing a message and exiting the programm
            displayLostBoard(board , nb_rows , nb_columns );
            printf("%s\n" , "Nice try but you clicked on a mine ! Better luck next time !");
            exit(EXIT_SUCCESS);
        }
        /* if the cell you discovered isn't a mine, proceed to check the number of close mines*/
        else if (board[pos_x][pos_y].isMine == 0)
        {   
            //deleting the flag if there was one
            board[pos_x][pos_y].isFlagged = 0;
            //couting the number of adjacents mines
            board[pos_x][pos_y].nbCloseMines = numberCloseMines(board , nb_rows , nb_columns , pos_x , pos_y);
            /*display the board with the number of mines around the cell you chose */
            displayBoard(board , nb_rows , nb_columns);
            int_nbRemainingMines--;
        }
        
        
    }
    
    } while ((board[pos_x][pos_y].isMine == 0 || board[pos_x][pos_y].isFlagged == 1) && int_nbRemainingMines != 0);
    //printing message and displaying the final board
    printf("%s\n" , "Congratulations, you found all the mines, you've won the game");
    displayBoard(board , nb_rows , nb_columns);
    
    
    /*free the memory*/
    for ( i = 0; i < nb_columns; i++)
    {
        free(board[i]);
    }
    free(board);

    return (0);
}
