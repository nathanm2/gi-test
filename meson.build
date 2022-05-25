project('gi-test', 'c', version: '0.1.1')

gobject = dependency('gobject-2.0')

libmyhello_c = files('my-hello.c')
libmyhello_h = files('my-hello.h')

libmyhello = library('myhello',
  libmyhello_c,
  dependencies: [gobject],
  install: true)

hello_c = files('main.c')

executable('hello', hello_c,
  link_with: libmyhello,
  dependencies: [gobject],
  install: true)

# libgirepository requires namespace version string to either be a single major
# number (e.g. 1) or a major.minor number (e.g. 1.1).
version_array = meson.project_version().split('.')
api_version = '@0@.@1@'.format(version_array[0], version_array[1])
api_name = '@0@-@1@'.format(meson.project_name(), api_version)

gnome = import('gnome')

# Neither the 'symbol_prefix' nor the 'export_packages' seem to make any
# difference in the resulting typelib file, but they're present in all the
# examples I've looked at.
gnome.generate_gir(libmyhello,
  sources: libmyhello_c + libmyhello_h,
  namespace: 'My',
  nsversion: api_version,
  identifier_prefix: 'My',
  symbol_prefix: 'my',
  export_packages: api_name,
  includes: [ 'GObject-2.0' ],
  install: true)

gi = dependency('gobject-introspection-1.0')

gir_c = files('gir-test.c')
executable('gir-test', gir_c,
  dependencies: [gi])
