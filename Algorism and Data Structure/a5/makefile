TARGET = naive_recursive bottom_up closed_form matrix_representation

all: $(TARGET)

naive_recursive:
	g++ naive_recursive.cpp biginteger.h biginteger.cpp -o naive_recursive
	
bottom_up:
	g++ bottom_up.cpp biginteger.h biginteger.cpp -o bottom_up
	
closed_form:
	g++ closed_form.cpp -o closed_form
	
matrix_representation:
	g++ matrix_representation.cpp biginteger.h biginteger.cpp -o matrix_representation

clean:
	-rm $(TARGET)