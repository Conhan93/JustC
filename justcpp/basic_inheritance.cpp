#include <iostream>
#include <vector>
#include <string>


class Base
{
  private:
    /*
        private members in base classes are always
        inaccesible to base classes and are only
        reached through base class methods
    */
    std::string inaccessible;

    // cannot be used unless through an instantiation of base class
    void Imprivate() { std::cout << "private" << '\n';}
  protected:
    /*
        protected members are only available
        to derived classes and self.
    */
    int derivedCanSeeMe;

    void setPriv(std::string priv)
    {
      if(priv != "douchecanoe")
       this->inaccessible = priv;
    }
    void Improtected() { std::cout << "protected" << '\n';}
  public:
    /*
      Public members are available to everyone.
      Usually virtual functions for interface classes
      are declared here.

      Interfaces act as a outward face for polymorphisms
      or derived classes. defining a way for the user to
      interact with a family or category of classes/objects
    */
    std::string getPrivate() {return this->inaccessible; }

    void impublic() {std::cout << "public" << '\n';}
};

/*
    Derived classes can use access modifiers when inheriting
    from base/parent classes, this will decide the access levels
    of the base class members in the derived class. only for protected
    and public members though. private base class members are always
    inaccesible to child/derived classes and can only be used in
    implementation of base class methods.

    public inheritance
      public base members will be public in derived
      protected base members will be protected in derived
    protected inheritance
      public and protected base members will be set to protected
      in derived classes
    private inheritance
      public and protected base members will be set to private
      in derived classes

*/
class Derived : public Base
{
  private:

  public:
    Derived(std::string piv, int prot)
    {
      this->inaccessible = piv; // unable to set directly
      setPriv(piv); // set via parent class setter

      this->derivedCanSeeMe = prot; // able to set directly

      /*
          the constructor is unable to directly set the parents
          private members because parent private members are
          inaccesible to anyone but the parent, or encapsulated.

          To access the parents class private variables, the
          parents class own methods will have to be called.
          Where the parent class can control how it's members
          are accessed or used.

          the parent protected-method setPriv is used to set
          the inaccesible var.

          derivedCanSeeMe is a protected member so any derived
          classes has direct access to the member and can manipulate
          it directly.

          if we wanted to use the protected member from outside of a
          class we would have to go through a method like setPriv.

          protected and private set levels of encapsulation.
          where protected extends encapsulation to a family of classes
          and private provides encapsulation only for itself.
      */
    };

};


int main()
{
  Derived derived = Derived("inaccessible", 10);

  derived.Imprivate() // unable to call, inaccesible to child class
  derived.Improtected() // unable to call, protected in child class
  derived.impublic(); // able to call with public inheritance  from parent

  std::cout << derived.getPrivate() << '\n';
  /*
      This uses a method from the parent class to
      access the private member of the parent class
      which is otherwise inaccesible outside the parent class
  */


}
