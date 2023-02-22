#include <iostream>
using namespace std;

void sort_for_me(int profit[],int weight[],int ratio[],int size){
    int arr[size][3]={},temp_pro=0,temp_weight=0,temp_ratio=0;
    for(int i=0;i<size;i++){
        arr[i][1]=ratio[i];
        arr[i][2]=profit[i];
        arr[i][3]=weight[i];
    }
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;i++){
            if(arr[i][1]<arr[i+1][1]){
                temp_pro=arr[i][2];
                arr[i][2]=arr[i+1][2];
                arr[i+1][2]=temp_pro;
                
                temp_weight=arr[i][1];
                arr[i][1]=arr[i+1][1];
                arr[i+1][1]=temp_weight;
                
                temp_ratio=arr[i][3];
                arr[i][3]=arr[i+1][3];
                arr[i+1][3]=temp_ratio;
            }
        }
    }
    for(int i=0;i<size;i++){
        ratio[i]=arr[i][1];
        profit[i]=arr[i][2];
        weight[i]=arr[i][3];
    }
    
}
int main()
{
    int weight[]={10, 30, 20},profit[]={60, 120, 100},N=50;
    int profit_main=0,weightused=N,arr_profit[3]={},size=sizeof(weight) / sizeof(int);
    for(int i=0;i<size;i++){
        arr_profit[i]=int(profit[i]/weight[i]);
    }
    sort_for_me(profit,weight,arr_profit,size);
    for(int i=0;i<size;i++){
        if(weight[i]<=weightused){
            profit_main=profit_main+profit[i];
            weightused=weightused-weight[i];
            cout<<"profit after using weight :-"<<"\t"<<profit_main<<"\t"<<weightused<<"\n";
        }
        else{
            if(weightused!=0){
                profit_main=profit_main+arr_profit[i]*weightused;
                cout<<"profit after using weight :-"<<"\t"<<profit_main<<"\t"<<weightused<<"\n";
            }
        }
    }
    cout<<"Total Profit:-"<<"\t"<<profit_main;
    
    return 0;
}
