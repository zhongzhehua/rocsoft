#include <iostream>
#include <string.h>
using namespace std;
#define MAX_GOODS 1000
class shopper
{
public:
	int num;
	char name[255];
	double money;
	double discount;
	int buyfnum,buydnum,buyanum;
	double sum;
	food *buyfo[MAX_GOODS];
	dailyuse *buyda[MAX_GOODS];
	appliances *buyap[MAX_GOODS];
	shopper(int snum,char *sname,double smoney,double sdiscount=1);
};
shopper::shopper(int snum,char *sname,double smoney,double sdiscount)
{
	num=snum;
	strcpy(name,sname);
	money=smoney;
	discount=sdiscount;
	buyfnum=0;
	buydnum=0;
	buyanum=0;
	sum=0.0;
}