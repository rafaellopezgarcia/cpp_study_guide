# Emplace back and push back

I have been confused about `emplace_back` and `push_back` over my C++ career,
thinking that the former is a better, upgraded version of the latter and it
should always be used. 

Incorrectly, I have thought that `emplace_back` is more efficient, as it 
prefers the use of move constructors over copy constructors. This is however 
not precise.

The main difference between `emplace_back` and `push_back` is that 
- `emplace_back` is a variadic template with a parameter pack of universal 
references that are forwarded to the constructors. The constructors can be
either a constructor, a copy constructor, or a move constructor.

- `push_back` provides overloads for copy and a move constructors.

This means that if you have a vector of a data type which constructor has
default constructor does not take any parameters, you can make the following
call.

```c++
std::vector<Foo> v;
v.emplace_back();
// v.push_bacl(); // Error. Won't compile.
```

## When to pick one over the other

According to Scott Mayers

Emplacement's advantage over insertion generally stems from the fact that
its interface doesn't require the creation and destruction of a temporary
object **when the argument(s) passed are of a type other than that held
by the container**.

In emplacement functions, perfect-forwarding defers the creation of the 
resouce-managing objects until they can be constructed in the container's
memory, and that opens a window during which exceptions can lead to 
resource leaks.

`emplace_back` leads to potential improved code efficiency at the cost of
diminished exception safety.