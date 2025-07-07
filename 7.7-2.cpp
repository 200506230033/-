#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

// 空格可能的移动方向 (上下左右)
const int dx[] = { -1, 1, 0, 0 }; // 行偏移：上、下
const int dy[] = { 0, 0, -1, 1 }; // 列偏移：左、右

// 位置索引转为二维坐标
int getX(int pos) { return pos / 3; }
int getY(int pos) { return pos % 3; }

int bfs(string start, string goal) {
    unordered_map<string, int> dist;
    queue<string> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        string cur = q.front();
        q.pop();

        if (cur == goal) return dist[cur];

        int pos = cur.find('.');
        int x = getX(pos), y = getY(pos);

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;

            int np = nx * 3 + ny;
            string next = cur;
            swap(next[pos], next[np]);

            if (!dist.count(next)) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }

    return -1; // 无法达到
}

int main() {
    string start, goal;
    cin >> start >> goal;
    int result = bfs(start, goal);
    cout << result << endl;
    return 0;
}
