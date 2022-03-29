#ifndef READ_H
#define READ_H

#include <fstream>
#include <exception>

class Read
{
    public:
        class NoExistingFileException : public std::exception{};
        Read(const std::string &fname);
        ~Read();

        void first();
        void next();
        int current() const;
        bool end() const;



    private:
        enum Status{norm, abnorm};
        Status _st;
        int _e;
        std::ifstream _f;
};

#endif // READ_H
