#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "Buffer.hpp"
#include "ioperation.hpp"
#include <thread>   
#include <chrono>
#include <future>
#include <cstdlib>

template<typename T>
class Processor : public IOperation<T> {   
private:
    std::thread _t;
    using IOperation<T>::Next;
    using IOperation<T>::Terminate;
    std::atomic_bool stopLoop;

    static void Sleep() {
        unsigned short s;
        _rdrand16_step(&s);
        s = (s % 50) + 1;
        //std::cout << "Sleep : " << s << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(s*s));
    }

    Buffer<T> queue;

    void Run() {
        while(!stopLoop) {
            T data = queue.pop();
            if (stopLoop)
                break;
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
    Processor():
        _t(&Processor::Run, this), stopLoop(false)
    {}

    void invoke(T& data) { queue.push(data); }
    void terminate() {
        stopLoop = true;
        Order tmp(0, 0, 0);
        invoke(tmp);
        _t.join();
    }
};

#endif