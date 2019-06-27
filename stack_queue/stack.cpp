#include "stack.h"

Stack::Stack()
{
}

Stack::~Stack()
{
}

int Stack::max() const
{
    return d_maxSoFar.back();
}
