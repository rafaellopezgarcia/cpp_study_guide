# Perfect forwarding
Perfect forwarding avoids assumptions about the value category of
a variable, passing it with the original value category.

Perfect forwarding appears in function templates with the following
signature.

```c++
template <typename T>
void foo(T&& arg) {
    bar(std::forward<T>(arg));
}
```

In that case, `arg` is passed to `bar` with the value category used 
to call `foo`.

Perfect forwarding also appears inside the body of a function when 
using `auto&&`.

```c++
void f() {
    auto&& val = compute();
    process(std::forward<decltype(val)>(val));
}
```

Similarly, `val` will be passed to `process` with the value category
and type from `compute`.