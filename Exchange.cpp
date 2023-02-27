#include <iostream>
#include <cstring>
using namespace std;

class Bancnota{
private:
    string nume;
    string simbol, tara;
    float valoare;
public:
    void setNume(string nume)
    {
        this->nume=nume;

    }
    void setSimbol(string simbol)
    {
        this->simbol=simbol;


    }
    void setTara(string tara)
    {
        this->tara=tara;

    }
    void setValoare(float valoare) {
        this->valoare = valoare;
    }

    string getNume(){
        return this->nume;
    }
    string getSimbol(){
        return this->simbol;
    }
    string getTara(){
        return this->tara;
    }
    float getValoare(){
        return this->valoare;
    }

    Bancnota & operator=(const Bancnota & b) {
        if(this!=&b) {
            this->nume = b.nume;
            this->simbol = b.simbol;
            this->tara = b.tara;
            this->valoare = b.valoare;
        }
        return *this;
    }
    bool operator==(  const Bancnota& b) {

        if (this->nume == b.nume && this->simbol == b.simbol && this->tara == b.tara && this->valoare == b.valoare)
            return true;
        return false;

    }
    bool operator<(const Bancnota& b) {

        if (this->valoare < b.valoare)
            return true;
        return false;

    }
    bool operator>=(const Bancnota& b) {

        if (this->valoare >= b.valoare)
            return true;
        return false;

    }
    float operator / (const Bancnota& b1){
        return (this->valoare/b1.valoare);
    }
    Bancnota operator ++ ();
    Bancnota operator ++(int);
    Bancnota operator +=(float z);



    Bancnota()
    {
        this->nume = "Anonim";
        this->simbol = "Anonim";
        this->tara = "Anonim" ;
        this->valoare=0;

    }

    Bancnota(string nume, string simbol, string tara, int valoare)
    {
        this->nume = nume;
        this->simbol = simbol;
        this->tara = tara;
        this->valoare = valoare;
    }

    //Bancnota(const Bancnota& b);
    //cosntructor de copiere
    Bancnota(const Bancnota & b) {
        this->nume = b.nume;
        this->simbol = b.simbol;
        this->simbol = b.simbol;
        this->valoare = b.valoare;
    }
    //pentru atribuirea unui obiect cu alt obiect

    friend istream& operator>>(istream& in, Bancnota& b);
    friend ostream& operator<<(ostream& out, const Bancnota& b);
    ~Bancnota() {}


};
Bancnota Bancnota::operator ++()
{
    this->valoare++;
    return *this;
}

Bancnota Bancnota::operator ++(int)
{
    Bancnota h=*this;
    this->valoare++;
    return h;
}

Bancnota Bancnota ::operator +=(float z){
    this->valoare +=z;
    return *this;

}
istream& operator>>(istream& in, Bancnota& b)
{

    cout << "\nNume Bancnota: ";
    in >> b.nume;
    cout << "\nNume Simbol: ";
    in >> b.simbol;
    cout << "\nNume Tara: ";
    in >> b.tara;
    cout << "\nValoare Bancnota in LEI: ";
    in >> b.valoare;

    return in;
}
ostream& operator<<(ostream& out, const Bancnota& b)
{
    out << "\nNume Bancnota: " << b.nume;
    cout << "\nNume Simbol: " <<b.simbol;
    cout << "\nNume Tara: "<<b.tara;
    out << "\nValoare Bancnota: " << b.valoare;

    return out;
}

class CursValutar {
private:
    Bancnota* listaBancnote;
    int lungimeLista;
    float*valoriInUltimileZile;
    int numarZile;
    float*pretCumparareInUltimeleZile;
    float*pretVanzareInUltimeleZile;


public:
    CursValutar();
    CursValutar(float* valoriInUltimileZile, float* pretCumparareInUltimeleZile,float *pretVanzareInUltimeleZile,  int numarZile, Bancnota* listaBancnote, int lungimeLista);
    CursValutar(const CursValutar& curs);
    CursValutar& operator= (const CursValutar& curs);

    void setValori(float* valoriInUltimileZile, int numarZile);
    void setCumparare(float* pretCumparareInUltimeleZile , int numarZile);
    void setVanzare(float* pretVanzareInUltimeleZile , int numarZile);
    const float* getvaloriInUltimileZile()const;
    const float* getpretCumparareInUltimeleZile()const;
    const float* getpretVanzareInUltimeleZile()const;

    int getnumarZile();

    friend ostream& operator<<(ostream& out, const CursValutar& curs);
    friend istream& operator>>(istream& in, CursValutar& curs);
//
//    const CursValutar& operator++();
//    const CursValutar operator++(int);

    friend CursValutar operator+(CursValutar curs, const Bancnota& b);
    friend CursValutar operator+(const Bancnota& b, CursValutar curs);

    Bancnota operator[](int index);
    void afisare();
    void stergereBancnota(const Bancnota&);
//    float transformare(int sumab1, const Bancnota b1, const Bancnota b2, float tva);
//    float cumparare(int sumab1, const Bancnota b1, const Bancnota b2, float tva);
//    float vanzare(int sumab1, const Bancnota b1, const Bancnota b2, float tva);
    ~CursValutar();



};


