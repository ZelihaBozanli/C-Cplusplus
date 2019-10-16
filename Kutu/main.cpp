#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

class space{
    public:
        class Box{
            public:
            class coord{
                public:
                double x;
                double X[3];
                double y;
                double Y[3];

            }koord;
        double density;
        double width;
        double height;

        }kutular[10];
};


int rastgele(){

return rand()%3+1;
}
int rastgele2(){


return rand()%5+1;
}


int main(){

space s;
for(int i=0;i<10;i++){
s.kutular[i].koord.x =rastgele();
s.kutular[i].koord.y =rastgele2();

s.kutular[i].height=rastgele();
s.kutular[i].width=rastgele2();
}


for(int i=0;i<10;i++){
s.kutular[i].koord.X[0]=s.kutular[i].koord.x;
s.kutular[i].koord.Y[0]=s.kutular[i].koord.y;

s.kutular[i].koord.X[1]=s.kutular[i].koord.x;
s.kutular[i].koord.Y[1]=s.kutular[i].koord.y+s.kutular[i].height;

s.kutular[i].koord.X[2]=s.kutular[i].koord.x+s.kutular[i].width;
s.kutular[i].koord.Y[2]=s.kutular[i].koord.y;

s.kutular[i].koord.X[3]=s.kutular[i].koord.X[2];
s.kutular[i].koord.Y[3]=s.kutular[i].koord.Y[1];
}
for(int i=0;i<10;i++){
        cout<<i+1<<". kutu koordinatlari"<<endl;
        cout<<"A("<<s.kutular[i].koord.X[0]<<","<<s.kutular[i].koord.Y[0]<<") -";
        cout<<"B("<<s.kutular[i].koord.X[1]<<","<<s.kutular[i].koord.Y[1]<<") -";
        cout<<"C("<<s.kutular[i].koord.X[2]<<" "<<s.kutular[i].koord.Y[2]<<") -";
        cout<<"D("<<s.kutular[i].koord.X[3]<<" "<<s.kutular[i].koord.Y[3]<<")"<<endl;

}

cout<<rastgele()<<" "<<rastgele();

/*cout<<s.kutular[0].koord.Y[0]<<endl;
cout<<s.kutular[0].koord.Y[1]<<endl;
cout<<s.kutular[0].height;*/








}
