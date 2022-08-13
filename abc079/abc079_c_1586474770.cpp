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
  int A, B, C, D;
  string temp;
  cin >> temp;
  A             = temp[0] - '0';
  B             = temp[1] - '0';
  C             = temp[2] - '0';
  D             = temp[3] - '0';
  string parity = "+++";
  if (A + B + C + D == 7) {

  } else if (A - B + C + D == 7) {
    parity[0] = '-';

  } else if (A + B - C + D == 7) {
    parity[1] = '-';
  } else if (A + B + C - D == 7) {
    parity[2] = '-';
  } else if (A - B - C + D == 7) {
    parity[0] = '-';
    parity[1] = '-';
  } else if (A - B + C - D == 7) {
    parity[0] = '-';
    parity[2] = '-';
  } else if (A + B - C - D == 7) {
    parity[1] = '-';
    parity[2] = '-';
  } else {
    parity = "---";
  }
  cout << A << parity[0] << B << parity[1] << C << parity[2] << D << "=7" << endl;
}
