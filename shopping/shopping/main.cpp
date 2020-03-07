#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include "classgoods.h"
#include "classuser.h"
#include "classshopper.h"
using namespace std;
#define MAX_GOODS 1000
#define MAX_USERS 10
int nfood,ndaily,napp,nuser,nvip;
shopper *buyer;
food *fo[MAX_GOODS];
dailyuse *da[MAX_GOODS];
appliances *ap[MAX_GOODS];
user *us[MAX_USERS];
vip *vi[MAX_USERS];
void loading();			//���뺯��
void login();			//��¼����
void shop();			//���ﺯ��
int isuse(int);			//�ж��û��Ƿ����
void buyfood();			//����ʳƷ
void buydaily();		//��������Ʒ
void buyapp();			//����ҵ�
void shoppingcart();	//���ﳵ
void showbuyer();		//��������Ϣ
void exitshopping();	//�����˳�
int main()
{
	loading();
	login();
	shop();
}
void loading()
{
	int tmpaa;char tmpbb[255];double tmpcc;char tmpdd[255];double tmpee;
/**********ʳƷ�๹��**********/
	ifstream foodFile;
	string tmpStr("");
	string tmpf[MAX_GOODS];
	nfood=0;
	foodFile.open("./food.txt",ios::in);
	while(getline(foodFile,tmpStr))
	{
		tmpf[nfood]=tmpStr;
		nfood=nfood+1;
	}
	for(int j=0;j<nfood;j++)
	{
		istringstream istr (tmpf[j]);
		istr>>tmpaa;
		istr>>tmpbb;
		istr>>tmpcc;
		istr>>tmpdd;
		fo[j]=new food(tmpaa,tmpbb,tmpcc,tmpdd);
	}
	foodFile.close();
/**********����Ʒ�๹��**********/
	ifstream dailyFile;
	string tmpd[MAX_GOODS];
	ndaily=0;
	dailyFile.open("./dailyuse.txt",ios::in);
	while(getline(dailyFile,tmpStr))
	{
		tmpd[ndaily]=tmpStr;
		ndaily=ndaily+1;
    }
	for(int j=0;j<ndaily;j++)
    {
		istringstream istr (tmpd[j]);
		istr>>tmpaa;
		istr>>tmpbb;
		istr>>tmpcc;
		istr>>tmpdd;
		da[j]=new dailyuse(tmpaa,tmpbb,tmpcc,tmpdd);
	}
	dailyFile.close();
/**********�ҵ��๹��**********/
	ifstream appFile;
	string tmpa[MAX_GOODS];
	napp=0;
	appFile.open("./appliances.txt",ios::in);
	while(getline(appFile,tmpStr))
	{
		tmpa[napp]=tmpStr;
		napp=napp+1;
    }
	for(int j=0;j<napp;j++)
    {
		istringstream istr (tmpa[j]);
		istr>>tmpaa;
		istr>>tmpbb;
		istr>>tmpcc;
		istr>>tmpdd;
		ap[j]=new appliances(tmpaa,tmpbb,tmpcc,tmpdd);
	}
	appFile.close();
	/**********��ͨ�û��๹��**********/
	ifstream userFile;
	string tmpu[MAX_USERS];
	nuser=0;
	userFile.open("./user.txt",ios::in);
	while(getline(userFile,tmpStr))
	{
		tmpf[nuser]=tmpStr;
		nuser=nuser+1;
	}
	for(int j=0;j<nuser;j++)
	{
		istringstream istr (tmpf[j]);
		istr>>tmpaa;
		istr>>tmpbb;
		istr>>tmpcc;
		us[j]=new user(tmpaa,tmpbb,tmpcc);
	}
	userFile.close();
	/**********��ͨ�û��๹��**********/
	ifstream vipFile;
	string tmpv[MAX_USERS];
	nvip=0;
	vipFile.open("./vip.txt",ios::in);
	while(getline(vipFile,tmpStr))
	{
		tmpf[nvip]=tmpStr;
		nvip=nvip+1;
	}
	for(int j=0;j<nvip;j++)
	{
		istringstream istr (tmpf[j]);
		istr>>tmpaa;
		istr>>tmpbb;
		istr>>tmpcc;
		istr>>tmpee;
		vi[j]=new vip(tmpaa,tmpbb,tmpcc,tmpee);
	}
	vipFile.close();
}
void login()
{
	cout<<"**********��ӭ����**********"<<endl;
	cout<<"�����������˺ţ�"<<endl;
	int tmpnum;
	cin>>tmpnum;
	char tmpname[255];
	double tmpmoney;
	double tmpdiscount;
	int buynum;			//��ţ�����100Ϊ��ͨ�û���С��100ΪVIP
	buynum=isuse(tmpnum);
	while(buynum==-1)
	{
		cout<<"��������˺��������������룺";
		cin>>tmpnum;
		buynum=isuse(tmpnum);
	}
	if(buynum>=100)
	{
		strcpy(tmpname,us[buynum-100]->getuname());
		tmpmoney=us[buynum-100]->getumoney();
		buyer=new shopper(tmpnum,tmpname,tmpmoney);
	}
	else
	{
		strcpy(tmpname,vi[buynum]->getuname());
		tmpmoney=vi[buynum]->getumoney();
		tmpdiscount=vi[buynum]->getvdiscount();
		buyer=new shopper(tmpnum,tmpname,tmpmoney,tmpdiscount);
	}
	cout<<"��½�ɹ���"<<endl;
	cout<<"****************************"<<endl;
	Sleep(1000);
	system("cls");
	cout<<"**********��ӭ�� "<<buyer->name<<"**********"<<endl;
	cout<<"�˻���Ϣ"<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<"�˺ţ�"<<buyer->num<<endl;
	cout<<"�˻�����"<<buyer->name<<endl;
	cout<<"�˻���"<<buyer->money<<endl;
	cout<<"*******************************"<<endl;
	Sleep(3000);
}
void shop()
{
	system("cls");
	cout<<"**********��ӭ����**********"<<endl;
	cout<<"1.ѡ��ʳƷ"<<endl;
	cout<<"----------------------------"<<endl;
	cout<<"2.ѡ������Ʒ"<<endl;
	cout<<"----------------------------"<<endl;
	cout<<"3.ѡ���ҵ�"<<endl;
	cout<<"----------------------------"<<endl;
	cout<<"4.�鿴���ﳵ"<<endl;
	cout<<"----------------------------"<<endl;
	cout<<"5.�鿴������Ϣ"<<endl;
	cout<<"----------------------------"<<endl;
	cout<<"6.�˳�"<<endl;
	cout<<"****************************"<<endl;
	cout<<"\n��ѡ��˵��";
	int chx;
	while(1)
	{
		cin>>chx;
		switch(chx)
		{
			case 1:buyfood();break;
			case 2:buydaily();break;
			case 3:buyapp();break;
			case 4:shoppingcart();break;
			case 5:showbuyer();break;
			case 6:exitshopping();break;
			default:cout<<"�����������������룺";
		}
	}
}

