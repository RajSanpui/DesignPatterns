// An example of abstract Car Factory - skeletal format

#include <iostream>
using namespace std;

class CarFactory {
   int mileage;
   int engine;

   public:
       void displayCar() = 0;
};

class IndianCarFactory : public CarFactory {
    
};

class Maruti : public IndianCarFactory {

};

class SUV : public IndianCarFactory {

};


class EuropeanCarFactory : public CarFactory {

};

class Volkswagen : public EuropeanCarFactory {
     
};

class Ferrari : public EuropeanCarFactory {

};

class AutoMobileFactory {
   public:
         CarFactory* createIndianCar( ) = 0;
         CarFactory* createEuropeanCar( ) = 0;
};

class ConcreteFactory {
     public:
          CarFactory* createIndianCar(string cost)
          {
              if (cost == "low")
                return new Maruti;
              else 
                return new SUV;
          }

          CarFactory* createEuropeanCar(string style)
          {
               if (style == "stylish")
                  return new Ferrari;
               else
                   return new Volkswagen;
           }
};
