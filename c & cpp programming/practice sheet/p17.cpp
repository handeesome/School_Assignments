#include <iostream>
using namespace std;
class Book {
    public:
        const char* title;
        int pages;
       // Book(const Book&);
        Book(const char* t, int p);
        Book();
// ...
// setter and getter methods omitted
};

/*Book::Book(const Book&a){
    this->title = a.title;
    this->pages = a.pages;
}*/

Book::Book(const char* t, int p){
    this->title = t;
    this->pages = p;
}


int main(){
    Book a("one", 100);
    Book b = a;
    Book c(a);    a.title = "two";

    cout << a.title << endl;
    cout << b.title << endl;
    cout << c.title << endl;
}
