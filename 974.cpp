#include<cstdio>
int main(){
    int kaprekar[]={1,9,45,55,99,297,703,999,2223,2728,4879,4950,5050,5292,7272,7777,9999,17344,22222,38962};
    int len=20;
    int i,z,test;
    scanf("%d",&test);
    for(z=1;z<=test;z++){
                         int lower,upper,cnt=0;
                         scanf("%d%d",&lower,&upper);
                         printf("case #%d\n",z);
                         for(i=1;i<len;i++){
                                             if(kaprekar[i]>=lower && kaprekar[i]<=upper){
                                                                    printf("%d\n",kaprekar[i]);
                                                                    cnt++;
                                             }
                         }
                         if(cnt==0)
                                   printf("no kaprekar numbers\n");
                         if(z!=test)
                                    printf("\n");
    }
    return 0;
}
