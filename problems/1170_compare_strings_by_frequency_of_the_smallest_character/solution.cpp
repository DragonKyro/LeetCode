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
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        auto f = [](const string& s) {
            char mn = *min_element(s.begin(), s.end());
            return (int)count(s.begin(), s.end(), mn);
        };
        vector<int> wordFreqs;
        for (auto& w : words) wordFreqs.push_back(f(w));
        sort(wordFreqs.begin(), wordFreqs.end());
        vector<int> result;
        for (auto& q : queries) {
            int qf = f(q);
            int pos = upper_bound(wordFreqs.begin(), wordFreqs.end(), qf) - wordFreqs.begin();
            result.push_back(wordFreqs.size() - pos);
        }
        return result;
    }
};
