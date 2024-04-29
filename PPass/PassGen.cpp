#include "Header.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>

namespace PPass {

    std::string pass_gen(int length, int count, bool useNumbers, bool useSmallLetters, bool useBigLetters, bool useSpecialSymbols)
    {
        const int specialChars[][2] =
        {
            {33, 47},
            {58, 64},
            {91, 96},
            {123, 126}
        };

        const int digitChars[][2] = { {48, 57} };
        const int uppercaseChars[][2] = { {65, 90} };
        const int lowercaseChars[][2] = { {97, 122} };

        const int numSpecialRanges = sizeof(specialChars) / sizeof(specialChars[0]);
        const int numDigitRanges = sizeof(digitChars) / sizeof(digitChars[0]);
        const int numUppercaseRanges = sizeof(uppercaseChars) / sizeof(uppercaseChars[0]);
        const int numLowercaseRanges = sizeof(lowercaseChars) / sizeof(lowercaseChars[0]);

        std::string password;

        for (int j = 0; j < count; ++j)
        {
            std::string generatedPassword;

            for (int i = 0; i < length; ++i)
            {
                int validRanges[4]; // ³íäåêñè äîïóñòèìèõ ä³àïàçîí³â
                int count = 0;

                if (useNumbers) validRanges[count++] = 1;
                if (useSmallLetters) validRanges[count++] = 2;
                if (useBigLetters) validRanges[count++] = 3;
                if (useSpecialSymbols) validRanges[count++] = 0;

                int rangeIndex = validRanges[rand() % count];
                int start = (rangeIndex == 0) ? specialChars[rand() % numSpecialRanges][0] :
                    (rangeIndex == 1) ? digitChars[rand() % numDigitRanges][0] :
                    (rangeIndex == 2) ? uppercaseChars[rand() % numUppercaseRanges][0] :
                    lowercaseChars[rand() % numLowercaseRanges][0];
                int end = (rangeIndex == 0) ? specialChars[rand() % numSpecialRanges][1] :
                    (rangeIndex == 1) ? digitChars[rand() % numDigitRanges][1] :
                    (rangeIndex == 2) ? uppercaseChars[rand() % numUppercaseRanges][1] :
                    lowercaseChars[rand() % numLowercaseRanges][1];

                int random_pass = start + rand() % (end - start + 1);

                generatedPassword += static_cast<char>(random_pass);
            }

            password += generatedPassword + "\r\n";
        }

        return password;
    }
}
