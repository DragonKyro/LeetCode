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
    unordered_map<string, int> lookup;
    using Poly = map<vector<string>, int>;

    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        for (int i = 0; i < (int)evalvars.size(); i++) lookup[evalvars[i]] = evalints[i];
        auto tokens = tokenize(expression);
        int idx = 0;
        Poly poly = parseExpr(tokens, idx);
        vector<pair<vector<string>, int>> entries;
        for (auto& [k, v] : poly) if (v != 0) entries.push_back({k, v});
        sort(entries.begin(), entries.end(), [](auto& a, auto& b) {
            if (a.first.size() != b.first.size()) return a.first.size() > b.first.size();
            return a.first < b.first;
        });
        vector<string> result;
        for (auto& [k, v] : entries) {
            string s = to_string(v);
            for (auto& var : k) s += "*" + var;
            result.push_back(s);
        }
        return result;
    }

    vector<string> tokenize(string& s) {
        vector<string> tokens;
        int i = 0;
        while (i < (int)s.size()) {
            if (s[i] == ' ') { i++; continue; }
            if (string("()*+-").find(s[i]) != string::npos) { tokens.push_back(string(1, s[i])); i++; }
            else { int j = i; while (j < (int)s.size() && s[j] != ' ' && string("()*+-").find(s[j]) == string::npos) j++; tokens.push_back(s.substr(i, j-i)); i = j; }
        }
        return tokens;
    }

    Poly parseExpr(vector<string>& tokens, int& idx) {
        Poly left = parseTerm(tokens, idx);
        while (idx < (int)tokens.size() && (tokens[idx] == "+" || tokens[idx] == "-")) {
            string op = tokens[idx++]; Poly right = parseTerm(tokens, idx);
            left = combine(left, right, op);
        }
        return left;
    }

    Poly parseTerm(vector<string>& tokens, int& idx) {
        Poly left = parseFactor(tokens, idx);
        while (idx < (int)tokens.size() && tokens[idx] == "*") {
            idx++; Poly right = parseFactor(tokens, idx);
            left = combine(left, right, "*");
        }
        return left;
    }

    Poly parseFactor(vector<string>& tokens, int& idx) {
        if (tokens[idx] == "(") { idx++; Poly result = parseExpr(tokens, idx); idx++; return result; }
        string token = tokens[idx++]; Poly m;
        if (lookup.count(token)) m[{}] = lookup[token];
        else if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) m[{}] = stoi(token);
        else m[{token}] = 1;
        return m;
    }

    Poly combine(Poly& a, Poly& b, string op) {
        Poly result;
        if (op == "*") {
            for (auto& [k1, v1] : a) for (auto& [k2, v2] : b) {
                vector<string> key(k1); key.insert(key.end(), k2.begin(), k2.end()); sort(key.begin(), key.end());
                result[key] += v1 * v2;
            }
        } else {
            result = a;
            int sign = op == "+" ? 1 : -1;
            for (auto& [k, v] : b) result[k] += sign * v;
        }
        return result;
    }
};
