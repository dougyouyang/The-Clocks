//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define MAXS (1<<18)
bool visited[MAXS];

struct clocks{
    int conf[9];
    vector<int> steps;
};
typedef struct clocks stc;
queue<stc> q;

void print(stc clock)
{
    for(int i=0;i<clock.steps.size()-1;i++){
        cout << clock.steps[i] << " ";
    }
    cout << clock.steps[clock.steps.size()-1] << endl;
}

int isgood(stc clock)
{
    int i;
    for(i=0;i<9;i++)
        if(clock.conf[i])
            return 0;
    return 1;
}

int index(stc clock)
{
    int i, base=1, r=0;
    
    for(i=0;i<9;i++){
        r+=base*clock.conf[i];
        base*=4;
    }
    return r;
}

void f(int cn, stc &clock)
{
    switch(cn){
    case 1:
        clock.conf[0]=(clock.conf[0]+1) % 4;
        clock.conf[1]=(clock.conf[1]+1) % 4;
        clock.conf[3]=(clock.conf[3]+1) % 4;
        clock.conf[4]=(clock.conf[4]+1) % 4;
        break;
    case 2:
        clock.conf[0]=(clock.conf[0]+1) % 4;
        clock.conf[1]=(clock.conf[1]+1) % 4;
        clock.conf[2]=(clock.conf[2]+1) % 4;
        break;
    case 3:
        clock.conf[1]=(clock.conf[1]+1) % 4;
        clock.conf[2]=(clock.conf[2]+1) % 4;
        clock.conf[4]=(clock.conf[4]+1) % 4;
        clock.conf[5]=(clock.conf[5]+1) % 4;
        break;
    case 4:
        clock.conf[0]=(clock.conf[0]+1) % 4;
        clock.conf[6]=(clock.conf[6]+1) % 4;
        clock.conf[3]=(clock.conf[3]+1) % 4;
        break;
    case 5:
        clock.conf[7]=(clock.conf[7]+1) % 4;
        clock.conf[1]=(clock.conf[1]+1) % 4;
        clock.conf[3]=(clock.conf[3]+1) % 4;
        clock.conf[4]=(clock.conf[4]+1) % 4;
        clock.conf[5]=(clock.conf[5]+1) % 4;
        break;
    case 6:
        clock.conf[2]=(clock.conf[2]+1) % 4;
        clock.conf[5]=(clock.conf[5]+1) % 4;
        clock.conf[8]=(clock.conf[8]+1) % 4;
        break;
    case 7:
        clock.conf[7]=(clock.conf[7]+1) % 4;
        clock.conf[6]=(clock.conf[6]+1) % 4;
        clock.conf[3]=(clock.conf[3]+1) % 4;
        clock.conf[4]=(clock.conf[4]+1) % 4;
        break;
    case 8:
        clock.conf[6]=(clock.conf[6]+1) % 4;
        clock.conf[7]=(clock.conf[7]+1) % 4;
        clock.conf[8]=(clock.conf[8]+1) % 4;
        break;
    case 9:
        clock.conf[5]=(clock.conf[5]+1) % 4;
        clock.conf[7]=(clock.conf[7]+1) % 4;
        clock.conf[8]=(clock.conf[8]+1) % 4;
        clock.conf[4]=(clock.conf[4]+1) % 4;
        break;
    }
}

int main()
{
    int i, idx;
    stc clk, clk2;
    
    for(i=0;i<9;i++){
        cin >> clk.conf[i];
        clk.conf[i]=(clk.conf[i]/3)%4;
    }
    idx=index(clk);
    visited[idx]=true;
    if(isgood(clk)){
        print(clk);
        return 0;
    }
    
    q.push(clk);
    while(!q.empty()){
        clk=q.front();
        q.pop();
        for(i=1;i<=9;i++){
            clk2=clk;
            f(i, clk2);
            idx=index(clk2);
            if(visited[idx])
               continue;
            else
                visited[idx] = true;
            if(isgood(clk2)){
                clk2.steps.push_back(i);
                print(clk2);
                return 0;
            }
            clk2.steps.push_back(i);
            q.push(clk2);
        }
    }
    
    return 0;
}
