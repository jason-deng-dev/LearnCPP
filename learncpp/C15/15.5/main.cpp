#include <iostream>
#include <string>

template <typename T1, typename T2, typename T3>
class Triad {
public:
  // for constructors take values by reference incase expensive type to copy
  // also use const to allow pass rvalues (literals, temporaries) AND const
  // objects
  Triad(const T1& v1, const T2& v2, const T3& v3)
      : m_v1{v1}, m_v2{v2}, m_v3{v3} {}

  // for accessor functions:
  // use const on the function body to ensure you can't change any member values
  // use const reference return type, to save copy cost, and prevent modify
  // returned value
  const T1& getV1() const { return m_v1; }
  const T2& getV2() const { return m_v2; }
  const T3& getV3() const { return m_v3; }

  // make print const after function name to make it const member function:
  // cannot modify any member variables, and can be called on const objects
  void print() const;

private:
  T1 m_v1{};
  T2 m_v2{};
  T3 m_v3{};
};

template <typename T1, typename T2, typename T3>
void Triad<T1, T2, T3>::print() const {
  std::cout << this->m_v1 << this->m_v2 << this->m_v3;
}

int main() {
  Triad<int, int, int> t1{1, 2, 3};
  t1.print();
  std::cout << '\n';
  std::cout << t1.getV1() << '\n';

  using namespace std::literals::string_literals;
  const Triad t2{1, 2.3, "Hello"s};
  t2.print();
  std::cout << '\n';

  return 0;
}
