#include <iostream>
using namespace std;

void WordSort(string* S, int lower, int upper, int i){
    int n=upper-lower+1;
    int temp[26] = {0};
    string s[n];
    int num;

    int temp2[26];
    int Fornull = 0;
    for(int j=lower; j<=upper; j++){
        if(S[j][i]<=122 && S[j][i]>=97){
            num = S[j][i]-97;
            temp[num]++;
        }else{
            s[Fornull] = S[j];
            Fornull++;
        }
    }
    for(int j=0; j<26; j++){
        temp2[j] = temp[j];
    }

    for(int j=1; j<26; j++){
        temp[j] +=temp[j-1];
    }

    for(int j=upper; j>=lower;j--){
        num = S[j][i]-97;
        if(Fornull!=0){
            if(num<0 || num>26){
            }else{
            s[temp[num]-1+Fornull] = S[j];
            }
        }else{
        s[temp[num]-1] = S[j];
        }
        temp[num]--;
    }

    for(int j=lower, k=0; j<=upper; j++, k++){
        S[j] = s[k];
    }
    for(int k=0; k<26; k++)
        cout << temp2[k]<<' ';
    cout << endl;
    int index = lower-1;
    for(int j=0; j<26; j++){
        index +=temp2[j];
        if(temp2[j]!=0 && temp2[j]!=1){
            WordSort(S, index-temp2[j]+1, index, i+1);
        }
    }

}
void print(string arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] <<' ';
    }
    cout << endl;
}

int main(){

    string sequence[10] = {"word", "category", "cat", "new", "news", "world", "bear", "at", "work", "time"};

    int n = sizeof(sequence)/sizeof(sequence[0]);

    WordSort(sequence, 0, n-1, 0);
    print(sequence, n);

    return 0;
}
