//round robin without arrival time

#include<iostream>
#include<cmath>
using namespace std;

struct wait
{
	int time;
	int mtime;
}s;

int main()
{
	int n,n1=0,n2;
	float sum1=0,t,avg,sum=0;
	cout<<"Enter the number of processes u want to enter"<<endl;
	cin>>n;
	
	struct wait s[n];
	int w[n];
	int ta[n];
	cout<<"Enter burst times of processes"<<endl;
	
	for(int i=0;i<n;i++)
	{
		cin>>s[i].time;
		s[i].mtime=s[i].time;
	}
	
	
	cout<<"Enter the quatum time "<<endl;
	cin>>t;
	
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
		w[j]=warr[i-1];				//waiting time of each process
		ta[j]=warr[i];				//turnaround time of each process
		
		
	//	cout<<"modified time "<<s[j].mtime<<" at j= "<<j<<endl;
	//	cout<<"warr values are "<<warr[i]<<endl;
		j=(j+1)%n;
		
		if(count==n)							//all processes are completed
		{
			break;
		}
		count=0;
	}
	
	for(int i=0;i<n;i++)			
	{
		sum=sum+w[i];
		//cout<<"waitiing time of process "<<i<<" is "<<w[i]<<endl;
	}
	
	avg=sum/n;
	cout<<"average waiting time is "<<avg<<endl;
	
	sum=0;
	
	for(int i=0;i<n;i++)
	{
		sum=sum+ta[i];
		//cout<<"turnaround time of process "<<i<<" is "<<ta[i]<<endl;
	}
	avg=sum/n;
	cout<<"average turnaround time is "<<avg<<endl;
}
