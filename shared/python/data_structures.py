"""
Shared data structures for LeetCode problems.
Matches LeetCode's internal representations.
"""
from typing import List, Optional
import json


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __repr__(self):
        vals = []
        node = self
        seen = set()
        while node and id(node) not in seen:
            seen.add(id(node))
            vals.append(str(node.val))
            node = node.next
        return " -> ".join(vals)


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self):
        return f"TreeNode({self.val})"


class Node:
    """For N-ary tree, graph clone, etc."""
    def __init__(self, val=0, neighbors=None, children=None, next=None, random=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
        self.children = children if children is not None else []
        self.next = next
        self.random = random


# ---------------------------------------------------------------------------
# Serialization helpers (match LeetCode format)
# ---------------------------------------------------------------------------

def list_to_linked(arr):
    """Convert array to linked list. [1,2,3] -> 1->2->3"""
    if not arr:
        return None
    head = ListNode(arr[0])
    curr = head
    for val in arr[1:]:
        curr.next = ListNode(val)
        curr = curr.next
    return head


def linked_to_list(head):
    """Convert linked list to array. 1->2->3 -> [1,2,3]"""
    result = []
    seen = set()
    while head and id(head) not in seen:
        seen.add(id(head))
        result.append(head.val)
        head = head.next
    return result


def list_to_tree(arr):
    """Convert LeetCode-format array to binary tree.
    [1,null,2,3] -> tree with root=1, right=2, right.left=3
    Uses level-order (BFS) serialization.
    """
    if not arr or arr[0] is None:
        return None
    root = TreeNode(arr[0])
    queue = [root]
    i = 1
    while queue and i < len(arr):
        node = queue.pop(0)
        # Left child
        if i < len(arr):
            if arr[i] is not None:
                node.left = TreeNode(arr[i])
                queue.append(node.left)
            i += 1
        # Right child
        if i < len(arr):
            if arr[i] is not None:
                node.right = TreeNode(arr[i])
                queue.append(node.right)
            i += 1
    return root


def tree_to_list(root):
    """Convert binary tree to LeetCode-format array (level-order).
    Trims trailing nulls.
    """
    if not root:
        return []
    result = []
    queue = [root]
    while queue:
        node = queue.pop(0)
        if node:
            result.append(node.val)
            queue.append(node.left)
            queue.append(node.right)
        else:
            result.append(None)
    # Trim trailing Nones
    while result and result[-1] is None:
        result.pop()
    return result


def list_to_linked_cycle(arr, pos):
    """Create a linked list with a cycle. pos = index where tail connects (-1 for no cycle)."""
    if not arr:
        return None
    head = list_to_linked(arr)
    if pos == -1:
        return head
    # Find the tail and the node at pos
    tail = head
    target = None
    idx = 0
    while tail.next:
        if idx == pos:
            target = tail
        tail = tail.next
        idx += 1
    if idx == pos:
        target = tail
    if target:
        tail.next = target
    return head
