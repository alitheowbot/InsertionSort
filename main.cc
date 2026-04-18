#include <iostream>
#include <vector>

using namespace std;


struct T
{
    int element = 0;
    T *next = NULL;
    T *prev = NULL;
};

struct List
{
    T* head;
    T* tail;
};


vector<List*> TList;

List* UseCorrectList();

void DeleteByValue(List* list) {
    int userElement = 0;
    cout << "\nInsert number: ";
    cin >> userElement;

    T* newNode = list->head->next;

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

void DeleteByIndex(List* list) {
    int userElement = 0;
    int index = 0;
    cout << "\nType Index [Count from 0]: ";
    cin >> userElement;

    T* newNode = list->head->next;

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

void DisplayForward(List* list)
{
    T* tmpNode = list->head->next;

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

void DisplayBackward(List* list)
{
    T* tmpNode = list->tail->prev;
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

void InsertSorted(List* list)
{
    int userElement = 0;
    cout << "\nInsert number: ";
    cin >> userElement;

    T *newNode = new T;
    T *traverseNode = list->head->next;

    while (traverseNode->next != NULL || traverseNode == list->tail) { // checks if our list is empty as well.
        if (traverseNode->element > userElement || traverseNode == list->tail)
        {
            traverseNode->prev->next = newNode;

            newNode->prev = traverseNode->prev;
            newNode->next = traverseNode;
            newNode->element = userElement;

            traverseNode->prev = newNode;
            return;
        }
        else
        {
            traverseNode = traverseNode->next;
        }
    }
    cout << "Failed to find where to insert!" << endl;

}

void InsertForward(List* list)
{
    int userElement = 0;
    cout << "\nInsert number: ";
    cin >> userElement;

    T *newNode = new T;

    newNode->element = userElement;
    newNode->prev = list->head;
    newNode->next = list->head->next;
    list->head->next->prev = newNode;
    list->head->next = newNode;
}

void InsertBack(List* list)
{
    int userElement = 0;
    cout << "\nInsert number: ";
    cin >> userElement;

    T *newNode = new T;

    newNode->element = userElement;
    newNode->next = list->tail;
    newNode->prev = list->tail->prev;
    list->tail->prev->next = newNode;
    list->tail->prev = newNode;
}

void ListSplit(List* list)
{
    DisplayForward(list);

    int userInput = 0;
    int index = 0;
    cout << "At what index [0, 1, 2, etc.] would you like to split the list at?" << endl;
    cin >> userInput;

    T *traverseNode = list->head->next;
    T *newHead = new T; // For new list
    T *newTail = new T; // For original list
    while (traverseNode != NULL)
    {
        if (index == userInput)
        {
            traverseNode->next->prev = newHead;
            newHead->next = traverseNode->next;
            newHead->prev = NULL;

            newTail->prev = traverseNode;
            newTail->next = NULL;

            traverseNode->next = newTail;

            List* newList = new List;
            newList->head = newHead;
            newList->tail = list->tail;
            list->tail = newTail;

            TList.push_back(newList);
            return;
        }
        else
        {
            traverseNode = traverseNode->next;
            index++;
        }
    }
    cout << "Failed!";
}

List* UseCorrectList()
{
    int num = -2;

    for (int i = 0; i < TList.size(); i++)
    {
        cout << (i+1) << ". ";
        DisplayForward(TList[i]);
        cout << endl;
    }

    cout << "Which list would you like to edit? ";

    while (num == -2)
    {
        cin >> num;
        if (num <= TList.size()) return TList[num-1];
        else { cout << "\nInvalid input, try again\n"; num = -2; }
    }

    return 0;
}

void DisplayAll() // Hidden Function, type "88" in the menu to access!
{
    cout << endl;
    for (int i = 0; i < TList.size(); i++)
    {
        List* list = TList[i];
        T* traverseNode = list->head->next;
        while (traverseNode->next != NULL) {
            cout << "Element: " << traverseNode->element << " Next Address Element: " << traverseNode->next->element << endl;
            traverseNode = traverseNode->next;
        }
    }
}

void Everything()
{
    // Initializes our first list
    T *head = new T; T *tail = new T; head->next = tail; tail->prev = head;
    List* first_List = new List;
    first_List->head = head; first_List->tail = tail;
    TList.push_back(first_List);

    int userInput = 0;
    while (userInput != -1)
    {
        List* list = TList[0];
        if (TList.size() > 1)
        {
            list = UseCorrectList();
        }


        // TODO:
        // Sort list using merge sort (list split recursively until n=2. then compare and swap their positions around. I think?)
        // once n=1, thats when we start merging. keep comparing the head of each list with the head of the other list
        // whichever head is smaller, drag it to a separate list, and keep doing that recursively
        cout << endl
             << endl;
        cout << "______________________" << endl;
        cout << "|                    |" << endl;
        cout << "| Insert Menu:       |" << endl;
        cout << "| 1. Insert at back  |" << endl;
        cout << "| 2. Insert at front |" << endl;
        cout << "| 3. Insert sorted   |" << endl;
        cout << "| 4. Display forward |" << endl;
        cout << "| 5. Display backward|" << endl;
        cout << "| 6. List Split      |" << endl;
        cout << "| 7. Delete by value |" << endl;
        cout << "| 8. Delete by index |" << endl;
        cout << "| -1 to exit         |" << endl;
        cout << "|____________________|" << endl;
        cout << endl
             << endl;

        cin >> userInput;
        if (userInput == 1)
        {
            InsertBack(list);
        }
        else if (userInput == 2)
        {
            InsertForward(list);
        }
        else if (userInput == 3) {
            InsertSorted(list);
        }
        else if (userInput == 4)
        {
            DisplayForward(list);
        }
        else if (userInput == 5)
        {
            DisplayBackward(list);
        }
        else if (userInput == 6)
        {
            ListSplit(list);
        }
        else if (userInput == 7)
        {
            DisplayForward(list);
            DeleteByValue(list);
            DisplayForward(list);
        }
        else if (userInput == 88) {
            DisplayAll();
        }
        else if (userInput == 8)
        {
            DisplayForward(list);
            DeleteByIndex(list);
            DisplayForward(list);
        }
    }

    /*T* current = head->next;
    while (current != tail) {
        T* temp = current;
        current = current->next;
        delete temp;
    }
    delete head;
    delete tail;*/
    // Construction notes: Go through each List in TList and delete the heads and tails of those
}

int main()
{
    Everything();
    return 0;
}
