#include <iostream>
using namespace std;
const int INF = 9999999;
const int m = 7; //number of cities
class dis{
    public:
        int d = INF;        //set every city Infinite distance to your_city
        int pre = INF;      //initially no previous city
};

int find_meetup_city(int *adj_matrix[m], int your_city, int friend_city){
    dis city[m];               //create m nodes have distance and previous city

    city[your_city].d = 0;    //set the start city as 0;
    for(int i=your_city; i<m; i++)
        for(int j=i+1; j<m; j++)
            if(adj_matrix[i][j]+city[i].d < city[j].d){     //add shortest so far with that city to the next
                city[j].d = adj_matrix[i][j]+city[i].d;     //change to the shortest
                city[j].pre = i;                            //and keep record of the previous city
            }
    for(int i=0; i<your_city; i++)
        for(int j=i+1; j<m; j++)                            //repeat the above process for the missed cities
            if(adj_matrix[i][j]+city[i].d < city[j].d){
                city[j].d = adj_matrix[i][j]+city[i].d;
                city[j].pre = i;
            }
    int dis_from_friend = 0;                //to calculate from the friend side
    int current_pos = friend_city;          //potential answer
    int half_dis = city[friend_city].d/2;   //half distance of the shortest distance
    while(dis_from_friend < half_dis){      //stop when dis has reached half_dis
        dis_from_friend = dis_from_friend + city[current_pos].d-city[city[current_pos].pre].d;
        if(dis_from_friend==half_dis)
            return city[current_pos].pre;
        else if (dis_from_friend<half_dis)
            current_pos = city[current_pos].pre;
    }

    if(city[current_pos].d - half_dis < half_dis-city[city[current_pos].pre].d)
        return current_pos;
    else
        return city[current_pos].pre;
}
int main(){
    int a[m] = {0, 1, 5, 4, 2, 8, 10};      // the matrix is symmetrical across the diagonal
    int b[m] = {1, 0, 1, 9, 7, 4, 3};
    int c[m] = {5, 1, 0, 1, 5, 6, 7};
    int d[m] = {4, 9, 1, 0, 1, 3, 4};
    int e[m] = {2, 7, 5, 1, 0, 1, 6};
    int f[m] = {8, 4, 6, 3, 1, 0, 1};
    int g[m] = {10, 3, 7, 4, 6, 1, 0};

    int *matrix[m] = {a, b, c, d, e, f, g};
    cout << find_meetup_city(matrix, 2, 4);
}
