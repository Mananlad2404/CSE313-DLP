#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

// Function to process the input string and check if it's accepted by the DFA
bool isAcceptedByDFA(int initialState, const vector<int>& acceptingStates,
                     const unordered_map<int, unordered_map<char, int>>& transitionTable,
                     const string& inputString) {
    int currentState = initialState;

    for (char symbol : inputString) {
        if (transitionTable.at(currentState).find(symbol) == transitionTable.at(currentState).end()) {
            return false; // Invalid transition
        }
        currentState = transitionTable.at(currentState).at(symbol);
    }

    // Check if the final state is an accepting state
    for (int state : acceptingStates) {
        if (currentState == state) {
            return true;
        }
    }

    return false;
}

int main() {
    int numInputSymbols;
    cout << "Enter number of input symbols: ";
    cin >> numInputSymbols;

    vector<char> inputSymbols(numInputSymbols);
    cout << "Enter input symbols: ";
    for (int i = 0; i < numInputSymbols; i++) {
        cin >> inputSymbols[i];
    }

    int numStates;
    cout << "Enter number of states: ";
    cin >> numStates;

    int initialState;
    cout << "Enter initial state: ";
    cin >> initialState;

    int numAcceptingStates;
    cout << "Enter number of accepting states: ";
    cin >> numAcceptingStates;

    vector<int> acceptingStates(numAcceptingStates);
    cout << "Enter accepting states: ";
    for (int i = 0; i < numAcceptingStates; i++) {
        cin >> acceptingStates[i];
    }

    unordered_map<int, unordered_map<char, int>> transitionTable;
    cout << "Enter transition table in the format: state input_symbol next_state (e.g., 1 a 2):" << endl;
    for (int i = 0; i < numStates * numInputSymbols; i++) {
        int currentState, nextState;
        char symbol;
        cin >> currentState >> symbol >> nextState;
        transitionTable[currentState][symbol] = nextState;
    }

    string inputString;
    cout << "Enter the input string: ";
    cin >> inputString;

    if (isAcceptedByDFA(initialState, acceptingStates, transitionTable, inputString)) {
        cout << "The input string is ACCEPTED by the DFA." << endl;
    } else {
        cout << "The input string is REJECTED by the DFA." << endl;
    }

    return 0;
}
