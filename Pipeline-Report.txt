------------- INTRODUCTION -------------
Our project is about designing a payment processing system using the pipeline design pattern (and a
circuit breaker to terminate the pipeline). This payment processing system can get or update any 
balance without concern about concurrency issues. 

The basic idea of this pattern is much like the idea of an assembly line: To perform a sequence of
essentially identical calculations, each of which can be broken down into the same sequence of steps,
we set up a "pipeline", one stage for each step, with all stages potentially executing concurrently. 
Each of the sequence of calculations is performed by having the first stage of the pipeline perform 
the first step, and then the second stage the second step, and so on. As each stage completes a step 
of a calculation, it passes the calculation-in-progress to the next stage and begins work on the next
calculation.

The stages of our pipeline pattern are:
1) Creating an order
2) Price of the order
3) Payment Processing
4) Delivering the order
5) Report of the order

------------- OUR IMPLEMENTATION -------------
1) The pipeline executes a sequence of operations one by one. Each operation is written in a 
dedicated class. The interface of an operation is invoked to process the data.

2) The operations are registered in the pipeline before pipeline is invoked. The pipeline class also
implements the Operation interface so they can be combined.

3) Another feature of this project is a circuit breaker.Each operation will return the result : fail 
or success.If an operation fails, the order directly goes to the last stage and the order status 
becomes cancelled. 

4) The pipeline can deal with asynchronous operations.Every operation calls the next operation in the 
pipeline, after they are finished processing the data.

5) Each operation of the pipeline is run in a dedicated thread.Each thread will consume and produce 
data from a concurrent queue that will act as a buffer.

6) Each order processor is isolated in a dedicated thread, so you can optimize how you store the data
and have direct memory access without using a lock.The payment order processor is the only thread that 
can access user balances. It can get or update any balance without concern about concurrency issues.
The pipeline is processing the sequence of operations as fast as possible.

------------- RUNNING THE PROJECT -------------
The directory contains a makefile. So to test this project on a linux machine,
run the following commands in order.

1) make
2) ./Pipeline



