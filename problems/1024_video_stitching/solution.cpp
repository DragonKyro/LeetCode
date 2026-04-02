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
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        int ans = 0, end = 0, farthest = 0, i = 0;
        while (end < time) {
            while (i < clips.size() && clips[i][0] <= end)
                farthest = max(farthest, clips[i++][1]);
            if (farthest == end) return -1;
            end = farthest;
            ans++;
        }
        return ans;
    }
};
