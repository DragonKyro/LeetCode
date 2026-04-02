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
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        while (left < right) {
            int mid = (left + right) / 2;
            int d = 1, cur = 0;
            for (int w : weights) {
                if (cur + w > mid) { d++; cur = 0; }
                cur += w;
            }
            if (d <= days) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
