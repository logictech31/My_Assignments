#include <stdio.h>
#include <stdlib.h>

void E();
void EP();
void T();
void TP();
void F();
void advance();

int i=0;
char str[200], tp;

void advance(){
    printf("\nAdvanced");
    i++;
    tp=str[i];
}

void F(){
    if(tp=='i'){
        advance();
    }
    else
    {
        if(tp=='('){
            advance();
            E();
            if(tp==')')
                advance();
        }
        else{
            printf("\n String not accepted");
            exit(1);
        }
    }
}

void E(){
    T();
    EP();
}

void T(){
    F();
    TP();
}

void TP(){
    if(tp=='*'){
        advance();
        F();
        TP();
    }
}

void EP(){
    if(tp=='+'){
        advance();
        T();
        EP();
    }
}


int main(){
    printf("Enter a string: ");
    scanf("%s",&str);
    tp=str[0];
    E();
    printf("\nString accepted"); 
    return 0;
}
