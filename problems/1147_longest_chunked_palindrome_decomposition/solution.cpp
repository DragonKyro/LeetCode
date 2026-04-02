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
    int longestDecomposition(string text) {
        int n = text.size();
        int result = 0;
        string lStr, rStr;
        int left = 0, right = n - 1;
        while (left < right) {
            lStr += text[left];
            rStr = text[right] + rStr;
            if (lStr == rStr) {
                result += 2;
                lStr = "";
                rStr = "";
            }
            left++;
            right--;
        }
        if (left == right || !lStr.empty()) result++;
        return result;
    }
};
