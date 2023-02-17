#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string> &names,vector<int> &scores,vector<char> &grades){
 ifstream ns(filename.c_str());
 string s;
 while (getline(ns,s))
 {
   char format[] = "%[^:]: %d %d %d";
   int a,b,c;
   char u[50];
   sscanf(s.c_str(),format,u,&a,&b,&c);
   names.push_back(u);
   scores.push_back(a+b+c);
   grades.push_back(score2grade(a+b+c));

 }
 
}

void getCommand(string &command,string &key){
cout << "Please input your command: ";
string o;
getline(cin,o);
char format[] = "%s %[^:]";
char m[50];
char l[50];
sscanf(o.c_str(),format,l,m);
key = m;
command = l;


}

void searchName(vector<string> names,vector<int> scores,vector<char> grades,string key){
bool as = false;
for (int i = 0; i < names.size(); i++)
{
    if (toUpperStr(key)==toUpperStr(names[i]))
    {
        cout << "---------------------------------"<<endl;
        cout << names[i] << "'s score = " << scores[i] <<endl;
        cout << names[i] << "'s grade = " << grades[i] <<endl;
        cout << "---------------------------------"<<endl;
        as = true;
    }
   
}
   if (!as)
   {
     cout << "---------------------------------"<<endl;
     cout << "Cannot found."<<endl;
     cout << "---------------------------------"<<endl;

   }
   
}

void searchGrade(vector<string> names,vector<int> scores,vector<char> grades,string key){
bool as = false;
  cout << "---------------------------------"<<endl;
for (int i = 0; i < grades.size(); i++)
{
    string g(1,grades[i]);
    if (toUpperStr(key)==toUpperStr(g))
    {
        
        cout << names[i] << " (" << scores[i] << ")" <<endl;
        
        as = true;
    }
   
}
   if (!as)
   {
     
     cout << "Cannot found."<<endl;
    

   }
     cout << "---------------------------------"<<endl;
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
