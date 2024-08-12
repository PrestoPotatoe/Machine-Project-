/******************************************************************************
This is to certify that this project is my own work, based on my personal
efforts in studying and applying the concepts learned. I have constructed
the functions and their respective algorithms and corresponding code by
myself. The program was run, tested, and debugged by my own efforts. I
further certify that I have not copied in part or whole or otherwise
plagiarized the work of other students and/or persons.

Prestoza, Andrea Mae J. - 12314994 - S15
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*******************************************************
Function : int rollaDice()
Description : Rolls a value between 1 and 6
Precondition(s) : Its called in another function based on how many tiles are available
Parameters : None
Return Value : A value between 1 - 6
*******************************************************/
int rollaDice() {
     return rand() % 6 + 1; // = 1-6 sum
}

/*******************************************************
Function : int rollaDiceTwice()
Description : Rolls a value between 2 and 12
Precondition(s) : Its called in another function based on how many tiles are available
Parameters : None
Return Value : A value between 2 - 12
*******************************************************/
int rollaDiceTwice() {
     return (rand() % 6 + 1) + (rand() % 6 + 1); // = 2-12 sum 
}

/*******************************************************
Function : int rollaDiceThrice()
Description : Rolls a value between 3 and 18
Precondition(s) : Its called in another function based on how many tiles are available
Parameters : None
Return Value : A value between 3 - 18
*******************************************************/
int rollaDiceThrice() {
     return (rand() % 6 + 1) + (rand() % 6 + 1) + (rand() % 6 + 1); // = 3-18 sum 
}

/*******************************************************
Function : int checkHowManyDice
Description : Returns a dice value of how many dice can be rolled based on how many tiles are available
Precondition(s) : Tiles must be declared and updated by each turn
Parameters : The tile variables
Return Value : A dice quantity value between 1 and 3
*******************************************************/
int checkHowManyDice(int *tile01, int *tile02, int *tile03, int *tile04, int *tile05, int *tile06,
                     int *tile07, int *tile08, int *tile09, int *tile10, int *tile11, int *tile12,
                     int *tile13, int *tile14, int *tile15, int *tile16, int *tile17, int *tile18) {

    // Player can choose between rolling 1 || 2 || 3 dice if tiles 7 through 18 are closed already
    if (*tile07 == 0 && *tile08 == 0 && *tile09 == 0 && *tile10 == 0 && *tile11 == 0 && *tile12 ==0
             && *tile13 == 0 && *tile14 == 0 && *tile15 == 0 && *tile16 == 0 && *tile17 == 0 && *tile18 == 0)
    {
        return 1;
    }
    
    // Player can choose between rolling 2 || 3 dice if tiles 13 through 18 are closed already
    else if (*tile13 == 0 && *tile14 == 0 && *tile15 == 0 && *tile16 == 0 && *tile17 == 0 && *tile18 == 0)
    {
        return 2; 
    }

    // Otherwise, if any number from 1 through 18 are available, player must roll 3 dice by default
    else
    {
        return 3;
    }
}

/*******************************************************
Function : void showGridPlayerOne
Description : Prints the currently updated grid of Player One (Gojo)
Precondition(s) : Tiles must be declared and updated by each turn
Parameters : The tile variables
Return Value : The updated grid after each move :)
*******************************************************/
void showGridPlayerOne (int *nOneTile01, int *nOneTile02, int *nOneTile03, int *nOneTile04, int *nOneTile05, int *nOneTile06,
                        int *nOneTile07, int *nOneTile08, int *nOneTile09, int *nOneTile10, int *nOneTile11, int *nOneTile12,
                        int *nOneTile13, int *nOneTile14, int *nOneTile15, int *nOneTile16, int *nOneTile17, int *nOneTile18) {
     //printed with -02- included so that the tiles take up two spaces
     //this is done so that the tiles are aligned for both one-digit and two-digit numbers ex. [01] [10]
     printf("[%02d] [%02d] [%02d] [%02d] [%02d] [%02d]\n", *nOneTile01, *nOneTile02, *nOneTile03, *nOneTile04, *nOneTile05, *nOneTile06);
     printf("[%02d] [%02d] [%02d] [%02d] [%02d] [%02d]\n", *nOneTile07, *nOneTile08, *nOneTile09, *nOneTile10, *nOneTile11, *nOneTile12);
     printf("[%02d] [%02d] [%02d] [%02d] [%02d] [%02d]\n", *nOneTile13, *nOneTile14, *nOneTile15, *nOneTile16, *nOneTile17, *nOneTile18);
}

/*******************************************************
Function : void showGridPlayerTwo
Description : Prints the currently updated grid of Player One (Sukuna)
Precondition(s) : Tiles must be declared and updated by each turn
Parameters : The tile variables
Return Value : The updated grid after each move :)
*******************************************************/
void showGridPlayerTwo (int *nTwoTile01, int *nTwoTile02, int *nTwoTile03, int *nTwoTile04, int *nTwoTile05, int *nTwoTile06,
                        int *nTwoTile07, int *nTwoTile08, int *nTwoTile09, int *nTwoTile10, int *nTwoTile11, int *nTwoTile12,
                        int *nTwoTile13, int *nTwoTile14, int *nTwoTile15, int *nTwoTile16, int *nTwoTile17, int *nTwoTile18) {
     printf("[%02d] [%02d] [%02d] [%02d] [%02d] [%02d]\n", *nTwoTile01, *nTwoTile02, *nTwoTile03, *nTwoTile04, *nTwoTile05, *nTwoTile06);
     printf("[%02d] [%02d] [%02d] [%02d] [%02d] [%02d]\n", *nTwoTile07, *nTwoTile08, *nTwoTile09, *nTwoTile10, *nTwoTile11, *nTwoTile12);
     printf("[%02d] [%02d] [%02d] [%02d] [%02d] [%02d]\n", *nTwoTile13, *nTwoTile14, *nTwoTile15, *nTwoTile16, *nTwoTile17, *nTwoTile18);
}

