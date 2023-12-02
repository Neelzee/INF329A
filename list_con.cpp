#include "list_con.h"

template <typename T, std::size_t N>
requires (N > 0)
constexpr auto arrayToList(const T (&array)[N]) {
    return atl(array, List<>());
}

template <typename T, std::size_t N, auto... Xs>
requires (N > 0)
constexpr auto atl(const T (&array)[N], List<Xs...> l) {

    T arr[N - 1];

    for (int i = 0; i <= N - 1; i++) {
        arr[i] = array[i];
    }

    return l.cons(array[0]).prepend(atl(arr, l));
}

template <auto... Xs>
constexpr auto listToArray(List<Xs...>) {

}
template <typename T, std::size_t N>
constexpr auto lta(List<>, const T (&array)[N]) {
    return array;
}

template <std::size_t N, auto... Xs, typename T>
constexpr auto lta(List<Xs...> l, const T (&array)[N]) {
    T arr[N + 1];

    for (int i = 0; i <= N; i++) {
        arr[i] = array[i];
    }

    arr[N + 1] = head(l);

    return lta<N + 1>(init(l), arr);
}