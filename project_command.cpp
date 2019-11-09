#include <iostream>
#include <string>

using namespace std;

string commands[5];

void execute();

void just_ls() { cout << "just ls" << endl; }
void not_just_ls() { cout << "not just ls" << endl; }
void cd(){};
void mv(){};

int main() {
    execute();
    return 0;
}

void execute() {
    while (1) {
        string temp;
        cout << "enter commands" << endl;
        getline(cin, temp);
        int k = 0;
        int index = 0;

        int n = temp.find(" ");
        if (n == string::npos) {
            commands[0] = temp;
        } else {
            while (n != string::npos) {
                commands[index] = temp.substr(k, n - k);
                k = n + 1;
                n = temp.find(" ", k);
                ++index;
                if (n == string::npos) {
                    commands[index] = temp.substr(k, temp.size() - k);
                    break;
                }
            }
        }

        if (commands[0] == "ls" && commands[1] == "") {
            just_ls();
        } else if (commands[0] == "ls" && commands[1] != "") {
            not_just_ls();
        } else if (commands[0] == "cd") {
            cd();
        } else if (commands[0] == "mv") {
            mv();
        } else if (commands[0] == "q") {
            break;
        }
    }
}
