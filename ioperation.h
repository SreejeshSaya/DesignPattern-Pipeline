#ifndef IOPERATION_H
#define IOPERATION_H

template <typename T>
class IOperation {
public:
	IOperation<T> next;
	IOperation<T> terminate;
	virtual void invoke(T) = 0;
};

#endif