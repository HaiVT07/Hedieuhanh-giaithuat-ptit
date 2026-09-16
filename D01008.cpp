#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> current;
void Try(int i, int sum) {
    int start = (i == 0) ? 1 : current[i - 1] + 1;
    for (int j = start; j <= n - k + i + 1; j++) {
        current[i] = j;
        int next_sum = sum + j;
        
        if (i == k - 1) {
            if (next_sum % 2 == 0) {
                for (int p = 0; p < k; p++) {
                    cout << current[p] << (p == k - 1 ? "" : " ");
                }
                cout << "\n";
            }
        } else {
            Try(i + 1, next_sum);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    if (cin >> n >> k) {
        current.resize(k);
        Try(0, 0);
    }
    
    return 0;
}