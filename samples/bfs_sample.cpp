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
const int MAX_R=50;

 
int main(){
// magic spell------------------------------
  cin.tie(0);
  ios::sync_with_stdio(false);
//------------------------------------------
  int ans=-1;
  int R,C;
  while(cin >> R >> C){
    VVI maps(MAX_R,VI(MAX_R,-2));
    PII st, go;
    int cntw=0;
    st = MP(0,0);
    go = MP(R-1,C-1);
    REP(i,R){
      str row;
      cin >> row;
      REP(j,C){
        if(row[j]=='.') {
          maps[i][j]++;  
          cntw++;
        }
      }
    }
    if(maps[0][0]==-2||maps[R-1][C-1]==-2){
      cout << ans << endl;
      return 0;
    }
    deque <PII> q;
    q.PB(st);
    maps[st.FS][st.SE]++;
    PII cur = q.front();
    int x,y;
    while(!q.empty()){
      y = cur.FS;
      x = cur.SE;
      if(y>0&&maps[y-1][x]==-1){
        maps[y-1][x]=maps[y][x]+1; 
        q.PB(make_pair(y-1,x));
      }
      if(y<R-1&&maps[y+1][x]==-1){
        maps[y+1][x]=maps[y][x]+1; 
        q.PB(make_pair(y+1,x));
      }
      if(x>0&&maps[y][x-1]==-1){
        maps[y][x-1]=maps[y][x]+1; 
        q.PB(make_pair(y,x-1));
      }
      if(x<C-1&&maps[y][x+1]==-1){
        maps[y][x+1]=maps[y][x]+1; 
        q.PB(make_pair(y,x+1));
      }
      q.pop_front();
      cur = q.front();
    }
    if(maps[R-1][C-1]>0) ans = cntw-maps[go.FS][go.SE]-1;
    cout << ans << endl;
  }
  return 0;
}