//
//float CursValutar::transformare(int sumab1, const Bancnota b1, const Bancnota b2, float tva)
//{
//    int indice,indice1;
//    float a,b,k;
//    for (int i=0;i<lungimeLista;i++) {
//        if (listaBancnote[i] == b1)
//            indice = i;
//        if (listaBancnote[i] == b2)
//            indice1 = i;
//    }
//    a=valoriInUltimileZile[indice];
//    b=valoriInUltimileZile[indice1];
//    k=sumab1*(a/b+tva);
//    return k;
//
//
//}
//
//float CursValutar::cumparare(int sumab1, const Bancnota b1, const Bancnota b2, float tva)
//{
//    int indice,indice1;
//    float a,b,k;
//    for (int i=0;i<lungimeLista;i++) {
//        if (listaBancnote[i] == b1)
//            indice = i;
//        if (listaBancnote[i] == b2)
//            indice1 = i;
//    }
//    a=pretCumparareInUltimeleZile[indice];
//    b=pretCumparareInUltimeleZile[indice1];
//    k=sumab1*(a/b+tva);
//    return k;
//
//}
//
//
//float CursValutar::vanzare(int sumab1, const Bancnota b1, const Bancnota b2, float tva)
//{
//    int indice,indice1;
//    float a,b,k;
//    for (int i=0;i<lungimeLista;i++) {
//        if (listaBancnote[i] == b1)
//            indice = i;
//        if (listaBancnote[i] == b2)
//            indice1 = i;
//    }
//    a=pretVanzareInUltimeleZile[indice];
//    b=pretVanzareInUltimeleZile[indice1];
//    k=sumab1*(a/b+tva);
//    return k;
//
//}



void CursValutar::stergereBancnota(const Bancnota& b)
{
    Bancnota* listaBancnoteAux;
    int c=0;
    listaBancnoteAux = new Bancnota[lungimeLista];
    for (int i = 0; i < lungimeLista; i++) {
        if (listaBancnote[i] == b)
            c++;
        listaBancnoteAux[i] = listaBancnote[i];

    }

    if (listaBancnote != NULL)
        delete[] listaBancnote;
    lungimeLista =lungimeLista-c;
    int j = 0;
    listaBancnote = new Bancnota[lungimeLista];
    for (int i = 0; i < lungimeLista +c; i++) {
        if (!(listaBancnoteAux[i] == b))
        {
            listaBancnote[j] = listaBancnoteAux[i];
            j++;
        }

    }
    if (listaBancnoteAux != NULL)
        delete[] listaBancnoteAux;
}




Bancnota CursValutar::operator[](int index) {

    if (0 <= index && index < this->lungimeLista)
        return this->listaBancnote[index];
    cout << "Indexul nu e corect";

}
CursValutar operator+(const Bancnota& b, CursValutar curs) {
    Bancnota* listaBancnoteAux;
    listaBancnoteAux = new Bancnota[curs.lungimeLista];
    for (int i = 0; i < curs.lungimeLista; i++) {
        listaBancnoteAux[i] = curs.listaBancnote[i];
    }
    if (curs.listaBancnote != NULL)
        delete[] curs.listaBancnote;

    curs.lungimeLista++;
    curs.listaBancnote = new Bancnota[curs.lungimeLista];
    for (int i=0;i <curs.lungimeLista-1; i++)
        curs.listaBancnote[i] = listaBancnoteAux[i];

    curs.listaBancnote[curs.lungimeLista-1] = b;

    if (listaBancnoteAux != NULL)
        delete[] listaBancnoteAux;
    return curs;
}
CursValutar operator+(CursValutar curs, const Bancnota& b) {

    Bancnota* listaBancnoteAux;
    listaBancnoteAux = new Bancnota[curs.lungimeLista];
    for (int i = 0; i < curs.lungimeLista; i++) {
        listaBancnoteAux[i] = curs.listaBancnote[i];
    }
    if (curs.listaBancnote != NULL)
        delete[] curs.listaBancnote;
    curs.lungimeLista++;
    curs.listaBancnote = new Bancnota[curs.lungimeLista];
    for (int i = 0; i < curs.lungimeLista - 1; i++)
        curs.listaBancnote[i] = listaBancnoteAux[i];

    curs.listaBancnote[curs.lungimeLista - 1] = b;

    if (listaBancnoteAux != NULL)
        delete[] listaBancnoteAux;
    return curs;
}
//const CursValutar& CursValutar::operator++() {
//    this->tva++;
//    return *this;
//}
//const CursValutar CursValutar::operator++(int) {
//    CursValutar aux(*this);
//    this->tva++;
//    return aux;
//}

