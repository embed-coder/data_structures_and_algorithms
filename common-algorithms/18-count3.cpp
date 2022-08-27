/* 
DEM3 - Bài toán đếm 3
Đề bài
    Cho 2 số nguyên dương N,KN, KN,K. Đếm xem có bao nhiêu số tự nhiên dương không vượt quá NNN mà có tích các chữ số không vượt quá KKK.
Dữ liệu vào
    Gồm 2 số N,KN, KN,K.
    Dữ liệu đảm bảo 1≤N≤1012 1 \le N \le 10^{12} 1≤N≤1012 , 1≤K≤109 1 \le K \le 10^91≤K≤109.
Dữ liệu ra
    In ra kết quả theo yêu cầu.
Ví dụ
    Input #1
        9 10
    Output #1
        9
    Input #2
        19 3
    Output #2
        7
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <iostream>
#include <utility>

using namespace std;

int count3(const int &n, const int &k) {
    return 0;
}

#ifndef RunTests
int main()
{
    int n = 3, k = 2;

    cout << "Result: " << count3(n, k) << endl;
}
#endif