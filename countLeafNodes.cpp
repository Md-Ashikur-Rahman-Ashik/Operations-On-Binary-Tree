#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int integerValue;
    Node *leftNode;
    Node *rightNode;

    Node(int integerValue)
    {
        this->integerValue = integerValue;
        this->leftNode = NULL;
        this->rightNode = NULL;
    }
};

Node *inputTree()
{
    int inputValue;
    cin >> inputValue;
    if (inputValue == -1)
    {
        return NULL;
    }

    Node *root = new Node(inputValue);
    queue<Node *> nodeQueue;
    nodeQueue.push(root);
    while (!nodeQueue.empty())
    {
        Node *frontNode = nodeQueue.front();
        nodeQueue.pop();

        int leftValue, rightValue;
        cin >> leftValue >> rightValue;

        Node *leftOfFront, *rightOfFront;

        if (leftValue != -1)
        {
            leftOfFront = new Node(leftValue);
        }
        else
        {
            leftOfFront = NULL;
        }

        frontNode->leftNode = leftOfFront;

        if (rightValue != -1)
        {
            rightOfFront = new Node(rightValue);
        }
        else
        {
            rightOfFront = NULL;
        }

        frontNode->rightNode = rightOfFront;

        if (frontNode->leftNode)
        {
            nodeQueue.push(frontNode->leftNode);
        }

        if (frontNode->rightNode)
        {
            nodeQueue.push(frontNode->rightNode);
        }
    }

    return root;
}

int countLeafNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int leftCount = countLeafNodes(root->leftNode);
        int rightCount = countLeafNodes(root->rightNode);

        if (root->leftNode == NULL && root->rightNode == NULL)
        {
            return (leftCount + rightCount + 1);
        }
        else
        {
            return (leftCount + rightCount);
        }
    }
}

int main()
{
    Node *root = inputTree();
    int count = countLeafNodes(root);
    cout << count;

    return 0;
}