istream& operator>>(istream& in, CursValutar& curs)
{
    int h=0;
    cout<<"\nCate Bancnote vreti sa vedeti: "<<endl;
    in>>curs.lungimeLista;
    cout<<"\nBancnotele dorite: "<<endl;
    if (curs.listaBancnote != NULL)
        delete[] curs.listaBancnote;
    curs.listaBancnote = new Bancnota[curs.lungimeLista];
    for (int i = 0; i < curs.lungimeLista; i++)
        cin >> curs.listaBancnote[i];
    cout<<"\nPe cate zile contorizam"<<endl;
    in>>curs.numarZile;
    cout<<"\nValoarea Oficiala pt fiecare bancnota "<<endl;
    if (curs.valoriInUltimileZile != NULL)
        delete[] curs.valoriInUltimileZile;
    curs.valoriInUltimileZile = new float[(curs.numarZile)*(curs.lungimeLista)];
    for (int i = 0; i < curs.numarZile; i++) {
        cout << "Ziua "<<i+1<<endl;
        for (int j = 0; j<curs.lungimeLista; j++) {
            cout<<"Pt bancnota"<<curs.listaBancnote[j].getNume()<<" dati valoarea: "<<endl;
            in>>curs.valoriInUltimileZile[h];
            h+=1;
        }
    }
    h=0;
    cout << "\nPretul de cumparare pt fiecare bancnota: "<<endl;
    if (curs.pretCumparareInUltimeleZile != NULL)
        delete[] curs.pretCumparareInUltimeleZile;
    curs.pretCumparareInUltimeleZile = new float[(curs.numarZile)*(curs.lungimeLista)];

    for (int i = 0;i < curs.numarZile; i++) {
        cout << "Ziua "<<i+1<<endl;
        for (int j=0;j<curs.lungimeLista; j++) {
            cout<<"Pt bancnota "<<curs.listaBancnote[j].getNume()<<" dati valoarea: "<<endl;
            in>>curs.pretCumparareInUltimeleZile[h];
            h += 1;
        }
    }
    h=0;
    cout << "\nPretul de vanzare pt fiecare bancnota: "<<endl;
    if (curs.pretVanzareInUltimeleZile != NULL)
        delete[] curs.pretVanzareInUltimeleZile;
    curs.pretVanzareInUltimeleZile = new float[(curs.numarZile)*(curs.lungimeLista)];
    for (int i=0;i<curs.numarZile;i++) {
        cout << "Ziua "<<i+1<<endl;
        for (int j = 0; j < curs.lungimeLista; j++) {
            cout<<"Pt bancnota "<<curs.listaBancnote[j].getNume()<<" dati valoarea: "<<endl;
            in >>curs.pretVanzareInUltimeleZile[h];
            h += 1;
        }
    }


    return in;


}

ostream& operator<<(ostream& out, const CursValutar& curs)
{
    int h=0;


    out << "\nBancnotele dorite sunt: "<<endl;
    for (int i = 0; i < curs.lungimeLista; i++)
        out<<curs.listaBancnote[i] << "\n";
    out <<"\nValoarea pt fiecare bancnota: "<<endl;
    for (int i=0;i<curs.numarZile; i++) {
        out << "Ziua " << i+1 << endl;
        for (int j = 0;j<curs.lungimeLista;j++) {
            out << "Pt bancnota" <<curs.listaBancnote[j].getNume() << " are valoarea: "<<curs.valoriInUltimileZile[h]<<endl;
            h+=1;
        }
    }

    out << "\nPret cumparare pt fiecare bancnota: "<<endl;
    for (int i = 0; i<curs.numarZile; i++) {
        out << "Ziua "<< i+1<<endl;
        for (int j = 0;j <curs.lungimeLista; j++) {
            out << "Pt bancnota" <<curs.listaBancnote[j].getNume() << " are valoarea: " <<curs.pretCumparareInUltimeleZile[h]<<endl;
            h += 1;
        }
    }

    out << "\nPret vanzare pt fiecare bancnota: "<<endl;

    for (int i = 0; i < curs.numarZile; i++) {
        out << "Ziua " << i+1 <<endl;
        for (int j = 0; j < curs.lungimeLista; j++) {
            out <<"Pt bancnota"<<curs.listaBancnote[j].getNume()<<" are valoarea: " << curs.pretVanzareInUltimeleZile[h]<<endl;
            h += 1;
        }
    }
    return out;

}

void CursValutar::setValori(float* valoriInUltimileZile, int numarZile) {
    int h=0;
    if (this->valoriInUltimileZile != NULL)
        delete[] this->valoriInUltimileZile;
    this->numarZile = numarZile;
    this->valoriInUltimileZile = new float[(this->numarZile)*(this->lungimeLista)];
    for (int i = 0; i < this->numarZile; i++)
        for(int j=0;j <this->lungimeLista;j++)
        {this->valoriInUltimileZile[h] = valoriInUltimileZile[h];
            h++;}
}

