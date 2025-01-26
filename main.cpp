//
////  main.cpp
////  DataStructures
////
////  Created by Shaik on 18/01/25.
//#include "BST.h"
//#include "avl.hpp"
//#include <iostream>
//#include "CompleteBinaryTree.h"
//class Student {
//    int id {-1};
//    int marks {0};
//public:
//    Student (int i, int m) : id (i), marks(m) {}
////    bool operator <(const Student& first) const  {
////        return marks < first.marks;
////    }
////    bool operator == (const Student& first) const {
////        return marks == first.marks;
////    }
//    
//    //This is overloading << for std::cout<<studentObjcet;
//    friend std::ostream& operator<< (std::ostream&os, const Student& s) {
//        os<<"The student id: "<<s.id<<" and marks: "<<s.marks<<"\n";
//        return os;
//    }
//    int getid() const {
//        return id;
//    }
//    int getmarks() const {
//        return marks;
//    }
//};
//
//int main () {
//    
//    Student s1 (1, 95);
//    Student s2(2, 99);
//    Student s3 (3, 55);
//    Student s4 (4, 56);
//    Student s5 (6, 78);
//    Student s6 (7, 82);
//    Student s7 (5, 67);
//    Student s8 (9, 47);
//    Student s9 (8, 96);
//    Student s10 (9, 96);
//    Student s11 (23, 65);
//    
//    avl<Student> avl1 ([&] (Student a, Student b) -> bool { return a.getid() < b.getid();}, [&] (Student a, Student b) -> bool { return a.getid() == b.getid();});
//    BST<Student> bst ([&] (Student a, Student b) -> bool { return a.getid() < b.getid();}, [&] (Student a, Student b) -> bool { return a.getid() == b.getid();});
//    bst.add(s1);
//    bst.add(s2);
//    bst.add(s3);
//    bst.add(s4);
//    bst.add(s5);
//    bst.add(s6);
//    bst.add(s7);
//    bst.add(s8);
//    bst.add(s9);
//    bst.add(s10);
//    bst.add(s11);
//    
//    avl1.add(s1);
//    avl1.add(s2);
//    avl1.add(s3);
//    avl1.add(s4);
//    avl1.add(s5);
//    avl1.add(s6);
//    avl1.add(s7);
//    avl1.add(s8);
//    avl1.add(s9);
//    avl1.add(s10);
//    avl1.add(s11);
//    
//    std::cout<<"height: "<<bst.height()<<"\n";
//    std::cout<<"height: "<<avl1.height()<<"\n";
//    
//    std::vector<Student> v = bst.inorder();
//    std::cout<<"INorder traversal: \n";
//    for (auto s : v) {
//        std::cout<<s<<"\n";
//    }
//    v = avl1.inorder();
//    std::cout<<"INorder traversal for avl: \n";
//    for (auto s : v) {
//        std::cout<<s<<"\n";
//    }
//    
//    std::cout<<"Levelorder traversal: \n";
//    v = bst.levelorder();
//    for (auto s : v) {
//        std::cout<<s<<"\n";
//    }
//    std::cout<<"Levelorder traversal for avl: \n";
//    v = avl1.levelorder();
//    for (auto s : v) {
//        std::cout<<s<<"\n";
//    }
//    
//    bst.remove(s4);
//    std::cout<<"after removing s4: \n";
//    std::cout<<"INorder traversal: \n";
//    v = bst.inorder();
//    for (auto s : v) {
//        std::cout<<s<<"\n";
//    }
//    std::cout<<"Levelorder traversal: \n";
//    v = bst.levelorder();
//    for (auto s : v) {
//        std::cout<<s<<"\n";
//    }
//    
//    avl1.remove(s4);
//    std::cout<<"after removing s4 in avl: \n";
//    std::cout<<"INorder traversal in avl: \n";
//    v = avl1.inorder();
//    for (auto s : v) {
//        std::cout<<s<<"\n";
//    }
//    std::cout<<"Levelorder traversal in avl: \n";
//    v = avl1.levelorder();
//    for (auto s : v) {
//        std::cout<<s<<"\n";
//    }
//    
//    
//    bst.remove(s1);
//    std::cout<<"after removing s1: \n";
//    std::cout<<"Inorder traversal: \n";
//    v = bst.inorder();
//    for (auto s : v) {
//        std::cout<<s<<"\n";
//    }
//    std::cout<<"Levelorder traversal: \n";
//    v = bst.levelorder();
//    for (auto s : v) {
//        std::cout<<s<<"\n";
//    }
//    
//    avl1.remove(s1);
//    std::cout<<"after removing s1 in avl: \n";
//    std::cout<<"Inorder traversal in avl: \n";
//    v = avl1.inorder();
//    for (auto s : v) {
//        std::cout<<s<<"\n";
//    }
//        
//    std::cout<<"Levelorder traversal in avl1: \n";
//    v = avl1.levelorder();
//    for (auto s : v) {
//        std::cout<<s<<"\n";
//    }
//        
//    std::cout<<"height: "<<bst.height()<<"\n";
//    std::cout<<"height: "<<avl1.height()<<"\n";
//        //NISAB PROBLEM
//        //    Student ss(66,66);
//        //    Student sss(64,64);
//        //    Student sss(63,63);
//        //    TreeNode<Student> node1(ss);
//        //    node1->left = TreeNode<Student>(sss);
//        //    node1->right = TreeNode<Student>(ssss);
//        return 0;
//}
//    
