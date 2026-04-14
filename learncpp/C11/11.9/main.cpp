// define your factorial() function template here
template <int N>
constexpr int factorial() {
  static_assert(N >= 0);
  int res{1};
  for (int i{2}; i <= N; ++i) {
    res*=i;
  }
  return res;
}

int main()
{
    static_assert(factorial<0>() == 1);
    static_assert(factorial<3>() == 6);
    static_assert(factorial<5>() == 120);

    factorial<-3>(); // should fail to compile

    return 0;
}
