#include "Read.h"

Read::Read(const std::string &fname)
{
    _f.open(fname);
    if (_f.fail()){
        throw NoExistingFileException();
    }
}

Read::~Read()
{
    _f.close();
}

void Read::first()
{
    if (!(_f >> _e)) _st = abnorm;
}
void Read::next()
{
    first();
}
int Read::current() const
{
    return _e;
}
bool Read::end() const
{
    return (_st == abnorm);
}
