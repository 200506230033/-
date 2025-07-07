#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll unhappy_sum = 0;  // 总不高兴度

// 归并排序时计算不高兴度
void merge_sort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);

    vector<int> tmp(r - l + 1);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            int swaps = mid - i + 1; // arr[i] > arr[j]，所以 arr[i...mid] 都 > arr[j]
            // arr[j] 被这些比它大的元素“压”过去，要移动 swaps 次
            unhappy_sum += (ll)swaps * (swaps + 1) / 2;
            tmp[k++] = arr[j++];
        }
    }
    while (i <= mid) tmp[k++] = arr[i++];
    while (j <= r) tmp[k++] = arr[j++];
    for (int p = 0; p < k; ++p) {
        arr[l + p] = tmp[p];
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }

    merge_sort(height, 0, n - 1);
    cout << unhappy_sum << endl;

    return 0;
}
