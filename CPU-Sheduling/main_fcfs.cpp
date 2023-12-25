//fcfs without arrival time(complete)
//non-preamptive

#include<iostream>
using namespace std;

struct wait
{
	int time;			//burst time
}s;

int main()
{
	int n,temp=0;
	float avg,sum=0;
	cout<<"Enter the number of processes u want to enter"<<endl;
	cin>>n;
	struct wait s[n];
	
	int warr[n+1];
	cout<<"Enter the process brust time "<<endl;
	
	for(int i=0;i<n;i++)
	{
		cin>>s[i].time;
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<s[i].time;
	}
	
	
	warr[0]=0;
	for(int i=1;i<n+1;i++)
	{
		warr[i]=warr[i-1]+s[i-1].time;
		cout<<"values="<<warr[i]<<endl;
	}
	
	for(int i=0;i<n;i++)
	{
		sum=sum+warr[i];
	}
	avg=sum/n;
	cout<<"average waiting time is "<<avg<<endl;
	
	sum=sum+warr[n];
	avg=sum/n;
	
	cout<<"average turnaround time is "<<avg<<endl;
	
}
