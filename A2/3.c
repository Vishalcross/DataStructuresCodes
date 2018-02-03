#include<stdio.h>
#include<string.h>
/*helo
*/
int main(){
    char c='a',prev='a';
    char res[20000];
    int single=0,multi=0,i=0,transit = 0;
    memset(res,0,sizeof(res));
    while(c != '~'){
        scanf("%c",&c);
        if( (c == '/' && prev == '*') && (multi == 1) && (single == 0) ){
            multi = 0;
            c = 0;
        }

        if( (c == '*' && prev == '/') && (multi == 0) && (single == 0) ){
            multi = 1;
            res[i-1] = 0;
            i--;
            transit = 1;
        }

        if( (c == '\n') && (single == 1) && (multi == 0) ){
            single = 0;
            c = 0;
        }

        if( (c == '/' && prev == '/') && (single == 0) && (multi == 0) ){
            single = 1;
            res[i-1] = 0;
            i--;
        }

        if(single == 0 && multi == 0){
            if(c != 0)
                {   if(!transit)
                        res[i++] = c;
                    else transit = 0;
                }
        }
        prev = c;
        //printf("single line %d multi line %d\n",single,multi);
    }
    printf("%s",res);
    return 0;
}

