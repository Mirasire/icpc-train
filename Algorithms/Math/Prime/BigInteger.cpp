
struct BigInterger{
    static const int BASE = 1000000000;
    static const WIDTH = 8;
    vector<int> s;

    BigInterger(long long num = 0) { *this = num;}
    //Operator The =
    BigInterger operator = (long long num) {
        s.clear(); //vector's clear 函数
        do{
            s.push_back(num % BASE);
            num /= BASE;
        } while(num > 0);
        return *this;
    }
    BigInterger operator = (const string &str){
        s.clear();
        int x,len = (str.length() - 1)/WIDTH +1;
        for(int i=0; i<len; i++){
            int end = str.length() - i*WIDTH;
            int start = maxn(0, end - WIDTH);
            sscanf(str.substr(start,end-start).c_str(),"%d",&x);
            s.push_back(x);
        }
        return *this;
    }

