#include <iostream>
// void someFcn(int i)
// {
// }

// class Demo {

// };


// int main()
// {
//     // int i {9.5}; //brace initialization prevents type narrowing
//     double d{ 5.0 };

//     someFcn(d); // bad: implicit narrowing conversion will generate compiler warning

//     // good: we're explicitly telling the compiler this narrowing conversion is intentional
//     someFcn(static_cast<int>(d)); // no warning generated
    
//     Demo dd = Demo();
//     return 0;
// }

class A {
    int val;
public:
    A(int v) : val(v) {}
    int get_val () const {return val;}

    // Friend function: declared inside but is a non-member function


    // std::ostream& operator<<(std::ostream& os);
    // std::ostream& operator<< (std::ostream& os) {
    //     os<<val<<"\n";
    //     return os;
    // }
};

// Definition of the friend function outside the class:
// std::ostream& A:: operator<<(std::ostream& os) {
//     os << val;
//     return os;
// }

//Third way
std::ostream& operator<<(std::ostream& os, const A& obj) {
    os<<obj.get_val();
    return os;
}

int main () {
    A obj(5);
    std::cout<<obj;
    // obj<<std::cout;

    return 0;
}