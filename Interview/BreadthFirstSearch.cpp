#include "stdafx.h"
#include "general.h"
#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <deque>
#include <algorithm>
#include <utility>
#include <list>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <future>
#include <thread>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data);
};

Node::Node(int data) :
    data(data)
{
    this->left = nullptr;
    this->right = nullptr;
}

void bfs(Node* root)
{
    queue<Node*> q;

    if (root == nullptr)
    {
        return;
    }

    Node* temp = root;

    while (temp != nullptr)
    {
        cout << temp->data << " ";

        if (temp->left != nullptr)
        {
            q.push(temp->left);
        }

        if (temp->right != nullptr)
        {
            q.push(temp->right);
        }

        if (q.empty())
        {
            temp = nullptr;
        } 
        else
        {
            temp = q.front();
            q.pop();
        }
    }
}

int BST_BreadthFirstSearch_Main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    bfs(root);

    return 0;
}