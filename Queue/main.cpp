#include <iostream>
#include <vector>
#include <stack>

using namespace std;


// Class definition for Queue
class Queue {
public:
    // Constructor to initialize the queue with a specific capacity
    Queue(int qsize);
    
    // Destructor to clean up resources (if any)
    ~Queue();

    // Adds an element to the end of the queue
    void enqueue(int x);

    // Removes the front element from the queue
    void dequeue();

    // Returns the front element of the queue
    int getFront();

    // Displays all elements in the queue
    void display();


    // Checks if the queue is empty
    bool isEmpty();


private:
    vector<int> arr; // Internal storage for the queue
    int size;        // Current number of elements in the queue
    int capacity;    // Maximum capacity of the queue
    int front;       // Index of the front element
};

// Constructor implementation
Queue::Queue(int qsize) {
    size = 0;              // Initialize size to 0
    front = 0;             // Initialize front to 0
    capacity = qsize;      // Set the capacity of the queue
    arr.resize(qsize);     // Allocate space for the queue
}

// Destructor implementation
Queue::~Queue() {
    // Since we're using a vector, no manual memory management is needed.
    // However, we can clear the vector to free up the memory explicitly, although this is not required.
    arr.clear();  // Clear the vector to deallocate memory
}

// Function to add an element to the end of the queue
void Queue::enqueue(int x) {
    if (size == capacity) { // Check if the queue is full
        return;             // Do nothing if full
    }
    arr[size] = x;          // Add the element at the next available position
    size++;                 // Increment the size of the queue
}

// Function to remove the front element from the queue
void Queue::dequeue() {
    if (size == 0) {        // Check if the queue is empty
        return;             // Do nothing if empty
    }
    // Shift all elements to the left to maintain the queue order
    for (int i = 1; i < size; i++) {
        arr[i - 1] = arr[i];
    }
    size--;                 //Decrement the size of the queue...
}

// Function to get the front element of the queue
int Queue::getFront() {
    if (size == 0) {        // Check if the queue is empty
        return -1;          // Return -1 to indicate an empty queue
    }
    return arr[front];      // Return the front element
}

// Function to display all elements in the queue
void Queue::display() {
    for (int i = front; i < size; i++) { // Iterate through the queue
        cout << arr[i] << " ";           // Print each element
    }
    cout << endl;                        // Print a newline at the end
}
bool Queue::isEmpty(){
    return size == 0;
}

//reversing the queue using stack
void reverse(Queue *Q);


int main() {
    // Create a queue with a capacity of 4
    Queue* q = new Queue(4);

    q->enqueue(3);          // Add element 3 to the queue
    q->enqueue(2);          // Add element 2 to the queue
    q->enqueue(1);          // Add element 1 to the queue

    cout << q->getFront() << endl; // Display the front element of the queue

    q->dequeue();           // Remove the front element
    q->enqueue(0);          // Add element 0 to the queue

   
    cout << "Original Queue: ";
    q->display();           // Display the queue

    reverse(q);             // Reverse the queue using a stack

    cout << "Reversed Queue: ";
    q->display();           // Display the reversed queue

    delete q;               // Delete the dynamically allocated queue object
    return 0;               // Exit the program
}


void reverse(Queue *Q) {
    stack<int> s;

    // Run while Q is not empty
    while (!Q->isEmpty()) {
        // Dequeue an item from Q and push the dequeued item to stack s
        s.push(Q->getFront());
        Q->dequeue();
    }

    // Run while stack s is not empty
    while (!s.empty()) {
        // Pop an item from stack s and enqueue the popped item to Q
        Q->enqueue(s.top());
        s.pop();
    }
}
