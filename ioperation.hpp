#ifndef IOPERATION_H
#define IOPERATION_H

template <typename T>
class IOperation {
public:
	virtual void invoke(T) = 0;
};

#endif