#include "bits/stdc++.h"
#define int long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define sqr(x) (x) * (x)
#define cube(x) (z) * (z) * (x)
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))
#define itn int

using namespace std;
using ll      = long long;
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e13 + 7);

template <class T = int>
int in() {
  T x;
  cin >> x;
  return x;
}

signed main() {
  string S;
  cin >> S;
  string piano = "WBWBWWBWBWBW";
  int loc;
  for (unsigned int i = 0; i < 12; i++) {
    FOR(j, i, min(i + 12, S.size())) {
      if (piano[j - i] != S[j]) {
        break;
      } else if (j == min(i + 12, S.size()) - 1) {
        loc = i;
        goto go;
      }
    }
  }
go:
  loc = (12 - loc) % 12;
  if (loc <= 1) {
    cout << "Do" << endl;
  } else if (loc <= 3) {
    cout << "Re" << endl;
  } else if (loc <= 4) {
    cout << "Mi" << endl;
  } else if (loc <= 6) {
    cout << "Fa" << endl;
  } else if (loc <= 8) {
    cout << "So" << endl;
  } else if (loc <= 10) {
    cout << "La" << endl;
  } else {
    cout << "Si" << endl;
  }
}
</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2020-04-20 19:22:56+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/abc039/tasks/abc039_c">C - ピアニスト高橋君</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/abc039/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view ky's submissions'></span></a></td>
				</tr>
				<tr>
					<th>Language</th>
					<td class="text-center">C++14 (GCC 5.4.1)</td>
				</tr>
				<tr>
					<th>Score</th>
					<td class="text-center">0</td>
				</tr>
				<tr>
					<th>Code Size</th>
					<td class="text-center">1426 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-warning' data-toggle='tooltip' data-placement='top' title="Compilation Error">CE</span></td>
				</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In function ‘int main()’:
./Main.cpp:32:35: error: no matching function for call to ‘min(long long unsigned int, std::basic_string<char>::size_type)’
     FOR(j, i, min(i + 12, S.size())) {
                                   ^
./Main.cpp:3:55: note: in definition of macro ‘FOR’
 #define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
                                                       ^
In file included from /usr/include/c++/5/bits/char_traits.h:39:0,
                 from /usr/include/c++/5/ios:40,
                 from /usr/include/c++/5/istream:38,
                 from /usr/include/c++/5/sstream:38,
                 from /usr/include/c++/5/complex:45,
                 from /usr/include/c++/5/ccomplex:38,
                 from /usr/include/x86_64-linux-gnu/c++/5/bits/stdc++.h:52,
                 from ./Main.cpp:1:
/usr/include/c++/5/bits/stl_algobase.h:195:5: note: candidate: template<class _Tp> constexpr const _Tp& std::min(const _Tp&, const _Tp&)
     min(const _Tp& __a, const _T...