
#include <stdio.h>

#include "my-hello.h"

struct _MyHello {
    GObject parent_instance;
    const char *greeting;
};

G_DEFINE_TYPE(MyHello, my_hello, G_TYPE_OBJECT)

static void my_hello_class_init(MyHelloClass *klass) {}

static void my_hello_init(MyHello *self) {}

/**
 * my_hello_new:
 *
 * Create a MyHello object.
 *
 * Returns: (transfer full): A MyHello object.
 */
MyHello *my_hello_new(void)
{
    MyHello *hello = g_object_new(MY_TYPE_HELLO, NULL);
    hello->greeting = "Hi";

    return hello;
}

void my_hello_greet(MyHello *self, const char *name)
{
    printf("%s, %s\n", self->greeting, name);
}

/**
 * my_get_constant:
 *
 * Get a constant.
 *
 * Returns: (transfer none): A constant string
 */
const char *my_get_constant(void)
{
    return "Hello world";
}
