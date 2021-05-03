#include "pipeline.hpp"
#include "ioperation.hpp"
#include "order.hpp"

template class Pipeline<Order>;

template <typename T>
Pipeline<T>::Pipeline(){

}

template <typename T>
void Pipeline<T>::registerOperation(IOperation<T>* operation) {
	if (!operations.empty()) {
		operations.back()->Next = operation;
	}
	operations.push_back(operation);
}

template <typename T>
void Pipeline<T>::invoke(T& data) {

	for (auto operation : operations){
		operation->Terminate = operations.back();
	}
	operations.back()->Terminate = nullptr;
	IOperation<Order> *op = (!operations.empty()) ? operations.front() : nullptr;
	if (op == nullptr)
		std::cout << "PIPELINE EMPTY!" << std::endl;
	op->invoke(data);
}

template <typename T>
void Pipeline<T>::terminate() {
	for (IOperation<T> *operation : operations) {
		operation->terminate();
	}
}