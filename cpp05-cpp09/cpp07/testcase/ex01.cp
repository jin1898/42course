class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}

# ex01.cp 테스트케이스 돌리는법 : (1)makefile에서 "SCRS = ex01.cp"로 바꾸기 (2) iter.hpp에서 print 비활성화하기 (3) ex01.cp에서 헤더파일 #include "iter.hpp"추가하기
