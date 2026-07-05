#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to evaluate a propositional logic expression
bool evaluateExpression(const vector<bool>& values, const string& operation) {
    if (operation == "conjunction") {
        for (bool value : values) {
            if (!value) {
                return false;
            }
        }
        return true;
    }
    else if (operation == "disjunction") {
        for (bool value : values) {
            if (value) {
                return true;
            }
        }
        return false;
    }
    else if (operation == "xor") {
        int trueCount = 0;
        for (bool value : values) {
            if (value) {
                trueCount++;
            }
        }
        return trueCount == 1;
    }
    else if (operation == "negation") {
        return !values[0];
    }
    else if (operation == "implication") {
        return !values[0] || values[1];
    }
    else if (operation == "double_implication") {
        return values[0] == values[1];
    }
    else {
        cout << "Unsupported operation: " << operation << endl;
        return false;
    }
}

// Function to generate a truth table for a given number of propositions
void generateTruthTable(const vector<string>& propositions, const string& operation) {
    for (const string& prop : propositions) {
        cout << prop << "\t";
    }
    cout << "| " << "Law of " << operation << endl;

    for (size_t i = 0; i < propositions.size(); ++i) {
        cout << "--------";
    }
    cout << "|-----------------------------" << endl;

    int numCombinations = pow(2, propositions.size());
    for (int i = 0; i < numCombinations; ++i) {
        vector<bool> values;
        for (size_t j = 0; j < propositions.size(); ++j) {
            bool value = (i >> j) & 1;
            values.push_back(value);
            cout << (value ? 'T' : 'F') << "\t";
        }

        bool result = evaluateExpression(values, operation);

        if (operation == "conjunction") {
            cout << "| " << "(" << propositions[0] << " ^ " << propositions[1] << ")";
        }
        else if (operation == "disjunction") {
            cout << "| " << "(" << propositions[0] << " v " << propositions[1] << ")";
        }
        else if (operation == "xor") {
            cout << "| " << "(" << propositions[0] << " xor " << propositions[1] << ")";
        }
        else if (operation == "negation") {
            cout << "| " << "~" << propositions[0];
        }
        else if (operation == "implication") {
            cout << "| " << "(" << propositions[0] << " -> " << propositions[1] << ")";
        }
        else if (operation == "double_implication") {
            cout << "| " << "(" << propositions[0] << " <-> " << propositions[1] << ")";
        }
        else {
            cout << "| Unsupported operation";
        }

        cout << " = " << (result ? 'T' : 'F') << endl;
    }
}

// Function to check if a given expression is a tautology
bool isTautology(const vector<string>& propositions, const string& operation) {
    for (int i = 0; i < pow(2, propositions.size()); ++i) {
        vector<bool> values;
        for (size_t j = 0; j < propositions.size(); ++j) {
            bool value = (i >> j) & 1;
            values.push_back(value);
        }
        if (!evaluateExpression(values, operation)) {
            return false;
        }
    }
    return true;
}

// Function to get the logical operation from the user
string getLogicalOperation() {
    int operationChoice;
    while (true) {
        cout << "Select the logical operation:\n"
            << "1. Conjunction (^)\n"
            << "2. Disjunction (v)\n"
            << "3. XOR \n"
            << "4. Negation (~)\n"
            << "5. Implication (->)\n"
            << "6. Double Implication (<->)\n"
            << "Enter the corresponding number: ";
        cin >> operationChoice;

        switch (operationChoice) {
        case 1:
            return "conjunction";
        case 2:
            return "disjunction";
        case 3:
            return "xor";
        case 4:
            return "negation";
        case 5:
            return "implication";
        case 6:
            return "double_implication";
        default:
            cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
        }
    }
}

// Function to evaluate Expression1 from code(2)
bool evaluateExpression1(bool p, bool q) {
    return !(p || (!p && q));
}

// Function to evaluate Expression2 from code(2)
bool evaluateExpression2(bool p, bool q) {
    return !p && !q;
}

