#include <iostream>
#include "stemplate.h"
#include "stemplate.cpp"

int main() {
	Test<int> t(3);
	t.print();
	return 0;
}
