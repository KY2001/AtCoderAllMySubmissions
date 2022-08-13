import sys
import math
import string
import fractions
import random
from operator import itemgetter
import itertools
from collections import deque
import copy
import heapq
import bisect

MOD = 10 ** 9 + 7
INF = float('inf')
input = lambda: sys.stdin.readline().strip()


class Node:
    def __init__(self, x):
        self.data = x
        self.priority = random.random()
        self.left = None
        self.right = None


def rotate_right(node):
    l_node = node.left
    node.left = l_node.right
    l_node.right = node
    return l_node


def rotate_left(node):
    r_node = node.right
    node.right = r_node.left
    r_node.left = node
    return r_node


def search_min(node):
    while node.left is not None:
        node = node.left
    return node.data


def traverse_(node):
    if node is not None:
        for x in traverse_(node.left):
            yield x
        yield node.data
        for x in traverse_(node.right):
            yield x


class Treap:
    """
    動的ランダム二分探索木の中の一つ。構築:O(nlogn), 他の操作:期待値O(logn)
    """

    def __init__(self):
        self.root = None

    def search(self, x):
        def search_(node, x):
            while node is not None:
                if x == node.data:
                    return True
                elif x < node.data:
                    node = node.left
                else:
                    node = node.right
            return False

        return search_(self.root, x)

    def insert(self, x):
        def insert_(node, x):
            if node is None:
                return Node(x)
            elif x == node.data:
                return node
            elif x < node.data:
                node.left = insert_(node.left, x)
                if node.priority > node.left.priority:
                    node = rotate_right(node)
            else:
                node.right = insert_(node.right, x)
                if node.priority > node.right.priority:
                    node = rotate_left(node)
            return node

        self.root = insert_(self.root, x)

    def delete(self, x):
        def delete_(node, x):
            if node is not None:
                if x == node.data:
                    if node.left is None:
                        return node.right
                    elif node.right is None:
                        return node.left
                    else:
                        node.data = search_min(node.right)
                        node.right = delete_(node.right, node.data)
                elif x < node.data:
                    node.left = delete_(node.left, x)
                else:
                    node.right = delete_(node.right, x)
            return node

        self.root = delete_(self.root, x)

    def traverse(self):

        for x in traverse_(self.root):
            yield x

    def lower_bound(self, x):
        def lower_bound_(node, x):
            while node is not None:
                if node.right and node.left:
                    if node.right.data < x:
                        return lower_bound_(node.right, x)
                    elif node.data < x:
                        return min(node.right.data, lower_bound_(node.right, x))
                    else:
                        return min(node.data, lower_bound_(node.left, x))
                elif node.right:
                    if node.right.data < x:
                        return lower_bound_(node.right, x)
                    elif node.data < x:
                        return min(node.right.data, lower_bound_(node.right, x))
                    else:
                        return node.data  # 怪しい！！
                elif node.left:
                    if node.data < x:
                        return INF
                    elif node.left.data < x:
                        return min(node.data, lower_bound_(node.left, x))
                    else:
                        return lower_bound_(node.left, x)
                elif x <= node.data:
                    return node.data
                else:
                    return INF

        if self.root:
            return lower_bound_(self.root, x)
        else:
            return INF

    def upper_bound(self, x):
        def upper_bound_(node, x):
            while node is not None:
                if node.right and node.left:
                    if node.left.data > x:
                        return upper_bound_(node.left, x)
                    elif node.data > x:
                        return max(node.left.data, upper_bound_(node.left, x))
                    else:
                        return max(node.data, upper_bound_(node.right, x))
                elif node.left:
                    if node.left.data > x:
                        return upper_bound_(node.left, x)
                    elif node.data > x:
                        return max(node.left.data, upper_bound_(node.left, x))
                    else:
                        return node.data
                elif node.right:
                    if node.data > x:
                        return -INF
                    elif node.right.data > x:
                        return max(node.data, upper_bound_(node.right, x))
                    else:
                        return upper_bound_(node.right, x)
                elif x >= node.data:
                    return node.data
                else:
                    return -INF

        if self.root:
            return upper_bound_(self.root, x)
        else:
            return -INF

    def __str__(self):
        if self.root is None:
            return "Treap()"
        buff = "Treap("
        for x in traverse_(self.root):
            buff += "%s, " % x
        buff = buff.rstrip(", ")
        buff += ")"
        return buff


N = int(input())
S = input()
Q = int(input())
strings = [Treap() for _ in range(26)]
alphabets = string.ascii_lowercase
check = {}
for i in range(26):
    check[alphabets[i]] = i
for i in range(N):
    strings[check[S[i]]].insert(i)
for _ in range(Q):
    Query, a, b = map(str, input().split())
    if Query == "1":
        a = int(a)
        strings[check[S[a - 1]]].delete(a - 1)
        strings[check[b]].insert(a - 1)
        S = S[:a-1] + b + S[a:]
    else:
        a, b = map(int, (a, b))
        ans = 0
        for i in range(26):
            if strings[i].lower_bound(a - 1) <= b - 1:
                ans += 1
        print(ans)
