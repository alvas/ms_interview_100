#CFLAGS=-DMAIN

exec1: 
	g++ exec1.cpp

exec2:
	g++ exec2.cpp

RandomArray.o:
	g++ -c RandomArray.cpp

QuickSort.o: RandomArray.o
	g++ $(CFLAGS) -c QuickSort.cpp

QuickSort: QuickSort.o RandomArray.o
	g++ $(CFLAGS) QuickSort.o RandomArray.o

exec3:
	g++ exec3.cpp

exec4:
	g++ exec4.cpp

exec5:
	g++ exec5.cpp

HeapSort:
	g++ HeapSort.cpp

InsertionSort.o: RandomArray.o
	g++ $(CFLAGS) -c InsertionSort.cpp RandomArray.o

InsertionSort: RandomArray.o
	g++ $(CFLAGS) InsertionSort.cpp RandomArray.o

Select: QuickSort.o RandomArray.o InsertionSort.o
	g++ $(CFLAGS) Select.cpp QuickSort.o RandomArray.o InsertionSort.o

clean:
	rm a.out *.o
