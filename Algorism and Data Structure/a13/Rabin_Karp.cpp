#include <iostream>
using namespace std;
void algorithm(string text, string pattern, int d, int q){
    int n = text.length();
    int m = pattern.length();
    int h = 1;
    int p = 0;  //hash value for pattern
    int t = 0;  //hash value for text

    for(int i=0; i<m-1; i++)
        h = (h*d)%q;
    for(int i=0; i<m; i++){
        p = (d*p + pattern[i]) % q;     //hash value of pattern
        t = (d*t + text[i]) % q;        //first part of text
    }
    for(int i=0; i<=n-m; i++){
        int j;
        if(p==t){
            for(j=0; j<m; j++){
                if(pattern[j]!=text[i+j])   //verify whether the found substring is the pattern
                    break;
            }
            if(j==m){
                cout << "Pattern occurs at index " << i << endl;
            }
        }
        if(i<n-m){
            t = (d*(t-text[i]*h)+text[i+m])%q; // remove the high-order and add low-order character
            if(t<0)          //avoid t is negative
                t +=q;
        }
    }
}
int main(){
    string pattern = "app";
    string text = "this is an app";
    algorithm(text, pattern, 256, 101); //ASCII so 256, 101 is a big prime number
    return 0;
}
