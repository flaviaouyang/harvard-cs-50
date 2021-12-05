#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char* word);
int points_check(char* word, char point[], int size);

int main(void)
{
    char word1[100], word2[100];
    // Get input words from both players
    printf("Player 1: ");
    scanf("%s", word1);
    // printf("Word 1 is %s\n", word1);

    printf("Player 2: ");
    scanf("%s", word2);
    // printf("Word 2 is %s\n", word2);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if ( score1 > score2 ){
        printf("Player one won.\n");
    } else if ( score1 == score2){
        printf("They tied.\n");
    } else {
        printf("Player two won.\n");
    }
}

int compute_score(char* word)
{
    int score;
    // TODO: Compute and return score for string
    // a, e, i, l, n, o, r, s, t, u
    char point1 [20] = {'A', 'a', 'E', 'I', 'L', 'N', 'O', 'R', 'S', 'T', 'U', 'e', 'i', 'l', 'n', 'o', 'r', 's', 't', 'u'};
    // b, c, m, p
    char point3 [8] = {'B','C', 'M', 'P', 'b', 'c', 'm', 'p'};
    // d, g
    char point2 [4] = {'D', 'G', 'd', 'g'};
    // f, h, v, w, y
    char point4 [10] = {'F', 'H', 'V', 'W', 'Y', 'f', 'h', 'w', 'v', 'y'};
    char point5 [2] = {'K', 'k'};
    char point8 [4] = {'J', 'X', 'j', 'x'};
    char point10 [4] = {'Q', 'Z', 'q', 'z'};

    score = points_check(word, point1, 20) + points_check(word, point3, 8)*3 + points_check(word, point2, 4)*2 + points_check(word, point4, 10)*4 + points_check(word, point5, 2)*5 + points_check(word, point8, 4)*8 + points_check(word, point10, 4)*10;
    // printf("Score is: %i.\n", score);
    return score;
}

int points_check(char word[], char point[], int size)
{
    // printf("check: %c\n", word[0]);
    // printf("point: %c\n", point[0]);
    // printf("length of array is : %lu", strlen(point));
    int points = 0;
    for (int i = 0; i < strlen(word); i++){
        // printf("i is %i\n", i);
        for (int j = 0; j < size; j++){
            // printf("j is %i\n", j);
            if ( word[i] == point[j] ){
                points += 1;
            }
        }
    }
    // printf("point is %i\n", points);
    return points;
}