#include <iostream>

using namespace std;

class Base {
protected:
    string m_name;    
public:
    Base (){
        cout << "Base's constructor" << endl;
    }

    Base (string name) : m_name(name){
        cout << "Base's constructor: " << name << endl;
    }

    virtual void f() {
        cout << "Base f() " << m_name << endl;
    }

    virtual ~Base () {
        cout << "Base's destructor " << m_name << endl;
    }
};

class Derived: public Base {
private:
    Base objBase;
public:
    Derived (){
        cout << "Derived's constructor" << endl;
    }

    Derived (string name) : objBase(name) {
        cout << "Derived's constructor: " << m_name << endl;
    }

    // Derived (string name) {
    //     cout << "Derived's constructor: " << m_name << endl;
    // }
    
    void f() override{
        cout << "Derived f() " << m_name << endl;
    }

    void f1() {
        cout << "Derived f1() " << m_name << endl;
    }

    ~Derived () {
        cout << "Derived's destructor " << m_name << endl;
    }
};

class Derived1: public Derived {
public:
    Derived1 (){
        cout << "Derived1's constructor" << endl;
    }

    Derived1 (string name) : Derived(name) {
        cout << "Derived1's constructor: " << m_name << endl;
    }
    
    // Derived1 (string name) {
    //     cout << "Derived1's constructor: " << m_name << endl;
    // }
    
    void f() override{
        cout << "Derived1 f() " << m_name << endl;
    }

    ~Derived1 () {
        cout << "Derived1's destructor " << m_name << endl;
    }
};

int main() {
   Base *p = new Derived1("p");
   cout << "--------------------------" << endl;
   Derived *q = new Derived1("q");
   cout << "--------------------------" << endl;
   Derived1 *r = new Derived1("r");
   cout << "--------------------------" << endl;
   Derived s("s");
   cout << "--------------------------" << endl;
   Derived1 t("t");
   cout << "--------------------------" << endl;
   
   p->f();
   cout << "--------------------------" << endl;
   q->f();
   cout << "--------------------------" << endl;

   q->f1();
   cout << "--------------------------" << endl;
   
   r->f();
   cout << "--------------------------" << endl;
   s.f();
   cout << "--------------------------" << endl;
   t.f();
   cout << "--------------------------" << endl;

   Derived u;
   cout << "--------------------------" << endl;
   u.f();
   cout << "--------------------------" << endl;

   delete p;
   cout << "--------------------------" << endl;
   delete q;
   cout << "--------------------------" << endl;
   delete r;
   cout << "--------------------------" << endl;

   return 0;
}