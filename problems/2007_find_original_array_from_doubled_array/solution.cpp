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
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 != 0) return {};
        sort(changed.begin(), changed.end());
        map<int, int> freq;
        for (int num : changed) freq[num]++;
        vector<int> result;
        for (int num : changed) {
            if (freq[num] == 0) continue;
            if (freq[num * 2] == 0) return {};
            result.push_back(num);
            freq[num]--;
            freq[num * 2]--;
        }
        return result;
    }
};
