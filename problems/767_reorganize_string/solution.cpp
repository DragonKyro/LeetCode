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
    string reorganizeString(string s) {
        unordered_map<char, int> counts;
        for (char c : s) counts[c]++;
        priority_queue<pair<int, char>> pq;
        for (auto& [c, cnt] : counts) pq.push({cnt, c});
        string result;
        pair<int, char> prev = {0, ' '};
        while (!pq.empty()) {
            auto [cnt, ch] = pq.top(); pq.pop();
            result += ch;
            if (prev.first > 0) pq.push(prev);
            prev = {cnt - 1, ch};
        }
        return result.size() == s.size() ? result : "";
    }
};
