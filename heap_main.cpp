#include "Heap.hpp"
#include <iostream>
#include <vector>
#include <functional>
#include <string>

class Student {
public:
    std::string name;
    int grade;

    Student(std::string n, int g) : name(n), grade(g) {}

    void print() const {
        std::cout << "Student: " << name << ", Grade: " << grade << std::endl;
    }

    // bool operator> (Student& s) {
    //     return grade > s.grade;
    // }

    friend std::ostream& operator<<(std::ostream& os, Student& s) {
        os<<"The student name: "<<s.name<<" and grade: "<<s.grade<<"\n";
        return os;
    }
};

struct StudentGradeComparator {
    bool operator()(const Student& a, const Student& b) const {
        return a.grade > b.grade;  // Max-heap based on grade
    }
};

int main() {
    std::vector<Student> students = {
        Student("Alice", 90),
        Student("Bob", 85),
        Student("Charlie", 92),
        Student("Diana", 88)
    };

    Heap<Student> studentHeap(students, StudentGradeComparator());
    // Heap<Student> studentHeap(students);

    std::cout << "Heap after heapify:" << std::endl;
    studentHeap.print();

    studentHeap.add(Student("Eve", 95));

    std::cout << "\nHeap after adding Eve:" << std::endl;
    studentHeap.print();

    Student removedStudent = studentHeap.remove();
    std::cout << "\nRemoved Student: "<<removedStudent;
    removedStudent.print();

    std::cout << "\nHeap after removal:" << std::endl;
    studentHeap.print();

    return 0;
}
