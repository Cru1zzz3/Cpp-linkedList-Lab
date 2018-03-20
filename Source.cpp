#include <iostream>
#include "linkedListClass.h"

using namespace std;

int main() {

    int x;
    // Initialization root

    linkedListClass *rootElement = new linkedListClass();

    cout << "Input root element: ";
    cin >> x;
	cout << endl;
    rootElement->data = x;

    linkedListClass* currentElement = rootElement;

mark:
	cout << "\nCurrent element is: " << currentElement->data << endl; 
    cout << "Choose option:\n 0. Exit programm \n 1. Add new element after current \n 2. Find element \n 3. Delete current element \n 4. Delete root element \n 5. Show list\n "  << endl;
	cout << "My option is: ";
    cin >> x;
	cout << endl;
    switch (x){
        case 0:
            break;
        case 1:
			currentElement = currentElement -> inputElement(currentElement);
            goto mark;
		case 2:
			rootElement = rootElement -> findElement(rootElement);
			goto mark;
		case 3: 
			currentElement = currentElement -> deletingElement(currentElement);
			goto mark;
		case 4: 
			rootElement = rootElement -> deletingRootElement(rootElement);
			currentElement = rootElement;
			goto mark;
        case 5:
			rootElement->showList(rootElement);
            goto mark;
        default:
            cout << "Incorrect option! Input your option again" << endl << endl;
            goto mark;
    }

    cout << "Bye :c" << endl;
    getchar();
    return 0;
}