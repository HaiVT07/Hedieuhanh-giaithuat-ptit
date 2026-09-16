#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 16
#define MAX_LEN 140
#define MAX_RESULTS 7000

char numbers[MAX_N][15];
char results[MAX_RESULTS][MAX_LEN];
int result_count = 0;
int N, K;

// Hàm quay lui chọn đúng K số theo đúng thứ tự xuất hiện
void generate_combinations(int index, int chosen_count, char *current_str) {
    if (chosen_count == K) {
        strcpy(results[result_count++], current_str);
        return;
    }
    
    // Cắt tỉa nhanh nếu số phần tử còn lại không đủ để chọn đủ K phần tử
    if (index + (K - chosen_count) > N) {
        return;
    }

    for (int i = index; i < N; i++) {
        int len = strlen(current_str);
        
        // Nối số vào chuỗi hiện tại
        strcat(current_str, numbers[i]);
        
        // Đệ quy chọn tiếp số kế tiếp
        generate_combinations(i + 1, chosen_count + 1, current_str);
        
        // Backtrack (Khôi phục trạng thái chuỗi ban đầu)
        current_str[len] = '\0';
    }
}

// Hàm so sánh cho qsort
int compare_strings(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main() {
    if (scanf("%d %d", &N, &K) != 2) return 0;

    for (int i = 0; i < N; i++) {
        scanf("%s", numbers[i]);
    }

    char current_str[MAX_LEN] = "";
    
    // Sinh các tổ hợp chập K của N
    generate_combinations(0, 0, current_str);

    // Sắp xếp kết quả theo thứ tự từ điển
    qsort(results, result_count, sizeof(results[0]), compare_strings);

    // In kết quả và loại bỏ các xâu trùng lặp
    for (int i = 0; i < result_count; i++) {
        if (i == 0 || strcmp(results[i], results[i - 1]) != 0) {
            printf("%s\n", results[i]);
        }
    }

    return 0;
}