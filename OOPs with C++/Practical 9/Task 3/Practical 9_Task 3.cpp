
#include <iostream>
using namespace std;

class test
{
   private:
    static int count;

   public:
    test()
    {
        count++;
    }
    static int obj_count()
    {
        return count;
    }
};
int test::count=0;

int main()
{
    test t1, t2, t3, t4;
    int c;
    c = test::obj_count();

    cout << "\nNumber of objects are: " << c << endl;
    return 0;
}
