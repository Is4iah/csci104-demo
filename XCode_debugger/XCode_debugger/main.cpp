#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

void funcB(Node* in1, Node* in2);





Node* funcA(Node* in)
{
    cout << in->value << endl; //tells us value every time

    if (in == NULL) return NULL; //executes at the end of list ENDING recursion

    Node* out = NULL; //created empty pointer

    if (in->next != NULL) //if there is another node in the list
    {
        out = funcA(in->next); //make out equal to the return of
                               //funcA (starts recursive function)
        
        cout << in->value << endl; //once done with recursion, shows num backwards

        funcB(in, out);  //call funcB

        in->next = NULL;
        return out;
    }
    return in;
}

void funcB(Node* in1, Node* in2)
{
    if (in2->next != NULL)
    {
        funcB(in1, in2->next);
        return;
    }
    in2->next = in1;
}



















int main() {
    Node* tempVal5 = new Node;
    tempVal5->value = 5;
    tempVal5->next = NULL;

    Node* tempVal4 = new Node;
    tempVal4->value = 4;
    tempVal4->next = tempVal5;
    
   
    Node* tempVal3 = new Node;
    tempVal3->value = 3;
    tempVal3->next = tempVal4;

    Node* tempVal2 = new Node;
    tempVal2->value = 2;
    tempVal2->next = tempVal3;

    Node* tempVal = new Node;
    tempVal->value = 1;
    tempVal->next = tempVal2;
    
    funcA(tempVal);


}
