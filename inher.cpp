#include <iostream>

template <int>
class IOperation {
public:
    IOperation<int>* Next;
    IOperation<int>* Terminate;
    virtual void invoke() = 0;
};

class Processor : public IOperation<int> {   
private:
    void Run() {  //to do
    //     //Console.WriteLine($ "Thread {GetType().Name} Started !");
    //     std::cout<<"Thread started!"<< std::endl; //incomplete

    //     while(true) {
    //         T data = queue.pop();
    //         auto operation = Process(data) ? Next : Terminate;
    //         operation->invoke(data);
    //         Sleep(); 
    //     }
        std::cout << Next << std::endl;
        std::cout << Terminate << std::endl;
    }

public:
    Processor() {}
    //IOperation<T> *Terminate;
    //IOperation<T> *Next;
    void invoke() {
        std::cout << Next << std::endl;
        std::cout << Terminate << std::endl;
        Run();
    }
    /*void IOperation<T>.invoke(T data) {
        queue.push(data);
    }*/

};

int main() {
    Processor *p = new Processor();
    p->invoke();
}