#include <iostream>
using namespace std;

long long M;

long long int pord(long long int a,long long int n)
{
	long long out = 1;
	while(n)
    {
    	if(n%2) out = (out*a) % M;
    	a = (a * a) % M;
    	n /= 2;
    }
    return out;
}

int main()
{
    long long a,b,c;
    cin >> a >> b >> c >> M;
    return 0;
}
