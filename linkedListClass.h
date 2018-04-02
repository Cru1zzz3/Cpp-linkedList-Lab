#ifndef LINKEDLISTCLASS_H
#define LINKEDLISTCLASS_H


class linkedListClass{
	private:
		linkedListClass *previous;
		int data;
		linkedListClass *next;
	public:
		void getCurrentElement(linkedListClass* currentElement);
		linkedListClass* createRootElement(linkedListClass *rootElement);
		linkedListClass* inputElement(linkedListClass *currentElement);
		linkedListClass* findElement(linkedListClass *rootElement);
		linkedListClass* deletingElement(linkedListClass *currentElement);
		linkedListClass* deletingRootElement(linkedListClass *rootElement);
		void showList(linkedListClass *rootElement);
};

#endif LINKEDLISTCLASS_H