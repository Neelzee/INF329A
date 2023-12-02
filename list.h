#include <concepts>


template<auto... Xs>
struct List
{
    template<auto... Ys>
    constexpr auto prepend(List<Ys...> L) const;

    template<auto... Ys>
    constexpr auto append(List<Ys...> L) const;

    constexpr auto cons(auto X) const;

    constexpr auto lenght() const;
};

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

template<typename... Ts>
concept AllComparable = (Comparable<Ts> && ...);

template<auto... Xs>
requires AllComparable<decltype(Xs)...>
struct ListC{
    template<auto... Ys>
    requires AllComparable<decltype(Ys)...>
    constexpr auto append(ListC<Ys...> L) const {
        return ListC<Xs..., Ys...>();
    }
};
