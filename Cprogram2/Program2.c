#include <stdio.h>


void calculate_score(int score){
    
    for (int conversion=0; conversion <= score/8;conversion++){        // The max amount of TD + 2pt is the score/8 
        for (int extra=0; extra <= (score-conversion*8)/7;extra++){  // The max amount of TD + FG is the (score-conversion points) divided by 7
            for (int touchdown=0; touchdown<= (score-(conversion*8)-(extra*7))/6;touchdown++){
                for (int fieldGoal=0; fieldGoal <= (score-(conversion*8)-(extra*7)-(touchdown*6))/3;fieldGoal++){
                    for (int safety=0; safety<= (score-(conversion*8)-(extra*7)-(touchdown*6)-(fieldGoal*3))/2;safety++){
                        int combinedScore = (conversion*8) + (extra*7) + (touchdown*6) + (fieldGoal*3) + (safety*2);

                        /* This chain is followed all the way down from TD + 2pt to safeties.
                        It checks all possible combinations of scores based off of the previous values
                        passed in via the other for loops. If the combined score (which is all of
                        the score points multiplied by the times each score happened) is equal to
                        the score passed in by the user, then we have found a possible combination.
                        */

                        if (score == combinedScore){
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",conversion,extra,touchdown,fieldGoal,safety);
                        }
                    }
                }
            }
        }
    }
}

    
int main(){
    int score,safety,fieldGoal,touchdown,extra,conversion;  // Initialize variables to increment in the calculate score function

    printf("Enter 0 or 1 to STOP\n");   // Print info to the terminal for the user
    printf("Enter the NFL score: ");    // Prompt to enter info
    scanf("%d",&score);  // Scanf to store the user input

    if (score > 1 ){    // Checks the first time the score is put in, and runs if it's greater than 1
        while(score > 1){   // Runs as long as the score is greater than 1
            calculate_score(score);   // Pass in the score
            // The function will decrement the score to find the solutions

            printf("Enter 0 or 1 to STOP\n");   // Print info to the terminal for the user
            printf("Enter the NFL score: ");    // Prompt to enter info
            scanf("%d",&score);  // Scanf to store the user input
        }
    }

    if (score <= 1){    // Stops the program if the score is less than or equal to 1
        printf("Ending the Program");   // Print statement telling the user that the program has ended
    }
}