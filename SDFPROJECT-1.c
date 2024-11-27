/*
 THIS PROJECT IS MADE FOR SDF-1 PBL.
 INSTITUE: JAYPEE INSTITUTE OF INFORMATION TECHNOLOGY
 BATCH : B12
 CREDITS TO:
 PRAKHAR ARORA   :  2401030123
 DEVANSH AGARWAL :  2401030103
 KUSHAAN VADEHRA :  2401030115
 RUVIR GANDHI    :  2401030117
*/


#include<stdio.h>

#include<string.h>

#include<stdlib.h>

#include<time.h>

#include<windows.h>

#include<unistd.h>

/*
ti refers to tic tac toe
fo refers to four in a row
ba refers to battleship
wo refers to wordle
*/

char tiarr[3][3];
char foarr[9][9];
int foarr2[9];
char woarr[25][25];
char wostr[50][20];
int wostrs[5];
int wostrconfig[5][3];
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

void foinitialize() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      foarr[i][j] = ' ';
    }
  }
  for (int i = 0; i < 9; i++) {
    foarr2[i] = 9;
  }
}

//function to check if the game has ended
int focheck(int a, int b) {
  int k, l;

  //Checking for horizontal
  int count = 0;
  int max = 0;
  k = a;
  l = b - 3;
  for (int i = 0; i < 7; i++) {
    if (l < 0 || l > 9) {
      l++;
      continue;
    }
    if (foarr[k][l++] == foarr[a][b]) {
      count++;
    } else
      count = 0;
    if (count > max)
      max = count;
  }
  if (max >= 4)
    return 1;

  //Checking for vertical
  count = 0;
  max = 0;
  k = a - 3;
  l = b;
  for (int i = 0; i < 7; i++) {
    if (k < 0 || k > 9) {
      k++;
      continue;
    }
    if (foarr[k++][l] == foarr[a][b]) {
      count++;
    } else
      count = 0;
    if (count > max)
      max = count;
  }
  if (max >= 4)
    return 1;

  //Checking for left diagonal
  count = 0;
  max = 0;
  k = a - 3;
  l = b - 3;
  for (int i = 0; i < 7; i++) {
    if ((k < 0 || k > 9) || (l < 0 || l > 9)) {
      l++;
      k++;
      continue;
    }
    if (foarr[k++][l++] == foarr[a][b]) {
      count++;
    } else
      count = 0;
    if (count > max)
      max = count;
  }
  if (max >= 4)
    return 1;

  //Checking for right diagonal
  count = 0;
  max = 0;
  k = a - 3;
  l = b + 3;
  for (int i = 0; i < 7; i++) {
    if ((k < 0 || k > 9) || (l < 0 || l > 9)) {
      l--;
      k++;
      continue;
    }
    if (foarr[k++][l--] == foarr[a][b]) {
      count++;
    } else
      count = 0;
    if (count > max)
      max = count;
  }
  if (max >= 4)
    return 1;

  return 0;
}

void fodisplay() {
  for (int i = 0; i <= 9; i++) {
    if (i < 9) {
      for (int j = 0; j < 9; j++) {
        if (j != 8)
          printf("%c  |", foarr[i][j]);
        else
          printf("%c  ", foarr[i][j]);
      }
      printf("\n");
      for (int j = 0; j <= 35; j++) {
        printf("-");
      }
      printf("\n");
    }
    if (i == 9) {
      printf(" ");
      for (int j = 1; j <= 9; j++)
        printf("%d   ", j);
      printf("\n");
    }

  }
}