/*******************************************************
Function : int nChosenTileForPlayerOne
Description : The updater for the tile variables for Player One
Precondition(s) : An input meant to be the chosen tile for it to be shut down
Parameters : The tile variables and the chosen tile
Return Value : Returns 0 if an available tile is chosen
*******************************************************/
void nChosenTileForPlayerOne (int nChosenTile, int *nOneTile01, int *nOneTile02, int *nOneTile03, int *nOneTile04, int *nOneTile05, int *nOneTile06,
                                              int *nOneTile07, int *nOneTile08, int *nOneTile09, int *nOneTile10, int *nOneTile11, int *nOneTile12,
                                              int *nOneTile13, int *nOneTile14, int *nOneTile15, int *nOneTile16, int *nOneTile17, int *nOneTile18) {
         if (nChosenTile == 1)  { *nOneTile01 = 0; } else if (nChosenTile == 2)  { *nOneTile02 = 0; } else if (nChosenTile == 3)  { *nOneTile03 = 0; }
    else if (nChosenTile == 4)  { *nOneTile04 = 0; } else if (nChosenTile == 5)  { *nOneTile05 = 0; } else if (nChosenTile == 6)  { *nOneTile06 = 0; } else if (nChosenTile == 7) { *nOneTile07 = 0; }
    else if (nChosenTile == 8)  { *nOneTile08 = 0; } else if (nChosenTile == 9)  { *nOneTile09 = 0; } else if (nChosenTile == 10) { *nOneTile10 = 0; } else if (nChosenTile == 11) { *nOneTile11 = 0; }
    else if (nChosenTile == 12) { *nOneTile12 = 0; } else if (nChosenTile == 13) { *nOneTile13 = 0; } else if (nChosenTile == 14) { *nOneTile14 = 0; } else if (nChosenTile == 15) { *nOneTile15 = 0; }
    else if (nChosenTile == 16) { *nOneTile16 = 0; } else if (nChosenTile == 17) { *nOneTile17 = 0; } else if (nChosenTile == 18) { *nOneTile18 = 0; }
}

/*******************************************************
Function : int nChosenTileForPlayerTwo
Description : The updater for the tile variables for Player Two
Precondition(s) : An input meant to be the chosen tile for it to be shut down
Parameters : The tile variables and the chosen tile
Return Value : Returns 0 if an available tile is chosen
*******************************************************/
void nChosenTileForPlayerTwo (int nChosenTile, int *nTwoTile01, int *nTwoTile02, int *nTwoTile03, int *nTwoTile04, int *nTwoTile05, int *nTwoTile06,
                                              int *nTwoTile07, int *nTwoTile08, int *nTwoTile09, int *nTwoTile10, int *nTwoTile11, int *nTwoTile12,
                                              int *nTwoTile13, int *nTwoTile14, int *nTwoTile15, int *nTwoTile16, int *nTwoTile17, int *nTwoTile18) {
         if (nChosenTile == 1)  { *nTwoTile01 = 0; } else if (nChosenTile == 2)  { *nTwoTile02 = 0; } else if (nChosenTile == 3)  { *nTwoTile03 = 0; }
    else if (nChosenTile == 4)  { *nTwoTile04 = 0; } else if (nChosenTile == 5)  { *nTwoTile05 = 0; } else if (nChosenTile == 6)  { *nTwoTile06 = 0; } else if (nChosenTile == 7) { *nTwoTile07 = 0; }
    else if (nChosenTile == 8)  { *nTwoTile08 = 0; } else if (nChosenTile == 9)  { *nTwoTile09 = 0; } else if (nChosenTile == 10) { *nTwoTile10 = 0; } else if (nChosenTile == 11) { *nTwoTile11 = 0; }
    else if (nChosenTile == 12) { *nTwoTile12 = 0; } else if (nChosenTile == 13) { *nTwoTile13 = 0; } else if (nChosenTile == 14) { *nTwoTile14 = 0; } else if (nChosenTile == 15) { *nTwoTile15 = 0; }
    else if (nChosenTile == 16) { *nTwoTile16 = 0; } else if (nChosenTile == 17) { *nTwoTile17 = 0; } else if (nChosenTile == 18) { *nTwoTile18 = 0; }
}

/*******************************************************
Function : int isChosenTileValidOne
Description : If the input doesn't match any of the tiles, it returns a value of 0 to the inputted tile value
Precondition(s) : A chosen tile value must be inputted + the tile variables for player one must be declared and updated
Parameters : Tile input + tile variables
Return Value : Returns 0 to the tile input value if it satisfies the condition that it matches no available tiles
*******************************************************/
int isChosenTileValidOne (int *nChosenTile, int *nOneTile01, int *nOneTile02, int *nOneTile03, int *nOneTile04, int *nOneTile05, int *nOneTile06,
                                           int *nOneTile07, int *nOneTile08, int *nOneTile09, int *nOneTile10, int *nOneTile11, int *nOneTile12,
                                           int *nOneTile13, int *nOneTile14, int *nOneTile15, int *nOneTile16, int *nOneTile17, int *nOneTile18) {
    if (*nChosenTile != *nOneTile01 && *nChosenTile != *nOneTile02 && *nChosenTile != *nOneTile03 && *nChosenTile != *nOneTile04 &&
        *nChosenTile != *nOneTile05 && *nChosenTile != *nOneTile06 && *nChosenTile != *nOneTile07 && *nChosenTile != *nOneTile08 &&
        *nChosenTile != *nOneTile09 && *nChosenTile != *nOneTile10 && *nChosenTile != *nOneTile11 && *nChosenTile != *nOneTile12 &&
        *nChosenTile != *nOneTile13 && *nChosenTile != *nOneTile14 && *nChosenTile != *nOneTile15 && *nChosenTile != *nOneTile16 &&
        *nChosenTile != *nOneTile17 && *nChosenTile != *nOneTile18) {
        
        *nChosenTile = 0;
    }

     return *nChosenTile;
}

