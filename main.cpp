#include <iostream>
#include "classes.h"
#include <vector>

using namespace std;

int main()
{
    cout<<"Alegeti optiunea dvs:\n";
    cout<<"1. Adaugati un patrat.\n";
    cout<<"2. Adaugati un dreptunghi.\n";
    cout<<"3. Adaugati un romb.\n";
    cout<<"4. Adaugati un paralelogram. \n";
    cout<<"5. Adaugati un trapez. \n";
    cout<<"6. Afisati vectorul de forme.\n";
    cout<<"7. Afisati aria formei cu indexul (...). \n";
    cout << "8. Exit\n";
    vector < Patrat* > Geometric_Figures;
    while(true)
    {
        int choice;
        cout<<"Alegerea ta: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            Patrat p;
            cout<<"Introduceti, in aceasta ordine, coordonatele unui punct si latura patratului:\n";
            cin>>p;
            Patrat* newSquare = new Patrat(p);
            Geometric_Figures.push_back(newSquare);
            cout<<"Patratul a fost adaugat. \n";
            break;
        }

        case 2:
        {
            cout<<"Introduceti, in aceasta ordine, coordonatele unui punct si valorile a cele 2 laturi ale dreptunghiului:\n";
            Dreptunghi d;
            cin>>d;
            Dreptunghi* newRectangle = new Dreptunghi(d);
            Geometric_Figures.push_back(newRectangle);
            cout<<"Dreptunghiul a fost adaugat. \n";
            break;
        }

        case 3:
        {
            cout<<"Introduceti, in aceasta ordine, coordonatele coltului de stanga jos, dupa coltul dreapta sus, dupa latura rombului: \n";
            Romb r;
            cin>>r;
            Romb *newRhombus= new Romb(r);
            Geometric_Figures.push_back(newRhombus);
            cout<<"Rombul a fost adaugat. \n";
            break;
        }
        case 4:
        {
            cout<<"Introduceti, in aceasta ordine, coordonatele coltului de stanga jos, dupa coltul dreapta sus, dupa cele 2 laturi ale paralelogramului: \n";
            Paralelogram para;
            cin>>para;
            Paralelogram *newParalellogram= new Paralelogram(para);
            Geometric_Figures.push_back(newParalellogram);
            cout<<"Paralelogramul a fost adaugat. \n";
            break;
        }
        case 5:
        {
            cout<<"Introduceti, in aceasta ordine, coordonatele coltului de stanga jos, dupa coltul dreapta sus, dupa cele 2 laturi ale trapezului si in final a doua baza: \n";
            Trapez tr;
            cin>>tr;
            Trapez *newTrapezoid=new Trapez(tr);
            Geometric_Figures.push_back(newTrapezoid);
            cout<<"Trapezul a fost adaugat. \n";
            break;
        }
        case 6:
        {
            for(Patrat* it: Geometric_Figures)
            {
                if(Trapez *Trapezoid = dynamic_cast <Trapez*> (it))
                    cout<< *Trapezoid;
                else if(Paralelogram *Paralellogram = dynamic_cast <Paralelogram*> (it))
                    cout<< *Paralellogram;
                else if(Romb *Rhombus = dynamic_cast <Romb*> (it))
                    cout<< *Rhombus;
                else if(Dreptunghi *Rectangle = dynamic_cast < Dreptunghi* > (it))
                    cout << *Rectangle;
                else if(Patrat *Square = dynamic_cast < Patrat* > (it))
                    cout << *Square;
                else
                    cout<<"Eroare. \n";
            }
            break;
        }

        case 7:
        {
            cout<<"Indexul ales: ";
            int index;
            cin>>index;
            if(index<Geometric_Figures.size())
            {
                if(Trapez *Trapezoid = dynamic_cast <Trapez*> (Geometric_Figures[index]))
                    cout<< Trapezoid->computeArea();
                else if(Paralelogram *Paralellogram = dynamic_cast <Paralelogram*> (Geometric_Figures[index]))
                    cout<< Paralellogram->computeArea();
                else if(Romb *Rhombus = dynamic_cast <Romb*> (Geometric_Figures[index]))
                    cout<< Rhombus->computeArea();
                else if(Dreptunghi *Rectangle = dynamic_cast < Dreptunghi* > (Geometric_Figures[index]))
                    cout << Rectangle->computeArea();
                else if(Patrat *Square = dynamic_cast < Patrat* > (Geometric_Figures[index]))
                    cout << Square->computeArea();
                else
                    cout<<"Eroare.";
                cout<<"cm^2";
                cout<<'\n';
            }
            else
                cout<<"Index out of range. \n";
            break;

        }
        case 8:
            return 0;
        }

    }
}
