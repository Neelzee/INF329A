template<auto... Xs>
struct List
{
    template<auto... Ys>
    constexpr auto prepend(List<Ys...> L) const;
};
