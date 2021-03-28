#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void PrintInitializedBoard(int m, int n, char board[][3]);
void CreateBoard(int m, int n, char board[][3]);
int IsValidBoard(int m,int n,char board[][3]);
void ListWinningCells(int m, int n, char board[][3]);
char WhoIsWinner(int m,int n, char board[][3]);

int main()
{
    int c = 1 ;
    int valid_check = 0;
    int list_check;
    int list_winning_cell;
    char board[3][3] ;
    int row,col ;
    
    char choice;
    
    printf("\n");
    printf("New Game: \n");
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            board[i][j] = c + '0'  ;
            c++;
        }
    }
    while(1)
    {
        //Instructions. 
        printf("\n");
        printf("press \"p\" to print the tic-tac-toe board\n");
        printf("press \"c\" to create a tic-tac-toe board with some X and O cells\n");
        printf("press \"t\" to test if a tic-tac-toe board is valid or invalid board\n");
        printf("press \"w\" to predict winning cell for player X and O\n");
        printf("press \"e\" to Exit\n");
        
        scanf(" %c",&choice);
        printf("\n\n");
        
        //Cases for checking the insruction conditions.
        switch (choice)
        {
          case 'p' :
            PrintInitializedBoard(row,col,board);
            break;
          case 'c' :
            CreateBoard(row,col,board);
            WhoIsWinner(row,col,board);
            break;
          case 't' :
            IsValidBoard(row,col,board);
            break;
          case 'w' :
            ListWinningCells(row,col,board);
            break;
        }
        if(choice == 'e')
          {
            printf("\t \tGame Over.....\n");
            break;
          }
    
    }
    
    printf("\nHave a Nice Day!");
}   

void PrintInitializedBoard(int m, int n, char board[][3])
{
    int c = 1 ;
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            board[i][j] = c + '0'  ;
            c++;
        }
    }
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<1;j++)
        {
            printf("     |     |     \n");
            printf("  %c  |  %c  |  %c \n", board[i][j], board[i][j+1], board[i][j+2]);
        }
        
        if(i != 2){
            printf("_____|_____|_____\n");
        }
    }
    printf("     |     |     \n");
    return;
}

void CreateBoard(int m, int n, char board[][3])
{
    char key , alpha;
    
    while(1){
        printf("Enter Row and Column number to insert X/O; or e to Exit: ");
        scanf(" %c",&key);
        
        if(key == 'e')
        {
            break;
        }
        
        printf("Type \"X\" or \"O\": ");
        scanf(" %c",&alpha);
        
        if(key<'1' && key >'9' && (alpha !='X' || alpha !='O'))
        {
            printf("Invalid Input\n");
        }
        else
        {
            for(int row = 0;row<3;row++){
                    for(int col=0;col<3;col++){
                        if(board[row][col] == key)
                        {
                            board[row][col] = alpha ;    
                        }
                    }   
                }
            
                //Printing Board.
                for(int i=0;i<3;i++){
                    for(int j=0;j<1;j++){
                        printf("     |     |     \n");
                        printf("  %c  |  %c  |  %c \n", board[i][j], board[i][j+1], board[i][j+2]);
                    }
                    
                    if(i != 2)
                    {
                        printf("_____|_____|_____\n");
                    }
                }
                printf("     |     |     \n");
        }
    }
    
}

int IsValidBoard(int m,int n,char board[][3])
{
    int X_count=0 , O_count=0 , result_count;
    
    printf("\n");
    
    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            if(board[i][j] == 'X')
            {
                X_count++;
            }
            else if(board[i][j] == 'O')
            {
                O_count++;
            }
        }
    }
    
    result_count = abs(X_count - O_count);
    
    if(result_count == 0 || result_count == 1)
    {
        printf("Valid Board\n") ;
    }
    else
    {
        printf("Invalid Board\n");
    }
    
    printf("\n\n");
}

