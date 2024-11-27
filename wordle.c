#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
 char woarr[25][25];
 char wostr[50][20];
 int wostrs[5];
 int wostrconfig[5][3];

 void woinitialize()
 {
    srand(time(0));
    //Making a word library to store words
 strcpy(wostr[0], "factor");
 strcpy(wostr[1], "ambience");
 strcpy(wostr[2], "dog");
 strcpy(wostr[3], "table");  
 strcpy(wostr[4], "prakhar") ;
 strcpy(wostr[5], "bottle"); 
 strcpy(wostr[6], "equinix");
 strcpy(wostr[7], "lamp");
 strcpy(wostr[8], "atrocious");
 strcpy(wostr[9], "golden");
 strcpy(wostr[10], "harmony");
 strcpy(wostr[11], "mountain");
 strcpy(wostr[12], "river");
 strcpy(wostr[13], "cloud");
 strcpy(wostr[14], "sunshine");
 strcpy(wostr[15], "forest");
 strcpy(wostr[16], "ocean");
 strcpy(wostr[17], "moonlight");
 strcpy(wostr[18], "starlight");
 strcpy(wostr[19], "bliss");
 strcpy(wostr[20], "cascade");
 strcpy(wostr[21], "whisper");
 strcpy(wostr[22], "tranquil");
 strcpy(wostr[23], "serendipity");
 strcpy(wostr[24], "euphoria");
 strcpy(wostr[25], "radiance");
 strcpy(wostr[26], "melody");
 strcpy(wostr[27], "vortex");
 strcpy(wostr[28], "sapphire");
 strcpy(wostr[29], "emerald");
 strcpy(wostr[30], "amber");
 strcpy(wostr[31], "crimson");
 strcpy(wostr[32], "violet");
 strcpy(wostr[33], "shadow");
 strcpy(wostr[34], "reflection");
 strcpy(wostr[35], "infinity");
 strcpy(wostr[36], "paradise");
 strcpy(wostr[37], "dreamscape");
 strcpy(wostr[38], "zenith");
 strcpy(wostr[39], "horizon");
 strcpy(wostr[40], "nebula");
 strcpy(wostr[41], "galaxy");
 strcpy(wostr[42], "cosmos");
 strcpy(wostr[43], "comet");
 strcpy(wostr[44], "asteroid");
 strcpy(wostr[45], "meteor");
 strcpy(wostr[46], "eclipse");
 strcpy(wostr[47], "aurora");
 strcpy(wostr[48], "twilight");
 strcpy(wostr[49], "phoenix");
    //words to be selected from grid
    int count =0;
    for(int i=0; i<5; i++)
    {
      int rsw = rand()%50;
      int ch=0;
      for(int j=0; j<count; j++)
      {
        if(rsw==wostrs[j])
        {
            ch=1;
            break;
        }
      } 
      if(ch==1)
        {
            i--; 
            continue;
        }

            
            wostrs[count++]=rsw;
    }

    for(int i=0; i<5; i++)
    {
        int or,word;
        or=rand()%4;
        int r ,c;
        r= rand()%25;
        c= rand()%25;
        int check=0;
        int test=strlen(wostr[wostrs[i]]);
            //0 for left
            //1 for right
            //2 for up
            //3 for down

            switch(or)
            {
                //0 for left
                case 0:
                //checking if the word can fit
                if(c-test < 0)
                {
                    check=1;
                    break;
                }
                //checking if space is empty
                for(int j=c;j>c-test; j--)
                {
                    if(woarr[r][j]!='\0')
                    {
                        check=1;
                        break;
                    }
                }
                if(check==1)
                {
                    break;
                }
                for(int j=c; j>c-test; j--)
                {
                    woarr[r][j]=wostr[wostrs[i]][c-j];
                }
                wostrconfig[i][0]=r;
                wostrconfig[i][1]=c;                   
                wostrconfig[i][2]=or;
                break;

                //1 for right
                case 1:
                //checking if the word can fit
                if(c+test > 25)
                {
                    check=1;
                    break;
                }
                //checking if space is empty
                for(int j=c;j<c+test; j++)
                {
                    if(woarr[r][j]!='\0')
                    {
                        check=1;
                        break;
                    }
                }
                if(check==1)
                {
                    break;
                }
                for(int j=c; j<c+test; j++)
                {
                    woarr[r][j]=wostr[wostrs[i]][j-c];
                }
                wostrconfig[i][0]=r;
                wostrconfig[i][1]=c;                   
                wostrconfig[i][2]=or;
                break;

                //2 for upwards
                case 2:
                //checking if the word can fit
                if(r-test < 0)
                {
                    check=1;
                    break;
                }
                //checking if space is empty
                for(int j=r;j>r-test; j--)
                {
                    if(woarr[j][c]!='\0')
                    {
                        check=1;
                        break;
                    }
                }
                if(check==1)
                {
                    break;
                }
                for(int j=r; j>r-test; j--)
                {
                    woarr[j][c]=wostr[wostrs[i]][r-j];
                }
                wostrconfig[i][0]=r;
                wostrconfig[i][1]=c;                   
                wostrconfig[i][2]=or;
                break;

                //3 for downwards
                case 3:
                //checking if the word can fit
                if(r+test > 25)
                {
                    check=1;
                    break;
                }
                //checking if space is empty
                for(int j=r;j<r+test; j++)
                {
                    if(woarr[j][c]!='\0')
                    {
                        check=1;
                        break;
                    }
                }
                if(check==1)
                {
                    break;
                }
                for(int j=r; j<r+test; j++)
                {
                    woarr[j][c]=wostr[wostrs[i]][j-r];
                }
                wostrconfig[i][0]=r;
                wostrconfig[i][1]=c;                   
                wostrconfig[i][2]=or;
                break;

            }
        if(check==1)
        {
            i=i-1;
            continue;
        }
    }

    //randomly assigning characters to empty spaces
    for(int i=0; i<25; i++)
    {
        for(int j=0; j<26; j++)
        {
            if(woarr[i][j]=='\0')
            woarr[i][j]=(char) (rand()%26 + 97);
        }
    }

 }

 void wodisplay()
 {
    printf("\n      ");
    for(int i=0; i<25; i++)
    {
        printf("%-2d ",i+1 );
    }
    printf("\n");
    for(int i=0; i<25; i++)
    {
        for(int j=0; j<26; j++)
        {
            if(j==0)
            {
                printf("%-2d-   ", i+1);
                continue;
            }
            if(woarr[i][j-1]=='\0')
            printf("  |");
            else
            printf("%c |",woarr[i][j-1]);
        }
        printf("\n");
    }
 }

 void woworddisplay()
 {
    for(int i=0; i<5;i++)
    {
        if(wostrs[i]==-1)
        continue;
        printf("\n%d : %s",i+1,wostr[wostrs[i]]);
    }
 }

 int wocheck(int a, int b, int or, int n)
 {
    if(wostrconfig[n][0]==a && wostrconfig[n][1] == b && wostrconfig[n][2]==or)
    {
        system("cls");
        printf("\nCongratulations, You found the word ");
        sleep(3);
        wostrs[n]=-1;
    }
    else
    {
        system("cls");
        printf("\nWrong answer ");
        sleep(3);
        return 0;
    }
    int count=0;
    for(int i=0; i<5; i++)
    {
        if(wostrs[i]==-1)
        count++;
    }
     if(count==5)
     return 1;
     else
     return 0;
    
 }

 void woinput()
 {
    wodisplay();
    woworddisplay();
    int n;
    printf("\nEnter the word number you have found : ");
    scanf("%d", &n);
   if(wostrs[n-1]==-1)
   {
     printf("You have already found the word");
     system("cls");
     woinput();
   }
   else
   {
     printf("\nEnter the row and column index : ");
     int a,b;
     scanf("%d %d", &a, &b);
     printf("\nEnter the orientation of word 1-LEFT 2-RIGHT 3-UP 4-DOWN : ");
     int or;
     scanf("%d",&or);
     int ans=wocheck(a-1, b-1 , or-1,n-1);
     system("cls");
     if(ans)
     printf("\nCongratulation! You have found all the words");
     else
     woinput();
   }

 }
 

 void womain()
 {
    woinitialize();
    woinput();
 }

 

 int main()
 {
    womain();
    return 0;
 }