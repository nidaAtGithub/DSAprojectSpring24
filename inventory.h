#pragma once
#include <iostream>
using namespace std;


struct AVLNode {
    int data;
    int height;
    AVLNode* left;
    AVLNode* right;
};

class AVLTree
{

public:
    AVLNode* root;
    AVLTree() : root(nullptr) {}
    //void insert(string data);
    //void inOrder(AVLNode* node); // For displaying inventory

    void insert(int data)
    {
        root = insertFunc(root, data);
    }

    void inOrder() 
    {
        displayAVL(root);
    }
    int height(AVLNode* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    int balanceFactor(AVLNode* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    AVLNode* rightRotate(AVLNode* node)
    {
        AVLNode* newRoot = node->left;
        AVLNode* temp = newRoot->right;
        newRoot->right = node;
        node->left = temp;

        // Update heights
        node->height = max(height(node->left), height(node->right)) + 1;
        newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

        return newRoot;
    }

    AVLNode* leftRotate(AVLNode* node) {
        AVLNode* newRoot = node->right;
        AVLNode* temp = newRoot->left;
        newRoot->left = node;
        node->right = temp;

        // Update heights
        node->height = max(height(node->left), height(node->right)) + 1;
        newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

        return newRoot;
    }

    AVLNode* insertFunc(AVLNode* node, int data)
    {

        if (node == nullptr) {
            AVLNode* newNode = new AVLNode;
            newNode->data = data;
            newNode->height = 1;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }

        if (data < node->data) {
            node->left = insertFunc(node->left, data);
        }
        else if (data > node->data) {
            node->right = insertFunc(node->right, data);
        }
        else {
            // Duplicate entry, handle as needed
            return node;
        }

        // Update height of the current node
        node->height = 1 + max(height(node->left), height(node->right));

        // Check balance factor
        int balance = balanceFactor(node);

        // Left-Left case
        if (balance > 1 && data < node->left->data) {
            return rightRotate(node);
        }
        // Right-Right case
        if (balance < -1 && data > node->right->data) {
            return leftRotate(node);
        }
        // Left-Right case
        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // Right-Left case
        if (balance < -1 && data < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void displayAVL(AVLNode* node)
    {
        if (node != nullptr) {
            displayAVL(node->left);
            cout << node->data << endl;
            displayAVL(node->right);
        }
    }
};

