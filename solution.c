#include <stdio.h>
#include <string.h>

int main(void) {
    int row, column, shortSequence, longSequence;
    int matchPenalty = 0;
    int mismatchPenalty = 1;
    int gapPenalty = 2;
    char sequenceOne[] = "TAAGGTCA";
    char sequenceTwo[] = "AACAGTTACC";
    int numberOfRows = strlen(sequenceOne); 
    int numberOfColumns = strlen(sequenceTwo);
    char traceMatrix[(numberOfRows + 1)][(numberOfColumns + 1)];
    int scoreMatrix[(numberOfRows + 1)][(numberOfColumns + 1)];
    traceMatrix[0][0] = 'F';
    scoreMatrix[0][0] = 0;

    /* Inititalise first row of values in the score and trace matricies. */
    
    for (row = 0; row < 1; row += 1) {
        for (column = 1; column <= numberOfColumns; column += 1) {
            scoreMatrix[row][column] = scoreMatrix[row][(column - 1)] + gapPenalty;
            traceMatrix[row][column] = 'L';
        }
    }

    /* Inititalise first column of values in the score and trace matricies. */

    for (row = 1; row <= numberOfRows; row += 1) {
        for (column = 0; column < 1; column += 1) {
            scoreMatrix[row][column] = scoreMatrix[(row - 1)][column] + gapPenalty;
            traceMatrix[row][column] = 'U';
        }
    }

    /* Filling in the rest of the rows and columns in the score and trace matricies. */ 

    for (row = 1; row <= numberOfRows; row += 1) {
        for (column = 1; column <= numberOfColumns; column += 1) {
            int v1 = scoreMatrix[(row - 1)][(column - 1)];
            int v2 = scoreMatrix[(row - 1)][column] + gapPenalty;
            int v3 = scoreMatrix[row][(column - 1)] + gapPenalty;
            if (sequenceOne[(row - 1)] == sequenceTwo[(column - 1)]) {
                v1 += matchPenalty;
            }
            else {
                v1 += mismatchPenalty;
            }
            if (v1 <= v2 && v1 <= v3) {
                scoreMatrix[row][column] = v1;
                traceMatrix[row][column] = 'D';
            }
            if (v2 < v1 && v2 <= v3) {
                scoreMatrix[row][column] = v2;
                traceMatrix[row][column] = 'U';
            }
            if (v3 < v1 && v3 < v2) {
                scoreMatrix[row][column] = v3;
                traceMatrix[row][column] = 'L';
            }
        }
    }
    
    /* Find path for global sequence alignment. */

    if (numberOfRows >= numberOfColumns) {
        printf("%s", sequenceOne);
        longSequence = numberOfRows;
        shortSequence = numberOfColumns;
    }
    else {
        printf("%s", sequenceTwo);
        longSequence = numberOfColumns;
        shortSequence = numberOfRows;
    }
    
    
    char alignedSequence[longSequence];
    row = numberOfRows;
    column = numberOfColumns;
    
    
    if (shortSequence == numberOfRows) {
        while (shortSequence != 0) {
        char character = traceMatrix[row][column];
        if (character == 'D') {
            alignedSequence[longSequence] = sequenceOne[(shortSequence - 1)];
            row -= 1;
            column -= 1;
            shortSequence -= 1;
        }
        if (character == 'U') {
            alignedSequence[longSequence] = '-';
            row -= 1;
        }
        if (character == 'L') {
            alignedSequence[longSequence] = '-';
            column -= 1;
        }
        longSequence -= 1;
    }
    } else
    {
        while (shortSequence != 0) {
        char character = traceMatrix[row][column];
        if (character == 'D') {
            alignedSequence[longSequence] = sequenceTwo[(shortSequence - 1)];
            row -= 1;
            column -= 1;
            shortSequence -= 1;
        }
        if (character == 'U') {
            alignedSequence[longSequence] = '-';
            row -= 1;
        }
        if (character == 'L') {
            alignedSequence[longSequence] = '-';
            column -= 1;
        }
        longSequence -= 1;
    }
    }
    printf("%s \n", alignedSequence);
    printf("The minimum edit distance is %d. \n", scoreMatrix[numberOfRows][numberOfColumns]);    
}