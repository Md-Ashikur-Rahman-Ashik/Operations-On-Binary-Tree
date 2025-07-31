#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int integerValue;
    Node *leftPointer;
    Node *rightPointer;

    Node(int integerValue)
    {
        this->integerValue = integerValue;
        this->leftPointer = NULL;
        this->rightPointer = NULL;
    }
};

void levelOrder(Node *root)
{
    queue<Node *> nodeQueue;
    nodeQueue.push(root);
    while (!nodeQueue.empty())
    {
        Node *frontNode = nodeQueue.front();
        nodeQueue.pop();

        cout << frontNode->integerValue << " ";
        if (frontNode->leftPointer != NULL)
        {
            nodeQueue.push(frontNode->leftPointer);

            if (frontNode->rightPointer != NULL)
            {
                nodeQueue.push(frontNode->rightPointer);
            }
        }
        else if (frontNode->rightPointer != NULL)
        {
            nodeQueue.push(frontNode->rightPointer);
        }
    }
}

int main()
{
    Node *root = new Node(10);
    Node *leftOfRoot = new Node(20);
    Node *leftOfTwenty = new Node(40);
    Node *rightOfRoot = new Node(30);
    Node *leftOfThirty = new Node(50);
    Node *rightOfThirty = new Node(60);

    root->leftPointer = leftOfRoot;
    leftOfRoot->leftPointer = leftOfTwenty;
    root->rightPointer = rightOfRoot;
    rightOfRoot->leftPointer = leftOfThirty;
    rightOfRoot->rightPointer = rightOfThirty;

    levelOrder(root);

    return 0;
}