void ListWinningCells(int m, int n, char board[][3])
{
    
    char x_count[100] , o_count[100] ;
    int i = 0 ;
    int xcount = 0 , ocount = 0 ;
    
    //Horizontal line check
    for(int i=0 ; i<3;i++)
    {
        int a=0,b=1,c=2;
        
        if(board[i][a] == board[i][b])
        {
            if(board[i][c] >='1' && board[i][c] <= '9')
            {
                if(board[i][a] != 'X')
                {
                    o_count[ocount] = board[i][c];
                    ocount++;
                }
                else
                {
                    x_count[xcount] = board[i][c];
                    xcount++;
                }
            }
        }
        else if(board[i][a] == board[i][c])
        {
            if(board[i][b] >='1' && board[i][b] <= '9')
            {
                if(board[i][a] != 'X')
                {
                    o_count[ocount] = board[i][b];
                    ocount++;
                }
                else
                {
                    x_count[xcount] = board[i][b];
                    xcount++;
                }
            }
        }
        else if(board[i][b] == board[i][c])
        {
            if(board[i][a] >='1' && board[i][a] <= '9')
            {
                if(board[i][b] != 'X')
                {
                    o_count[ocount] = board[i][a];
                    ocount++;
                }
                else
                {
                    x_count[xcount] = board[i][a];
                    xcount++;
                }
            }
        }
    }
    
    
    //Vertical line check 
    for(int i=0 ; i<3;i++)
    {
        int a=0,b=1,c=2;
        
        if(board[a][i] == board[b][i])
        {
            if(board[c][i] >='1' && board[c][i] <= '9')
            {
                if(board[a][i] != 'X')
                {
                   o_count[ocount] = board[c][i];
                    ocount++;
                }
                else
                {
                    x_count[xcount] = board[c][i];
                    xcount++;
                }
            }
        }
        else if(board[a][i] == board[c][i])
        {
            if(board[b][i] >='1' && board[b][i] <= '9')
            {
                if(board[a][i] != 'X')
                {
                    o_count[ocount] = board[b][i];
                    ocount++;
                }
                else
                {
                    x_count[xcount] = board[b][i];
                    xcount++;
                }
            }
        }
        else if(board[b][i] == board[c][i])
        {
            if(board[a][i] >='1' && board[a][i] <= '9')
            {
                if(board[b][i] == 'X')
                {
                    o_count[ocount] = board[a][i];
                    ocount++;
                }
                else
                {
                    x_count[xcount] = board[a][i];
                    xcount++;
                }
            }
        }
    }
    
    //Diagonal Check 
    for(int i=0;i<2;i++)
    {
        int a = 2;
        if(board[i][i] == board[i+1][i+1])
        {
            if(board[a][a] >='1' && board[a][a] <= '9')
            {
                if(board[i][i] != 'X')
                {
                    o_count[ocount] = board[a][a];
                    a--;
                    ocount++;
                    
                }
                else
                {
                   x_count[xcount] = board[a][a];
                    a--;
                    xcount++;
                }
            }
        }
        
        if(board[i][i] == board[i+2][i+2] && i == 0)
        {
            if(board[a][a] >='1' && board[a][a] <= '9')
            {
                if(board[i][i] != 'X')
                {
                    o_count[ocount] = board[a][a];
                    a--;
                    ocount++;
                }
                else
                {
                    x_count[xcount] = board[a][a];
                    a--;
                    xcount++;
                }
            }
        }
    }
    
    if(board[0][2] == board[1][1])
    {
        if(board[2][0] >='1' && board[2][0] <='9')
        {
            if(board[0][2] != 'X')
            {
                o_count[ocount] = board[2][0];
                ocount++;
            }
            else
            {
                x_count[xcount] = board[2][0];
                xcount++;
            }
            
            i++;
        }
    }
    if(board[0][2] == board[2][0])
    {
        if(board[1][1] >='1' && board[1][1] <='9')
        {
            if(board[0][2] != 'X')
            {
                o_count[ocount] = board[1][1];
                ocount++;
            }
            else
            {
                x_count[xcount] = board[1][1];
                xcount++;
            }
            
            i++;
        }
    }
    if(board[1][1] == board[2][0])
    {
        if(board[0][2] >='1' && board[0][2] <='9')
        {
            if(board[1][1] != 'X')
            {
                o_count[ocount] = board[0][2];
                ocount++;
            }
            else
            {
                x_count[xcount] = board[0][2];
                xcount++;
            }
            i++;
        }
    }
    
    
    
    printf("\n\n\n");
    
    
    //Printing Cell Number.
    if(xcount == 0 && ocount == 0)
    {
        printf("There are no winning cell for player X or O");
    }
    else if(ocount == 0)
    {
        printf("Cell "); 
        for(int j = 0;j <xcount ; j++)
        {
                if(j > 0)
                {
                    printf(" and ");
                }
                printf("#%c ",x_count[j]);
        }
        printf("is the winning cell for Player X\n");
    }
    else if(xcount == 0)
    {
        printf("Cell ");
        for(int j = 0;j <ocount ; j++)
        {
            if(j > 0)
            {
                printf(" and ");
            }    
            printf("#%c ",o_count[j]);
        }
        printf("is the winning cell for Player O\n");
            
    }
    else
    {
        printf("Cell "); 
        for(int j = 0;j <xcount ; j++)
        {
                if(j > 0)
                {
                    printf(" and ");
                }
                printf("#%c ",x_count[j]);
        }
        printf("is the winning cell for Player X\n\n");
        printf("Cell ");
        for(int j = 0;j <ocount ; j++)
        {
            if(j > 0)
            {
                printf("and ");
            }    
            printf("#%c ",o_count[j]);
        }
        printf("is the winning cell for Player O\n\n");
    }
    
    printf("\n\n");
}

