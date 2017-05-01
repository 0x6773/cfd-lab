#include<iostream>
#include<cstring>

using namespace std;

// Function to encrypt the message using (ax + b) mod m where m is the size of the alphabet.(here m=26)
string encrypt(string m)
{
    string cipher_text = "";
    int a = 5;
    int b = 8;

    for (int i = 0; i < m.length(); i++)
    {
        cipher_text = cipher_text + (char) ((((a * m[i]) + b) % 26) + 65);
    }

    return cipher_text;
}


// Function to decrypt the cipher text given using a^-1(x - b) here a^-1 is the inverse of a s.t. 1 = a*a^-1 mod m
string decrypt(string cipher_text)
{
    string m = "";
    int a = 5;
    int b = 8;
    int a_inv = 0;
    int flag = 0;
    // calculating a^-1 for decryption
    for (int i = 0; i < 26; i++)
    {
        flag = (a * i) % 26;
        if (flag == 1)
        {
            a_inv = i;
        }
    }

    for (int i = 0; i < cipher_text.length(); i++)
    {
        m = m + (char) (((a_inv * ((cipher_text[i] - b)) % 26)) + 65);
    }

    return m;
}

// Main function for checking the encrypt and decrypt functions above
// int main()
// {
//     string message;
//     cout << "Enter the message: ";
//     cin >> message;
//     cout << "Encrypted Message of "<< message << "is : " << encrypt(message)<<endl;
//     cout << "Decrypted Message of "<< encrypt(message) << "is: " << decrypt(encrypt(message));
// }
