#include <iostream>

#define or_ << elvis_() <<

template<typename T>
struct elvis
{
  T && t;

  template<typename U>
  friend decltype(auto) operator << (elvis<T> const & e, U && u)
  {
    return std::move(
      static_cast<bool>(e.t) ? e.t : u
    );
  }
};

struct elvis_
{
  template<typename T>
  friend decltype(auto) operator << (T && t, elvis_ const &)
  {
    return elvis<T>{ std::move(t) };
  }
};

int main()
{
  auto result = 0 or_ 1;
  std::cout << ">>" << result << std::endl;
}