#include <iostream>
#include <string>

using namespace std;

int n;
string s;
int cnt;

// Quay lui sinh xâu tam phân độ dài N
void Try(int i) {
    for (char c = '0'; c <= '2'; c++) {
        s[i] = c;
        if (i == n - 1) {
            cnt++; // Đếm thứ tự từ điển
            if (cnt % 2 == 0) { // Chỉ in ra xâu ở thứ tự chẵn
                cout << cnt << ": " << s << "\n";
            }
        } else {
            Try(i + 1);
        }
    }
}

int main() {
    // Tối ưu nhập xuất I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (cin >> n) {
        s.resize(n);
        cnt = 0;
        Try(0);
    }

    return 0;
}