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

        if (leftValue != -1)
        {
            Node *leftOFront = new Node(leftValue);
            frontNode->leftNode = leftOFront;
        }
        else
        {
            Node *leftOfFront = NULL;
            frontNode->leftNode = leftOfFront;
        }

        if (rightValue != -1)
        {
            Node *rightOfFront = new Node(rightValue);
            frontNode->rightNode = rightOfFront;
        }
        else
        {
            Node *rightOfFront = NULL;
            frontNode->rightNode = rightOfFront;
        }

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

void printUsingLevelOrder(Node *root)
{
    if(root == NULL){
        cout << "There is no tree";
        return;
    }
    
    queue<Node *> nodeQueue;
    nodeQueue.push(root);
    while (!nodeQueue.empty())
    {
        Node *frontNode = nodeQueue.front();
        nodeQueue.pop();

        cout << frontNode->integerValue << " ";

        if (frontNode->leftNode)
        {
            nodeQueue.push(frontNode->leftNode);
        }

        if (frontNode->rightNode)
        {
            nodeQueue.push(frontNode->rightNode);
        }
    }
}

int main()
{
    Node *root = inputTree();
    printUsingLevelOrder(root);

    return 0;
}