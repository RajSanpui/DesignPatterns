
#include <iostream>
using namespace std;

class Builder {
   public:
       virtual string cookMainCourse() = 0;
       virtual string getSideDish() = 0;
       virtual string getCompDrinks() = 0;
};

class ChineseBuilder : public Builder
{
   public:
     string cookMainCourse() {return "Noodles";}
     string getSideDish() {return "spaggheti";}
     string getCompDrinks() {return "Vodka";}
};

class IndianBuilder : public Builder
{
   public:
     string cookMainCourse() {return "Biriyani";}
     string getSideDish() {return "Rasgulla";}
     string getCompDrinks() {return "Wine";}
};

class Director {
  Builder *builder;

   public:
        void setBuilder(Builder *b)
        {
            builder = b;
        }

        void getFood()
        {
            cout << "Cooked: " << builder->cookMainCourse() << endl;
            cout << "SideDish: " << builder->getSideDish() << endl;
            cout << "Complimentary drinks: " << builder->getCompDrinks() << endl;
        }
};

class Client {
   public:
         void orderFood(string order)
         {
              if (order == "Chinese")
              {
                Director d;
                d.setBuilder(new ChineseBuilder);
                d.getFood();
              }
              else if (order == "Indian")
              {
                Director d;
                d.setBuilder(new IndianBuilder);
                d.getFood();
              }
              else {
                 cout << "Food not available in restaurant" << endl;
              }
          }
};

int main()
{
   Client c;
   c.orderFood("Chinese");
   
   cout << endl;
   c.orderFood("Indian");
   
   cout << endl;
   c.orderFood("Rusian");
    
}        
