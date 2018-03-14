#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define modulo 1000000007
long long int modMultiply(int a, int b){
    printf("Solving for modMultiply\n");
    return ((a%modulo)*(b%modulo))%modulo;
}

void extendedEuclidean(long long int a, long long int b, long long int* x, long long int* y) {
    if(b == 0){
        *x = 1;
        *y = 0;
        printf("Solving for extendedEuclidean\n");
        return;
    }
    long long int x1, y1;
    extendedEuclidean(b,a%b,&x1,&y1);
    *x = y1;
    *y = x1 - (a/b)*y1;
}

long long int findInverse(long long int a){
    printf("Solving for inverse\n");

    long long int x, y;
    extendedEuclidean(a,modulo,&x,&y);
    if(x<0){
        x = (x%modulo + modulo)%modulo;
    }
    return x;
}

long long int solveForX(long long int a, long long int b){
    printf("Solving for X\n");
    long long int inverse = findInverse(b);
    printf("%lld is the inverse\n",inverse);
    return modMultiply(a,inverse);
}
int main(){
    char alphabet[26], alphabetMod[26];
    memset(alphabet,0,sizeof(alphabet));
    memset(alphabetMod,0,sizeof(alphabetMod));
    char inputString[1000];
    scanf("%s", inputString);
    int t;
    scanf("%d",&t);
    while(t--){
        int l,r,sum=0;
        scanf("%d %d",&l,&r);
        for(int i=l-1;i<r;i++){
            alphabet[inputString[i] - 97] ++;
        }
        printf("\n");
        for(int i=0;i<26;i++){
            alphabetMod[i] = alphabet[i]%2;
            alphabet[i] /= 2;
            sum += alphabet[i];
        }
        for(int i=0;i<26;i++) printf("%c %d %d ",i+97,alphabet[i],alphabetMod[i]);
        printf("\n%d\n",sum);
        long long int numerator=1, denominator=1;
        while(sum>0){
            printf("solving for numerator\n");
            numerator = modMultiply(numerator,sum);
            sum--;
        }
        for(int i=0;i<26;i++){
            printf("solving for denominator\n");
            while(alphabet[i] > 0){
                denominator = modMultiply(denominator,alphabet[i]);
                alphabet[i]--;
            }
        }
        int count = 0;
        long long int answer = 0;
        for(int i=0;i<26;i++){
            count += alphabetMod[i];
        }
        answer = solveForX(numerator,denominator);
                printf("Vars are %lld %lld %lld\n",answer,numerator,denominator);
        answer = modMultiply(answer,count);
                printf("Vars are %lld %d\n",answer,count);
        printf("Answer is %lld\n",answer);
    }
    return 0;
}
