#include <iostream>
using namespace std;

class Residence{
    private:
        int population;
        int minimumAge;
        int maximumAge;
        string gender;
        int zipCode;
        string geo_id;
    public:
        Residence();
        Residence(int pop, int minAge, int maxAge, string Gender, int zipCode, string Geo_id);
        void PrintVal();
        int GetPopulation();
        int GetMinAge();
        int GetMaxAge();
        string GetGender();
        int GetZipCode();
        // Comparison(Residence tmp1, Residence tmp2);
        string GetGeoID();
        // void SetPopulation(int population);
};

Residence::Residence(){

}

Residence::Residence(int pop, int minAge, int maxAge, string Gender, int ZipCode, string Geo_id){
    population = pop;
    minimumAge = minAge;
    maximumAge = maxAge;
    gender = Gender;
    zipCode = ZipCode;
    geo_id = Geo_id;
}

int Residence::GetPopulation(){
    return population;
}
string Residence::GetGeoID(){
    return geo_id;
}
int Residence::GetMinAge(){
    return minimumAge;
}
int Residence::GetMaxAge(){
    return maximumAge;
}
string Residence::GetGender(){
    return gender;
}
int Residence::GetZipCode(){
    return zipCode;
}
void Residence::PrintVal(){
    cout << population << " , " << minimumAge << " , " << maximumAge << " , " << gender << " , " << zipCode << " , " << geo_id << endl;
}

// int Residence::Comparison(Residence tmp1, Residence tmp2){
//     // cout <<'H' << endl;
//     int a = tmp1.GetPopulation();
//     int b = tmp2.GetPopulation();
//     if(a < b){
//         return -1;
//     }else if(a == b){
//         string id1 = tmp1.GetGeoID();
//         string id2 = tmp2.GetGeoID();
//         if(id1==id2){
//             return -1;
//         }else if(id1<id2){
//             return -1;
//         }else{
//             return 1;
//         }
//     }else{
//         return 1;
//     }
// }



// void Residence::SetPopulation(int population){
//     this.population = population;
// }