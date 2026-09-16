#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Tối ưu nhập xuất I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c1, c2;
    if (cin >> c1 >> c2) {
        char start_char = min(c1, c2);
        char end_char = max(c1, c2);

        // Tạo xâu chứa các ký tự từ start_char đến end_char
        string s = "";
        for (char c = start_char; c <= end_char; c++) {
            s.push_back(c);
        }

        // In ra hoán vị đầu tiên và sinh các hoán vị tiếp theo theo thứ tự từ điển
        do {
            cout << s << "\n";
        } while (next_permutation(s.begin(), s.end()));
    }

    return 0;
}