#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

long long extgcd(long long a, long long b, long long &x, long long &y) {
  long long g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}

long long modinv(int a, int m=MOD) {
  long long x, y;
  if (extgcd(a, m, x, y) == 1) return (x + m) % m;
  else                         return 0; // unsolvable
}