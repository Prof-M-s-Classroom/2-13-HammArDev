#include <iostream>
using namespace std;

class student {
public:
    string name;
    int age;

    student(string name, int age) {
        this->name = name;
        this->age = age;
    }
    void print() { cout << name << " " << age << endl; }
};

template <typename T> class Node {
public:
    T *value;
    Node<T> *next;
    Node(T *value) {
        this->value = value;
        this->next = NULL;
    }
    void print() { value->print(); }
};

template <typename T> class LinkedList {
private:
    int length;
    Node<T> *head;

public:
    LinkedList(T *value) {
        this->length = 1;
        this->head = new Node<T>(value);
    }
    void add(T *value) {
        Node<T> *newNode = new Node<T>(value);
        Node<T> *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        length++;
    }

    void addhead(T *value) {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        length++;
    }

    void delfirst() {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void dellast() {
        Node<T> *temp = head;
        while (temp->next->next!=NULL)
            temp = temp->next;
        delete temp->next;
        temp->next=nullptr;
        length--;
    }

    void deleteNode(int index) {
       //TODO:Write the function to delete at the given index. Reuse the pre-written functions for edge cases. Account for missing index.
        //yell at user if index>length
        //There are 3 cases: they want to delete the first element, the last element, or a middle one
        //Case 1: Deleting the first element
        if(index>length-1){
            cout<<"Invalid index, please enter a valid index(whole number below "<<length<<")"<<endl;
            return;
        }
        else if(index==0){
            delfirst();
        }
        //Case 2: Deleting the last element
        else if(index==length-1){
            dellast();
        }
        //Case 3: Deleting a middle element-we'll keep track of the Node before
        //And store the node to be deleted in a temp pointer
        //Then, shift pointers and delete that temp
        else{
            /*int currIndex = 0;
            Node<T>* predNode = head;
            while(currIndex<index-1){
                predNode=predNode->next;
                ++currIndex;
            }*/
            Node<T>* predNode = get(index-1);
            Node<T>* delNode = predNode->next;
            predNode->next=delNode->next;
            delete delNode;
        }
        --length;
    }

   void insert(int index, T *value) {
        //TODO:Write a function to insert a new node at a give index. Reuse the pre-written functions for edge cases. Account for missing index
        if(index>length || index<0){
            cout<<"Invalid index, please enter a valid index(whole number below "<<length+1<<")"<<endl;
        }
        else if(index==0){
            addhead(value);
        }else if(index==length){
            add(value);
        }else{
            /*Node<T>* oldNode = head;
            Node<T>* newNode = new Node<T>(value);
            int currIndex = 0;
            while(currIndex<indx){
                oldNode=oldNode->next;
                ++currIndex;
            }*/
            Node<T>* newNode = new Node<T>(value);
            Node<T>* oldNode = get(index);
            newNode->next=oldNode->next;
            oldNode->next=newNode;
            ++length;
        }
    }

   void reverseList(){
        //TODO:Write a function to reverse the list using the logic from the slide.
        Node<T>* prev, curr, next;
        prev = nullptr;
        curr = head;
        while (curr->next) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }

    Node<T>* get(int index) {
        if (index<0 ||index>length-1) {
            return nullptr;
        }
        Node<T>* temp = head;
        for (int i=0; i<index; ++i) {
            temp = temp->next;
        }
        return temp;
    }

    ~LinkedList() {
        while (head) {
            Node<T>* temp = head->next;
            delete head;
            head = temp;
        }
        delete this;
    }

    void print() {
        cout << "Printing List.." << endl;
        Node<T> *temp = head;
        while (temp != NULL) {
            temp->print();
            temp = temp->next;
        }
    }
};

int main() {
    student *s1 = new student("A", 20);
    student *s2 = new student("B", 21);
    student *s3 = new student("C", 22);
    LinkedList<student> *ll = new LinkedList<student>(s1);
    /*ll->add(s2);
    ll->addhead(s3);
    ll->print();
    ll->delfirst();
    ll->print();
    ll->dellast();
    ll->print();*/
    ll->add(s2);
    ll->add(s3);
    ll->print();
    ll->insert(3, s2);
    ll->print();
    /*ll->reverseList();
    ll->print();*/

}