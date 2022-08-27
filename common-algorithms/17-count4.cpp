/* Đề bài
    Đếm xem có bao nhiêu dãy số nguyên dương ( lớn hơn bằng 1 1 1 ) gồm Q Q Q số sao cho tích của 2 số liên tiếp không vượt quá P P P.
    In ra kết quả theo modulo 109+7 10^9 + 7 109+7.

Dữ liệu vào
    Gồm 1 dòng chứa : P,Q P , Q P,Q
        2≤P≤109 2 \le P \le 10^9 2≤P≤109
        2≤Q≤100 2 \le Q \le 100 2≤Q≤100
Dữ liệu ra
    In ra kết quả theo yêu cầu đề bài

Ví dụ:
    Input #1
        3 2
    Output #1
        5
Gợi ý
    Trong test mẫu có 5 5 5 dãy là : (1,1),(1,2),(1,3),(2,1),(3,1) (1, 1) , (1, 2), (1, 3), (2, 1) , (3, 1) (1,1),(1,2),(1,3),(2,1),(3,1)
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <iostream>
#include <utility>

using namespace std;

int count4(const int &P, const int &Q) {
    return 0;
}

#ifndef RunTests
int main()
{
    int P = 3, Q = 2;

    cout << "Result: " << count4(P, Q) << endl;
}
#endif