//function to input cross or circle and to also call check function
int foinput(int t) {
  //variable to store column number
  int b;
  if (t == 1) {
    printf("\nPlayer 1's turn");
    printf("\nEnter the column (1,2,3,4,5,6,7,8,9) : ");
    scanf("%d", & b);
    if (foarr[foarr2[b - 1] - 1][b - 1] != ' ') {
      printf("The grid space is already occupied, please enter again!\n");
      return foinput(t);
    } else {
      foarr[--foarr2[b - 1]][b - 1] = 'X';
      int re = focheck(foarr2[b - 1], b - 1);
      return re;
    }

  } else {
    printf("\nPlayer 2's turn");
    printf("\nEnter the column (1,2,3,4,5,6,7,8,9) : ");
    scanf("%d", & b);
    if (foarr[foarr2[b - 1] - 1][b - 1] != ' ') {
      printf("The grid space is already occupied, please enter again!\n");
      return foinput(t);
    } else {
      foarr[--foarr2[b - 1]][b - 1] = 'O';
      int re = focheck(foarr2[b - 1], b - 1);
      return re;
    }
  }

}

void fomain() {
  foinitialize();
  fodisplay();
  //variable for player's turn
  int turn = 1;
  //variable to store how many moves has been made
  int count = 0;
  //variable to store whether someone has won the game or not
  int res = 0;
  while (1) {
    if (count == 81) {
      printf("The game is a DRAW!");
      break;
    }
    if (turn == 1) {
      res = foinput(turn);
      count++;
      fodisplay();
      if (res) {
        printf("Player 1 WON!");
        break;
      }
      turn = 2;
    } else {
      res = foinput(turn);
      count++;
      fodisplay();
      if (res) {
        printf("Player 2 WON!");
        break;
      }
      turn = 1;
    }

  }
}

void tiinitialize() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      tiarr[i][j] = ' ';
    }
  }
}

//function to input cross or circle
void tiinput(int t) {
  //variable to store row number
  int a;
  //variable to store column number
  int b;
  if (t == 1) {
    printf("Player 1's move\nEnter the row (1,2,3) : ");
    scanf("%d", & a);
    printf("\nEnter the column (1,2,3) : ");
    scanf("%d", & b);
    if (tiarr[a - 1][b - 1] != ' ') {
      printf("The grid space is already occupied, please enter again!\n");
      tiinput(t);
    } else
      tiarr[a - 1][b - 1] = 'X';
  } else {
    printf("Player 2's move\nEnter the row (1,2,3) : ");
    scanf("%d", & a);
    printf("\nEnter the column (1,2,3) : ");
    scanf("%d", & b);
    if (tiarr[a - 1][b - 1] != ' ') {
      printf("The grid space is already occupied, please enter again!\n");
      tiinput(t);
    } else
      tiarr[a - 1][b - 1] = 'O';
  }
}
//function to check if the game has ended
int ticheck() {
  //variable to keep count to consecutive cross or circle
  int count = 0;
  //checking for upper row
  for (int i = 0; i < 2; i++) {
    if (tiarr[0][i] != tiarr[0][i + 1]) {
      count = 1;
      break;
    }
  }
  if (count == 0 && tiarr[0][0] != ' ')
    return 1;
  count = 0;
  //checking for middle row
  for (int i = 0; i < 2; i++) {
    if (tiarr[1][i] != tiarr[1][i + 1]) {
      count = 1;
      break;
    }
  }
  if (count == 0 && tiarr[1][0] != ' ')
    return 1;
  count = 0;
  //checking for lower row
  for (int i = 0; i < 2; i++) {
    if (tiarr[2][i] != tiarr[2][i + 1]) {
      count = 1;
      break;
    }
  }
  if (count == 0 && tiarr[2][0] != ' ')
    return 1;
  count = 0;
  //checking for first column
  for (int i = 0; i < 2; i++) {
    if (tiarr[i][0] != tiarr[i + 1][0]) {
      count = 1;
      break;
    }
  }
  if (count == 0 && tiarr[0][0] != ' ')
    return 1;
  count = 0;
  //checking for second column
  for (int i = 0; i < 2; i++) {
    if (tiarr[i][1] != tiarr[i + 1][1]) {
      count = 1;
      break;
    }
  }
  if (count == 0 && tiarr[0][1] != ' ')
    return 1;
  count = 0;
  //checking for third column
  for (int i = 0; i < 2; i++) {
    if (tiarr[i][2] != tiarr[i + 1][2]) {
      count = 1;
      break;
    }
  }
  if (count == 0 && tiarr[0][2] != ' ')
    return 1;
  count = 0;
  //checking for left diagonal
  for (int i = 0; i < 2; i++) {
    if (tiarr[i][i] != tiarr[i + 1][i + 1]) {
      count = 1;
      break;
    }
  }
  if (count == 0 && tiarr[0][0] != ' ')
    return 1;
  count = 0;
  //checking for right diagonal
  for (int i = 0; i < 2; i++) {
    if (tiarr[i][2 - i] != tiarr[i + 1][1 - i]) {
      count = 1;
      break;
    }
  }
  if (count == 0 && tiarr[0][2] != ' ')
    return 1;
  count = 0;

  return 0;

}

