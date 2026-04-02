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
    string decodeMessage(string key, string message) {
        unordered_map<char, char> map;
        int idx = 0;
        for (char c : key) {
            if (c != ' ' && !map.count(c)) {
                map[c] = 'a' + idx++;
            }
        }
        string result;
        for (char c : message) result += map.count(c) ? map[c] : c;
        return result;
    }
};
