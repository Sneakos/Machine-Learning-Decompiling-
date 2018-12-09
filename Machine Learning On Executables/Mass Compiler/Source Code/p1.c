#include <stdlib.h>
#include <string.h>

int main(){
        char str1[20];
        char str2[20];
        char ans[20];

        int i,j,k;
        char c;
        int add = 1;

        scanf("%s",str1);
        scanf("%s",str2);

        for(i=0;i<strlen(str1);i++){
                if(str1[i] == str2[i]){
                        c = str1[i];
                        for(j=0;j<strlen(ans);j++){
                                if(ans[j] == c){
                                        add = 0;
                                }
                        }
                        if(add == 1)
                                ans[strlen(ans)] = c;
                }
                add = 1;
        }
        printf("%s\n",ans);
        printf("%d\n",strlen(ans));
        return 0;
}
