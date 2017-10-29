  # include <iostream>
    using namespace std;

    class A
    {
          private:
          int x;
          int y;
          public:
          A( ) 
        {
                 x=1;
                 y=2;
               }
    };

    class B : private A
    {
        public:
        int z;
        B( ) { z=3; }
    };

    int main()
    {
        B b;            // object declaration
        int *p;        // pointer declaration
        p=&b.z;        // address of public member variabe is stored                     in pointer
        cout<<endl<<" Address of z : "<<(unsigned)p <<" "<<"Value             of z :"<<*p;
        p--;            // points to previous location
        cout<<endl<<" Address of y : "<<(unsigned)p <<" "<<"Value             of y :"<<*p;
        
        p--;
        cout<<endl<<" Address of x : "<<(unsigned)p <<" "<<"Value             of x :"<<*p;
    }

 