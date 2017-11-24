//    g++ main.cpp -o main.exe
//    ./main.exe input_size


#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <time.h>

#include "Residence.h"

using namespace std;

void printArray(vector<Residence> resList);
bool Comparison(Residence tmp1, Residence tmp2);
int partition(vector<Residence>& A, int low,int high);
void quickSort(vector<Residence>& A, int low,int high);
void exportExcel(vector<Residence> resList);

ofstream MyExcelFile;


int main(int argc, char *argv[] ){
    // MyExcelFile.open("test.csv");
    ifstream myfile("population_by_zip_2010.csv");
	stringstream userInput(argv[1]);
	int inputSize = 0;
	userInput >> inputSize;
    string line;
    vector<Residence> residenceList;
    clock_t t;


    
    // MyExcelFile << "population,minimum_age,maximum_age,gender,zipcode,geo_id" << endl;
	//  Residence hey(13,42,1,"M",34060,"asdadasd");
	//  hey.PrintVal();

	 if(myfile.is_open()){
        getline(myfile, line); //Just for the ignoring first line
		for(int i=0; i<inputSize; ++i){
            getline(myfile, line);

			unsigned pos = line.find(",");
			int population = atof(line.substr(0,pos).c_str());
			line = line.substr(pos+1);
			pos = line.find(",");
			int minAge = atof(line.substr(0,pos).c_str());
			line = line.substr(pos+1);
            pos = line.find(",");
			int maxAge = atof(line.substr(0,pos).c_str());
			line = line.substr(pos+1);
            pos = line.find(",");
            string gender = line.substr(0,pos);
            line = line.substr(pos+1);
            pos = line.find(",");
            int zipCode = atof(line.substr(0,pos).c_str());
            line = line.substr(pos+1);
            pos = line.find(",");
            string Geo_ID = line.substr(0,pos);

            //Create an Residence object with the data in .csv file.
            Residence tmp(population,minAge,maxAge,gender,zipCode,Geo_ID);
            // tmp.PrintVal();
            residenceList.push_back(tmp);
		}
        // cout << residenceList[1].Comparison(residenceList[2]) << endl;
        t = clock();
        quickSort(residenceList,0,inputSize-1);
        t = clock() - t;
        // exportExcel(residenceList);
    }
    printArray(residenceList);
    printf ("It took (%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
    
    return 0;
}

void exportExcel(vector<Residence> resList){
    for(int i=0; i<resList.size(); ++i){
        MyExcelFile << resList[i].GetPopulation() << ',' <<
        resList[i].GetMinAge() << ',' <<
        resList[i].GetMaxAge() << ',' <<
        resList[i].GetGender() << ',' <<
        resList[i].GetZipCode() << ','<<
        resList[i].GetGeoID() << endl;
    }
}

void printArray(vector<Residence> resList){
    for (int i=0; i < resList.size(); i++){
        resList[i].PrintVal();
    }
}


int partition(vector<Residence>& A, int low,int high){
    Residence x = A[high];
    int i=low-1;
    int j;
    
    for(j=low; j<=high-1; j++){
        // If GeoIDs are the same do nothing!! Means that previous element will be first.
        if(A[j].GetPopulation() == x.GetPopulation() && A[j].GetGeoID() == x.GetGeoID()){
            break;
        }
       
        // int a = A[j].GetPopulation();
        // int b = x.GetPopulation();
        
            if(Comparison(A[j],x)){
                i++;
                swap(A[i],A[j]);
            }
    }
    swap(A[i+1],A[high]);
    return i+1;
}

void quickSort(vector<Residence>& A, int low,int high){
    if(low<high)
    {
        int r=partition(A, low,high);
        quickSort(A,low,r-1);  
        quickSort(A,r+1,high);
    }
}

bool Comparison(Residence tmp1, Residence tmp2){
    // cout <<'H' << endl;
    int a = tmp1.GetPopulation();
    int b = tmp2.GetPopulation();
    if(a < b){
        return true;
    }else if(a == b){
        string id1 = tmp1.GetGeoID();
        string id2 = tmp2.GetGeoID();
        if(id1==id2){
            return true;
        }else if(id1<id2){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}


