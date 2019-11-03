//Accept
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

const int maxn = 1e3+100;
string code,ein;
vector<string> line[maxn];
int most[maxn];

void prt(int l) {
	for(int i=0; i<l; i++) {
		int end = line[i].size();
		for(int j=0; j<end; j++) {
			printf("%s",line[i][j].c_str());
			if(j!=(end-1))
				for(int k=0; k<(most[j]-line[i][j].size()+1); k++) putchar(' ');
			else 
				putchar('\n');
		}
	}
}

int main() {
	int cnt = 0,l=0;
	while(getline(cin,code)) {
		istringstream in(code); //learned
		int cnt = 0;
		while(in >> ein) {
			line[l].push_back(ein);
			most[cnt] = max(most[cnt],(int)ein.size());
			cnt++;
		}
		l++;
	}
	prt(l);
	return 0;
}
