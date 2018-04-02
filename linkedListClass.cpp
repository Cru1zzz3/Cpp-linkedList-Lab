#include <iostream>
#include "linkedListClass.h"

using namespace std;

linkedListClass* linkedListClass::createRootElement(linkedListClass *rootElement){
	int x;
    cout << "Input root element: ";
    cin >> x;
	cout << endl;
    rootElement->data = x;
	return (rootElement);
};

void linkedListClass::getCurrentElement(linkedListClass* currentElement){
	cout << "\nCurrent element is: " << currentElement->data << endl;
};

linkedListClass* linkedListClass::inputElement(linkedListClass *currentElement){
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

linkedListClass* linkedListClass::findElement(linkedListClass *rootElement){
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
		return(rootElement);
	};

linkedListClass* linkedListClass::deletingElement(linkedListClass *currentElement){
	
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

linkedListClass* linkedListClass::deletingRootElement(linkedListClass *currentElement){

		linkedListClass *deleteElement = currentElement;
		if ((deleteElement->next == nullptr) && (deleteElement == nullptr)){
		cout << "Can't delete last element of list!!!"<< endl;
		return (currentElement);
		}
		else {
			linkedListClass *currentElement = deleteElement->next;
			int tempData = deleteElement->data;
			currentElement->previous = nullptr;
			delete(deleteElement);
			cout << "Root element with data "<< tempData << " sucssessfully deleted!" << endl;
			return (currentElement);
		}
	};

void  linkedListClass::showList(linkedListClass *rootElement){

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
	}



