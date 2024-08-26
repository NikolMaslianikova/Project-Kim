

#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>



int main() {

    long long apples, pals;
    std::cin >> apples >> pals;

    std::vector<long double> outcomes;
    outcomes.push_back(apples);

    std::vector<long double> temp;
    for (long long i = 0; i < pals; i++) {

        sort(outcomes.begin(), outcomes.end());
        outcomes.erase(unique(outcomes.begin(), outcomes.end()), outcomes.end());

        for (long long j = 0; j < outcomes.size(); j++) {
            if (outcomes[j] != (int)outcomes[j]) { //check if not a whole number
                if (outcomes[j] - 0.5 >= 0) {
                    temp.push_back(outcomes[j] - 0.5);
                }
            }
            else { //if a whole number, we make from it 2 numbers: n - 0.5 and n / 2
                if (outcomes[j] - 0.5 >= 0) {
                    temp.push_back(outcomes[j] - 0.5);
                } temp.push_back(outcomes[j] / 2.0);
            }

        }

        outcomes = temp;

        temp.clear();


    }

    sort(outcomes.begin(), outcomes.end());
    outcomes.erase(unique(outcomes.begin(), outcomes.end()), outcomes.end());

    std::cout << outcomes.size() << std::endl;

    for (const auto &outcome: outcomes) {
        std::cout << std::setprecision(1) << std::fixed << outcome << " ";
    }

    return 0;


}
