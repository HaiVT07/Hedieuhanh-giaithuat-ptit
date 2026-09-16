#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> target;
vector<int> current;
int cnt;
int result;

// Hàm quay lui sinh các tổ hợp chập K của N
void Try(int i) {
    int start = (i == 0) ? 1 : current[i - 1] + 1;
    for (int j = start; j <= n - k + i + 1; j++) {
        current[i] = j;
        if (i == k - 1) {
            cnt++; // Đếm số thứ tự tổ hợp hiện tại
            
            // Kiểm tra xem tổ hợp hiện tại có trùng với target không
            bool match = true;
            for (int p = 0; p < k; p++) {
                if (current[p] != target[p]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                result = cnt;
            }
        } else {
            Try(i + 1);
        }
    }
}

void solve() {
    cin >> n >> k;
    target.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> target[i];
    }
    
    current.resize(k);
    cnt = 0;
    result = 0;
    
    Try(0);
    
    cout << result << "\n";
}

int main() {
    // Tối ưu nhập xuất dữ liệu
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