void CursValutar::setCumparare(float* pretCumparareInUltimeleZile, int numarZile) {
    int h=0;
    if (this->pretCumparareInUltimeleZile != NULL)
        delete[] this->pretCumparareInUltimeleZile;
    this->numarZile = numarZile;
    this->pretCumparareInUltimeleZile = new float[(this->numarZile)*(this->lungimeLista)];
    for (int i = 0; i < this->numarZile; i++)
        for(int j=0;j <this->lungimeLista;j++)
        {this->pretCumparareInUltimeleZile[h] = pretCumparareInUltimeleZile[h];
            h+=1;}

}
void CursValutar::setVanzare(float *pretVanzareInUltimeleZile, int numarZile) {
    int h=0;
    if (this->pretVanzareInUltimeleZile != NULL)
        delete[] this->pretVanzareInUltimeleZile;
    this->numarZile = numarZile;
    this->pretVanzareInUltimeleZile = new float[(this->numarZile)*(this->lungimeLista)];
    for (int i = 0; i < this->numarZile; i++)
        for(int j=0;j <this->lungimeLista;j++)
        {this->pretVanzareInUltimeleZile[i] = pretVanzareInUltimeleZile[i];
            h+=1;}

}

const float* CursValutar::getvaloriInUltimileZile()const {
    return this->valoriInUltimileZile;
}
const float* CursValutar::getpretCumparareInUltimeleZile()const {
    return this->pretCumparareInUltimeleZile;
}
const float* CursValutar::getpretVanzareInUltimeleZile()const {
    return this->pretVanzareInUltimeleZile;
}

int  CursValutar::getnumarZile() {
    return this->numarZile;
}

CursValutar::CursValutar() {

    this->numarZile = 0;
    this->lungimeLista = 0;

    this->valoriInUltimileZile = NULL;
    this->pretCumparareInUltimeleZile = NULL;
    this->pretVanzareInUltimeleZile = NULL;
    this->listaBancnote = 0;

}

CursValutar::CursValutar(float* valoriInUltimileZile, float* pretCumparareInUltimeleZile,float *pretVanzareInUltimeleZile,  int numarZile, Bancnota* listaBancnote, int lungimeLista)
{
    int h=0;
    this->lungimeLista = lungimeLista;
    this->listaBancnote = new Bancnota[lungimeLista];
    for (int i = 0; i < lungimeLista; i++)
        this->listaBancnote[i] = listaBancnote[i];
    this->numarZile = numarZile;
    this->valoriInUltimileZile = new float[(this->numarZile)*(this->lungimeLista)];
    for (int i = 0; i < this->numarZile; i++)
        for(int j=0;j <this->lungimeLista;j++)
        {this->valoriInUltimileZile[h] = valoriInUltimileZile[h];
            h+=1;}
    h=0;
    this->pretCumparareInUltimeleZile = new float[(this->numarZile)*(this->lungimeLista)];
    for (int i = 0; i < this->numarZile; i++)
        for(int j=0;j <this->lungimeLista;j++)
        {this->pretCumparareInUltimeleZile[h] = pretCumparareInUltimeleZile[h];
            h+=1;}

    h=0;
    this->pretVanzareInUltimeleZile = new float[(this->numarZile)*(this->lungimeLista)];
    for (int i = 0; i < this->numarZile; i++)
        for(int j=0;j <this->lungimeLista;j++)
        {this->pretVanzareInUltimeleZile[h] = pretVanzareInUltimeleZile[h];
            h+=1;}

}

CursValutar::CursValutar(const CursValutar& curs) {

    int h=0;
    this->lungimeLista=curs.lungimeLista;
    this->listaBancnote=new Bancnota[curs.lungimeLista];
    for (int i=0;i<curs.lungimeLista; i++)
        this->listaBancnote[i]=curs.listaBancnote[i];
    this->numarZile=curs.numarZile;

    this->valoriInUltimileZile = new float[(this->numarZile)*(this->lungimeLista)];
    for (int i = 0; i < this->numarZile; i++)
        for(int j=0;j <this->lungimeLista;j++)
        {this->valoriInUltimileZile[h]=curs.valoriInUltimileZile[h];
            h+=1;}
    h=0;
    this->pretCumparareInUltimeleZile = new float[(this->numarZile)*(this->lungimeLista)];
    for (int i = 0; i < this->numarZile; i++)
        for(int j=0;j <this->lungimeLista;j++)
        {this->pretCumparareInUltimeleZile[h]=curs.pretCumparareInUltimeleZile[h];
            h+=1;}
    h=0;
    this->pretVanzareInUltimeleZile = new float[(this->numarZile)*(this->lungimeLista)];
    for (int i = 0; i < this->numarZile; i++)
        for(int j=0;j <this->lungimeLista;j++)
        {this->pretVanzareInUltimeleZile[h] = curs.pretVanzareInUltimeleZile[h];
            h+=1;}

}

