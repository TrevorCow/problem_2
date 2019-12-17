#pragma once

#include "Tree.h"
#include "TreeNode.h"
#include <vector>
#include "LinkedStack.h"

template<class T>
class BinaryTree : public Tree<T> {
private:
    TreeNode<T> *root;

    int height(TreeNode<T> *root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(height(root->left), height(root->right));
    }

public:
    BinaryTree() : root(nullptr) {};

    BinaryTree(std::vector<T> &array) {
        // not implemented yet
    }

    BinaryTree(TreeNode<T> *root) : root(root) {
    }

    bool contains(T val) override {
        // not implemented yet
        return false;
    }

    std::vector<T> traverseInOrder() override {
        //LEFT ROOT RIGHT
        std::vector<T> inorder;
        LinkedStack<TreeNode<T> *> stack;
        TreeNode<T> *curr = root;
        while (curr != nullptr || !stack.isEmpty()) {
            while (curr != nullptr) {
                stack.push(curr);
                curr = curr->getLeft();
            }
            curr = stack.peek();
            stack.pop();

            inorder.push_back(curr->val);

            curr = curr->getRight();
        }

        return inorder;
    }

    std::vector<T> traversePreOrder() override {
        // don't bother
    }

    std::vector<T> traversePostOrder() override {
        ///LEFT RIGHT ROOT
        std::vector<T> postorder;
        LinkedStack<TreeNode<T> *> stack;
        TreeNode<T> *curr = root;
        do {
            while (curr != nullptr) {
                if (curr->getRight() != nullptr) {
                    stack.push(curr->getRight());
                }
                stack.push(curr);

                curr = curr->getLeft();
            }

            curr = stack.peek();
            stack.pop();

            if (curr->getRight() != nullptr && !stack.isEmpty() && stack.peek() == curr->getRight()) {
                stack.pop();
                stack.push(curr);
                curr = curr->getRight();
            } else {
                postorder.push_back(curr->val);
                curr = nullptr;
            }

        } while (!stack.isEmpty());


        return postorder;
    }

    void deleteNode(TreeNode<T> *node) {
        if (node != nullptr) {
            TreeNode<T> *left = node->getLeft();
            TreeNode<T> *right = node->getRight();

            delete node;
            deleteNode(left);
            deleteNode(right);
        }
    }

    virtual ~BinaryTree() {
        deleteNode(root);
    }

    TreeNode<T> *LCA(TreeNode<T> *node, T node1, T node2) {
        if (node == nullptr) return nullptr;

        if (node->val == node1 || node->val == node2)
            return node;

        TreeNode<T> *leftLCA = LCA(node->getLeft(), node1, node2);
        TreeNode<T> *rightLCA = LCA(node->getRight(), node1, node2);

        if (leftLCA && rightLCA) return node;

        return (leftLCA != nullptr) ? leftLCA : rightLCA;
    }


    T LCA(T node1, T node2) {
        TreeNode<T> *test = LCA(root, node1, node2);
        return test->val;
    }

    bool add(const T &) override {
        // not implemented yet
    }

    bool remove(const T &) override {
        // not implemented yet
    }

    int height() override {
        return height(root);
    }

};
