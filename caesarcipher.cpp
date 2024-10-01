#include <iostream>
#include <cstring> 
using namespace std;

#define N 26

class Cipher {
private:
    char arr1[N];
    char arr2[N];

public:
    Cipher() {
        for (int i = 0; i < N; i++) {
            arr1[i] = 'a' + i;
            arr2[i] = 'z' - i;
        }
    }

    void encrypt(const char word[], char encryptedWord[], int key) {
        int len = strlen(word);
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < N; j++) {
                if (word[i] == arr1[j]) {
                    encryptedWord[i] = arr2[(j + key) % N];
                    break; 
                }
            }
        }
        encryptedWord[len] = '\0';
    }

    void decrypt(const char word[], char decryptedWord[], int key) {
        int len = strlen(word);
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < N; j++) {
                if (word[i] == arr2[j]) {
                    decryptedWord[i] = arr1[(j - key + N) % N];
                    break; 
                }
            }
        }
        decryptedWord[len] = '\0';
    }
};

int main() {
    char word[100];
    char encryptedWord[100];
    char decryptedWord[100];

    cout << "Enter the key: ";
    int key;
    cin >> key;

    Cipher cipher;

    cout << "Enter a word to encrypt: ";
    cin >> word;
    cipher.encrypt(word, encryptedWord, key);
    cout << "Encrypted word: " << encryptedWord << endl;

    cout << "Enter encrypted word to decrypt: ";
    cin >> word;
    cipher.decrypt(word, decryptedWord, key);
    cout << "Decrypted word: " << decryptedWord << endl;

    return 0;
}
