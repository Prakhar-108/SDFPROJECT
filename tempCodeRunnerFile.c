#include<stdio.h>
char foarr[9][9];
int foarr2[9];

void foinitialize()
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                foarr[i][j]=' ';
            }
        }
        for(int i=0; i<9; i++)
        {
            foarr2[i]=9;
        }
        printf("%d",foarr2[8]);
    }


    //function to check if the game has ended
      int focheck(int a ,int b)
      {
        int k,l;

        //Checking for horizontal
        int count = 0;
        int max=0;
        k=a;
        l=b-3;
        for(int i=0; i<7; i++)
        {
          if(l<0 || l>9)
          {
            l++;
            continue;
          }  
          if(foarr[k][l++]==foarr[a][b])
          {
            count++;
          }
          else
           count=0;
           if(count>max)
           max=count;
        }
        if(max>=4)
        return 1;

        //Checking for vertical
        count = 0;
        max=0;
        k=a-3;
        l=b;
        for(int i=0; i<7; i++)
        {
          if(k<0 || k>9)
          {
            k++;
            continue;
          }
          if(foarr[k++][l]==foarr[a][b])
          {
            count++;
          }
          else
           count=0;
           if(count>max)
           max=count;
        }
        if(max>=4)
        return 1;

       //Checking for left diagonal
        count = 0;
        max=0;
        k=a-3;
        l=b-3;
        for(int i=0; i<7; i++)
        {
          if((k<0 || k>9)||(l<0 || l>9))
          {
             l++; k++;
            continue;
          }
          if(foarr[k++][l++]==foarr[a][b])
          {
            count++;
          }
          else
           count=0;
           if(count>max)
           max=count;
        }
        if(max>=4)
        return 1;

       //Checking for right diagonal
        count = 0;
        max=0;
        k=a-3;
        l=b+3;
        for(int i=0; i<7; i++)
        {
          if((k<0 || k>9)||(l<0 || l>9))
          {
            l--; k++;
            continue;
          }
          if(foarr[k++][l--]==foarr[a][b])
          {
            count++;
          }
          else
           count=0;
           if(count>max)
           max=count;
        }
         if(max>=4)
         return 1;
         
         return 0;
       }

       void fodisplay()
    {
        for(int i=0; i<=9; i++)
        {
            if(i<9)
            {
             for(int j=0; j<9; j++)
            {
                if(j!=8)
                printf("%c |", foarr[i][j]);
                else
                printf("%c ", foarr[i][j]);
            }
            printf("\n");
              for(int j=0; j<=25; j++)
             {
                printf("-");
             }
             printf("\n");
            }
            if(i==9)
            {   printf(" ");
                for(int j=1; j<=9; j++)
                printf("%d  ",j);
                printf("\n");
            }
            
        }
    }

    //function to input cross or circle and to also call check function
    int foinput(int t)
    {
        //variable to store column number
        int b;
        if(t==1)
        {
             printf("\nPlayer 1's turn");
             printf("\nEnter the column (1,2,3,4,5,6,7,8,9) : ");
             scanf("%d",&b);
        if(foarr[foarr2[b-1]-1][b-1]!=' ')
        {
            printf("The grid space is already occupied, please enter again!\n");
            return foinput(t);
        }
        else
             {
                foarr[--foarr2[b-1]][b-1]='X';
                int re= focheck(foarr2[b-1],b-1);
                return re;
             }

        }
        else
        {    printf("\nPlayer 2's turn");
             printf("\nEnter the column (1,2,3,4,5,6,7,8,9) : ");
             scanf("%d",&b);
        if(foarr[foarr2[b-1]-1][b-1]!=' ')
        {
            printf("The grid space is already occupied, please enter again!\n");
            return foinput(t);
        }
        else
            {
                foarr[--foarr2[b-1]][b-1]='O';
                int re= focheck(foarr2[b-1],b-1);
                return re;
            }
        }
        
    }

void fomain()
    {
      foinitialize();
      fodisplay();
      //variable for player's turn
      int turn=1;
      //variable to store how many moves has been made
      int count=0;
      //variable to store whether someone has won the game or not
      int res=0;
      while(1)
      {
        if(count==81)
        {
          printf("The game is a DRAW!");
          break;
        }
        if(turn==1)
        {
            res=foinput(turn);
            count++;
            fodisplay();
            if(res)
            {
                printf("Player 1 WON!");
                break;
            }
            turn=2;
        }
        else
        {
            res=foinput(turn);
            count++;
            fodisplay();
            if(res)
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
        fomain();
        return 0;
    }