/*
 Briefly explain the purpose and functionality of this file (program).

 @author Tu hao wei
 @ID     B06505001
 @Department Engineering Science and Ocean Engineering
 @Affiliation National Taiwan University
*/
#include <iostream>
using namespace std;

class rectangle
{
private:
    double width;
    double length;
    double perimeter;
    double area;
public:
    // Constructor, automatically compute the perimeter and area once it is OK.
    rectangle (double wd, double lg)
    {
        width = wd; length = lg;
    };
    // Set the dimension and automatically update the perimeter and area.
    void setDimension (double wd, double lg)
    {
        width = wd; length = lg;
    };
    // Set the width and automatically update the perimeter and area.
    void setWidth (double wd)
    {
        width = wd;
    };
    // Set the length and automatically update the perimeter and area.
    void setLength (double lg)
    {
        length = lg;
    };
    // Return the width of the rectangle.
    double getWidth ()
    {
        return width;
    };
    // Return the length of the rectangle.
    double getLength ()
    {
        return length;
    };
    // Return the perimeter of the rectangle.
    double getPerimeter ()
    {
        return 2 * (length + width);
    };
    // Return the area of the rectangle.
    double getArea ()
    {
        return length * width;
    };
    // True, if width = length.
    bool isSquare ()
    {
        if(length == width)
        {
            return true;
        }
        else
        {
            return false;
        }
    };
};
