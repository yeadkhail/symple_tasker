//
// Created by yead on 9/16/23.
//

#include "../../../../headers/base64.h"
#include<string>
#include<vector>

using namespace std;
namespace crypto {

        static const std::string base64_chars =
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz"
                "0123456789+/";

        static inline bool is_base64(unsigned char c) {
            return (isalnum(c) || (c == '+') || (c == '/'));
        }

        std::string base64::encode(const std::string &in) {
            std::string out;

            int val = 0, valb = -6;
            for (unsigned char c : in) {
                val = (val << 8) + c;
                valb += 8;
                while (valb >= 0) {
                    out.push_back(base64_chars[(val >> valb) & 0x3F]);
                    valb -= 6;
                }
            }
            if (valb > -6) out.push_back(base64_chars[((val << 8) >> (valb + 8)) & 0x3F]);
            while (out.size() % 4) out.push_back('=');
            return out;
        }

        std::string base64::decode(const std::string &in) {
            std::string out;

            std::vector<int> T(256, -1);
            for (int i = 0; i < 64; i++) T[base64_chars[i]] = i;

            int val = 0, valb = -8;
            for (unsigned char c : in) {
                if (T[c] == -1) break;
                val = (val << 6) + T[c];
                valb += 6;
                if (valb >= 0) {
                    out.push_back(char((val >> valb) & 0xFF));
                    valb -= 8;
                }
            }
            return out;
        }
} // crypto