/*******************************************************
Function : int isChosenTileValidTwo
Description : If the input doesn't match any of the tiles, it returns a value of 0 to the inputted tile value
Precondition(s) : A chosen tile value must be inputted + the tile variables for player two must be declared and updated
Parameters : Tile input + tile variables
Return Value : Returns 0 to the tile input value if it satisfies the condition that it matches no available tiles
*******************************************************/
int isChosenTileValidTwo (int *nChosenTile, int *nTwoTile01, int *nTwoTile02, int *nTwoTile03, int *nTwoTile04, int *nTwoTile05, int *nTwoTile06,
                                           int *nTwoTile07, int *nTwoTile08, int *nTwoTile09, int *nTwoTile10, int *nTwoTile11, int *nTwoTile12,
                                           int *nTwoTile13, int *nTwoTile14, int *nTwoTile15, int *nTwoTile16, int *nTwoTile17, int *nTwoTile18) {
    if (*nChosenTile != *nTwoTile01 && *nChosenTile != *nTwoTile02 && *nChosenTile != *nTwoTile03 && *nChosenTile != *nTwoTile04 && *nChosenTile != *nTwoTile05 &&
        *nChosenTile != *nTwoTile06 && *nChosenTile != *nTwoTile07 && *nChosenTile != *nTwoTile08 && *nChosenTile != *nTwoTile09 && *nChosenTile != *nTwoTile10 &&
        *nChosenTile != *nTwoTile11 && *nChosenTile != *nTwoTile12 && *nChosenTile != *nTwoTile13 && *nChosenTile != *nTwoTile14 && *nChosenTile != *nTwoTile15 &&
        *nChosenTile != *nTwoTile16 && *nChosenTile != *nTwoTile17 && *nChosenTile != *nTwoTile18) {
            
        *nChosenTile = 0;
    }

    return *nChosenTile;
}

/*******************************************************
Function : void shutTheBox
Description : If all tiles are closed, it prints a special message that they win immediately
Precondition(s) : Player score must be zero
Parameters : Player score
Return Value : Prints that the current player is the winner
*******************************************************/
void shutTheBox (int nPlayerScore) {
    if (nPlayerScore == 0)
    {
        printf("\n[SPECIAL FEATURE] Sorcerer! You have closed all your tiles and shut the box!\n");
        printf("[DOMAIN EXPANSION ACTIVATION] Riyoiki Tenkai!\n\n");
        printf("\n\nY O U    W I N ! ! !\n");

    }
}

/*******************************************************
Function : int calculateScoreForPlayerOne
Description : Returns a score value from the remaining open tiles
Precondition(s) : All tiles are declared and updated
Parameters : The tile variables
Return Value : The score for player one by the end of his turn
*******************************************************/
int calculateScoreForPlayerOne(int *nOneTile01, int *nOneTile02, int *nOneTile03, int *nOneTile04, int *nOneTile05, int *nOneTile06,
                               int *nOneTile07, int *nOneTile08, int *nOneTile09, int *nOneTile10, int *nOneTile11, int *nOneTile12,
                               int *nOneTile13, int *nOneTile14, int *nOneTile15, int *nOneTile16, int *nOneTile17, int *nOneTile18) {
    int ScoreOne;
    return ScoreOne = (*nOneTile01 + *nOneTile02 + *nOneTile03 + *nOneTile04 + *nOneTile05 + *nOneTile06 +
           *nOneTile07 + *nOneTile08 + *nOneTile09 + *nOneTile10 + *nOneTile11 + *nOneTile12 +
           *nOneTile13 + *nOneTile14 + *nOneTile15 + *nOneTile16 + *nOneTile17 + *nOneTile18);
}

/*******************************************************
Function : int calculateScoreForPlayerTwo
Description : Returns a score value from the remaining open tiles
Precondition(s) : All tiles are declared and updated
Parameters : The tile variables
Return Value : The score for player two by the end of his turn
*******************************************************/
int calculateScoreForPlayerTwo(int *nTwoTile01, int *nTwoTile02, int *nTwoTile03, int *nTwoTile04, int *nTwoTile05, int *nTwoTile06,
                               int *nTwoTile07, int *nTwoTile08, int *nTwoTile09, int *nTwoTile10, int *nTwoTile11, int *nTwoTile12,
                               int *nTwoTile13, int *nTwoTile14, int *nTwoTile15, int *nTwoTile16, int *nTwoTile17, int *nTwoTile18) {
    int ScoreTwo;
    return ScoreTwo = (*nTwoTile01 + *nTwoTile02 + *nTwoTile03 + *nTwoTile04 + *nTwoTile05 + *nTwoTile06 +
           *nTwoTile07 + *nTwoTile08 + *nTwoTile09 + *nTwoTile10 + *nTwoTile11 + *nTwoTile12 +
           *nTwoTile13 + *nTwoTile14 + *nTwoTile15 + *nTwoTile16 + *nTwoTile17 + *nTwoTile18);
}

