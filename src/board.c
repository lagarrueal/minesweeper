/*!
	\file board.c
	\version final
	\author Alexandre Lagarrue <lagarrueal@eisti.eu>
	\date december 19 2020
	\brief files which contains the coded functions
*/

//including headers
#include "board.h"


struct sminesweeper** initializeBoard(struct sminesweeper** board, int int_rows , int int_columns , int nb_mines)
{
    //var
    int i;
    int j;
    int pos_x;
    int pos_y;
    //2 interlocked loops to browse the whole board
    for ( i = 0; i < int_rows ; i++)
    {
        for (j = 0; j < int_columns ; j++)
        {
            //setting those fields to base values
            board[i][j].nbCloseMines = 0 ;
            board[i][j].isFlagged = 0 ;
            board[i][j].display = ' ' ;
            board[i][j].isMine = 0 ;
        }  
    }
    //randomly placing the mines across the board
    for ( i = 0; i < nb_mines; i++)
    {
        pos_x = rand() % int_rows;
        pos_y = rand() % int_columns;
        //if there isn't a mine in this cell we place it
        if (board[pos_x][pos_y].isMine == 0)
        {
            board[pos_x][pos_y].isMine = 1 ;
        }
        //else we decrease the value of i to stay in the loop as long as we need
        else
        {
            i--;
        }  
    }
    //returning the initialized board  
    return(board);    
}

int numberCloseMines(struct sminesweeper** board , int int_rows , int int_columns , int pos_x , int pos_y)
{
    //var
    int int_closeMines;
    int_closeMines = 0;


    
    //top left corner
    if (pos_x ==0 && pos_y == 0)
    {
        //testing the 3 cells surrounding the chosen one
        if (board[pos_x + 1][pos_y].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x + 1][pos_y + 1].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x][pos_y + 1].isMine == 1)
        {
            int_closeMines++;
        }
    }
    //bottom left corner
    else if (pos_x ==0 && pos_y == int_rows - 1)
    {
        //testing the 3 cells surrounding the chosen one
        if (board[pos_x][pos_y - 1 ].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x + 1][pos_y - 1].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x + 1][pos_y].isMine == 1)
        {
            int_closeMines++;
        }
    }
    //bottom right corner   
    else if (pos_x == int_columns - 1 && pos_y == int_rows - 1)
    {
        //testing the 3 cells surrounding the chosen one
        if (board[pos_x - 1][pos_y  ].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x - 1][pos_y - 1].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x][pos_y - 1].isMine == 1)
        {
            int_closeMines++;
        }
    }
    //top right corner
    else if (pos_x == int_columns - 1 && pos_y == 0)
    {
        //testing the 3 cells surrounding the chosen one
        if (board[pos_x - 1][pos_y].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x - 1][pos_y + 1].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x][pos_y + 1].isMine == 1)
        {
            int_closeMines++;
        }
    }
    //left border
    else if (pos_x == 0)
    {
        //testing the 5 cells surrounding the chosen cell
        if (board[pos_x ][pos_y - 1].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x + 1][pos_y - 1].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x + 1][pos_y ].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x + 1][pos_y + 1].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x ][pos_y + 1].isMine == 1)
        {
            int_closeMines++;
        }
    }
    //right border
    else if (pos_x == int_columns - 1 )
    {
        //testing the 5 cells surrounding the chosen cell
        if (board[pos_x ][pos_y + 1].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x - 1][pos_y + 1].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x - 1][pos_y ].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x -1][pos_y - 1].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x ][pos_y - 1].isMine == 1)
        {
            int_closeMines++;
        }
    }
    //top border 
    else if (pos_y == 0)
    {
        //testing the 5 cells surrounding the chosen cell
        if (board[pos_x +1 ][pos_y].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x + 1 ][pos_y + 1].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x][pos_y + 1].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x - 1][pos_y + 1].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x - 1][pos_y].isMine == 1)
        {
            int_closeMines++;
        }
    }
    //bottom border
    else if (pos_y == int_columns - 1 )
    {
        //testing the 5 cells surrounding the chosen cell
        if (board[pos_x - 1 ][pos_y].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x - 1 ][pos_y - 1].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x][pos_y - 1].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x +1][pos_y - 1].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x + 1][pos_y ].isMine == 1)
        {
            int_closeMines++;
        }
    }
    //cell in the middle of the board
    else 
    {
        //testing the 8 cells surrounding the chosen cell
        if (board[pos_x - 1][pos_y -1 ].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x][pos_y - 1].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x + 1][pos_y - 1].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x + 1][pos_y].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x + 1][pos_y + 1].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x][pos_y + 1].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x - 1][pos_y + 1].isMine == 1)
        {
            int_closeMines++;
        }
        if (board[pos_x - 1][pos_y].isMine == 1)
        {
            int_closeMines++;
        }  
    }  
    printf("%d\n" , int_closeMines);
    
    //return the number of mines nearby the selected cell
    return (int_closeMines);     
}


