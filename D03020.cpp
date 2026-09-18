#include <stdio.h>
#include <string.h>

// Cài đặt Max Heap thủ công bằng mảng
typedef struct {
    int data[30];
    int size;
} MaxHeap;

void push(MaxHeap* heap, int val) {
    heap->data[heap->size] = val;
    int i = heap->size;
    heap->size++;

    while (i > 0 && heap->data[i] > heap->data[(i - 1) / 2]) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[(i - 1) / 2];
        heap->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int pop(MaxHeap* heap) {
    if (heap->size <= 0) return 0;
    int top = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;

    int i = 0;
    while (2 * i + 1 < heap->size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int maxIdx = left;

        if (right < heap->size && heap->data[right] > heap->data[left]) {
            maxIdx = right;
        }

        if (heap->data[i] < heap->data[maxIdx]) {
            int temp = heap->data[i];
            heap->data[i] = heap->data[maxIdx];
            heap->data[maxIdx] = temp;
            i = maxIdx;
        } else {
            break;
        }
    }
    return top;
}

void solve() {
    int k;
    if (scanf("%d", &k) != 1) return;

    static char s[1000005];
    scanf("%s", s);

    int count[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'A']++;
    }

    MaxHeap heap;
    heap.size = 0;

    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            push(&heap, count[i]);
        }
    }

    // Loại bỏ K ký tự có tần suất cao nhất
    while (k > 0 && heap.size > 0) {
        int top = pop(&heap);
        top--;
        k--;
        if (top > 0) {
            push(&heap, top);
        }
    }

    // Tính tổng bình phương các tần suất còn lại
    long long ans = 0;
    while (heap.size > 0) {
        long long top = pop(&heap);
        ans += top * top;
    }

    printf("%lld\n", ans);
}

int main() {
    int t;
    if (scanf("%d", &t) == 1) {
        while (t--) {
            solve();
        }
    }
    return 0;
}