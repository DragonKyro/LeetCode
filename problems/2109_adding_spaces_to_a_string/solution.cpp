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
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int j = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (j < (int)spaces.size() && i == spaces[j]) {
                result += ' ';
                j++;
            }
            result += s[i];
        }
        return result;
    }
};
