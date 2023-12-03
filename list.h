#include <concepts>
#include <type_traits>
#include <string>

#pragma once

template<auto... Xs>
struct List
{
    template<auto... Ys>
    constexpr auto prepend(List<Ys...>) const {
        return List<Ys..., Xs...>();
    }

    constexpr auto prepend(List<>) const {
        return List<Xs...>();
    }

    template<auto... Ys>
    constexpr auto append(List<Ys...> L) const {
        return L.prepend(List<Xs...>());
    }

    constexpr auto append(List<> L) const {
        return List<Xs...>();
    }

    constexpr std::size_t length() const {
        return sizeof... (Xs);
    }
};



// Concept to check if F is invocable with a specific argument type
template<typename F, typename Arg>
concept InvocableWith = std::is_invocable_r_v<bool, F, Arg>;

template<typename T>
concept Comparable = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
    { a <= b } -> std::convertible_to<bool>;
    { a > b } -> std::convertible_to<bool>;
    { a >= b } -> std::convertible_to<bool>;
    { a == b } -> std::convertible_to<bool>;
};

template<typename T>
concept BoolConvertible = requires(T x) {
    { static_cast<bool>(x) } -> std::convertible_to<bool>;
};

template<typename T>
concept IsNumeric = std::is_arithmetic_v<T>;


template<typename... Ts>
concept AllComparable = (Comparable<Ts> && ...);


constexpr std::string to_string(List<>) {
    return "<>";
}

template<auto X>
constexpr std::string to_string(List<X>) {
    return ("[ " + std::to_string(X) + " ]");
}

template<auto X, auto... Xs>
requires (IsNumeric<decltype(X)> && (IsNumeric<decltype(Xs)> && ...))
constexpr std::string to_string(List<X, Xs...>) {
    std::string pm = (... + (std::to_string(Xs) + ", "));
    pm.pop_back();
    pm.pop_back();
    return ("< " + std::to_string(X) + ", " + pm +  " >");
}

template<auto X, auto... Xs>
constexpr auto cons(List<Xs...>) {
    return List<X, Xs...>();
}

template<auto X, auto... Xs>
constexpr auto cons_append(List<Xs...>)  {
    return List<Xs...>().append(List<X>());
}