/*******************************************************
Function : void endOfGame
Description : Prints both players' scores and determines who is the winner based on those scores
Precondition(s) : Scores must be calculated through the calculateScoreFor.. function for each player
Parameters : The two scores from the two players
Return Value : Prints the scores for both + who is the winner
*******************************************************/
void endOfGame(int nPlayerOneScore, int nPlayerTwoScore) {
    printf("\n[PLAYER ONE] Gojo Satoru's Score is: %d\n", nPlayerOneScore);
    printf("\n[PLAYER TWO] Ryomen Sukuna's Score is: %d\n", nPlayerTwoScore);

    // Player One has the lower score, meaning Player One wins
    if (nPlayerOneScore < nPlayerTwoScore) {
        printf("\n==========================================================================\n\n");
        printf("Sukuna's reign of terror ends here - Gojo's limitless strength knows no bounds!\n");
        printf("    [ P L A Y E R   O N E]   G O J O     S A T O R U    W I N S  ! ! !\n");
        printf("\n==========================================================================\n\n");
    }

    // Player Two has the lower score, meaning Player Two wins
    else if (nPlayerTwoScore < nPlayerOneScore) {
        printf("\n==========================================================================\n\n");
        printf("The indomitable Sukuna has defeated Gojo! The curse world's true king emerges!\n");
        printf("    [ P L A Y E R   T W O]   R Y O M E N    S U K U N A   W I N S  ! ! !   \n");
        printf("\n==========================================================================\n\n");
    }

    // It's a tie between both players 
    else if (nPlayerTwoScore == nPlayerOneScore) {
        printf("\n======================================================================================================================\n\n");
        printf("Neither Gojo nor Sukuna claimed victory; the battle ended in a tie, showcasing their equal strength and indomitable will.\n");
        printf("                                   [ I T ' S       A        T I E ]  ! ! !                                            \n");
        printf("\n======================================================================================================================\n\n");
    }
}

