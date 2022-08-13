#include "C:/Users/yukiy/Desktop/jhelper-example-project-master/tasks/CLinearApproximation.cpp"

#include <cctype>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace jhelper {

struct Test {
  std::string input;
  std::string output;
  bool active;
  bool has_output;
};

bool check(std::string expected, std::string actual) {
  while (!expected.empty() && isspace(*--expected.end()))
    expected.erase(--expected.end());
  while (!actual.empty() && isspace(*--actual.end()))
    actual.erase(--actual.end());
  return expected == actual;
}

} // namespace jhelper

signed main() {
  std::vector<jhelper::Test> tests = { {"5\n2 2 3 5 5\n", "2\n", true, true},{"9\n1 2 3 4 5 6 7 8 9\n", "0\n", true, true},{"6\n6 5 4 3 2 1\n", "18\n", true, true},{"7\n1 1 1 1 2 3 4\n", "6\n", true, true}, };
  bool allOK = true;
  int testID = 0;
  std::cout << std::fixed;
  double maxTime = 0.0;
  for (const jhelper::Test &test : tests) {
    std::cout << "Test #" << ++testID << std::endl;
    std::cout << "Input: \n" << test.input << std::endl;
    if (test.has_output) {
      std::cout << "Expected output: \n" << test.output << std::endl;
    } else {
      std::cout << "Expected output: \n"
                << "N/A" << std::endl;
    }
    if (test.active) {
      std::stringstream in(test.input);
      std::ostringstream out;
      std::clock_t start = std::clock();
      CLinearApproximation solver;
      solver.solve(in, out); std::clock_t finish = std::clock();
      double currentTime = double(finish - start) / CLOCKS_PER_SEC;
      maxTime = std::max(currentTime, maxTime);
      std::cout << "Actual output: \n" << out.str() << std::endl;
      if (test.has_output) {
        bool result = jhelper::check(test.output, out.str());
        allOK = allOK && result;
        std::cout << "Result: " << (result ? "OK" : "Wrong answer")
                  << std::endl;
      }
      std::cout << "Time: " << currentTime << std::endl;
    } else {
      std::cout << "SKIPPED\n";
    }

    std::cout << std::endl;
  }
  if (allOK) {
    std::cout << "All OK" << std::endl;
  } else {
    std::cout << "Some cases failed" << std::endl;
  }
  std::cout << "Maximal time: " << maxTime << "s." << std::endl;
  return 0;
}
</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2020-04-25 13:05:37+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/abc102/tasks/arc100_a">C - Linear Approximation</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/abc102/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
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
					<td class="text-center">2366 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-warning' data-toggle='tooltip' data-placement='top' title="Compilation Error">CE</span></td>
				</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp:1:96: fatal error: C:/Users/yukiy/Desktop/jhelper-example-project-master/tasks/CLinearApproximation.cpp: No such file or directory
 #include "C:/Users/yukiy/Desktop/jhelper-example-project-master/tasks/CLinearApproximation.cpp"
                                                                                                ^
compilation terminated.
