//
// Created by yead on 9/16/23.
//

#ifndef SYMPLE_TASKER_BASE64_H
#define SYMPLE_TASKER_BASE64_H
#include <string>
namespace crypto {

    class base64 {
    public:
        static std::string encode(const std::string &in);

        static std::string decode(const std::string &in);
    };

} // crypto

#endif //SYMPLE_TASKER_BASE64_H
