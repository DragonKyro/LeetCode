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
    string longestDiverseString(int a, int b, int c) {
        string res;
        priority_queue<pair<int, char>> pq;
        if (a) pq.push({a, 'a'});
        if (b) pq.push({b, 'b'});
        if (c) pq.push({c, 'c'});
        while (!pq.empty()) {
            auto [cnt1, ch1] = pq.top(); pq.pop();
            int n = res.size();
            if (n >= 2 && res[n-1] == ch1 && res[n-2] == ch1) {
                if (pq.empty()) break;
                auto [cnt2, ch2] = pq.top(); pq.pop();
                res += ch2;
                if (cnt2 - 1 > 0) pq.push({cnt2 - 1, ch2});
                pq.push({cnt1, ch1});
            } else {
                res += ch1;
                if (cnt1 - 1 > 0) pq.push({cnt1 - 1, ch1});
            }
        }
        return res;
    }
};
