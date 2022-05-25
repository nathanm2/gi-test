project('gi-test', 'c', version: '0.1.1')

gobject = dependency('gobject-2.0')

libmyhello_c = files('my-hello.c')
libmyhello_h = files('my-hello.h')

libmyhello = library('libmyhello', libmyhello_c, dependencies: [gobject])

hello_c = files('main.c')
executable('hello', hello_c,
  link_with: libmyhello,
  dependencies: [gobject])
