using namespace std;

//Greatest Common Devider
template <typename T>
T gcd(T a,T b){
  if(b == 0) return a;
  return gcd(b,a%b);
}
//------------------------------------------
//Least Common Multiple
//Must be used with GCD
template <typename T>
T lcm(T a,T b){
  T g = gcd(a,b);
  return a / g * b;
}