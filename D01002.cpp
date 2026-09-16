#include <iostream>
#include <string>

using namespace std;

int n;
string s;

void Try(int i) {
    for (char c = 'A'; c <= 'B'; c++) {
        s[i] = c;
        if (i == n - 1) {
            // Kiểm tra xâu có hợp lệ không (không phải toàn 'A' hoặc toàn 'B')
            if (s != string(n, 'A') && s != string(n, 'B')) {
                cout << s << "\n";
            }
        } else {
            Try(i + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    if (cin >> n) {
        s.resize(n);
        Try(0);
    }
    
    return 0;
}