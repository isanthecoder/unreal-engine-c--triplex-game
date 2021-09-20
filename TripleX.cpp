#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Print welcome messages to the terminal
    std::cout << "\n\nYou are a hacker breaking into one of the most secure level " << Difficulty;
    std::cout << " state facility prisons in the world to rescue your mate who's serving a lifetime sentence there...\nYou need to enter the correct codes to continue...\n\n";
}

bool PlayGame(int Difficulty)
{ 
    PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal
    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA+GuessB+GuessC;
    int GuessProduct = GuessA*GuessB*GuessC;

    // check if the player's guess is correct
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** You're successful mate, keep hacking to rescue your prison mate! ***";
        return true;
    }
    else
    {
        std::cout << "\n*** You failed miserably mate, your prison mate is still in for a hard time at the prison all his life! Be careful and try again! ***";
        return false;
    }
} 

int main()
{
    srand(time(NULL)); // creates new random sequence based on time of day

    int LevelDifficulty = 1;\
    int const MaxDifficulty = 5;
    
    while (LevelDifficulty <= MaxDifficulty) // loop game until all levels completed
    {
      bool bLevelComplete = PlayGame(LevelDifficulty);
      std::cin.clear(); // Clears any errors
      std::cin.ignore(); // Discards the buffer

      if(bLevelComplete)
      {
          ++LevelDifficulty;
      }
    }
    std::cout << "\n*** Great work mate, you're a master hacker, your prison mate has escaped into the shadows, well done! Now join your mate in the shadows and remember to stay anonymous! :) ***\n";
    return 0;
}