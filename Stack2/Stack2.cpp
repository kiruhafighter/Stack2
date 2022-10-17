#include <iostream>
using namespace std;
template<typename T>
class Stack {
public:
    Stack();
    ~Stack();
    void pop();
    void clear();
    void push_back(T data);
    int Count() { return size; }
    T& operator[](const int index);
    void push(T data);
    


private:

    template<typename T>
    struct Node {
    public:
        Node* pnext;
        T data;
        Node(T data = T(), Node* pnext = nullptr) {
            this->data = data;
            this->pnext = pnext;
        }
    };
    int size;
    Node<T>* top;

};


template<typename T>
Stack<T>::Stack() {
    size = 0;
    top = nullptr;
}


template<typename T>
Stack<T>::~Stack() {
    clear();
}


template<typename T>
void Stack<T>::pop()
{
    Node<T>* temp = top;
    top = top->pnext;
    delete temp;
    size--;
}

template<typename T>
void Stack<T>::clear()
{
    while (size) {
        pop();
    }
}

template<typename T>
void Stack<T>::push_back(T data) {
    if (top == nullptr) {
        top = new Node<T>(data);
    }
    else {
        Node<T>* curr = this->top;
        while (curr->pnext != nullptr) {
            curr = curr->pnext;
        }
        curr->pnext = new Node<T>(data);
    }
    size++;
}


template<typename T>
T& Stack<T>::operator[](const int index)
{
    int counter = 0;
    Node<T>* curr = this->top;
    while (curr != nullptr) {
        if (counter == index) {
            return curr->data;
        }
        curr = curr->pnext;
        counter++;
    }
}


template<typename T>
void Stack<T>::push(T data)
{
    top = new Node<T>(data, top);
    size++;
}

//Print
template<typename T>
void printStack(Stack<T> s) {
    for (int i = 0; i < s.Count(); i++) {
        cout << s[i] << " ";
    }
    cout << endl;
}

template<typename T>
Stack<T> Reverse(Stack<T> stk) {
    Stack<T> res;
    for (int i = stk.Count()-1; i >=0; i--) {
        res.push_back(stk[i]);
    }
    return res;
}





//Menu
int menu() {
    cout << "Choose action from list : " << endl;
    cout << "1. Remove " << endl;
    cout << "2. Clear" << endl;
    cout << "3. Get Size of Stack" << endl;
    cout << "4. Add on top" << endl;
    cout << "5. Print" << endl;
    cout << "6. Reverse Stack" << endl;
    int res;
    cin >> res;
    return res;
}

int main()
{
    Stack<int> stk;
    Stack<int> stk2;
    while (true) {
        switch (menu()) {
        case 1:
        {
            system("cls");
            stk.pop();  
        }
        break;
        
        case 2:
        {
            system("cls");
            stk.clear();
        }
        break;

        case 3:
        {
            system("cls");
            cout << stk.Count() << endl;
        }
        break;
        case 4: {
            system("cls");
            cout << "Write number to add " << endl;
            int numa5;
            cin >> numa5;
            stk.push(numa5);
            
        }
              break;
        case 5:
        {
            system("cls");
             printStack(stk);
        }
        break;
        case 6:
        {
            /*Stack<int>resau = Reverse(stk);*/
            
        }
        break;
        }
    }
}
