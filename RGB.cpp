#include "RGB.h"

std::ostream& operator<<(std::ostream& os, const RGB& obj)
{
    return os << '(' << obj.red << ' ' << obj.green << ' ' << obj.blue << ')';
}
