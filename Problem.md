**Title** 

Computing the similarity between two DNA sequences

**Problem Statement**

Genetic sequences are formed from the genetic bases Adenine (A), Thymine (T), Guanine (G) and Cytosine (C). Genetic sequences that are similar enough might be expected to behaviour in a similar manner. This is an attempt to quantify the similarity through the edit distance, here the two sequences ate aligned but we are permitted to insert a gap in either sequence to make them the same length. There will be a penalty for each gap or mismatch in a pair of characters in the final alignments. The following penalty scoring will be applied :
- matchPenalty = 0
- mismatchPenalty = 1
- gapPenalty = 2


**Solution Method**

The problem is solved through the implementation of the Needleman Wunsch Algorithm. 
The procedure involves the following steps :
  - Creating a Matrix of (M x N) where M represents all of the characters in Sequence A and N represents all of the characters in Sequence B.
  - The Matrix is filled in from the top left to the bottom right using the above scoring system.
  - The score is calculated by comparing the scores of the neighbouring left, top and top-left (diagonal) and adding the appropriate score for a match, mismatch or gap.
  - The path from left or the top represents a gap pairing so you would add the gap penalty to the left or top-left score.
  - The diagonal path represents a match or mismatch pairing so you would add the match or mistmatch penalty to the top-left diagonal cell. 
  - Whilst this is done, the best path to reach the current cell is recorded in a trace matrix.
  - Once the two matrices are filled in the trace matrix is used to determine the best optimal alignment path.

  **Improvments to be made**
  - Enable the DNA Sequence to be read in from a text file or a user input. 
  - Enable the scoring system to be generated through user input