CursValutar& CursValutar::operator= (const CursValutar& curs) {

    if (this != &curs) {
        if (this->listaBancnote != NULL)
            delete[] this->listaBancnote;
        if (this->valoriInUltimileZile != NULL)
            delete[] this->valoriInUltimileZile;
        if (this->pretCumparareInUltimeleZile != NULL)
            delete[] this->pretCumparareInUltimeleZile;
        if (this->pretVanzareInUltimeleZile != NULL)
            delete[] this->pretCumparareInUltimeleZile;

        this->lungimeLista=curs.lungimeLista;
        this->listaBancnote=new Bancnota[curs.lungimeLista];
        for (int i=0;i<curs.lungimeLista; i++)
            this->listaBancnote[i]=curs.listaBancnote[i];
        this->numarZile=curs.numarZile;
        int h=0;
        this->valoriInUltimileZile = new float[this->numarZile];
        for (int i = 0; i < this->numarZile; i++)
            for(int j=0;j <this->lungimeLista;j++)
            {this->valoriInUltimileZile[h]=curs.valoriInUltimileZile[h];
                h+=1;}
        h=0;
        this->pretCumparareInUltimeleZile = new float[(this->numarZile)*(this->lungimeLista)];
        for (int i = 0; i < this->numarZile; i++)
            for(int j=0;j <this->lungimeLista;j++)
            {this->pretCumparareInUltimeleZile[h]=curs.pretCumparareInUltimeleZile[h];
                h+=1;}
        h=0;
        this->pretVanzareInUltimeleZile = new float[(this->numarZile)*(this->lungimeLista)];
        for (int i=0; i<this->numarZile; i++)
            for(int j=0;j<this->lungimeLista;j++)
            {this->pretVanzareInUltimeleZile[h]=curs.pretVanzareInUltimeleZile[h];
                h+=1;}

    }

    return *this;

}

CursValutar::~CursValutar() {

    if (this->listaBancnote != NULL)
        delete[] this->listaBancnote;
    if (this->valoriInUltimileZile != NULL)
        delete[] this->valoriInUltimileZile;
    if (this->pretCumparareInUltimeleZile != NULL)
        delete[] this->pretCumparareInUltimeleZile;
    if (this->listaBancnote != NULL)
        delete[] this->listaBancnote;

}


void  CursValutar::afisare() {

    cout << "\nNumar de bacnote" << this->lungimeLista<<endl;
    if (this->lungimeLista) {

        for (int i = 0; i < this->lungimeLista; i++)
            cout << "Bancnota" << this->listaBancnote[i] << endl;
    }

    cout << "\nNumar de zile" << this->numarZile<<endl;

    if (this->numarZile != 0) {

        int h = 0;
        this->valoriInUltimileZile = new float[(this->numarZile) * (this->lungimeLista)];
        for (int i = 0; i < this->numarZile; i++) {
            cout << "In ziua " << i+1<<endl;
            for (int j = 0; j < this->lungimeLista; j++) {
                cout << " Valoarea bancnotei : " << listaBancnote[j] << "a fost" << this->valoriInUltimileZile[h]
                     << " lei" << endl;
                h += 1;
            }
            cout << endl;

        }


    }


    if (this->numarZile != 0) {

        int h = 0;
        this->pretCumparareInUltimeleZile = new float[(this->numarZile) * (this->lungimeLista)];
        for (int i = 0; i < this->numarZile; i++) {
            cout << "In ziua " << i+1<<endl;
            for (int j = 0; j < this->lungimeLista; j++) {
                cout << " Pretul de cumparare a  bancnotei : " << listaBancnote[j] << "a fost"
                     << this->pretCumparareInUltimeleZile[h] << " lei" << endl;
                h += 1;
            }
            cout << endl;
        }
    }
    if (this->numarZile != 0) {
        int h = 0;
        this->pretVanzareInUltimeleZile = new float[(this->numarZile) * (this->lungimeLista)];
        for (int i = 0; i < this->numarZile; i++) {
            cout << "In ziua " << i+1<<endl;
            for (int j = 0; j < this->lungimeLista; j++) {
                cout << " Pretul de vanzare a  bancnotei : " << listaBancnote[j] << "a fost"
                     << this->pretVanzareInUltimeleZile[h] << " lei" << endl;
                h += 1;
            }
            cout << endl;
        }

    }
}



class Card
{
private:
    Bancnota ban;
    int* numarCard;
    int lungimeNumarCard;
    string dataExp;
    string numeBanca;
    float total;
public:


    Card& operator=(const Card& card)
    {
        if (this != &card)
        {
            this->ban=card.ban;
            this->lungimeNumarCard=lungimeNumarCard;
            if (this->numarCard != NULL)
                delete[] this->numarCard;


            this->numarCard = new int[(this->lungimeNumarCard)];
            for(int i=0;i<this->lungimeNumarCard;i++)
                this->numarCard[i]=card.numarCard[i];
            this->dataExp=card.dataExp;
            this->numeBanca =card.numeBanca;
            this->total = card.total;
        }

        return *this;
    }
    Card(const Card& card)
    {
        this->ban=card.ban;
        if (this->numarCard != NULL)
            delete[] this->numarCard;

        this->lungimeNumarCard=card.lungimeNumarCard;
        this->numarCard = new int[(this->lungimeNumarCard)];
        for(int i=0;i<this->lungimeNumarCard;i++)
            this->numarCard[i]=card.numarCard[i];
        this->dataExp=card.dataExp;
        this->numeBanca = card.numeBanca;
        this->total = card.total;
    }