/*******************************************************
Function : int runGameForPlayerTwo
Description : Game looping for player two
Precondition(s) : Player one's turn must be ended already
Parameters : None
Return Value : The score at the end of his turn
*******************************************************/
int runGameForPlayerTwo() {

    printf("\n\n THE TURN WILL NOW BE [PLAYER TWO] RYOMEN SUKUNA'S\n\n");
    
    srand(time(NULL));
    
    int nGameStatus = 1;

    int nPlayerTwoScore;

    int nTwoTile01 = 1, nTwoTile02 = 2, nTwoTile03 = 3, nTwoTile04 = 4, nTwoTile05 = 5, nTwoTile06 = 6,
        nTwoTile07 = 7, nTwoTile08 = 8, nTwoTile09 = 9, nTwoTile10 = 10, nTwoTile11 = 11, nTwoTile12 = 12,
        nTwoTile13 = 13, nTwoTile14 = 14, nTwoTile15 = 15, nTwoTile16 = 16, nTwoTile17 = 17, nTwoTile18 = 18;

    // As long as the game status is 1, the moves keep looping, ends if the player types -1
    while (nGameStatus == 1) {

        int nHowManyDice = checkHowManyDice(&nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                            &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                            &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);

        int nDiceQuantity, nDiceValue, nHowManyTiles;
        int nFirstTile, nSecondTile, nThirdTile, nFourthTile, nFifthTile;
        int nTileSum;

        printf("========================================================\n");
        printf(" [ P L A Y E R      T W O ]\n");
        showGridPlayerTwo(&nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                          &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                          &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
        printf("\n");

        if (nHowManyDice == 3) {
                printf("3 dice shall be rolled\n\n");
                nDiceValue = rollaDiceThrice();
            }

        else if (nHowManyDice == 2) {
            int validInput = 0; // Flag to check if input is valid
            while (!validInput) 
            {
                printf("You may choose to roll 2 or 3 dice, how many do you want to roll?: \n");
                scanf("%d", &nDiceQuantity);

            if (nDiceQuantity == 3 || nDiceQuantity == 2) 
                {
                    validInput = 1; // Input is valid, exit the loop
                    if (nDiceQuantity == 3) {
                        nDiceValue = rollaDiceThrice();
                    } else if (nDiceQuantity == 2) {
                        nDiceValue = rollaDiceTwice();
                    }
                } 
            
            else 
                {
                    printf("Invalid Input! Try Again!\n");
                    while (getchar() != '\n'); // clears input buffer so it doesn't go in a loop
                }
            }
        }

        else if (nHowManyDice == 1) {
            int validInput = 0; // Flag to check if input is valid
            while (!validInput) 
            {
            printf("You may choose to roll 1, 2, or 3 dice, how many do you want to roll? \n");
            scanf("%d", &nDiceQuantity);

            if (nDiceQuantity == 1) {
                nDiceValue = rollaDice();
                validInput = 1; // Input is valid, exit the loop
            } else if (nDiceQuantity == 2) {
                nDiceValue = rollaDiceTwice();
                validInput = 1; // Input is valid, exit the loop
            } else if (nDiceQuantity == 3) {
                nDiceValue = rollaDiceThrice();
                validInput = 1; // Input is valid, exit the loop
            } else {
                printf("Invalid Input! Try Again!\n");
                while (getchar() != '\n'); // Clears input buffer so it doesn't go in a loop
            }
         }
}
            printf("[PLAYER 2] Ryomen Sukuna! You have rolled a dice value of %d\n\n", nDiceValue);
            printf("[INPUT -1] If the sorcerer cannot think of any more tiles to put down whose sum can equal to the sum of the dice rolled\n");
            printf("[INPUT -1] If the sorcerer thinks he has shut down all his tiles!\n\n");
            printf("How many tiles would you like to put down? Choose between 1 to 5: ");

            scanf("%d", &nHowManyTiles);

                if (nHowManyTiles == -1) {
                    return nPlayerTwoScore = calculateScoreForPlayerTwo(&nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                                 &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                                 &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                }

                else if (nHowManyTiles == 1 || nHowManyTiles == 2 || nHowManyTiles == 3 || nHowManyTiles == 4 || nHowManyTiles == 5) {
                    if (nHowManyTiles == 5) {
                        printf("Choose which tiles you want to put down: \n");
                        scanf("%d %d %d %d %d", &nFirstTile, &nSecondTile, &nThirdTile, &nFourthTile, &nFifthTile);

                        isChosenTileValidTwo(&nFirstTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                         &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                         &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                        isChosenTileValidTwo(&nSecondTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                         &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                         &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                        isChosenTileValidTwo(&nThirdTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                         &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                         &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                        isChosenTileValidTwo(&nFourthTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                         &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                         &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                        isChosenTileValidTwo(&nFifthTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                         &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                         &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);

                        nTileSum = nFirstTile + nSecondTile + nThirdTile + nFourthTile + nFifthTile;

                        if (nTileSum == nDiceValue && nFirstTile != nSecondTile && nFirstTile != nThirdTile && nFirstTile != nFourthTile && nFirstTile != nFifthTile
                                                   && nSecondTile != nThirdTile && nSecondTile != nFourthTile && nSecondTile != nFifthTile 
                                                   && nThirdTile != nFourthTile && nThirdTile != nFifthTile && nFourthTile != nFifthTile
                                                   && nFirstTile != 0 && nSecondTile != 0 && nThirdTile != 0 && nFourthTile != 0 && nFifthTile != 0) {
                            printf("The King of Curses has awakened! Bow before Sukuna's might! Tiles are now updated! \n");
                            nChosenTileForPlayerTwo(nFirstTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                                &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                                &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                            nChosenTileForPlayerTwo(nSecondTile,&nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                                &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                                &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                            nChosenTileForPlayerTwo(nThirdTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                                &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                                &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                            nChosenTileForPlayerTwo(nFourthTile,&nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                                &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                                &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                            nChosenTileForPlayerTwo(nFifthTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                                &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                                &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                        }
                        
                        else if (nTileSum != nDiceValue || nFirstTile == nSecondTile || nFirstTile == nThirdTile || nFirstTile == nFourthTile || nFirstTile == nFifthTile
                                                        || nSecondTile == nThirdTile || nSecondTile == nFourthTile || nSecondTile == nFifthTile 
                                                        || nThirdTile == nFourthTile || nThirdTile == nFifthTile || nFourthTile == nFifthTile
                                                        || nFirstTile == 0 || nSecondTile == 0 || nThirdTile == 0 || nFourthTile == 0 || nFifthTile == 0) {
                            printf("\nInvalid Move! Focus sorcerer, input again!\n\n");
                            while (getchar() != '\n'); // clears input buffer so it doesn't go in a loop
                        }
                    }

                    else if (nHowManyTiles == 4) {
                        printf("Choose which tiles you want to put down: \n");
                        scanf("%d %d %d %d", &nFirstTile, &nSecondTile, &nThirdTile, &nFourthTile);

                        isChosenTileValidTwo(&nFirstTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                         &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                         &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                        isChosenTileValidTwo(&nSecondTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                         &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                         &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                        isChosenTileValidTwo(&nThirdTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                         &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                         &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                        isChosenTileValidTwo(&nFourthTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                         &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                         &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);

                        nTileSum = nFirstTile + nSecondTile + nThirdTile + nFourthTile;

                        if (nTileSum == nDiceValue && nFirstTile != nSecondTile && nFirstTile != nThirdTile && nFirstTile != nFourthTile
                                                   && nSecondTile != nThirdTile && nSecondTile != nFourthTile && nThirdTile != nFourthTile
                                                   && nFirstTile != 0 && nSecondTile != 0 && nThirdTile != 0 && nFourthTile != 0) {
                            printf("Sukuna, the one who stands above all curses! Show them your wrath! Tiles are now updated! \n");
                            nChosenTileForPlayerTwo(nFirstTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                                &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                                &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                            nChosenTileForPlayerTwo(nSecondTile,&nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                                &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                                &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                            nChosenTileForPlayerTwo(nThirdTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                                &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                                &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                            nChosenTileForPlayerTwo(nFourthTile,&nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                                &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                                &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                        }

                        else if (nTileSum != nDiceValue || nFirstTile == nSecondTile || nFirstTile == nThirdTile || nFirstTile == nFourthTile
                                                        || nSecondTile == nThirdTile || nSecondTile == nFourthTile || nThirdTile == nFourthTile
                                                        || nFirstTile == 0 || nSecondTile == 0 || nThirdTile == 0 || nFourthTile == 0) {
                            printf("\nInvalid Move! Focus sorcerer, input again!\n\n");
                            while (getchar() != '\n'); // clears input buffer so it doesn't go in a loop
                        }
                    }

                    else if (nHowManyTiles == 3) {
                        printf("Choose which tiles you want to put down: \n");
                        scanf("%d %d %d", &nFirstTile, &nSecondTile, &nThirdTile);

                        nTileSum = nFirstTile + nSecondTile + nThirdTile;

                        isChosenTileValidTwo(&nFirstTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                         &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                         &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                        isChosenTileValidTwo(&nSecondTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                         &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                         &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                        isChosenTileValidTwo(&nThirdTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                         &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                         &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);

                        if (nTileSum == nDiceValue && nFirstTile != nSecondTile && nFirstTile != nThirdTile &&
                                                      nSecondTile != nThirdTile && nFirstTile != 0 && nSecondTile != 0 && nThirdTile != 0) {
                            printf("Sukuna, remind them why you're the undisputed King of Curses! Tiles are now updated! \n");
                            nChosenTileForPlayerTwo(nFirstTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                                &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                                &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                            nChosenTileForPlayerTwo(nSecondTile,&nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                                &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                                &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                            nChosenTileForPlayerTwo(nThirdTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                                &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                                &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                        }

                        else if (nTileSum != nDiceValue || nFirstTile == nSecondTile || nFirstTile == nThirdTile || nSecondTile == nThirdTile
                                 || nFirstTile == 0 || nSecondTile == 0 || nThirdTile == 0) {
                            printf("\nInvalid Move! Focus sorcerer, input again!\n\n");
                            while (getchar() != '\n'); // clears input buffer so it doesn't go in a loop
                        }
                    }

                    else if (nHowManyTiles == 2) {
                        printf("Choose which tiles you want to put down: \n");
                        scanf("%d %d", &nFirstTile, &nSecondTile);

                        isChosenTileValidTwo(&nFirstTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                         &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                         &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                        isChosenTileValidTwo(&nSecondTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                         &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                         &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);

                        nTileSum = nFirstTile + nSecondTile;

                        if (nTileSum == nDiceValue && nFirstTile != nSecondTile && nFirstTile != 0 && nSecondTile != 0) {
                            printf("Sukuna, unleash your malevolent power and let the world tremble! Tiles are now updated! \n");
                            nChosenTileForPlayerTwo(nFirstTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                                &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                                &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                            nChosenTileForPlayerTwo(nSecondTile,&nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                                &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                                &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                        }

                        else if (nTileSum != nDiceValue || nFirstTile == nSecondTile || nFirstTile == 0 || nSecondTile == 0) {
                            printf("\nInvalid Move! Focus sorcerer, input again!\n\n");
                            while (getchar() != '\n'); // clears input buffer so it doesn't go in a loop
                        }
                    }

                    if (nHowManyTiles == 1) {
                        printf("Choose which tiles you want to put down: \n");
                        scanf("%d", &nFirstTile);

                        isChosenTileValidTwo(&nFirstTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                         &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                         &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);

                        nTileSum = nFirstTile;

                        if (nTileSum == nDiceValue && nFirstTile != 0) {
                            printf("The curse world bows only to Sukuna! Dominate them all! Tiles are now updated! \n");
                            nChosenTileForPlayerTwo(nFirstTile, &nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                                &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                                &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);
                        }

                        else if (nTileSum != nDiceValue && nFirstTile == 0) {
                            printf("\nInvalid Move! Focus sorcerer, input again!\n\n");
                            while (getchar() != '\n'); // clears input buffer so it doesn't go in a loop
                        }
                    }
                }

                else if (nHowManyTiles != 1 || nHowManyTiles != 2 || nHowManyTiles != 3 || nHowManyTiles != 4 || nHowManyTiles != 5) {
                        printf("========================================================\n");
                        printf("Invalid input, sorcerer! Focus and choose again, [1], [2], [3], [4], or [5]? \n");
                        while (getchar() != '\n'); // clears input buffer so it doesn't go in a loop
                }
                
            }

            nPlayerTwoScore = calculateScoreForPlayerTwo(&nTwoTile01, &nTwoTile02, &nTwoTile03, &nTwoTile04, &nTwoTile05, &nTwoTile06,
                                                                &nTwoTile07, &nTwoTile08, &nTwoTile09, &nTwoTile10, &nTwoTile11, &nTwoTile12,
                                                                &nTwoTile13, &nTwoTile14, &nTwoTile15, &nTwoTile16, &nTwoTile17, &nTwoTile18);  
             return nPlayerTwoScore;
}

/*******************************************************
Function : int runGameForPlayerOne
Description : Game looping for player one
Precondition(s) : None
Parameters : None
Return Value : The score at the end of his turn
*******************************************************/
int runGameForPlayerOne() {
    srand(time(NULL));
    
    int nGameStatus = 1;

    int nPlayerOneScore;

        int nOneTile01 = 1, nOneTile02 = 2, nOneTile03 = 3, nOneTile04 = 4, nOneTile05 = 5, nOneTile06 = 6,
        nOneTile07 = 7, nOneTile08 = 8, nOneTile09 = 9, nOneTile10 = 10, nOneTile11 = 11, nOneTile12 = 12,
        nOneTile13 = 13, nOneTile14 = 14, nOneTile15 = 15, nOneTile16 = 16, nOneTile17 = 17, nOneTile18 = 18;

    // As long as the game status is 1, the moves keep looping, ends if the player types -1
    while (nGameStatus == 1) {
        int nHowManyDice = checkHowManyDice(&nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                            &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                            &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);

        int nDiceQuantity, nDiceValue, nHowManyTiles;
        int nFirstTile, nSecondTile, nThirdTile, nFourthTile, nFifthTile;
        int nTileSum;

        printf("========================================================\n");
        printf(" [ P L A Y E R      O N E ]\n");
        showGridPlayerOne(&nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                          &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                          &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
        printf("\n");

            if (nHowManyDice == 3) {
                printf("3 dice shall be rolled\n\n");
                nDiceValue = rollaDiceThrice();
            }

            else if (nHowManyDice == 2) {
            int validInput = 0; // Flag to check if input is valid
            while (!validInput) 
            {
                printf("You may choose to roll 2 or 3 dice, how many do you want to roll?: \n");
                scanf("%d", &nDiceQuantity);

            if (nDiceQuantity == 3 || nDiceQuantity == 2) 
                {
                    validInput = 1; // Input is valid, exit the loop
                    if (nDiceQuantity == 3) {
                        nDiceValue = rollaDiceThrice();
                    } else if (nDiceQuantity == 2) {
                        nDiceValue = rollaDiceTwice();
                    }
                } 
            
            else 
                {
                    printf("Invalid Input! Try Again!\n");
                    while (getchar() != '\n'); // clears input buffer so it doesn't go in a loop
                }
            }
        }

            else if (nHowManyDice == 1) {
            int validInput = 0; // Flag to check if input is valid
            while (!validInput) 
            {
            printf("You may choose to roll 1, 2, or 3 dice, how many do you want to roll? \n");
            scanf("%d", &nDiceQuantity);

            if (nDiceQuantity == 1) {
                nDiceValue = rollaDice();
                validInput = 1; // Input is valid, exit the loop
            } else if (nDiceQuantity == 2) {
                nDiceValue = rollaDiceTwice();
                validInput = 1; // Input is valid, exit the loop
            } else if (nDiceQuantity == 3) {
                nDiceValue = rollaDiceThrice();
                validInput = 1; // Input is valid, exit the loop
            } else {
                printf("Invalid Input! Try Again!\n");
                while (getchar() != '\n'); // Clears input buffer so it doesn't go in a loop
            }
         }
}

            printf("[PLAYER 1] Satoru Gojo! You have rolled a dice value of %d\n\n", nDiceValue);
            printf("[INPUT -1] If the sorcerer cannot think of any more tiles to put down whose sum can equal to the sum of the dice rolled\n");
            printf("[INPUT -1] If the sorcerer thinks he has shut down all his tiles!\n\n");
            printf("How many tiles would you like to put down? Choose between 1 to 5: ");

            scanf("%d", &nHowManyTiles);

                if (nHowManyTiles == -1) {
                    return nPlayerOneScore = calculateScoreForPlayerOne(&nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                                 &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                                 &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                }

                else if (nHowManyTiles == 1 || nHowManyTiles == 2 || nHowManyTiles == 3 || nHowManyTiles == 4 || nHowManyTiles == 5) {
                    if (nHowManyTiles == 5) {
                        printf("Choose which tiles you want to put down: \n");
                        scanf("%d %d %d %d %d", &nFirstTile, &nSecondTile, &nThirdTile, &nFourthTile, &nFifthTile);

                        isChosenTileValidOne(&nFirstTile, &nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                          &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                          &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                        isChosenTileValidOne(&nSecondTile, &nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                          &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                          &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                        isChosenTileValidOne(&nThirdTile, &nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                          &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                          &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                        isChosenTileValidOne(&nFourthTile, &nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                          &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                          &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                        isChosenTileValidOne(&nFifthTile, &nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                          &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                          &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);

                        nTileSum = nFirstTile + nSecondTile + nThirdTile + nFourthTile + nFifthTile;

                        if (nTileSum == nDiceValue && nFirstTile != nSecondTile && nFirstTile != nThirdTile && nFirstTile != nFourthTile && nFirstTile != nFifthTile
                                                   && nSecondTile != nThirdTile && nSecondTile != nFourthTile && nSecondTile != nFifthTile 
                                                   && nThirdTile != nFourthTile && nThirdTile != nFifthTile && nFourthTile != nFifthTile
                                                   && nFirstTile != 0 && nSecondTile != 0 && nThirdTile != 0 && nFourthTile != 0 && nFifthTile != 0) {
                            printf("Gojo, you're the one who breaks all limits! Tiles are now updated! \n");
                            nChosenTileForPlayerOne(nFirstTile, &nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                                &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                                &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                            nChosenTileForPlayerOne(nSecondTile,&nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                                &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                                &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                            nChosenTileForPlayerOne(nThirdTile, &nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                                &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                                &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                            nChosenTileForPlayerOne(nFourthTile,&nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                                &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                                &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                            nChosenTileForPlayerOne(nFifthTile, &nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                                &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                                &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                        }
                        
                        else if (nTileSum != nDiceValue || nFirstTile == nSecondTile || nFirstTile == nThirdTile || nFirstTile == nFourthTile || nFirstTile == nFifthTile
                                                        || nSecondTile == nThirdTile || nSecondTile == nFourthTile || nSecondTile == nFifthTile 
                                                        || nThirdTile == nFourthTile || nThirdTile == nFifthTile || nFourthTile == nFifthTile
                                                        || nFirstTile == 0 || nSecondTile == 0 || nThirdTile == 0 || nFourthTile == 0 || nFifthTile == 0) {
                            printf("\nInvalid Move! Focus sorcerer, input again!\n\n");
                            while (getchar() != '\n'); // clears input buffer so it doesn't go in a loop
                        }
                    }

                    else if (nHowManyTiles == 4) {
                        printf("Choose which tiles you want to put down: \n");
                        scanf("%d %d %d %d", &nFirstTile, &nSecondTile, &nThirdTile, &nFourthTile);

                        isChosenTileValidOne(&nFirstTile, &nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                          &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                          &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                        isChosenTileValidOne(&nSecondTile, &nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                          &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                          &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                        isChosenTileValidOne(&nThirdTile, &nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                          &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                          &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                        isChosenTileValidOne(&nFourthTile, &nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                          &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                          &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);

                        nTileSum = nFirstTile + nSecondTile + nThirdTile + nFourthTile;

                        if (nTileSum == nDiceValue && nFirstTile != nSecondTile && nFirstTile != nThirdTile && nFirstTile != nFourthTile
                                                   && nSecondTile != nThirdTile && nSecondTile != nFourthTile && nThirdTile != nFourthTile
                                                   && nFirstTile != 0 && nSecondTile != 0 && nThirdTile != 0 && nFourthTile != 0) {
                            printf("Let's see that Infinity in action, Gojo! You're unstoppable! Tiles are now updated! \n");
                            nChosenTileForPlayerOne(nFirstTile,&nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                               &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                               &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                            nChosenTileForPlayerOne(nSecondTile,&nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                                &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                                &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                            nChosenTileForPlayerOne(nThirdTile, &nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                                &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                                &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                            nChosenTileForPlayerOne(nFourthTile,&nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                                &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                                &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                        }

                        else if (nTileSum != nDiceValue || nFirstTile == nSecondTile || nFirstTile == nThirdTile || nFirstTile == nFourthTile
                                                        || nSecondTile == nThirdTile || nSecondTile == nFourthTile || nThirdTile == nFourthTile
                                                        || nFirstTile == 0 || nSecondTile == 0 || nThirdTile == 0 || nFourthTile == 0) {
                            printf("\nInvalid Move! Focus sorcerer, input again!\n\n");
                            while (getchar() != '\n'); // clears input buffer so it doesn't go in a loop
                        }
                    }

                    else if (nHowManyTiles == 3) {
                        printf("Choose which tiles you want to put down: \n");
                        scanf("%d %d %d", &nFirstTile, &nSecondTile, &nThirdTile);

                        isChosenTileValidOne(&nFirstTile, &nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                          &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                          &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                        isChosenTileValidOne(&nSecondTile, &nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                          &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                          &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                        isChosenTileValidOne(&nThirdTile, &nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                          &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                          &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);

                        nTileSum = nFirstTile + nSecondTile + nThirdTile;

                        if (nTileSum == nDiceValue && nFirstTile != nSecondTile && nFirstTile != nThirdTile &&
                                                      nSecondTile != nThirdTile && nFirstTile != 0 && nSecondTile != 0 && nThirdTile != 0) {
                            printf("Gojo, with your Six Eyes, nothing can escape you! Tiles are now updated! \n");
                            nChosenTileForPlayerOne(nFirstTile,&nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                               &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                               &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                            nChosenTileForPlayerOne(nSecondTile,&nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                                &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                                &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                            nChosenTileForPlayerOne(nThirdTile,&nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                               &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                               &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                        }

                        else if (nTileSum != nDiceValue || nFirstTile == nSecondTile || nFirstTile == nThirdTile || nSecondTile == nThirdTile
                                 || nFirstTile == 0 || nSecondTile == 0 || nThirdTile == 0) {
                            printf("\nInvalid Move! Focus sorcerer, input again!\n\n");
                            while (getchar() != '\n'); // clears input buffer so it doesn't go in a loop
                        }
                    }

                    else if (nHowManyTiles == 2) {
                        printf("Choose which tiles you want to put down: \n");
                        scanf("%d %d", &nFirstTile, &nSecondTile);

                        isChosenTileValidOne(&nFirstTile, &nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                          &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                          &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                        isChosenTileValidOne(&nSecondTile, &nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                          &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                          &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);

                        nTileSum = nFirstTile + nSecondTile;

                        if (nTileSum == nDiceValue && nFirstTile != nSecondTile && nFirstTile != 0 && nSecondTile != 0) {
                            printf("Gojo Sensei! Show them why you're the strongest sorcerer! Tiles are now updated! \n");
                            nChosenTileForPlayerOne(nFirstTile, &nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                                &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                                &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                            nChosenTileForPlayerOne(nSecondTile,&nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                                &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                                &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                        }

                        else if (nTileSum != nDiceValue || nFirstTile == nSecondTile || nFirstTile == 0 || nSecondTile == 0) {
                            printf("\nInvalid Move! Focus sorcerer, input again!\n\n");
                            while (getchar() != '\n'); // clears input buffer so it doesn't go in a loop
                        }
                    }

                    if (nHowManyTiles == 1) {
                        printf("Choose which tiles you want to put down: \n");
                        scanf("%d", &nFirstTile);

                        isChosenTileValidOne(&nFirstTile, &nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                          &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                          &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);

                        nTileSum = nFirstTile;

                        if (nTileSum == nDiceValue && nFirstTile != 0) {
                            printf("It's time to teach them why you're the pride of Jujutsu High, Gojo! Tiles are now updated! \n");
                            nChosenTileForPlayerOne(nFirstTile, &nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                                &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                                &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);
                        }

                        else if (nTileSum != nDiceValue || nFirstTile == 0) {
                            printf("\nInvalid Move! Focus sorcerer, input again!\n\n");
                            while (getchar() != '\n'); // clears input buffer so it doesn't go in a loop
                        }
                    }
                }

                else if (nHowManyTiles != 1 || nHowManyTiles != 2 || nHowManyTiles != 3 || nHowManyTiles != 4 || nHowManyTiles != 5) {
                        printf("========================================================\n");
                        printf("Invalid input, sorcerer! Focus and choose again, [1], [2], [3], [4], or [5]? \n");
                        while (getchar() != '\n'); // clears input buffer so it doesn't go in a loop
                }
            }

            nPlayerOneScore = calculateScoreForPlayerOne(&nOneTile01, &nOneTile02, &nOneTile03, &nOneTile04, &nOneTile05, &nOneTile06,
                                                        &nOneTile07, &nOneTile08, &nOneTile09, &nOneTile10, &nOneTile11, &nOneTile12,
                                                        &nOneTile13, &nOneTile14, &nOneTile15, &nOneTile16, &nOneTile17, &nOneTile18);

             return nPlayerOneScore;
}

/*******************************************************
Function : int main()
Description : Main program, gives the flow of the game
Precondition(s) : None
Parameters : None
Return Value : 0 once the functions are ran through, ends the program immediately. 
*******************************************************/
int main() { 
    // Random number generator
    srand(time(NULL));

    int nPlayerOneScore, nPlayerTwoScore;

    // Introduction to the game
     printf("========================================================\n");
     printf("Welcome to a classic game of Shut-The-Box with a twist!\n");
     printf("  + This game will be themed around Jujutsu Kaisen +\n");
     printf("--------------------------------------------------------\n");
     printf("   [PLAYER 1]                            [PLAYER 2]\n");
     printf("   Satoru Gojo                         Ryomen Sukuna\n");
     printf("========================================================\n");
     printf("[PLAYER 1] Satoru Gojo shall go first! Good luck sorcerer!\n");

    // Runs game looping for Player One's Turn
     nPlayerOneScore = runGameForPlayerOne();

    // If by the end of Player One's Turn, his score is 0, then it prints the special Shut-The-Box message and ends the game
     if (nPlayerOneScore == 0)
     {
        shutTheBox(nPlayerOneScore);
     }

    // However, if his score is not 0, then it will put the turn unto Player Two instead of making Player One the winner immediately
     else if (nPlayerOneScore != 0)
     {
        // Runs game looping for Player Two's Turn
        nPlayerTwoScore = runGameForPlayerTwo();

        // If by the end of Player One's Turn, his score is 0, then it prints the special Shut-The-Box message
        if (nPlayerTwoScore == 0)
        {
            shutTheBox(nPlayerTwoScore);
        }
        
        // Prints the scores of each player and prints the winner also
        endOfGame(nPlayerOneScore, nPlayerTwoScore);
     }

    return 0;
}
