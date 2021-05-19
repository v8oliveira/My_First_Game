// A simple game of rock-paper-scissors. With single and multi-player option.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;


int main(void){
    const char *options[3] = {"Rock", "Paper", "Scissor"};
    int player1,player2;
    int victoryp1=0, victoryp2 = 0;

    printf("Welcome to Rock-Paper-Scissors game!\n\n");
    printf("Choose one option:\n0 - Rock;\n1 - Paper\n2 - Scissor\n\nPress 'q' to quit\n\n");
    scanf("%d", &player1);

    while(player1 != 'q'){
        srand((unsigned)time(0));   //Reset seed to generate different random numbers;
        player2 = rand()%3;     //Generates random numbers between 0-2

        if(player1 != 0 && player1 != 1 && player1 !=2)
            goto ERROR;

        printf("\n\nPLAYER 1(%d)        PLAYER 2(%d)\n  %s          %s\n        ", victoryp1,victoryp2,options[player1], options[player2]);

        switch (player1)
        {
        case 0:
            if(player2 == 0)    //Rock - Rock
                printf("It's a draw! Let's try again!\n\n");
            else if(player2 == 1) {  //Rock - Paper
                printf("Player 2 won!\n\n");
                victoryp2++;
            }
            else{    //Rock - Scissor
                printf("Player 1 won!\n\n");
                victoryp1++;
            }
            break;

        case 1:            
            if(player2 == 0){    //Paper - Rock
                printf("Player 1 won!\n\n");
                victoryp1++;
            }
            else if(player2 == 1)   //Paper - Paper
                printf("It's a draw! Let's try again!\n\n");
            else{    //Paper - Scissor
                printf("Player 2 won!\n\n");
                victoryp2++;
            }
            break;

        case 2:
            if(player2 == 0){    //Scissor - Rock
                printf("Player 2 won!\n\n");
                victoryp2++;
            }
            else if(player2 == 1){   //Scissor - Paper
                printf("Player 1 won!\n\n");
                victoryp1++;
            }
            else    //Scissor - Scissor
                printf("It's a draw! Let's try again!\n\n");
            break;

ERROR:  default:
            printf("Not valid!\nRemember:\n0 - Rock;\n1 - Paper\n2 - Scissor\n\n");
        }  
        
        scanf("%d", &player1);
    }
    
    system("pause");

return 0;
} 