//function to display the tic tac toe grid
void tidisplay() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (j != 2)
        printf("%c |", tiarr[i][j]);
      else
        printf("%c ", tiarr[i][j]);
    }
    printf("\n");
    if (i != 2) {
      for (int j = 0; j <= 8; j++) {
        printf("-");
      }
      printf("\n");
    }

  }
}
void timain() {
  tiinitialize();
  tidisplay();
  //variable for player's turn
  int turn = 1;
  //variable to store how many moves has been made
  int count = 0;
  while (1) {
    if (count == 9) {
      printf("The game is a DRAW!");
      break;
    }
    if (turn == 1) {
      tiinput(turn);
      count++;
      tidisplay();
      if (ticheck()) {
        printf("Player 1 WON!");
        break;
      }
      turn = 2;
    } else {
      tiinput(turn);
      count++;
      tidisplay();
      if (ticheck()) {
        printf("Player 2 WON!");
        break;
      }
      turn = 1;
    }

  }
}

void woinitialize() {
  srand(time(0));
  //Making a word library to store words
  strcpy(wostr[0], "factor");
  strcpy(wostr[1], "ambience");
  strcpy(wostr[2], "dog");
  strcpy(wostr[3], "table");
  strcpy(wostr[4], "prakhar");
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
  int count = 0;
  for (int i = 0; i < 5; i++) {
    int rsw = rand() % 50;
    int ch = 0;
    for (int j = 0; j < count; j++) {
      if (rsw == wostrs[j]) {
        ch = 1;
        break;
      }
    }
    if (ch == 1) {
      i--;
      continue;
    }

    wostrs[count++] = rsw;
  }

  for (int i = 0; i < 5; i++) {
    int or, word;
    or = rand() % 4;
    int r, c;
    r = rand() % 25;
    c = rand() % 25;
    int check = 0;
    int test = strlen(wostr[wostrs[i]]);
    //0 for left
    //1 for right
    //2 for up
    //3 for down

    switch (or) {
      //0 for left
    case 0:
      //checking if the word can fit
      if (c - test < 0) {
        check = 1;
        break;
      }
      //checking if space is empty
      for (int j = c; j > c - test; j--) {
        if (woarr[r][j] != '\0') {
          check = 1;
          break;
        }
      }
      if (check == 1) {
        break;
      }
      for (int j = c; j > c - test; j--) {
        woarr[r][j] = wostr[wostrs[i]][c - j];
      }
      wostrconfig[i][0] = r;
      wostrconfig[i][1] = c;
      wostrconfig[i][2] = or;
      break;

      //1 for right
    case 1:
      //checking if the word can fit
      if (c + test > 25) {
        check = 1;
        break;
      }
      //checking if space is empty
      for (int j = c; j < c + test; j++) {
        if (woarr[r][j] != '\0') {
          check = 1;
          break;
        }
      }
      if (check == 1) {
        break;
      }
      for (int j = c; j < c + test; j++) {
        woarr[r][j] = wostr[wostrs[i]][j - c];
      }
      wostrconfig[i][0] = r;
      wostrconfig[i][1] = c;
      wostrconfig[i][2] = or;
      break;

      //2 for upwards
    case 2:
      //checking if the word can fit
      if (r - test < 0) {
        check = 1;
        break;
      }
      //checking if space is empty
      for (int j = r; j > r - test; j--) {
        if (woarr[j][c] != '\0') {
          check = 1;
          break;
        }
      }
      if (check == 1) {
        break;
      }
      for (int j = r; j > r - test; j--) {
        woarr[j][c] = wostr[wostrs[i]][r - j];
      }
      wostrconfig[i][0] = r;
      wostrconfig[i][1] = c;
      wostrconfig[i][2] = or;
      break;

      //3 for downwards
    case 3:
      //checking if the word can fit
      if (r + test > 25) {
        check = 1;
        break;
      }
      //checking if space is empty
      for (int j = r; j < r + test; j++) {
        if (woarr[j][c] != '\0') {
          check = 1;
          break;
        }
      }
      if (check == 1) {
        break;
      }
      for (int j = r; j < r + test; j++) {
        woarr[j][c] = wostr[wostrs[i]][j - r];
      }
      wostrconfig[i][0] = r;
      wostrconfig[i][1] = c;
      wostrconfig[i][2] = or;
      break;

    }
    if (check == 1) {
      i = i - 1;
      continue;
    }
  }

  //randomly assigning characters to empty spaces
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 26; j++) {
      if (woarr[i][j] == '\0')
        woarr[i][j] = (char)(rand() % 26 + 97);
    }
  }

}

