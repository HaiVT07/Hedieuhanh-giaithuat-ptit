#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, K;
string S;
int indices[25];
set<long long> unique_numbers; // Tự động lọc trùng và sắp xếp tăng dần theo giá trị số

// Quay lui chọn K vị trí từ xâu S
void Try(int i, int start) {
    for (int j = start; j < N; j++) {
        indices[i] = j;
        if (i == K - 1) {
            string current_str = "";
            for (int m = 0; m < K; m++) {
                current_str += S[indices[m]];
            }
            // Chuyển sang số nguyên để sắp xếp đúng theo giá trị số (tránh lỗi sort từ điển xâu)
            long long val = stoll(current_str);
            unique_numbers.insert(val);
        } else {
            Try(i + 1, j + 1);
        }
    }
}

void solve() {
    cin >> S >> K;
    N = S.length();
    unique_numbers.clear();
    
    Try(0, 0);

    // In ra các số đã được sắp xếp tăng dần theo giá trị
    for (long long num : unique_numbers) {
        cout << num << "\n";
    }
}

int main() {
    // Tối ưu tốc độ nhập/xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}