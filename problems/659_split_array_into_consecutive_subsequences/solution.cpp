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
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, appendfreq;
        for (int num : nums) freq[num]++;
        for (int num : nums) {
            if (freq[num] == 0) continue;
            if (appendfreq[num] > 0) {
                appendfreq[num]--;
                appendfreq[num + 1]++;
            } else if (freq[num + 1] > 0 && freq[num + 2] > 0) {
                freq[num + 1]--;
                freq[num + 2]--;
                appendfreq[num + 3]++;
            } else return false;
            freq[num]--;
        }
        return true;
    }
};
