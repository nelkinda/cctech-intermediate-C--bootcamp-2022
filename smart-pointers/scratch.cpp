#include <iostream>
#include <memory>
#include <cstdio>

using namespace std;

class A {
public:
    A() {
        cout << "Created an instance of A." << endl;
    }
    virtual ~A() {
        cout << "Deleted an instance of A." <<  endl;
    }
};

class B: public A {
public:
    B() {
        cout << "Created an instance of B." << endl;
    }
    virtual ~B() {
        cout << "Deleted an instance of B." <<  endl;
    }
};

void explicitNewDelete() {
    // In good C++ code, you basically don't see this type of code anymore.
    A *a = new B(); // struct A *a = (struct B *) malloc(sizeof(struct B));
    A *a2 = a;
    printf("%p %p\n", a, a2);
    delete a;       // free(a);
    printf("%p %p\n", a, a2); // a and a2 are now dangling pointers
}

void withUniquePtr() {
    unique_ptr<A> a(new B());
    // Now a goes out of scope, a is deleted, and because a is a smart pointer, it will also delete new B();
}

void withSharedPtr() {
    shared_ptr<A> a(new B());
    shared_ptr<A> a2 = a;
    // Now a2 goes out of scope, the destructor of shared_ptr drops the reference counter from 2 to 1.
    // Then a goes out of scope, the destructor of shared_ptr drops the reference counter from 1 to 0 and calls delete new B();
}

void withWeakPtr() {
    shared_ptr<A> a(new B());
    weak_ptr<A> a2(a); // Weak ptrs do not increase the reference counter.
    if (a2.expired()) {
        cout << "Object gone." << endl;
    } else {
        cout << "Object still exists." << endl;
    }
}

int main() {
    //list<string> lines;
    explicitNewDelete();
    withUniquePtr();
    withSharedPtr();
    withWeakPtr();
}
