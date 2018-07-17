#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findMatrixNumber(int x, int y, int edge=4) {
    vector<int> coordinates = helper(edge, vector<int>{x, y});
    cout << coordinates[0] << " " << coordinates[1] << endl;
    return coordinates[0]*edge + coordinates[1];
  }

  vector<int> helper(int edge, vector<int> cur) {
    if (edge==1) return vector<int>{0, 0};
    edge/=2;
    vector<int> next = helper(edge, vector<int>{cur[0]%edge, cur[1]%edge});
    if (cur[0]<edge && cur[1]<edge)
      next[1] += edge/2;
    else if (cur[0]<edge && cur[1]>=edge)
      next[1] += edge/2;
    else if (cur[0]>=edge && cur[1]>=edge)
      next[0] += edge/2, next[1] += edge/2; 
    return next;
  }
};

int main(int argc, char* argv[])
{
  cout << "Program name: " << argv[0] << endl;
  cout << "Number of input parameters: " << argc << endl;
  cout << "Starting function tests! \n" << endl;

  Solution solu;
  cout << "Matrix value at (" << 3 << ", " << 2 << "): " << solu.findMatrixNumber(3, 2) << endl;

  return 0;
}
