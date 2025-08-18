#include <iostream>
using namespace std;

// Function to find length of string
int strLength(char str[]) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

// (a) Concatenate
void concatenate(char str1[], char str2[]) {
    int i = strLength(str1);
    int j = 0;
    while (str2[j] != '\0') {
        str1[i++] = str2[j++];
    }
    str1[i] = '\0';
    cout << "Concatenated string: " << str1 << endl;
}

// (b) Reverse
void reverseStr(char str[]) {
    int len = strLength(str);
    for (int i = 0; i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
    cout << "Reversed string: " << str << endl;
}

// (c) Delete vowels
void removeVowels(char str[]) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        char c = str[i];
        if (!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
              c=='A'||c=='E'||c=='I'||c=='O'||c=='U')) {
            str[j++] = c;
        }
        i++;
    }
    str[j] = '\0';
    cout << "Without vowels: " << str << endl;
}

// (d) Sort strings alphabetically (Bubble Sort)
void sortStrings(char str[10][50], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            int k = 0;
            while (str[j][k] != '\0' && str[j+1][k] != '\0' && str[j][k] == str[j+1][k]) k++;
            if (str[j][k] > str[j+1][k]) {
                char temp[50];
                int m = 0;
                while ((temp[m] = str[j][m]) != '\0') m++;
                m = 0;
                while ((str[j][m] = str[j+1][m]) != '\0') m++;
                m = 0;
                while ((str[j+1][m] = temp[m]) != '\0') m++;
            }
        }
    }

    cout << "Sorted strings:\n";
    for (int i = 0; i < n; i++) {
        cout << str[i] << endl;
    }
}

// (e) Convert uppercase to lowercase
void toLower(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
    cout << "Lowercase: " << str << endl;
}

// ---------------- MAIN ----------------
int main() {
    int choice;
    do {
        cout << "\n---- STRING PROGRAMS ----\n";
        cout << "1. Concatenate two strings\n";
        cout << "2. Reverse a string\n";
        cout << "3. Delete vowels from a string\n";
        cout << "4. Sort multiple strings alphabetically\n";
        cout << "5. Convert uppercase to lowercase\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            char str1[100], str2[50];
            cout << "Enter first string: ";
            cin >> str1;
            cout << "Enter second string: ";
            cin >> str2;
            concatenate(str1, str2);
        }
        else if (choice == 2) {
            char str[100];
            cout << "Enter string: ";
            cin >> str;
            reverseStr(str);
        }
        else if (choice == 3) {
            char str[100];
            cout << "Enter string: ";
            cin >> str;
            removeVowels(str);
        }
        else if (choice == 4) {
            int n;
            cout << "Enter number of strings: ";
            cin >> n;
            char arr[10][50];
            cout << "Enter " << n << " strings:\n";
            for (int i = 0; i < n; i++) cin >> arr[i];
            sortStrings(arr, n);
        }
        else if (choice == 5) {
            char str[100];
            cout << "Enter string: ";
            cin >> str;
            toLower(str);
        }
    } while (choice != 0);

    return 0;
}
