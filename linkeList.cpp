#include <iostream>

using namespace std;

int intersect1; //keeps track of the intersecting node from list 1
int intersect2; //keeps track of the intersecting node from the second list
class linkedList {
public:
    int data;
    linkedList* head;


};



void addValue(linkedList** pos, int value)
{
    linkedList* node = new linkedList(); //creates new node to store the next value
    node->data = value; //assings the appropriate value to the empty node
    node->head = (*pos); //moves to the next node
    (*pos) = node;

    // the below if statement checks if the current position is empty
    // if it is empty it sets the node equal to the current postion
    if (node->head == nullptr) {
        (*pos) = node;
    }
}


/*
the following method contains a while loop to 
print all the values from the lists until 
the pointer to the next address is empty
*/
void print_list(linkedList* n) {
    while (n != NULL) {
        cout << n->data << " "; //prints each value from the list followed by a space
        n = n->head;
    }
    

}

/*
This method compares the values from both lists at exactly the same position
if the values from a position in list one is equal to the value at exactly the 
same position in the second list, then the program prints that the list intersect
and returns the intersecting values. It compares the entire lists and returns as
many intersections as there are.

*/
void intersect(linkedList* list1 , linkedList* list2)
{

    while (list1->head != NULL && list2->head != NULL)
    {
        if (list1->data == list2->data)
        {
            intersect1 = list1->data;
            intersect2 = list2->data;
            cout << "the list contains intersecting values " << intersect1 << " and " << intersect2 << endl; //prints the values at the intersection from both lists
        }

        list1 = list1->head;
        list2 = list2->head;
    }

     
}


int main() {
    linkedList* list2 = NULL; //creates and initializes the first list
    linkedList* list1 = NULL; //creates and initializes the second list


   //passing specific values into list1
    addValue(&list1, 1);
    addValue(&list1, 3);
    addValue(&list1, 4);
    addValue(&list1, 11);
    addValue(&list1, 19);
    addValue(&list1, 10);
    addValue(&list1, 11);
    addValue(&list1, 9);
    addValue(&list1, 13);

    //passing specific values into list2
    addValue(&list2, 8);
    addValue(&list2, 3);
    addValue(&list2, 9);
    addValue(&list2, 19);
    addValue(&list2, 18);
    addValue(&list2, 6);
    addValue(&list2, 11);
    addValue(&list2, 10);
    addValue(&list2, 10);

 
 
    cout << "the first list is: " << endl;
    print_list(list1);
    cout << endl;
    cout << "the second list is: " << endl;
    print_list(list2);
    cout << endl;
    intersect(list1, list2);
}