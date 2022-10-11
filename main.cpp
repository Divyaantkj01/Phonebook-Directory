#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct node
{
    string name, number;
    node *next;
};
node *head = NULL, *newnode, *temp;

void C_node()
{
    newnode = new node;
    cout << "Enter Name ";
    cin >> newnode->name;
    
    cout << "Enter Mobile number";
    cin >> newnode->number;
    cout<<"\n";
    
    newnode->next = NULL;
    
    if (head == NULL)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}
//Sorting and display in phonebook



void display() //display function

{

	int len=0;

	if (head==NULL)

	cout<<"Contact list is Empty!"<<endl;

	else

	{

		bubblesort();

		node *trav=head;

		while(trav!=NULL)

		{

			cout<<"\n\tFull Name"<<trav->name<<endl;

			cout<<"\t\tPhone number"<<trav->number<<endl;

			trav=trav->next;

			len++;

		}

		cout<<"Total contacts in the list:"<<len<<endl;

	}

}


void search_contact()
{
    node *search_node = head;
    string srch;
    int count = 0;

    cout << "Enter your desired contact you want to search: ";
    cin >> srch;
    bool found = true;
    if (head == NULL)
    {
        cout << "\nList is Empty " << endl;
    }
    else
    {
        while (search_node != NULL)
        {
            if (srch == search_node->name || srch == search_node->number)
            {
                cout << "\n\tFull Name: " << search_node->name << endl;
                cout << "\tPhone Number: " << search_node->number << endl;
                found = true;
                break;
            }
            search_node = search_node->next;
            count++;
        }
    }
    if (found == true)
    {

        cout << "\tIndex of Contact = " << count << endl;
        cout << "\n";
    }
    else
    {
        cout << "Desired contact not found" << endl;
    }
}

void at_given()
{
    int pos;
    node *next_node;
    temp = head;
    cout << "Enter your desired position from where you want to delete contact" << endl;
    cin >> pos;

    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else if (pos > len)
    {
        cout << "Invalid Position" << endl;
    }

    else if (pos == 0)
    {
        temp = head;
        head = head->next;
        delete temp;
        cout << "Contact has been deleted" << endl;
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        next_node = temp->next;
        temp->next = next_node->next;
        delete next_node;
        cout << "Contact has been deleted" << endl;
    }
}

void clear_all()
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        temp = head;
        while (head != NULL)
        {
            head = head->next;
            delete temp;
        }
        cout << "All Contact list has been deleted" << endl;
    }
}

void menu()
{
    cout << "Enter 1 to add contact " << endl;
    cout << "Enter 2 to display all contact" << endl;
    cout << "Enter 3 to search contact" << endl;
    cout << "Enter 4 to delete contact" << endl;
    cout << "Enter 5 to clear ALL records" << endl;
}

int main()
{
    int op;
    while (true)
    {
        menu();
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "\n";
            C_node();
            break;

        case 2:
            cout << "\n";
            len = 0;
            display();
            break;

        case 3:
            cout << "\n";
            search_contact();
            break;

        case 4:
            cout << "\n";
            at_given();
            break;

        case 5:
            clear_all();
            break;

        default:
            cout << "Invalid Option" << endl;
        }
    }
}
