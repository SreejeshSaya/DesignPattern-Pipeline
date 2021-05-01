#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "Buffer.hpp"
#include "ioperation.hpp"
#include <thread>   
#include <chrono>
#include <future>

template<typename T>
class Processor : public IOperation<T> {   
private:
    using IOperation<T>::Next;
    using IOperation<T>::Terminate;

    static void Sleep() {
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }

    Buffer<T> queue;

    void Run() {  //to do
        //Console.WriteLine($ "Thread {GetType().Name} Started !");
        //std::cout<<"Thread started!"<< std::endl; //incomplete

        while(true) {
            T data = queue.pop();
            auto operation = Process(data) ? Next : Terminate;
            if (operation != nullptr) {
                    operation->invoke(data);
            }
            Sleep(); 
        }
    }

    protected: 
    virtual bool Process(T& data) = 0;

public:
    Processor() {
        //thread t1([]() { Run(); }).detach();
        //std::thread t5(&foo::bar, &f); // t5 runs foo::bar() on object f
        std::thread t(&Processor::Run, this);   
        t.detach();
    }

    void invoke(T& data) {
        queue.push(data);
    }
};

#endif