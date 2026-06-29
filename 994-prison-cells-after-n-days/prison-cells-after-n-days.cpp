class Solution {
public:
    
    vector<int> nextDay(vector<int> &cells) {
        vector<int> next(8, 0);

        for (int i = 1; i <= 6; i++) {
            next[i] = (cells[i - 1] == cells[i + 1]);
        }

        return next;
    }

    vector<int> prisonAfterNDays(vector<int>& cells, int n) {

        unordered_map<string, int> seen;

        while (n > 0) {

            string state;
            for (int x : cells)
                state += char(x + '0');

           
            if (seen.count(state)) {

                int cycleLength = seen[state] - n;
                n %= cycleLength;
            }

           
            seen[state] = n;

            if (n > 0) {
                n--;
                cells = nextDay(cells);
            }
        }

        return cells;
    }
};