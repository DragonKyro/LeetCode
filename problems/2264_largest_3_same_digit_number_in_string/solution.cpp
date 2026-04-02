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
    string largestGoodInteger(string num) {
        string result = "";
        for (int i = 0; i <= (int)num.size() - 3; i++) {
            if (num[i] == num[i+1] && num[i+1] == num[i+2]) {
                string s = num.substr(i, 3);
                result = max(result, s);
            }
        }
        return result;
    }
};
