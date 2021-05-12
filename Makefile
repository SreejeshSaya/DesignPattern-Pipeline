CC=g++

Pipeline: PipelinePattern.o order.o user.o product.o
	$(CC) -o Pipeline -pthread PipelinePattern.o order.o user.o product.o

PipelinePattern.o: product.hpp order.hpp user.hpp pipeline.hpp\
	CreateOrderProcessor.hpp PriceOrderProcessor.hpp\
	PaymentOrderProcessor.hpp DeliverOrderProcessor.hpp\
	ReportOrderProcessor.hpp Processor.hpp
	$(CC) -c -mrdrnd PipelinePattern.cpp

order.o: order.cpp order.hpp product.hpp
	$(CC) -c order.cpp

user.o: user.cpp user.hpp
	$(CC) -c user.cpp

product.o: product.cpp product.hpp
	$(CC) -c product.cpp

clean:
	rm *.o Pipeline

