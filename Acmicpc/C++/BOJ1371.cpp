#include <iostream>
#include <algorithm>
#include <ctype.h>

int alpha[26];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string str;
    while(std::cin >> str) {
        for(int i = 0; i < str.length(); i++)
            if(isalpha(str[i]))
                alpha[str[i]-'a']++;
        str.clear();
    }

    int MAX = *std::max_element(alpha, alpha + 25);

    for(int i = 0 ; i < 26; i++) {
        if(MAX == alpha[i])
            printf("%c", i + 'a');
    }

    return 0;
}