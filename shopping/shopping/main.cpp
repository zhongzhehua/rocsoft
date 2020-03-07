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
void loading();			//载入函数
void login();			//登录函数
void shop();			//购物函数
int isuse(int);			//判断用户是否存在
void buyfood();			//购买食品
void buydaily();		//购买日用品
void buyapp();			//购买家电
void shoppingcart();	//购物车
void showbuyer();		//购物者信息
void exitshopping();	//结束退出
int main()
{
	loading();
	login();
	shop();
}
void loading()
{
	int tmpaa;char tmpbb[255];double tmpcc;char tmpdd[255];double tmpee;
/**********食品类构造**********/
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
/**********日用品类构造**********/
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
/**********家电类构造**********/
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
	/**********普通用户类构造**********/
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
	/**********普通用户类构造**********/
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
	cout<<"**********欢迎光临**********"<<endl;
	cout<<"请输入您的账号："<<endl;
	int tmpnum;
	cin>>tmpnum;
	char tmpname[255];
	double tmpmoney;
	double tmpdiscount;
	int buynum;			//序号，大于100为普通用户，小于100为VIP
	buynum=isuse(tmpnum);
	while(buynum==-1)
	{
		cout<<"您输入的账号有误，请重新输入：";
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
	cout<<"登陆成功！"<<endl;
	cout<<"****************************"<<endl;
	Sleep(1000);
	system("cls");
	cout<<"**********欢迎您 "<<buyer->name<<"**********"<<endl;
	cout<<"账户信息"<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<"账号："<<buyer->num<<endl;
	cout<<"账户名："<<buyer->name<<endl;
	cout<<"账户余额："<<buyer->money<<endl;
	cout<<"*******************************"<<endl;
	Sleep(3000);
}
void shop()
{
	system("cls");
	cout<<"**********欢迎光临**********"<<endl;
	cout<<"1.选购食品"<<endl;
	cout<<"----------------------------"<<endl;
	cout<<"2.选购日用品"<<endl;
	cout<<"----------------------------"<<endl;
	cout<<"3.选购家电"<<endl;
	cout<<"----------------------------"<<endl;
	cout<<"4.查看购物车"<<endl;
	cout<<"----------------------------"<<endl;
	cout<<"5.查看个人信息"<<endl;
	cout<<"----------------------------"<<endl;
	cout<<"6.退出"<<endl;
	cout<<"****************************"<<endl;
	cout<<"\n请选择菜单项：";
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
			default:cout<<"输入有误，请重新输入：";
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
	cout<<"食品"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	cout<<setw(4)<<"编号"<<setw(30)<<"品          名"<<setw(15)<<"价格"<<setw(25)<<"保   质   期"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	for(int i=0;i<nfood;i++)
		fo[i]->show();
	cout<<"--------------------------------------------------------------------------"<<endl;
	int bfnum;
	cout<<"请输入商品编号选购商品(输入0退出)：";
	cin>>bfnum;
	while(bfnum!=0)
	{
		while((bfnum-1000)>=nfood || (bfnum-1000)<0)
		{
			cout<<"编号有误，请重新输入：";
			cin>>bfnum;
		}
		buyer->buyfo[buyer->buyfnum]=fo[bfnum-1000];
		cout<<"\n您已成功选购商品："<<endl;
		cout<<"--------------------------------------------------------------------------"<<endl;
		buyer->buyfo[buyer->buyfnum]->show();
		cout<<"--------------------------------------------------------------------------"<<endl;
		buyer->buyfnum++;
		cout<<"请输入商品编号选购商品(输入0退出)：";
		cin>>bfnum;
	}
	shop();
}
void buydaily()
{
	system("cls");
	cout<<"日用品"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	cout<<setw(4)<<"编号"<<setw(30)<<"品          名"<<setw(15)<<"价格"<<setw(25)<<"规        格"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	for(int i=0;i<ndaily;i++)
		da[i]->show();
	cout<<"--------------------------------------------------------------------------"<<endl;
	int bdnum;
	cout<<"请输入商品编号选购商品(输入0退出)：";
	cin>>bdnum;
	while(bdnum!=0)
	{
		while((bdnum-2000)>=ndaily || (bdnum-2000)<0)
		{
			cout<<"编号有误，请重新输入：";
			cin>>bdnum;
		}
		buyer->buyda[buyer->buydnum]=da[bdnum-2000];
		cout<<"\n您已成功选购商品："<<endl;
		cout<<"--------------------------------------------------------------------------"<<endl;
		buyer->buyda[buyer->buydnum]->show();
		cout<<"--------------------------------------------------------------------------"<<endl;
		buyer->buydnum++;
		cout<<"请输入商品编号选购商品(输入0退出)：";	
		cin>>bdnum;
	}
	shop();
}
void buyapp()
{
	system("cls");
	cout<<"家电"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	cout<<setw(4)<<"编号"<<setw(30)<<"品          名"<<setw(15)<<"价格"<<setw(25)<<"型        号"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	for(int i=0;i<napp;i++)
		ap[i]->show();
	cout<<"--------------------------------------------------------------------------"<<endl;
	int banum;
	cout<<"请输入商品编号选购商品(输入0退出)：";
	cin>>banum;
	while(banum!=0)
	{
		while((banum-3000)>=napp || (banum-3000)<0)
		{
			cout<<"编号有误，请重新输入：";
			cin>>banum;
		}
		buyer->buyap[buyer->buyanum]=ap[banum-3000];
		cout<<"\n您已成功选购商品："<<endl;
		cout<<"--------------------------------------------------------------------------"<<endl;
		buyer->buyap[buyer->buyanum]->show();
		cout<<"--------------------------------------------------------------------------"<<endl;
		buyer->buyanum++;
		cout<<"请输入商品编号选购商品(输入0退出)：";
		cin>>banum;
	}
	shop();
}
void shoppingcart()
{
	system("cls");
	cout<<"购物车"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	cout<<"\n您已选购的食品"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	for(int i=0;i<buyer->buyfnum;i++)
		buyer->buyfo[i]->show();
	cout<<"--------------------------------------------------------------------------"<<endl;
	cout<<"\n您已选购的日用品"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	for(int i=0;i<buyer->buydnum;i++)
		buyer->buyda[i]->show();
	cout<<"--------------------------------------------------------------------------"<<endl;
	cout<<"\n您已选购的家电"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	for(int i=0;i<buyer->buyanum;i++)
		buyer->buyap[i]->show();
	cout<<"--------------------------------------------------------------------------"<<endl;
	cout<<"如需要买单请输入0,按回车键返回主菜单"<<endl;
	getchar();
	if(getchar()=='0')
	{
		system("cls");
		cout<<"买单"<<endl;
		cout<<"-----------------------------------"<<endl;
		if(buyer->buyfnum+buyer->buydnum+buyer->buyanum==0)
		{
			cout<<"您还没有选购任何商品"<<endl;
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
		cout<<"账单总金额："<<buyer->sum<<endl;
		cout<<"优惠金额："<<buyer->sum*(1-buyer->discount)<<endl;
		cout<<"-----------------------------------"<<endl;
		cout<<"实际需要支付金额："<<buyer->sum*buyer->discount<<endl;
		cout<<"您的账户余额："<<buyer->money<<endl;
		cout<<"-----------------------------------"<<endl;
		if(buyer->sum>buyer->money)
		{
			cout<<"您的账户余额不足哦！"<<endl;
			cout<<"正在为您清空购物车！"<<endl;
			buyer->buyfnum=0;cout<<"."<<endl;Sleep(300);
			buyer->buydnum=0;cout<<".."<<endl;Sleep(300);
			buyer->buyanum=0;cout<<"..."<<endl;Sleep(300);
			buyer->sum=0.0;cout<<"...."<<endl;Sleep(300);
			cout<<"清空成功！请返回重新选购。"<<endl;
			cout<<"-----------------------------------"<<endl;
			getchar();
			getchar();
			shop();
		}
		else
		{
			cout<<"您的账户余额足够支付本次购物！"<<endl;
			cout<<"正在为您结算！"<<endl;
			buyer->money=buyer->money-buyer->sum*buyer->discount;cout<<"."<<endl;Sleep(300);
			buyer->buyfnum=0;cout<<".."<<endl;Sleep(300);
			buyer->buydnum=0;cout<<"..."<<endl;Sleep(300);
			buyer->buyanum=0;cout<<"...."<<endl;Sleep(300);
			buyer->sum=0.0;cout<<"....."<<endl;Sleep(300);
			cout<<"结算成功！"<<endl;
			cout<<"-----------------------------------"<<endl;
			cout<<"账户余额："<<buyer->money<<endl;
			cout<<"-----------------------------------"<<endl;
			cout<<"如果还需要购买商品请输入0，否则将退出。"<<endl;
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
	cout<<"个人信息"<<endl;
	cout<<"-----------------------------------"<<endl;
	cout<<"账号："<<buyer->num<<endl;
	cout<<"账户名："<<buyer->name<<endl;
	cout<<"账户余额："<<buyer->money<<endl;
	cout<<"-----------------------------------"<<endl<<endl;
	cout<<"按任意键返回主菜单"<<endl;
	getchar();
	getchar();
	shop();
}
void exitshopping()
{
	system("cls");
	cout<<"-----------------------------"<<endl;
	cout<<buyer->name<<" 您已成功退出系统"<<endl;
	cout<<"-----------------------------"<<endl;
	exit(0);
}