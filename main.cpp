//
// Created by Arvinderjeet singh on 5/3/2024.
//
#include<iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>


using namespace std;

void main_menu();

void sub_menu_linear();

void sub_menu_non_linear();

void sub_menu_algorithm();

void sub_menu_searching_algorithm();

void sub_menu_sorting_algorithm();

//classes
class Search {
    vector<int> array;
public:
    int size;

    Search() {
        size = 0;
    }

    void sort_array() {
        for (int i = 0; i < array.size(); i++) {
            for (int j = i + 1; j < array.size(); j++) {
                if (array[i] > array[j]) {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
    }

    void print() {
        cout << "[ ";
        for (int i = 0; i < array.size(); i++) {
            cout << array[i] << " ";
        }
        cout << "]" << endl;
    }

    void insert() {
        int elem;
        cout << "Enter size of array: ";
        cin >> size;
        for (int i = 0; i < size; i++) {
            cout << "Enter element: ";
            cin >> elem;
            array.push_back(elem);
        }
        this->print();
        cout << "sorting array ..." << endl;
        this->sort_array();
        this->print();
    }

    int linearSearch(int key) {

        for (int i = 0; i < array.size(); ++i) {
            if (array[i] == key) {
                return i;
            }
        }
        return -1;
    }

    int binarySearch(int left, int right, int key) {
        if (left > right) {
            cout << "Element not found" << endl;
            return -1;
        }
        int mid = left + (right - left) / 2;
        if (array[mid] == key) {
            return mid;
        }
        if (array[mid] < key) {
            return binarySearch(mid + 1, right, key);
        } else {
            return binarySearch(left, mid - 1, key);
        }
    }

};

class Sorting {
private:
    int *arr;
    int size;
    void merge(int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        int L[n1], R[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];

        int i = 0, j = 0, k = l;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort(int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(l, m);
            mergeSort(m + 1, r);
            merge(l, m, r);
        }
    }

    int partition(int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    void quickSort(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    int getMax() {
        int mx = arr[0];
        for (int i = 1; i < size; i++)
            if (arr[i] > mx)
                mx = arr[i];
        return mx;
    }

    void countSort(int exp) {
        int output[size];
        int count[10] = {0};

        for (int i = 0; i < size; i++)
            count[(arr[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = size - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < size; i++)
            arr[i] = output[i];
    }

    void radixSort() {
        int m = getMax();

        for (int exp = 1; m / exp > 0; exp *= 10)
            countSort(exp);
    }

    void selectionSort() {
        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < size; j++)
                if (arr[j] < arr[minIndex])
                    minIndex = j;
            if (minIndex != i)
                swap(arr[i], arr[minIndex]);
        }
    }

    void bubbleSort() {
        for (int i = 0; i < size - 1; i++)
            for (int j = 0; j < size - i - 1; j++)
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
    }

    void insertionSort() {
        for (int i = 1; i < size; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

public:
    Sorting() {
        arr = nullptr;
        size = 0;
    }

    void takeInput() {
        cout << "Enter the size of the array: ";
        cin >> size;

        if (size <= 0) {
            cout << "Invalid size!";
            return;
        }

        arr = new int[size];

        cout << "Enter the elements of the array:\n";
        for (int i = 0; i < size; ++i)
            cin >> arr[i];
    }

    void display() {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }

        cout << "Array elements: ";
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }

    void sortMenu() {
        int choice;
        do {
            cout << "\n--- Sorting Menu ---\n";
            cout << "1. Merge Sort\n";
            cout << "2. Quick Sort\n";
            cout << "3. Radix Sort\n";
            cout << "4. Selection Sort\n";
            cout << "5. Bubble Sort\n";
            cout << "6. Insertion Sort\n";
            cout << "7. back to menu\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    mergeSort(0, size - 1);
                    display();
                    cout << "Array sorted using Merge Sort.\n";
                    break;
                case 2:
                    quickSort(0, size - 1);
                    display();
                    cout << "Array sorted using Quick Sort.\n";
                    break;
                case 3:
                    radixSort();
                    display();
                    cout << "Array sorted using Radix Sort.\n";
                    break;
                case 4:
                    selectionSort();
                    display();
                    cout << "Array sorted using Selection Sort.\n";
                    break;
                case 5:
                    bubbleSort();
                    display();
                    cout << "Array sorted using Bubble Sort.\n";
                    break;
                case 6:
                    insertionSort();
                    display();
                    cout << "Array sorted using Insertion Sort.\n";
                    break;
                case 0:
                    exit(0);
                default:
                    cout << "Invalid choice!\n";
            }
        } while (choice != 7);
        sub_menu_algorithm();
    }

    ~Sorting() {
        delete[] arr;
    }
};


class ArrayOps {
private:
    int size;
    int current_position;
    int *arr;

public:
    ArrayOps(int size) {
        this->size = size;
        this->arr = new int[this->size];
        this->current_position = 0;
        cout << "Array is created" << endl;
        for (int i = 0; i < size; ++i) {
            arr[i] = 0;
        }
    }

    void del_old_array() {
        delete[]arr;
        cout << "old Array is deleted" << endl;
    }

    void display_array() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void append_array(int val) {
        if (current_position == size) {
            cout << "Cannot append more elements" << endl;
            return;
        }
        arr[current_position] = val;
        current_position++;
        cout << val << " is appended" << endl;
        cout << "\n current position is ";
        cout << current_position + 1 << endl;
    }

    void append_at_position(int pos, int val) {
        arr[pos - 1] = val;
    }

    void deletion(int pos) {
        for (int i = pos - 1; i < size; i++) {
            arr[i] = arr[i + 1];
        }
        current_position--;
    }

    void reverse_array() {
        for (int i = 0; i < size / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[size - i - 1];
            arr[size - i - 1] = temp;
        }
    }

    static void sort(int array_ro_sort[], int size_array) {
        for (int i = 0; i < size_array - 1; ++i) {
            for (int j = 0; j < size_array - i - 1; ++j) {
                if (array_ro_sort[j] > array_ro_sort[j + 1]) {
                    int temp = array_ro_sort[j];
                    array_ro_sort[j] = array_ro_sort[j + 1];
                    array_ro_sort[j + 1] = temp;
                }
            }
        }
        cout << "sorted array is " << endl;
        for (int i = 0; i < size_array; ++i) {
            cout << array_ro_sort[i] << " ";
        }
        cout << endl;
    }

    void merge_array() {
        int *temp;
        temp = new int[size];
        for (int i = 0; i < size; ++i) {
            temp[i] = arr[i];
        }
        cout << "enter size of array 2" << endl;
        int size2;
        cin >> size2;
        int *arr2 = new int[size2];
        for (int i = 0; i < size2; ++i) {
            cout << "enter element " << i + 1 << endl;
            cin >> arr2[i];
        }
        int merged_arr[this->size + size2];
        sort(temp, size);
        sort(arr2, size2);

        int i = 0, j = 0, k = 0;
        while (i < this->size && j < size2) {
            if (this->arr[i] <= arr2[j]) {
                merged_arr[k++] = this->arr[i++];
            } else {
                merged_arr[k++] = arr2[j++];
            }
        }
        while (i < this->size) {
            merged_arr[k++] = this->arr[i++];
        }
        while (j < size2) {
            merged_arr[k++] = arr2[j++];
        }

        cout << "merged array is " << endl;
        for (int l = 0; l < this->size + size2; ++l) {
            cout << merged_arr[l] << " ";
        }
        cout << endl;
        delete[]arr2;
        delete[]temp;
    }
};

void create_array();

void menu_array(ArrayOps array) {
    int choice;
    int val = 0;
    int pos = 0;
    do {
        cout << "\nenter choice :" << endl;
        cout << "1. append" << endl;
        cout << "2. append at position" << endl;
        cout << "3. deletion" << endl;
        cout << "4. reverse array" << endl;
        cout << "5. merge another array with current array" << endl;
        cout << "6. create new array" << endl;
        cout << "7. back to menu" << endl;
        cout << "0. exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "enter value to append" << endl;
                cin >> val;
                array.append_array(val);
                array.display_array();
                break;
            case 2:
                cout << "enter value to append" << endl;
                cin >> val;
                cout << "enter position to append" << endl;
                cin >> pos;
                array.append_at_position(pos, val);
                array.display_array();
                break;
            case 3:
                cout << "enter position to delete" << endl;
                cin >> pos;
                array.deletion(pos);
                array.display_array();
                break;
            case 4:
                array.reverse_array();
                array.display_array();
                break;
            case 5:
                array.merge_array();
                array.display_array();
                break;
            case 6:
                break;
            case 7:
                sub_menu_linear();
                break;
            case 0:
                cout << "exiting" << endl;
                exit(0);
            default:
                cout << "invalid choice" << endl;
                break;
        }
    } while (choice != 6);
    array.del_old_array();
    create_array();
}

void create_array() {
    cout << "enter size of array" << endl;
    int size;
    cin >> size;
    ArrayOps array(size);
    menu_array(array);
}

class LinkedList {
private:
    struct Node {
        int data;
        Node *next;
    };
    Node *head;
    Node *current_node;
    int count;

public:
    LinkedList() {
        head = new Node;
        head->next = nullptr;
        current_node = head;
        count = 1;
    }

    void insert(int value) {
        if (count == 1) {
            head->data = value;
            head->next = new Node;
            current_node = head->next;
            current_node->next = nullptr;
            count++;
            return;
        }

        current_node->next = new Node;
        current_node->data = value;
        current_node = current_node->next;
        current_node->next = nullptr;
        count++;
    }

    void display() {
        if (count == 1) {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        cout << "List: ";
        while (temp->next != nullptr) {
            cout << temp->data << " >> ";
            temp = temp->next;
        }
        cout << "NULL " << endl;

    }

    void insert_at_position(int value, int position) {
        int current_position = 1;
        Node *temp = head;
        while (temp != nullptr) {
            if (current_position == position - 1) {
                Node *new_node = new Node;
                new_node->data = value;
                new_node->next = temp->next;
                temp->next = new_node;
                count++;
                break;
            }
            current_position++;
            temp = temp->next;
        }
    }

    void delete_at_position(int position) {
        if (position == 1) {
            Node *temp = head;
            head = head->next;
            delete (temp);
        } else {
            Node *currentNode = head;
            Node *previousNode = head;
            int i = 1;
            while (i < position) {
                previousNode = currentNode;
                currentNode = currentNode->next;
                i++;
            }
            previousNode->next = currentNode->next;
            count--;
            cout << "Node deleted with value " << currentNode->data << " at position " << position << "" << endl;
            delete (currentNode);
        }
    }

    int get_count() const {
        return count;
    }
};

void create_link_list() {
    LinkedList list;
    int value;
    int position;
    int choice;
    do {
        cout << ">> 1.Insert" << endl;
        cout << ">> 2.Display" << endl;
        cout << ">> 3.Count" << endl;
        cout << ">> 4.Insert at position" << endl;
        cout << ">> 5.Delete at position" << endl;
        cout << ">> 6.back to menu" << endl;
        cout << ">> 0.Exit" << endl;
        cout << "\t Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the value to insert:\n";
                cin >> value;
                list.insert(value);
                list.display();
                break;
            case 2:
                list.display();
                break;
            case 3:
                cout << "Number of nodes: " << list.get_count() << endl;
                break;
            case 4:
                cout << "Enter the value to insert: ";
                cin >> value;
                cout << "Enter the position to insert: ";
                cin >> position;
                list.insert_at_position(value, position);
                list.display();
                break;
            case 5:
                cout << "Enter the position to delete: ";
                cin >> position;
                list.delete_at_position(position);
                list.display();
                break;
            case 6:
                sub_menu_linear();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 0);
}

class Stack_menu {
public:
    Stack_menu() = default;

    void selection_menu() {
        cout << ">>1.stack from array" << endl;
        cout << ">>2.stack from link list" << endl;
        cout << ">>0.exit" << endl;
    }

    void menu() {
        cout << "\n||MENU||" << endl;
        cout << "  >>1.Push" << endl;
        cout << "  >>2.Pop" << endl;
        cout << "  >>3.Empty" << endl;
        cout << "  >>4.Full" << endl;
        cout << "  >>5.Peek" << endl;
        cout << "  >>6.Display" << endl;
        cout << "  >>7.back to menu" << endl;
        cout << "  >>0.exit" << endl;
        cout << ">>Choose an option" << endl;
    }
};

void main_menu_stack();

class Stack_from_array : public Stack_menu {
    int top;
    int size;
    int *arr;
    int menu_choice;
    int value;
public:
    Stack_from_array() = default;

    Stack_from_array(int s) {
        top = -1;
        size = s;
        menu_choice = 0;
        value = 0;
        arr = new int[s];
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == size - 1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack is full" << endl;
        } else {
            top++;
            arr[top] = val;
            cout << "Value pushed " << value << " to the stack" << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            top--;
        }
    }

    void peek() const {
        if (!isEmpty()) {
            cout << "Top element is " << arr[top] << endl;
        } else {
            cout << "Stack is empty" << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack elements are: " << endl;
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " >> ";
            }
            cout << "NULL " << endl;
        }
        cout << endl;
    }

    void operations_array() {
        int goto_choice = 0;
        do {
            menu();
            cout << "Enter your choice" << endl;
            cin >> menu_choice;
            switch (menu_choice) {
                case 1:
                    cout << "Enter the value to push: " << endl;
                    cin >> value;
                    push(value);
                    display();
                    break;
                case 2:
                    pop();
                    display();
                    break;
                case 3:
                    if (isEmpty()) { cout << "Stack is empty" << endl; }
                    else { cout << "Stack is not empty" << endl; }
                    break;
                case 4:
                    if (isFull()) { cout << "Stack is full" << endl; }
                    else { cout << "Stack is not full" << endl; }
                    break;
                case 5:
                    peek();
                    display();
                    break;
                case 6:
                    display();
                    break;
                case 0:
                    cout << "Exiting the program" << endl;
                    exit(0);
                default:
                    cout << "Invalid choice" << endl;
            }
        } while (menu_choice != 7);
        char choice_to_delete;
        cout << "delete current stack(y/n): " << endl;
        cin >> choice_to_delete;
        if (choice_to_delete == 'y') {
            delete[]arr;
        }
        cout << "Back to main menu" << endl;
        main_menu_stack();
    }
};

class Stack_from_link_list : public Stack_menu {
private:
    struct Node {
        int data;
        Node *next;
    };
    Node *head;
    Node *current_node;
    int menu_choice;
    int value;
public:
    Stack_from_link_list() {
        head = new Node;
        head->next = nullptr;
        current_node = head;
        menu_choice = 0;
        value = 0;
    };

    void push(int val) {
        current_node->data = val;
        current_node->next = new Node;
        current_node = current_node->next;
        current_node->next = nullptr;
        cout << "Value pushed " << value << " to the stack" << endl;
    }

    bool isEmpty() const {
        return head->next == nullptr;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *temp;
        temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        current_node = temp;
        cout << "Value popped" << endl;
    }

    void peek() {
        if (!isEmpty()) {
            cout << "Top element is ";
            Node *temp;
            temp = head->next;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            cout << "Top element is " << temp->data << endl;
        } else {
            cout << "Stack is empty" << endl;
        }

    }

    void display() {
        if (head == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr) {
            cout << temp->data << " >> ";
            temp = temp->next;
        }
        cout << "NULL " << endl;
    }

    void operations_link_list() {
        int goto_choice = 0;
        do {
            menu();
            cout << "Enter your choice" << endl;
            cin >> menu_choice;
            switch (menu_choice) {
                case 1:
                    cout << "Enter value to push to the stack: " << endl;
                    cin >> value;
                    push(value);
                    display();
                    break;
                case 2:
                    pop();
                    display();
                    break;
                case 3:
                    if (isEmpty()) {
                        cout << "Stack is empty" << endl;
                    } else {
                        cout << "Stack is not empty" << endl;
                    }
                case 4:
                    cout << "Stack is not full" << endl;
                    break;
                case 5:
                    peek();
                    display();
                    break;
                case 6:
                    display();
                    break;
                case 7:
                    goto_choice = 7;
                    break;
                case 0:
                    exit(0);
                    break;
                default:
                    cout << "Invalid choice" << endl;
            }
        } while (menu_choice != 7);
        char choice_to_delete;
        cout << "delete current stack(y/n): " << endl;
        cin >> choice_to_delete;
        if (choice_to_delete == 'y') {
            Node *temp = head;
            while (temp != nullptr) {
                Node *next_node = temp->next;
                delete temp;
                temp = next_node;
            }
            head = nullptr;
        }
        cout << "Back to main menu" << endl;
        main_menu_stack();
    }
};

void create_stack_from_array(int size) {
    Stack_from_array stack_from_array(size);
    stack_from_array.operations_array();
}

void create_stack_from_linked_list() {
    Stack_from_link_list stack_from_linked_list;
    stack_from_linked_list.operations_link_list();
}

void main_menu_stack() {
    Stack_menu menu;
    menu.selection_menu();
    int choice_to_create_stack;
    int size;
    cout << "Enter your choice: " << endl;
    cin >> choice_to_create_stack;
    switch (choice_to_create_stack) {
        case 1:
            cout << "Enter the size of the stack: " << endl;
            cin >> size;
            create_stack_from_array(size);
            break;
        case 2:
            create_stack_from_linked_list();
            break;
        case 0:
            cout << "Exiting the program ... " << endl;
            exit(0);
        default:
            cout << "Invalid choice" << endl;
    }
}

void create_queue();

class Queue {
public:
    virtual void enqueue(int value) = 0;

    virtual void dequeue() = 0;

    virtual void peek() = 0;

    virtual void display() = 0;
};

class QueueArray : public Queue {
private:
    int *arr;
    int front, rear, capacity;

public:
    QueueArray(int size) {
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }

    void enqueue(int value) {
        if (rear == capacity - 1) {
            cout << "Queue Overflow! Cannot enqueue." << endl;
            return;
        }
        arr[++rear] = value;
        if (front == -1) front = 0;
        cout << "Element " << value << " enqueued to the array-based queue." << endl;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow! Cannot dequeue." << endl;
            return;
        }
        int dequeuedElement = arr[front++];
        cout << "Element " << dequeuedElement << " dequeued from the array-based queue." << endl;
        if (front > rear) front = rear = -1;
    }

    void peek() {
        if (front == -1) {
            cout << "Queue is empty. Cannot peek." << endl;
            return;
        }
        cout << "Front element of the array-based queue: " << arr[front] << endl;
    }

    void rear_peek() {
        if (rear == -1) {
            cout << "Queue is empty. Cannot peek." << endl;
            return;
        }
        cout << "Rear element of the array-based queue: " << arr[rear] << endl;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Elements of the array-based queue: ";
        for (int i = front; i <= rear; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class QueueLinkedList : public Queue {
private:
    struct Node {
        int data;
        Node *next;
    };
    Node *front;
    Node *rear;

public:
    QueueLinkedList() {
        front = rear = nullptr;
    }

    void enqueue(int value) {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Element " << value << " enqueued to the linked list-based queue." << endl;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow! Cannot dequeue." << endl;
            return;
        }
        int dequeuedElement = front->data;
        Node *temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) rear = nullptr;
        cout << "Element " << dequeuedElement << " dequeued from the linked list-based queue." << endl;
    }

    void peek() {
        if (front == nullptr) {
            cout << "Queue is empty. Cannot peek." << endl;
            return;
        }
        cout << "Front element of the linked list-based queue: " << front->data << endl;
    }

    void rear_peek() {
        if (rear == nullptr) {
            cout << "Queue is empty. Cannot peek." << endl;
            return;
        }
        cout << "Rear element of the linked list-based queue: " << rear->data << endl;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Elements of the linked list-based queue: ";
        Node *temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void ops_array() {
    int size = 0;
    cout << "\nenter size of array: ";
    cin >> size;
    QueueArray arrayQueue(size);

    int choice, value;
    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Enqueue (Array)" << endl;
        cout << "2. Dequeue (Array)" << endl;
        cout << "3. Peek (Array)" << endl;
        cout << "4. Rear peek (Array)" << endl;
        cout << "5. Display (Array)" << endl;
        cout << "6. back to menu" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue (Array): ";
                cin >> value;
                arrayQueue.enqueue(value);
                arrayQueue.display();
                break;
            case 2:
                arrayQueue.dequeue();
                arrayQueue.display();
                break;
            case 3:
                arrayQueue.peek();
                arrayQueue.display();
                break;
            case 4:
                arrayQueue.rear_peek();
                break;
            case 5:
                arrayQueue.display();
                break;
            case 6:
                create_queue();
                break;
            case 0:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 0);

}

void ops_linked_list() {
    QueueLinkedList linkedListQueue;

    int choice, value;
    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Enqueue (Linked List)" << endl;
        cout << "2. Dequeue (Linked List)" << endl;
        cout << "3. Peek (Linked List)" << endl;
        cout << "4. Display (Linked List)" << endl;
        cout << "5. Rear peek (Linked List)" << endl;
        cout << "6. back to menu" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue (Linked List): ";
                cin >> value;
                linkedListQueue.enqueue(value);
                linkedListQueue.display();
                break;
            case 2:
                linkedListQueue.dequeue();
                linkedListQueue.display();
                break;
            case 3:
                linkedListQueue.peek();
                linkedListQueue.display();
                break;
            case 4:
                linkedListQueue.display();
                break;
            case 5:
                linkedListQueue.rear_peek();
                linkedListQueue.display();
                break;
            case 6:
                create_queue();
                break;
            case 0:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 0);

}

void create_queue() {
    cout << "CREATE QUEUE FROM:" << endl;
    cout << ">> 1. ARRAY" << endl;
    cout << ">> 2. LINKED LIST" << endl;
    cout << ">> 3. back to menu" << endl;
    cout << ">> 0. EXIT" << endl;
    int choice_to_create_stack;
    cout << "Enter your choice: ";
    cin >> choice_to_create_stack;
    switch (choice_to_create_stack) {
        case 1:
            ops_array();
            break;
        case 2:
            ops_linked_list();
            break;
        case 3:
            sub_menu_linear();
            break;
        case 0:
            cout << "Exiting the program ... " << endl;
            exit(0);
        default:
            cout << "Invalid choice" << endl;
    }

}


struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode *constructTree() {
    int value;
    cout << "Enter value for root node: ";
    cin >> value;
    TreeNode *root = new TreeNode(value);

    queue<TreeNode *> nodesToProcess;
    nodesToProcess.push(root);

    while (!nodesToProcess.empty()) {
        TreeNode *current = nodesToProcess.front();
        nodesToProcess.pop();

        int leftVal, rightVal;
        cout << "Enter value for left child of " << current->value << " (or -1 if no left child): ";
        cin >> leftVal;
        if (leftVal != -1) {
            current->left = new TreeNode(leftVal);
            nodesToProcess.push(current->left);
        }

        cout << "Enter value for right child of " << current->value << " (or -1 if no right child): ";
        cin >> rightVal;
        if (rightVal != -1) {
            current->right = new TreeNode(rightVal);
            nodesToProcess.push(current->right);
        }
    }

    return root;
}

void inOrderTraversal(TreeNode *node) {
    if (node != nullptr) {
        inOrderTraversal(node->left);
        cout << node->value << " ";
        inOrderTraversal(node->right);
    }
}

void preOrderTraversal(TreeNode *node) {
    if (node != nullptr) {
        cout << node->value << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

void postOrderTraversal(TreeNode *node) {
    if (node != nullptr) {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->value << " ";
    }
}

void tree_ops() {
    TreeNode *root = constructTree();
    int choice;
    do {
        cout << "1. Inorder traversal" << endl;
        cout << "2. Preorder traversal" << endl;
        cout << "3. Postorder traversal" << endl;
        cout << "4. back to menu" << endl;
        cout << "0. exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "\nInorder traversal: ";
                inOrderTraversal(root);
                break;
            case 2:
                cout << "\nPostorder traversal: ";
                postOrderTraversal(root);
                break;
            case 3:
                cout << "\nPreorder traversal: ";
                preOrderTraversal(root);
                break;
            case 4:
                sub_menu_non_linear();
            case 0:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 0);
    cout << endl;
}

//functions
void sub_menu_linear() {
    cout << "\nLinear Data structure" << endl;
    cout << ">> 1. array" << endl;
    cout << ">> 2. linked list" << endl;
    cout << ">> 3. Stack" << endl;
    cout << ">> 4. Queue" << endl;
    cout << ">> 5. Main Menu" << endl;
    cout << ">> 0. Exit" << endl;
    cout << "\tEnter your choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            create_array();
            break;
        case 2:
            create_link_list();
            break;
        case 3:
            main_menu_stack();
            break;
        case 4:
            create_queue();
            break;
        case 5:
            main_menu();
            break;
        case 0:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
            break;
    }

}

void sub_menu_non_linear() {
    cout << "\nNon-Linear Data structure" << endl;
    cout << ">> 1. tree" << endl;
    cout << ">> 2. Main Menu" << endl;
    cout << ">> 0. Exit" << endl;
    cout << "\tEnter your choice: ";
    int choice = 0;
    cin >> choice;

    switch (choice) {
        case 1:
            tree_ops();
            break;
        case 2:
            main_menu();
            break;
        case 0:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
            break;
    }
}

void sub_menu_algorithm() {
    cout << "\nPerform algorithm" << endl;
    cout << ">> 1. search algorithm" << endl;
    cout << ">> 2. sort algorithm" << endl;
    cout << ">> 3. back to Main Menu" << endl;
    cout << ">> 0. Exit" << endl;
    cout << "\tEnter your choice: ";
    int choice = 0;
    cin >> choice;
    switch (choice) {
        case 1:
            sub_menu_searching_algorithm();
            break;
        case 2:
            sub_menu_sorting_algorithm();
            break;
        case 3:
            main_menu();
            break;
        case 0:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
            break;
    }

}

void sub_menu_searching_algorithm() {
    Search s;
    s.insert();
    s.linearSearch(4);
    int choice;
    do {
        cout << "\nSearch algorithm" << endl;
        cout << ">> 1. linear search" << endl;
        cout << ">> 2. binary search" << endl;
        cout << ">> 3. Main Menu" << endl;
        cout << ">> 0. Exit" << endl;
        cout << "\tEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter key: ";
            int key;
            cin >> key;
            cout << "Searching..." << endl;
            int result_linear = s.linearSearch(key);
            cout << "Result: " << result_linear << endl;
        } else if (choice == 2) {
            cout << "Enter key: ";
            int key;
            cin >> key;
            cout << "Searching..." << endl;
            int result_binary = s.binarySearch(0, s.size - 1, key);
            cout << "Result: " << result_binary << endl;
        } else if (choice == 3) {
            sub_menu_algorithm();
        } else {
            exit(0);
        }
    } while (choice != 0);
}

void sub_menu_sorting_algorithm() {
    Sorting s;
    s.takeInput();
    s.sortMenu();
}

void main_menu() {
    int choice;
    do {
        cout << "\nMain Menu" << endl;
        cout << ">> 1. Linear Data structure" << endl;
        cout << ">> 2. Non-Linear Data structure" << endl;
        cout << ">> 3. Perform algorithm Operations" << endl;
        cout << ">> 0. Exit" << endl;
        cout << "\tEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                sub_menu_linear();
                break;
            case 2:
                sub_menu_non_linear();
                break;
            case 3:
                sub_menu_algorithm();
                break;
            case 0:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 0);
}

int main() {
    main_menu();
    return 0;
}

//THIS ISN'T THE FINAL CODE, LOT OF THINGS TO CHANGE IN THIS, IT'S OPEN FOR CORRECTIONS!!! THANKS 