    bool operator==(const Card& card) {

        if (this->ban == card.ban && this->numeBanca == card.numeBanca && this->total ==card.total && this->numarCard ==card.numarCard && this->lungimeNumarCard==card.lungimeNumarCard && this->dataExp==card.dataExp)
            return true;
        else return false;

    }
    bool operator<(const Card& card) {

        if (this->total <card.total)
            return true;
        else return false;

    }
    bool operator>=(const Card& card) {

        if (this->total >=card.total)
            return true;
        else return false;

    }

    Card()
    {
        this->numarCard=NULL;
        this->lungimeNumarCard=0;
        this->dataExp="09/22";
        this->numeBanca="Anonim";
        this->total=0;

    }

    Card( Bancnota ban, int* numarCard, int lungimeNumarCard,  string dataExp, string numeBanca, float total)
    {
        this->ban=ban;
        if (this->numarCard != NULL)
            delete[] this->numarCard;
        this->lungimeNumarCard=lungimeNumarCard;
        this->numarCard = new int[(this->lungimeNumarCard)];
        for(int i=0;i<this->lungimeNumarCard;i++)
            this->numarCard[i]=numarCard[i];
        this->dataExp=dataExp;
        this->numeBanca =numeBanca;
        this->total =total;
    }

    Card(const Bancnota &ban);


    Card operator+=(int x) {

        this->total += x;
        return *this;
    }



    Card operator+(int x) {

        Card aux(*this);
        aux.total = aux.total + x;
        return aux;


    }
    Card operator+(Card card) {
        int *numarCardaux;
        card.numeBanca = this->numeBanca + card.numeBanca;
        numarCardaux = new int[(this->lungimeNumarCard)+(card.lungimeNumarCard)];
        for (int i = 0; i < this->lungimeNumarCard; i++) {

            numarCardaux[i] = this->numarCard[i];

        }
        if(this->numarCard!=NULL)
            delete [] this->numarCard;
        int h=this->lungimeNumarCard;
        for (int i = 0; i < card.lungimeNumarCard; i++) {

            numarCardaux[h] = card.numarCard[i];
            h++;

        }
        this->numarCard= new int[(this->lungimeNumarCard)+(card.lungimeNumarCard)];
        for (int i = 0; i < this->lungimeNumarCard+card.lungimeNumarCard; i++) {

            this->numarCard[i] = numarCardaux[i];

        }
        if(numarCardaux!=NULL)
            delete [] numarCardaux;

        card.lungimeNumarCard=this->lungimeNumarCard+card.lungimeNumarCard;
        card.dataExp=this->dataExp+card.dataExp;
        card.total = this->total +card.total;
        return card;

    }
    friend Card operator+(int x, Card card) {

        card.total = card.total + x;
        return card;
    }


    explicit operator int() {

        return (int)this->total;
    }

    friend istream& operator>>(istream& in, Card& card);
    friend ostream& operator<<(ostream& out, const Card& card);


    ~Card() {}


};


istream& operator>>(istream& in, Card& card)
{
    cout<<"Valuta card: "<<endl;
    in>>card.ban;
    cout<<"Lungimea numarului de card"<<endl;
    in>>card.lungimeNumarCard;

    if (card.numarCard != NULL)
        delete[] card.numarCard;
    card.numarCard = new int[card.lungimeNumarCard];
    cout<<"Dati numarul Cardului: "<<endl;
    for (int i = 0; i <card.lungimeNumarCard; i++)
    {
//        cout<<card.numarCard[i];
        in >>card.numarCard[i];

    }

    cout << "\nNume Banca: "<<endl;
    in >> card.numeBanca;
    cout<<"\nData Exp: "<<endl;
    in >> card.dataExp;
    cout << "\nTotalul Cardului: "<<endl;
    in >> card.total;

    return in;
}
ostream& operator<<(ostream& out, const Card& card)
{

    out<<"\nValuta card: "<<card.ban<<endl;
    out<<"\nLungimea numarului de card"<<card.lungimeNumarCard<<endl;

    out<<"\nNumarul Cardului este: "<<endl;
    for (int i = 0; i < card.lungimeNumarCard; i++)
    {
        out<<card.numarCard[i];

    }


    out << "\nNume Banca: "<< card.numeBanca<<endl;
    out<<"\nData Exp: "<<card.dataExp<<endl;
    out << "\nTotalul Cardului: "<<card.total;


    return out;
}



class Utilizator {
private:

    char* nume;
    string prenume;
    int varsta;
    bool persoana;
    char initialaTatat;

    Card *listaCarduri;
    int lungimeListaCarduri;
    const int idUtilizator;
    static int contorId;



public:
    Utilizator();
    Utilizator(char* nume, string prenume, int varsta, bool persoana, char initialaTatat, Card* listaCarduri, int lungimeListaCarduri);
    Utilizator(const Utilizator& cont);
    Utilizator& operator= (const Utilizator& cont);


    void setVarsta(int varsta);
    void setNume(char* nume);
    int getVarsta();
    const char* getNume();

