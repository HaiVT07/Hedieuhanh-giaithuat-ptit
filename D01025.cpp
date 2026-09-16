#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 25
#define MAX_RESULTS 100000

char S[MAX_N];
char results[MAX_RESULTS][MAX_N];
int result_count = 0;
int N, K;

// Hàm quay lui chọn đúng K vị trí
void generate_combinations(int index, int chosen_count, char *current_str) {
    if (chosen_count == K) {
        strcpy(results[result_count++], current_str);
        return;
    }
    
    // Cắt tỉa nhánh nếu số ký tự còn lại không đủ
    if (index + (K - chosen_count) > N) {
        return;
    }

    for (int i = index; i < N; i++) {
        int len = strlen(current_str);
        
        // Chọn ký tự tại vị trí i
        current_str[len] = S[i];
        current_str[len + 1] = '\0';
        
        // Đệ quy chọn tiếp từ vị trí i + 1
        generate_combinations(i + 1, chosen_count + 1, current_str);
        
        // Backtrack (Khôi phục xâu)
        current_str[len] = '\0';
    }
}

// Hàm so sánh cho qsort
int compare_strings(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

void solve() {
    scanf("%s %d", S, &K);
    N = strlen(S);
    result_count = 0;

    char current_str[MAX_N] = "";
    generate_combinations(0, 0, current_str);

    // Sắp xếp các xâu thu được theo thứ tự từ nhỏ đến lớn
    qsort(results, result_count, sizeof(results[0]), compare_strings);

    // In kết quả và loại bỏ các xâu trùng lặp
    for (int i = 0; i < result_count; i++) {
        if (i == 0 || strcmp(results[i], results[i - 1]) != 0) {
            printf("%s\n", results[i]);
        }
    }
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        solve();
    }
    return 0;
}