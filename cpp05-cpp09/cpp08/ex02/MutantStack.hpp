#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

// 어뎁터인 std::stack안에는 iterator가 없지만 stack안에 있는 container_type deque에는
// begin, end()가 있다.  그 점을 이용해 stack을 새롭게 구현하는 문제

// https://cplusplus.com/reference/list/list/?kw=list
// 리스트의 iterator부분을 참고하여 구현

/*
class _LIBCPP_TEMPLATE_VIS stack
{
public:
    typedef _Container                               container_type;
    typedef typename container_type::value_type      value_type;
    typedef typename container_type::reference       reference;
    typedef typename container_type::const_reference const_reference;
    typedef typename container_type::size_type       size_type;
    static_assert((is_same<_Tp, value_type>::value), "" );

protected:
    container_type c;
*/

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	//--------occf-----------start-
	MutantStack(void) {std::cout << "occf디폴트 생성자 호출" << std::endl;};
	MutantStack(const MutantStack& obj) {std::cout << "occf 복사 생성자 호출" << std::endl; *this = obj;};
	MutantStack& operator=(const MutantStack& obj) {std::cout << "occf 복사 할당 연산자 호출" << std::endl; *this = obj; return (*this);}
	~MutantStack(void) {std::cout << "occf 소멸자 호출" << std::endl;};
	//----------occf---------end-

	// 반복자(iterator)를 stack을 상속받은 MutantStack에 추가
	typedef typename MutantStack<T>::stack::container_type::iterator iterator;
	iterator begin(void) {return this->c.begin();}
	iterator end(void) {return this->c.end();}

	// 역순으로 정렬되어 있는 반복자(iterator)를 반복합니다.
	typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin(void) {return this->c.rbegin();}
	reverse_iterator rend(void) {return this->c.rend();}

};

#endif
