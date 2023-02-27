
#include <iostream>
#include <cstring>
using namespace std;


//interfata
class CitireAfisare{
public:
    virtual ostream& Afisare(ostream&)const=0;
    virtual istream& Citire(istream&)=0;


};

//clasa abstracta
class SoftwareEngineer:public CitireAfisare{
protected:

    string nume, prenume, educatie;
    float salariu;
    int experientaAni;
    int nrLimbajeProgramare, nrFrameWorkuri;

public:

    //constructorul fara parametri
    SoftwareEngineer(){


        this->nume="Anonim";
        this->prenume="Anonim";
        this->educatie="Facultate";
        this->salariu = 0;
        this->experientaAni =0;
        this->nrLimbajeProgramare=0;
        this->nrFrameWorkuri=0;


    }
    //constructorul cu toti parametri
    SoftwareEngineer(string nume,string prenume, string educatie, int experientaAni, float salariu, int nrLimbajeProgramare, int nrFrameWorkuri){
        cout<<"cosntructor SoftwareEngineer:\n";

        this->nume=nume;
        this->prenume=prenume;
        this->educatie=educatie;
        this->salariu = salariu;
        this->experientaAni =experientaAni;
        this->nrLimbajeProgramare=nrLimbajeProgramare;
        this->nrFrameWorkuri=nrFrameWorkuri;

    }
    //copy constructor

    SoftwareEngineer(const SoftwareEngineer &s)
    {
        this->nume=s.nume;
        this->prenume=s.prenume;
        this->educatie=s.educatie;
        this->experientaAni=s.experientaAni;
        this->salariu=s.salariu;
        this->nrLimbajeProgramare=s.nrLimbajeProgramare;
        this->nrFrameWorkuri=s.nrFrameWorkuri;
    }
    //operatorul =
    virtual SoftwareEngineer & operator =(const SoftwareEngineer &s)
    {
        if(this!=&s) {
            this->nume = s.nume;
            this->prenume = s.prenume;
            this->educatie = s.educatie;
            this->experientaAni = s.experientaAni;
            this->salariu = s.salariu;
            this->nrLimbajeProgramare = s.nrLimbajeProgramare;
            this->nrFrameWorkuri = s.nrFrameWorkuri;
        }
        return *this;
    }
        virtual bool operator==(const SoftwareEngineer& soft){
        if(this->salariu==soft.salariu && this->experientaAni==soft.experientaAni &&
        this->nrFrameWorkuri==soft.nrFrameWorkuri && this->nrLimbajeProgramare==soft.nrLimbajeProgramare
        && this->educatie==soft.educatie && this->nume==soft.nume && this->prenume==soft.prenume)
            return true;
        else return false;
    }
     void setNume(string nume)
    {
        this->nume=nume;
    }

    string getNume()
    {
        return this->nume;
    }

    //operatorul de afisare
     virtual ostream& Afisare (ostream& out) const{

        out<<"Nume: "<<this->nume<<endl;
        out<<" Prenume: "<<this->prenume<<endl;
        out<<" Forma de educatie: "<<this->educatie<<endl;
        out<<"Salariu: "<<this->salariu<<endl;
        out<<" Ani de experienta: "<<this->experientaAni<<endl;
        out<<" Numarul de limbaje de programare cunoscute: "<<this->nrLimbajeProgramare<<endl;
        out<<" Numarul de framework-uri cunoscute: "<<this->nrFrameWorkuri<<endl;


        return out;

    }


    // operatorul de citire
    virtual  istream& Citire(istream& in){

        cout<<"Numele: ";
        in>>this->nume;
        cout<<"\nPrenumele ";
        in>>this->prenume;
        cout<<"\nForma de educatie: ";
        in>>this->educatie;
        cout<<"\nSalariu: ";
        in>>this->salariu;
        cout<<"\nAni de experienta: ";
        in>>this->experientaAni;
        cout<<"\nNumarul de limbaje de programare cunoscute: ";
        in>>this->nrLimbajeProgramare;
        cout<<"\nNumarul de framework-uri cunoscute: ";
        in>>this->nrFrameWorkuri;


        return in;
    }

    friend istream& operator>>(istream& in, SoftwareEngineer& p)
    {
        return p.Citire(in);
    }
    friend ostream& operator<<(ostream& out, const SoftwareEngineer& p)
    {
        return p.Afisare(out);
    }

    //functia virtuala pura
    virtual float calculeazaSalariu()=0;
    ~SoftwareEngineer(){

        cout<<"\n Destructor SoftwareEngineer\n";
    }
};

class FrontEndEngineer: virtual public SoftwareEngineer{
protected:

    int nivelCreativitate;
    string spiritArtistic, trioPackageHTMLCSSJS;
    int nrInstrumenteDesign;

public:
    //constructor fara parametri
    FrontEndEngineer():SoftwareEngineer(){

        this->nivelCreativitate=10;
        this->spiritArtistic="DA";
        this->trioPackageHTMLCSSJS="DA";
        this->nrInstrumenteDesign=2;


    }
    //constructor cu toti parametri
    FrontEndEngineer(string nume, string prenume, string educatie, int experientaAni, float salariu, int nrLimbajeProgramare, int nrFrameWorkuri, int nivelCreativitate, string spiritArtistic, string trioPackageHTMLSCSSJS, int nrInstrumenteDesign):
            SoftwareEngineer(nume,prenume,educatie, experientaAni, salariu, nrLimbajeProgramare, nrFrameWorkuri){
        cout<<"cosntructor FrontEndEngineer:\n";
        this->nivelCreativitate=nivelCreativitate;
        this->spiritArtistic=spiritArtistic;
        this->trioPackageHTMLCSSJS=trioPackageHTMLSCSSJS;
        this->nrInstrumenteDesign=nrInstrumenteDesign;

    }

    //constructor de copiere
    FrontEndEngineer(const FrontEndEngineer &f):SoftwareEngineer(f){

        this->spiritArtistic=f.spiritArtistic;
        this->nivelCreativitate=f.nivelCreativitate;
        this->trioPackageHTMLCSSJS=f.trioPackageHTMLCSSJS;
        this->nrInstrumenteDesign=f.nrInstrumenteDesign;
        cout<<"Copy constructor FRONTEND"<<endl;
    }

    virtual bool operator==(const FrontEndEngineer& front)
    {
        SoftwareEngineer::operator==(front);
        if ( SoftwareEngineer::operator==(front) && (this->nrInstrumenteDesign==front.nrInstrumenteDesign && this->nivelCreativitate==front.nivelCreativitate
        && this->trioPackageHTMLCSSJS==front.trioPackageHTMLCSSJS && this->spiritArtistic==front.spiritArtistic))
            return true;
        else return false;
    }

    virtual FrontEndEngineer& operator=(const FrontEndEngineer& f)
    {
        if (this != &f)
        {
            SoftwareEngineer::operator=(f);
            this->spiritArtistic = f.spiritArtistic;
            this->trioPackageHTMLCSSJS=f.trioPackageHTMLCSSJS;
            this->nrInstrumenteDesign=f.nrInstrumenteDesign;
            this->nivelCreativitate=f.nivelCreativitate;
        }
        return *this;
    }




       virtual ostream& Afisare (ostream& out) const{

        SoftwareEngineer::Afisare(out);

        out<<"\nNota creativitate: "<<this->nivelCreativitate;
        out<<"\nAre spirit artistic:  "<<this->spiritArtistic;
        out<<"\nStie HTML, CSS, JavaScript: "<<this->trioPackageHTMLCSSJS;
        out<<"\nCate instrumente de Design stie sa foloseasca (Photoshop, Adobe..): "<<this->nrInstrumenteDesign;



        return out;

    }

    virtual istream& Citire(istream& in){

       SoftwareEngineer::Citire(in);

        cout<<"\nNota creativitate: ";
        in>>this->nivelCreativitate;
        cout<<"\nAre spirit artistic:  ";
        in>>this->spiritArtistic;
        cout<<"\nStie HTML, CSS, JavaScript: ";
        in>>this->trioPackageHTMLCSSJS;
        cout<<"\nCate instrumente de Design stie sa foloseasca (Photoshop, Adobe..): ";
        in>>this->nrInstrumenteDesign;


        return in;
    }

    float calculeazaSalariu(){
        if (this->nrInstrumenteDesign>4)
            return (float) 30/100*this->salariu+this->salariu;
        else return (float) this->salariu;
    }



    ~FrontEndEngineer(){

        cout<<"\n Destructor FrontEndEngineer\n";
    }
};

class BackendEngineer: public virtual SoftwareEngineer{
protected:

    int ExperientaSecuritateWeb;
    string Analitic;
    string hasGoodDSA;
    int nrElemPachetDBMS;

public:

    BackendEngineer():SoftwareEngineer(){

        this->ExperientaSecuritateWeb=2;
        this->Analitic="Da";
        this->hasGoodDSA="Da";
        this->nrElemPachetDBMS=2;

    }


