#include <iostream>
using namespace std;
void hanoi(int n,char from,char to,char inter)
{
	if(n==1)
	{
		cout<<"Move disk 1 from "<<from<<" to "<<to<<"."<<endl;
		return;
	}
	hanoi(n-1,from,inter,to);
	cout<<"Move disk "<<n<<" from "<<from<<" to "<<to<<"."<<endl;
	hanoi(n-1,inter,from,to);
}
int main()
{
	cout<<"TOWER OF HANOI:\n";
	hanoi(3,'A','B','C');
	return 0;
}
