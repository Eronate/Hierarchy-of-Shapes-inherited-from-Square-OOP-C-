#include <iostream>
#include "classes.h"
using namespace std;

Punct& Punct::operator=(Punct &p)
{
    this->x=p.x;
    this->y=p.y;
    return *this;
}

std::istream &operator>>(istream &in, Punct &p)
{
    int x,y;
    in>>x>>y;
    p.setX(x);
    p.setY(y);
    return in;
}

std::ostream &operator<<(ostream &out, Punct &p)
{
    out<<p.x<<" "<<p.y<<endl;
    return out;
}

Patrat& Patrat::operator=(Patrat &p)
{
    stanga_jos.x=p.stanga_jos.x;
    stanga_jos.y=p.stanga_jos.y;
    latura=p.latura;
    return *this;
}

std::istream &operator>>(istream &in, Patrat &p)
{
    Punct pct;
    in>>pct;
    p.stanga_jos=pct;
    float lat;
    in>>lat;
    p.latura=lat;
    return in;
}

std::ostream &operator<<(ostream &out, Patrat &p)
{
    out<<"Coord. punctului de stanga jos: "<<p.stanga_jos.getX()<<" "<<p.stanga_jos.getY()<<", Latura: "<<p.getLatura()<<endl;
    return out;
}

std::istream &operator>>(istream &in, Dreptunghi &d)
{
    ///citesc punctul si dupa laturile
    Punct p;
    float latura_1,latura_2;
    in>>p;
    in>>latura_1>>latura_2;
    d.getStanga_jos()->setX(p.getX());
    d.getStanga_jos()->setY(p.getY());
    d.setLatura(latura_1);
    d.setLatura2(latura_2);
    return in;
}

Dreptunghi& Dreptunghi::operator=(Dreptunghi &d)
{
    this->setLatura(d.getLatura());
    this->setLatura2(d.getLatura2());
    this->getStanga_jos()->setX(d.getStanga_jos()->getX());
    this->getStanga_jos()->setY(d.getStanga_jos()->getY());
    return *this;
}

std::ostream &operator<<(ostream &out, Dreptunghi &d)
{
    out<<"Coord. punctului de stanga jos: "<<d.getStanga_jos()->getX()<<" "<<d.getStanga_jos()->getY()<<", Latura 1: "<<d.getLatura()<<", Latura 2: "<<d.getLatura2()<<endl;
    return out;
}

std::istream &operator>>(istream &in, Romb &r)
{
    ///citesc 2 puncte si dupa latura
    Punct p,q;
    in>>p;
    in>>q;
    float latura;
    in>>latura;
    r.getStanga_jos()->setX(p.getX());
    r.getStanga_jos()->setY(p.getY());
    r.getColt_opus()->setX(q.getX());
    r.getColt_opus()->setY(q.getY());
    r.setLatura(latura);

    return in;
}

std::ostream &operator<<(ostream &out, Romb &r)
{
    ///afisez coordonatele celor doua puncte si latura
    out<<"Coord. punctului de stanga jos: "<<r.getStanga_jos()->getX()<<" "<<
    r.getStanga_jos()->getY()<<", Coord. coltului opus: "<<
    r.getColt_opus()->getX()<<" "<<
    r.getColt_opus()->getY()<<", Latura: "<<
    r.getLatura()<<endl;
    return out;
}

Romb& Romb::operator=(Romb &r)
{
    this->setLatura(r.getLatura());
    this->getStanga_jos()->setX(r.getStanga_jos()->getX());
    this->getStanga_jos()->setY(r.getStanga_jos()->getY());
    this->getColt_opus()->setX(r.getColt_opus()->getX());
    this->getColt_opus()->setY(r.getColt_opus()->getY());
    return *this;
}

std::istream &operator>>(istream &in, Paralelogram &pa)
{
    ///am 2 puncte stanga jos si colt opus, si 2 laturi
    Punct p,q;
    float latura1,latura2;
    in>>p;
    in>>q;
    in>>latura1>>latura2;
    pa.getStanga_jos()->setX(p.getX());
    pa.getStanga_jos()->setY(p.getY());
    pa.getColt_opus()->setX(q.getX());
    pa.getColt_opus()->setY(q.getY());
    pa.setLatura(latura1);
    pa.setLatura2(latura2);
    return in;
}

std::ostream &operator<<(ostream &out, Paralelogram &pa)
{
    out<<"Coord. punctului de stanga jos: "<<pa.getStanga_jos()->getX()<<" "<<
    pa.getStanga_jos()->getY()<<", Coord. punctului de dreapta sus: "<<
    pa.getColt_opus()->getX()<<" "<<
    pa.getColt_opus()->getY()<<", Latura 1: "<<
    pa.getLatura()<<", Latura 2: "<<pa.getLatura2()<<endl;
    return out;
}

Paralelogram& Paralelogram::operator=(Paralelogram &pa)
{
    this->setLatura(pa.getLatura());
    this->setLatura2(pa.getLatura2());
    this->getStanga_jos()->setX(pa.getStanga_jos()->getX());
    this->getStanga_jos()->setY(pa.getStanga_jos()->getY());
    this->getColt_opus()->setX(pa.getColt_opus()->getX());
    this->getColt_opus()->setY(pa.getColt_opus()->getY());
    return *this;
}

std::istream &operator>>(istream &in, Trapez &t)
{
    ///punct stanga jos, punct colt opus, latura 1, latura 2, baza2
    Punct p,q;
    float latura1,latura2,baza2;
    in>>p;
    in>>q;
    in>>latura1>>latura2;
    in>>baza2;
    t.getStanga_jos()->setX(p.getX());
    t.getStanga_jos()->setY(p.getY());
    t.getColt_opus()->setX(q.getX());
    t.getColt_opus()->setY(q.getY());
    t.setLatura(latura1);
    t.setLatura2(latura2);
    t.setBaza2(baza2);
    return in;
}

std::ostream &operator<<(ostream &out, Trapez &t)
{
    out<<"Coord. punctului de stanga jos: "<<t.getStanga_jos()->getX()<<" "<<
    t.getStanga_jos()->getY()<<", Coord. punctului de dreapta sus: "<<
    t.getColt_opus()->getX()<<" "<<
    t.getColt_opus()->getY()<<", Latura1: "<<
    t.getLatura()<<", Latura2: "<<t.getLatura2()<<", Baza2: "<<t.getBaza2()<<endl;
    return out;
}

Trapez& Trapez::operator=(Trapez &t)
{
    this->setLatura(t.getLatura());
    this->setLatura2(t.getLatura2());
    this->setBaza2(t.getBaza2());
    this->getStanga_jos()->setX(t.getStanga_jos()->getX());
    this->getStanga_jos()->setY(t.getStanga_jos()->getY());
    this->getColt_opus()->setX(t.getColt_opus()->getX());
    this->getColt_opus()->setY(t.getColt_opus()->getY());
    return *this;
}
