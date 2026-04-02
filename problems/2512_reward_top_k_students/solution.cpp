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
    vector<int> topStudents(vector<string>& pos, vector<string>& neg, vector<string>& report, vector<int>& id, int k) {
        set<string> p(pos.begin(), pos.end()), n(neg.begin(), neg.end());
        vector<pair<int,int>> sc;
        for (int i = 0; i < id.size(); i++) {
            int score = 0;
            istringstream iss(report[i]); string w;
            while (iss >> w) { if (p.count(w)) score += 3; else if (n.count(w)) score -= 1; }
            sc.push_back({-score, id[i]});
        }
        sort(sc.begin(), sc.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) ans.push_back(sc[i].second);
        return ans;
    }
};
