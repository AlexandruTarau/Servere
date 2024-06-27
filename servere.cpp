#include <bits/stdc++.h>
using namespace std;

class Task {
 public:
    /* Function that runs the code */
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int n;
    vector<int> p;
    vector<int> c;

    /* Reading function */
    void read_input() {
        ifstream fin("servere.in");
        fin >> n;

        /* Reading the computing power of the servers */
        for (int i = 0, power; i < n; i++) {
            fin >> power;
            p.push_back(power);
        }

        /* Reading the current limit of the servers */
        for (int i = 0, current; i < n; i++) {
            fin >> current;
            c.push_back(current);
        }
        fin.close();
    }

    /* Function that calculates the result */
    double get_result() {
        vector<double> aux(n);

        // Copying the currents in an auxiliar variable
        for (int i = 0; i < n; i++) {
            aux[i] = c[i];
        }

        // Calculating the medium between the min and max values of the currents
        int maxCurrent = *max_element(c.begin(), c.end());
        int minCurrent = *min_element(c.begin(), c.end());
        double current = (maxCurrent + minCurrent) / 2.0;

        double min_power;
        int old_index = -1;
        double old_current;

        // While within an error of 0.01, find a closer solution for the problem
        do {
            int min_index;
            min_power = INFINITY;

            // Find the minimum power with current
            for (int i = 0; i < n; i++) {
                double power = p[i] - abs(current - c[i]);

                if (min_power > power) {
                    min_power = power;
                    min_index = i;
                }
            }

            /* Save the current value and update it with the current of the
            server with minimum power */
            old_current = current;
            current = (current + aux[min_index]) / 2.0;

            /* Save the new index and update the old current */
            if (old_index != min_index) {
                if (old_index != -1) {
                    aux[old_index] = old_current;
                }
                old_index = min_index;
            }
        } while (abs(old_current - current) > 0.01);

        return min_power;
    }

    /* Printing function */
    void print_output(double result) {
        ofstream fout("servere.out");
        fout << setprecision(1) << fixed << result;
        fout.close();
    }
};

int main() {
    auto *task = new (nothrow) Task();
    if (!task) {
        cerr << "new failed: WTF are you doing? Throw your PC!\n";
        return -1;
    }
    task->solve();
    delete task;
    return 0;
}
