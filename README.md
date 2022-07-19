# Huffman Coding : 
### (Encrypting the input file & decrypting the original text back)
A C++ compression and decompression project based on Huffman Coding.

## Introduction :

This project is to design compression and decompression programs based on Huffman Coding.
The idea of Huffman Coding is to minimize the weighted expected length of the code by means of assigning shorter codes to frequently-used characters and longer codes to rarely used characters.

## Implementation Details:

The programs can compress and decompress text consisting of 128 ASCII characters.

### Compression:

1. Open input file, count and store the frequencies of different characters;
2. Construct Priority Queue and then Huffman Tree;
3. Calculate Huffman Encode Table;
4. Encode the text, store Huffman Encode Table and encoded it.

### Decompression:

1. Recreate Huffman Tree based on Huffman Encode Table;
2. Decode the text based on the tree.
