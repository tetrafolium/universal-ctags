namespace S {
struct T {
  enum E {
    alpha,
    beta,
  } elt;
};
} // namespace S

struct S::T s = {.elt = S::T::E::alpha};
