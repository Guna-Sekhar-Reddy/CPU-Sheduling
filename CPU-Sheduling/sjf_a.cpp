// arrival time		(non preemtive) 

#include<iostream>
using namespace std;

struct wait
{
	int time;			//burst time
	int atime;
}s;

int main()
{
	int n,swap=0,temp=0,temp2=0;
	float avg,sum=0;
	cout<<"Enter the number of processes u want to enter"<<endl;
	cin>>n;
	struct wait s[n];
	
	int warr[n+1],warr1[n+1];
	cout<<"Enter the process brust time "<<endl;
	
	for(int i=0;i<n;i++)
	{
		cin>>s[i].time;
	}
	
	cout<<"Enter the arrival time of process "<<endl;
	
	for(int i=0;i<n;i++)
	{
		cin>>s[i].atime;
	}
	
	for(int i=0;i<n;i++)					//sorting acording to shortest time 
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
				
				temp2=s[j+1].atime;
				s[j+1].atime=s[j].atime;
				s[j].atime=temp2;
			}
			
			
		}
		if(swap=0)
		break;
	}
	
//	for(int i=0;i<n;i++)
//	{
//		cout<<"after sorting "<<s[i].time<<endl;
//	}
	
	warr[0]=0;
	warr1[0]=0;
	for(int i=1;i<n+1;i++)
	{
		warr[i]=warr[i-1]+s[i-1].time;
		cout<<"values="<<warr[i]<<endl;
		
		if(warr[i]<s[i].atime)
		{
			warr1[i]=0;
		}
		
		else
		{
			warr1[i]=warr[i]-s[i].atime;
		}
	
	    cout<<"warr1 values"<<warr1[i]<<endl;
	}
	
	for(int i=0;i<n;i++)
	{
		sum=sum+warr1[i];
	}
	avg=sum/n;
	cout<<"average waiting time is "<<avg<<endl;
	
	sum=sum+warr1[n];
	avg=sum/n;
	
	cout<<"average turnaround time is "<<avg<<endl;
	
}
