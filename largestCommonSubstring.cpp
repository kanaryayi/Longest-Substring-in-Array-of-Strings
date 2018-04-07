// Find longest common subString in array of words
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

/*
###
Algo hold all substring possibilities in an map<string,bool> substrings as keys
Iterate all words in array and takes their all substrings.
Then, checks they are obtained before or not
*/
string convertLowerCase(string s){
  int i = s.size()-1;
  while(i>-1){
    if(!islower(s[i])){
      s[i] = tolower(s[i]);
    }
    i--;
  }
  return s;
}
int main ()
{
  string words[] = {"AnkAra","AnTalyA","ArdAhaN","KaraMan","BurSa","EdirNe"};
  map<string,bool> matchs;
  int sizeL = sizeof(words)/sizeof(string);
  string res = "";
  int sizeR = 0;
  string sub ="";
  // for all words in array
  for (int i = 0 ;i<sizeL;i++){
    //convert All word to lowercase
    words[i]=convertLowerCase(words[i]);
    string s = words[i];
    int n = s.length();
    //for every char in word
    for (int i = 0; i < n; i++){
        // for every char after specific char
        for (int len = 1; len <= n - i; len++){
          string sub = s.substr(i, len);
          cout << sub <<endl;
          // check existence of substring in map
          map<string,bool>:: iterator t = matchs.find(sub);
          if(t==matchs.end()){
            // not inside map
            matchs[sub] = false;
          }
          else{
            //inside map
            matchs[sub] = true;
            if(sizeR<sub.length()){
                // it is greater than old result so change it
                res = sub;
                sizeR = sub.length();
            }
          }
        }
     }
  }

  cout << endl <<res <<endl;

}
