#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "Buffer.hpp"
#include "ioperation.hpp"
#include <thread>   
#include <chrono>
#include <future>
#include <cstdlib>
#include <immintrin.h>

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
        // std::this_thread::sleep_for(std::chrono::milliseconds(s*s));
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
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
    virtual bool Process(T&) = 0; 
    static std::mutex mtx;

public:
    Processor():
        _t(&Processor::Run, this), stopLoop(false)
    {
        _t.detach();
    }

    void invoke(T& data) { queue.push(data); }
    void terminate() {
        stopLoop = true;
        Order tmp(0, 0, 0, 0);
        invoke(tmp);
        _t.join();
    }
};

template <typename T>
std::mutex Processor<T>::mtx;
#endif