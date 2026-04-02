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
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> res;
        int start = rounds[0], end = rounds.back();
        if (start <= end) {
            for (int i = start; i <= end; i++) res.push_back(i);
        } else {
            for (int i = 1; i <= end; i++) res.push_back(i);
            for (int i = start; i <= n; i++) res.push_back(i);
        }
        return res;
    }
};
