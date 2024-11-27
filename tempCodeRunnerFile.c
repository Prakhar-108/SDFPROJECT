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
            if(i!=2)
            {
              for(int j=0; j<=8; j++)
             {
                printf("-");
             }
              printf("\n");
            }
            
        }
    }