#include <iostream>
#include <vector>
using namespace std;

class Queue{
public:
Queue(int qize);
~Queue(){};
void enqueue(int x);
void dequeue();
int getFront();
void display();

private:
    vector<int> arr;
    int size;
    int capacity;
    int front;
};

Queue:: Queue(int qsize)
{
     size = 0;
     front = 0;
    capacity = qsize;
    arr.resize(qsize);
}

//Function to add an element to the end of the queue

void Queue:: enqueue(int x){
          // If queue is full
        if (size == capacity) {
            return;
        }

        arr[size] = x;

        // Increment queue size.
        size++;
}
void Queue:: dequeue(){

        // If queue is empty
        if (size == 0) {
            return;
        }

        // Shift all the elements  to the left.
        for (int i = 1; i < size; i++) {
            arr[i - 1] = arr[i];
        }

        // decrement queue size
        size--;
}
int Queue:: getFront(){

       // If queue is empty
        if (size == 0)
            return -1;

        return arr[front];
}
void Queue:: display(){

    for (int i = front; i < size; i++)
     {
            cout << arr[i] << " ";
    }
        cout << endl;
}

int main() {
  
    Queue *q = new Queue(4);

    q->enqueue(3);
    q->enqueue(2);
    q->enqueue(1);
    cout << q->getFront() << endl;
    q->dequeue();
    q->enqueue(0);
    q->display();

    return 0;
}