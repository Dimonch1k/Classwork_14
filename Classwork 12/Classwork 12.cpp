#include <iostream>
#include <queue>

using namespace std;



/*

class Node {
public:
    int value;   
    Node* next;

    Node()
    {
        value = 0;
        next = nullptr;
    }
    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};

void putNodeToTail(Node*& head, int value)
{
    Node* newNode = new Node(value);

    if (head == nullptr) 
    {
        head = newNode;
        return;
    }

    Node* tmp = new Node();
    tmp = head;

    while (tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void display(Node* head)
{
    Node* temp;
    temp = head;   

    cout << "All numbers: \n";    
    while (temp != nullptr)
    {
        cout << temp->value << " ";       
        temp = temp->next;
    }
    cout << "\n\n";
}

void displayNegative(Node* &head)
{
    Node* temp;
    temp = head;    temp = temp->next;
    int negative = 0;
    cout << "Negative numbers:\n";
    while (temp != nullptr)
    {
        if (temp->value < 0)
        {
            cout << temp->value << " ";           
            temp = temp->next;
            negative++;
        }
        else
        {
            temp = temp->next;
        }
    }
    if (negative == 0) {
        cout << "There are no negative numbers!\n\n\n";
    }
    else {
        cout << "\n\n\n";
    }
}

void increase_Values(int increase, Node* &head)
{
    Node* temp;
    temp = head;   
    while (temp != nullptr)
    {
        temp->value += increase;
        temp = temp->next;
    }
    cout << "The values successfully increased by " << increase << "!\n\n\n";
}

bool removeNumber(int remove, Node* &head)
{
    if (head->value == remove) 
    {
        if (head->next == nullptr)
        {
            head = nullptr;
            return false;
        }
        head = head->next;
        return true;
    }

    Node* temp;
   

    temp = head;
    while (temp->next != nullptr)
    { 
        if (temp->next->value == remove)
        {
            if (temp->next->next == nullptr)
            {
                temp->next = nullptr;
                return false;
            }
            temp->next = temp->next->next;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void removeNumbers(Node* &head, int remove) 
{
    while (removeNumber(remove, head))
    {
        cout << "Number " << remove << " was deleted " << endl;
    }
}


void setElement(Node* &head, int V1, int V2)
{
    Node* temp = head;

    while (temp != nullptr)
    {            
        if (temp->value == V1)
        {      
            if (temp->next != nullptr) 
            {
                Node* newNode = new Node(V2);
                newNode = temp->next;
                temp = newNode;
            }

            else if (temp->next == nullptr)
            {
                Node* newNode = new Node(V2);
                newNode = nullptr;
                temp = newNode;
            }
        }
        temp = temp->next->next;
    }
}

int main() {
    Node* head = nullptr; // Create start node
    cout << "Enter 5 numbers to the list:\n";

    for (int i = 0; i < 5; i++) // The user input 5 values in list
    {
        int value = 0;
        cout << "Enter " << i + 1 << " number: ";    
        cin >> value;
        putNodeToTail(head, value); // Put node to the end of the list   
    }
    cout << "\n\n\n\n";
    display(head); // Display all list of values 
    displayNegative(head); // Display all negative numbers in list

    int increase = 0;
    cout << "Enter the value to increase all numbers on this value: "; cin >> increase; // The user input value
    increase_Values(increase, head); // Increase all numbers with the given by the user value    display(head); // Display all list of values
    display(head);

    int remove = 0;
    cout << "Enter the value to delete all numbers with this value: "; cin >> remove; // The user input value
    removeNumbers(head, remove); // Delete all numbers with the given by the user value    display(head); // Display all list of values
    display(head);



    int V1 = 0;
    int V2 = 0;
    cout << "Enter V1: "; cin >> V1;
    cout << "Enter V2: "; cin >> V2;
    setElement(head, V1, V2);
    display(head);

}


*/


