
#pragma once

#include <glib-object.h>

#define MY_TYPE_HELLO my_hello_get_type()
G_DECLARE_FINAL_TYPE(MyHello, my_hello, MY, HELLO, GObject)

void my_hello_greet(MyHello *self, const char *name);