    BackendEngineer(string nume, string prenume, string educatie, int experientaAni, float salariu,int nrLimbajeProgramare, int nrFrameWorkuri,
                    int ExperientaSecuritateWeb, string Analitic, string hasGoodDSA, int nrElemPachetDBMS):
            SoftwareEngineer(nume,prenume,educatie, experientaAni, salariu, nrLimbajeProgramare, nrFrameWorkuri){

        cout<<"cosntructor BackendEngineer:\n";
        this->ExperientaSecuritateWeb=ExperientaSecuritateWeb;
        this->Analitic=Analitic;
        this->hasGoodDSA=hasGoodDSA;
        this->nrElemPachetDBMS=nrElemPachetDBMS;

    }


    //constructorul de copiere
    BackendEngineer(const BackendEngineer & b):SoftwareEngineer(b)
    {

        this->Analitic=b.Analitic;
        this->hasGoodDSA=b.hasGoodDSA;
        this->ExperientaSecuritateWeb=b.ExperientaSecuritateWeb;
        this->nrElemPachetDBMS=b.nrElemPachetDBMS;



    }

    virtual bool operator ==(const BackendEngineer& back)
    {
        if(SoftwareEngineer::operator==(back) && (this->nrElemPachetDBMS==back.nrElemPachetDBMS &&
        this->ExperientaSecuritateWeb==back.ExperientaSecuritateWeb && this->Analitic==back.Analitic
        && this->hasGoodDSA==back.hasGoodDSA))
            return true;
        else return false;
    }
    virtual BackendEngineer & operator =(const BackendEngineer & b)
    {
        if(this != &b)
        {
            this->SoftwareEngineer::operator=(b);
            this->Analitic=b.Analitic;
            this->hasGoodDSA=b.hasGoodDSA;
            this->ExperientaSecuritateWeb=b.ExperientaSecuritateWeb;
            this->nrElemPachetDBMS=b.nrElemPachetDBMS;
            cout<<"\nop = Backend"<<endl;
        }
        return *this;
    }





    virtual ostream& Afisare(ostream& out) const{

        SoftwareEngineer::Afisare(out);
        out<<"\nAni de experienta are in securitate web: "<<this->ExperientaSecuritateWeb;
        out<<"\nEste analitic? "<<this->Analitic;
        out<<"\n Este bun la rezolvat probleme? "<<this->hasGoodDSA;
        out<<"\n Numarul de tehnologii de baze de date cunoscute: "<<this->nrElemPachetDBMS;

        return out;

    }

    virtual istream& Citire(istream& in){

        SoftwareEngineer::Citire(in);
        cout<<"\nAni de experienta are in securitate web: ";
        in>>this->ExperientaSecuritateWeb;
        cout<<"\nEste analitic? ";
        in>>this->Analitic;
        cout<<"\n Este bun la rezolvat probleme? ";
        in>>this->hasGoodDSA;
        cout<<"\n Numarul de tehnologii de baze de date cunoscute: ";
        in>>this->nrElemPachetDBMS;


        return in;
    }

    float calculeazaSalariu() {
        if (this->ExperientaSecuritateWeb > 3 && this->nrElemPachetDBMS > 4)
            return (float) 25 / 100 * this->salariu + this->salariu;
        else return (float) this->salariu;
    }

    ~BackendEngineer(){

        cout<<"\n Destructor BackendEngineer\n";
    }

};

class FullStackEngineer:public FrontEndEngineer, public BackendEngineer{
protected:

    int nivelRezistentaStres;
    string Multitasking;


public:
    FullStackEngineer():BackendEngineer(), FrontEndEngineer(),SoftwareEngineer(){

        this->nivelRezistentaStres=5;
        this->Multitasking="Da";


    }
    FullStackEngineer(string nume,string prenume,  string educatie, int experientaAni, float salariu, int nrLimbajeProgramare, int nrFrameWorkuri,
                      int nivelCreativitate, string spiritArtistic, string trioPackageHTMLSCSSJS, int nrInstrumenteDesign,
                      int ExperientaSecuritateWeb, string Analitic, string hasGoodDSA, int nrElemPachetDBMS,
                      int nivelRezistentaStres, string Multitasking, int bonusSite):
            BackendEngineer(nume,prenume,educatie, experientaAni, salariu, nrLimbajeProgramare, nrFrameWorkuri, ExperientaSecuritateWeb, Analitic, hasGoodDSA, nrElemPachetDBMS),
            FrontEndEngineer(nume,prenume,educatie, experientaAni, salariu, nrLimbajeProgramare, nrFrameWorkuri, nivelCreativitate, spiritArtistic, trioPackageHTMLSCSSJS, nrInstrumenteDesign),
            SoftwareEngineer(nume,prenume, educatie, experientaAni, salariu, nrLimbajeProgramare, nrFrameWorkuri)
            {

                    cout<<"cosntructor FullStackEngineer:\n";

                    this->nivelRezistentaStres=nivelRezistentaStres;
                    this->Multitasking=Multitasking;

            }

