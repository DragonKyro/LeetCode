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
    string defangIPaddr(string address) {
        string result;
        for (char c : address) {
            if (c == '.') result += "[.]";
            else result += c;
        }
        return result;
    }
};
