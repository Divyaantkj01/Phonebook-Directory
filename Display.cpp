//Sorting and display in phonebook

void display() //display function
{
	int len=0;
	if (head==NULL)
	cout<<"Contact list is Empty!"<<endl;
	else
	{
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


