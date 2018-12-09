#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fill_array(char array[100][30],char buff[], int row){
        int i;
        for(i=0;i<strlen(buff);i++){
                strcpy(array[row],buff);
        }
}

void sort(char array[100][30], int N){
        char temp[30];
        int i,j;
        for(i=0;i<N;i++){
                for(j=0;j<(N-1-i);j++){
                        if(strcmp(array[j],array[j+1]) > 0){
                                strcpy(temp,array[j]);
                                strcpy(array[j],array[j+1]);
                                strcpy(array[j+1], temp);
                        }
                }
        }
}

int r_count(char word[]){
        int i;
        int count = 0;
        for(i=0;i<strlen(word);i++){
                if(word[i] == 'r' || word[i] == 'R'){
                        count++;
                }
        }
        return count;
}

int main(int argc, char *argv[]){
        char words[100][30];
        char buffer[30];
        char temp[30];
        int row = 0;
        int r = 0;
        int i,j;

        if(argc < 3){
                printf("The proper usage is ./a.out input_file output_file\n");
                return 0;
        }

        FILE *file_in;
        FILE *file_out;

        file_in = fopen(argv[1],"r");
        file_out = fopen(argv[2],"w");

        if(file_in == NULL){
                printf("The file |%s| was not found\n",argv[1]);
                return(0);
        }


        fgets(buffer,30,file_in);

        while(! feof(file_in)){//filling array
                fill_array(words,buffer,row);
                r = r + r_count(buffer);
                fgets(buffer,30,file_in);
                row++;
        }

        sort(words,row);
        for(i=0;i<row;i++){
                fprintf(file_out,"%2d) %s",i+1,words[i]);
        }
        printf("Total words %d\n", row);
        printf("First word: %s",words[0]);
        printf("Last word: %s",words[row-1]);
        printf("Total 'r' count: %d\n",r);

        return 0;
}
