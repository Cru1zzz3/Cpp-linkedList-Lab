#include <iostream>
#include <cstdlib>

using namespace std;

class linkedListClass{
public:
    int *previous;
    int data;
    int *next;
};

void addElement(int x, linkedListClass *linkedListPointer){

};

void inputElement(linkedListClass *linkedListPointer){

    linkedListPointer = (linkedListClass *) realloc( linkedListPointer, sizeof(linkedListClass)+ sizeof(linkedListClass));
    int x;
    cout << "Input element" << endl;
    cin >> x;
    addElement(x,linkedListPointer);
};

int main() {
    int x;

    linkedListClass *linkedListPointer = new linkedListClass[1];

    cout << "Data of linkedListPointer: \t" <<linkedListPointer->data << endl;
    cout << "Size of linkedListClass is: \t" << sizeof(linkedListClass) << endl;

    cout << "Size of linkedListPointer is: \t" << sizeof(linkedListPointer) << endl;

    mark:
    cout << "Choose option:" << endl;
    cin >> x;

    switch (x){
        case 0:
            break;
        case 1:
            inputElement(linkedListPointer);
        default:
            cout << "Input your option again" << endl;
            goto mark;
    }

    delete linkedListPointer;
    cout << "Press button to exit" << endl;
    cin >> x;
    return 0;
}