#include <iostream>
using namespace std;

class node
{
	int data;
	node *next;
	node()
	{
		data=0;
		next=NULL;
	}
	node(int data)
	{
		this->data=data;
		this->next=NULL;
	}
	friend class cll;
};

class cll
{
	node *start;
public:
	cll()
	{
		start = NULL;
	}
	void add()
	{
		node *temp;
		cout<<"Enter data:";
		cin>>temp->data;
		node *tr;
		if(start == NULL)
		{
			start= temp;
			temp->next=start;
		}
		else
		{
			tr = start;
			while(tr->next!=start)
				tr=tr->next;
			tr->next=temp;
			temp->next=start;
		}
	}
	void display()
	{
		node *temp;
		temp=start;
		while(temp->next =! start)
			cout<<temp->data<<"->";
		temp->data;
	}
};

int main()
{
	int ch;
	cll c;
	while(1)
	{
		cout<<"1.add\n2.display\n3.exit\nchoice:";
		cin>>ch;
		switch(ch)
		{
		case 1:c.add();
		break;
		case 2:c.display();
		break;
		case 3:break;

		}
	}
	cout << "!!!Hello Archbloom!!!" << endl; // prints !!!Hello Archbloom!!!
	return 0;
}
