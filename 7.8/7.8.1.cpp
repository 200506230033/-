#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> candies(n);

    for (int i = 0; i < n; ++i) {
        cin >> candies[i];
    }

    int total_added = 0;

    while (true) {
        // Step 1: 如果所有糖果相等，退出
        bool all_equal = true;
        for (int i = 1; i < n; ++i) {
            if (candies[i] != candies[0]) {
                all_equal = false;
                break;
            }
        }
        if (all_equal) break;

        // Step 2: 所有人先分出一半（临时数组记录将要给别人的数量）
        vector<int> half(n);
        for (int i = 0; i < n; ++i) {
            half[i] = candies[i] / 2;
            candies[i] -= half[i]; // 自己先减去一半
        }

        // Step 3: 每个人接收右边的人给自己的一半
        for (int i = 0; i < n; ++i) {
            candies[i] += half[(i + 1) % n]; // 从右边来的
        }

        // Step 4: 检查奇数，加糖
        for (int i = 0; i < n; ++i) {
            if (candies[i] % 2 != 0) {
                candies[i]++;
                total_added++;
            }
        }
    }

    cout << total_added << endl;
    return 0;
}
