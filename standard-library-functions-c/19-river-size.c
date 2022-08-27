/*
You are given a two-dimensional array (matrix) of potentially unequal height and width containing only 0s and 1s. Each 0 represents land, and each 1 represents part of a river. A river consists of any number of 1s that are either horizontally or vertically adjacent (but not diagonally adjacent). The number of adjacent 1s forming a river determine its size. Write a function that returns an array of the sizes of all rivers represented in the input matrix. Note that these sizes do not need to be in any particular order.

Sample input:
[
[1, 0, 0, 1, 0],
[1, 0, 1, 0, 0],
[0, 1, 1, 0, 1],
[0, 1, 0, 1, 0],
[0, 0, 1, 1, 1]
]
Sample output: [2, 1, 4, 4]
*/

#include <vector>
using namespace std;
int traverseRiver(vector<vector<int>> &matrix, int x, int y, vector<vector<int>> &mem) {
    // cout << "traverseRiver 1" << endl;
    int tmp = 0;
    if (matrix[x][y] == 1) {
        mem[x][y] = 1;
        if (0 < x) {
            if (matrix[x - 1][y] == 1 &&
                 mem[x - 1][y] == 0)
                tmp += traverseRiver(matrix, x - 1, y, mem);
        }
        if (x < matrix.size() - 1) {
            if (matrix[x + 1][y] == 1 &&
                 mem[x + 1][y] == 0)
                tmp += traverseRiver(matrix, x + 1, y, mem);
        }
        if (0 < y) {
            if (matrix[x][y - 1] == 1 &&
                 mem[x][y - 1] == 0)
                tmp += traverseRiver(matrix, x, y - 1, mem);
        }
        if (y < matrix[0].size() - 1) {
            if (matrix[x][y + 1] == 1 &&
                 mem[x][y + 1] == 0)
                tmp += traverseRiver(matrix, x, y + 1, mem);
        }
        return tmp + 1;
    }

    return 0;
}

vector<int> riverSizes(vector<vector<int>> matrix) {
  // Write your code here.
    vector<vector<int>> memoize(matrix.size(), vector<int>(matrix[0].size(), 0));
    vector<int> retSizes;
    int rSize;

    cout << "riverSizes 1, " << matrix.size() <<
        ", " << matrix[0].size() << endl;

    for (int i = 0; i < matrix.size(); i++) {
        // cout << "riverSizes 2" << endl;
        for (int j = 0; j < matrix[i].size(); j++) {
            // cout << "riverSizes 3: " << j << endl;
            if (memoize[i][j] == 0) {
                // cout << "riverSizes 4: " << i << ", " <<
                //     j << endl;
                rSize = traverseRiver(matrix, i, j, memoize);
                if (rSize != 0) {
                    cout << "riverSizes 5: " << rSize << endl;
                    retSizes.push_back(rSize);
                }
            }
        }
    }
  return retSizes;
}

// Add, edit, or remove tests in this file.
// Treat it as your playground!

#include "program.cpp"
#include <algorithm>

class ProgramTest : public TestSuite {
public:
  void Run() {

    RunTest("Test Case 1", []() {
      vector<vector<int>> testInput{{0}};
      vector<int> expected{};
      vector<int> output = riverSizes(testInput);
      sort(output.begin(), output.end());
      assert(output == expected);
    });

    RunTest("Test Case 2", []() {
      vector<vector<int>> testInput{{1}};
      vector<int> expected{1};
      vector<int> output = riverSizes(testInput);
      sort(output.begin(), output.end());
      assert(output == expected);
    });

    RunTest("Test Case 3", []() {
      vector<vector<int>> testInput{{1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0}};
      vector<int> expected{1, 2, 3};
      vector<int> output = riverSizes(testInput);
      sort(output.begin(), output.end());
      assert(output == expected);
    });

    RunTest("Test Case 4", []() {
      vector<vector<int>> testInput{
          {1, 0, 0, 1},
          {1, 0, 1, 0},
          {0, 0, 1, 0},
          {1, 0, 1, 0},
      };
      vector<int> expected{1, 1, 2, 3};
      vector<int> output = riverSizes(testInput);
      sort(output.begin(), output.end());
      assert(output == expected);
    });

    RunTest("Test Case 5", []() {
      vector<vector<int>> testInput{
          {1, 0, 0, 1, 0}, {1, 0, 1, 0, 0}, {0, 0, 1, 0, 1},
          {1, 0, 1, 0, 1}, {1, 0, 1, 1, 0},
      };
      vector<int> expected{1, 2, 2, 2, 5};
      vector<int> output = riverSizes(testInput);
      sort(output.begin(), output.end());
      assert(output == expected);
    });

    RunTest("Test Case 6", []() {
      vector<vector<int>> testInput{
          {1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0},
          {1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0},
          {0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1},
          {1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0},
          {1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1},
      };
      vector<int> expected{1, 1, 2, 2, 5, 21};
      vector<int> output = riverSizes(testInput);
      sort(output.begin(), output.end());
      assert(output == expected);
    });

    RunTest("Test Case 7", []() {
      vector<vector<int>> testInput{
          {1, 0, 0, 0, 0, 0, 1}, {0, 1, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 0, 0},
          {0, 0, 0, 1, 0, 0, 0}, {0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 1, 0},
          {1, 0, 0, 0, 0, 0, 1},
      };
      vector<int> expected{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
      vector<int> output = riverSizes(testInput);
      sort(output.begin(), output.end());
      assert(output == expected);
    });

    RunTest("Test Case 8", []() {
      vector<vector<int>> testInput{
          {1, 0, 0, 0, 0, 0, 1}, {0, 1, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 0, 0},
          {0, 0, 1, 1, 1, 0, 0}, {0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 1, 0},
          {1, 0, 0, 0, 0, 0, 1},
      };
      vector<int> expected{1, 1, 1, 1, 1, 1, 1, 1, 7};
      vector<int> output = riverSizes(testInput);
      sort(output.begin(), output.end());
      assert(output == expected);
    });

    RunTest("Test Case 9", []() {
      vector<vector<int>> testInput{
          {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0},
      };
      vector<int> expected{};
      vector<int> output = riverSizes(testInput);
      sort(output.begin(), output.end());
      assert(output == expected);
    });

    RunTest("Test Case 10", []() {
      vector<vector<int>> testInput{
          {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1},
          {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1},
          {1, 1, 1, 1, 1, 1, 1},
      };
      vector<int> expected{49};
      vector<int> output = riverSizes(testInput);
      sort(output.begin(), output.end());
      assert(output == expected);
    });

    RunTest("Test Case 11", []() {
      vector<vector<int>> testInput{
          {1, 1, 0, 0, 0, 0, 1, 1},
          {1, 0, 1, 1, 1, 1, 0, 1},
          {0, 1, 1, 0, 0, 0, 1, 1},
      };
      vector<int> expected{3, 5, 6};
      vector<int> output = riverSizes(testInput);
      sort(output.begin(), output.end());
      assert(output == expected);
    });

    RunTest("Test Case 12", []() {
      vector<vector<int>> testInput{
          {1, 1, 0}, {1, 0, 1}, {1, 1, 1}, {1, 1, 0}, {1, 0, 1}, {0, 1, 0},
          {1, 0, 0}, {1, 0, 0}, {0, 0, 0}, {1, 0, 0}, {1, 0, 1}, {1, 1, 1},
      };
      vector<int> expected{1, 1, 2, 6, 10};
      vector<int> output = riverSizes(testInput);
      sort(output.begin(), output.end());
      assert(output == expected);
    });
  }
};
