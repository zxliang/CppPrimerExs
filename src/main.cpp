#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findMatrixNumber(int x, int y, int edge=4) {
    return helper(edge, vector<int>{x, y});
  }

  int helper(int edge, vector<int> cur) {
    if (edge==1) return 0;
    edge/=2;
    int next = helper(edge, vector<int>{cur[0]%edge, cur[1]%edge});
    if (cur[0]<edge && cur[1]<edge)
      next += edge*edge;
    else if (cur[0]<edge && cur[1]>=edge)
      next += edge*edge*2;
    else if (cur[0]>=edge && cur[1]>=edge)
      next += edge*edge*3; 
    return next;
  }
};

int main(int argc, char* argv[])
{
  cout << "Program name: " << argv[0] << endl;
  cout << "Number of input parameters: " << argc << endl;
  cout << "Starting function tests! \n" << endl;

  Solution solu;
  for (int i=0; i<4; i++) 
    for (int j=0; j<4; j++) 
      cout << "Matrix value at (" << i << ", " << j << "): " << solu.findMatrixNumber(i, j) << endl;

  return 0;
}
