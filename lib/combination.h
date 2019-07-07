#include<iostream>
using namespace std;


const int MAX = 10000, MOD=1e9+7;
long long fact[MAX],finv[MAX],inv[MAX];

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

void cominit(int mod=MOD) {
  fact[0] = 1;
  for (int i = 1; i < MAX; ++i){
    fact[i] = (fact[i - 1] * i) % mod;
  }
  finv[MAX-1] = modinv(fact[MAX-1]);
  for (int i = MAX-2; i >= 0;--i){
    finv[i] = (finv[i+1]*(i+1))%mod;
  }
}

long long nCk(int n, int k,int mod=MOD){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fact[n] * (finv[k] * finv[n - k] % mod) % mod;
}