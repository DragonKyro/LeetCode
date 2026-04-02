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
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letters, digits;
        for (auto& log : logs) {
            int i = log.find(' ');
            if (isdigit(log[i + 1])) digits.push_back(log);
            else letters.push_back(log);
        }
        sort(letters.begin(), letters.end(), [](const string& a, const string& b) {
            int ia = a.find(' '), ib = b.find(' ');
            string ba = a.substr(ia + 1), bb = b.substr(ib + 1);
            return ba == bb ? a < b : ba < bb;
        });
        letters.insert(letters.end(), digits.begin(), digits.end());
        return letters;
    }
};
