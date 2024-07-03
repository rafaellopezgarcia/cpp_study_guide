## References

- References in C++ are used to alias objects
- Lvalue references alias existing objects
- Rvalue references extend the life of temporary objects

## What is it to take into account
- Rvalue references used in expressions default to lvalues.

## Move semantics and the fallback mechanism
Due to the fallback mechanism, if an rvalue is passed as an 
argument to a function that does not have an overload for move 
semantics, it will default into calling the function with a const
reference for that argument. If that overload does not exist, an
error will be produced.