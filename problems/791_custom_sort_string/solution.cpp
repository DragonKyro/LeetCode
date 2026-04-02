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
    string customSortString(string order, string s) {
        int rank[26];
        fill(rank, rank + 26, 26);
        for (int i = 0; i < (int)order.size(); i++) rank[order[i] - 'a'] = i;
        sort(s.begin(), s.end(), [&](char a, char b) { return rank[a - 'a'] < rank[b - 'a']; });
        return s;
    }
};
