# MagicNumber_Const

The difference between const before and after a function
A const basis

If the const keyword does not involve Pointers, which is easy to understand, here's what happens when Pointers are involved:

Int b = 500;
Const int* a = &b; [1]
Int const *a = &b; [2]
Int * const a = &b; [3]
Const int* const a = &b; [4]

If you can distinguish between the four, then congratulations, you've made a nice step. We can refer to the practice on item21 in effective c++. If const is to the left of the asterisk, const is used to modify the variable pointed to by the pointer, that is, the pointer is a constant; If const is to the right of the asterisk, const modifies the pointer itself, that is, the pointer itself is constant. Therefore, as in [1] and [2], the contents pointed to by the pointer are constant. In this case, it is not allowed to change the contents, such as *a = 3; [3] is that the pointer itself is a constant, and the content pointed to by the pointer is not a constant, in this case, the pointer itself cannot be changed, such as a++ is wrong; [4] is the pointer itself and the contents pointed to are constant quantities.
Another powerful feature of const is its use in function declarations. In a function declaration, const modifies the return value of a function, or an argument. For member functions, you can also decorate the whole function. There are several cases, which will be explained gradually: a& operator=(const a& a);
Void fun0(const a* a);
Void fun1 () const; // fun1() is a class member function
Const a fun2 ();

Two const initialization

Let's look at the const variable initialization first
1) non-pointer const constant initialization: a b;
Const a = b;

2) pointer (reference)const constant initialization: a* d = new a();
Const a* c = d;
Const a* c = new a();
Reference:
A, f.
Const a& e = f; // in this way, e can only access functions declared as const, but not general member functions;

[consideration 1] : is this assignment method correct?
Const a * c = new a ();
A * e = c;
[consideration 2] : is this assignment method correct?
A * const c = new a();
A * b = c;

Const modifier for parameters and return values

In fact, the same principle applies to both parameters and return values. Const variables are initialized when parameters are passed in and when functions return
Void fun0(const a* a); Void fun1 (const a & a);
When calling the function, const constant is initialized with the corresponding variable, then constant quantization is carried out in the function body according to the part modified by const. If the formal parameter is const a* a, the contents of the pointer passed in cannot be changed to protect the contents pointed to by the original pointer. If the formal parameter is const a& a, the reference object passed in cannot be changed, protecting the properties of the original object.
[note] : the parameter const is usually used when the parameter is a pointer or reference;
Modifies the const of the return value, such as const a fun2(); Const a * fun3 ();
After the return value is declared in this way, const modifies according to the "modifier principle" to play a corresponding protective role. Const rational operators *(const rational& LHS, const rational& RHS)
{
Return the rational (LHS) numerator () * RHS in numerator (),
LHS. The denominator () * RHS. The denominator ());
}

The return value is decorated with const to prevent this from happening :rational a,b;
Radional c;
(a * b) = c;

Const is usually used to modify the return value as the object itself when the binocular operator overloads the function and produces a new object.
In general, when the return value of a function is an object, if it is declared as const, it is usually used for operator overloading. In general, it is not recommended to use const to modify the return value of a function as an object or a reference to an object.
The reasons are as follows:
If the return value is const for an object or a reference to an object is const, the return value has a const attribute, and the return instance can only access the public data members and const member functions in class a, and no assignment is allowed on them, which is rarely used in general.

[think 3] : is it ok to define the assignment operator overload function this way?
Const a& operator=(const a& a);

The use of const in four class member functions

Void fun() const;
If a member function's member does not modify the data member, then it is best to declare it const, because const member functions do not allow data members to be modified, if modified, the compiler will report an error, which greatly improves the robustness of the program.
Some Suggestions for using const

1. Use const boldly. It will bring you endless benefits, but only if you know why.
2 to avoid the most general assignment operation error, such as const variable assignment, the specific can be seen in the thinking;
3. Using const in parameters should use a reference or pointer instead of a generic object instance, for the same reason as above;
4 three USES of const in member functions should be well used;
Do not easily set the return value of a function to const;
6. Do not specify the return value as a const reference to an object except for overloaded operators.