    friend ostream& operator<<(ostream& out, const Utilizator& cont);
    friend istream& operator>>(istream& in, Utilizator& cont);

    const Utilizator& operator++();
    const Utilizator operator++(int);

    friend Utilizator operator+(Utilizator cont, const Card& card);
    friend Utilizator operator+(const Card& card, Utilizator cont);

    Card operator[](int index);

    void afisare2();
    void stergereCard(const Card&);

    ~Utilizator();



};

void Utilizator::stergereCard(const Card& card)
{
    Card* listaCarduriAux;
    int contor = 0;
    listaCarduriAux = new Card[lungimeListaCarduri];
    for (int i = 0; i < lungimeListaCarduri; i++) {
        if (listaCarduri[i] == card)
            contor++;
        listaCarduriAux[i] = listaCarduri[i];

    }
    cout << contor;
    if (listaCarduri != NULL)
        delete[] listaCarduri;
    lungimeListaCarduri =lungimeListaCarduri- contor;
    int j = 0;
    listaCarduri = new Card[lungimeListaCarduri];
    for (int i = 0; i < lungimeListaCarduri + contor; i++) {
        if (!(listaCarduriAux[i] == card))
        {
            listaCarduri[i] = listaCarduriAux[i];
            j++;
        }

    }
    if (listaCarduriAux != NULL)
        delete[] listaCarduriAux;
}



Card Utilizator::operator[](int index) {

    if (0 <= index && index < this->lungimeListaCarduri)
        return this->listaCarduri[index];
    cout << "Index gresit";

}
Utilizator operator+(const Card& card, Utilizator cont) {
    Card* listaCarduriAux;
    listaCarduriAux = new Card[cont.lungimeListaCarduri];
    for (int i = 0; i < cont.lungimeListaCarduri; i++) {
        listaCarduriAux[i] = cont.listaCarduri[i];
    }
    if (cont.listaCarduri != NULL)
        delete[] cont.listaCarduri;

    cont.lungimeListaCarduri++;

    cont.listaCarduri = new Card[cont.lungimeListaCarduri];
    for (int i = 0; i <cont.lungimeListaCarduri - 1; i++)
        cont.listaCarduri[i] = listaCarduriAux[i];

    cont.listaCarduri[cont.lungimeListaCarduri - 1] = card;

    if (listaCarduriAux != NULL)
        delete[] listaCarduriAux;
    return cont;
}
Utilizator operator+(Utilizator cont, const Card& card) {

    Card* listaCarduriAux;
    listaCarduriAux = new Card[cont.lungimeListaCarduri];
    for (int i = 0; i < cont.lungimeListaCarduri; i++) {
        listaCarduriAux[i] =cont.listaCarduri[i];
    }
    if (cont.listaCarduri != NULL)
        delete[] cont.listaCarduri;

    cont.lungimeListaCarduri++;

    cont.listaCarduri = new Card[cont.lungimeListaCarduri];
    for (int i = 0; i <cont.lungimeListaCarduri - 1; i++)
        cont.listaCarduri[i] = listaCarduriAux[i];

    cont.listaCarduri[cont.lungimeListaCarduri - 1] = card;

    if (listaCarduriAux != NULL)
        delete[] listaCarduriAux;
    return cont;
}
int Utilizator::contorId = 1000;
const Utilizator& Utilizator::operator++() {
    this->varsta++;
    return *this;
}
const Utilizator Utilizator::operator++(int) {
    Utilizator aux(*this);
    this->varsta++;
    return aux;
}

istream& operator>>(istream& in, Utilizator& cont)
{


//    in>>p.nume;
    char *aux;
    cout << "\nNume: ";
    in >> aux;
    if (cont.nume != NULL)
        delete[] cont.nume;
    cont.nume = new char[strlen(aux) + 1];
    strcpy(cont.nume, aux);

    cout << "\nPrenume: ";
    in >> cont.prenume;
    cout << "\nVarsta: ";
    in >> cont.varsta;
    cout << "\npersoana [1-fizica/0-juridica]: ";
    in >> cont.persoana;
    cout << "\nInitiala tata: ";
    in >> cont.initialaTatat;


    cout << "\nCate Carduri vreti sa adaugati: "<<endl;
    in >> cont.lungimeListaCarduri;

    if (cont.listaCarduri != NULL)
        delete[] cont.listaCarduri;
    cont.listaCarduri = new Card[cont.lungimeListaCarduri];
    for (int i = 0; i < cont.lungimeListaCarduri; i++)
        in >> cont.listaCarduri[i];


    if (cont.listaCarduri!= NULL)
        delete[] cont.listaCarduri;
    cont.listaCarduri = new Card[cont.lungimeListaCarduri];
    cout << "\nCarduri "<<endl;
    for (int i = 0; i <cont.lungimeListaCarduri; i++)
        in >>cont.listaCarduri[i];


    return in;

}

