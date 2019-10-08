#include <iostream>

using namespace std;

class Cosmetic{
private:
    bool isOpened = 0;
public:
    string name;
    int monthOpened;
    int yearOpened;
    int pao;
    bool getIsOpened (){
        return isOpened;
    }
    void setIsOpened () {
        this->isOpened = 1;
    }
    void whenOpened (int month, int year){
        this->monthOpened = month;
        this->yearOpened = year;
    }

};

class Cream : public Cosmetic {
public:
    string creamType;
    Cream(string name){
        this->name = name;
        this->creamType = "moisturizing";
    }
    ~Cream(){
        cout<<"deleted: "<<this->name<<endl;
    }
};

class Mascara : public Cosmetic {
public:
    string formula = "thick";

    Mascara(string name) {
        this->name = name;
    }
    ~Mascara(){
        cout<<"deleted: "<<this->name<<endl;
    }

};

class Lipstick : public Cosmetic {
public:
    string color = "red";
    Lipstick(string name) {
        this->name = name;
    }
    ~Lipstick(){
        cout<<"deleted: "<<this->name<<endl;
    }

};

class Eyeshadow : public Cosmetic {
public:
    bool inPalette = 0;
    Eyeshadow(string name) {
        this->name = name;
    }
    ~Eyeshadow(){
        cout<<"deleted: "<<this->name<<endl;
    }
};

int currentYear = 2019;
int currentMonth = 10;

void rotten (Cosmetic kosmetyk){
        int year =0;
        int month=0;
        if (((kosmetyk.pao)%12)==0) {
            year = kosmetyk.yearOpened + (kosmetyk.pao)/12;
            month = kosmetyk.monthOpened;
        }else {
            month = kosmetyk.monthOpened + kosmetyk.pao;
        }

        if (year <= currentYear){
            if (month <= currentMonth){
                cout<<"\n expired: "<<kosmetyk.name;
            }
        }

    }

int main(){
    Cream Nivea("Nivea");
    Mascara Rimmel("rimmel");
    Eyeshadow colourpop("colourpop");
    Lipstick Loreal("L'oreal");

    Nivea.setIsOpened();
    Nivea.pao = 12;
    Nivea.whenOpened(2,2018);

    Rimmel.setIsOpened();
    Rimmel.pao = 6;
    Rimmel.whenOpened(9,2019);

    colourpop.setIsOpened();
    colourpop.pao = 36;
    colourpop.whenOpened(6,2016);

    Loreal.pao = 24;

    rotten(Rimmel);
    rotten(Nivea);
    rotten(colourpop);

    return 0;
}