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
        cout << "Previous element adress: " << showPointer->previous << "\t Data: " << showPointer->data << " / Data adress: "<< showPointer << "\t Next element adress:\t " << showPointer->next<< endl;
        showPointer = showPointer->next;
    } while (showPointer != nullptr);
	cout << "\n" << endl;
};

linkedListClass*  inputElement(linkedListClass *currentElement){

    int x;
    cout << "Input new element: ";
    cin >> x;
	cout << endl;
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

linkedListClass* findElement(linkedListClass *rootElement){
	int x;
    cout << "Find element with data: ";
    cin >> x;
	cout << endl;

	linkedListClass *findPointer = rootElement;

	while (findPointer != nullptr){
		if(findPointer->data != x){
			findPointer = findPointer->next;
		}
		else {
			cout << "Element with data "<< findPointer->data << " was found!" << endl;
			cout << "Previous element adress: " << findPointer->previous << "\t Data: " << findPointer->data << " / Data adress: "<< findPointer << "\t Next element adress:\t " << findPointer->next<< endl << endl;
			return (findPointer);
			 
		} 
	}
	cout << " No element with data "<< findPointer->data << endl; 
};

int main() {
    int x;

    // Initialization root

    linkedListClass *rootElement = new linkedListClass();

    cout << "Input root element: ";
    cin >> x;
	cout << endl;
    rootElement->data = x;

    linkedListClass *currentElement = rootElement;

    mark:
    cout << "Choose option:\n 0. Exit programm \n 1. Add new element \n 2. Find element \n 3. Delete element \n 4. Show list\n"  << endl;
	cout << "My option is: ";
    cin >> x;
	cout << endl;
    switch (x){
        case 0:
            break;
        case 1:
           currentElement = inputElement(currentElement);
            goto mark;
		case 2:
			currentElement = findElement(rootElement);
			goto mark;
        case 4:
           showList(rootElement);
            goto mark;
        default:
            cout << "Input your option again" << endl;
            goto mark;
    }

	

  //deleteElement(rootElement);

    cout << "Bye :c" << endl;
    getchar();
    return 0;
}