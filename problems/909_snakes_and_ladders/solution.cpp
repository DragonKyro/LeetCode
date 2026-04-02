#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<pair<int,int>> q;
        q.push({1, 0});
        visited[1] = true;
        while (!q.empty()) {
            auto [curr, moves] = q.front(); q.pop();
            for (int i = 1; i <= 6; i++) {
                int next = curr + i;
                if (next > n * n) break;
                int r = (next - 1) / n, c = (next - 1) % n;
                if (r % 2 == 1) c = n - 1 - c;
                r = n - 1 - r;
                if (board[r][c] != -1) next = board[r][c];
                if (next == n * n) return moves + 1;
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }
        return -1;
    }
};