/*
class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node()
    {
        value = 0;
        next = nullptr;
        prev = nullptr;
    }
    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

void putNodeToTail(Node*& head, int value)
{
    Node* newNode = new Node(value);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* tmp = new Node();
    tmp = head;

    while (tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->prev = tmp;
}
  
void display(Node* head)
{
    Node* temp;
    temp = head;

    cout << "All numbers: \n";
    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << "\n\n";
}


bool Check(Node*& head)
{
    Node* temp = head;

    while (temp != nullptr)
    {
        if (temp->next != nullptr)
        {
            if (temp->value < temp->next->value)
            {
                temp = temp->next;
                continue;
            }
            return false;
        }
        temp = temp->next;
    }
    return true;
}

string CheckDrop(Node*& head)
{
    if (Check(head))
    {
        return "The list is sorted by height.\n\n";
    }
    return "The list isn't sorted\n\n";
}

bool identical_Numbers(Node*& head)
{
    Node* temp = head;
    Node* temp2 = temp->next;

    while (temp != nullptr)
    {
        while (temp2 != nullptr)
        {
            
            if (temp2->value == temp->value)
            {
                return true;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
        if (temp->next != nullptr) { temp2 = temp->next; continue; }
        break;
    }
    return false;
}

string check_Ident_Nums(Node*& head)
{
    if (identical_Numbers(head))
    {
        return "There is pair of identical numbers\n\n\n";
    }
    return "There isn't any pair of identical numbers\n\n\n";
}

bool swapValues(Node*& head)
{
    if (head == nullptr)
    {
        return false;
    }

    Node* temp1 = head;

    int counter = 0;
    while (temp1 != nullptr)
    {
        counter++;
        temp1 = temp1->next;
    }
    if (counter == 1) { return false; }


    Node* mainTemp = head;
    Node* temp2 = mainTemp;

    int i = 1;
    while (mainTemp != nullptr)
    {
        if (mainTemp->next != nullptr)
        {
            if (mainTemp->next->next == nullptr)
            {
                Node* newTemp = temp2;
                newTemp = temp2->next;
                temp2->next = temp2;
                newTemp = nullptr;

                return true;
            }
            Node* newTemp = temp2;
            Node* newTemp2 = temp2->next;
            newTemp = temp2->next->next;
            temp2->prev = newTemp2;
            newTemp2 = newTemp;
            newTemp = temp2->next->next;

            mainTemp = mainTemp->next;
            i++;
            continue;
        }
        return true;
    }
    return true;
}

string Swap(Node* head)
{
    if (swapValues(head))
    {
        return "The values were swapping\n\n\n";
    }
    return "There is one value in your list\n\n\n";
}

int main()
{
    Node* head = nullptr;
    

    for (int i = 0; i < 5; i++) // The user input 5 values in list
    {
        int value = 0;
        cout << "Enter " << i + 1 << " number: ";
        cin >> value;
        putNodeToTail(head, value); // Put node to the end of the list   
    }
    display(head);
    cout << CheckDrop(head);

    cout << check_Ident_Nums(head);

    cout << Swap(head);
    display(head);
}*/




/**/
class Node {
public:
    int value;
    Node* next;

    Node()
    {
        value = 0;
        next = nullptr;
    }
    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};


void putNodeToTail(Node*& head, int value)
{
    Node* newNode = new Node(value);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* tmp = new Node();
    tmp = head;

    while (tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}


void display(Node* head)
{
    cout << "All numbers: \n";
    while (head != nullptr)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << "\n\n";
}


void deleteNum(Node*& head)
{
    if (!head)
    {
        cout << "The queue is empty!!!\n\n";
        return;
    }
    else if (head->next != nullptr)
    {
        head = head->next;
        cout << "The number deleted!\n\n";
        return;
    }
    head = nullptr;
    cout << "First number deleted!\n\n";
}


string isEmpty(Node* head)
{
    if (!head)
    {
        return "The queue is empty!\n\n";
    }
    return "The queue is filled!\n\n";
}

bool isEmpty2(Node* head)
{
    if (!head)
    {
        return true;
    }
    return false;
}



int getFirstElem(Node* head)
{
    if (isEmpty2(head) == false)
    {
        return head->value;
    }
    cout << "The "
}

int main()
{
    Node* head = nullptr;


    for (int i = 0; i < 4; i++) // The user input 5 values in list
    {
        int value = 0;
        cout << "Enter " << i + 1 << " number: ";
        cin >> value;
        putNodeToTail(head, value); // Put node to the end of the list   
    }
    display(head);
    cout << isEmpty(head);
    if (isEmpty2(head))
    {
deleteNum(head);
    
    

    display(head);
}






























/*

#include <queue>


void display(queue<int> que)
{
    cout << "All numbers: ";
    while (!que.empty())
    {
        cout << que.front() << " ";
        que.pop();
    }
    cout << "\n\n";
}

void add(queue<int> &que)
{
    int num;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter " << i + 1 << " number: ";
        cin >> num;
        que.push(num);
    }
}

void remove(queue<int>& que, int num)
{
    queue<int> que2 = que;
    while (!que2.empty()) 
    {
        if (que2.front() == num)
        {

        }
    }

}

int main()
{
    queue<int> que;

    add(que);
    display(que);

    remove(que, 4);
}*/


/**/
