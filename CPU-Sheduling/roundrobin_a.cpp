//round robin without arrival time

#include<iostream>
#include<cmath>
using namespace std;

struct wait
{
	int time;						//burst time
	int mtime;						//modified time
	int atime;						//arrival time 
}s;

int main()
{
	int n,n1=0,n2,swap,temp1,temp2,temp;
	float sum1=0,t,avg,sum=0;
	cout<<"Enter the number of processes u want to enter"<<endl;
	cin>>n;
	
	struct wait s[n];
	cout<<"Enter burst times of processes"<<endl;
	
	for(int i=0;i<n;i++)
	{
		cin>>s[i].time;
		s[i].mtime=s[i].time;
	}
	
	
	cout<<"Enter the quatum time "<<endl;
	cin>>t;
	
	cout<<"Enter the arrival time"<<endl;
	
	for(int i=0;i<n;i++)
	{
		cin>>s[i].atime;
	}
	
	for(int i=0;i<n;i++)					//sorting according to priority
	{
		swap=0;
		for(int j=0;j<n-1-i;j++)
		{
			if(s[j].atime>s[j+1].atime)			//sorting according to arrival time 
			{
				temp=s[j+1].time;
				s[j+1].time=s[j].time;
				s[j].time=temp;
				swap=1;
				
				temp1=s[j+1].mtime;
				s[j+1].mtime=s[j].mtime;
				s[j].mtime=temp1;
				
				temp2=s[j+1].atime;
				s[j+1].atime=s[j].atime;
				s[j].time=temp2;
			}	
		}
		if(swap=0)
		break;
	}
	
	for(int i=0;i<n;i++)						//n1 contains the number of process parts 
	{
		if(s[i].time<=t)
		{
			n1++;
		}
		else
		{
			n2=ceil(s[i].time/t);
			cout<<"n2 for "<<s[i].time<<" is "<<n2<<endl;
			n1=n1+n2;
		}
	}											
	
	cout<<n1<<endl;
	
	int warr[n1+1];
	int j=0,count=0;
	warr[0]=0;
	
	for(int i=1;i<=n1;i++)
	{
		if(s[j].mtime<=0)
		{
			while(s[j].mtime<=0)
			{
				j=(j+1)%n;
				count++;
			//	cout<<"count and s[j].mtime"<<count<<" "<<s[j].mtime<<endl;
				if(count==n)
				{
					break;
				}
			}
		}
		if(s[j].mtime<=t)
		{
			warr[i]=warr[i-1]+s[j].mtime;
			s[j].mtime=0;
		}
		else
		{
			warr[i]=warr[i-1]+t;
			s[j].mtime=s[j].mtime-t;
		}
		
	//	cout<<"modified time "<<s[j].mtime<<" at j= "<<j<<endl;
	//	cout<<"warr values are "<<warr[i]<<endl;
		j=(j+1)%n;
		
		if(count==n)							//all processes are completed
		{
			break;
		}
		count=0;
	}
	
	for(int i=0;i<n1;i++)				//except last one in warr
	{
		sum=sum+warr[i];
	}
	
	avg=sum/n1;
	cout<<"average waiting time is "<<avg<<endl;
	
	sum=sum+warr[n1];
	avg=sum/n1;
	cout<<"average turnaround time is "<<avg<<endl;
}
