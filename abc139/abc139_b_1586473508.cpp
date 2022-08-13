#include "algorithm"
#include "cmath"
#include "iostream"
#include "map"
#include "string"
#include "unordered_map"
#include "vector"
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
using namespace std;

int main() {
  double A, B;
  cin >> A >> B;
  cout << (int)ceil((B - 1) / (A - 1));
}
