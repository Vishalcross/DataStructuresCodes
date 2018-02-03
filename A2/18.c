#include<stdio.h>
#include<string.h>
int main(){
    char c,lastc;
    c = 'a';
    char res[20000] = "";
    while(c != '\n'){
        scanf("%c",&c);
        if(c != '\n'){
            if(lastc == c){
                strcat(res," ");
            }
            switch(c){
                case ' ': strcat(res,"0");
                break;
                case '0': strcat(res,"00");
                break;
                case '1': strcat(res,"11");
                break;
                case '2': strcat(res,"2222");
                break;
                case '3': strcat(res,"3333");
                break;
                case '4': strcat(res,"4444");
                break;
                case '5': strcat(res,"5555");
                break;
                case '6': strcat(res,"6666");
                break;
                case '7': strcat(res,"77777");
                break;
                case '8': strcat(res,"8888");
                break;
                case '9': strcat(res,"99999");
                break;
                case 'a': strcat(res,"2");
                break;
                case 'b': strcat(res,"22");
                break;
                case 'c': strcat(res,"222");
                break;
                case 'd': strcat(res,"3");
                break;
                case 'e': strcat(res,"33");
                break;
                case 'f': strcat(res,"333");
                break;
                case 'g': strcat(res,"4");
                break;
                case 'h': strcat(res,"44");
                break;
                case 'i': strcat(res,"444");
                break;
                case 'j': strcat(res,"5");
                break;
                case 'k': strcat(res,"55");
                break;
                case 'l': strcat(res,"555");
                break;
                case 'm': strcat(res,"6");
                break;
                case 'n': strcat(res,"66");
                break;
                case 'o': strcat(res,"666");
                break;
                case 'p': strcat(res,"7");
                break;
                case 'q': strcat(res,"77");
                break;
                case 'r': strcat(res,"777");
                break;
                case 's': strcat(res,"7777");
                break;
                case 't': strcat(res,"8");
                break;
                case 'u': strcat(res,"88");
                break;
                case 'v': strcat(res,"888");
                break;
                case 'w': strcat(res,"9");
                break;
                case 'x': strcat(res,"99");
                break;
                case 'y': strcat(res,"999");
                break;
                case 'z': strcat(res,"9999");
                break;
            }
            lastc = c;
        }
    }
    printf("%s",res);
}
