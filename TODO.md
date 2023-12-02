## `Vec` Functions

### Member Functions

- [x] `(::)` : `(x : a) -> (xs : Vec a n) -> Vec a (S n)`
- [x] `prepend` : `(xs : Vec a n) -> (ys : Vec a m) -> Vec a (m + m)`
- [x] `append` : `(xs : Vec a n) -> (ys : Vec a m) -> Vec a (n + m)`
- [x] `length` : `(xs : Vec a n) -> Nat`

### Basic Operations

- [x] `Nil` : `Vec a 0`
- [x] `(!)` : `(xs : Vec a (S n)) -> Fin (S n) -> a`
- [x] `head` : `(xs : Vec a (S n)) -> a`
- [x] `tail` : `(xs : Vec a (S n)) -> Vec a n`
- [x] `last` : TODO
- [x] `init` : TODO
- [x] `reverse` : `(xs : Vec a n) -> Vec a n`

### List Transformation

- [x] `map` : `(f : a -> b) -> (xs : Vec a n) -> Vec b n`
- [x] `zip` : `(xs : Vec a n) -> (ys : Vec b n) -> Vec (a, b) n`
- [x] `zip3` : `(xs : Vec a n) -> (ys : Vec b n) -> (zs : Vec c n) -> Vec (a, b, c) n`

### List Reduction

- [x] `foldl` : `(f : a -> b -> a) -> (acc : a) -> (xs : Vec b n) -> a`
- [x] `foldr` : `(f : a -> b -> b) -> (z : b) -> (xs : Vec a n) -> b`
- [x] `take` : `(k : Nat) -> (xs : Vec a n) -> Vec a (min k n)`
- [x] `drop` : `(k : Nat) -> (xs : Vec a n) -> Vec a (n - k)`
- [x] `splitAt` : `(k : Nat) -> (xs : Vec a n) -> (Vec a k, Vec a (n - k))`
- [x] `takeWhile` : `(p : a -> Bool) -> (xs : Vec a n) -> Vec a m`
- [x] `dropWhile` : `(p : a -> Bool) -> (xs : Vec a n) -> Vec a m`
- [x] `filter` : `(p : a -> Bool) -> (xs : Vec a n) -> Vec a m`
- [x] `partition` : `(p : a -> Bool) -> (xs : Vec a n) -> (Vec a m, Vec a k)`

### List Searching

- [x] `elem` : `(x : a) -> (xs : Vec a n) -> Bool`
- [x] `find` : `(p : a -> Bool) -> (xs : Vec a n) -> Maybe a`
- [x] `findIndex` : `(p : a -> Bool) -> (xs : Vec a n) -> Maybe (Fin n)`

### List Sorting and Grouping

- [x] `sort` : `(xs : Vec a n) -> Vec a n`
- [x] `sortBy` : `(cmp : a -> a -> Ordering) -> (xs : Vec a n) -> Vec a n`
- [x] `unique` : TODO
- [x] `group` : `(xs : Vec a n) -> Vec (Vec a m) k`
- [x] `groupBy` : `(cmp : a -> a -> Bool) -> (xs : Vec a n) -> Vec (Vec a m) k`

### List Indexing and Slicing

- [ ] `span` : `(p : a -> Bool) -> (xs : Vec a n) -> (Vec a m, Vec a k)`

### List Folds and Reduces

- [ ] `sum` : `(xs : Vec Nat n) -> Nat`
- [ ] `product` : `(xs : Vec Nat n) -> Nat`
- [ ] `maximum` : `(xs : Vec Nat (S n)) -> Nat`
- [ ] `minimum` : `(xs : Vec Nat (S n)) -> Nat`

### List Range and Replication

- [ ] `replicate` : `(k : Nat) -> (x : a) -> Vec a k`
- [ ] `range` : `(from : Nat) -> (to : Nat) -> Vec Nat (to - from)`

### List Conversion

- [ ] `fromList` : `(xs : List a) -> Vec a n`
- [ ] `toList` : `(xs : Vec a n) -> List a`
