#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct river {
    char name[40];
    int length;
    int drainage_area;
};

int cmpar (const void* a, const void* b){
    const struct river *i = (const struct river*) a;
    const struct river *j = (const struct river*) b;
    if(i->length<j->length){
        return -1;
    }else if(i->length==j->length){
        return 0;
    }else{
        return 1;
    }

}
int main(){
    struct river *list = (struct river*)malloc(sizeof(struct river)*30);
    FILE *a = fopen("data.txt", "r");
    FILE *b = fopen("output.txt", "w");
    char name[40];
    int length, drainage_area;
    struct river temp;
    int i=0;
    while(fscanf(a, "%s", &name)!=EOF){
        fscanf(a, "%d\n%d", &length, &drainage_area);
        strcpy(list[i].name, name);
        list[i].length = length;
        list[i].drainage_area = drainage_area;
      //  list[i] = temp;
        i++;
    }
      //  fprintf(b, "%s %d %d", list[i].name, list[i].length, list[i].drainage_area);

  //  int (*p)(const void *, const void *);
  //  p = cmpar;
    qsort(list, i, sizeof(struct river), cmpar);
    int k=0;
    while(k<i){
        fprintf(b, "%s %d %d\n", list[k].name, list[k].length, list[k].drainage_area);
        k++;
    }
}
