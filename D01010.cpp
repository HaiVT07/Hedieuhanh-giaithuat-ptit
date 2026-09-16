#include <iostream>
#include <string>

using namespace std;

int max_len;
string s;

// Quay lui sinh xâu độ dài target_len
void Try(int i, int target_len, int cntA, int cntB, int cntC) {
    for (char c = 'A'; c <= 'C'; c++) {
        s[i] = c;
        
        int nextA = cntA + (c == 'A');
        int nextB = cntB + (c == 'B');
        int nextC = cntC + (c == 'C');

        if (i == target_len - 1) {
            // Kiểm tra các điều kiện đề bài
            if (nextA >= 1 && nextB >= 1 && nextC >= 1 && nextA <= nextB && nextB <= nextC) {
                cout << s << "\n";
            }
        } else {
            Try(i + 1, target_len, nextA, nextB, nextC);
        }
    }
}

int main() {
    // Tối ưu nhập xuất I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (cin >> max_len) {
        // Duyệt độ dài từ 3 đến N
        for (int len = 3; len <= max_len; len++) {
            s.resize(len);
            Try(0, len, 0, 0, 0);
        }
    }

    return 0;
}