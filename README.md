# C++17 New Features
Some brief code I wrote to showcase a few new language features of C++17. Specifically, I demonstrated: 
* `if constexpr`
* `constexpr` lambda functions 
* capturing `*this` in lambda functions

## `if constexpr`
This allows for compile-time evaluation of an `if` statement. It is typically used in conjunction with templates and some Boolean operator. The unused branch of the `if` statement is discarded, meaning it does not have to be able to compile.

It is similar to `std::enable_if` but much cleaner.

## `constexpr` lambdas
Functions could be declared `constexpr` since C++11 but not lambda functions. In C++17, lambdas are implicitly `constexpr` when all conditions are satisfied. This allows lambda functions to be evaluated at compile time. One can also explicitly declare a lambda as `constexpr`.

## Capturing `*this` in lambda functions
Lambda functions can be used within a class to access member variables of that class, but must explicitly capture `this`.

Until C++14, one could only capture by reference. C++17 introduced a solution for cleanly capturing `*this` by value.
