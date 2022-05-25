
#include <stdio.h>

#include "my-hello.h"

struct _MyHello {
    GObject parent_instance;
};

G_DEFINE_TYPE(MyHello, my_hello, G_TYPE_OBJECT)

static void my_hello_class_init(MyHelloClass *klass) {}

static void my_hello_init(MyHello *self) {}

void my_hello_greet(MyHello *self, const char *name)
{
    printf("Hi, %s\n", name);
}
