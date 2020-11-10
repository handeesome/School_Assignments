TARGET =  array_search testLinkedList testStack vector vector2


all: $(TARGET)


array_search:
	g++ array_search.cpp -o array_search
	
testLinkedList:
	g++ LinkedList.h testLinkedList.cpp -o testLinkedList
	
testStack:
	g++ Stack.h testStack.cpp -o testStack
	
vector:
	g++ vector.cpp -o vector
	
vector2:
	g++ vector2.cpp -o vector2
	
clean:
	rm -f $(TARGET)
