
#include <glib-object.h>
#include <stdio.h>

#include "my-hello.h"

int main(int argc, char *argv[])
{
    MyHello *hello = my_hello_new();
    my_hello_greet(hello, "Nate");
    g_object_unref(G_OBJECT(hello));

    printf("%s\n", my_get_constant());
    return 0;
}
