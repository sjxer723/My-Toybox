#include "io.inc"

static int N = 8;
static int row[8];
static int col[8];
static int d[2][16];

static void printBoard(void) {
  int i;
  int j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (col[i] == j)
          printStr(" O");
      else
          printStr(" .");
    }
    printStr("\n");
  }
  printStr("\n");
}

static void search(int c) {
  if (c == N) {
    printBoard();
  } else {
    int r;
    for (r = 0; r < N; r++) {
      if (row[r] == 0 && d[0][r + c] == 0 && d[1][r + N - 1 - c] == 0) {
        row[r] = d[0][r + c] = d[1][r + N - 1 - c] = 1;
        col[c] = r;
        search(c + 1);
        row[r] = d[0][r + c] = d[1][r + N - 1 - c] = 0;
      }
    }
  }
}

int main(void) {
  search(0);
  return judgeResult % Mod;  // 171
}
