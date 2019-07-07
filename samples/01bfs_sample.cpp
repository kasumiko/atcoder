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
  str ans="ERR";
  int H,W;
  while(cin >> H >> W){
    VVI maps(MAX,VI(MAX,-3));
    PII go;
    deque <PII> q;
    REP(i,H){
      str row;
      cin >> row;
      REP(j,W){
        maps[i][j]++;
        if(row[j]=='s') {
          q.PB(MP(i,j));
          maps[i][j]=0;
        }
        else if(row[j]=='.') {
          maps[i][j]++;
        }
        else if(row[j]=='g') {
          go = MP(i,j);
          maps[i][j]++;
        }
      }
    }
    int x,y;
    PII cur = q.front();
    while(!q.empty()){
      q.pop_front();
      y = cur.FS;
      x = cur.SE;
      if(maps[y][x]>2){
        ans="NO";
        break;
      }
      if(MP(y,x)==go){
        ans="YES";
        break;
      }
      if(y>0&&maps[y-1][x]==-1){
        maps[y-1][x]=maps[y][x]; 
        q.push_front(MP(y-1,x));
      }
      if(y<H-1&&maps[y+1][x]==-1){
        maps[y+1][x]=maps[y][x]; 
        q.push_front(MP(y+1,x));
      }
      if(x>0&&maps[y][x-1]==-1){
        maps[y][x-1]=maps[y][x]; 
        q.push_front(MP(y,x-1));
      }
      if(x<W-1&&maps[y][x+1]==-1){
        maps[y][x+1]=maps[y][x]; 
        q.push_front(MP(y,x+1));
      }
      if(y>0&&maps[y-1][x]==-2){
        maps[y-1][x]=maps[y][x]+1; 
        q.PB(MP(y-1,x));
      }
      if(y<H-1&&maps[y+1][x]==-2){
        maps[y+1][x]=maps[y][x]+1; 
        q.PB(MP(y+1,x));
      }
      if(x>0&&maps[y][x-1]==-2){
        maps[y][x-1]=maps[y][x]+1; 
        q.PB(MP(y,x-1));
      }
      if(x<W-1&&maps[y][x+1]==-2){
        maps[y][x+1]=maps[y][x]+1; 
        q.PB(MP(y,x+1));
      }
      cur = q.front();
    }

    cout << ans << endl;
  }
  return 0;
}