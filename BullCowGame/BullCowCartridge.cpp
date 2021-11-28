// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::InitGame()
{
    

    HiddenWord = TEXT("cake");
    Lives = HiddenWord.Len(); 
    bGameOver = false;
    
    PrintLine(TEXT("Welcome to the bull cow game\nThe Hidden Word is %i Characters Long "), HiddenWord.Len());
    PrintLine(TEXT("You Have %i Lives"), Lives);
}




void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    
    InitGame();

    //PrintLine(FString::Printf(TEXT("The HiddenWord is: %s "), *HiddenWord)); //Debug Line

}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if(bGameOver)
    {
        ClearScreen();
        InitGame();
    }
    else
    {
        ProcessGuess(Input, Lives);
    }    

}   

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("The word was %s"), *HiddenWord);
    PrintLine(TEXT("You Lost Press Enter To Try Agian..."));  
}

void UBullCowCartridge::ProcessGuess(FString Guess , int32 Counter)
{
        ClearScreen();
        if(Guess == HiddenWord)
        {
            PrintLine(TEXT("Nice one you got it correct!"));
            bGameOver = true;
        }
        //if(!IsIsogram)
        // {
        //     PrintLine(TEXT("There are no repeating letters"))
        // }
        
        else 
        {
            --Lives;
            if(Lives > 0)
            {
                PrintLine(TEXT("Incorrect Try again\nYou have %i Lives remaining"), Lives);
                if (HiddenWord.Len() != Guess.Len())
                {
                    PrintLine(TEXT("The word is %i letters long"),HiddenWord.Len());
                }
            }
            else
            {
                EndGame();
            }
        }
        //else check PlayerGuess
        //Or quit
    
}

