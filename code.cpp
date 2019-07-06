#include<bits/stdc++.h>
 
using namespace std;
 
//container util
//------------------------------------------
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
 
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define REACH(i,c) for(typeof((c).end()) i=(c).end(); i!=(c).begin(); --i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

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
 

//grobal var
//------------------------------------------
LL dp[2000][2000];

int main(){
// magic spell------------------------------
  cin.tie(0);
  ios::sync_with_stdio(false);
//------------------------------------------
  int N,K;
  while(cin >> N >> K){
    int ans = 0;
    REP(i,N){

    }
    ans = 0;
    cout << ans << endl;
  }

  return 0;
}