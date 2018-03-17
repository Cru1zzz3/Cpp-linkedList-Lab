#include <iostream>
using namespace std;

class linkedListClass{
public:
    linkedListClass *previous;
    int data;
    linkedListClass *next;
};

void showList(linkedListClass *rootElement){

	if (rootElement != nullptr){
		linkedListClass *showPointer = rootElement;
		do {
			cout << "Previous element adress: " << showPointer->previous << "\t Data: " << showPointer->data << " / Data adress: "<< showPointer << "\t Next element adress:\t " << showPointer->next<< endl;
			showPointer = showPointer->next;
		} while (showPointer != nullptr);
		cout << "\n" << endl;
	} else {
		cout << "Linked list is empty! Input root element!" << endl;
	}
};

linkedListClass*  inputElement(linkedListClass *currentElement){
    int x;
    cout << "Input new element: ";
    cin >> x;
    cout << endl;

    linkedListClass *newElement = new linkedListClass();

    if (currentElement->next != nullptr){
		newElement->data = x;
		newElement->next = currentElement->next;
		currentElement->next = newElement;
		newElement->previous = currentElement;
		currentElement= newElement->next;
		currentElement->previous = newElement->previous;
		currentElement = newElement;
    }
	
	else {
		newElement->data = x;
		newElement->previous = currentElement;

		currentElement->next = newElement;
		currentElement = newElement;		
	}
	    
    return (currentElement);
};

linkedListClass* deletingRootElement(linkedListClass *rootElement){

	linkedListClass *deleteElement = rootElement;
	if (deleteElement->next == nullptr){
	cout << "Can't delete last element of list!!!"<< endl;
	return (rootElement);
	}

	linkedListClass *currentElement = deleteElement->next;

	int tempData = deleteElement->data;
	currentElement->previous = nullptr;

	delete(deleteElement);
	cout << "Root element with data "<< tempData << " sucssessfully deleted!" << endl;
	return (currentElement);
	
}

linkedListClass* deletingElement(linkedListClass *currentElement){
	
	linkedListClass *deleteElement = currentElement;
	int tempData = deleteElement->data;
		 
	 if (deleteElement->next == nullptr){
		currentElement = deleteElement->previous;
		currentElement->next = nullptr;
		
	}
	 else {
		currentElement = currentElement->previous;
		currentElement ->next = deleteElement->next;
		currentElement = currentElement->next;
		currentElement ->previous = deleteElement->previous;
	}

	delete(deleteElement);
	cout << "Element with data "<< tempData << " sucssessfully deleted!" << endl;
	return (currentElement);

    
}


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
	cout << "\nCurrent element is: " << currentElement->data << endl; 
    cout << "Choose option:\n 0. Exit programm \n 1. Add new element after current \n 2. Find element \n 3. Delete current element \n 4. Delete root element \n 5. Show list\n "  << endl;
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
		case 3: 
			currentElement = deletingElement(currentElement);
			goto mark;
		case 4: 
			rootElement = deletingRootElement(rootElement);
			currentElement = rootElement;
			goto mark;
        case 5:
           showList(rootElement);
            goto mark;
        default:
            cout << "Incorrect option! Input your option again" << endl << endl;
            goto mark;
    }

	

  //deleteElement(rootElement);

    cout << "Bye :c" << endl;
    getchar();
    return 0;
}