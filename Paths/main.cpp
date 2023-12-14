//
//  main.cpp
//  Paths
//
//  Created by Michalis on 14.12.2023.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string path;
    cout<<"Введите путь к файлу: ";
    cin>>path;
    ifstream fin;
    fin.open(path);
    char symbolArr[50];
    int index=0;
    if (!fin.is_open()){
        cout<<"Error opening of file!"<<endl;
    }
    else{
        cout<<"File is open!"<<endl;
        char ch;
        while(fin.get(ch)){
            cout<<ch;
            if ((ch=='<')||(ch=='>')){
                symbolArr[index]=ch;
                index++;
            }
        }
    }
    fin.close();
    cout<<symbolArr;
    int count=0;
    if (symbolArr[0]=='>'){
        count++;
    }
    for (int i=0;i<index;i++){
        if (symbolArr[i] == '<' && (i == index - 1 || symbolArr[i + 1] != '>')) {
        count++;
    } else if (symbolArr[i] == '>' && (i == 0 || symbolArr[i - 1] != '<')) {
        count++;
    }
    }
    cout<<endl;
    cout<<"Errors: "<<count<<endl;
    
    
    
    
    
    
    return 0;
}

