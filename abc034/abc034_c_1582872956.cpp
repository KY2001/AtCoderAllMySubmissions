import sys
import math
import fractions
import itertools
from collections import deque
import copy
import bisect

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

W, H = map(int, input().split())
ans = 0


def nck(n, k, mod):
    """
     O(n)でnCkを返す関数。
    """

    def continuous_inv(n, mod):
        """
        O(n)で1からnまでの範囲の逆元のリストを返す。
        """
        inv_list = [1]  # 0で割るというのは定義されないので無視。
        for i in range(n):
            inv_list.append(int(mod - inv_list[(mod % (i + 2)) - 1] * (mod // (i + 2)) % mod))
        return inv_list

    inv_list = continuous_inv(max(k, n - k), mod)
    return_value = 1
    for i in range(2, n + 1):
        return_value *= i
        return_value %= mod
    for i in range(k):
        return_value *= inv_list[i]
        return_value %= mod
    for i in range(n - k):
        return_value *= inv_list[i]
        return_value %= mod
    return return_value


print(nck(W + H - 2, W - 1, MOD))
</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2020-02-28 15:55:56+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/abc034/tasks/abc034_c">C - 経路</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/abc034/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view ky's submissions'></span></a></td>
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
					<td class="text-center">1109 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-warning' data-toggle='tooltip' data-placement='top' title="Compilation Error">CE</span></td>
				</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp:18:7: warning: missing terminating " character
     """
       ^
./Main.cpp:18:5: error: missing terminating " character
     """
     ^
./Main.cpp:19:6: error: stray ‘\343’ in program
      O(n)でnCkを返す関数。
      ^
./Main.cpp:19:6: error: stray ‘\201’ in program
./Main.cpp:19:6: error: stray ‘\247’ in program
./Main.cpp:19:6: error: stray ‘\343’ in program
./Main.cpp:19:6: error: stray ‘\202’ in program
./Main.cpp:19:6: error: stray ‘\222’ in program
./Main.cpp:19:6: error: stray ‘\350’ in program
./Main.cpp:19:6: error: stray ‘\277’ in program
./Main.cpp:19:6: error: stray ‘\224’ in program
./Main.cpp:19:6: error: stray ‘\343’ in program
./Main.cpp:19:6: error: stray ‘\201’ in program
./Main.cpp:19:6: error: stray ‘\231’ in program
./Main.cpp:19:6: error: stray ‘\351’ in program
./Main.cpp:19:6: error: stray ‘\226’ in program
./Main.cpp:19:6: error: stray ‘\242’ in program
./Main.cpp:19:6: error: stray ‘\346’ in program
./Main.cpp:19:6: error: stray ‘\225’ in program
./Main.cpp:19:6: error: stra...