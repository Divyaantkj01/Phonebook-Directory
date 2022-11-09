#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct node
{
    string name, number;
    node *next;
    node *prev;
};

node *head = NULL, *newnode, *temp;
int len = 0;
void add_contact()
{
    newnode = new node;
    cout << " Enter Name: ";
    cin >> newnode->name;

    cout << " Enter Phone Number: ";
    cin >> newnode->number;
    cout << "\n";

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
void display()
{

    if (head == NULL)
    {
        cout << " Contact list is Empty " << endl;
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            cout << "\n\tFull Name: " << temp->name << endl;
            cout << "\tPhone Number: " << temp->number << endl;
            cout << "\n";
            temp = temp->next;
            len++;
        }
        cout << "Total contacts in the list = " << len << endl;
        cout << "\n";
    }
}

void search_contact()
{
    node *temp = head;

    int count = 0;

    cout << "***********" << endl;
    cout << "  Press 1 if you want to Search By Name" << endl;
    cout << "  Press 2 if you want to Search By Number" << endl;
    int Ecommand;

    cout << "  Enter the Command: ";
    cin >> Ecommand;
    string x, y;

    if (Ecommand == 1)
    {
        bool Echeck = false;
        cout << "  Enter the Name to Search: ";
        cin >> x;
        while (temp != NULL)
        {
            if (temp->name == x)
            {
                cout << "***********" << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Phone Number: " << temp->number << endl;
                cout << "***********" << endl;
                Echeck = true;
                break;
            }
            temp = temp->next;
            count++;
        }
        if (Echeck == true)
        {

            cout << "\tIndex of Contact = " << count << endl;
            cout << "\n";
        }
        else
        {
            cout << "Desired contact not found" << endl;
        }
    }

    else if (Ecommand == 2)
    {
        bool Echeck = false;
        cout << "  Enter the Number to Edit: ";
        cin >> y;
        while (temp != NULL)
        {
            if (temp->number == y)
            {
                cout << "***********" << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Phone Number: " << temp->number << endl;
                cout << "***********" << endl;
                Echeck = true;
                break;
            }
            temp = temp->next;
        }
        if (Echeck == true)
        {

            cout << "\tIndex of Contact = " << count << endl;
            cout << "\n";
        }
        else
        {
            cout << "Desired contact not found" << endl;
        }
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

void EditContacts()
{
    node *temp = head;
    cout << "***********" << endl;
    cout << "  Press 1 if you want to Edit By Name" << endl;
    cout << "  Press 2 if you want to Edit By Number" << endl;
    int Ecommand;
    cout << "  Enter the Command: ";
    cin >> Ecommand;
    string x, y;
    if (Ecommand == 1)
    {
        bool Echeck = false;
        cout << "  Enter the Name to Edit: ";
        cin >> x;
        while (temp != NULL)
        {
            if (temp->name == x)
            {
                cout << "***********" << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Phone Number: " << temp->number << endl;
                cout << "***********" << endl;
                Echeck = true;
                break;
            }
            temp = temp->next;
        }
        if (Echeck == true)
        {
            int command;
            cout << "  Press 1 to Edit the Contact: ";
            cin >> command;
            if (command == 1)
            {
                cout << "  Enter New Name: ";
                cin >> x;
                cout << "  Enter New Number: ";
                cin >> y;

                temp->name = x;
                temp->number = y;

                cout << "  Contact Edited Success Fully" << endl;
            }
            else
            {
                cout << "  You Enter Wrong Command ... Try Again" << endl;
            }
        }
        else if (Echeck == false)
        {
            cout << "  Contact Not Found" << endl;
        }
    }
    else if (Ecommand == 2)
    {
        bool Echeck = false;
        cout << "  Enter the Number to Edit: ";
        cin >> y;
        while (temp != NULL)
        {
            if (temp->number == y)
            {
                cout << "***********" << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Phone Number: " << temp->number << endl;
                cout << "***********" << endl;
                Echeck = true;
                break;
            }
            temp = temp->next;
        }
        if (Echeck == true)
        {
            int command;
            cout << "  Press 1 to Edit the Contact: ";
            cin >> command;
            if (command == 1)
            {
                cout << "  Enter New Name: ";
                cin >> x;
                cout << "  Enter New Number: ";
                cin >> y;

                temp->name = x;
                temp->number = y;

                cout << "  Contact Edited Success Fully" << endl;
            }
            else
            {
                cout << "  You Enter Wrong Command" << endl;
            }
        }
        else if (Echeck == false)
        {
            cout << "  There is No Contact of this Number." << endl;
        }
    }
    else
    {
        cout << "  You Enter Wrong Command ... Try Again" << endl;
    }
}
void OfflineSave()
{
    node *temp = head;
    ofstream myfile("contactbook.txt");
    if (myfile.is_open())
    {
        while (temp != NULL)
        {
            myfile << temp->name << endl;
            myfile << temp->number << endl;
            temp = temp->next;
        }
        myfile.close();
        
    }
    else
    {
        cout << "  Thanks file is empty." << endl;
    }
}


void menu()
{
    cout << "Enter 1 to add contact " << endl;
    cout << "Enter 2 to display all contact" << endl;
    cout << "Enter 3 to search contact" << endl;
    cout << "Enter 4 to delete contact" << endl;
    cout << "Enter 5 to clear ALL records" << endl;
    cout << "Enter 6 to Edit Contact" << endl;
    
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
            add_contact();
            OfflineSave();
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

        case 6:
            EditContacts();
            break;

        default:
            cout << "Invalid Option" << endl;
        }
    }
}