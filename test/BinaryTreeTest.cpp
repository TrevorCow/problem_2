#include "BinaryTree.h"
#include "gtest/gtest.h"

TEST(tree, demo) {
    TreeNode<int> *root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));

    BinaryTree<int> tree(root);

    ASSERT_EQ(tree.height(), 3);
}

TEST(tree, destroy) {
    TreeNode<int> *root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));

    BinaryTree<int> *tree = new BinaryTree<int>(root);
    delete tree;
}

TEST(tree, inorder) {
    TreeNode<int> *root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));

    BinaryTree<int> tree(root);

    std::vector<int> inorder = tree.traverseInOrder();

    ASSERT_TRUE(inorder == (std::vector<int>{2, 1, 7, 3, 5, 5,}));
}

TEST(tree, postorder) {
    TreeNode<int> *root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));

    BinaryTree<int> tree(root);

    std::vector<int> postorder = tree.traversePostOrder();

    ASSERT_TRUE(postorder == (std::vector<int>{2, 7, 1, 5, 5, 3}));
}

TEST(tree, LCA) {
    TreeNode<int> *root = new TreeNode<int>(4);
    root->setLeft(new TreeNode<int>(8));
    root->setRight(new TreeNode<int>(6));

    root->getLeft()->setLeft(new TreeNode<int>(7));
    root->getLeft()->setRight(new TreeNode<int>(3));

    root->getRight()->setLeft(new TreeNode<int>(2));
    root->getRight()->setRight(new TreeNode<int>(9));

    BinaryTree<int> tree(root);

    ASSERT_TRUE(tree.LCA(4, 4) == 4);
    ASSERT_TRUE(tree.LCA(7, 7) == 7);
    ASSERT_TRUE(tree.LCA(7, 3) == 8);
    ASSERT_TRUE(tree.LCA(7, 8) == 8);
    ASSERT_TRUE(tree.LCA(8, 6) == 4);
    ASSERT_TRUE(tree.LCA(3, 2) == 4);

}