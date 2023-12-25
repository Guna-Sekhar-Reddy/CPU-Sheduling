//sjf without arrival time  (non preemtive)

#include<iostream>
using namespace std;

struct wait
{
	int time;			//burst time
}s;

int main()
{
	int n,swap=0,temp=0;
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
	
	for(int i=0;i<n;i++)
	{
		swap=0;
		for(int j=0;j<n-1-i;j++)
		{
			if(s[j].time>s[j+1].time)
			{
				temp=s[j+1].time;
				s[j+1].time=s[j].time;
				s[j].time=temp;
				swap=1;
			}
		}
		if(swap=0)
		break;
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<"after sorting "<<s[i].time<<endl;
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
