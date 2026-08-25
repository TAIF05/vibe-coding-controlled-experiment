#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Helper function to check if we can satisfy the condition >= prev
// if we choose 'current_char' at 'index' and minimize the rest?
// Actually, we need to check: if we are currently matching the prefix of prev,
// does choosing 'current_char' allow us to potentially win later?
bool is_viable(const string& prev, const string& raw_curr, int idx, char current_char) {
    // If we are strictly greater already at this digit, we are safe (viable).
    if (current_char > prev[idx]) return true;
    
    // If we are strictly smaller, this path is dead.
    if (current_char < prev[idx]) return false;

    // If we are equal (current_char == prev[idx]), we need to look ahead.
    // Can we form a valid suffix that is >= prev's suffix?
    // We test the "best case scenario" for the rest of the string:
    // turn all subsequent 6s and 9s into 9s (max possible value).
    for (size_t i = idx + 1; i < raw_curr.length(); ++i) {
        char max_val = (raw_curr[i] == '6' || raw_curr[i] == '9') ? '9' : raw_curr[i];
        
        if (max_val > prev[i]) return true; // We can eventually get bigger
        if (max_val < prev[i]) return false; // Even with max effort, we lose
        // If equal, continue to next digit
    }
    
    // If we reached the end and are still equal, then >= is satisfied.
    return true;
}

int main() {
    // 1. REQUESTING INPUT AS INSTRUCTED
    cout << "Please enter the number of elements followed by the elements themselves:" << endl;

    int n;
    // Check if input exists to avoid crashes
    if (!(cin >> n)) return 0;

    vector<string> inputs(n);
    for (int i = 0; i < n; ++i) {
        cin >> inputs[i];
    }

    vector<string> result;
    // We start with a "previous" value of "0" (or empty) that is smaller than any positive integer
    string prev = "0"; 

    for (const string& raw : inputs) {
        // Condition 1: Length check
        // If current number is shorter than previous, impossible to be >= (since inputs are positive integers)
        if (raw.length() < prev.length()) {
            cout << "impossible" << endl;
            return 0;
        }

        string curr = "";

        // Condition 2: Current is longer than previous
        if (raw.length() > prev.length()) {
            // Since it's longer, it's automatically larger.
            // We just make it as small as possible (convert all 6/9 to 6).
            for (char c : raw) {
                if (c == '6' || c == '9') curr += '6';
                else curr += c;
            }
        } 
        // Condition 3: Same length
        else {
            bool already_larger = false;
            
            for (size_t i = 0; i < raw.length(); ++i) {
                char c = raw[i];
                
                // If we are already larger than 'prev' due to a previous digit,
                // we just want the smallest possible digit here (greedy min).
                if (already_larger) {
                    if (c == '6' || c == '9') curr += '6';
                    else curr += c;
                    continue;
                }

                // If we are currently "equal" to prev so far, we have to be careful.
                // Determine our options.
                char low = (c == '6' || c == '9') ? '6' : c;
                char high = (c == '6' || c == '9') ? '9' : c;

                // Try the smallest option first
                if (is_viable(prev, raw, i, low)) {
                    curr += low;
                    if (low > prev[i]) already_larger = true;
                } 
                // If smallest option fails, try the largest option
                else if (is_viable(prev, raw, i, high)) {
                    curr += high;
                    if (high > prev[i]) already_larger = true;
                } 
                // If both fail, it's impossible
                else {
                    cout << "impossible" << endl;
                    return 0;
                }
            }
        }

        result.push_back(curr);
        prev = curr;
    }

    // Output success and the list
    cout << "possible" << endl;
    for (const string& s : result) {
        cout << s << endl;
    }

    return 0;
}