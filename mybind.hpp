#ifndef	MYBIND_HPP_
# define MYBIND_HPP_

// These functions have for aim to simulate boost::bind with boost::ref.
// We call the static member function creatCallBack and with the partial specialisation.
// We recup an generic object and we can put it in STL contener or array/list.
// I made surcharges from 0 to 9 arguments.
// The only signature exeption which isn't accept is for functions : void(...),
// because the aim of a callback, for me, is to return at least true/false
// Ex.: If we creat Mybind<int(int, char)>::creatCallBack(&Class::func, Class&)
//      We recup function in a pointer : Mybind<int(int, int)>::ICallObj*
//      and we can put it in a std::vector<Mybind<int(int, int)>::ICallObj*> with
//      other functions with the same signature.

template<typename RET>
class	Mybind;

#define CALLBACK_(COMA, _ARG, _TPARG, NMPARAM, TPTPARM)			\
template<typename RET COMA _ARG>					\
class	Mybind<RET(_TPARG)>						\
{									\
public:									\
  Mybind() {};								\
  virtual ~Mybind() {};							\
									\
public:									\
  class	ICallObj							\
  {									\
  public:								\
    virtual ~ICallObj() {};						\
    virtual RET	operator()(_TPARG) = 0;					\
  };									\
									\
private:								\
  template<typename T, typename U>					\
  class	CallObj : public ICallObj					\
  {									\
  public:								\
    CallObj() {};							\
    CallObj(T _func, U& _instence)					\
      :func(_func), instence(_instence) {};				\
    virtual ~CallObj() {};						\
    virtual RET	operator()(TPTPARM) {					\
      return (this->instence.*this->func)(NMPARAM);			\
    };									\
									\
  private:								\
    T	func;								\
    U&	instence;							\
  };									\
									\
public:									\
  template<typename TYPE, typename INST>				\
  static ICallObj*	creatCallBack(TYPE _func, INST& _instence) {	\
    ICallObj*	obj = new CallObj<TYPE, INST>(_func, _instence);	\
    return obj;								\
  };									\
};									\

#define CAT(a, b) a ## b
#define ENUM1(A) CAT(A, 1)
#define ENUM2(A) ENUM1(A) , CAT(A, 2)
#define ENUM3(A) ENUM2(A) , CAT(A, 3)
#define ENUM4(A) ENUM3(A) , CAT(A, 4)
#define ENUM5(A) ENUM4(A) , CAT(A, 5)
#define ENUM6(A) ENUM5(A) , CAT(A, 6)
#define ENUM7(A) ENUM6(A) , CAT(A, 7)
#define ENUM8(A) ENUM7(A) , CAT(A, 8)
#define ENUM9(A) ENUM8(A) , CAT(A, 9)

#define	TPTPARM1(A, B) CAT(A, 1) CAT(B, 1)
#define	TPTPARM2(A, B) TPTPARM1(A, B), CAT(A, 2) CAT(B, 2)
#define	TPTPARM3(A, B) TPTPARM2(A, B), CAT(A, 3) CAT(B, 3)
#define	TPTPARM4(A, B) TPTPARM3(A, B), CAT(A, 4) CAT(B, 4)
#define	TPTPARM5(A, B) TPTPARM4(A, B), CAT(A, 5) CAT(B, 5)
#define	TPTPARM6(A, B) TPTPARM5(A, B), CAT(A, 6) CAT(B, 6)
#define	TPTPARM7(A, B) TPTPARM6(A, B), CAT(A, 7) CAT(B, 7)
#define	TPTPARM8(A, B) TPTPARM7(A, B), CAT(A, 8) CAT(B, 8)
#define	TPTPARM9(A, B) TPTPARM8(A, B), CAT(A, 9) CAT(B, 9)

#define	CM	,

CALLBACK_(,,,,)
CALLBACK_(CM, ENUM1(typename A), ENUM1(A), ENUM1(_), TPTPARM1(A, _))
CALLBACK_(CM, ENUM2(typename A), ENUM2(A), ENUM2(_), TPTPARM2(A, _))
CALLBACK_(CM, ENUM3(typename A), ENUM3(A), ENUM3(_), TPTPARM3(A, _))
CALLBACK_(CM, ENUM4(typename A), ENUM4(A), ENUM4(_), TPTPARM4(A, _))
CALLBACK_(CM, ENUM5(typename A), ENUM5(A), ENUM5(_), TPTPARM5(A, _))
CALLBACK_(CM, ENUM6(typename A), ENUM6(A), ENUM6(_), TPTPARM6(A, _))
CALLBACK_(CM, ENUM7(typename A), ENUM7(A), ENUM7(_), TPTPARM7(A, _))
CALLBACK_(CM, ENUM8(typename A), ENUM8(A), ENUM8(_), TPTPARM8(A, _))
CALLBACK_(CM, ENUM9(typename A), ENUM9(A), ENUM9(_), TPTPARM9(A, _))

#endif // !MYBIND_HPP_
