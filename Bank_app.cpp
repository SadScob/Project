#include <iostream>
#include <string>
#include <vector>

using namespace std;

auto CheckUser() -> void {
    string name;
    string pass;
    string checkPass;
    cout << "Welcome to the PJATKBank!\n\n" << "Sing up. Type your username:\n\n";
    cin >> name;
    cout << endl << endl;
    cout << name << ", Type your password (minimum 6 symbols):\n\n";
    cin >> pass;
    cout << endl << endl;

    while (pass.size() < 6) {
        cout << "Password must have minimum 6 symbols!\n\nTry again: \n\n";
        cin >> pass;
        cout << endl << endl;
    }
    do {
        cout << name << ", please repeat password: \n\n";
        cin >> checkPass;
        cout << endl << endl;
    } while (checkPass != pass);
    cout << "\n\nWelcome, " << name << "!\n\n";
}

auto main(int argc, char *argv[]) -> int {
    CheckUser();
    vector<float> history;
    float stat = 1000;
    int Choice;
    do {
        cout << "1. Account status\t" << "2. Deposit\t" << "3. Withdraw funds\t" << "4. History \t" << "5. Sing out\n";

        cin >> Choice;
        switch (Choice) {
            case 1:

                cout << "\n\nYour balance is: " << stat << "$.\n\n";

            case 2:

                float deposit;
                cout << "\nType an amount:\n\n";
                cin >> deposit;
                stat += deposit;
                cout << "\n\nThanks for payment, your balance is: " << stat << "$ now.\n\n";
                history.push_back(deposit);
                break;
            case 3:
                float amount;
                cout << "\nType an amount: \n";
                cin >> amount;
                stat -= amount;
                cout << "\n\nTake your money, your balance is: " << stat << "$ now.\n\n";
                history.push_back(amount * -1);
                break;
            case 4:
                if (history.empty()) {
                    cout << "\nHistory is empty!\n\n";
                    break;
                } else {
                    cout << "\nBalance: " << stat << "$" << endl << endl;
                    cout << "History of operations: \n\n";
                    for (float i = history.size() - 1; i >= 0; --i) {
                        cout << history[i] << "$\n\n";
                    }
                    break;
                }


            case 5:
                cout << "\nBye!" << endl;
                return 0;

        }
    } while (Choice != 5);


}


