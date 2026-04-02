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
    int convertTime(string current, string correct) {
        auto toMin = [](string& t) {
            return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3));
        };
        int diff = toMin(correct) - toMin(current), ops = 0;
        for (int d : {60, 15, 5, 1}) {
            ops += diff / d;
            diff %= d;
        }
        return ops;
    }
};
