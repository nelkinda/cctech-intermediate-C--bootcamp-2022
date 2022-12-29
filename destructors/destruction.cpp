#include <iostream>

using namespace std;

class VirtualA {
public:
    VirtualA() {
        cout << "Created an instance of VirtualA." << endl;
    }
    virtual ~VirtualA() {
        cout << "Deleted an instance of VirtualA." <<  endl;
    }
};

class VirtualB: public VirtualA {
public:
    VirtualB() {
        cout << "Created an instance of VirtualB." << endl;
    }
    virtual ~VirtualB() {
        cout << "Deleted an instance of VirtualB." <<  endl;
    }
};

class VirtualC: public VirtualA {
public:
    VirtualC() {
        cout << "Created an instance of VirtualC." << endl;
    }
    virtual ~VirtualC() {
        cout << "Deleted an instance of VirtualC." <<  endl;
    }
};

class NonVirtualA {
public:
    NonVirtualA() {
        cout << "Created an instance of NonVirtualA." << endl;
    }
    ~NonVirtualA() {
        cout << "Deleted an instance of NonVirtualA." <<  endl;
    }
};

class NonVirtualB: public NonVirtualA {
public:
    NonVirtualB() {
        cout << "Created an instance of NonVirtualB." << endl;
    }
    ~NonVirtualB() {
        cout << "Deleted an instance of NonVirtualB." <<  endl;
    }
};

class NonVirtualC: public NonVirtualA {
public:
    NonVirtualC() {
        cout << "Created an instance of NonVirtualC." << endl;
    }
    ~NonVirtualC() {
        cout << "Deleted an instance of NonVirtualC." <<  endl;
    }
};

VirtualA *createSomeVirtualA() {
    return new VirtualB();
}

void virtualAandB() {
    VirtualA *a = createSomeVirtualA();
    delete a;
}

NonVirtualA *createSomeNonVirtualA() {
    return new NonVirtualC();
}

void nonVirtualAandB() {
    // More code
    {
        NonVirtualA *a = createSomeNonVirtualA();
        delete a;
        // More code, a is still in scope, a is a dangling pointer, access is undefined behavior.
        a = createSomeNonVirtualA();
        // More code, a is still in scope, and a is a new pointer, access is ok.
        delete a;
    }
    // More code, a is out of scope, no risk of accessing a dangling pointer.
}

int main() {
    cout << "Virtual A and B" << endl;
    virtualAandB();
    cout << endl;
    cout << "NonVirtual A and B" << endl;
    nonVirtualAandB();
}
