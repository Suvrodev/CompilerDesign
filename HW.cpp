#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

string RemoveDoubleSlashComment(string Text){

    int count=0;
    bool CheckQuot;

    for(int i=0;i<Text.length();i++){       //something right
        if(Text[i]=='"'){
            count++;
            continue;
        }
        
        if(count==0 || count%2==0){
        if(Text[i]=='/' && Text[i+1]=='/'){
             Text= Text.substr(0, i-1);
             break;
        }
        }
    }
    return Text;
}

int main(){
    string Text_="";
    string NewString="";
    string WithoutSpace="";


    ifstream MyReadFile("D:\\xyz.txt");

    while (getline(MyReadFile,Text_))
    {
        string Text= RemoveDoubleSlashComment(Text_);
        cout<<Text<<endl;
        NewString+=Text;
        Text="";
    }
    MyReadFile.close();

    cout<<"\nNew String in One Line: "<<NewString<<endl;

    //Remove Space between two words
    NewString.erase(remove(NewString.begin(), NewString.end(), ' '), NewString.end());
    cout<<"\nNew String without space: \n"<<NewString<<endl;

    //Remove /* */ Comment 
    int Check=0;
    int x_count=0;
    for(int i=0; NewString[i]!='\0'; i++) {
         if(NewString[i]=='"'){
            Check++;
            continue;
        }
        
        if(Check==0 || Check%2==0){
            if(NewString[i]=='/' && NewString[i+1]=='*'){
                for(int j=i+2;NewString[j]!='\0';j++){
                    x_count++;
                    if(NewString[j]=='*' && NewString[j+1]=='/'){
                         NewString.erase(i,x_count+3);
                         x_count=0;
                         break;
                     }
               }
           }
        }
     }

    cout<<"\nWithout /* */ Comment: \n"<<NewString<<endl;

    

    return 0;
    
}