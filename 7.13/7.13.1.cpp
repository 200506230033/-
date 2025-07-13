#include <iostream>
#include <string>
using namespace std;

int main() {
    int V;
    cin >> V;

    for (int n = 1;; n++) {
        int max_inv = n * (n - 1) / 2;
        if (max_inv >= V) {
            string result = "";
            int remain = V;
            for (int i = n - 1; i >= 0; i--) {
                int pos = min(remain, i);
                pos = min(pos, (int)result.size()); // 修复：防止 insert 越界
                result.insert(result.begin() + pos, 'a' + (n - 1 - i));
                remain -= pos;
            }
            cout << result << endl;
            break;
        }
    }

    return 0;
}
