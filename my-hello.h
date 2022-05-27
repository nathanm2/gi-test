
#pragma once

#include <glib-object.h>

#include "my-title.h"

#define MY_TYPE_HELLO my_hello_get_type()
G_DECLARE_FINAL_TYPE(MyHello, my_hello, MY, HELLO, GObject)

MyHello *my_hello_new(const char *greeting);

void my_hello_greet(MyHello *self, MyTitle title, const char *name);

const char *my_get_constant(void);
