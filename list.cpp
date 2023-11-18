#include "list.h"

template<auto... Ys>
constexpr auto List::prepend(List<Ys...> L) const {
    return List<Xs..., Ys...>();
}
