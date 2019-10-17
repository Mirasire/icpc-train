#include <cstdio>

int main(){
    int n;
    int Arr[10];
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%1d",arr+i);
    for(int i=1; i<10; i++) scanf("%d",Arr+i);
    for(int i=0; i<n; i++){
        if(Arr[arr[i]] > arr[i]){
            for(int j=i; j<n; j++){
                if(Arr[arr[j]] < arr[j]) break;
                else arr[j] = Arr[arr[j]]; 
            }
            break;
        }
    }
    for(int i=0; i<n; i++) printf("%d",arr[i]);
    printf("\n");
    return 0;
}
