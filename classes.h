#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

class Punct
{
    float x, y;
public:
    Punct()
    {
        x=0;
        y=0;
    }
    Punct(const float &val)
    {
        x=val;
        y=val;
    }
    Punct(float x, float y):x(x), y(y) {}
    Punct(Punct &p)
    {
        x=p.x;
        y=p.y;
    }
    ~Punct()
    {}
    void setX(float val)
    {
        x=val;
    }
    void setY(float val)
    {
        y=val;
    }
    float getX()
    {
        return x;
    }
    float getY()
    {
        return y;
    }
    Punct &operator=(Punct &p);
    friend std::istream &operator>>(std::istream &in, Punct &p);
    friend std::ostream &operator<<(std::ostream &out, Punct &p);
    friend class Patrat;

};

class Patrat
{
    Punct stanga_jos;
    float latura;
public:
    Patrat(): latura(0), stanga_jos(0,0) {}
    Patrat(Punct &p, float l)
    {
        stanga_jos.x=p.x;
        stanga_jos.y=p.y;
        latura=l;
    }
    Patrat(Patrat &pa)
    {
        stanga_jos.setX(pa.stanga_jos.getX());
        stanga_jos.setY(pa.stanga_jos.getY());
        latura=pa.latura;
    }
    Punct* getStanga_jos()
    {
        Punct *aux=&stanga_jos;
        return aux;
    }
    float getLatura()
    {
        return latura;
    }
    void setLatura(float val)
    {
        latura=val;
    }
    ~Patrat() {}
    Patrat &operator=(Patrat &p);
    friend std::istream &operator>>(std::istream &in, Patrat &p);
    friend std::ostream &operator<<(std::ostream &out, Patrat &p);
    virtual float computeArea()
    {
        return latura*latura;
    }
};

class Dreptunghi: public virtual Patrat
{
    float latura2;
public:
    Dreptunghi(): Patrat(), latura2(0) {}
    Dreptunghi(Punct &p, float latura_1, float latura_2): Patrat(p,latura_1), latura2(latura_2) {}
    Dreptunghi(Dreptunghi &d)
    {
        this->getStanga_jos()->setX(d.getStanga_jos()->getX());
        this->getStanga_jos()->setY(d.getStanga_jos()->getY());
        this->latura2=d.latura2;
    }
    ~Dreptunghi() {}
    void setLatura2(float val)
    {
        latura2=val;
    }
    float getLatura2()
    {
        return latura2;
    }
    Dreptunghi &operator=(Dreptunghi &d);
    friend std::istream &operator>>(std::istream &in, Dreptunghi &d);
    friend std::ostream &operator<<(std::ostream &out, Dreptunghi &d);
    virtual float computeArea()
    {
        return this->getLatura()*latura2;
    }
};

class Romb: public virtual Patrat
{
    Punct colt_opus;
public:
    Romb(): Patrat(), colt_opus(0,0) {}
    Romb(Punct& StJ, Punct &DrS, float latura): Patrat(StJ, latura), colt_opus(DrS)
    {

    }
    Romb(Punct& StJ, float latura, Punct &DrS): Patrat(StJ, latura), colt_opus(DrS) {}
    Romb(Romb &r)
    {
        colt_opus=r.colt_opus;
        this->getStanga_jos()->setX(r.getStanga_jos()->getX());
        this->getStanga_jos()->setY(r.getStanga_jos()->getY());
        this->setLatura(r.getLatura());
    }
    Punct *getColt_opus()
    {
        Punct *aux=&colt_opus;
        return aux;
    }
    ~Romb() {}
    Romb &operator=(Romb &r);
    friend std::istream &operator>>(std::istream &in, Romb &r);
    friend std::ostream &operator<<(std::ostream &out, Romb &r);
    virtual float computeArea()
    {
        float Ysus=this->getColt_opus()->getY();
        float Yjos=this->getStanga_jos()->getY();
        std::cout<<Ysus-Yjos;
        float rezultat=(Ysus-Yjos)*(this->getLatura());
        return rezultat;
    }
};

class Paralelogram:  public Dreptunghi,  public Romb
{
    ///Punct stanga_jos, colt_opus
    ///float latura, latura2
public:
    Paralelogram(): Patrat(), Dreptunghi(), Romb() {}
    Paralelogram(Punct &SJ, Punct &CO, float L1, float L2):
        Patrat(SJ,L1),
        Romb(SJ,CO,L1),
        Dreptunghi(SJ,L1,L2) {}
    Paralelogram(Paralelogram &para)
    {
        *this=para;
    }
    ~Paralelogram() {}
    Paralelogram &operator=(Paralelogram &r);
    friend std::istream &operator>>(std::istream &in, Paralelogram &r);
    friend std::ostream &operator<<(std::ostream &out, Paralelogram &r);
    virtual float computeArea()
    {
        return Romb::computeArea();
    }
};

class Trapez: public Paralelogram
{
    float baza2;
public:
    Trapez(): Paralelogram(), baza2(0) {}
    Trapez(Punct &SJ, Punct &CO, float L1, float L2, float baza2_val):
        Patrat(SJ,L1),
        Paralelogram(SJ,CO,L1,L2),
        baza2(baza2_val) {}
    Trapez(Trapez &t){
    *this=t;
    }
    ~Trapez() {}
    float getBaza2()
    {
        return baza2;
    }
    void setBaza2(float baza2)
    {
        this->baza2=baza2;
    }
    Trapez &operator=(Trapez &r);
    friend std::istream &operator>>(std::istream &in, Trapez &r);
    friend std::ostream &operator<<(std::ostream &out, Trapez &r);
    float computeArea()
    {
        float Ysus=this->getColt_opus()->getY();
        float Yjos=this->getStanga_jos()->getY();
        return (this->getLatura()+baza2)/2*(Ysus-Yjos);
    }
};


#endif // CLASSES_H_INCLUDED
