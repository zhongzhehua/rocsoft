#include <iostream>
#include <string.h>
using namespace std;
/**********�û���**********/
class user
{
protected:
	int unum;
	char uname[255];
	double umoney;
public:
	user(int num,char *name,double money);
	int getunum();
	char *getuname();
	double getumoney();
};
/**********��Ա��**********/
class vip:public user		//��Ա�๫�м̳��û���
{
protected:
	double vdiscount;		//�ۿ�
public:
	vip(int num,char *name,double money,double discount);
	double getvdiscount();
};
user::user(int num, char *name, double money)
{
	unum=num;
	strcpy(uname,name);
	umoney=money;
}
vip::vip(int num, char *name, double money, double discount):user(num,name,money)
{
	vdiscount=discount;
}
int user::getunum()
{
	return unum;
}
char *user::getuname()
{
	return uname;
}
double user::getumoney()
{
	return umoney;
}
double vip::getvdiscount()
{
	return vdiscount;
}