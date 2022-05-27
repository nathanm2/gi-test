
#include <stdio.h>

#include "my-hello.h"

typedef enum { PROP_GREETING = 1, N_PROPERTIES } MyHelloProperty;

static GParamSpec *obj_properties[N_PROPERTIES] = {
    NULL,
};

struct _MyHello {
    GObject parent_instance;
    char *greeting;
};

G_DEFINE_TYPE(MyHello, my_hello, G_TYPE_OBJECT)

static void my_hello_set_property(GObject *object, guint property_id, const GValue *value,
                                  GParamSpec *pspec)
{
    MyHello *self = MY_HELLO(object);

    switch ((MyHelloProperty)property_id) {
    case PROP_GREETING:
        g_free(self->greeting);
        self->greeting = g_value_dup_string(value);
        break;
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        break;
    }
}

static void my_hello_get_property(GObject *object, guint property_id, GValue *value,
                                  GParamSpec *pspec)
{
    MyHello *self = MY_HELLO(object);

    switch ((MyHelloProperty)property_id) {
    case PROP_GREETING:
        g_value_set_string(value, self->greeting);
        break;
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        break;
    }
}

static void my_hello_finalize(GObject *object)
{
    MyHello *self = MY_HELLO(object);
    g_free(self->greeting);

    /* Always chain up */
    G_OBJECT_CLASS(my_hello_parent_class)->finalize(object);
}

static void my_hello_class_init(MyHelloClass *klass)
{
    GObjectClass *object_class = G_OBJECT_CLASS(klass);

    object_class->set_property = my_hello_set_property;
    object_class->get_property = my_hello_get_property;
    object_class->finalize = my_hello_finalize;

    obj_properties[PROP_GREETING] = g_param_spec_string(
        "greeting", "Greeting", "The greeting.", "Hi", G_PARAM_CONSTRUCT_ONLY | G_PARAM_READWRITE);

    g_object_class_install_properties(object_class, N_PROPERTIES, obj_properties);
}

static void my_hello_init(MyHello *self) {}

/**
 * my_hello_new:
 * @greeting: (not nullable): The greeting.
 *
 * Create a MyHello object.
 *
 * Returns: (transfer full): A MyHello object.
 */
MyHello *my_hello_new(const char *greeting)
{
    MyHello *hello = g_object_new(MY_TYPE_HELLO, "greeting", greeting, NULL);

    return hello;
}

void my_hello_greet(MyHello *self, MyTitle title, const char *name)
{
    const char *title_str;
    switch (title) {
    case MY_TITLE_DR:
        title_str = "Dr.";
        break;
    case MY_TITLE_MR:
        title_str = "Mr.";
        break;
    default:
        title_str = "";
        break;
    }

    printf("%s, %s %s\n", self->greeting, title_str, name);
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
