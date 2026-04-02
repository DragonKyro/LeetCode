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
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> first(26, -1);
        int result = -1;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (first[c] != -1) {
                result = max(result, i - first[c] - 1);
            } else {
                first[c] = i;
            }
        }
        return result;
    }
};
