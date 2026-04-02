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
    string countOfAtoms(string formula) {
        stack<map<string,int>> stk;
        stk.push({});
        int i = 0, n = formula.size();
        while (i < n) {
            if (formula[i] == '(') { stk.push({}); i++; }
            else if (formula[i] == ')') {
                i++;
                int start = i;
                while (i < n && isdigit(formula[i])) i++;
                int mult = start < i ? stoi(formula.substr(start, i - start)) : 1;
                auto top = stk.top(); stk.pop();
                for (auto& [name, cnt] : top) stk.top()[name] += cnt * mult;
            } else {
                int start = i++;
                while (i < n && islower(formula[i])) i++;
                string name = formula.substr(start, i - start);
                start = i;
                while (i < n && isdigit(formula[i])) i++;
                int cnt = start < i ? stoi(formula.substr(start, i - start)) : 1;
                stk.top()[name] += cnt;
            }
        }
        string res;
        for (auto& [name, cnt] : stk.top()) {
            res += name;
            if (cnt > 1) res += to_string(cnt);
        }
        return res;
    }
};
