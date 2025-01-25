//
//  Binary_Tree_functions.h
//  DataStructures
//
//  Created by Shaik on 25/01/25.
//

#ifndef Binary_Tree_functions_h
#define Binary_Tree_functions_h


#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include "TreeNode.h"
//This is header file containing all extra Binary Tree functions

template <typename T>
int height (TreeNode<T>* root) {
    if (root == nullptr) {
        return 0;
    }
    return std::max (height(root->left), height(root->right)) + 1;
}

template <typename T>
int size (TreeNode<T>* root) {
    if (root == nullptr) {
        return 0;
    }
    return size(root->left) + size(root->right) + 1;
}

template <typename T>
void preorder (std::vector<T>& values, TreeNode<T>* root) {
    if (root == nullptr) {
        return;
    }
    values.push_back (root->key);
    inorder (values, root->left);
    inorder (values, root->right);
}

template <typename T>
std::vector<T> preorder_traversal (TreeNode<T>* root) {
    std::vector<T> values;
    preorder (values, root);
    return values;
}

template <typename T>
void inorder (std::vector<T>& values, TreeNode<T>* root) {
    if (root == nullptr) {
        return;
    }
    inorder (values, root->left);
    values.push_back (root->key);
    inorder (values, root->right);
    }
template <typename T>
std::vector<T> inorder_traversal (TreeNode<T>* root) {
    std::vector<T> values;
    inorder (values, root);
    return values;
}

template <typename T>
void postorder (std::vector<T>& values, TreeNode<T>* root) {
    if (root == nullptr) {
        return;
    }
    inorder (values, root->left);
    inorder (values, root->right);
    values.push_back (root->key);
}
template <typename T>
std::vector<T> postorder_traversal (TreeNode<T>* root) {
    std::vector<T> values;
    postorder (values, root);
    return values;
}

template <typename T>
std::vector<T> levelorder_traversal (TreeNode<T>* root) {
    if (root == nullptr) {
        return std::vector<T> {};
    }
    
    std::vector<T> values;
    values.push_back(root->key);
    std::queue<TreeNode<T>*> q;
    q.push(root);
    
    while (!q.empty ()) {
        TreeNode<T>* temp = q.front();
        q.pop();
        if (temp->left != nullptr) {
            values.push_back(temp->left->key);
            q.push(temp->left);
        }
        
        if (temp->right != nullptr) {
            values.push_back(temp->right->key);
            q.push(temp->right);
        }
    }
    return values;
}

template <typename T>
std::vector<T> left_view (TreeNode<T>* root) {
    if (root == nullptr) {
        return std::vector<T> {};
    }
    std::queue<std::pair<int, TreeNode<T>*>> q;
    q.push({0, root});
        
    std::vector<T> values;
    int req_level = 0;
            
    while (!q.empty()) {
        int level = q.front().first;
        TreeNode<T>* temp = q.front().second;
        if (level == req_level) {
            values.push_back(temp->key);
            req_level++;
        }
        q.pop();
        if (temp->left != nullptr) {
            q.push({req_level, temp->left});
        }
        if (temp->right != nullptr) {
            q.push({req_level, temp->right});
        }
    }
    return values;
}

template <typename T>
std::vector<T> right_view (TreeNode<T>* root) {
    if (root == nullptr) {
        return std::vector<T> {};
    }
    
    std::queue<std::pair<int, TreeNode<T>*>> q;
    q.push({0, root});
    std::vector<T> values;
    int req_level = 0;
    
    while (!q.empty()) {
        int level = q.front().first;
        TreeNode<T>* temp = q.front().second;
        if (level == req_level) {
            values.push_back(temp->key);
            req_level++;
        }
        q.pop();
        if (temp->right != nullptr) {
            q.push({req_level, temp->right});
        }
        if (temp->left != nullptr) {
            q.push({req_level, temp->left});
        }
    }
    return values;
}

template <typename T>
std::vector<T> bottom_view (TreeNode<T>* root) {
    if (root == nullptr) {
        return std::vector<T> {};
    }
    
    std::vector<T> values;
    std::map<int, T> mp;
    std::queue<std::pair<int, TreeNode<T>*>> q;
    q.push({0, root});

    while (!q.empty()) {
        std::pair<int, TreeNode<T>*> t = q.front();
        q.pop();
        
        int level = t.first;
        TreeNode<T>* temp = t.second;

        if (mp.find(level) == mp.end()) {
            mp[level] = temp;
        }
        if (temp->left != nullptr) {
            q.push({level - 1, temp->left});
        }
        if (temp->right != nullptr) {
            q.push({level + 1, temp->right});
        }
    }

    for (std::pair<int, T> p : mp) {
        values.push_back(p.second);
    }

    return values;
}

template <typename T>
std::vector<T> top_view(TreeNode<T>* root) {
    if (root == nullptr) {
        return std::vector<T> {};
    }
    
    std::vector<T> values;
    std::map<int, T> mp;
    std::queue<std::pair<int, TreeNode<T>*>> q;

    q.push({0, root});

    while (!q.empty()) {
        std::pair<int, TreeNode<T>*> t = q.front();
        q.pop();

        int level = t.first;
        TreeNode<T>* temp = t.second;

        mp[level] = temp;

        if (temp->left != nullptr) {
            q.push({level - 1, temp->left});
        }
        if (temp->right != nullptr) {
            q.push({level + 1, temp->right});
        }
    }

    for (std::pair<int, T> p : mp) {
        values.push_back(p.second);
    }

    return values;
}




#endif /* Binary_Tree_functions_h */
