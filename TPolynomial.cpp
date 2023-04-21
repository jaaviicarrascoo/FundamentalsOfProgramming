

#include <iostream>
#include <array>
using namespace std;

const int MAXDEGREE = 4;
typedef array<float, MAXDEGREE + 1> TPoly;
struct TMono
{
    float coef;
    int deg;
};
typedef array<TMono, MAXDEGREE + 1> TPoly2;
void PrintTPoly(TPoly p);
void PrintTPoly2(TPoly2 p);
void addMono(TPoly &p, TMono m);
void addMono2(TPoly2 &p, TMono m);
void adjustTPoly2(TPoly2 &p);
void addPoly(TPoly &p, TPoly q);
void addPoly2(TPoly2 &p, TPoly2 q);

int main()
{
    TPoly p = {{0, 1, -2, 0, 1}};
    TPoly a = {{2, 0, 4, 2, 0}};
    TPoly2 q = {{{1, 4}, {-2, 2}, {1, 1}}};
    TPoly2 b = {{{3, 4}, {2, 3}, {2, 0}}};

    cout << "PrintTPoly(p): " << endl;
    PrintTPoly(p);
    cout << endl;

    cout << "PrintTPoly2(q): " << endl;
    PrintTPoly2(q);
    cout << endl;

    cout << "addMono(p, {3, 0}): " << endl;
    addMono(p, {3, 0});
    cout << "After addition, PrintTPoly(p): " << endl;
    PrintTPoly(p);
    cout << endl;

    cout << "addMono2(q, {3, 0}) : " << endl;
    addMono2(q, {3, 0});
    cout << "After addition, PrintTPoly2(q) : " << endl;
    PrintTPoly2(q);
    cout << endl;

    cout << "addPoly(p, a), PrintTPoly(p) : " << endl;
    addPoly(p, a);
    PrintTPoly(p);
    cout << endl;

    cout << "addPoly2(q, b), Adjust and PrintTPoly2(q) : " << endl;
    addPoly2(q, b);
    adjustTPoly2(q);
    PrintTPoly2(q);
    cout << endl;

    return 0;
}

void PrintTPoly(TPoly p)
{
    bool first = true;
    for (int i = MAXDEGREE; i > 0; --i)
    {
        if (p[i] != 1 and p[i] != 0 and p[i] != -1 and p[i] > 0 and first == false)
        {
            cout << "+ " << p[i] << "x";
            first = false;
        }
        else if (p[i] != 1 and p[i] != 0 and p[i] != -1 and p[i] < 0)
        {
            cout << "- " << -1 * p[i] << "x";
            first = false;
        }
        else if (p[i] == 1 and first == false)
        {
            cout << "+ x";
            first = false;
        }
        else if (p[i] == -1)
        {
            cout << "- x";
            first = false;
        }
        else if (p[i] != 1 and p[i] != 0 and p[i] != -1 and p[i] > 0 and first == true)
        {
            cout << p[i] << "x";
            first = false;
        }
        else if (p[i] == 1 and first == true)
        {
            cout << "x";
            first = false;
        }
        if (p[i] != 0 and i > 1)
        {
            cout << "^" << i << "  ";
        }
    }
    if (p[0] > 0 and p[0] != 1)
    {
        cout << " + " << p[0];
    }
    else if (p[0] == 1)
    {
        cout << " + " << p[0];
    }
    else if (p[0] < 0 and p[0] != -1)
    {
        cout << " - " << -1 * p[0];
    }
    else if (p[0] == -1)
    {
        cout << " - " << p[0];
    }
    cout << endl;
}

void PrintTPoly2(TPoly2 p)
{
    bool first = true;
    for (int i = 0; i < MAXDEGREE + 1; ++i)
    {
        if (p[i].coef != 1 and p[i].coef > 0 and first == true and p[i].deg > 0)
        {
            cout << p[i].coef << "x";
            first = false;
        }
        else if (p[i].coef != 1 and p[i].coef > 0 and first == false and p[i].deg > 0)
        {
            cout << " + " << p[i].coef << "x";
        }
        else if (p[i].coef == 1 and first == false and p[i].deg > 0)
        {
            cout << "+ x";
            first = false;
        }
        else if (p[i].coef == 1 and first == true and p[i].deg > 0)
        {
            cout << "x";
            first = false;
        }
        else if (p[i].coef != -1 and p[i].coef < 0 and p[i].deg > 0)
        {
            cout << "- " << -1 * p[i].coef << "x";
            first = false;
        }
        else if (p[i].coef == -1 and p[i].deg > 0)
        {
            cout << "- x";
        }

        if (p[i].deg > 1)
        {
            cout << "^" << p[i].deg << " ";
        }

        if (p[i].deg == 0 and p[i].coef > 0)
        {
            cout << " + " << p[i].coef;
        }
        else if (p[i].deg == 0 and p[i].coef < 0)
        {
            cout << " - " << -1 * p[i].coef;
        }
    }
    cout << endl;
}

void addMono(TPoly &p, TMono m)
{
    for (int i = 0; i < MAXDEGREE; ++i)
    {
        if (m.deg == i)
        {
            p[i] += m.coef;
        }
    }
}

void addMono2(TPoly2 &p, TMono m)
{
    bool notadded = true;
    bool done = false;
    for (int i = 0; i <= MAXDEGREE; ++i)
    {
        if (p[i].deg == m.deg)
        {
            p[i].coef += m.coef;
            notadded = false;
        }
    }
    if (notadded == true)
    {
        for (int i = 0; i < MAXDEGREE; ++i)
        {
            if (p[i].deg == 0 and p[i].deg == 0 and done == false)
            {
                p[i].deg = m.deg;
                p[i].coef = m.coef;
                notadded = true;
                done = true;
            }
        }
    }
}

void adjustTPoly2(TPoly2 &p)
{
    TMono m;
    for (int j = 0; j < MAXDEGREE; ++j)
    {
        for (int i = 0; i < MAXDEGREE; ++i)
        {
            while (p[i].deg < p[i + 1].deg)
            {
                m.coef = p[i].coef;
                m.deg = p[i].deg;
                p[i].coef = p[i + 1].coef;
                p[i].deg = p[i + 1].deg;
                p[i + 1].coef = m.coef;
                p[i + 1].deg = m.deg;
            }
        }
    }
}

void addPoly(TPoly &p, TPoly q)
{
    for (int i = 0; i < MAXDEGREE; ++i)
    {
        p[i] += q[i];
    }
}

void addPoly2(TPoly2 &p, TPoly2 q)
{
    for (int i = 0; i < MAXDEGREE; ++i)
    {
        addMono2(p, q[i]);
    }
}