ostream& operator<<(ostream& out, const Utilizator& cont)
{


    out << "\nId Utilizator: " << cont.idUtilizator;
    out << "\nNume: " << cont.nume;
    out << "\nPrenume: " << cont.prenume;
    out << "\nVarsta: " << cont.varsta;
    out << "\nInitiala tata: " << cont.initialaTatat;
    out << "\npersoana: ";
    if (cont.persoana) out << "da";
    else out << "nu";
    out<< "\n Numarul de carduri este "<<cont.lungimeListaCarduri;
    out << "\nCardurile dumneavoastra sunt: "<<endl;
    for (int i = 0; i <cont.lungimeListaCarduri; i++)
        out <<cont.listaCarduri[i] <<endl;

    return out;

}


void  Utilizator::setVarsta(int varsta) {

    this->varsta = varsta;
}
void  Utilizator::setNume(char* nume) {

    if (this->nume != NULL)
        delete[] this->nume;
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);

}
int  Utilizator::getVarsta() {

    return this->varsta;
}
const char* Utilizator::getNume() {
    return this->nume;
}

Utilizator::Utilizator() :idUtilizator(contorId++) {

    this->nume = new char[strlen("Anonim") + 1];
    strcpy(this->nume, "Anonim");

    this->prenume = "Anonim";
    this->varsta = 0;
    this->persoana = true;
    this->initialaTatat = 'M';

    this->lungimeListaCarduri = 0;
    this->listaCarduri = 0;

}

Utilizator:: Utilizator(char* nume, string prenume, int varsta, bool persoana, char initialaTatat, Card* listaCarduri, int lungimeListaCarduri):idUtilizator(contorId++)
{

    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);

    this->prenume = prenume;
    this->varsta = varsta;
    this->persoana = persoana;
    this->initialaTatat = initialaTatat;

    this->lungimeListaCarduri = lungimeListaCarduri;

    this->listaCarduri = new Card[lungimeListaCarduri];
    for (int i = 0; i < lungimeListaCarduri; i++)
        this->listaCarduri[i] = listaCarduri[i];


}

Utilizator::Utilizator(const Utilizator& cont) :idUtilizator(cont.idUtilizator) {

    this->nume = new char[strlen(cont.nume) + 1];
    strcpy(this->nume, cont.nume);

    this->prenume = cont.prenume;
    this->varsta = cont.varsta;
    this->persoana = cont.persoana;
    this->initialaTatat = cont.initialaTatat;


    this->lungimeListaCarduri = cont.lungimeListaCarduri;
    this->listaCarduri = new Card[cont.lungimeListaCarduri];
    for (int i = 0; i < cont.lungimeListaCarduri; i++)
        this->listaCarduri[i] =cont.listaCarduri[i];


}

Utilizator& Utilizator::operator= (const Utilizator& cont) {

    if (this != &cont) {

        if (this->nume != NULL)
            delete[] this->nume;
        this->nume = new char[strlen(cont.nume) + 1];
        strcpy(this->nume, cont.nume);

        this->prenume = cont.prenume;
        this->varsta = cont.varsta;
        this->persoana = cont.persoana;
        this->initialaTatat = cont.initialaTatat;

        this->lungimeListaCarduri =cont.lungimeListaCarduri;
        if (this->listaCarduri != NULL)
            delete[] this->listaCarduri;

        this->listaCarduri = new Card[cont.lungimeListaCarduri];
        for (int i = 0; i < cont.lungimeListaCarduri; i++)
            this->listaCarduri[i] =cont.listaCarduri[i];


    }

    return *this;

}

Utilizator::~Utilizator() {

    if (this->nume != NULL)
        delete[] this->nume;
    if (this->listaCarduri != NULL)
        delete[] this->listaCarduri;

}


void  Utilizator::afisare2() {


    cout << "\n\nUtilizator are id: " << this->idUtilizator<<endl;
    cout << "\nNume: " << this->nume<<endl;
    cout << "\nVarsta: " << this->varsta<<endl;
    cout << "\npersoana: "; if (this->persoana) cout << "DA"; else cout << "NU"<<endl;
    cout << "\nIntialaTata: " << this->initialaTatat<<endl;

    if (this->lungimeListaCarduri != 0)
    {
        cout << "Cardurile dumneavoastra sunt: "<<endl;
        for (int i = 0; i < this->lungimeListaCarduri; i++)
            cout << this->listaCarduri[i] <<endl;

    }
    cout << endl;


}


int main() {
//    Bancnota p1("Euro","Eur","Europa",20), p2("Euro","Eur","Europa",20);
//    Bancnota p3=Bancnota();
//    Bancnota p4=Bancnota();
  //CursValutar t1= CursValutar();
   //cout<<t1;
//    cin>>t1;
//    cin>>p3;
//    cin>>p4;
//    cout<<t1.cumparare(10,p3,p4,20);


  //  Bancnota b("Euro","Eur","Europa",10);
//    Card( Bancnota ban, int* numarCard, int lungimeNumarCard,  string dataExp, string numeBanca, float total)

// Card c(b, 1, 6, "09/20", "Banca Transilvania", 1050);
//Utilizator p1=Utilizator();
//    cout << p1;


    return 0;
}
