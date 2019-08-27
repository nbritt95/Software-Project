#include <iostream>
#include<string>

using namespace std;

int main()
{
    int dfa[5][2] = {{3,2},{2,4},{5,3},{2,4},{5,3}};
    
    char w[25];
   
    cout<<"Enter a string: \n";
    cin>>w;
   
    int InitialState, AcceptingState1, AcceptingState2, StartingState;
    
    StartingState = 0;
    AcceptingState1 = 4;
    AcceptingState2 = 5;

    InitialState = StartingState;
    
    int i =0;
    
    while (i<strlen(w))
    {
        InitialState = dfa[InitialState][(w[i] - '0')];
        cout<<"State: "<<InitialState<<" SymbolToProcess: "<<w[i] - '0';
        InitialState--;
        cout<< endl;
        i++;
    }
    InitialState = InitialState+1;
    cout<<endl<<endl<<endl<<InitialState<<endl<<endl<<endl;
    
    switch (InitialState) {
        case 4 :
            cout<< w << " is accepted"<<endl;
            break;
        case 5 :
            cout<< w << " is accepted"<<endl;
            break;
        default:
            cout<< w << " is rejected."<<endl;
            break;
    }
   
    return 0;
    
}
