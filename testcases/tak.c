#include "io.inc"
static int tak(int x, int y, int z) {
  if (y < x)
    return 1 + tak(tak(x - 1, y, z), tak(y - 1, z, x), tak(z - 1, x, y));
  else
    return z;
}

int main(void) {
  int a = 18;
  int b = 12;
  int c = 6;
  printInt(tak(a, b, c));
  return judgeResult % Mod;  // 186
}
