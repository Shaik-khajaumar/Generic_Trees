//
//  main2.cpp
//  DataStructures
//
//  Created by Shaik on 26/01/25.
//

#include "CompleteBinaryTree.h"

class Student {
    int id {-1};
    int marks {0};
public:
    Student (int i, int m) : id (i), marks(m) {}
    
    //This is overloading << for std::cout<<studentObjcet;
    friend std::ostream& operator<< (std::ostream&os, const Student& s) {
        os<<"The student id: "<<s.id<<" and marks: "<<s.marks<<"\n";
        return os;
    }
    bool operator == (const Student& first) const {
        return id == first.id;
    }
    int getid() const {
        return id;
    }
    int getmarks() const {
        return marks;
    }
};

int main () {
    
    Student s1 (1, 95);
    Student s2(2, 99);
    Student s3 (3, 55);
    Student s4 (4, 56);
    Student s5 (6, 78);
    Student s6 (7, 82);
    Student s7 (5, 67);
    Student s8 (9, 47);
    Student s9 (8, 96);
    Student s10 (9, 96);
    Student s11 (23, 65);
    
    CompleteBinaryTree<Student> obj1;
    
    CompleteBinaryTree<int> obj;
    obj1.add(s1);
    obj1.add(s2);
    obj1.add(s3);
    obj1.add(s4);
    obj1.add(s5);
    obj1.add(s6);
    obj1.add(s7);
    obj1.add(s8);
    obj1.add(s9);
    obj1.add(s10);
    obj1.add(s11);
    std::vector<int> v {1, 2, 3, 4, 5, 6, 7};
    
    for (int e : v)
    obj.add(e);
    
    std::cout<<obj.size();
    
    std::cout<<"inorder: \n";
    std::vector<int> values = obj.inorder();
    for (int e : values) {
        std::cout<<e<<"\n";
    }
    
    std::cout<<"levelorder: \n";
    values = obj.levelorder();
    for (int e : values) {
        std::cout<<e<<"\n";
    }
    
    obj.remove(1);
    std::cout<<"After deleting root i.e 1: \n";
    std::cout<<"inorder: \n";
    values = obj.inorder();
    for (int e : values) {
        std::cout<<e<<"\n";
    }
    
    std::cout<<"levelorder: \n";
    obj.level();
    
    obj.remove(5);
    std::cout<<"After deleting 5: \n";
    std::cout<<"inorder: \n";
    values = obj.inorder();
    for (int e : values) {
        std::cout<<e<<"\n";
    }
    
    std::cout<<"levelorder: \n";
    obj.level();
    
    
    std::cout<<"inorder for Student objects: \n";
    std::vector<Student> vv = obj1.inorder();
    for (auto e : vv) {
        std::cout<<e<<"\n";
    }
    
    std::cout<<"levelorder: \n";
    vv = obj1.levelorder();
    for (auto e : vv) {
        std::cout<<e<<"\n";
    }
    
    std::cout<<"removing s1: \n";
    
    obj1.remove(s1);
    std::cout<<"inorder for Student objects: \n";
    vv = obj1.inorder();
    for (auto e : vv) {
        std::cout<<e<<"\n";
    }
    
    std::cout<<"levelorder: \n";
    vv = obj1.levelorder();
    for (auto e : vv) {
        std::cout<<e<<"\n";
    }
    
    return 0;
}
