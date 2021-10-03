#include <core/logger.h>
#include <core/asserts.h>

// TODO: Test.
#include <platform/platform.h>

int main(void) 
{
    LPAFATAL("A fatal message: %f", 3.14f);
    LPAERROR("An error message: %f", 3.14f);
    LPAWARN("A warn message: %f", 3.14f);
    LPAINFO("An info message: %f", 3.14f);
    LPADEBUG("A debug message: %f", 3.14f);
    LPATRACE("A trace message: %f", 3.14f);

    platform_state state;
    if (platform_startup(&state, "LowPolyApe Engine Testbed", 100, 100, 1280, 720))
    {
        while (TRUE)
        {
            platform_pump_messages(&state);
        }
    }
    platform_shutdown(&state);
    
    return 0;
}