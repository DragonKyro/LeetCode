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
    string getSmallestString(string s) {
        for (int i = 0; i < (int)s.size()-1; i++) {
            if ((s[i]-'0')%2 == (s[i+1]-'0')%2 && s[i] > s[i+1]) {
                swap(s[i], s[i+1]);
                break;
            }
        }
        return s;
    }
};
