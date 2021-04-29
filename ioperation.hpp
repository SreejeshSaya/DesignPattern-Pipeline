#ifndef IOPERATION_H
#define IOPERATION_H

template <typename T>
class IOperation {
public:
	IOperation<T>* Next;
	IOperation<T>* Terminate;
	virtual void invoke(T&) = 0;
};

#endif