#include <bits/stdc++.h>
using namespace std;

// d: Number of characters in the input alphabet (a prime number is good)
#define d 257
// q: A prime number for the modulo operation
#define q 101

void search(const string& pat, const string& txt) {
    int M = pat.length();
    int N = txt.length();
    int i, j;
    int p_hash = 0; // hash value for pattern
    int t_hash = 0; // hash value for txt window
    int h = 1;

    // The value of h would be "pow(d, M-1) % q"
    // We calculate it efficiently in a loop
    for (i = 0; i < M - 1; i++) {
        h = (h * d) % q;
    }

    // Calculate the hash value of the pattern and the first window of text
    for (i = 0; i < M; i++) {
        p_hash = (d * p_hash + pat[i]) % q;
        t_hash = (d * t_hash + txt[i]) % q;
    }

    // Slide the pattern over the text one by one
    for (i = 0; i <= N - M; i++) {

        // Check the hash values of current window of text and pattern.
        // If the hash values match, then only check for characters one by one (to handle collisions)
        if (p_hash == t_hash) {
            // Check for characters one by one
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }
            // if p_hash == t_hash and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == M) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Calculate hash value for next window of text:
        // Remove leading digit, add trailing digit
        if (i < N - M) {
            // Calculate the rolling hash
            t_hash = (d * (t_hash - txt[i] * h) + txt[i + M]) % q;

            // We might get a negative value of t_hash, converting it to positive
            if (t_hash < 0) {
                t_hash = (t_hash + q);
            }
        }
    }
}


int main() {
    string txt = "AABAACAADAABAABA";
    string pat = "AABA";
    cout << "Text: " << txt << endl;
    cout << "Pattern: " << pat << endl;
    search(pat, txt);
    return 0;
}