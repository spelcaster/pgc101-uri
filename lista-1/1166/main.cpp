#include <iostream>
#include <vector>
#include <cmath>

void dump(const std::vector< int >&);

int main(int argc, char *argv[])
{
  int T;

  std::cin >> T;

  for (int i = 0; i < T; ++i) {
    int N;
    int ball = 1;
    int currentPeg = 0;

    std::vector< int > pegs;

    std::cin >> N;

    pegs.resize(N, 0);
    for (ball; ball <= 100000; ++ball) {
      currentPeg = 0;
      for (int i = 0; i < N; i++) {
        if (pegs[currentPeg] == 0) {
          pegs[currentPeg] = ball;
          break;
        }

        int v = ball + pegs[currentPeg];
        double sqrtNum = sqrt(v);

        if (fmod(v, sqrtNum) > 0) {
          ++currentPeg;
          continue;
        }

        pegs[currentPeg] = ball;
        break;
      }

      dump(pegs);

      if (pegs[currentPeg] != ball) {
        break;
      }
    }

    int result = -1;

    if (pegs[currentPeg] != ball) {
      result = ball - 1;
    }

    std::cout << result << std::endl;
  }

  return 0;
}

void dump(const std::vector< int >& vec)
{
  auto it = vec.cbegin();

  while (it != vec.cend()) {
    std::cout << *it << "\t";
    ++it;
  }

  std::cout << std::endl;
}