    FullStackEngineer(const FullStackEngineer &fl): BackendEngineer(fl),FrontEndEngineer(fl),SoftwareEngineer(fl)
    {
        this->Multitasking=fl.Multitasking;
        this->nivelRezistentaStres=fl.nivelRezistentaStres;

        cout<<"Copy constructor FULLSTACK"<<endl;
    }

    bool operator==(const FullStackEngineer& full)
    {
        if(FrontEndEngineer::operator==(full) && (this->Multitasking==full.Multitasking && this->nivelRezistentaStres==full.nivelRezistentaStres
        && this->ExperientaSecuritateWeb==full.ExperientaSecuritateWeb && this->nrElemPachetDBMS==full.nrElemPachetDBMS
        && this->hasGoodDSA==full.hasGoodDSA && this->Analitic==full.Analitic))
            return true;
        else return false;
    }
    FullStackEngineer & operator=(const FullStackEngineer & fl){
        if(this != &fl)
        {
            this->BackendEngineer::operator=(fl);
            this->FrontEndEngineer::operator=(fl);
            this->nivelRezistentaStres=nivelRezistentaStres;
            this->Multitasking=Multitasking;
        }
        cout<<"FULL stack OP =";
        return *this;


    }

     virtual istream& Citire(istream& in){

        FrontEndEngineer::Citire(in);


        cout<<"\nAni de experienta are in securitate web: ";
        in>>this->ExperientaSecuritateWeb;
        cout<<"\nEste analitic? ";
        in>>this->Analitic;
        cout<<"\n Este bun la rezolvat probleme? ";
        in>>this->hasGoodDSA;
        cout<<"\n Numarul de tehnologii de baze de date cunoscute: ";
        in>>this->nrElemPachetDBMS;
        cout<<"\n Nota rezistenta la stres: ";
        in>>this->nivelRezistentaStres;
        cout<<"\n Este bun la multitasking? ";
        in>>this->Multitasking;

        return in;
    }
     virtual ostream& Afisare(ostream& out) const{

        FrontEndEngineer::Afisare(out);

        out<<"\nAni de experienta are in securitate web: "<<this->ExperientaSecuritateWeb;
        out<<"\nEste analitic? "<<this->Analitic;
        out<<"\n Este bun la rezolvat probleme? "<<this->hasGoodDSA;
        out<<"\n Numarul de tehnologii de baze de date cunoscute: "<<this->nrElemPachetDBMS;

        out<<"\n Nota rezistenta la stres: "<<this->nivelRezistentaStres;
        out<<"\n Este bun la multitasking? "<<this->Multitasking;


        return out;

    }

    float calculeazaSalariu(){
        if(this->nivelRezistentaStres)
           return (float) 50/100*this->salariu+this->salariu;
        else return (float) this->salariu;
    }
    ~FullStackEngineer(){

        cout<<"\n Destructor FullStackEngineer\n";
    }


};



class CompanieIT{
private:
    string nume;
    double profit;
    int nrBackendEngineeri, nrFrontEndEngineeri, nrFullStackEngineeri;
    FrontEndEngineer *listaFrontEndEngineer;
    BackendEngineer *listaBackendEngineer;
    FullStackEngineer *listaFullStackEngineer;




public:

    CompanieIT& operator=(const CompanieIT & companie);
    CompanieIT();
    CompanieIT(string nume, double profit, int nrBackendEngineeri,
               BackendEngineer  *listaBackendEngineer, int  nrFrontEndEngineeri, FrontEndEngineer *listaFrontEndEngineer,
               int nrFullStackEngineeri, FullStackEngineer *listaFullStackEngineer);

    void setProfit(double profit);
    void setNume(string nume);
    string getNume();
    int getNrBackendEngineeri();
    double getProfit();
    const FrontEndEngineer* getFrontEnd()const;
    const BackendEngineer* getBackEnd()const;
    const FullStackEngineer* getFullStack()const;
    void setFrontEnd(int nrFrontEndEngineeri, FrontEndEngineer *listaFrontEndEngineer);
    void setBackEnd(int nrBackendEngineeri, BackendEngineer *listaBackendEngineer );
    void setFullStack(int nrFullStackEngineeri, FullStackEngineer *listaFullStackEngineer);
    friend ostream& operator<<(ostream& out, const CompanieIT& companie);
    friend istream& operator>>(istream& in, CompanieIT& companie);
    // bun deci vreau sa am o lista de front end engineer, o lista de back end engineer, o lista de fullstackengineer
    void adaugareFrontEnd(const FrontEndEngineer&);
    void adaugareBackEnd(const BackendEngineer&);
    void adaugareFullStack(const FullStackEngineer&);
    void stergereFrontEnd(const FrontEndEngineer&);
    void stergereBackEnd(const BackendEngineer&);
    void stergereFullStack(const FullStackEngineer&);
    ~CompanieIT(){
        cout<<"\n Destructor CompanieIT";
    }

};

