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
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> counts;
        for (auto& cp : cpdomains) {
            int i = cp.find(' ');
            int count = stoi(cp.substr(0, i));
            string domain = cp.substr(i + 1);
            counts[domain] += count;
            for (int j = 0; j < domain.size(); j++) {
                if (domain[j] == '.') counts[domain.substr(j + 1)] += count;
            }
        }
        vector<string> result;
        for (auto& [k, v] : counts) result.push_back(to_string(v) + " " + k);
        return result;
    }
};
