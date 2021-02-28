#include <iostream>
using namespace std;
 
  class PowerSupply
  {
     public:
        virtual int plugin() = 0;
        virtual int live() = 0;
        virtual int power() = 0;
   };
 
   // Adaptee
   class Socket : public PowerSupply
   {
      public:
         int plugin()
         {
             return 220; // 220 Voltage
         }

         int live() { return 1;}
         int power() { return 1;}
    };
 
   // Adapter - wraps the adaptee
   class Adapter : public PowerSupply
   {
       public:
         Socket *socket = new Socket();
         
         int plugin()
         {
             return 120; // 220 Voltage
         }

         // Wrappers below
         int live() { return socket->live(); }
         int power() { return socket->power(); }
               
   };
 
   class kettle
   {
      int voltage;
      PowerSupply *a;
      public:
         void plugin(PowerSupply *a)
         {
             voltage = a->plugin();
             cout << "Kettle voltage: " << voltage << endl;
             this->a = a;
         }
 
         void switchOn()
          {
             if ((voltage > 120) && (a->power() && a->live()))
              {
                 cout << "Kettle on fire" << endl;
              }
              else if ((voltage <= 120) && (a->power() && a->live())) {
                 cout << "Water boiling" << endl;
              }
           }
    };
 
    int main()
    {
       PowerSupply *direct = new Socket;
       PowerSupply *adapter = new Adapter;
 
       kettle *mykettle = new kettle;
 
       cout << "Kettle directly to A/C mains" << endl;
       mykettle->plugin(direct); 
       mykettle->switchOn();
 
       cout << endl;
 
       cout << "Kettle through adapter:" << endl;
       mykettle->plugin(adapter);
       mykettle->switchOn();
    }
