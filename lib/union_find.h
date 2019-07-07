#include <vector>
using namespace std;

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