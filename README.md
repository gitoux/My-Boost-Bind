My-Boost-Bind
=============

My first step in C++ meta-programming.

For a school project I had to creat a callable object which can call a member function,
which is situated in a specific instance.
I hadn't the right to use Boost library, so I re-code a boost::bind/boost::ref light.
It's a limited callable object, but it's the first time I use meta-programmation in C++, so I'm a little proud of me.

I creat an Object with the type : Mybind<TYPE>::ICallObj
Type is a function's signature.
I developed this code because I wanted to develop a Proactor for my project, so the signature in : void(), isn't accepted,
and it doesn't take a C function's pointer.
But you can put this Object in a std::vector or other, you are just limited by the signature.

You can declare two differents class like this :

class     test1
{
  public:
  test1() {};
  ~test1() {};
  int  test1() {
  std::cout << "test1" << std::endl;
  };
}

class     test2
{
  public:
  test2() {};
  ~test2() {};
  int  test2() {
  std::cout << "test2" << std::endl;
  };
}

and you can use Mybind to put two diffentes member's functions in the same list/vector.
For use it, you have just to call : creatCallBack(TYPE _func, INST& _instence).

All the macro generates a code which can take 0 to 9 arguments.

This project isn't finished, and it can't replace boost::bind and boost::ref, but I think I will continue to develop it for the fun !

Have fun if you want to use it =D
