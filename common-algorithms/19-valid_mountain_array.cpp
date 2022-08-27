/* 
Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

    arr.length >= 3
    There exists some i with 0 < i < arr.length - 1 such that:
        arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
        arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Example:
- Mountain array: 0 2 3 4 5 2 1 0
- Not a mountain array: 0 2 3 3 5 2 1 0

Example 1:
    Input: arr = [2,1]
    Output: false
Example 2:
    Input: arr = [3,5,5]
    Output: false
Example 3:
    Input: arr = [0,3,2,1]
    Output: true

Constraints:
    1 <= arr.length <= 104
    0 <= arr[i] <= 104
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        uint len = arr.size();
        int tmp = arr[1];
        bool isLeftSide = true;
        if (len < 3)
            return false;
        if (arr[0] >= arr[1])
            return false;

        for (uint i = 2; i < len; i++) {
            if (arr[i] == tmp)
                return false;
            else if (isLeftSide) {
                if (arr[i] < tmp)
                    isLeftSide = false;
            } else {
                if (arr[i] >= tmp)
                    return false;
            }
            tmp = arr[i];
        }
        return isLeftSide ? false : true;
    }
};

int main(int argc, char* argv[]) {
    // vector<int> vec = {0, 2, 3, 4, 5, 2, 1, 0}; // true
    // vector<int> vec = {0, 2, 3, 3, 5, 2, 1, 0}; // false
    // vector<int> vec = {0, 2, 3}; // false
    // vector<int> vec = {0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 19, 16, 15, 14, 13, 12, 11, 10, 6, 6, 4, 3, 1}; // false
    vector<int> vec = {0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 19, 16, 15, 14, 13, 12, 11, 10, 6, 5, 4, 3, 1}; // true
    Solution sol;

    cout << "Result: " << sol.validMountainArray(vec) << endl;
}