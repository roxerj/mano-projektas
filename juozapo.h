using namespace std;
struct Studentas {
    string Vardas;
    string Pavarde;
    int nd[15];
    int egz;
    int ndsk;
    double vidurkis;
    double mediana;
    int ilgis;
};
void Sort(int* arr, int n);
void print(Studentas* studentai, int kiekis);
void printStudentai(Studentas* studentai, int kiekis, bool isVid);
void nuskaitymas(int n, int m);
void skaiciavimas(int n, int m);
vector <Studentas> studentai;

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
void nuskaitymas(int n, int m){
    try
    {
        const char SF[] = "duom2.txt";

        ifstream sf(SF);
        string temp = "";
        sf >> temp;
        if (temp == "")
        {
            throw SF;
        }
        sf.ignore(100000, '\n');
        Studentas studentas;
        for (int i = 0; i < n; i++)
        {


            sf >> studentas.Vardas >> studentas.Pavarde;
            for (int j = 0; j < m; j++)
            {
                sf >> studentas.nd[j];

            }
            sf >> studentas.egz;
            studentai.push_back(studentas);
        }
        sf.ignore(100000, '\n');
    }
    catch (...)
    {

        cout << "Exception Caught \n";

    }
}

void skaiciavimas(int n, int m)
    {
    try
    {


  //  cout << "Output of begin and end: ";
    for(int i = 0; i<n; i++){
        Studentas studentas= studentai.at(i);
        int sum=0;
        for(int j=0; j<m; j++)
        {
            sum+=studentas.nd[j];
        }
        studentai[i].vidurkis=(double)sum/m;
        /////// mediana
        Sort(studentas.nd, m);

        if (m % 2 == 0)
        {
         //   cout << "namu darbu skaicius lyginis" << endl;
            studentai[i].mediana = (double)(studentas.nd[(m - 1) / 2] + studentas.nd[m / 2]) / 2.0;

        }

        else
        {
       //     cout << "namu darbu skaicius nelyginis" << endl;

            studentai[i].mediana = (double)studentas.nd[m / 2];
        };


      //  cout << studentai[i].vidurkis <<" "<<setprecision(3)<<studentai[i].mediana<< " ";
        }


    cout<<"Pavarde             Vardas                   Galutinis (Vid.)              Galutinis (Med.)"<<endl<<"--------------------------------------------------------------------------------------------------------"<<endl;

        for (int i = 0; i < studentai.size(); i++)
    {
        cout << studentai[i].Pavarde;
        for(int j=0; studentai[i].Pavarde.length()+j<20; j++)
        {
            cout<<" ";
        }
        cout<< studentai[i].Vardas;
        for(int j=0; studentai[i].Pavarde.length()+j<20; j++)
        {
            cout<<" ";
        }
        double galutinisvid=0.4*studentai[i].vidurkis+0.6*studentai[i].egz;
        printf("%*.2f", 10, galutinisvid);
        for(int j=0; j<20; j++)
        {

            cout<<" ";
        }
        double galutinismed=0.4*studentai[i].mediana+0.6*studentai[i].egz;
        printf("%*.2f", 10, galutinismed);
        cout<<endl;
    } } catch(int n ) {
      cout << "Exception Caught \n";
   }
    }

