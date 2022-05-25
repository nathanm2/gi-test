#include <girepository.h>
#include <glib-object.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    GError *error = NULL;
    GIRepository *gir = g_irepository_get_default();
    GSList *paths = g_irepository_get_search_path();
    while (paths) {
        printf("%s\n", (const char *)paths->data);
        paths = paths->next;
    }

    GITypelib *l = g_irepository_require(gir, "My", "0.1.1", 0, &error);
    if (l == NULL) {
        printf("%s\n", error->message);
    }

    return 0;
}
