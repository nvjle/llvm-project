// RUN: %clang_cc1 -fexperimental-new-constant-interpreter -verify=expected,both %s
// RUN: %clang_cc1 -verify=ref,both %s

struct Foo {
  int a;
};

constexpr int dead1() { // expected-error {{never produces a constant expression}}

  Foo *F2 = nullptr;
  {
    Foo F{12}; // expected-note 2{{declared here}}
    F2 = &F;
  } // Ends lifetime of F.

  return F2->a; // expected-note 2{{read of variable whose lifetime has ended}} \
                // ref-note {{read of object outside its lifetime is not allowed in a constant expression}}
}
static_assert(dead1() == 1, ""); // both-error {{not an integral constant expression}} \
                                 // both-note {{in call to}}