void CompanieIT::setFrontEnd(int nrFrontEndEngineeri, FrontEndEngineer *listaFrontEndEngineer) {
    if(this->listaFrontEndEngineer!=NULL)
        delete[] this->listaFrontEndEngineer;
    this->nrFrontEndEngineeri=nrFrontEndEngineeri;
    this->listaFrontEndEngineer= new FrontEndEngineer[this->nrFrontEndEngineeri];
    for(int i=0;i<nrFrontEndEngineeri;i++)
        this->listaFrontEndEngineer[i]=listaFrontEndEngineer[i];

}
void CompanieIT::setBackEnd(int nrBackendEngineeri, BackendEngineer *listaBackendEngineer) {
    if(this->listaBackendEngineer!=NULL)
        delete[] this->listaBackendEngineer;
    this->nrBackendEngineeri=nrBackendEngineeri;
    this->listaBackendEngineer=new BackendEngineer[this->nrBackendEngineeri];
    for(int i=0;i<nrBackendEngineeri;i++)
        this->listaBackendEngineer[i]=listaBackendEngineer[i];
}
void CompanieIT::setFullStack(int nrFullStackEngineeri, FullStackEngineer *listaFullStackEngineer) {
    if(this->listaFullStackEngineer!=NULL)
        delete[] this->listaFullStackEngineer;
    this->nrFullStackEngineeri=nrFullStackEngineeri;
    this->listaFullStackEngineer=new FullStackEngineer[this->nrFullStackEngineeri];
    for(int i=0;i<nrFullStackEngineeri;i++)
        this->listaFullStackEngineer[i]=listaFullStackEngineer[i];
}
const FrontEndEngineer* CompanieIT::getFrontEnd() const {
    return this->listaFrontEndEngineer;
}
const BackendEngineer* CompanieIT::getBackEnd() const {
    return this->listaBackendEngineer;
}
const FullStackEngineer* CompanieIT::getFullStack() const {
    return this->listaFullStackEngineer;
}

void CompanieIT::adaugareFrontEnd(const FrontEndEngineer &front) {
    FrontEndEngineer *listaFrontEngineerAux;
    listaFrontEngineerAux= new FrontEndEngineer[nrFrontEndEngineeri];
    for(int i=0;i<nrFrontEndEngineeri;i++)
        listaFrontEngineerAux[i]=listaFrontEndEngineer[i];
    if(listaFrontEndEngineer!=NULL)
        delete[] listaFrontEndEngineer;
    nrFrontEndEngineeri = nrFrontEndEngineeri+1;
    listaFrontEndEngineer = new FrontEndEngineer[nrFrontEndEngineeri];
    for(int i=0;i<nrFrontEndEngineeri-1;i++)
        listaFrontEndEngineer[i]=listaFrontEngineerAux[i];
    listaFrontEndEngineer[nrFrontEndEngineeri-1]=front;

    if(listaFrontEngineerAux!=NULL)
        delete[] listaFrontEngineerAux;


}
void CompanieIT::adaugareBackEnd(const BackendEngineer &back) {
    BackendEngineer *listaBackEndEngineerAux;
    listaBackEndEngineerAux = new BackendEngineer[nrBackendEngineeri];
    for(int i=0;i<nrBackendEngineeri;i++)
        listaBackEndEngineerAux[i]=listaBackendEngineer[i];
    if(listaBackendEngineer!=NULL)
        delete[]  listaBackendEngineer;

    nrBackendEngineeri=nrBackendEngineeri+1;
    listaBackendEngineer = new BackendEngineer[nrBackendEngineeri];
    for(int i=0;i<nrBackendEngineeri-1;i++)
        listaBackendEngineer[i]=listaBackEndEngineerAux[i];
    listaBackendEngineer[nrBackendEngineeri-1]=back;
    if(listaBackEndEngineerAux!=NULL)
        delete[] listaBackEndEngineerAux;

}
void CompanieIT::adaugareFullStack(const FullStackEngineer &full) {
    FullStackEngineer *listaFullStackEngineerAux;
    listaFullStackEngineerAux=new FullStackEngineer[nrFullStackEngineeri];
    for(int i=0;i<nrFullStackEngineeri;i++)
        listaFullStackEngineerAux[i]=listaFullStackEngineer[i];
    if(listaFullStackEngineer!=NULL)
        delete[]  listaFullStackEngineer;

    nrFullStackEngineeri=nrFullStackEngineeri+1;
    listaFullStackEngineer = new FullStackEngineer[nrFullStackEngineeri];

    for(int i=0;i<nrFullStackEngineeri-1;i++)
        listaFullStackEngineer[i]=listaFullStackEngineerAux[i];

    listaFullStackEngineer[nrFullStackEngineeri-1]=full;
    if(listaFullStackEngineerAux!=NULL)
        delete[] listaFullStackEngineerAux;

}

