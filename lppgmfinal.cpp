//<start>
#include<iostream>
#include<fstream>
using namespace std;
class patient
{
	public:
		int id,count=0;
		int age;
		char name[15],dname[15];
		char gender[10],specialisation[10];
	void pdetails()
	{
		cout<<"enter the patient name"<<endl;
		cin>>name;
		cout<<"enter patient id number"<<endl;
		cin>>id;
		cout<<"enter the age"<<endl;
		cin>>age;
		cout<<"enter patient gender"<<endl;
		cin>>gender;
		count++;
	}
	void pdisplay()
	{
		cout<<"patient nameis:"<<name<<endl;
		cout<<"patient id is"<<id<<endl;
		cout<<"patient ageis"<<age<<endl;
		cout<<"patient gender is"<<gender<<endl; 
	}
	void ddetails()
	{
		cout<<"enter doctorname"<<endl;
		cin>>dname;
		cout<<"enter specialisation"<<endl;	
		cin>>specialisation;
	}
	void ddisplay()
	{
		cout<<"doctor name"<<dname<<endl;
		cout<<"doctor specilasation"<<specialisation<<endl;
	}
	void bill()
	{	int d1,d2,m1,m2,y1,y2;
		int days;
		int month_days[]={31,28,31,30,31,30,31,31,31,3031,30,31};
		fstream b;
		b.open("price.txt",ios::out|ios::in|ios::app);
		cout<<"enter first date"<<endl;
		cin>>d1>>m1>>y1;
		/*
		b<<d1<<m1<<y1;
		*/
		cout<<"enter second date"<<endl;
		cin>>d2>>m2>>y2;
		if(y1==y2)
		{
			if(m1==m2)
			days=d2-d1;
			else
			{
				for(int i=m1;i<m2-1;i++)
				
					days+=month_days[i];
					days+=month_days[m1-1]-d1+d2;
				
			}
	
		}
		else
		{
			for(int i=0;i<m2-1;i++)
			days+=month_days[i];
			for(int i=m1;i<12;i++)
			days+=month_days[i];
			if(y2-y1>=0)
			days+=(y2-y1-1)*365+month_days[m1-1]-d1+d2;
	}
		cout<<"no of days in hospital"<<days<<endl;
		int  amount;
		amount=(days*100)+150;
		cout<<"total amount is"<<amount<<endl;
		
		
					
	}
};
class hospital:public patient
{	public:
	void enquiry()
	{
		hospital a;
		int found=0,bid;
		do
		{
			fstream file("patie.txt",ios::in|ios::out|ios::app);
			cout<<"enetr ur bid no"<<endl;
			cin>>bid;
			file.read((char*)&a,sizeof(hospital));
			while(!file.eof())
			{
				if(a.id==bid)
				{
					a.bill();
					found=1;
					break;
				}
				file.read((char*)&a,sizeof(hospital));
			}
			
		if(a.id!=bid)
		cout<<"incorrectid"<<endl;
		 	
		}while(found==0);
		
		
	}
};
void counsultancy()
{
	cout<<"thanku for visiting"<<endl;
}
main()
{
	int ch,count=0;
	int op;
	
	do
	{
		cout<<"enter ur choice"<<endl;
		cout<<"1.registration for patient\n2.registration for doctor\n3.patient details display\n4.doctor details display\n5.billing6.exit"<<endl;
		cin>>ch;
		//switch(ch)
		
		//{
		//	case 1:
		if(ch==1)
		{
		
				    fstream file;
					file.open("patie.txt",ios::out|ios::in|ios::app);
					if(!file.is_open())
					{
						cout<<"file opening error"<<endl;
						
					}
					hospital p;
					char op;
					do
					{
						p.pdetails();
						file.write((char*)&p,sizeof(hospital));
						cout<<"any other registration"<<endl;
						cin>>op;
					}while(op=='Y'||op=='y');
			}
			
			if(ch==2)
			{
				fstream file;
				file.open("doctor.txt",ios::out|ios::in|ios::app);
				if(!file.is_open())
				{
					cout<<"file opening error"<<endl;
				}
				hospital q;
				char po;
				do
				{
					q.ddetails();
					file.write((char*)&q,sizeof(hospital));
					cout<<" any other registration"<<endl;
					cin>>po;
				}while(po=='Y'||po=='y');
		}
			
		if(ch==3)
		{
		
		
			hospital r;
			fstream file;
			file.open("patie.txt",ios::out|ios::in);
			file.seekg(0);
			file.read((char*)&r,sizeof(hospital));
			while(!file.eof())
			{
				r.pdisplay();
				file.read((char*)&r,sizeof(hospital));
				break;
				
			}
		
	}
		if(ch==4)
		{
		
		
			hospital s;
			fstream file;
			file.open("doctor.txt",ios::out|ios::in|ios::app);
			file.seekg(0);
			file.read((char*)&s,sizeof(hospital));
			while(!file.eof())
			{
				s.ddisplay();
				file.read((char*)&s,sizeof(hospital));
				
			}
		
	}
		if(ch==5)
		{
		
			hospital t;
			t.enquiry();
	}
			
	/*	if(ch==6)
		{0
		
		
			fstream file;
			file.open("patie.txt",ios::in|ios::out|ios::app);
			file.seekg(0);
			int count=0;
			hospital y;
		if(!file.eof())
		{
		
			
					count++;
				
			}
				cout<<"no of patients  are"<<count+1<<endl;
		}*/
		}while(ch!=6);
				
	}

  

