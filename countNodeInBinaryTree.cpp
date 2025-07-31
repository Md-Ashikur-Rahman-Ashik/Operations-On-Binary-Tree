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

int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int countOfLeft = countNodes(root->leftNode);
        int countOfRight = countNodes(root->rightNode);
        return (countOfLeft + countOfRight + 1);
    }
}

int main()
{
    Node *root = inputTree();
    int count = countNodes(root);
    cout << count << endl;

    return 0;
}