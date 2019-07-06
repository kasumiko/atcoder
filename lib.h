#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
//--------------Union Find-----------------
struct UnionFind {
    vector<int> par; 
 
    UnionFind(int N) : par(N,-1) {} 
 
    int root(int x) { 
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }
 
    bool unite(int x, int y) { 
        x = root(x); 
        y = root(y); 
        if (x == y) return false; 
        if(size(x) < size(y))  swap(x,y);
        par[x] += par[y];
        par[y] = x; 
        return true;
    }
    bool same(int x, int y) { 
        return root(x) == root(y);
    }
    
    int size(int x){
      return -par[root(x)];
    }
};
//------copy matrix---------
template <typename T>
void cpmt(T *a,T *b,size_t size_a1,size_t size_a2){
  REP(i,size_a1){
    REP(j,size_a2){
      a[i][j] = b[i][j];
    }
  }
}

//------show matrix---------
template <typename T>
void showmat(vector<vector<T>> a,size_t size_a1,size_t size_a2){
  REP(i,size_a1){
    REP(j,size_a2){
      cerr << a[i][j];
    }
    cerr << endl;
  }  
}
//---------interval scheduling----------------------
struct interval {
  int s, f;
  interval(int s, int f) : s(s), f(f) { }
};
bool compare_f(const interval &x, const interval &y) {
  return x.f < y.f;
}
vector<interval> interval_scheduling(vector<interval> J) {
  vector<interval> A;
  sort(J.begin(), J.end(), compare_f);
  int f = 0;
  for (int i = 0; i < J.size(); ++i) {
    if (J[i].s >= f) {
      A.push_back(J[i]);
      f = J[i].f;
    }
  }
  return A;
}
//Greatest Common Devider
LL gcd(LL a,LL b){
  if(b == 0) return a;
  return gcd(b,a%b);
}
//------------------------------------------
//Least Common Multiple
//Must be used with GCD
LL lcm(LL a,LL b){
  LL g = gcd(a,b);
  return a / g * b;
}

// ---------------calculate combination nCk-----------
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//--------------
template< typename T > void modAdd(T& a, T b, T mod) { a = (a + b + mod) % mod; }
template< typename T > void modMul(T& a, T b, T mod) { a = (a * b) % mod; }
long long modPow(long long x, long long k) {
	long long ret = 1;	
	while (k > 0) {
		if (k & 1) modMul(ret, x, MOD);
		modMul(x, x, MOD);
		k >>= 1;
	}
	return ret;
}

// ax + by = gcd(a, b) となるような (x, y) を求める
// 多くの場合 a と b は互いに素として ax + by = 1 となる (x, y) を求める
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x); // 再帰的に解く
    y -= a / b * x;
    return d;
}

// 負の数にも対応した mod (a = -11 とかでも OK) 
inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}

// 逆元計算 (ここでは a と m が互いに素であることが必要)
long long modinv(long long a, long long m) {
    long long x, y;
    extGCD(a, m, x, y);
    return mod(x, m); // 気持ち的には x % m だが、x が負かもしれないので
}