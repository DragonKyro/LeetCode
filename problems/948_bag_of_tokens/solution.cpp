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
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int left = 0, right = tokens.size() - 1, score = 0, result = 0;
        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left++];
                result = max(result, ++score);
            } else if (score > 0) {
                power += tokens[right--];
                score--;
            } else break;
        }
        return result;
    }
};
