static int judgeResult = 0;
static const int Mod = 253;

static void printInt(int x) {
  judgeResult ^= x;
  judgeResult += 173;
}

static void printStr(const char *str) {
  for (const char *cur = str; *cur != 0; ++cur) {
    judgeResult ^= *cur;
    judgeResult += 521;
  }
}
