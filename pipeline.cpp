#include "pipeline.hpp"
#include "ioperation.hpp"
#include "order.hpp"

template class Pipeline<Order>;

template <typename T>
Pipeline<T>::Pipeline(){

}

template <typename T>
void Pipeline<T>::registerOperation(IOperation<T>* operation) {
	operation->Next = success;
	operation->Terminate = fail;
	if (!operations.empty()) {
		operations.back()->Next = operation;
	}
	operations.push_back(operation);
}

template <typename T>
void Pipeline<T>::invoke(T& data) {
	std::cout << "IN PIPELINE::INVOKE\n";
	IOperation<Order> *op = (!operations.empty()) ? operations.front() : fail;
	op->invoke(data);
}

template <typename T>
bool Pipeline<T>::Success(T& data) {
	Continue(data);
	return true;
}

template <typename T> bool Pipeline<T>::Fail(T& data) {
	Continue(data);
	return false;
}

template <typename T>
void Pipeline<T>::Continue(T& data) {
	if (Next != nullptr) {
		Next->invoke(data);
	}
}