# Error-Correction-DNA-Storage

## A Hierarchical Error Correction Strategy for Text DNA Storage

A hierarchical error correction strategy is used to store text data in DNA storage which is motivated by the divide and conquer algorithm. The robust code is designed to find one-base error in character sequence, including insertion and deletion. There are three stages for error correction, which corrects the error gradually, first in DNA sequence reads, second in multiple alignments of character lines, and the third in word spelling checker. The strategy concerns English text, so the book strategy is used to encode the characters by 30 strings which has base of 6. Also, for 10 digits (0 to 9) and 26 punctuations same string book is used and to identify them 4 shadowed code is used e.g. Uppercase shift, Punctuation shift, Digit shift and Space character. The table having 30 codes of string, the minimal hamming distance is 3. Using the principle hamming distance d = 2t + 1 can correct t errors, this code book can correct 1-base error (d=3, t=1). In decoding part error correction is done in three steps, error correction by code book, error correction by sequence and error correction by word spelling. First, the sequence is cut into 6-base slices then the calculation of minimum hamming distance with the code book is done. Then detect the error slices and determine the error, correct the slice by the minimum edit distance. And do the same until the end. Then in the second level, the wrongly corrected codes in the first level are corrected using multiple alignment of the reads of the same sequence. And at the third stage a spelling correction is done by using some inbuilt package provided by corresponding language.\
Full article: https://link.springer.com/article/10.1007/s12539-021-00476-x
X. Zan et al., “A Hierarchical Error Correction Strategy for Text DNA Storage,” Interdisciplinary Sciences: Computational Life Sciences, vol. 14, no. 1, pp. 141–150, Aug. 2021, doi: 10.1007/s12539-021-00476-x.

## Cloning the repo:
> git clone https://github.com/ROCK05/Error-Correction-DNA-Storage.git \
Prefered - latest version of Visual Studio Code having C++ runing environment.
