#include <iostream>
#include <algorithm>
using namespace std;

// 欧几里得算法求gcd
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int a, b;
    cin >> a >> b;
    
    if (gcd(a, b) != 1) {
        cout << "0" << endl;  // 表示不存在最大不能组合的数（有无限多个）
    } else {
        cout << a * b - a - b << endl;
    }
    
    return 0;
}
