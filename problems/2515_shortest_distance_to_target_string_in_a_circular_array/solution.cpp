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
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size(), ans = n;
        for (int i = 0; i < n; i++)
            if (words[i] == target)
                ans = min(ans, min(abs(i-startIndex), n-abs(i-startIndex)));
        return ans < n ? ans : -1;
    }
};
