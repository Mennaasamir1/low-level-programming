#include "game.h"

/**
 * main - stone, paper, scissors game
 *
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
    srand((unsigned)time(NULL));

    StartGame();

    return (0);
}