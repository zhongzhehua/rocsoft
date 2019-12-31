#include <iostream>
#include <string.h>
#include <iomanip>			//输出位数控制
using namespace std;
/**********商品类**********/
class goods		
{
protected:
	int gnum;
	char gname[255];
	double gprice;
public:
	goods(int num,char *name,double price);
	virtual void show();
	friend double operator + (double x,const goods &y);		//友元函数重载运算符
};

/**********食品类**********/
class food:public goods		//食品类公有继承商品类
{
protected:
	char fexp_date[255];		//保质期
public:
	food(int num,char *name,double price,char *exp_date);
	void show();
};
/**********日用品类**********/
class dailyuse:public goods		//日用品类公有继承商品类
{
protected:
	char dweight[255];		//重量
public:
	dailyuse(int num,char *name,double price,char *dweight);
	void show();
};

/**********家电类**********/
class appliances:public goods		//家电类公有继承商品类
{
protected:
	char amodel[255];	//型号
public:
	appliances(int num,char *name,double price,char *model);
	void show();
};

goods::goods(int num, char *name,double price)
{
	gnum=num;
	strcpy(gname,name);
	gprice=price;
}
food::food(int num,char *name, double price,char *exp_date):goods(num,name,price)
{
	strcpy(fexp_date,exp_date);
}
dailyuse::dailyuse(int num, char *name, double price, char *weight):goods(num,name,price)
{
	strcpy(dweight,weight);
}
appliances::appliances(int num, char *name, double price, char *model):goods(num,name,price)
{
	strcpy(amodel,model);
}

void goods::show()
{
	cout<<setw(4)<<gnum<<setw(30)<<gname<<setw(15)<<gprice;
}
void food::show()
{
	goods::show();
	cout<<setw(25)<<fexp_date<<endl;
}
void dailyuse::show()
{
	goods::show();
	cout<<setw(25)<<dweight<<endl;
}
void appliances::show()
{
	goods::show();
	cout<<setw(25)<<amodel<<endl;
}
double operator + (double x,const goods &y)
{
	return x+y.gprice;
}