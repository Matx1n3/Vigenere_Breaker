#include <iostream>
#include <unordered_map>
#include <cmath>

/*git
 * mod function to handle negative numbers
 * pre: a is an integer, b is an integer
 * post: returns a mod b
 */
int mod(int a, int b) {
    return (a % b + b) % b;
}

int main() {

    int from;
    int to;
    std::string ciphertext;

    std::cout << "From: " << std::endl;
    std::cin >> from;

    std::cout << "To: " << std::endl;
    std::cin >> to;

    std::cout << "Ciphertext: " << std::endl;
    std::string line;
    while (std::getline(std::cin, line)) {
        if (!line.empty()) {
            ciphertext += line;
        }
    }

    float max_sd = 0;
    int max_k = 0;
    std::unordered_map<char, int>* freq_ptr = nullptr;

    for (int k = from; k <= to; k++) {
        std::unordered_map<char, int> frequencies[k];
        float mean[k];
        float variance[k];
        float sd = 0;

        // Initialize the mean and variance arrays to 0
        for (int i = 0; i < k; i++) {
            mean[i] = 0;
            variance[i] = 0;
        }
        // Count the frequency of each letter for each of the k vectors
        // and sum the total number of letters in each vector
        for (int i = 0; i < ciphertext.size(); i++) {
            frequencies[i % k][ciphertext[i]] += 1;
            mean[i % k] += 1;
        }

        for (int i = 0; i < k; i++) {
            // Divide by 26 to get the mean
            mean[i] /= 26;

            // Compute the variance
            for (const auto &pair: frequencies[i]) {
                variance[i] += float(pow((float(pair.second) - mean[i]), 2));
            }
            variance[i] /= 26;

            // Compute the standard deviation
            sd += float(sqrt(double(variance[i])));

        }

        // Update if neccessary
        if (sd > max_sd) {

            max_sd = sd;
            max_k = k;

            if (freq_ptr != nullptr) {
                delete[] freq_ptr;  // Free the memory allocated for the frequencies no longer needed
            }
            freq_ptr = new std::unordered_map<char, int>[k]; // Allocate memory for the new frequencies (Memory leak ????)
            // Copy the frequencies to the new pointer
            for (int i = 0; i < k; i++) {
                freq_ptr[i] = frequencies[i];
            }
        }
        std::cout << "Key length: " << k << " SD: " << sd << std::endl;
    }

    std::string likely_key = "";

    for (int i = 0; i < max_k; i++) {
        char most_frequent = 'a';
        for (const auto &pair: freq_ptr[i]) {
            if (pair.second > freq_ptr[i][most_frequent]) {
                most_frequent = pair.first;
            }
        }
        char shift = char(mod((most_frequent - 'e'), 26) + 97);
        likely_key += shift;
    }

    std::cout << "Likely key for k = " << max_k << ": " << likely_key << std::endl;

    delete[] freq_ptr;  // Free the memory allocated for the frequencies
    return 0;
}
