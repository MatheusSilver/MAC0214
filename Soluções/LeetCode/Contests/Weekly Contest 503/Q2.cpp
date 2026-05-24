class Solution {
public:
    bool isLow(char c){
        return c >= 'a' && c <= 'z';
    }

    bool isUpp(char c){
        return c >= 'A' && c <= 'Z';
    }

    bool isDig(char c){
        return c >= '0' && c <= '9';
    }
    int passwordStrength(string password) {
        // Eu esqueci como usa mapas então vou pela solução TecProg brutamontes.

        // Note que a senha provavelmente está no formato UTF-8, e portanto, cada char está entre 0 a 255;

        bool charArray[256] = {false};
        int totalPoints = 0;

        for (char x : password){
            unsigned char charIndex = x;
            if (isLow(x) && charArray[charIndex] == false){
                totalPoints += 1;
                charArray[charIndex] = true;
            }
            else if (isUpp(x) && charArray[charIndex] == false){
                totalPoints += 2;
                charArray[charIndex] = true;
            }
            else if (isDig(x) && charArray[charIndex] == false){
                totalPoints += 3;
                charArray[charIndex] = true;
            }
            else if (charArray[charIndex] == false){
                totalPoints += 5;
                charArray[charIndex] = true;
            }
        }

        return totalPoints;
    }
};