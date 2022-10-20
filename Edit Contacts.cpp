int EditContacts()
    	{
	    	Node *temp=head;
	    	cout<<"***********"<<endl;
	    	cout<<"  Press 1 if you want to Search By Name"<<endl;
	    	cout<<"  Press 2 if you want to Search By Number"<<endl;
	    	int Ecommand;
	    	cout<<"  Enter the Command: ";
	    	cin>>Ecommand;
	  
	    	if(Ecommand==1)
	    	{
	    		bool Echeck=false;
	    		cout<<"  Enter the Name to Edit: ";
	    		cin>>x;
	    		while(temp!=NULL)
	    		{
	    	    	if(temp->name==x)
		        	{
		        		cout<<"***********"<<endl;
		        		cout<<"Name: "<<temp->name<<endl;
		        		cout<<"Phone Number: "<<temp->phone_number<<endl;
		        		cout<<"***********"<<endl;
		        		Echeck=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}				
	        	if(Echeck==true)
	        	{
	            	int command;
	        	    cout<<"  Press 1 to Edit the Contact: ";
	            	cin>>command;
	        	    if(command==1)
	        	    {
	        		    cout<<"  Enter New Name: ";
    	        		cin>>x;
	            		cout<<"  Enter New Number: ";
	            		cin>>y;
	        		
	            		temp->name=x;
	        	    	temp->phone_number=y;
	        		
	        		    cout<<"  Contact Edited Success Fully"<<endl;
			    	}
			    	else
			    	{
					    cout<<"  You Enter Wrong Command ... Try Again"<<endl;
	    	        }
	    	    }
	    	    else if(Echeck==false)
	    	    {
	    	    	cout<<"  Contact Not Found"<<endl;
				}
	        }
	    	else if(Ecommand==2)
	    	{
	    		bool Echeck=false;
	    		cout<<"  Enter the Number to Edit: ";
	    		cin>>y;
	    		while(temp!=NULL)
	    		{
	    	    	if(temp->phone_number==y)
		        	{
		        		cout<<"***********"<<endl;
		        		cout<<"Name: "<<temp->name<<endl;
		        		cout<<"Phone Number: "<<temp->phone_number<<endl;
		        		cout<<"***********"<<endl;
		        		Echeck=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}
	        	if(Echeck==true)
	        	{
	            	int command;
	        	    cout<<"  Press 1 to Edit the Contact: ";
	            	cin>>command;
	        	    if(command==1)
	        	    {
	        		    cout<<"  Enter New Name: ";
    	        		cin>>x;
	            		cout<<"  Enter New Number: ";
	            		cin>>y;
	        		
	            		temp->name=x;
	        	    	temp->phone_number=y;
	        		
	        		    cout<<"  Contact Edited Success Fully"<<endl;
			    	}
			    	else
			    	{
					    cout<<"  You Enter Wrong Command"<<endl;
	    	        }
	        	}
	        	else if(Echeck==false)
	        	{
	        	    cout<<"  There is No Contact of this Number."<<endl;
	            }
	        }
	        else
			{
			    cout<<"  You Enter Wrong Command ... Try Again"<<endl;
			}
	    }
