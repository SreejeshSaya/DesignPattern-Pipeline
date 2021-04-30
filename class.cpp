
//#include <iostream>
//#include <functional>
//
//using namespace std::placeholders;
//
//class aClass {
//public:
//    void aTest(int a, int b) {
//        printf("%d + %d = %d", a, b, a + b);
//    }
//};
//
//class bClass {
//public:
//    void function1(std::function<void(int, int)> fun) {
//        fun(1, 1);
//    }
//};
//
//int main(int argc, const char* argv[]) {
//    aClass a;
//    bClass b;
//    auto fp = std::bind(&aClass::aTest, a, _1, _2);
//    b.function1(fp);
//
//    return 0;
//}

#include <iostream>
#include "ioperation.hpp"
#include "a.cpp"
//class B : public A {
//public:
//	int b;
//	B() :b(10) {}
//};

class C: public IOperation<int> {
public:
	void invoke(int &a) {
		std::cout << Next << std::endl;
		std::cout << Terminate << std::endl;
	}
};

// class C : public A {
// public:
// 	int c;
// 	// A* a;
// 	C() : c(15) {}
// 	void print() {
// 		std::cout << c << std::endl;
// 		std::cout << a << std::endl;
// 	}
// };

// void func(A& p) {
// 	p.a = new A();
// }

// void func2(C& p) {
// 	p.a = new A();
// }

int main() {
	//B b;
	//b.a = new A();
	C c;
	//c.a = new A();
	//std::cout << b.a << std::endl;
	//std::cout << c.a << std::endl;
	int a = 5;
	c.invoke(a);
	// func(c);
	// c.print();
	// func2(c);
	// c.print();

}