// Function to calculate mean and variance for a given set of events and probabilities (code(2))
void calculateMeanAndVariance() {
    int number_of_element;
    double event, probability, mean = 0, mean_of_squares = 0;

    cout << "Enter the number of elements: ";
    cin >> number_of_element;

    for (int i = 0; i < number_of_element; i++) {
        cout << "Enter the event: ";
        cin >> event;

        cout << "Enter the probability of this event: ";
        cin >> probability;

        mean += (event * probability);
        mean_of_squares += (event * event * probability);
    }

    cout << "Mean = " << mean << '\n';
    cout << "Variance = " << (mean_of_squares - (mean * mean)) << '\n';
}

int main() {
    int userChoice;
    cout << "Select the program to run:\n"
        << "1. Truth Table Generator\n"
        << "2. Equivalence Checker for Specific expression\n"
        << "3. Mean and Variance Calculator\n"
        << "Enter the corresponding number: ";
    cin >> userChoice;

    if (userChoice == 1) {
        int userChoiceCode1 = 1;
        while (userChoiceCode1 != 0) {
            string operation = getLogicalOperation();
            int numPropositions;
            vector<string> propositions;

            if (operation == "negation") {
                numPropositions = 1;
            }
            else {
                cout << "Enter the number of propositions: ";
                cin >> numPropositions;
            }

            for (int i = 0; i < numPropositions; ++i) {
                cout << "Enter proposition " << (i + 1) << " name: ";
                string proposition;
                cin >> proposition;
                propositions.push_back(proposition);
            }

            generateTruthTable(propositions, operation);

            if (isTautology(propositions, operation)) {
                cout << "The expression is a tautology." << endl;
            }
            else {
                cout << "The expression is not a tautology." << endl;
            }

            cout << "Enter 1 to repeat the program, or 0 to exit: ";
            cin >> userChoiceCode1;
        }
    }
    else if (userChoice == 2) {
        int choice;
        cout << "Expression1: ~(p v (~ p ^ q))" << endl;
        cout << "Expression2: (~p ^ ~q)" << endl;
        cout << "Do you want to check the equivalence of two expressions? Enter 1 for yes, 0 for no: ";
        cin >> choice;

        if (choice != 1) {
            cout << "Exiting program. No input received to check equivalence." << endl;
            return 0;
        }

        const int columnWidth = 12;

        cout << boolalpha;

        cout << setw(columnWidth) << "p" << " | " << setw(columnWidth) << "q"
            << " | " << setw(columnWidth) << "~p" << " | " << setw(columnWidth) << "~q"
            << " | " << setw(columnWidth) << "(~p ^ q)" << " | " << setw(columnWidth) << "(p v (~p ^ q)"
            << " | " << setw(columnWidth) << "~(p v (~p ^ q))" << " | " << setw(columnWidth) << "(~p ^ ~q)" << endl;

        cout << setfill('-') << setw(8 * columnWidth + 7 * 3) << "-" << setfill(' ') << endl;

        bool equivalent = true;
        for (bool p : {false, true}) {
            for (bool q : {false, true}) {
                bool not_p = !p;
                bool not_q = !q;
                bool not_p_and_q = !p && q;
                bool p_or_not_p_and_q = p || (!p && q);
                bool not_p_or_not_p_and_q = !(p_or_not_p_and_q);
                bool not_p_and_not_q = !p && !q;

                cout << setw(columnWidth) << (p ? "T" : "F") << " | " << setw(columnWidth) << (q ? "T" : "F")
                    << " | " << setw(columnWidth) << (not_p ? "T" : "F") << " | " << setw(columnWidth) << (not_q ? "T" : "F")
                    << " | " << setw(columnWidth) << (not_p_and_q ? "T" : "F") << " | " << setw(columnWidth) << (p_or_not_p_and_q ? "T" : "F")
                    << " | " << setw(columnWidth) << (not_p_or_not_p_and_q ? "T" : "F") << " | " << setw(columnWidth) << (not_p_and_not_q ? "T" : "F") << endl;

                if (not_p_or_not_p_and_q != not_p_and_not_q) {
                    equivalent = false;
                }
            }
        }

        cout << endl;
        if (equivalent) {
            cout << "The two expressions are equivalent." << endl;
        }
        else {
            cout << "The two expressions are not equivalent." << endl;
        }
    }
    else if (userChoice == 3) {
        // Call the function for calculating mean and variance (code(2))
        calculateMeanAndVariance();
    }
    
    
    else {
        cout << "Invalid choice. Exiting program." << endl;
    }

    return 0;
}

