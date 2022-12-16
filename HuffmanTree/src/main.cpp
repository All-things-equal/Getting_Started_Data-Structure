#include <cstdio>
#include <cstdlib>
#include "Huffman.h"

int main(int argc, char const *argv[])
{
      char test1[] = "I love FishC.com!";
      char test2[] = "0011111000111";
      HuffmanTree *codeTree = BuildTree(test1);
      hlTable *codeTable = BuildTable(codeTree);
      EnCode(codeTable, test1);
      DeCode(codeTree, test2);
      return 0;
}
