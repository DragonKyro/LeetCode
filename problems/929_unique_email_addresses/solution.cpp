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
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique;
        for (auto& email : emails) {
            string local, domain;
            int at = email.find('@');
            domain = email.substr(at);
            for (char c : email.substr(0, at)) {
                if (c == '+') break;
                if (c != '.') local += c;
            }
            unique.insert(local + domain);
        }
        return unique.size();
    }
};
