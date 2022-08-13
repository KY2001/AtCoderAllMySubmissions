#include "algorithm"
#include "iostream"
#include "string"
#include "vector"

using namespace std; // std::を省略して書くことができる

int main() {
  int N, T;
  cin >> N >> T;
  int t[N];
  cin >> t[0];
  int sum = 0;
  for (int i = 0; i < N - 1; i++) {
    cin >> t[i + 1];
    sum += min(T, t[i + 1] - t[i]);
  }
  cout << sum + T << endl;
}