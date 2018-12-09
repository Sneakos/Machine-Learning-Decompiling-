#include <stdio.h>
#include <stdlib.h>

int grid[30][60];
int cpy[30][60];
char arr[30][60];

int cell_check(int g[30][60], int l, int w){
    int i,j,sum = 0;
    int length = l, width = w;
    for(i=-1;i<=1;i++){
        for(j=-1;j<=1;j++){
            length = l + i;
            width = w + j;
            if(length >=0 && length <=30 && width >= 0 && length <=60){
                sum += g[length][width];
            }
        length = l;
        width = w;
        }
    }
    if(g[l][w] == 1)
        return sum-1;
    else
        return sum;
}

void birth(int g[30][60],int x, int y){
        g[x][y] = 1;
}

void death(int g[30][60],int x, int y){
        g[x][y] = 0;
}
void print_grid(int g[30][60]){
        int width, length;
        for(width = 0; width < 30;width++){
                for(length = 0;length < 60;length++){
                        printf("%d",g[width][length]);
                }
                printf("\n");
        }
}

void char_grid(char a[30][60]){
    int l,w;
    for(w=0;w<30;w++){
        for(l=0;l<60;l++){
            if(grid[w][l] == 1)
                arr[w][l] = '@';
            if(grid[w][l] == 0)
                arr[w][l] = '.';
        }
    }
    for(w=0;w<30;w++){
        for(l=0;l<60;l++){
            printf("%c",arr[w][l]);
        }
        printf("\n");
    }
}

void copy(){
    int l,w;
    for(l=0;l<30;l++){
        for(w=0;w<60;w++){
            grid[l][w] = cpy[l][w];
            cpy[l][w] = 0;
        }
    }
}

void run(){
    int l, w;
    for(l=0;l<30;l++){
        for(w=0;w<60;w++){
            if(grid[l][w] == 1){
                //printf("(1)(%d (%d,%d))\n",cell_check(grid,l,w) - 1,l,w);
                if(cell_check(grid,l,w) < 2)
                    cpy[l][w] = 0;
                else if(cell_check(grid,l,w) > 3)
                    cpy[l][w] = 0;
                else
                    cpy[l][w] = 1;
            }
            else{
                if(cell_check(grid,l,w) == 3){
                    //printf("(0)(%d (%d,%d))\n",cell_check(grid,l,w)-1,l,w);
                    cpy[l][w] = 1;
                }
            }
        }
    }
    printf("\n\n\n");
    copy();
    char_grid(arr);
}

int main(){
        int w,l;
        char fun = 'r';

        FILE *in;
        in = fopen("Life.txt","r");

        for(l=0;l < 30;l++){
                for(w=0;w < 60;w++){
                        grid[l][w] = 0;
                        cpy[l][w] = 0;
                        arr[l][w] = '.';
                }
        }

        fscanf(in,"%d %d",&w,&l);
        while(!feof(in)){
                birth(grid,l,w);
                birth(cpy,l,w);
                fscanf(in,"%d %d",&w,&l);
        }

        char_grid(arr);

        printf("Enter s to stop or ENTER to progress:");
        scanf("%c", &fun);
        while(fun != 's'){
            run();
            printf("Enter s to stop or ENTER to progress:");
            scanf("%c", &fun);
        }

        return 0;
}
