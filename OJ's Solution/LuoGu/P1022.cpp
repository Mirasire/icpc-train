#include <bits/stdc++.h>
using namespace std;

string str;
int fac=1,quan=0,ans=0;
int ff=1;
char Cans;

bool isDig(const char& c) { return c>='0'&&c<='9'; }

void getInt(int& t) {
	ff = str[t]=='-'? -1:1;
	if(str[t]=='-' || str[t]=='+') t++;
	int rt=0;
	while(t<str.size() && isDig(str[t])) {
		rt = rt*10+(str[t]-'0');
		t++;
	}
	if(!(str[t]=='-' || str[t]=='+' || str[t]=='=') && t<str.size()) {
		if(rt==0) rt=1;
		quan+=fac*ff*rt;
		Cans = str[t];
		t++;
	}
	else ans+=ff*fac*rt;
}

int main() {
	cin >> str;
	int i=0;
	while(i<str.size() && str[i]!='\r') {
		if(str[i]=='=') {
			fac*=-1;
			i++;
		}
		else getInt(i);
	}
	printf("%c=%.3lf",Cans,(1.0*ans)/(-1*quan));
	return 0;
}
