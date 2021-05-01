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
    std::thread t_;
    using IOperation<T>::Next;
    using IOperation<T>::Terminate;
    std::atomic_bool stopLoop;

    static void Sleep() {
        std::this_thread::sleep_for(std::chrono::seconds(3));
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
        t_(&Processor::Run, this), stopLoop(false)
    {}

    void invoke(T& data) { queue.push(data); }
    void terminate() {
        stopLoop = true;
        Order tmp(0, 0, 0);
        invoke(tmp);
        t_.join();
    }
};

#endif