int isuse(int n)
{
	for(int i=0;i<nuser;i++)
	{
		if(n==us[i]->getunum())
		{
			return i+100;
		}
	}
	for(int i=0;i<nvip;i++)
	{
		if(n==vi[i]->getunum())
		{
			return i;
		}
	}
	return -1;
}
void buyfood()
{
	system("cls");
	cout<<"ʳƷ"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	cout<<setw(4)<<"���"<<setw(30)<<"Ʒ          ��"<<setw(15)<<"�۸�"<<setw(25)<<"��   ��   ��"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	for(int i=0;i<nfood;i++)
		fo[i]->show();
	cout<<"--------------------------------------------------------------------------"<<endl;
	int bfnum;
	cout<<"��������Ʒ���ѡ����Ʒ(����0�˳�)��";
	cin>>bfnum;
	while(bfnum!=0)
	{
		while((bfnum-1000)>=nfood || (bfnum-1000)<0)
		{
			cout<<"����������������룺";
			cin>>bfnum;
		}
		buyer->buyfo[buyer->buyfnum]=fo[bfnum-1000];
		cout<<"\n���ѳɹ�ѡ����Ʒ��"<<endl;
		cout<<"--------------------------------------------------------------------------"<<endl;
		buyer->buyfo[buyer->buyfnum]->show();
		cout<<"--------------------------------------------------------------------------"<<endl;
		buyer->buyfnum++;
		cout<<"��������Ʒ���ѡ����Ʒ(����0�˳�)��";
		cin>>bfnum;
	}
	shop();
}
void buydaily()
{
	system("cls");
	cout<<"����Ʒ"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	cout<<setw(4)<<"���"<<setw(30)<<"Ʒ          ��"<<setw(15)<<"�۸�"<<setw(25)<<"��        ��"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	for(int i=0;i<ndaily;i++)
		da[i]->show();
	cout<<"--------------------------------------------------------------------------"<<endl;
	int bdnum;
	cout<<"��������Ʒ���ѡ����Ʒ(����0�˳�)��";
	cin>>bdnum;
	while(bdnum!=0)
	{
		while((bdnum-2000)>=ndaily || (bdnum-2000)<0)
		{
			cout<<"����������������룺";
			cin>>bdnum;
		}
		buyer->buyda[buyer->buydnum]=da[bdnum-2000];
		cout<<"\n���ѳɹ�ѡ����Ʒ��"<<endl;
		cout<<"--------------------------------------------------------------------------"<<endl;
		buyer->buyda[buyer->buydnum]->show();
		cout<<"--------------------------------------------------------------------------"<<endl;
		buyer->buydnum++;
		cout<<"��������Ʒ���ѡ����Ʒ(����0�˳�)��";	
		cin>>bdnum;
	}
	shop();
}
void buyapp()
{
	system("cls");
	cout<<"�ҵ�"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	cout<<setw(4)<<"���"<<setw(30)<<"Ʒ          ��"<<setw(15)<<"�۸�"<<setw(25)<<"��        ��"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	for(int i=0;i<napp;i++)
		ap[i]->show();
	cout<<"--------------------------------------------------------------------------"<<endl;
	int banum;
	cout<<"��������Ʒ���ѡ����Ʒ(����0�˳�)��";
	cin>>banum;
	while(banum!=0)
	{
		while((banum-3000)>=napp || (banum-3000)<0)
		{
			cout<<"����������������룺";
			cin>>banum;
		}
		buyer->buyap[buyer->buyanum]=ap[banum-3000];
		cout<<"\n���ѳɹ�ѡ����Ʒ��"<<endl;
		cout<<"--------------------------------------------------------------------------"<<endl;
		buyer->buyap[buyer->buyanum]->show();
		cout<<"--------------------------------------------------------------------------"<<endl;
		buyer->buyanum++;
		cout<<"��������Ʒ���ѡ����Ʒ(����0�˳�)��";
		cin>>banum;
	}
	shop();
}
void shoppingcart()
{
	system("cls");
	cout<<"���ﳵ"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	cout<<"\n����ѡ����ʳƷ"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	for(int i=0;i<buyer->buyfnum;i++)
		buyer->buyfo[i]->show();
	cout<<"--------------------------------------------------------------------------"<<endl;
	cout<<"\n����ѡ��������Ʒ"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	for(int i=0;i<buyer->buydnum;i++)
		buyer->buyda[i]->show();
	cout<<"--------------------------------------------------------------------------"<<endl;
	cout<<"\n����ѡ���ļҵ�"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	for(int i=0;i<buyer->buyanum;i++)
		buyer->buyap[i]->show();
	cout<<"--------------------------------------------------------------------------"<<endl;
	cout<<"����Ҫ��������0,���س����������˵�"<<endl;
	getchar();
	if(getchar()=='0')
	{
		system("cls");
		cout<<"��"<<endl;
		cout<<"-----------------------------------"<<endl;
		if(buyer->buyfnum+buyer->buydnum+buyer->buyanum==0)
		{
			cout<<"����û��ѡ���κ���Ʒ"<<endl;
			getchar();
			getchar();
			shop();
		}
		for(int i=0;i<buyer->buyfnum;i++)
			buyer->sum=buyer->sum+*(buyer->buyfo[i]);
		for(int i=0;i<buyer->buydnum;i++)
			buyer->sum=buyer->sum+*(buyer->buyda[i]);
		for(int i=0;i<buyer->buyanum;i++)
			buyer->sum=buyer->sum+*(buyer->buyap[i]);
		cout<<"�˵��ܽ�"<<buyer->sum<<endl;
		cout<<"�Żݽ�"<<buyer->sum*(1-buyer->discount)<<endl;
		cout<<"-----------------------------------"<<endl;
		cout<<"ʵ����Ҫ֧����"<<buyer->sum*buyer->discount<<endl;
		cout<<"�����˻���"<<buyer->money<<endl;
		cout<<"-----------------------------------"<<endl;
		if(buyer->sum>buyer->money)
		{
			cout<<"�����˻�����Ŷ��"<<endl;
			cout<<"����Ϊ����չ��ﳵ��"<<endl;
			buyer->buyfnum=0;cout<<"."<<endl;Sleep(300);
			buyer->buydnum=0;cout<<".."<<endl;Sleep(300);
			buyer->buyanum=0;cout<<"..."<<endl;Sleep(300);
			buyer->sum=0.0;cout<<"...."<<endl;Sleep(300);
			cout<<"��ճɹ����뷵������ѡ����"<<endl;
			cout<<"-----------------------------------"<<endl;
			getchar();
			getchar();
			shop();
		}
		else
		{
			cout<<"�����˻�����㹻֧�����ι��"<<endl;
			cout<<"����Ϊ�����㣡"<<endl;
			buyer->money=buyer->money-buyer->sum*buyer->discount;cout<<"."<<endl;Sleep(300);
			buyer->buyfnum=0;cout<<".."<<endl;Sleep(300);
			buyer->buydnum=0;cout<<"..."<<endl;Sleep(300);
			buyer->buyanum=0;cout<<"...."<<endl;Sleep(300);
			buyer->sum=0.0;cout<<"....."<<endl;Sleep(300);
			cout<<"����ɹ���"<<endl;
			cout<<"-----------------------------------"<<endl;
			cout<<"�˻���"<<buyer->money<<endl;
			cout<<"-----------------------------------"<<endl;
			cout<<"�������Ҫ������Ʒ������0�������˳���"<<endl;
			getchar();
			if(getchar()=='0')
				shop();
			else
				exitshopping();
		}
	}
	else
		shop();
}
void showbuyer()
{
	system("cls");
	cout<<"������Ϣ"<<endl;
	cout<<"-----------------------------------"<<endl;
	cout<<"�˺ţ�"<<buyer->num<<endl;
	cout<<"�˻�����"<<buyer->name<<endl;
	cout<<"�˻���"<<buyer->money<<endl;
	cout<<"-----------------------------------"<<endl<<endl;
	cout<<"��������������˵�"<<endl;
	getchar();
	getchar();
	shop();
}
void exitshopping()
{
	system("cls");
	cout<<"-----------------------------"<<endl;
	cout<<buyer->name<<" ���ѳɹ��˳�ϵͳ"<<endl;
	cout<<"-----------------------------"<<endl;
	exit(0);
}