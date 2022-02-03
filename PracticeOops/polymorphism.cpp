#include <iostream>
using namespace std;

class A
{
public:
  virtual ~A () { }
};

class B : public A
{
};

void rttiTest(A* a)
{
  try
    {
        cout << "here I am 1\n";
        B* b = dynamic_cast<B*> (a);
        cout << "here I am 2\n";
        if (!b)
        {
            std::cout << "Null cast\n";
        }
        else
        {
            std::cout << "Pass\n";
        }
    }
  catch (std::bad_cast)
    {
      std::cout << "Invalid cast.\n";
    }
}

int main()
{
    A *a1 = new B;
    std :: cout << "test 1" << std::endl;
    rttiTest(a1);
    A *a2 = new A;
    std :: cout << "test 2" << std::endl;
    rttiTest(a2); 

    std :: cout << "test 3" << std::endl;
    B *b2 = new B();
    delete b2;
    // b2 = NULL;
    rttiTest(b2);

  return 0;
}