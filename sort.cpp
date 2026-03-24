#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> input = {7, 3, 5, 2, 6, 1};
    vector<int> result;

    int comparisons = 0;
    int moves = 0;

    while (!input.empty()) {
        vector<int> strand;

        // Take first element
        strand.push_back(input[0]);
        input.erase(input.begin());
        moves++;

        int last = strand.back();

        // Build strand (descending)
        for (int i = 0; i < input.size();) {
            comparisons++;
            if (input[i] <= last) {
                strand.push_back(input[i]);
                last = input[i];
                input.erase(input.begin() + i);
                moves++;
            } else {
                i++;
            }
        }

        // Merge strand into result (descending)
        vector<int> temp;
        int i = 0, j = 0;

        while (i < result.size() && j < strand.size()) {
            comparisons++;
            if (result[i] >= strand[j]) {
                temp.push_back(result[i++]);
            } else {
                temp.push_back(strand[j++]);
            }
            moves++;
        }

        while (i < result.size()) {
            temp.push_back(result[i++]);
            moves++;
        }

        while (j < strand.size()) {
            temp.push_back(strand[j++]);
            moves++;
        }

        result = temp;
    }

    // Output
    cout << "Sorted list (Descending): ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Comparisons: " << comparisons << endl;
    cout << "Moves: " << moves << endl;

    return 0;
}