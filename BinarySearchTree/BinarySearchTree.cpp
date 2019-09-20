#include "BinarySearchTree.h"
#include<iostream>
using namespace std;

BinarySearchTree::BinarySearchTree()
    : p_root(nullptr)
{
}

BinarySearchTree::~BinarySearchTree()
{
    //dtor
}



void BinarySearchTree::printTree()
{
    printTreeHelper(p_root);
}
void BinarySearchTree::printTreeHelper(SearchTreeNode * p_node)
{
    if (p_node)
    {
        cout << p_node->data << " ";

        printTreeHelper(p_node->p_left);
        printTreeHelper(p_node->p_right);
    }
}


void BinarySearchTree::insert(int n)
{
    if(!p_root)
    {
        p_root = new SearchTreeNode(n);
    }
    else
    {
        insert_recursive(n, p_root);
    }
}

void BinarySearchTree::insert_recursive(int n, SearchTreeNode * p_node)
{
    if (n < p_node->data)
    {
        if (p_node->p_left)
        {
            insert_recursive(n, p_node->p_left);
        }
        else
        {
            p_node->p_left = new SearchTreeNode(n);
        }
    }
    else
    {

        if (p_node->p_right)
        {
            insert_recursive(n, p_node->p_right);
        }
        else
        {
            p_node->p_right = new SearchTreeNode(n);
        }
    }
}


void BinarySearchTree::insert_not_recursive(int n, SearchTreeNode * p_node)
{
    while(p_node)
    {
        if (p_node->p_left && n < p_node->data)
        {
            p_node = p_node->p_left;
        }
        else if (n < p_node->data && !p_node->p_left)
        {
            p_node->p_left = new SearchTreeNode(n);
            break;
        }
        else if (p_node->p_right)
        {
            p_node = p_node->p_right;
        }
        else
        {
            p_node->p_right = new SearchTreeNode(n);
            break;
        }
    }
}
