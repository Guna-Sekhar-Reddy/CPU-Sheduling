//priority arrival time		(preemtive) 

#include<iostream>
using namespace std;

struct wait
{
	int time;			//burst time
	int atime;
}s;

int main()
{
	int n;
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
	
	cout<<"Enter the arrival time of process "<<endl;
	
	for(int i=0;i<n;i++)
	{
		cin>>s[i].atime;
	}
	
	for(int i=0;i<n;i++)					//sorting acording to arrival time 
	{
		swap=0;
		for(int j=0;j<n-1-i;j++)
		{
			if(s[j].atime>s[j+1].atime)
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
	
	
	warr[0]=0;
	warr[1]=s[0].time;
	int min;
	min=s[1].time;
	for(int i=1;i<n;i++)
	{
		if(min>s[i].time)
		{
			min=s[i].time;
		}
	}  
	
	if(min>s[1].time)   
	{
		
	}
}