void CompanieIT::stergereFrontEnd(const FrontEndEngineer &front) {
    FrontEndEngineer *listaFrontEngineerAux;
    int contor=0;
    listaFrontEngineerAux= new FrontEndEngineer[nrFrontEndEngineeri];
    for(int i=0;i<nrFrontEndEngineeri;i++) {
        if(listaFrontEndEngineer[i] == front)
            contor++;
        listaFrontEngineerAux[i]=listaFrontEndEngineer[i];
    }
    if(listaFrontEndEngineer!=NULL)
        delete[] listaFrontEndEngineer;
    nrFrontEndEngineeri = nrFrontEndEngineeri-contor;
    listaFrontEndEngineer = new FrontEndEngineer[nrFrontEndEngineeri];
    for(int i=0;i<nrFrontEndEngineeri+contor;i++) {
        if (!(listaFrontEngineerAux[i] == front))
            listaFrontEndEngineer[i] = listaFrontEngineerAux[i];
    }

    if(listaFrontEngineerAux!=NULL)
        delete[] listaFrontEngineerAux;


}

void CompanieIT::stergereBackEnd(const BackendEngineer &back)  {
    BackendEngineer *listaBackEndEngineerAux;
    int contor=0;
    listaBackEndEngineerAux= new BackendEngineer[nrBackendEngineeri];

    for(int i=0;i<nrBackendEngineeri;i++) {
        if(listaBackendEngineer[i] == back)
            contor++;
        listaBackEndEngineerAux[i]=listaBackendEngineer[i];
    }
    if(listaFrontEndEngineer!=NULL)
        delete[] listaBackendEngineer;
    nrBackendEngineeri= nrBackendEngineeri-contor;
    listaBackendEngineer = new BackendEngineer[nrBackendEngineeri];
    for(int i=0;i<nrBackendEngineeri+contor;i++) {
        if (!(listaBackEndEngineerAux[i] == back))
            listaBackendEngineer[i] = listaBackEndEngineerAux[i];
    }

    if(listaBackEndEngineerAux!=NULL)
        delete[] listaBackEndEngineerAux;


}


void CompanieIT::stergereFullStack(const FullStackEngineer &full) {
    FullStackEngineer *listaFullStackEngineerAux;
    int contor=0;
    listaFullStackEngineerAux = new FullStackEngineer[nrFullStackEngineeri];

    for(int i=0;i<nrFullStackEngineeri;i++) {
        if(listaFullStackEngineer[i] == full)
            contor++;
        listaFullStackEngineerAux[i]=listaFullStackEngineer[i];
    }
    if(listaFullStackEngineer!=NULL)
        delete[] listaFullStackEngineer;
    nrFullStackEngineeri = nrFullStackEngineeri-contor;
    listaFullStackEngineer = new FullStackEngineer[nrFullStackEngineeri];
    for(int i=0;i<nrFullStackEngineeri+contor;i++) {
        if (!(listaFullStackEngineerAux[i] == full))
            listaFullStackEngineer[i] = listaFullStackEngineerAux[i];
    }

    if(listaFullStackEngineerAux!=NULL)
        delete[] listaFullStackEngineerAux;


}




