//
//  BST.h
//  DataStructures
//
//  Created by Shaik on 25/01/25.
//

#ifndef BST_h
#define BST_h

#include "Binary_Tree_functions.h"
#include <functional>
template <typename T>
class BST {
    TreeNode<T>* root {nullptr};
    std::function<bool(T,T)> compare;
    std::function<bool(T,T)> compare_equal;
    
public:
    BST() : root (nullptr) {
        compare = [&] (T a, T b) -> bool {
            return a < b;
        };
        compare_equal = [&] (T a, T b) -> bool {
            return a == b;
        };
    }
    
    BST(std::function<bool(T,T)> user_compare, std::function<bool(T,T)> user_compare_equal) : root (nullptr), compare(user_compare), compare_equal(user_compare_equal) {}
    
    void deleteNode (TreeNode<T>* node) {
        if (node) {
            deleteNode (node->left);
            deleteNode (node->right);
            delete node;
        }
    }
    ~BST () {
        deleteNode(root);
    }
    
    TreeNode<T>* add_node (TreeNode<T>* root, T key) {
        if (root == nullptr) {
            root = new TreeNode(key);
            return root;
        }
        if (compare_equal(root->key, key) == true) {
            return root;
        }
        
        if (compare(key, root->key)) {
            root->left =  add_node(root->left, key);
        }
        else {
            root->right = add_node(root->right, key);
        }
        return root;
    }
    TreeNode<T>* add (T key) {
        return root = add_node (root, key);
    }
    
    TreeNode<T>* remove_node (TreeNode<T>* root, T key) {
        std::cout<<"now in: "<<root->key<<" and key: "<<key<<"\n";
        if (root == nullptr) {
            return nullptr;
        }
        
        if (compare_equal(root->key, key)) {
            //leaf
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            
            //If not leaf then get predessosor or sucessosor
            TreeNode<T>* pre = getPreNode (root->left);
            if (pre != nullptr) {
                T new_value = pre->key;
                root->left = remove_node(root->left, pre->key);
                root->key = new_value;
            }
            else {
                TreeNode<T>* sus = getSusNode (root->right);
                T new_value = sus->key;
                root->right = remove_node(root->right, sus->key);
                root->key = new_value;
            }
        }
        else if (compare(key, root->key)) {
            root->left = remove_node(root->left, key);
        }
        else {
            root->right = remove_node(root->right, key);
        }
        return root;
    }
    TreeNode<T>* remove (T key) {
        return root = remove_node (root, key);
    }
    
    TreeNode<T>* getPreNode (TreeNode<T>* root) {
        while (root && root->right != nullptr) {
            root = root->right;
        }
        return root;
    }

    TreeNode<T>* getSusNode (TreeNode<T>* root) {
        while (root && root->left != nullptr) {
            root = root->left;
        }
        return root;
    }
    
    
    TreeNode<T>*  Search(T key) {
        TreeNode<T>*  t = root;
        while (t != nullptr){
            if (key == t->key){
                return t;
            } else if (key < t->key){
                t = t->left;
            } else {
                t = t->right;
            }
        }
        return nullptr;
    }

    TreeNode<T>* getRoot() const { return root; }
};

#endif /* BST_h */

