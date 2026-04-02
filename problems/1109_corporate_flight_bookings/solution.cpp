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
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> answer(n + 1, 0);
        for (auto& b : bookings) {
            answer[b[0] - 1] += b[2];
            if (b[1] < n) answer[b[1]] -= b[2];
        }
        for (int i = 1; i < n; i++) {
            answer[i] += answer[i - 1];
        }
        answer.resize(n);
        return answer;
    }
};
