#include<iostream>
#include<ctime>
#include<cstdlib>
#include<set>

using namespace std;

set<int> s;
int flag=0;

int RandomNumber(){
  cout<<"Please wait, computer is thinking.."<<endl;
  srand(time(0));
  return (rand()%10)+1;
}

void ShowBoard(char** arr){ //Function to show Updated Board
  cout<<arr[0][0]<<"|"<<arr[0][1]<<"|"<<arr[0][2]<<"\n"<<
  "------"<<"\n"
  <<arr[1][0]<<"|"<<arr[1][1]<<"|"<<arr[1][2]<<"\n"<<
  "------"<<"\n"
  <<arr[2][0]<<"|"<<arr[2][1]<<"|"<<arr[2][2]<<endl;
}

int PlayerChange(int f,int gametype){ //Changing Player for each turn
  if(gametype==1){
    if(f==0){
      return 1;
    }
    if(f==1){
      return 0;
    }
  }
  if(gametype==2){
    if(f==0){
      return 2;
    }
    if(f==2){
      return 0;
    }
  }
}

void UpdateBoard(char** arr,int option,char c){ //Updating Board with Player option
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

int Winner(char** arr){ //checking if game is over and someone won
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

void UpdateWithValidoption(char** arr,int player){ //checking valid option and calling the UpdateBoard function with respective player
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

    if (cin.get() == '\n') {//Pressing Enter makes the complete iteration
      flag=1;
    }
  }
  else if(player==1){
    cout<<"Player 2 please Enter a number: ";
    cin>>option;
    if(option>0&&option<10)
      UpdateBoard(arr,option,'O');
    else{
      cout<<"Please enter a valid option!"<<endl;
      UpdateWithValidoption(arr,player);
    }

    if (cin.get() == '\n') {//Pressing Enter makes the complete iteration
      flag=1;
    }
  }
  else if(player==2){
    option=RandomNumber();
    if(option>0&&option<10){
      if(s.find(option)!=s.end())
        UpdateWithValidoption(arr,player);
      else{
        UpdateBoard(arr,option,'O');
        flag=1;
      }
    }
    else{
      UpdateWithValidoption(arr,player);
    }
  }
}

int gamemode(){
  int gametype=0;
  cout<<"Do you want to play with.."<<endl;
  cout<<"1.Human"<<endl;
  cout<<"2.Computer"<<endl;
  cin>>gametype;
  if(gametype==1||gametype==2){
    return gametype;
  }
  else{
    gamemode();
  }
}

int main(){
  char** arr;int num=1;int gametype=0;

  gametype=gamemode();

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
  int player=0;
  do{
    system("cls");//refreshing the console (Updatingthe board)
    if(Winner(arr)==1){
      ShowBoard(arr);
      cout<<"Player 1 is the Winner!!";
      return 0;
    }
    else if(Winner(arr)==2){
      ShowBoard(arr);
      cout<<"Player 2 is the Winner!!";
      return 0;
    }
    else if(s.size()==9){
      ShowBoard(arr);
      cout<<"The Game is a DRAW!";
      return 0;
    }
    else{
      flag=0;
      ShowBoard(arr);

      UpdateWithValidoption(arr,player);

      player=PlayerChange(player,gametype);
    }
  }while(flag==1);
  return 0;
}
