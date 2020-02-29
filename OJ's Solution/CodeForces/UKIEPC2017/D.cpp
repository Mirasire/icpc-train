#include<iostream>
#include <limits.h>
#include<memory.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<string>
#include<map>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1000005;
map<string, int>p;
string s, t;

void bb(void) {
	for (int i = t.length() - 1; i >= 0; i--)
	{
		if (t[i] != s[i])
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (s[j] == t[i] && t[j] != s[j])
				{
					if (s[i] == t[j])
					{
						swap(s[i], s[j]);
						cout << i + 1 << " " << j + 1 << endl;
						break;
					}
				}
 
			}
		}
	}
    return;
}

int main()
{
	cin >> s;
	t = s;
	sort(s.begin(), s.end());
    bb();
	for (int i = t.length() - 1; i >= 0; i--)
	{
		if (t[i] != s[i])
		{
            int temp = -1;
			for (int j = i - 1; j >= 0; j--)
			{
				if (t[i]==s[j] && t[j] != s[j])
				{
					temp = j;
                    break;
				}
			}
            if(temp != -1) {
                swap(s[i], s[temp]);
                cout << i + 1 << " " << temp + 1 << endl;
                bb();
            }
			//cout << "bianhuan:" << s << endl;
		}
	}
    return 0;
}

