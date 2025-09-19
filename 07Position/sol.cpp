#include <stdint.h>
#include <string>
#include <iostream>

using namespace std;

bool check(string name)
{
    int v40, v48, v42, v44, v46, v32, v38, v34, v8, v36, v41, v49, v43, v45, v47, v33, v39, v35, v21, v37, buffer = 0;

    v40 = (name[0] & 1) + 5;
    v48 = ((name[0] & 0x10) != 0) + 5;
    v42 = ((name[0] & 2) != 0) + 5;
    v44 = ((name[0] & 4) != 0) + 5;
    v46 = ((name[0] & 8) != 0) + 5;

    v32 = (name[1] & 1) + 1;
    v38 = ((name[1] & 0x10) != 0) + 1;
    v34 = ((name[1] & 2) != 0) + 1;
    v8 = ((name[1] & 4) != 0) + 1;
    v36 = ((name[1] & 8) != 0) + 1;

    buffer += ((v40 + v8) == 7);
    buffer += ((v46 + v36) == 6);
    buffer += ((v42 + v38) == 8);
    buffer += ((v44 + v32) == 7);
    buffer += ((v48 + v34) == 6);

    v41 = (name[2] & 1) + 5;
    v49 = ((name[2] & 0x10) != 0) + 5;
    v43 = ((name[2] & 2) != 0) + 5;
    v45 = ((name[2] & 4) != 0) + 5;
    v47 = ((name[2] & 8) != 0) + 5;

    v33 = (name[3] & 1) + 1;
    v39 = ((name[3] & 0x10) != 0) + 1;
    v35 = ((name[3] & 2) != 0) + 1;
    v21 = ((name[3] & 4) != 0) + 1;
    v37 = ((name[3] & 8) != 0) + 1;

    buffer += ((v41 + v21) == 7);
    buffer += ((v47 + v37) == 7);
    buffer += ((v43 + v39) == 7);
    buffer += ((v45 + v33) == 7);
    buffer += ((v49 + v35) == 6);

    return buffer == 10;
}

void brutePass(string name,int length,string set){
    if (name.size()==length) return;
    for (auto c:set){
        string temp = name+ c;
        if (check(temp) && temp[3]=='p'){
            cout<<temp<<endl;
            break;
        }
        brutePass(temp,length,set);
    }
}

int main(){
    string set = "abcdefghijklmnopqrstuvwxyz";
    brutePass("",4,set);
    return 0;
}