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
    int longestWPI(vector<int>& hours) {
        int score = 0, result = 0;
        unordered_map<int, int> first;
        for (int i = 0; i < hours.size(); i++) {
            score += hours[i] > 8 ? 1 : -1;
            if (score > 0) {
                result = i + 1;
            } else {
                if (!first.count(score)) first[score] = i;
                if (first.count(score - 1)) {
                    result = max(result, i - first[score - 1]);
                }
            }
        }
        return result;
    }
};
