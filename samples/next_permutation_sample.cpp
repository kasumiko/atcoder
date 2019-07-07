#include<bits/stdc++.h>
 
using namespace std;
 
//container util
//------------------------------------------
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
 
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define REACH(i,c) for(typeof((c).end()) i=(c).end(); i!=(c).begin(); --i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
 
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).begin(),(c).end(),greater<int>())
 
#define PB(a) push_back(a)
#define PF(a) pop_front(a)

#define MP(a,b) make_pair(a,b)
 
#define FS first
#define SE second
 
#define ALL(x) (x).begin(),(x).end()
#define MAX_EL(c) *max_element((c).begin(),(c).end())
#define MIN_EL(c) *min_element((c).begin(),(c).end())
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef string str;
 
//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
 
//Templates
//--------------------------------------------
template <typename T>
void cpmt(T *a,T *b,size_t size_a1,size_t size_a2){
  REP(i,size_a1){
    REP(j,size_a2){
      a[i][j] = b[i][j];
    }
  }
}

template <typename T>
void showmat(vector<vector<T>> a,size_t size_a1,size_t size_a2){
  REP(i,size_a1){
    REP(j,size_a2){
      cerr << a[i][j];
    }
    cerr << endl;
  }  
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

//grobal var
//------------------------------------------
const int MAX=500;

 
int main(){
// magic spell------------------------------
  cin.tie(0);
  ios::sync_with_stdio(false);
//------------------------------------------
  int N,M;
  while(cin >> N >> M){
    int ans=0;
    vector<vector<bool>> graph(N,vector<bool>(M,false));
    REP(i,M){
      int a,b;
      cin >> a >> b;
      a--;
      b--;
      graph[a][b]=graph[b][a]=true;
    }
    VI arr(N);
    REP(i,N){
      arr[i]=i;
    }
    do{
      ans++;
      FOR(i,1,N){
        if(!graph[arr[i-1]][arr[i]]){
          ans--;
          break;
        }
      }
    }while(next_permutation(arr.begin()+1,arr.end()));
    cout << ans << endl;
  }
  return 0;
}