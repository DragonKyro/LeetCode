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
    string removeDigit(string number, char digit) {
        string result = "";
        for (int i = 0; i < number.size(); i++) {
            if (number[i] == digit) {
                string candidate = number.substr(0, i) + number.substr(i + 1);
                result = max(result, candidate);
            }
        }
        return result;
    }
};
