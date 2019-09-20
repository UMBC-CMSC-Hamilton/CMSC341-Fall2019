#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#define nullptr 0

struct SearchTreeNode {
    SearchTreeNode(int local_data = 0)
        : data(local_data), p_left(nullptr), p_right(nullptr)
    {
    }
    int data;
    SearchTreeNode * p_left;
    SearchTreeNode * p_right;
};

class BinarySearchTree
{
    public:
        BinarySearchTree();

        void insert(int n);

        void printTree();
        void printTreeHelper(SearchTreeNode * p_node );
        virtual ~BinarySearchTree();

    private:
        void insert_recursive(int n, SearchTreeNode * p_node);

        void insert_not_recursive(int n, SearchTreeNode * p_node);
        SearchTreeNode * p_root;
};

#endif // BINARYSEARCHTREE_H
