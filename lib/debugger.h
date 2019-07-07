#include<iostream>
#include<vector>
using namespace std;
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)


//------show vector---------
template <typename T>
void showV(vector < T > a){
  EACH(i,a){
    cerr << *i << ',';
  }  
  cerr << endl;
}

//------show matrix---------
template <typename T>
void showVV(vector < vector < T > > a){
  EACH(i,a){
    showV(*i);
  }  
}