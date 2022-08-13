#include "algorithm"
#include "iostream"
#include "string"
#include "vector"

using namespace std; // std::を省略して書くことができる

int main() {
  int N;
  cin >> N;
  int a[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  int transparent = 0;
  for (int i = 0; i < N; i++) {
    if (a[i] >= 3200) {
      transparent += 1;
    }
  }
  int num = 0;
  for (int i = 0; i < 8; i++) {
    for (int k = 0; k < N; k++) {
      if (400 * i <= a[k] && a[k] < 400 * (i + 1)) {
        num += 1;
        break;
      }
      else{

      }
    }
  }
  cout << num << " " << min(num + transparent, 8) << endl;
}