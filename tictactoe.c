#include<stdio.h>

    /*
    ti refers to tic tac toe
    fo refers to four in a row
    ba refers to battleship
    wo refers to wordle
    */
     
     char tiarr[3][3];

    
   
    void tiinitialize()
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                tiarr[i][j]=' ';
            }
        }
    }

    //function to input cross or circle
    void tiinput(int t)
    {
        //variable to store row number
        int a;
        //variable to store column number
        int b;
        if(t==1)
        {
             printf("Player 1's move\n");
             scanf("%d %d",&a, &b);
        if(tiarr[a-1][b-1]!=' ')
        {
            printf("The grid space is already occupied, please enter again!\n");
            tiinput(t);
        }
             tiarr[a-1][b-1]='X';
        }
        else
        {
            printf("Player 2's move\n");
            scanf("%d %d",&a, &b);
        if(tiarr[a-1][b-1]!=' ')
        {
            printf("The grid space is already occupied, please enter again!\n");
            tiinput(t);
        }
            tiarr[a-1][b-1]='O';
        }
    }
      //function to check if the game has ended
      int ticheck()
      {
        //variable to keep count to consecutive cross or circle
        int count=0;
        //checking for upper row
        for(int i=0; i<2; i++)
        {
            if(tiarr[0][i]!=tiarr[0][i+1])
            {
             count=1; 
             break;
            }
        }
        if(count==0 && tiarr[0][0]!=' ')
        return 1;
        count=0;
        //checking for middle row
        for(int i=0; i<2; i++)
        {
            if(tiarr[1][i]!=tiarr[1][i+1])
            {
             count=1; 
             break;
            }
        }
        if(count==0 && tiarr[1][0]!=' ')
        return 1;
        count=0;
        //checking for lower row
        for(int i=0; i<2; i++)
        {
            if(tiarr[2][i]!=tiarr[2][i+1])
            {
             count=1; 
             break;
            }
        }
        if(count==0 && tiarr[2][0]!=' ')
        return 1;
        count=0;
        //checking for first column
        for(int i=0; i<2; i++)
        {
            if(tiarr[i][0]!=tiarr[i+1][0])
            {
             count=1; 
             break;
            }
        }
        if(count==0 && tiarr[0][0]!=' ')
        return 1;
        count=0;
        //checking for second column
        for(int i=0; i<2; i++)
        {
            if(tiarr[i][1]!=tiarr[i+1][1])
            {
             count=1; 
             break;
            }
        }
        if(count==0 && tiarr[0][1]!=' ')
        return 1;
        count=0;
        //checking for third column
        for(int i=0; i<2; i++)
        {
            if(tiarr[i][2]!=tiarr[i+1][2])
            {
             count=1; 
             break;
            }
        }
        if(count==0 && tiarr[0][2]!=' ')
        return 1;
        count=0;
        //checking for left diagonal
        for(int i=0; i<2; i++)
        {
            if(tiarr[i][i]!=tiarr[i+1][i+1])
            {
             count=1; 
             break;
            }
        }
        if(count==0 && tiarr[0][0]!=' ')
        return 1;
        count=0;
        //checking for right diagonal
        for(int i=0; i<2; i++)
        {
            if(tiarr[i][2-i]!=tiarr[i+1][1-i])
            {
             count=1; 
             break;
            }
        }
        if(count==0 && tiarr[0][2]!=' ')
        return 1;
        count=0;

        return 0;

      }


    //function to display the tic tac toe grid
    void tidisplay()
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(j!=2)
                printf("%c |", tiarr[i][j]);
                else
                printf("%c ", tiarr[i][j]);
            }
            printf("\n");
            for(int j=0; j<=8; j++)
            {
                printf("-");
            }
            printf("\n");
        }
    }
     void timain()
    {
      tiinitialize();
      tidisplay();
      //variable for player's turn
      int turn=1;
      //variable to store how many moves has been made
      int count=0;
      while(1)
      {
        if(count==9)
        {
          printf("The game is a DRAW!");
          break;
        }
        if(turn==1)
        {
            tiinput(turn);
            count++;
            tidisplay();
            if(ticheck())
            {
                printf("Player 1 WON!");
                break;
            }
            turn=2;
        }
        else
        {
            tiinput(turn);
            count++;
            tidisplay();
            if(ticheck())
            {
                printf("Player 2 WON!");
                break;
            }
            turn=1;  
        }
        
      }
    }  
    int main()
    {
        timain();
        return 0;
    }