istream& operator>>(istream& in, CompanieIT& companie)
{
    cout<<"\nNumele companiei : ";
    in>>companie.nume;
    cout<<"\nProfitul companiei: ";
    in>>companie.profit;
    cout<<"\nCati angajati se ocupa de partea de FrotEnd: ";
    in>>companie.nrFrontEndEngineeri;

    if(companie.listaFrontEndEngineer!=NULL)
        delete[] companie.listaFrontEndEngineer;
    companie.listaFrontEndEngineer=new FrontEndEngineer[companie.nrFrontEndEngineeri];
    for(int i=0;i<companie.nrFrontEndEngineeri;i++)
    {
        cout<<"\n Dati datele pentru anagajatul "<<i+1<< " pe partea de FrontEnd ";
        in>>companie.listaFrontEndEngineer[i];}


    cout<<"\nCati angajati se ocupa de partea de BackEnd: ";
    in>>companie.nrBackendEngineeri;


    if(companie.listaBackendEngineer!=NULL)
        delete[] companie.listaBackendEngineer;
    companie.listaBackendEngineer=new BackendEngineer[companie.nrBackendEngineeri];
    for(int i=0;i<companie.nrBackendEngineeri;i++) {
        cout<<"\n Dati datele pentru angajatul "<<i+1<<" pe partea de BackEnd ";
        in >> companie.listaBackendEngineer[i];
    }
    cout<<"\nCati angajati se ocupa de partea de FullStack: ";
    in>>companie.nrFullStackEngineeri;

    if(companie.listaFullStackEngineer!=NULL)
        delete[] companie.listaFullStackEngineer;
    companie.listaFullStackEngineer=new FullStackEngineer[companie.nrFullStackEngineeri];
    for(int i=0;i<companie.nrFullStackEngineeri;i++) {
        cout<<"\n Dati datele pentru angajatul "<<i+1<<" pe partea de FullStack ";
        in >> companie.listaFullStackEngineer[i];
    }

    return in;
}

ostream& operator<<(ostream& out, const CompanieIT& companie)
{

    out<<"\nNumele companiei este "<<companie.nume;
    out<<"\nProfitul companiei este "<<companie.profit;
    out<<"\n Numarul de angajati care lucreza pe partea de FrontEnd: "<<companie.nrFrontEndEngineeri;
    out<<"\nAngajati pe partea de FrontEnd sunt:";
    for(int i=0;i<companie.nrFrontEndEngineeri;i++)
        out<<companie.listaFrontEndEngineer[i]<<endl;
    out<<"\n Numarul de angajati care lucreza pe partea de BackEnd: "<<companie.nrBackendEngineeri;
    out<<"\nAngajati pe partea de BackEnd sunt:";
    for(int i=0;i<companie.nrBackendEngineeri;i++)
        out<<companie.listaBackendEngineer[i]<<endl;
    out<<"\n Numarul de angajati care lucreza pe partea de FullStack: "<<companie.nrFullStackEngineeri;
    for(int i=0;i<companie.nrFullStackEngineeri;i++)
        out<<companie.listaFullStackEngineer[i]<<endl;
    return out;

}
void CompanieIT::setNume(string nume) {
    this->nume=nume;
}
void CompanieIT::setProfit(double profit){
    this->profit=profit;
}

string CompanieIT::getNume() {
    return this->nume;
}

double CompanieIT::getProfit() {
    return this->profit;
}


CompanieIT &CompanieIT:: operator=(const CompanieIT &companie) {
    if(this!=&companie)
    {

        this->nrBackendEngineeri=companie.nrFrontEndEngineeri;
        this->nrFrontEndEngineeri=companie.nrFrontEndEngineeri;
        this->nrFullStackEngineeri=companie.nrFullStackEngineeri;
        this->profit=companie.profit;
        this->nume=companie.nume;

        if(this->listaFrontEndEngineer!=NULL)
            delete[] this->listaFrontEndEngineer;
        this->listaFrontEndEngineer=new FrontEndEngineer[companie.nrFrontEndEngineeri];
        for (int i=0; i<companie.nrFrontEndEngineeri;i++)
            this->listaFrontEndEngineer[i]=companie.listaFrontEndEngineer[i];


        if(this->listaBackendEngineer!=NULL)
            delete[] this->listaBackendEngineer;
        this->listaBackendEngineer= new BackendEngineer[companie.nrBackendEngineeri];
        for (int i=0; i<companie.nrBackendEngineeri;i++)
            this->listaBackendEngineer[i]=companie.listaBackendEngineer[i];


        if(this->listaFullStackEngineer!=NULL)
            delete[] this->listaFullStackEngineer;
        this->listaFullStackEngineer= new FullStackEngineer[companie.nrFrontEndEngineeri];
        for (int i=0;i<companie.nrFullStackEngineeri;i++)
            this->listaFullStackEngineer[i]=companie.listaFullStackEngineer[i];



    }
    return *this;
}

