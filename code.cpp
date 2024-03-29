#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector <string> chop(vector <string> source, float start,float stop);

char cryptid(vector<string> intake);


int main(){
    int size = 0;
    string filename;
    cout << "Enter File Name:\n";
    cin >> filename;
    ifstream file;
    file.open(filename);
    if(file){
        cout << "Success!\n";
    }
    else{
        cout << "Failed!\n";
    }
    cout << "How long would you like your password?\n "; cin >> size;

    vector <string> Data;
    vector<vector <string>> data;

    for(int i = 0; i<size;i++){
        data.push_back(Data);
    }

    string garbo;
    string garb;
    while(file >> garbo){
        Data.push_back(garbo);
    }
    cout << Data.size() << endl;
    file.close();
    for(float i = 0.0; i<size;i++){
        data[i] = chop(Data,(i)/size,(i+1)/size);
    }

    string pass = "";
    for(int i = 0; i<size;i++){
        pass+=cryptid(data[i]);
    }
    cout << pass << endl;
    cout << "Enter Y to Exit\n";
    cin >> size;
    return 0;
}

vector <string> chop(vector <string> source,float start,float stop){
    vector <string> target;
    for(int i = (int)(source.size()*start);i<(int)source.size()*stop;i++){
        target.push_back(source[i]);
    }
    return target;
}

char cryptid(vector<string> intake){
    long int tot = 0;
    for(int i =0;i<(int)intake.size();i++){
        for(int j=0;j<(int)intake[i].size();j++)
            tot += (unsigned int)intake[i][j];

    }

    return (char)(tot%(126-48)+48);
}
