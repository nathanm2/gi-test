
#include <glib-object.h>

#include "my-hello.h"

int main(int argc, char *argv[])
{
    MyHello *hello = my_hello_new("Hi");
    my_hello_greet(hello, "Nate");
    g_object_unref(G_OBJECT(hello));

    return 0;
}
