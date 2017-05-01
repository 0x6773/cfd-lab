#include<iostream>
#include<cstring>

using namespace std;

// Function to encrypt the message
string encrypt(string m)
{
    string cipher_text = "";
    int n = 0;

    for (int i = 0; i < m.length(); i++)
    {
      if(islower(m[i]))
     {
       if((m[i] >= 'a') && ( m[i] < 'x'))
         m[i] = toupper(m[i] + (char) 3);
       else if(m[i] == 'x')
         m[i] = 'A';
       else if(m[i] == 'y')
         m[i] = 'B';
       else
         m[i] = 'C';
     }
     else
     {
       m[i] = m[i];
     }
    }

    cipher_text = m;
    return cipher_text;
}


// Function to decrypt the cipher text given
string decrypt(string m)
{
    //string m = "";

    for (int i = 0; i < m.length(); i++)
    {
      if(isupper(m[i]))
     {
       if((m[i] >= 'D' ) && ( m[i] <= 'Z' ))
         m[i] = tolower(m[i] - (char)3);
       else if(m[i] == 'A')
         m[i] = 'x';
       else if(m[i] == 'B')
         m[i] = 'y';
       else
         m[i] = 'z';
     }
     else
     {
       m[i] = m[i];
     }
    }


    return m;
}


// int main()
// {
//     string message;
//     cout << "Enter the message: ";
//     cin >> message;
//     cout << "Encrypted Message of "<< message << "is : " << encrypt(message)<<endl;
//     cout << "Decrypted Message of "<< encrypt(message) << "is: " << decrypt(encrypt(message));
// }
