/*
Important note: the Fibonacci sequence is often defined with its first 2 numbers as F0 = 0 and F1 = 1. For the purpose of this question, the first Fibonacci number is F0; therefore, getNthFib(1) is equal to F0, getNthFib(2) is equal to F1, etc..

Sample input #1: 2
Sample ouput #1: 1(0, 1)
Sample input #2: 6
Sample ouput #2: 5(0, 1, 1, 2, 3, 5)
*/

using namespace std;

int mem[256] = {0};

int getNthFib(int n) {
  // Write your code here.
        int ret = 0;

        if (0 <= n) {
                if (0 == n or 1 == n)
                        return 0;
                else if (2 == n or 3 == n)
                        return 1;
                else {
                        int fibArr[] = {1, 1};
                        for (int i = 4; i <= n; i++) {
                                ret = fibArr[0] + fibArr[1];
                                fibArr[0] = fibArr[1];
                                fibArr[1] = ret;
                        }
                        return ret;
                }
        }
  return -1;
}

// Add, edit, or remove tests in this file.
// Treat it as your playground!

#include "program.cpp"

class ProgramTest : public TestSuite {
public:
  void Run() {

    RunTest("Test Case 1", []() { assert(getNthFib(1) == 0); });

    RunTest("Test Case 2", []() { assert(getNthFib(2) == 1); });

    RunTest("Test Case 3", []() { assert(getNthFib(3) == 1); });

    RunTest("Test Case 4", []() { assert(getNthFib(4) == 2); });

    RunTest("Test Case 5", []() { assert(getNthFib(5) == 3); });

    RunTest("Test Case 6", []() { assert(getNthFib(6) == 5); });

    RunTest("Test Case 7", []() { assert(getNthFib(7) == 8); });

    RunTest("Test Case 8", []() { assert(getNthFib(8) == 13); });

    RunTest("Test Case 9", []() { assert(getNthFib(9) == 21); });

    RunTest("Test Case 10", []() { assert(getNthFib(10) == 34); });

    RunTest("Test Case 11", []() { assert(getNthFib(11) == 55); });

    RunTest("Test Case 12", []() { assert(getNthFib(12) == 89); });

    RunTest("Test Case 13", []() { assert(getNthFib(13) == 144); });

    RunTest("Test Case 14", []() { assert(getNthFib(14) == 233); });

    RunTest("Test Case 15", []() { assert(getNthFib(15) == 377); });

    RunTest("Test Case 16", []() { assert(getNthFib(16) == 610); });

    RunTest("Test Case 17", []() { assert(getNthFib(17) == 987); });

    RunTest("Test Case 18", []() { assert(getNthFib(18) == 1597); });
  }
};