#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

class IColor
{
public:
    virtual string Color() = 0;
};

class RedColor: public IColor
{
public:
    string Color()
    {
        return "of Red Color";
    }
};

class BlueColor: public IColor
{
public:
    string Color()
    {
        return "of Blue Color";
    }
};


class IShape
{
public:
virtual string Draw() = 0;
};

class Circle: public IShape
{
        IColor* impl;
    public:
        Circle(IColor *obj):impl(obj){}
        string Draw()
        {
            return "Drawn a Circle "+ impl->Color();
        }
};

class Square: public IShape
{
        IColor* impl;
    public:
        Square(IColor *obj):impl(obj){}
        string Draw()
        {
        return "Drawn a Square "+ impl->Color();;
        }
};

int main()
{
IColor* red = new RedColor();
IColor* blue = new BlueColor();

IShape* sq = new Square(red);
IShape* cr = new Circle(blue);

cout<<"\n"<<sq->Draw();
cout<<"\n"<<cr->Draw();

delete red;
delete blue;
return 1;
}
