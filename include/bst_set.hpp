#pragma once
#include <set>
#include<limits>
#include <stdexcept>
#include <stdio.h>

template <typename Key, class Compare = std::less<Key>> class BSTSet
{
  private:
    class Node
    {
        Node *right;
        Node *left;
        Node *parent;
        Key value;
        friend BSTSet;

        Node() : right(nullptr), left(nullptr), parent(nullptr) {}

        Node(const Key &value) : right(nullptr), left(nullptr), parent(nullptr), value(value) {}
    };

    Node *root;
    Node *leftmost;
    Node *rightmost;

    void clear_(Node *n)
    {
        if (n)
        {
            clear_(n->left);
            clear_(n->right);
            delete n;
        }
    }

    Node *get_node(const Key &t)
    {
        sz++;
        return new Node(t);
    }

    size_t sz;


  public:
    typedef Key value_type;
    typedef Key key_type;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef Compare key_compare;
    typedef Compare value_compare;
    typedef Key &reference;
    typedef const Key &const_reference;
    class Iterator;
    typedef Iterator iterator;
    typedef const Iterator const_iterator;

    class Iterator
    {
      private:
        Node *node;

        void next()
        {
            Node *inorder_successor = node->right, *current, *parent;
            // Move node to next node which is greater than this node
            if (!node)
            {
                throw std::out_of_range("Out of range");
            }

            // If this node has a right subtree, find the inorder sucessor
            if (node->right)
            {
                inorder_successor = node->right;
                while (inorder_successor && inorder_successor->left)
                    inorder_successor = inorder_successor->left;
                node = inorder_successor;
                return;
            }

            // If the node has a parent,
            if (node->parent)
            {
                current = node;
                parent = node->parent;
                // Keep traversing up, until we reach a node who is the left subtree for it's parent
                while (parent && parent->right == current)
                {
                    current = parent;
                    parent = current->parent;
                }
                node = parent;
            }

            else
            {
                // This is the root node, which does not have a right subtree
                node = nullptr;
            }
        }

      public:
        Iterator() : node(nullptr) {}

        Iterator(Node *node) : node(node) {}

        bool operator==(const Iterator &other) const { return node == other.node; }

        bool operator!=(const Iterator &other) const { return !(*this == other); }

        // Post increment
        Iterator operator++(int)
        {
            Iterator it(node);
            next();
            return it;
        }

        // Pre-increment
        Iterator &operator++()
        {
            next();
            return *this;
        }

        const Key &operator*() const { return node->value; }
    };

    BSTSet() : root(nullptr), leftmost(nullptr), rightmost(nullptr), sz(0) {}

    size_t size() { return sz; }

    std::pair<Iterator, bool> insert(const Key &t)
    {
        Node *current = root, *parent = nullptr, *new_node;
        if (!root)
        {
            root = get_node(t);
            leftmost = root;
            rightmost = root;
            return std::make_pair(Iterator(root), true);
        }
        if (t == leftmost->value)
        {
            return std::make_pair(Iterator(leftmost), false);
        }
        if (t == rightmost->value)
        {
            return std::make_pair(Iterator(rightmost), false);
        }
        if (Compare{}(t, leftmost->value))
        {
            leftmost->left = get_node(t);
            leftmost->left->parent = leftmost;
            leftmost = leftmost->left;
            return std::make_pair(Iterator(leftmost), true);
        }
        if (!Compare{}(t, rightmost->value))
        {
            rightmost->right = get_node(t);
            rightmost->right->parent = rightmost;
            rightmost = rightmost->right;
            return std::make_pair(Iterator(rightmost), true);
        }
        while (current)
        {
            parent = current;
            if (Compare{}(t, current->value))
                current = current->left;
            else if (t == current->value)
                break;
            else
                current = current->right;
        }
        if (current)
        {
            return std::make_pair(Iterator(current), false);
        }
        new_node = get_node(t);
        new_node->parent = parent;
        if (Compare{}(t, parent->value))
            parent->left = new_node;
        else
            parent->right = new_node;
        return std::make_pair(Iterator(new_node), true);
    }

    void clear()
    {
        // TODO: Make an iterative clear function instead
        clear_(root);
        root = nullptr;
    }

    Iterator begin() const { return Iterator(leftmost); }

    Iterator end() const { return Iterator(); }

    Iterator cbegin() const { return begin(); }

    Iterator cend() const { return end(); }

    /*
    Implement decrement operation before rbegin/rend
    Iterator rbegin() const { return Iterator(rightmost); }
    Iterator rend() const { return Iterator(); }
    */

    ~BSTSet() { clear(); }
    
    bool empty() const {
        return sz == 0;
    }
    
    size_type max_size() const
    {
        return std::numeric_limits<difference_type>::max(); 
    }
};