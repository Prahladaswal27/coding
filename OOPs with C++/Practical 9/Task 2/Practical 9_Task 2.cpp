
#include <iostream>
using namespace std;

class area
{
   private:
    int len, wid, side;

   public:
    area(int l, int w)  // constructor for initialize rectangle values
    {
        len = l;
        wid = w;
        print_area(len, wid);  // call first function
    }

    area(int s)  // constructor for initialize square values
    {
        side = s;
        print_area(side);  //call second function
    }
    void print_area(int l, int w)  /*first function for calculate 
                                    area of rectangle */
    {
        float ar;
        ar = l * w; //calculate area of rectangle
        cout << "\nArea of rectangle is: " << ar << endl;
    }

    void print_area(int s)   /*first function for calculate 
                                    area of square */
    {
        float ar2;
        ar2 = s * s; //calculate area of square
        cout << "\nArea of square is: " << ar2 << endl;
    }
};

int main()
{
    int l, w, s;

    cout << "\nEnter the length and width of rectangle: ";
    cin >> l >> w;
    cout << "\nEnter the side of the square: ";
    cin >> s;

    area obj(l, w);  // call first constructor
    area obj2(s); // call second constructor

    return 0;
}
