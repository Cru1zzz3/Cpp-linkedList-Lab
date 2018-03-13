#include <iostream>
using namespace std;

class linkedListClass{
public:
    linkedListClass *previous;
    int data;
    linkedListClass *next;
};

void showList(linkedListClass *rootElement){

    linkedListClass *showPointer = rootElement;

    do {
        cout << "Previous element adress:\t" << showPointer->previous << "\t Data:\t" << showPointer->data << "/Data adress: \t"<< showPointer << "\t Next element adress: \t" << showPointer->next<< endl;
        showPointer = showPointer->next;
    } while (showPointer != nullptr);
};

linkedListClass*  inputElement(linkedListClass *currentElement){

    int x;
    cout << "Input new element:" << endl;
    cin >> x;

    linkedListClass *newElement = new linkedListClass();

    newElement->data = x;
    newElement->previous = currentElement;

    currentElement->next = newElement;
    currentElement = newElement;
    return (currentElement);
};

/*
void deleteElements(linkedListClass *rootElement){

    linkedListClass *deletePointer = rootElement;

    deletePointer = deletePointer->next;
    do{
        free(deletePointer->previous);
    } while (deletePointer != nullptr);
}
*/

int main() {
    int x;

    // Initialization root

    linkedListClass *rootElement = new linkedListClass();

    cout << "Input root element:" << endl;
    cin >> x;
    rootElement->data = x;

    linkedListClass *currentElement = rootElement;

    mark:
    cout << "Choose option:\n 0. Exit programm \n 1. Add new element \n 2. Find element \n 3. Delete element \n 4. Show list\n"  << endl;
    cin >> x;

    switch (x){
        case 0:
            break;
        case 1:
           currentElement = inputElement(currentElement);
            goto mark;
        case 4:
           showList(rootElement);
            goto mark;
        default:
            cout << "Input your option again" << endl;
            goto mark;
    }

  //  deleteElements(rootElement);
    cout << "Press button to exit" << endl;
    cin >> x;
    return 0;
}