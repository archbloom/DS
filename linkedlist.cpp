
#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node *next;

	node(int data)
	{
		this->data=data;
		this->next=NULL;
	}
	friend class list;
};
class list
{
public:
	node *start;
	list()
	{
		start=NULL;
	}
	void insertdata();
	void display();
};
void list :: insertdata()
{
	node *p;
	int d;
	cout<<"Enter data:";
	cin>>d;
	p = new node(d);
	if(start == NULL)
	{
		start=p;
		p->next=NULL;
	}
	else
	{
		node *temp;
		temp=start;
		while(temp->next != NULL)
			temp=temp->next;
		temp->next=p;
		p->next=NULL;
	}
	return;
}
void list :: display()
{
	node *temp;
	if(start == NULL)
		cout<<"Create list First.\n";
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			cout<<temp->data;
			temp=temp->next;
		}
	}
	return;
}
int main()
{
	void choice();
	choice();
	return 0;
}
void choice()
{
	int ch,x=0;
	list l;
	while(1)
	{
		cout<<"1.insert data\n2.display\n3.exit\nYour choice:";
		cin>>ch;
		switch(ch)
		{
		case 1:l.insertdata();
		break;
		case 2:l.display();
		break;
		default:x=1;
		break;
		}
		if(x==1)
			break;
	}
	return;
}
