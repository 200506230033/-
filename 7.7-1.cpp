#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 判断是否是回文数
bool isPalindrome(int num) {
    string s = to_string(num);
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        ++l;
        --r;
    }
    return true;
}

// 计算各位数字之和
int digitSum(int num) {
    int sum = 0;
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> result;

    for (int i = 10000; i <= 999999; ++i) {
        if (isPalindrome(i) && digitSum(i) == n) {
            result.push_back(i);
        }
    }

    if (result.empty()) {
        cout << -1 << endl;
    } else {
        for (int num : result) {
            cout << num << endl;
        }
    }

    return 0;
}
