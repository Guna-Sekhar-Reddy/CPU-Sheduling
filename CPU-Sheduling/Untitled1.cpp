#include<iostream>

using namespace std;

int N=5;

void milk()
{
	cout<<N;
}
int main()
{
	cout<<N<<endl;
	N=10;
	cout<<N<<endl;
	milk();
}