CompanieIT::CompanieIT() {
    this->nume='Anonim';
    this->profit=0;
    this->listaFrontEndEngineer=NULL;
    this->listaFullStackEngineer=NULL;
    this->listaBackendEngineer=NULL;
    this->nrFrontEndEngineeri=0;
    this->nrBackendEngineeri=0;
    this->nrFullStackEngineeri=0;

}
CompanieIT::CompanieIT(string nume, double profit, int nrBackendEngineeri,
                       BackendEngineer  *listaBackendEngineer, int  nrFrontEndEngineeri, FrontEndEngineer *listaFrontEndEngineer,
                       int nrFullStackEngineeri, FullStackEngineer *listaFullStackEngineer ){
    this->nrFrontEndEngineeri=nrFrontEndEngineeri;
    this->nrBackendEngineeri=nrBackendEngineeri;
    this->nrFullStackEngineeri=nrFullStackEngineeri;
    this->profit=profit;

    this->listaFrontEndEngineer= new FrontEndEngineer[nrFrontEndEngineeri];
    for(int i=0; i<nrFrontEndEngineeri;i++)
        this->listaFrontEndEngineer[i]=listaFrontEndEngineer[i];

    this->listaBackendEngineer=new BackendEngineer[nrBackendEngineeri];
    for(int i=0;i<nrBackendEngineeri;i++)
        this->listaBackendEngineer[i]=listaBackendEngineer[i];


    this->listaFullStackEngineer = new FullStackEngineer[nrFullStackEngineeri];
    for(int i=0;i<nrFullStackEngineeri;i++)
        this->listaFullStackEngineer[i]=listaFullStackEngineer[i];


}



int main()
{

     CompanieIT comp=CompanieIT();
     int tasta, a,b,c;
     a=b=c=0;
     tasta=1;
     while(tasta==1)
     {
         cout<<"\n1 Adauga angajat FrontEnd ";
         cout<<"\n2 Adauga angajat BackEnd ";
         cout<<"\n3 Adauga angajat FullStack ";
         cout<<"\n4 Sterge angajat FrontEnd ";
         cout<<"\n5 Sterge angajat Backend ";
         cout<<"\n6 Sterge angajat FullStack ";
         cout<<"\n7 Modifica datele companiei ";
         cout<<"\n8 Afisare Angajati ";
         cout<<"\n9 Afisare Salarii finale ";
         cout<<"\n10 Stop ";
         cout<<endl;
            int comanda;
            cin>>comanda;
            switch(comanda)
            {

                case 1: {
                    FrontEndEngineer front = FrontEndEngineer();
                    cin >> front;
                    comp.adaugareFrontEnd(front);
                    a++;
                    break;
                }
                case 2:
                {
                    BackendEngineer back=BackendEngineer();
                    cin>>back;
                    comp.adaugareBackEnd(back);
                    b++;
                    break;
                }
                case 3:
                {
                    FullStackEngineer full=FullStackEngineer();
                    cin>>full;
                    comp.adaugareFullStack(full);
                    c++;
                    break;
                }
                case 4:{
                    FrontEndEngineer front=FrontEndEngineer();
                    cin>>front;
                    comp.stergereFrontEnd(front);
                    a--;
                    break;
                }
                case 5:{
                    BackendEngineer back=BackendEngineer();
                    cin>>back;
                    comp.stergereBackEnd(back);
                    b--;
                    break;
                }

                case 6:
                {
                    FullStackEngineer full=FullStackEngineer();
                    cin>>full;
                    comp.adaugareFullStack(full);
                    c--;
                    break;
                }
                case 7:
                {
                    string numeNou;
                    double profitNou;
                    cout<<"\nDati numele nou al companiei ";
                    cin>>numeNou;
                    comp.setNume(numeNou);
                    cout<<"\nDati noul profit al companiei ";
                    cin>>profitNou;
                    comp.setProfit(profitNou);

                }
               case 8:
               {
                   for(int j=0; j<a;j++)
                       cout<<comp.getFrontEnd()[j];
                   cout<<endl;
                   for(int j=0;j<b;j++)
                       cout<<comp.getBackEnd()[j];
                   cout<<endl;
                   for(int j=0;j<c;j++)
                       cout<<comp.getFullStack()[j];
                   cout<<endl;
                   break;
               }
                case 9:
                {   FrontEndEngineer f;
                     for(int j=0; j<a;j++)
                     {
                         f=comp.getFrontEnd()[j];
                         cout<<f.getNume()<<" "<<f.calculeazaSalariu()<<endl;
                     }
                     BackendEngineer  back;
                     for(int j=0; j<b;j++)
                     {
                         back=comp.getBackEnd()[j];
                         cout<<back.getNume()<<" "<<back.calculeazaSalariu()<<endl;
                     }
                     FullStackEngineer full;
                     for(int j=0;j<c;j++)
                     {
                         full=comp.getFullStack()[j];
                         cout<<full.getNume()<<" "<<full.calculeazaSalariu()<<endl;

                     }

                }
                case 10:
                tasta=0;
                break;
                default:{
                    cout<<"Nu exista comanda";
                }
            }

       }


    return 0;
}


