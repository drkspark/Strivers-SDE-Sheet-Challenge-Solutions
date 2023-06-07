// URL : https://www.codingninjas.com/codestudio/problems/max-xor-queries_1382020?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
#include <vector.h>

class Node
{
public:
    vector<Node *> list;
    Node()
    {
        list = vector<Node *>(2, NULL);
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(int val)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int x = (val & (1 << i)) == 0;
            if (node->list[x] == NULL)
            {
                node->list[x] = new Node();
            }
            node = node->list[x];
        }
    }

    int getMaxXor(int val)
    {
        int res = 0;
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int x = (val & (1 << i)) == 0;
            if (node->list[x ^ 1] != NULL)
            {
                res |= (1 << i);
                node = node->list[x ^ 1];
            }
            else
            {
                node = node->list[x];
            }
        }
        return res;
    }
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &que)
{
    int n = que.size();
    vector<int> res(n);
    vector<vector<int>> newQ(n);
    for (int i = 0; i < n; i++)
    {
        newQ[i] = {que[i][1], que[i][0], i};
    }
    sort(begin(newQ), end(newQ));
    sort(begin(arr), end(arr));
    int idx = 0;
    Trie *t = new Trie();
    for (int i = 0; i < n; i++)
    {
        while (idx < arr.size() && arr[idx] <= newQ[i][0])
        {
            t->insert(arr[idx]);
            idx++;
        }

        if (idx == 0)
        {
            res[newQ[i][2]] = -1;
        }
        else
        {
            res[newQ[i][2]] = t->getMaxXor(newQ[i][1]);
        }
    }

    return res;
}