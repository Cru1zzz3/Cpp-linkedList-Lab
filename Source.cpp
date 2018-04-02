#include <iostream>
#include "linkedListClass.h"
using namespace std;

int main() {
   int option;
   linkedListClass *rootElement = new linkedListClass();
   linkedListClass* currentElement = rootElement->createRootElement(rootElement);
do { 
	currentElement->getCurrentElement(currentElement);
    cout << "Choose option:\n 0. Exit programm \n 1. Add new element after current \n 2. Find element \n 3. Delete current element \n 4. Delete root element \n 5. Show list\n "  << endl;
	cout << "My option is: ";
    cin >> option;
	cout << endl;
	
		switch (option){
			case 0:
				break;
			case 1:
				currentElement = currentElement -> inputElement(currentElement);
				break;
			case 2:
				rootElement = rootElement -> findElement(rootElement);
				break;
			case 3: 
				currentElement = currentElement -> deletingElement(currentElement);
				break;
			case 4: 
				rootElement = rootElement -> deletingRootElement(rootElement);
				currentElement = rootElement;
				break;
			case 5:
				currentElement->showList(rootElement);
				break;
			default:
				cout << "Incorrect option! Input your option again" << endl << endl;
				break;
		}
	} while (option != 0);

    cout << "Bye :c" << endl;
    getchar();
    return 0;
}