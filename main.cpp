#include<iostream>
#include<cstring>
using namespace std;
int nums[65536];
char cals[65535],c,s[2147483648],nums_char[65536][2147483648];
unsigned short cals_sum=0,nums_sum[65536],nums_sum_sum=0;
int main(){
    cout<<"calculatorMax-cpp enter nothing to quit."<<endl;
    while(true){
        while(cin>>s){//enter nothing to quit.
            for(int i=1;i<=65536;i++){//列表数据清除
                nums_sum[i]=0;
                nums[i]=0;
            }
            for(int i=1;i<=strlen(s);i++){//分拣字符
                if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='%')//是运算符则加入运算字符串
                    cals[++cals_sum]=s[i];
                else nums_char[++nums_sum_sum][++nums_sum[nums_sum_sum]]=s[i];//否则加入整数字符串
            }
            for(int i=1;i<=nums_sum_sum;i++){//数字转化为整数
                for(int j=1;i<=nums_sum[i];j++){
                    nums[i]+=nums_char[i][j]-48;//'1'-48==1
                    nums[i]*=10;//预留给下一次增加
                }
                nums[i]/=10;//不然最后每个整数会多*10
            }
            for(int i=1;i<=nums_sum_sum-1/*不然最后会多一次空计算导致异常*/;i++){//计算
                if(cals[i]=='+') nums[i+1]+=nums[i];//加法
                if(cals[i]=='-') nums[i+1]-=nums[i];//减法
                if(cals[i]=='*') nums[i+1]*=nums[i];//乘法
                if(cals[i]=='/') nums[i+1]/=nums[i];//除法
                if(cals[i]=='%') nums[i+1]%=nums[i];//取模
            }
            cout<<nums[nums_sum_sum]-1<<endl;
        }
        cout<<"Are you sure you wanna quit?(y/n)";
        cin>>c;
        if(c=='y') break;
        else cout<<endl<<"You don't? Well, let's start again."<<endl;
    }
}
