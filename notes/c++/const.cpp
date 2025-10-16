/*
used to declare variables, objects, pointers, function parameters, 
return values, and class methods as unchangeable (read-only).

https://www.geeksforgeeks.org/cpp/const-keyword-in-cpp/
*/

void const_ex() {
    
    // const int y; // not allowed
    const int y = 10;
    // y = 11 // not allowed

    // pointer to a const value
    int x = 10;
    const int *i = &x; // can't modify the value i points to, but can change where i points
    // *i = 20; // illegal
    x = 9;

    // const pointer to a non-const value
    int a = 5;
    int c = 10;
    int *const b = &a;
    *b = 10;
    a = 50;
    // b = &c; // illegal, b can't point to anything else

    // const pointer to a const value
    int xx = 10;
    int cc = 20;
    const int *const yy = &xx;
    // int xx = 10; // illegal
    // *yy = 10 // illegal
    // yy = &cc // illegal

}