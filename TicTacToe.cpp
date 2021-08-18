#include<iostream>
#include<set>

using namespace std;

set<int> s;

void ShowBoard(char** arr){
  cout<<arr[0][0]<<"|"<<arr[0][1]<<"|"<<arr[0][2]<<"\n"<<
  "------"<<"\n"
  <<arr[1][0]<<"|"<<arr[1][1]<<"|"<<arr[1][2]<<"\n"<<
  "------"<<"\n"
  <<arr[2][0]<<"|"<<arr[2][1]<<"|"<<arr[2][2]<<endl;
}

int PlayerChange(int flag){
  if(flag==0){
    return 1;
  }
  if(flag==1){
    return 0;
  }
}

void UpdateBoard(char** arr,int option,char c){
  if(s.find(option)!=s.end()){
    cout<<"Please Enter a new number: ";
    cin>>option;
    UpdateBoard(arr,option,c);
  }
  else{
    s.insert(option);
    switch(option){
      case 1:
        arr[0][0]=c;
        break;
      case 2:
        arr[0][1]=c;
        break;
      case 3:
        arr[0][2]=c;
        break;
      case 4:
        arr[1][0]=c;
        break;
      case 5:
        arr[1][1]=c;
        break;
      case 6:
        arr[1][2]=c;
        break;
      case 7:
        arr[2][0]=c;
        break;
      case 8:
        arr[2][1]=c;
        break;
      case 9:
        arr[2][2]=c;
        break;
      }
    }
}

int Winner(char** arr){
  if(arr[0][0]=='X'&&arr[0][1]=='X'&&arr[0][2]=='X'||
arr[1][0]=='X'&&arr[1][1]=='X'&&arr[1][2]=='X'||
arr[2][0]=='X'&&arr[2][1]=='X'&&arr[2][2]=='X'||
arr[0][0]=='X'&&arr[1][0]=='X'&&arr[2][0]=='X'||
arr[0][1]=='X'&&arr[1][1]=='X'&&arr[2][1]=='X'||
arr[0][2]=='X'&&arr[1][2]=='X'&&arr[2][2]=='X'||
arr[0][0]=='X'&&arr[1][1]=='X'&&arr[2][2]=='X'||
arr[0][2]=='X'&&arr[1][1]=='X'&&arr[2][0]=='X')
    return 1;
  else if(arr[0][0]=='O'&&arr[0][1]=='O'&&arr[0][2]=='O'||
arr[1][0]=='O'&&arr[1][1]=='O'&&arr[1][2]=='O'||
arr[2][0]=='O'&&arr[2][1]=='O'&&arr[2][2]=='O'||
arr[0][0]=='O'&&arr[1][0]=='O'&&arr[2][0]=='O'||
arr[0][1]=='O'&&arr[1][1]=='O'&&arr[2][1]=='O'||
arr[0][2]=='O'&&arr[1][2]=='O'&&arr[2][2]=='O'||
arr[0][0]=='O'&&arr[1][1]=='O'&&arr[2][2]=='O'||
arr[0][2]=='O'&&arr[1][1]=='O'&&arr[2][0]=='O')
    return 2;
  else
    return 0;
}

void UpdateWithValidoption(char** arr,int player){
  int option;
  if(player==0){
    cout<<"Player 1 please Enter a number: ";
    cin>>option;
    if(option>0&&option<10)
      UpdateBoard(arr,option,'X');
    else{
      cout<<"Please enter a valid option!"<<endl;
      UpdateWithValidoption(arr,player);
    }
  }
  else{
    cout<<"Player 2 please Enter a number: ";
    cin>>option;
    if(option>0&&option<10)
      UpdateBoard(arr,option,'O');
    else{
      cout<<"Please enter a valid option!"<<endl;
      UpdateWithValidoption(arr,player);
    }
  }
}

int main(){
  char** arr;int num=1;

  /*Passing numbers as a char to the 2D array*/
  arr=new char*[3];
  for(int i = 0; i <3; i++)
    arr[i] = new char[3];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      arr[i][j]='0'+num;
      num++;
    }
  }

  /*Game Loop*/
  int flag=0,player=0;
  do{
    system("cls");//refreshing the console (Updatingthe board)
    if(Winner(arr)==1){
      cout<<"Player 1 is the Winner!!";
      return 0;
    }
    else if(Winner(arr)==2){
      cout<<"Player 2 is the Winner!!";
      return 0;
    }
    else{
      flag=0;
      ShowBoard(arr);

      UpdateWithValidoption(arr,player);

      if (cin.get() == '\n') {//Pressing Enter makes the complete iteration
        flag=1;
      }
      player=PlayerChange(player);
    }
  }while(flag==1);

  return 0;
}
