
#include <glib-object.h>

#include "my-hello.h"

int main(int argc, char *argv[])
{
    MyHello *hello = g_object_new(MY_TYPE_HELLO, NULL);
    my_hello_greet(hello, "Nate");
    g_object_unref(G_OBJECT(hello));

    return 0;
}
