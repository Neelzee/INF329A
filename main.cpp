#include <iostream>

/// ================= GET ================

template<std::size_t n, auto X, auto... Xs>
constexpr auto get(List<X, Xs...> l)
requires (n <= sizeof...(Xs))
{
    if constexpr (n == 0) {
        return X;
    } else {
        return get<n - 1>(List<Xs...>());
    }
}

/// ======================================




int main() {

    std::cout << "Hello, World!" << std::endl;

    return 0;
}


