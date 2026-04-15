#include <iostream>

using namespace std;

struct T
{
    int element = INT_MAX;
    T *next = NULL;
    T *prev = NULL;
};

void DeleteByValue(T *head) {
    int userElement = 0;
    cout << "\nInsert number: ";
    cin >> userElement;

    T* newNode = head->next;
    
    while (newNode->next != NULL) {
        if (newNode->element == userElement) {
            newNode->prev->next = newNode->next;
            newNode->next->prev = newNode->prev;
            delete newNode;
            return;
        }
        else {
            newNode = newNode->next;
        }
    }
    cout << "Element not found." << endl;
}

void DeleteByIndex(T *head) {
    int userElement = 0;
    int index = 0;
    cout << "\nType Index [Count from 0]: ";
    cin >> userElement;

    T* newNode = head->next;
    
    while (newNode->next != NULL) {
        if (index == userElement) {
            newNode->prev->next = newNode->next;
            newNode->next->prev = newNode->prev;
            delete newNode;
            return;
        }
        else {
            index++;
            newNode = newNode->next;
        }
    }
    cout << "Index not found." << endl;
}

void DisplayForward(T *head)
{
    T* tmpNode = head->next;

    cout << "List: [";
    while (tmpNode->next != NULL)
    {
        if (tmpNode->next->next == NULL)
        {
            cout << tmpNode->element;
        }
        else
        {
            cout << tmpNode->element << " ";
        }

        tmpNode = tmpNode->next;
    }
    cout << "]" << endl;
}

void DisplayBackward(T *tail)
{
    T* tmpNode = tail->prev;
    cout << "List: [";
    while (tmpNode->prev != NULL)
    {
        if (tmpNode->prev->prev == NULL)
        {
            cout << tmpNode->element;
        }
        else
        {
            cout << tmpNode->element << " ";
        }

        tmpNode = tmpNode->prev;
    }
    cout << "]" << endl;
}

void InsertForward(T *head, T *tail)
{
    int userElement = 0;
    cout << "\nInsert number: ";
    cin >> userElement;

    T *newNode = new T;

    newNode->element = userElement;
    newNode->prev = head;
    newNode->next = head->next;
    head->next->prev = newNode;
    head->next = newNode;
}

void InsertBack(T *head, T *tail)
{
    int userElement = 0;
    cout << "\nInsert number: ";
    cin >> userElement;

    T *newNode = new T;

    newNode->element = userElement;
    newNode->next = tail;
    newNode->prev = tail->prev;
    tail->prev->next = newNode;
    tail->prev = newNode;
}

void Everything()
{
    T *head = new T; T *tail = new T; head->next = tail; tail->prev = head;
    int userInput = 0;

    while (userInput != -1)
    {
        // TODO:
        // List split
        // Insert sorted (12, 6, 22), insert 15 would be: (12, 15, 6, 22)
        // Sort list using merge sort (list split recursively until n=2. then compare and swap their positions around. I think?)

        cout << endl
             << endl;
        cout << "______________________" << endl;
        cout << "|                    |" << endl;
        cout << "| Insert Menu:       |" << endl;
        cout << "| 1. Insert at back  |" << endl;
        cout << "| 2. Insert at front |" << endl;
        cout << "| 3. Display forward |" << endl;
        cout << "| 4. Display backward|" << endl;
        cout << "| 5. Delete by value |" << endl;
        cout << "| 6. Delete by index |" << endl;
        cout << "| -1 to exit         |" << endl;
        cout << "|____________________|" << endl;
        cout << endl
             << endl;

        cin >> userInput;
        if (userInput == 1)
        {
            InsertBack(head, tail);
        }
        else if (userInput == 2)
        {
            InsertForward(head, tail);
        }
        else if (userInput == 3)
        {
            DisplayForward(head);
        }
        else if (userInput == 4)
        {
            DisplayBackward(tail);
        }
        else if (userInput == 5)
        {
            DisplayForward(head);
            DeleteByValue(head);
            DisplayForward(head);
        }
        else if (userInput == 6)
        {
            DisplayForward(head);
            DeleteByIndex(head);
            DisplayForward(head);
        }
    }

    T* current = head->next;
    while (current != tail) {
        T* temp = current;
        current = current->next;
        delete temp;
    }
    delete head;
    delete tail;
}

int main()
{
    Everything();
    return 0;
}