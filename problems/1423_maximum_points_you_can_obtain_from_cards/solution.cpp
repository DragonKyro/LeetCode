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
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int ws = n - k;
        int window = accumulate(cardPoints.begin(), cardPoints.begin() + ws, 0);
        int minW = window;
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        for (int i = ws; i < n; i++) {
            window += cardPoints[i] - cardPoints[i - ws];
            minW = min(minW, window);
        }
        return total - minW;
    }
};
