#include <iostream>
#define N 10

using namespace std;

int size = 0;

class linkedListClass{
public:
    int *previous = nullptr;
    int data = 0;
    int *next = nullptr;
};




void inputElement(linkedListClass *linkedList){

    int x;
    size++;
    linkedListClass *previousPointer = linkedList;
    previousPointer[size-1] = previousPointer[size];

    cout << "Input element" << endl;
    cin >> x;

    linkedList->data = x;
    linkedList->previous = &previousPointer->data;
    linkedList->next = nullptr;

    cout << "Previous pointer of linkedList: \t" <<linkedList->previous << endl;
    cout << "Data of linkedList: \t" <<linkedList->data << endl;
    cout << "Next pointer of linkedList: \t" <<linkedList->next << endl;
    cout << "Size of list: \t" << size << endl;

    //linkedList = (linkedListClass *) realloc( linkedList, sizeof(linkedListClass)*size);

/*


    cout << "Previous pointer of linkedList: \t" <<linkedListPointer->previous << endl;
    cout << "Data of linkedList: \t" <<linkedListPointer->data << endl;
    cout << "Next pointer of linkedList: \t" <<linkedListPointer->next << endl;
    cout << "Size of list: \t" << size << endl;
*/
};

void showList(linkedListClass *rootPointer){
    int i = 0;
        for (rootPointer[i];i<size;i++){
            cout << i <<". Previous pointer:\t" << rootPointer[i].previous  << "\n Data:\t " << rootPointer[i].data<< "\n Next pointer: \t"  <<  rootPointer[i].next<< endl;
        }
};

/*void createNode(linkedListClass *rootPointer){
    int x;
    cout << "Input root element: "<< endl;
    cin >> x;

    rootPointer->data=x;
};
*/

int main() {
    int x;
    bool root;

    int *linkedListPointer;

    linkedListClass *linkedList = new linkedListClass[N];
    linkedListClass *rootPointer = &linkedList[0];
    cout << "Input root element:" << endl;
    cin >> x;
    rootPointer->data = x;
    size++;



    cout << "Previous pointer of linkedListPointer: \t" <<linkedList->previous << endl;
    cout << "Data of linkedListPointer: \t" <<linkedList->data << endl;
    cout << "Next pointer of linkedListPointer: \t" <<linkedList->next << endl;
    cout << "linkedList: \t" << linkedList << endl;
    cout << "rootPointer: \t" << rootPointer << endl;
   // createNode(rootPointer);
   // size++;

  //  cout << "Size of linkedListClass is: \t" << sizeof(linkedListClass) << endl;
  //  cout << "Size of linkedListPointer is: \t" << sizeof(linkedListPointer) << endl;

    mark:
    cout << "Choose option:\n 1. Add new element \n 2. Find element \n 3. Delete element \n 4. Show list\n"  << endl;
    cin >> x;

    switch (x){
        case 0:
            break;
        case 1:
            size++;
            inputElement(linkedList);
            goto mark;
        case 4:
            showList(rootPointer);
            goto mark;
        default:
            cout << "Input your option again" << endl;
            goto mark;
    }



    delete linkedListPointer;
    //delete rootPointer;
    cout << "Press button to exit" << endl;
    cin >> x;
    return 0;
}