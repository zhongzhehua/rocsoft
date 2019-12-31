#include <iostream>
#include <string.h>
#include <iomanip>			//���λ������
using namespace std;
/**********��Ʒ��**********/
class goods		
{
protected:
	int gnum;
	char gname[255];
	double gprice;
public:
	goods(int num,char *name,double price);
	virtual void show();
	friend double operator + (double x,const goods &y);		//��Ԫ�������������
};

/**********ʳƷ��**********/
class food:public goods		//ʳƷ�๫�м̳���Ʒ��
{
protected:
	char fexp_date[255];		//������
public:
	food(int num,char *name,double price,char *exp_date);
	void show();
};
/**********����Ʒ��**********/
class dailyuse:public goods		//����Ʒ�๫�м̳���Ʒ��
{
protected:
	char dweight[255];		//����
public:
	dailyuse(int num,char *name,double price,char *dweight);
	void show();
};

/**********�ҵ���**********/
class appliances:public goods		//�ҵ��๫�м̳���Ʒ��
{
protected:
	char amodel[255];	//�ͺ�
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