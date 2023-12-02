template<auto... Xs>
struct List
{
    template<auto... Ys>
    constexpr auto prepend(List<Ys...> L) const;

    template<auto... Ys>
    constexpr auto append(List<Ys...> L) const;
};
