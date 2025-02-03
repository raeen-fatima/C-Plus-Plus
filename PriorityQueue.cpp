#include <iostream>
#include <cstdlib>  // For exit()
using namespace std;

#define MAX 5

void insert_by_priority(int);
void delete_by_priority(int);
void create();
void check(int);
void display_pqueue();

int pri_que[MAX];
int front, rear;

int main()
{
    int n, ch;

    cout << "\n 1- Insert an element into queue";
    cout << "\n 2- Delete an element into queue";
    cout << "\n 3- Display queue elements";
    cout << "\n 4- Exit";

    create();

    while (1) {
        cout << "\n Enter Your Choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\nEnter value to be inserted: ";
                cin >> n;
                insert_by_priority(n);
                break;

            case 2:
                cout << "\nEnter value to delete: ";
                cin >> n;
                delete_by_priority(n);
                break;

            case 3:
                display_pqueue();
                break;

            case 4:
                exit(0);

            default:
                cout << "\nInvalid Choice! Enter a correct option.";
        }
    }
}

// Function to create an empty priority queue
void create() {
    front = rear = -1;
}

// Function to insert an element into the priority queue
void insert_by_priority(int data) {
    if (rear >= MAX - 1) {
        cout << "\nQueue overflow! No more elements can be inserted.";
        return;
    }

    if ((front == -1) && (rear == -1)) {
        front = rear = 0;
        pri_que[rear] = data;
        return;
    }

    check(data);
    rear++;
}

// Function to check priority and place element
void check(int data) {
    int i, j;
    for (i = 0; i <= rear; i++) {
        if (data >= pri_que[i]) {
            for (j = rear + 1; j > i; j--) {
                pri_que[j] = pri_que[j - 1];
            }
            pri_que[i] = data;
            return;
        }
    }
    pri_que[i] = data;
}

// Function to delete an element from the queue
void delete_by_priority(int data) {
    int i, found = 0;
    if ((front == -1) && (rear == -1)) {
        cout << "\nQueue is empty! No elements to delete.";
        return;
    }

    for (i = 0; i <= rear; i++) {
        if (data == pri_que[i]) {
            found = 1;
            for (; i < rear; i++) {
                pri_que[i] = pri_que[i + 1];
            }
            rear--;
            if (rear == -1) front = -1;  // Reset queue if empty
            break;
        }
    }

    if (!found) {
        cout << "\nElement not found in queue!";
    }
}

// Function to display queue elements
void display_pqueue() {
    if ((front == -1) && (rear == -1)) {
        cout << "\nQueue is empty!";
        return;
    }

    cout << "\nPriority Queue Elements: ";
    for (int i = front; i <= rear; i++) {
        cout << pri_que[i] << " ";
    }
    cout << endl;
}
