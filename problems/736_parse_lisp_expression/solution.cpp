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
    int evaluate(string expression) {
        vector<unordered_map<string,int>> scope;
        scope.push_back({});
        return parse(expression, scope);
    }

    int parse(string expr, vector<unordered_map<string,int>>& scope) {
        if (expr[0] != '(') {
            if (isdigit(expr[0]) || expr[0] == '-') return stoi(expr);
            for (int i = scope.size() - 1; i >= 0; i--)
                if (scope[i].count(expr)) return scope[i][expr];
            return 0;
        }
        string inner = expr.substr(1, expr.size() - 2);
        auto tokens = tokenize(inner);
        if (tokens[0] == "let") {
            scope.push_back({});
            int i = 1;
            while (i < (int)tokens.size() - 1) {
                string var = tokens[i];
                int val = parse(tokens[i+1], scope);
                scope.back()[var] = val;
                i += 2;
            }
            int res = parse(tokens.back(), scope);
            scope.pop_back();
            return res;
        } else if (tokens[0] == "add") {
            return parse(tokens[1], scope) + parse(tokens[2], scope);
        } else {
            return parse(tokens[1], scope) * parse(tokens[2], scope);
        }
    }

    vector<string> tokenize(string s) {
        vector<string> tokens;
        int i = 0;
        while (i < (int)s.size()) {
            if (s[i] == ' ') { i++; continue; }
            if (s[i] == '(') {
                int depth = 1, j = i + 1;
                while (depth > 0) { if (s[j]=='(') depth++; else if (s[j]==')') depth--; j++; }
                tokens.push_back(s.substr(i, j - i)); i = j;
            } else {
                int j = i;
                while (j < (int)s.size() && s[j] != ' ') j++;
                tokens.push_back(s.substr(i, j - i)); i = j;
            }
        }
        return tokens;
    }
};
