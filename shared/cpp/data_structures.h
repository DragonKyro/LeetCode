#pragma once
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
#include <climits>

using namespace std;

// ---------------------------------------------------------------------------
// ListNode
// ---------------------------------------------------------------------------
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}

    static ListNode* fromArray(const vector<int>& arr) {
        if (arr.empty()) return nullptr;
        ListNode* head = new ListNode(arr[0]);
        ListNode* curr = head;
        for (size_t i = 1; i < arr.size(); i++) {
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }
        return head;
    }

    static vector<int> toArray(ListNode* head) {
        vector<int> result;
        unordered_set<ListNode*> seen;
        while (head && seen.find(head) == seen.end()) {
            seen.insert(head);
            result.push_back(head->val);
            head = head->next;
        }
        return result;
    }

    static void freeList(ListNode* head) {
        while (head) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
};

// ---------------------------------------------------------------------------
// TreeNode
// ---------------------------------------------------------------------------
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}

    // INT_MIN used as sentinel for null in the array
    static TreeNode* fromArray(const vector<int>& arr, int null_val = INT_MIN) {
        if (arr.empty() || arr[0] == null_val) return nullptr;
        TreeNode* root = new TreeNode(arr[0]);
        queue<TreeNode*> q;
        q.push(root);
        size_t i = 1;
        while (!q.empty() && i < arr.size()) {
            TreeNode* node = q.front(); q.pop();
            if (i < arr.size()) {
                if (arr[i] != null_val) {
                    node->left = new TreeNode(arr[i]);
                    q.push(node->left);
                }
                i++;
            }
            if (i < arr.size()) {
                if (arr[i] != null_val) {
                    node->right = new TreeNode(arr[i]);
                    q.push(node->right);
                }
                i++;
            }
        }
        return root;
    }

    static vector<int> toArray(TreeNode* root, int null_val = INT_MIN) {
        vector<int> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node) {
                result.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            } else {
                result.push_back(null_val);
            }
        }
        // Trim trailing nulls
        while (!result.empty() && result.back() == null_val) {
            result.pop_back();
        }
        return result;
    }

    static void freeTree(TreeNode* root) {
        if (!root) return;
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
};

// ---------------------------------------------------------------------------
// Node (N-ary tree / graph)
// ---------------------------------------------------------------------------
class Node {
public:
    int val;
    vector<Node*> children;
    vector<Node*> neighbors;
    Node* next;
    Node* random;

    Node() : val(0), next(nullptr), random(nullptr) {}
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
    Node(int _val, vector<Node*> _children) : val(_val), children(_children), next(nullptr), random(nullptr) {}
};
