#include <iostream>
using namespace std;

void process(int n,int id)
{
  for(int i=0;i<n;i++)
    {
      cout<<"Running process has ID "<<id<<".\n";
    }
}

class node
{
public:
  int ar_time,req_time,id;
  node *next;
  node()
  {
    id=0;
    ar_time=0;
    req_time=0;
    next=NULL;
  }
  node(int i,int at,int rt)
  {
    id=i;
    ar_time=at;
    req_time=rt;
  }
  friend class queue;
};

class queue
{
  node *head,*tail;
public:
  queue()
  {
    head=NULL;
    tail=NULL;
  }

  bool empty()
  {
    if(head==NULL)
      return 1;
    else
      return 0;
  }

  void push(node *n)
  {
    node *temp;
    if(head==NULL)
      {
	head=n;
	tail=n;
      }
    if(head==tail)
      {
	head->next=n;
	tail=n;
      }
    else
      {
	temp=head;
	while(temp!=tail)
	  {
	    temp=temp->next;
	  }
	temp->next=n;
	tail=n;
      }
  }

  node * pop()
  {
    node *temp;
    temp=head;
    head=head->next;
    return temp;
  }

  void print()
  {
    node *temp;
    if(head==NULL)
      {
	cout<<"NULL queue.\n";
      }
    else
      {
	temp=head;
	while(temp!=tail)
	  {
	    cout<<"a_time = "<<temp->ar_time<<endl<<"req_time = "<<temp->req_time<<endl;
	    temp=temp->next;
	  }
	cout<<"a_time = "<<temp->ar_time<<endl<<"req_time = "<<temp->req_time<<endl;
      }
  }
};

int main()
{
  int num,n1,n2,quant,sum=0;
  node *nn;
  queue n;
  cout<<"Number of processes : ";
  cin>>num;
  for(int i=0;i<num;i++)
    {
      cout<<"Enter arrival time for "<<i+1<<"th process : ";
      cin>>n1;
      cout<<"Enter burst time for "<<i+1<<"th process :";
      cin>>n2;
      sum=sum+n2;
      n.push(new node(i+1,n1,n2));
    }

  cout<<"Enter CPU quantum time : ";
  cin>>quant;
  while(!n.empty())
    {
      nn=n.pop();
      if(nn->req_time > quant)
	{
	  nn->req_time=nn->req_time - quant;
	  process(quant,nn->id);
	  n.push(new node(nn->id,nn->ar_time,nn->req_time));
	}
      else if(nn->req_time <= quant)
	{
	  process(nn->req_time,nn->id);
	}
    }
  cout<<"Total time required = "<<sum;
  cout<<"\nAverage time for each process = "<<(float)sum/num<<endl;
  return 0;
}
