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
    int numberOfSubstrings(string s) {
        int count[3] = {}, res = 0, left = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            count[s[right]-'a']++;
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                res += s.size() - right;
                count[s[left++]-'a']--;
            }
        }
        return res;
    }
};
