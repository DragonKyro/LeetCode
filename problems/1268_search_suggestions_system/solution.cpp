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
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        string prefix;
        auto it = products.begin();
        for (char c : searchWord) {
            prefix += c;
            it = lower_bound(it, products.end(), prefix);
            vector<string> matches;
            for (auto i = it; i != products.end() && i < it + 3 && (*i).substr(0, prefix.size()) == prefix; i++)
                matches.push_back(*i);
            res.push_back(matches);
        }
        return res;
    }
};
