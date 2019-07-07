#include <iostream>
#include<iomanip>
using namespace std;
const int MOD = 1e9+7;

// Output double precision 
void outf(double d,int f1=9){
  cout << fixed << setprecision(f1) << d;
}

// Power
long long power(long long x, long long n, long long mod = MOD) {
  long long ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= mod;
    (x *= x) %= mod;
    n >>= 1;
  }
  return ret;
}