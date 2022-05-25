project('gi-test', 'c', version: '0.1.1')

gobject = dependency('gobject-2.0')

libmyhello_c = files('my-hello.c')
libmyhello_h = files('my-hello.h')

libmyhello = library('libmyhello',
  libmyhello_c,
  dependencies: [gobject],
  install: true)

hello_c = files('main.c')

executable('hello', hello_c,
  link_with: libmyhello,
  dependencies: [gobject],
  install: true)

gnome = import('gnome')

gnome.generate_gir(libmyhello,
  sources: libmyhello_c + libmyhello_h,
  namespace: 'My',
  nsversion: meson.project_version(),
  identifier_prefix: 'My',
  install: true)