char WhoIsWinner(int m,int n, char board[][3])
{
    
    int win = 0 ;
    
    printf("\n\n\n\n");
    
    //Horizontal Checking
    for(int i=0 ; i<3 ; i++)
    {
        int a = 0 , b = 1 , c = 2 , count = 0  ;
        if(board[i][a] == board[i][b] && board[i][b] == board[i][c])
        {
            count++;
        }
        
        if(count == 1)
        {
            if(board[i][a] != 'X')
            {
                 printf("Player O Wins");
                win++;
            }
            else
            {
                printf("Player X Wins");
                win++;
            }
        }
    }
    
    //Vertical Checking 
    for(int i=0 ; i<3 ; i++)
    {
        int a = 0 , b = 1 , c = 2 , count = 0  ;
        if(board[a][i] == board[b][i] && board[b][i] == board[c][i])
        {
            count++;
        }

        if(count == 1)
        {
            if(board[a][i] != 'X')
            {
                printf("Player O Wins");
                win++;
            }
            else
            {
                printf("Player X Wins");
                win++;
            }
        }
    }
    
    //Diagonal Checking
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if(board[0][0] != 'X')
        { 
            printf("Player O Wins");
            win++;
        }
        else
        {
            printf("Player X Wins");
            win++;
        }
    }
    else if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        if(board[0][2] != 'X')
        {
            printf("Player O Wins");
            win++;
        }
        else
        {
            printf("Player X Wins");
            win++;
        }
    }
    
    //Draw Check
    int count = 0 ;
    for(int i = 0 ; i<3;i++)
    {
        for(int j = 0 ; j<3 ; j++)
        {
            if(board[i][j] >='1' && board[i][j] <='9')
            {
                count++;
            }
        }
    }
    if(count == 0)
    {
        printf("     Draw    ");
    }
    else if(win == 0)
    {
        printf("To be Continued!!!");
    }
    
    printf("\n\n\n\n");
    
}
