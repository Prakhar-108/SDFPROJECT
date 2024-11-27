 #include<stdio.h>

 #include<windows.h>

 #include<stdlib.h>

 char baarr1[9][9];
 char baarr2[9][9];
 char bar1[9][9];
 char bar2[9][9];
 void bainitialize() {
   for (int i = 0; i < 9; i++) {
     for (int j = 0; j < 9; j++) {
       baarr1[i][j] = 'X';
       baarr2[i][j] = 'X';
       bar1[i][j] = 'X';
       bar2[i][j] = 'X';
     }
   }
 }
 int bacheck1() {
   for (int i = 0; i < 9; i++) {
     for (int j = 0; j < 9; j++) {
       if (baarr1[i][j] != bar1[i][j])
         return 0;
     }
   }
   return 1;
 }
 int bacheck2() {
   for (int i = 0; i < 9; i++) {
     for (int j = 0; j < 9; j++) {
       if (baarr2[i][j] != bar2[i][j])
         return 0;
     }
   }
   return 1;
 }
 void badisplay1(int c) {
   int k = 1, l = 1;
   for (int i = -1; i < 9; i++) {
     for (int j = -1; j < 9; j++) {
       if (i == -1 && j == 8)
         continue;
       if (i == -1) {
         if (j == -1)
           printf("  ");
         printf(" %d", k++);
       } else if (j == -1) {
         printf(" %d", l++);
       } else {
         printf(" %c", c == 1 ? baarr1[i][j] : bar1[i][j]);
       }
     }
     printf("\n");
   }
 }
 void badisplay2(int c) {
   int k = 1, l = 1;
   for (int i = -1; i < 9; i++) {
     for (int j = -1; j < 9; j++) {
       if (i == -1 && j == 8)
         continue;
       if (i == -1) {
         if (j == -1)
           printf("  ");
         printf(" %d", k++);
       } else if (j == -1) {
         printf(" %d", l++);
       } else {
         printf(" %c", c == 1 ? baarr2[i][j] : bar2[i][j]);
       }
     }
     printf("\n");
   }
 }
 char bacheckinput(int d, int s) {
   if (d > 9 || s > 9 || d < 1 || s < 1) {
     printf("OH! Wrong Input...\nInput again? (Y/N): ");
     char choice;
     fflush(stdin); // Clear input buffer
     scanf("%c", & choice);
     return choice;
   }
   return 'N';
 }

 void bainput1() {
   int a, b, c, d, m, n;
   q: printf("PLAYER 1:\nEnter for Ship of size 4: \nStarting Index: ");
   scanf("%d %d", & a, & b);
   if (bacheckinput(a, b) == 'Y')
     goto q;
   w: printf("Ending Index: ");
   scanf("%d %d", & c, & d);
   if (bacheckinput(a, b) == 'Y')
     goto w;
   m = a == c ? b : a;
   n = a == c ? d : c;
   if (m - n + 1 != 4 && n - m + 1 != 4) {
     printf("WRONG SIZE...");
     goto q;
   }
   for (int i = (m > n ? n : m); i <= (m > n ? m : n); i++) {
     if (a == c) {
       baarr1[a - 1][i - 1] = 'O';
     } else {
       baarr1[i - 1][b - 1] = 'O';
     }
   }
   system("cls");
   badisplay1(1);
   e: printf("Enter for Ship of size 3: \nStarting Index: ");
   scanf("%d %d", & a, & b);
   if (bacheckinput(a, b) == 'Y')
     goto e;
   r: printf("Ending Index: ");
   if (bacheckinput(a, b) == 'Y')
     goto r;
   scanf("%d %d", & c, & d);
   m = a == c ? b : a;
   n = a == c ? d : c;
   if (m - n + 1 != 3 && n - m + 1 != 3) {
     printf("WRONG SIZE...");
     goto e;
   }
   for (int i = (m > n ? n : m); i <= (m > n ? m : n); i++) {
     if (a == c) {
       baarr1[a - 1][i - 1] = 'O';
     } else {
       baarr1[i - 1][b - 1] = 'O';
     }
   }
   system("cls");
   badisplay1(1);
   t: printf("Enter for Ship of size 3: \nStarting Index: ");
   scanf("%d %d", & a, & b);
   if (bacheckinput(a, b) == 'Y')
     goto t;
   y: printf("Ending Index: ");
   scanf("%d %d", & c, & d);
   if (bacheckinput(a, b) == 'Y')
     goto y;
   m = a == c ? b : a;
   n = a == c ? d : c;
   if (m - n + 1 != 3 && n - m + 1 != 3) {
     printf("WRONG SIZE...");
     goto t;
   }
   for (int i = (m > n ? n : m); i <= (m > n ? m : n); i++) {
     if (a == c) {
       baarr1[a - 1][i - 1] = 'O';
     } else {
       baarr1[i - 1][b - 1] = 'O';
     }
   }
   system("cls");
   badisplay1(1);
   u: printf("Enter for Ship of size 2: \nStarting Index: ");
   scanf("%d %d", & a, & b);
   if (bacheckinput(a, b) == 'Y')
     goto u;
   i: printf("Ending Index: ");
   if (bacheckinput(a, b) == 'Y')
     goto i;
   scanf("%d %d", & c, & d);
   m = a == c ? b : a;
   n = a == c ? d : c;
   if (m - n + 1 != 2 && n - m + 1 != 2) {
     printf("WRONG SIZE...");
     goto u;
   }
   for (int i = (m > n ? n : m); i <= (m > n ? m : n); i++) {
     if (a == c) {
       baarr1[a - 1][i - 1] = 'O';
     } else {
       baarr1[i - 1][b - 1] = 'O';
     }
   }
   system("cls");
   printf("YOUR SHIPS:\n\n");
   badisplay1(1);
   Sleep(5000);
   system("cls");
 }
 void bainput2() {
   int a, b, c, d, m, n;
   q: printf("PLAYER 2:\nEnter for Ship of size 4: \nStarting Index: ");
   scanf("%d %d", & a, & b);
   if (bacheckinput(a, b) == 'Y')
     goto q;
   w: printf("Ending Index: ");
   scanf("%d %d", & c, & d);
   if (bacheckinput(a, b) == 'Y')
     goto w;
   m = a == c ? b : a;
   n = a == c ? d : c;
   if (m - n + 1 != 4 && n - m + 1 != 4) {
     printf("WRONG SIZE...");
     goto q;
   }
   for (int i = (m > n ? n : m); i <= (m > n ? m : n); i++) {
     if (a == c) {
       baarr2[a - 1][i - 1] = 'O';
     } else {
       baarr2[i - 1][b - 1] = 'O';
     }
   }
   system("cls");
   badisplay2(1);
   e: printf("Enter for Ship of size 3: \nStarting Index: ");
   scanf("%d %d", & a, & b);
   if (bacheckinput(a, b) == 'Y')
     goto e;
   r: printf("Ending Index: ");
   if (bacheckinput(a, b) == 'Y')
     goto r;
   scanf("%d %d", & c, & d);
   m = a == c ? b : a;
   n = a == c ? d : c;
   if (m - n + 1 != 3 && n - m + 1 != 3) {
     printf("WRONG SIZE...");
     goto e;
   }
   for (int i = (m > n ? n : m); i <= (m > n ? m : n); i++) {
     if (a == c) {
       baarr2[a - 1][i - 1] = 'O';
     } else {
       baarr2[i - 1][b - 1] = 'O';
     }
   }
   system("cls");
   badisplay2(1);
   t: printf("Enter for Ship of size 3: \nStarting Index: ");
   scanf("%d %d", & a, & b);
   if (bacheckinput(a, b) == 'Y')
     goto t;
   y: printf("Ending Index: ");
   scanf("%d %d", & c, & d);
   if (bacheckinput(a, b) == 'Y')
     goto y;
   m = a == c ? b : a;
   n = a == c ? d : c;
   if (m - n + 1 != 3 && n - m + 1 != 3) {
     printf("WRONG SIZE...");
     goto t;
   }
   for (int i = (m > n ? n : m); i <= (m > n ? m : n); i++) {
     if (a == c) {
       baarr2[a - 1][i - 1] = 'O';
     } else {
       baarr2[i - 1][b - 1] = 'O';
     }
   }
   system("cls");
   badisplay2(1);
   u: printf("Enter for Ship of size 2: \nStarting Index: ");
   scanf("%d %d", & a, & b);
   if (bacheckinput(a, b) == 'Y')
     goto u;
   i: printf("Ending Index: ");
   if (bacheckinput(a, b) == 'Y')
     goto i;
   scanf("%d %d", & c, & d);
   m = a == c ? b : a;
   n = a == c ? d : c;
   if (m - n + 1 != 2 && n - m + 1 != 2) {
     printf("WRONG SIZE...");
     goto u;
   }
   for (int i = (m > n ? n : m); i <= (m > n ? m : n); i++) {
     if (a == c) {
       baarr2[a - 1][i - 1] = 'O';
     } else {
       baarr2[i - 1][b - 1] = 'O';
     }
   }
   system("cls");
   printf("YOUR SHIPS:\n\n");
   badisplay2(1);
   Sleep(5000);
   system("cls");
 }
 void bamain() {
   bainitialize();
   badisplay1(1);
   bainput1();
   badisplay2(1);
   bainput2();
   int flag = 1, cp = 1, r, c;
   while (bacheck1() != 1 && bacheck2() != 1) {
     printf("Player 1 attack on Player 2\n\n");
     badisplay2(2);
     g: printf("Enter row and column number for attack: ");
     scanf("%d %d", & r, & c);
     if (baarr2[r - 1][c - 1] == 'O') {
       system("cls");
       printf("YOU HIT A SHIP! (Enter again)\n");
       bar2[r - 1][c - 1] = 'O';
       badisplay2(2);
       goto g;
     } else {
       printf("YOU MISSED!");
     }
     if (bacheck2() == 1) {
       printf("PLAYER 1 WON !");
       break;
     }
     Sleep(2000);
     system("cls");
     printf("Player 2 attack on Player 1\n\n");
     badisplay1(2);
     h: printf("Enter row and column number for attack: ");
     scanf("%d %d", & r, & c);
     if (baarr1[r - 1][c - 1] == 'O') {
       system("cls");
       printf("YOU HIT A SHIP! (Enter again)\n");
       bar1[r - 1][c - 1] = 'O';
       badisplay1(2);
       goto h;
     } else {
       printf("YOU MISSED!");
     }
     if (bacheck1() == 1) {
       printf("PLAYER 2 WON !");
       break;
     }
     Sleep(2000);
     system("cls");
   }
 }
 int main()
 {
    bamain();
    return 0;
 }