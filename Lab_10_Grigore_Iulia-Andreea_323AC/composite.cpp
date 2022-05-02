#include <algorithm>
#include <iostream>
#include <list>
#include <string>

using namespace std;
/*
Pros:
-> Se poate lucra cu structuri de tip arbore complexe mai convenabil, utilizand polimorfismul și recursiunea.
-> Codul este usor extensibil, adica se pot adauga functionalitati noi, fara sa fie afectat codul vechi/actual.

Cons:
-> Ar putea fi dificil de oferit o interfață comună pentru clasele a căror funcționalitate diferă 
  prea mult fata de design-ul celor specifice acestui pattern.
*/
class Component 
{
  protected:
    Component *parent_var;

  public:
    virtual ~Component() {}
    void SetParent(Component *parent) 
    {
      this->parent_var = parent;
    }
    Component *GetParent() const 
    {
      return this->parent_var;
    }
  
    virtual void Add(Component *component) {}
    virtual void Remove(Component *component) {}

    virtual bool IsComposite() const 
    {
      return false;
    }

    virtual string Operation() const = 0;
};

class Leaf : public Component 
{
  public:
    string Operation() const override 
    {
      return "Frunza";
    }
};

class Composite : public Component 
{
  protected:
    list<Component *> children_var;

  public:
    void Add(Component *component) override 
    {
      this->children_var.push_back(component);
      component->SetParent(this);
    }

  void Remove(Component *component) override 
  {
    children_var.remove(component);
    component->SetParent(nullptr);
  }

  bool IsComposite() const override 
  {
    return true;
  }

  string Operation() const override 
  {
    string result;
    for (const Component *c : children_var) 
    {
      if (c == children_var.back()) 
      {
        result += c->Operation();
      } else 
      {
        result += c->Operation() + "+";
      }
    }
    return "Ramura(" + result + ")";
  }
};

void ClientCode(Component *component) 
{
  
  cout << "Rezultat: " << component->Operation();
  
}

void ClientCode2(Component *component1, Component *component2) 
{
  if (component1->IsComposite()) {
    component1->Add(component2);
  }
  cout << "Rezultat: " << component1->Operation();
}

int main() 
{
  Component *simple = new Leaf;
  cout << "\nComponenta simpla:\n";
  ClientCode(simple);
  cout << "\n\n";
  

  Component *tree = new Composite;
  Component *branch1 = new Composite;
  Component *branch2 = new Composite;
  Component *leaf_1 = new Leaf;
  Component *leaf_2 = new Leaf;
  Component *leaf_3 = new Leaf;


  branch1->Add(leaf_1);
  branch1->Add(leaf_2);
  branch2->Add(leaf_3);
  tree->Add(branch1);
  tree->Add(branch2);


  cout << "Pom 1:\n";
  ClientCode(tree);
  cout << "\n\n";

  cout << "Pom 2:\n";
  ClientCode2(tree, simple);
  cout << "\n";

  delete simple;
  delete tree;
  delete branch1;
  delete branch2;
  delete leaf_1;
  delete leaf_2;
  delete leaf_3;

  return 0;
}