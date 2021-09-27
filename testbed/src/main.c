#include <core/logger.h>
#include <core/asserts.h>

int main(void) 
{
    LPAFATAL("A fatal message: %f", 3.14f);
    LPAERROR("An error message: %f", 3.14f);
    LPAWARN("A warn message: %f", 3.14f);
    LPAINFO("An info message: %f", 3.14f);
    LPADEBUG("A debug message: %f", 3.14f);
    LPATRACE("A trace message: %f", 3.14f);

    LPAASSERT(1 == 0);

    return 0;
}