void displayBoard(struct sminesweeper** board , int int_rows , int int_columns)
{
    printf("     ");
    //printing columns index
    for (int i = 0; i < int_columns; ++i)
    {
        printf("  %d  ",i );
    }
    printf("\n     ");
    //printing the top line
    for (int i = 0; i < int_columns; ++i)
    {   
        printf("_____");
    }
    printf("_\n ");

    //printing the border of the cells
    for (int i = 0; i < int_rows; ++i)
    {
        for (int k = 0; k < int_columns; ++k)
        {
            printf("    |");
        }
        printf("    |\n     ");
        
        //printing inside of the cells
        for (int j = 0; j < int_columns; ++j)
        {
            //if there is a flag display letter F in red
            if (board[i][j].isFlagged == 1)
            {
                printf("|\x1B[31m %c  \x1B[0m" , 'F');
            }
            //display the number of adjacent mines in color based on the real minesweeper game
            //the color codes are escape codes
            else if (board[i][j].isMine == 0)
            {
                //display nothing
                if (board[i][j].nbCloseMines == 0)
                {
                    printf("| %c  " , board[i][j].display );
                }
                //display in cyan
                else if (board[i][j].nbCloseMines == 1)
                {
                    printf("|\x1B[36m %d  \x1B[0m" , board[i][j].nbCloseMines);
                }
                //display in green
                else if (board[i][j].nbCloseMines ==2)
                {
                    printf("|\x1B[32m %d  \x1B[0m" , board[i][j].nbCloseMines);
                }
                //display in magenta
                else if (board[i][j].nbCloseMines == 3)
                {
                    printf("|\x1B[35m %d  \x1B[0m" , board[i][j].nbCloseMines);
                }
                //display in blue
                else if (board[i][j].nbCloseMines == 4)
                {
                    printf("|\x1B[34m %d  \x1B[0m" , board[i][j].nbCloseMines);
                }
                //display in red
                else if (board[i][j].nbCloseMines == 5)
                {
                    printf("|\x1B[31m %d  \x1B[0m" , board[i][j].nbCloseMines);
                }
                //display in yellow 
                else if (board[i][j].nbCloseMines == 6)
                {
                    printf("|\x1B[33m %d  \x1B[0m" , board[i][j].nbCloseMines);
                }
                //display in white
                else if (board[i][j].nbCloseMines == 7)
                {
                    printf("| %d  " , board[i][j].nbCloseMines);
                }
                //display in white
                else if (board[i][j].nbCloseMines == 8)
                {
                    printf("| %d  " , board[i][j].nbCloseMines);
                }
                //if there aren't any adjacent mines, print the initialized value of the field display
                else
                {
                printf("| %c  " , board[i][j].display );
                }
                
                
            }
            //and printing the initialized value of the field display by default
            else
            {
                printf("| %c  " , board[i][j].display );
            }
        }
        //print the index of the lines
        printf("|  %d\n     " , i );
        //printing the bottom lines
        for (int i = 0; i < int_columns; ++i)
        {   
            printf("|____");
        }
        printf("|\n ");
    } 
}


void displayLostBoard(struct sminesweeper** board, int int_rows , int int_columns )
{

    //the steps are the same than in the previous function except in this one we print the mines
    printf("     ");
    for (int i = 0; i < int_columns; ++i)
    {
        printf("  %d  ",i );
    }
    printf("\n     ");
    for (int i = 0; i < int_columns; ++i)
    {   
        printf("_____");
    }
    printf("_\n ");

    for (int i = 0; i < int_rows; ++i)
    {
        for (int k = 0; k < int_columns; ++k)
        {
            printf("    |");
        }
        printf("    |\n     ");
        
        for (int j = 0; j < int_columns; ++j)
        {
            //if there is a flag display letter F in red
            if (board[i][j].isFlagged == 1)
            {
                printf("|\x1B[31m %c  \x1B[0m" , 'F');
            }
            else if (board[i][j].isMine == 0)
            {
                //display nothing
                if (board[i][j].nbCloseMines == 0)
                {
                    printf("| %c  " , board[i][j].display );
                }
                //display in cyan
                else if (board[i][j].nbCloseMines == 1)
                {
                    printf("|\x1B[36m %d  \x1B[0m" , board[i][j].nbCloseMines);
                }
                //display in green
                else if (board[i][j].nbCloseMines ==2)
                {
                    printf("|\x1B[32m %d  \x1B[0m" , board[i][j].nbCloseMines);
                }
                //display in magenta
                else if (board[i][j].nbCloseMines == 3)
                {
                    printf("|\x1B[35m %d  \x1B[0m" , board[i][j].nbCloseMines);
                }
                //display in blue
                else if (board[i][j].nbCloseMines == 4)
                {
                    printf("|\x1B[34m %d  \x1B[0m" , board[i][j].nbCloseMines);
                }
                //display in red
                else if (board[i][j].nbCloseMines == 5)
                {
                    printf("|\x1B[31m %d  \x1B[0m" , board[i][j].nbCloseMines);
                }
                //display in yellow 
                else if (board[i][j].nbCloseMines == 6)
                {
                    printf("|\x1B[33m %d  \x1B[0m" , board[i][j].nbCloseMines);
                }
                //display in white
                else if (board[i][j].nbCloseMines == 7)
                {
                    printf("| %d  " , board[i][j].nbCloseMines);
                }
                //display in white
                else if (board[i][j].nbCloseMines == 8)
                {
                    printf("| %d  " , board[i][j].nbCloseMines);
                }
                else
                {
                printf("| %c  " , board[i][j].display );
                }
            }
            //here is the place where we are displaying the mines because
            //we want to show the player where they are when he loses the game
            else if (board[i][j].isMine == 1)
            {
                //displaying the mine in red then resetting the color to white
                printf("|\x1B[31m %c  \x1B[0m" , '*');
            }
            else
            {
                printf("| %c  " , board[i][j].display );
            }
        }
        printf("|  %d\n     " , i );

        for (int i = 0; i < int_columns; ++i)
        {   
            printf("|____");
        }
        printf("|\n ");
    } 
}
    


