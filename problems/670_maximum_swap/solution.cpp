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
    int maximumSwap(int num) {
        string digits = to_string(num);
        vector<int> last(10, -1);
        for (int i = 0; i < digits.size(); i++) last[digits[i] - '0'] = i;
        for (int i = 0; i < digits.size(); i++) {
            for (int k = 9; k > digits[i] - '0'; k--) {
                if (last[k] > i) {
                    swap(digits[i], digits[last[k]]);
                    return stoi(digits);
                }
            }
        }
        return num;
    }
};
