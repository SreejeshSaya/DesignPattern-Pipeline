#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "Buffer.hpp"
#include "ioperation.hpp"
#include <thread>   
#include <chrono>
#include <future>

template<typename T>
class Processor : public IOperation<T>
{   
    private:
    static void Sleep()
    {
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }

    Buffer<T> queue;

    void Run() //to do
    {
        //Console.WriteLine($ "Thread {GetType().Name} Started !");
        std::cout<<"Thread {   } started!"<<endl; //incomplete

        while (true)
        {
            T data = queue.pop();
            auto operation = Process(data) ? Next : Terminate;
            operation.Invoke(data);
            Sleep(); 
        }
    }

    protected: 
    virtual bool Process(T data) = 0;

    Processor()
    {
        thread([]() { Run(); }).detach();
    }

    public:
        IOperation<T> Terminate;
        IOperation<T> Next;
        void IOperation<T>.Invoke(T data)
        {
            queue.push(data);
        }

};

#endif