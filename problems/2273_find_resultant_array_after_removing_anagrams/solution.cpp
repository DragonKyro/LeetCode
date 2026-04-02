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
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result = {words[0]};
        for (int i = 1; i < words.size(); i++) {
            string a = words[i], b = words[i-1];
            sort(a.begin(), a.end()); sort(b.begin(), b.end());
            if (a != b) result.push_back(words[i]);
        }
        return result;
    }
};
