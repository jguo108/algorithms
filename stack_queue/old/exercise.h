#ifndef EXERCISE
#define EXERCISE

#include <iostream>
#include <vector>

class Exercise 
{
  public:
    static int RPNExpression(const std::vector<std::string>& expression);
      // EPI, Problem 9.2, Page 120

    static bool testWellFormedness(const std::vector<char>& input);
      // EPI, Problem 9.3, Page 122 (Uncompleted)

    static std::string normalizePathname(const std::string& path);
      // EPI, Problem 9.4, Page 122 (Uncompleted)

    static void searchPostingList(); 
      // EPI, Problem 9.5, Page 124 (Uncompleted)

    static std::vector<int> sunsetViewEastToWest(const std::vector<int>& buildings); 
      // EPI, Problem 9.6, Page 126

    static std::vector<std::vector<int>> BSTNodesInOrderOfDepth();
      // EPI, Problem 9.7, Page 128 (This should be done as part of BST chapter)
};

#endif
