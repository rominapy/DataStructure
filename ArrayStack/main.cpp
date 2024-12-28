
#include <iostream>
#include <stdexcept> // For standard exception classes
using namespace std;

template <typename T>
class ArrayStack {
    enum { DEF_CAP = 100 }; // Default capacity
public:
    ArrayStack(int cap = DEF_CAP); // Constructor
    ~ArrayStack();                // Destructor
    int size() const;             // Number of items in the stack
    bool empty() const;           // Is the stack empty?
    const T& top() const;         // Get the top element
    void push(const T& t);        // Push an element onto the stack
    T pop();                      // Pop the top element and return it

private:
    T* Array;        // Array of stack elements
    int capacity;    // Stack capacity
    int t;           // Index of the top stack element
};

// Constructor
template <typename T>
ArrayStack<T>::ArrayStack(int cap) : Array(new T[cap]), capacity(cap), t(-1) {}

// Destructor
template <typename T>
ArrayStack<T>::~ArrayStack() {
    delete[] Array;
}

// Returns the number of elements in the stack
template <typename T>
int ArrayStack<T>::size() const {
    return t + 1;
}

// Checks if the stack is empty
template <typename T>
bool ArrayStack<T>::empty() const {
    return t == -1;
}

// Returns the top element of the stack
template <typename T>
const T& ArrayStack<T>::top() const {
    if (empty()) {
        throw runtime_error("Stack is empty");
    }
    return Array[t];
}

// Pushes an element onto the stack
template <typename T>
void ArrayStack<T>::push(const T& item) {
    if (size() == capacity) {
        throw runtime_error("Stack is full");
    }
    Array[++t] = item;
}

// Pops the top element from the stack and returns it
template <typename T>
T ArrayStack<T>::pop() {
    if (empty()) {
        throw runtime_error("Stack is empty");
    }
    return Array[t--];
}

// Main function to test the ArrayStack
int main() {
    try {
        ArrayStack<int> A;   // A=[], size=0

        A.push(7);           // A=[7*], size=1
        A.push(13);          // A=[7, 13*], size=2

        cout << A.pop() << endl; // A=[7*], size=1, prints 13

        cout << A.top() << endl; // Prints 7
        A.pop();                // A=[], size=0
        cout << A.empty() << endl; // Prints 1 (true)
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
