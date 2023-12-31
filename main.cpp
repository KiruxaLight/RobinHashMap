#include "testing.h"

int main() {
  internal_tests::run_all();

  HashMap<int, int> map;
  using HashMapIterator = HashMap<int, int>::iterator;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    char code;
    int key;
    std::cin >> code;
    if (code != '!' && code != '<')
      std::cin >> key;
    if (code == '-')
      map.erase(key);
    else if (code == '?') {
      auto it = map.find(key);
      std::cout << (it == map.end() ? -1 : it->second) << "\n";
    } else if (code == '+') {
      int val;
      std::cin >> val;

      map[key] = val;
    } else if (code == '<') {
      for (HashMapIterator it = map.begin(); it != map.end(); ++it)
        std::cout << it->first << " " << it->second << "\n";
    } else if (code == '!')
      map.clear();
  }

  std::cout << map.size() << "\n";
  return 0;
}