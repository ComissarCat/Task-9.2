#include <iostream>
#include <vector>

using namespace std;

class Employer
{
public:
    virtual void print() {};
    virtual ~Employer() {};
};

class President : public Employer
{
public:
    void print() override { cout << "Я президент"; }
};

class Manager : public Employer
{
public:
    void print() override { cout << "Я манагер"; }
};

class Worker : public Employer
{
public:
    void print() override { cout << "Я работяга"; }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    vector<Employer*> employers;
    employers.push_back(new President);
    employers.push_back(new Manager);
    employers.push_back(new Worker);

    for (int i = 0; i < employers.size(); i++)
    {
        employers[i]->print();
        cout << endl;
    }

    for (int i = 0; i < employers.size(); i++)
    {
        delete employers[i];
    }

    return 0;
}