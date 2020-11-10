#include <iostream>
using namespace std;
const int MAX = 1000;

int c, t, a, n;
int oxygen[MAX], nitrogen[MAX], weight[MAX];
int cylinder[MAX][22][80];

int program(int pos, int co, int cn){
    if(cylinder[pos][co][cn]!=-1){
		return cylinder[pos][co][cn];
	}
	if(co==0&&cn==0){
		cylinder[pos][co][cn]= 0;
	}
	else if(pos==0){
		cylinder[pos][co][cn]= 10000;
	 }else{
		cylinder[pos][co][cn]=min(program(pos-1,co,cn),program(pos-1,max(co-oxygen[pos-1],0),max(cn-nitrogen[pos-1],0))+weight[pos-1]);
	}
	return cylinder[pos][co][cn];
}

int main(){

    cout << "number of test cases: ";
    cin >> c;

    for(int i=0; i<c; i++){
        cout << "oxygen and nitrogen need for the task: ";
        cin >> t >> a;
        cout << "number of accessible cylinders: ";
        cin >> n;

        for(int j=0; j<n+1; j++)
            for(int k=0; k<t+1; k++)
                for(int ii=0; ii<a+1; ii++)
                    cylinder[j][k][ii] = -1;

        cout << "enter " << n << " times of oxygen, nitrogen, and weight of a cylinder: " << endl;
        for(int j=0; j<n; j++)
            cin >> oxygen[j] >> nitrogen[j] >> weight[j];

        cout << program(n, t, a);
    }
    return 0;
}
