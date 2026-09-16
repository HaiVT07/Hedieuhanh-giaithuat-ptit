#include <iostream>
#include <string>

using namespace std;

int n;
string s;

// Thuật toán quay lui sinh xâu 6, 8 độ dài N
void Try(int i) {
    // Ưu tiên chọn '6' trước để đảm bảo thứ tự tăng dần
    s[i] = '6';
    if (i == n - 1) {
        cout << s << " ";
    } else {
        Try(i + 1);
    }

    // Sau đó thử chọn '8'
    s[i] = '8';
    if (i == n - 1) {
        cout << s << " ";
    } else {
        Try(i + 1);
    }
}

void solve() {
    cin >> n;
    // Dòng 1: In ra tổng số lượng số lộc phát = 2^N
    cout << (1 << n) << "\n";
    
    // Dòng 2: In ra tất cả các số lộc phát
    s.resize(n);
    Try(0);
    cout << "\n";
}

int main() {
    // Tối ưu I/O tăng tốc độ thực thi
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}