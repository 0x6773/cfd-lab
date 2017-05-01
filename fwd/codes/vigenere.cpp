#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char key[80] = "RANDOM";
int key_length = strlen(key);

// Function to encrypt the text using the given key and variable blcok size
string encrypt(string message)
{
    int block_length = message.length();
    cout << "key length" << key_length << endl;
    cout << "block length" << block_length << endl;
    string cipher_text = "";

    for (int i = 0; i < block_length; i++) {
        cipher_text = cipher_text
                      + (char)(((message[i] + key[i % key_length]) % 26) + 65);
    }
    return cipher_text;
}

// Function to decrypt the cipher text using the given key and variable block
// length.
string decrypt(string cipher_text)
{
    int block_length = cipher_text.length();
    string message = "";
    for (int i = 0; i < block_length; i++) {
        message
            += (char)(((cipher_text[i] - key[i % key_length] + 26) % 26) + 65);
    }
    return message;
}

int main()
{
    string me = "IITBHU";
    cout << "Encrypted message : " << encrypt(me) << endl;
    cout << "Decrypted message : " << decrypt(encrypt(me));

    return 0;
}
