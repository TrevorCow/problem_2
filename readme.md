## Binary Trees (80pt)

Use folder ```problem_2```.

We work on the Binary Tree class here. The definitions of "in-order" and "post-order" are as discussed in class. 

### 1. (20pt) Implement the destructor ~BinaryTree() with pre-order traversal. 
```c++
virtual ~BinaryTree() override {
       // homework
}
```
For testing, please make sure no memory leak once tree object is deleted.

### 2. (20pt) Implemenet the in-order traverse iteratively. The following is given in BinaryTree.h:

```c++
std::vector<T> traverseInOrder() override {
    // homework, to be done iteratively
}
```

Also please add unit tests in BinaryTreeTest.cpp.

### 3. (20pt) Implemenet the post-order traverse iteratively. The following is given in BinaryTree.h:
```c++
std::vector<T> traversePostOrder() override {
    // homework, to be done iteratively
}
```

Also please add unit tests in BinaryTreeTest.cpp.

### 4. (20pt) Given a binary tree, write the function to find the lowest common ancestor (LCA) of two given nodes in the tree

The concept of LCA are as discussed in class. This needs to be done **recursively**. 

For example, with the following tree
```bash
        4
      /   \
     8     6
   /  \   / \
  7   3  2   9
```
- LCA(4, 4) = 4
- LCA(7, 7) = 7
- LCA(7, 3) = 8
- LCA(7, 8) = 8
- LCA(8, 6) = 4
- LCA(3, 2) = 4

You can assume the following
* tree only contain positive integers, and 
* tree will contain both nodes
* there are no duplicated numbers in the tree. The following is given in BinaryTree.h

```c++
T LCA(T node1, T node2) {
    // homework
}
```

Please add unit test with the above tree and examples as test cases. 
