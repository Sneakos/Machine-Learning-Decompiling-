#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//23|16|27|8/|35|36|32|12|32|7/3 = 77
//2316278/35363212327/3 == 77
//06251/4526351216334/1 == 79
//xxxxxxxxxxxx == 300
//15362/x4/34253414xxx == 124

int main()
{
    int i;
    char score[50];
    int ret = 0;
    float frame = 1.0;

    printf("Enter Bowling Score Line: ");
    scanf("%s",score);

    for(i=0;i<strlen(score);i++){
        if(frame <= 9){ // rules for the first 9 frames
            if(score[i] == 'x'){// scoring for a strike
                ret += 10;
                if(score[i+1] != 'x')
                    ret+= (score[i+1] - '0'); // return the next throw if it isn't a strike
                else
                    ret += 10;//adds 10 if the next throw is a strike
                if(score[i+2] == 'x')
                    ret += 10;
                else if(score[i+2] == '/')
                    ret += (10-(score[i+1] - '0'));
                else ret += (score[i+2] - '0');;
            }
            else if(score[i] == '/'){ // scoring for a spare
                ret += (10 - (score[i-1] - '0'));
                if(score[i+1] != 'x')
                    ret += (score[i+1] - '0');
                else
                    ret += 10;
            }
            else{
                ret += (score[i] - '0');
            }
        }
        else{//rules for 10th frame
            if(score[i] == 'x')
                ret += 10 ;
            else if(score[i] == '/')
                ret += (10 - (score[i-1] - '0'));
            else
                ret += (score[i] - '0');
        }
        frame += 0.5; // advances frame by a half for 2 throws per frame
        if(score[i] == 'x')
            frame += 0.5;
    }
    printf("Score is: %d",ret);

    return 0;
}
