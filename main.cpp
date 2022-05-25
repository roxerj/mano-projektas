#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
void Sort(int* arr, int n);

struct Studentas {
    string Vardas;
    string Pavarde;
    int nd[10];
    int egz;
    int ndsk;
    double vidurkis;
    double mediana;
};
void print(Studentas* studentai, int kiekis);
void printStudentai(Studentas* studentai, int kiekis, bool isVid);
void nuskaitymas(int n, int m)



int main()
{
    double vidurkis = 0;
    int studentukiekis = 0;
    cout << "iveskite studentu kieki" << endl;

    cin >> studentukiekis;
    while (studentukiekis < 1)
    {
        cout << "studentu skaicius turi buti bent vienas" << endl;
        cin >> studentukiekis;
    }
    Studentas studentai[10];
    vector<Studentas> studentai2;

    for (int i = 0; i < studentukiekis; i++)

    {
        cout << "iveskite varda, pavarde" << endl;
        cin >> studentai[i].Vardas >> studentai[i].Pavarde;
        cout << "kiek yra namu darbu pazymiu? ";
        cin >> studentai[i].ndsk;
        while (studentai[i].ndsk < 1)
        {
            cout << "pazymiu skaicius turi buti bent vienas??" << endl;
            cin >> studentai[i].ndsk;
        }

        cout << "iveskite namu darbu pazymius" << endl;
        for (int j = 0; j < studentai[i].ndsk; j++)
        {
            int pazymys;
            cin >> pazymys;

            while (pazymys > 10 || pazymys < 1)
            {
                cout << "ivestas pazymis turi buti tarp 1 ir 10" << endl;
                cin >> pazymys;

            }studentai[i].nd[j] = pazymys;
            studentai[i].vidurkis += pazymys;

        }   Studentas studentas;
        studentas.Vardas = studentai[i].Vardas;
        studentai2.push_back(studentas);
        for (int j = 0; j < studentai2.size(); j++)
        {
            cout << "\nstudentu sk vektoriuje:  " << studentai2.size() << studentai2[j].Vardas << " " << endl;
        }
        studentai[i].vidurkis = studentai[i].vidurkis / studentai[i].ndsk;


        cout << "koks egzamino pazymys?" << endl;
        cin >> studentai[i].egz;
        while (studentai[i].egz > 10 || studentai[i].egz < 1)
        {
            cout << "egzamino pazymis turi buti tarp 1 ir 10" << endl;
            cin >> studentai[i].egz;
        }
        // cout<<studentai[0].Vardas<<endl<<studentai[0].Pavarde<<endl<<studentai[0].nd<<endl<<studentai[0].egz<<endl;




        Sort(studentai[i].nd, studentai[i].ndsk);
        double mediana = 0;
        int n = studentai[i].ndsk;
        if (studentai[i].ndsk % 2 == 0)
        {
            cout << "namu darbu skaicius lyginis" << endl;
            mediana = (double)(studentai[i].nd[(n - 1) / 2] + studentai[i].nd[n / 2]) / 2.0;

        }
        else
        {
            cout << "namu darbu skaicius nelyginis" << endl;

            mediana = (double)studentai[i].nd[n / 2];
        };
        studentai[i].mediana = mediana;


        /*  for(int i=0; i<studentai[0].ndsk; i++){
              cout<<studentai[0].nd[i]<<endl;
          }*/
        cout << "mediana yra " << mediana << endl;

    }


       // cout << "galutinis pazymys yra " << setprecision(3) << galutinis << endl;

    print(studentai, studentukiekis);
    return 0;
}

void Sort(int* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void print(Studentas* studentai, int kiekis)
{
    cout <<"ar norite kad galutinis pazymys butu skaiciuojamas pagal namu darbu vidurki ar mediana?"<<endl<<"iveskite 1 jei renkates vidurki, iveskite 2 jei renkates mediana"<<endl;
        double medarvid = 0;
        cin >>medarvid;
        while(medarvid!=1 && medarvid!=2)
        {
            cout<<"iveskite 1 arba 2"<<endl;
            cin>>medarvid;
        }
        if(medarvid==1)
        {
            cout<<"vid"<<endl;
           printStudentai(studentai,kiekis,true);

        }else
        {
            printStudentai(studentai,kiekis,false);
            cout<<"med"<<endl;
        }

}
void printStudentai(Studentas* studentai, int kiekis, bool isVid){

    if(isVid){
       printf("Pavarde  Vardas   Galutinis (Vid.)\n");
    }
    else{
        printf("Pavarde  Vardas   Galutinis (Med.)\n");
    }


    for(int i=0; i<kiekis; i++){
         if(isVid){
        cout<<studentai[i].Pavarde<<studentai[i].Vardas<<studentai[i].mediana<<endl;;
    }
    else{
        cout<<studentai[i].Pavarde<<studentai[i].Vardas<<studentai[i].mediana;
    }










    }





}
