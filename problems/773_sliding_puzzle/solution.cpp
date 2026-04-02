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
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450", start;
        for (auto& row : board) for (int v : row) start += to_string(v);
        if (start == target) return 0;
        vector<vector<int>> moves = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        queue<string> q;
        unordered_set<string> visited;
        q.push(start); visited.insert(start);
        int step = 0;
        while (!q.empty()) {
            step++;
            int sz = q.size();
            for (int s = 0; s < sz; s++) {
                string state = q.front(); q.pop();
                int idx = state.find('0');
                for (int nei : moves[idx]) {
                    string next = state;
                    swap(next[idx], next[nei]);
                    if (next == target) return step;
                    if (!visited.count(next)) { visited.insert(next); q.push(next); }
                }
            }
        }
        return -1;
    }
};
