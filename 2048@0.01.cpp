#include <iostream>
using namespace std;

int area[4][4];

void arr_to_0(int num[4])
{
    for(int i=0;i<4;i++) num[i]=0;
}
void move_up(int uper[4][4])
{
    for(int j=0;j<4;j++){

        int y[4];
        arr_to_0(y);
        int n=0;
        for(int i=0;i<4;i++){
            if(uper[j][i]!=0)
            {
                y[n]=uper[j][i];
                n++;
            }
        }

        for(int z=0;z<4;z++){
            if((y[z]==y[z+1])&&(y[z]!=0))
            {
                y[z]+=y[z+1];
                y[z+1]=0;
            }
        }

        for(int w=0;w<3;w++){
            if(y[w]==0)
            {
                y[w]=y[w+1];
                y[w+1]=0;
            }
        }

        for(int i=0;i<4;i++){
            uper[j][i]=y[i];
        }
    }
}
void move_down(int uper[4][4])
{

    for(int j=0;j<4;j++){

        int y[4];
        arr_to_0(y);
        int n=3;

        for(int i=3;i>-1;i--){
            if(uper[j][i]!=0){
                y[n]=uper[j][i];
                n--;
            }
        }

        for(int z=3;z>0;z--){
            if((y[z]==y[z-1])&&(y[z]!=0)){
                y[z]+=y[z-1];
                y[z-1]=0;
            }
        }

        for(int w=3;w>0;w--) {
            if(y[w]==0){
                y[w]=y[w-1];
                y[w-1]=0;
            }
        }

        for(int i=0;i<4;i++){
            uper[j][i]=y[i];
        }
    }
}
void move_left(int uper[4][4])
{
    for(int j=0;j<4;j++){

        int y[4];
        arr_to_0(y);
        int n=0;

        for(int i=0;i<4;i++){
            if(uper[i][j]!=0){
                y[n]=uper[i][j];
                n++;
            }
        }

        for(int z=0;z<4;z++){
            if((y[z]==y[z+1])&&(y[z]!=0)){
                y[z]+=y[z+1];
                y[z+1]=0;
            }
        }

        for(int w=0;w<3;w++){
            if(y[w]==0){
                y[w]=y[w+1];
                y[w+1]=0;
            }
        }

        for(int i=0;i<4;i++)uper[i][j]=y[i];
    }
}
void move_right(int uper[4][4])
{
    for(int j=0;j<4;j++){

        int y[4];
        arr_to_0(y);
        int n=3;

        for(int i=3;i>-1;i--){
            if(uper[i][j]!=0){
                y[n]=uper[i][j];
                n--;
            }
        }

        for(int z=3;z>0;z--){
            if((y[z]==y[z-1])&&(y[z]!=0)) {
                y[z]+=y[z-1];
                y[z-1]=0;
            }
        }

        for(int w=3;w>0;w--){
            if(y[w]==0){
                y[w]=y[w-1];
                y[w-1]=0;
            }
        }

        for(int i=0;i<4;i++)uper[i][j]=y[i];
    }
}
void fill()
{
    for(int j=0;j<4;j++){
        for(int i=0;i<4;i++){
            if(area[i][j]==0){
                cout<<"*"<<" ";
                continue;
            }
            cout<<area[i][j]<<" ";

        }
        cout<<"\n";
    }
    cout<<"\n";
}
void rand_fill()
{
    srand(time(NULL));
    for(int i =0; i <= rand()%100; i++) if(rand()%2 == 0) area[rand()%4][rand()%4]=2;
    for(int i =0; i <= rand()%100; i++)if(rand()%4 == 0) area[rand()%4][rand()%4]=4;
}
int main() {

    char key=' ';

    rand_fill();

    while(key!='q'){

        switch(key){
            case 'j':
                move_down(area);
                break;
            case 'k':
                move_up(area);
                break;
            case 'h':
                move_left(area);
                break;
            case 'l':
                move_right(area);
                break;

        }
        fill();
        cin >> key;
    }
    return 0;
}
