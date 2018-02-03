#include<stdio.h>
#include<string.h>
int main(){
    char a[2000];
    memset(a,0,sizeof(a));
    char res[2000] = "";
    fgets(a,2000,stdin);
    char c='a';
    int i=0;
    int dump = strlen(a);
    //scanf("%c",&dump);
    while(c != '\n'){
        //if(i>= dump) break;
        c = a[i];
        if(c != '\0'){
            switch(c) {
                //printf("sa");
                case '0': {
                    if(a[i+1] == '0'){
                        printf("0");
                        i+=2;
                    }
                    else{
                        printf(" ");
                        i++;
                    }
                    break;
                }
                //break;
                case '1': {
                    printf("1");
                    i+=2;
                    break;
                }
                //break;
                case '2': {
                    if(a[i+1] == '2'){
                        if(a[i+2] == '2'){
                            if(a[i+3] == '2'){
                                printf("2");
                                i+=4;
                            }
                            else{
                                printf("c");
                                i+=3;
                            }

                        }
                        else{
                            printf("b");
                            i+=2;
                        }
                    }
                    else{
                        printf("a");
                        i++;
                    }
                    break;
                }
                //break;
                case '3': {
                    if(a[i+1] == '3'){
                        if(a[i+2] == '3'){
                            if(a[i+3] == '3'){
                                printf("3");
                                i+=4;
                            }
                            else{
                                printf("f");
                                i+=3;
                            }

                        }
                        else{
                            printf("e");
                            i+=2;
                        }
                    }
                    else{
                        printf("d");
                        i++;
                    }
                    break;
                }
                //break;
                case '4': {
                    if(a[i+1] == '4'){
                        if(a[i+2] == '4'){
                            if(a[i+3] == '4'){
                                printf("4");
                                i+=4;
                            }
                            else{
                                printf("i");
                                i+=3;
                            }

                        }
                        else{
                            printf("h");
                            i+=2;
                        }
                    }
                    else{
                        printf("g");
                        i++;
                    }
                    break;
                }
                //break;
                case '5': {
                    if(a[i+1] == '5'){
                        if(a[i+2] == '5'){
                            if(a[i+3] == '5'){
                                printf("5");
                                i+=4;
                            }
                            else{
                                printf("l");
                                i+=3;
                            }

                        }
                        else{
                            printf("k");
                            i+=2;
                        }
                    }
                    else{
                        printf("j");
                        i++;
                    }
                    break;
                }
                //break;
                case '6': {
                    if(a[i+1] == '6'){
                        if(a[i+2] == '6'){
                            if(a[i+3] == '6'){
                                printf("6");
                                i+=4;
                            }
                            else{
                                printf("o");
                                i+=3;
                            }

                        }
                        else{
                            printf("n");
                            i+=2;
                        }
                    }
                    else{
                        printf("m");
                        i++;
                    }
                    break;
                }
               // break;
                case '7': {
                    if(a[i+1] == '7'){
                        if(a[i+2] == '7'){
                            if(a[i+3] == '7'){
                                if(a[i+4] == '7'){
                                    printf("7");
                                    i+=5;
                                }
                                else{
                                    printf("s");
                                    i+=4;
                                }
                            }
                            else{
                                printf("r");
                                i+=3;
                            }

                        }
                        else{
                            printf("q");
                            i+=2;
                        }
                    }
                    else{
                        printf("p");
                        i++;
                    }
                    break;
                }
                //break;
                case '8': {
                    if(a[i+1] == '8'){
                        if(a[i+2] == '8'){
                            if(a[i+3] == '8'){
                                printf("8");
                                i+=4;
                            }
                            else{
                                printf("v");
                                i+=3;
                            }

                        }
                        else{
                            printf("u");
                            i+=2;
                        }
                    }
                    else{
                        printf("t");
                        i++;
                    }
                    break;
                }
                //break;
                case '9': {
                    if(a[i+1] == '9'){
                        if(a[i+2] == '9'){
                            if(a[i+3] == '9'){
                                if(a[i+4] == '9'){
                                    printf("9");
                                    i+=5;
                                }
                                else{
                                    printf("z");
                                    i+=4;
                                }

                            }
                            else{
                                printf("y");
                                i+=3;
                            }

                        }
                        else{
                            printf("x");
                            i+=2;
                        }
                    }
                    else{
                        printf("w");
                        i++;
                    }
                    break;
                }
                //break;
                case ' ': i++;
                break;
                default : printf("");
            }
        }
        if(i>=dump) break;
    }
    //printf("end");
    return 0;
}