void wodisplay() {
  printf("\n      ");
  for (int i = 0; i < 25; i++) {
    printf("%-2d ", i + 1);
  }
  printf("\n");
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 26; j++) {
      if (j == 0) {
        printf("%-2d-   ", i + 1);
        continue;
      }
      if (woarr[i][j - 1] == '\0')
        printf("  |");
      else
        printf("%c |", woarr[i][j - 1]);
    }
    printf("\n");
  }
}

void woworddisplay() {
  for (int i = 0; i < 5; i++) {
    if (wostrs[i] == -1)
      continue;
    printf("\n%d : %s", i + 1, wostr[wostrs[i]]);
  }
}

int wocheck(int a, int b, int or, int n) {
  if (wostrconfig[n][0] == a && wostrconfig[n][1] == b && wostrconfig[n][2] == or) {
    system("cls");
    printf("\nCongratulations, You found the word ");
    sleep(3);
    wostrs[n] = -1;
  } else {
    system("cls");
    printf("\nWrong answer ");
    sleep(3);
    return 0;
  }
  int count = 0;
  for (int i = 0; i < 5; i++) {
    if (wostrs[i] == -1)
      count++;
  }
  if (count == 5)
    return 1;
  else
    return 0;

}

void woinput() {
  wodisplay();
  woworddisplay();
  int n;
  printf("\nEnter the word number you have found : ");
  scanf("%d", & n);
  if (wostrs[n - 1] == -1) {
    printf("You have already found the word");
    system("cls");
    woinput();
  } else {
    printf("\nEnter the row and column index : ");
    int a, b;
    scanf("%d %d", & a, & b);
    printf("\nEnter the orientation of word 1-LEFT 2-RIGHT 3-UP 4-DOWN : ");
    int or;
    scanf("%d", & or);
    int ans = wocheck(a - 1, b - 1, or - 1, n - 1);
    system("cls");
    if (ans)
      printf("\nCongratulation! You have found all the words");
    else
      woinput();
  }

}

void womain() {
  woinitialize();
  woinput();
}

int main() {
  while (1) {
    system("cls");
    printf("\nWhat do you wanna play?");
    printf("\n1-TIC TAC TOE");
    printf("\n2-FOUR IN A ROW");
    printf("\n3-WORDLE");
    printf("\n4-BATTLESHIP");
    printf("\n5-I AM GONNA PLAY ON PS5 (EXIT)");
    printf("\nEnter Your Choice : ");
    int n;
    scanf("%d", & n);
    system("cls");
    if (n == 1) {
      timain();
    } else
    if (n == 2) {
      fomain();
    } else
    if (n == 3) {
      womain();
    } else
    if (n == 4) {
      bamain();
    }
    if (n == 5) {
      printf("BYE! HAVE FUN");
      break;
    }
    sleep(3);

  }
  return 0;
}