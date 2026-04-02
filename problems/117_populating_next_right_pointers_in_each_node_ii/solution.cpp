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
    Node* connect(Node* root) {
        if (!root) return nullptr;
        Node* curr = root;
        while (curr) {
            Node dummy(0);
            Node* tail = &dummy;
            while (curr) {
                if (curr->left) { tail->next = curr->left; tail = tail->next; }
                if (curr->right) { tail->next = curr->right; tail = tail->next; }
                curr = curr->next;
            }
            curr = dummy.next;
        }
        return root;
    }
};
