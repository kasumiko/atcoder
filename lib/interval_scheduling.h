#include<vector>
#include<algorithm>
using namespace std;

struct interval {
  int s, f;
  interval(int inputs, int inputf) : s(inputs), f(inputf) { }
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