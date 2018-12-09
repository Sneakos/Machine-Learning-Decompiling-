#include <stdio.h>
#include <stdlib.h>

int countSpaces(char str[]){
    int i;
    int sp = 0;
    for(i=0;i<strlen(str);i++){
        if(str[i] == ' '){
           sp++;
        }
    }
    return sp;
}

int main()
{
    int x = 0;
    char word[50];
    fgets(word,50,stdin);
    x = countSpaces(word);
    printf("There are %d spaces" , x);
    return 0;
}
