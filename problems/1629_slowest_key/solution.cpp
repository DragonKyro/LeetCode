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
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int longest = releaseTimes[0];
        char result = keysPressed[0];
        for (int i = 1; i < releaseTimes.size(); i++) {
            int duration = releaseTimes[i] - releaseTimes[i - 1];
            if (duration > longest || (duration == longest && keysPressed[i] > result)) {
                longest = duration;
                result = keysPressed[i];
            }
        }
        return result;
    }
};
