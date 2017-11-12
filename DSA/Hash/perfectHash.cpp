/*Perfect Hashing*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <list>
using namespace std;

class ha
{	
public:
	int a;
	int b;
	int p;
	int m;
	int* numbers;
	ha()
	{
		a=0; b=0; p=0; m=0;
		numbers = NULL;
	}
};

long int hash(int a ,int x ,int b, int p, int m)
{
	return (((a * x) + b) % p) % m;
}

int main()
{
	int diffCount=0;
	int num [10]={1,12,30,4,57,68,7,88,9,10};	//change 10
	int arrCount[20]={0};			//change 20
	list <int> hashList[20]; 		//change 20
	int a,b,p,m;
	a = rand()%10+1;			//change 10
	b = rand()%997;
	p = 997; 
	m = 20; 				//change 20
	cout<<"a = "<<a<<" b = "<<b<<endl;
	for (int i = 0; i < 10; ++i) 		//change 10
	{
		int c = hash(a,num[i],b,p,m);
		cout<<"number "<<num[i]<<" is hashed to array = "<<c<<endl;
		hashList[c].push_back(num[i]);
		arrCount[c]++;
	}
	int count=0;
	for (int i = 0; i < m; ++i) 
	{
		count += arrCount[i]*arrCount[i];
	}

	cout<<"count = "<<count<<endl;

	//if(count<=m)
	//{
		ha* newHashList = (ha*) calloc(20,sizeof(ha));		//change 20

		for (int i = 0; i < 20; ++i) 		//change 20
		{

/*			newHashList[i].numbers = new int ;
		 	list <int> :: iterator k;
			k = hashList[i].begin();
			newHashList[i].numbers[0] = *k;		*/

			//cout<<"array count="<<arrCount[i]<<endl;

			if(arrCount[i]>1)
			{

				cout<<endl<<"the array number is "<<i<<endl;

				for (list<int>::iterator j = hashList[i].begin(); j != hashList[i].end(); ++j) //Numbers to print
				{
/*					recompute:
					//cout<<newCount<<endl;
					newHashList[i].numbers = (int * )calloc(arrCount[i]*arrCount[i],sizeof(int));
					newHashList[i].a = rand()%10+1;
					newHashList[i].b = rand()%997;
					newHashList[i].p = 997;
					newHashList[i].m = arrCount[i]*arrCount[i];
					int d = hash(newHashList[i].a,*j,newHashList[i].b,newHashList[i].p,newHashList[i].m);
					cout<<"d = "<<d<<"\t";
					cout<<"j = "<<*j<<"\t";

					if(newHashList[i].numbers[d]!=0 && newHashList[i].numbers[d]!=*j)
						goto recompute;
					else 
						{
							//newHashList[i].numbers[d] = *j;
							cout<<newHashList[i].numbers[d]<<endl;
						}
*/

					cout<<"number="<<*j<<"\t";
					for (list<int>::iterator n = hashList[i].begin(); n != hashList[i].end(); n++)
					{
						if (abs(*j - *n) > 10)
							diffCount = diffCount+1;
					}
				}
			}		
		
			else 
			{
				if(arrCount[i]==0)
				{
				}
/*				else
				{
					newHashList[i].numbers = new int ;
					list <int> :: iterator k;
					k = hashList[i].begin();
					newHashList[i].numbers[0] = *k;
				} 	*/
			}

		}
	//}
	/*else
	{
		cout<<"Error";
	}*/

		cout<<"Difference Count"<<diffCount<<endl;

}
