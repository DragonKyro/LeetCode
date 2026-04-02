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
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        vector<int> res;
        for (auto& q : queries) {
            int d = abs(q[0]) + abs(q[1]);
            pq.push(d);
            if ((int)pq.size() > k) pq.pop();
            res.push_back((int)pq.size() == k ? pq.top() : -1);
        }
        return res;
    }
};
